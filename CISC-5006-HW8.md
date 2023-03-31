# CISC-5006 Data Structures

## Homework 8 -  Due 04/04/2023 8 PM EST


### Description
---
In class, we looked at filling a 2D grid with a specific color and used a queue to do it. We can also use a stack as well. In this homework assignment, we'll look at what the potential differences are.


### Assignment
---

Below is the code we used in class to fill the grid.

```cpp
#include <vector>
#include <cstddef>
#include <iostream>
#include <queue>

enum class Color
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
};

struct Position {
    int r, c;
};

class Grid
{
public:
    // initialize a black [size x size] grid
    explicit Grid(size_t size)
        : g_(size, std::vector<Color>(size, Color::BLACK))
    {}

    Color& operator()(size_t r, size_t c)
    {
        return g_[r][c];
    }

    const Color& operator()(size_t r, size_t c) const
    {
        return g_[r][c];
    }

    void draw(std::ostream& os) const
    {
        for (size_t row = 0; row < g_.size(); ++row) {
            os << "\t";
            for (size_t col = 0; col < g_[row].size(); ++col) {
                draw(os, g_[row][col]);
            }
            os << "\n";
        }
    }

    void fill(int r, int c, Color new_color)
    {
        std::queue<Position> q;

        q.push(Position {r, c});

        Color color = g_[r][c];

        // keep track of visited positions to avoid
        std::vector<Position> visited;
        while (!q.empty()) {
            // extract the position to visit
            Position position_to_consider = q.front();
            q.pop();

            int row = position_to_consider.r;
            int col = position_to_consider.c;

            std::vector<Position> neighbors = find_neighbors_of(row, col, color);

            // visit the cell and mark it as visited
            g_[row][col] = new_color;
            visited.push_back(position_to_consider);

            // add any neighbors to visit that haven't already been visited
            for (const Position& p : neighbors) {
                if (!is_visited(visited, p)) {
                    q.push(p);
                }
            }
        }
    }

    int size() const
    {
        return (int) g_.size();
    }

private:
    void draw(std::ostream& os, Color color) const
    {
        switch (color) {
        case Color::BLACK:  os << "⬛"; break;
        case Color::WHITE:  os << "⬜"; break;
        case Color::RED:    os << "🟥"; break;
        case Color::GREEN:  os << "🟩"; break;
        case Color::BLUE:   os << "🟦"; break;
        case Color::YELLOW: os << "🟨"; break;
        }
    }

    // Remember, their are eight potential neighbors to consider
    std::vector<Position> find_neighbors_of(int row, int col, Color old_color)
    {
        std::vector<Position> positions;

        int deltas[] = {-1, 0, 1};
        for (auto dr : deltas) {
            for (auto dc : deltas) {
                // do not consider myself a neighbor
                if (dr == 0 && dc == 0)
                    continue;
                // out of bounds cells do not count
                if (!is_within_bounds(row + dr, col + dc))
                    continue;
                if (g_[row + dr][col + dc] == old_color)
                    positions.push_back(Position{ row + dr, col + dc});
            }
        }

        return positions;
    }

    bool is_within_bounds(int row, int col)
    {
        if (row < 0 || row >= size()) {
            return false;
        }

        if (col < 0 || col >= size()) {
            return false;
        }
        
        return true;
    }

    bool is_visited(const std::vector<Position>& visited, const Position& p) const
    {
        // a position is visited if it is found in the visited vector
        for (const Position& vp : visited) {
            if (vp.r == p.r && vp.c == p.c) {
                return true;
            }
        }

        return false;
    }

private:
    std::vector<std::vector<Color>> g_;
};

static Grid create_initial_grid()
{
    Grid g(10);
   g(0, 0) = Color::YELLOW;
   g(0, 1) = Color::YELLOW;
   g(0, 2) = Color::YELLOW;
   g(0, 3) = Color::GREEN;
   g(0, 4) = Color::GREEN;
   g(0, 5) = Color::GREEN;
   g(0, 6) = Color::GREEN;
   g(0, 7) = Color::GREEN;
   g(0, 8) = Color::GREEN;
   g(0, 9) = Color::GREEN;

   g(1, 0) = Color::YELLOW;
   g(1, 1) = Color::YELLOW;
   g(1, 2) = Color::YELLOW;
   g(1, 3) = Color::YELLOW;
   g(1, 4) = Color::YELLOW;
   g(1, 5) = Color::YELLOW;
   g(1, 6) = Color::GREEN;


   g(2, 0) = Color::GREEN;
   g(2, 1) = Color::GREEN;
   g(2, 2) = Color::GREEN;
   g(2, 3) = Color::GREEN;
   g(2, 4) = Color::GREEN;
   g(2, 5) = Color::GREEN;
   g(2, 6) = Color::GREEN;

   g(3, 0) = Color::WHITE;
   g(3, 1) = Color::WHITE;
   g(3, 2) = Color::WHITE;
   g(3, 3) = Color::WHITE;
   g(3, 4) = Color::WHITE;
   g(3, 5) = Color::GREEN;
   g(3, 6) = Color::GREEN;
   g(3, 7) = Color::GREEN;
   g(3, 8) = Color::GREEN;

   g(4, 0) = Color::WHITE;
   g(4, 1) = Color::RED;
   g(4, 2) = Color::RED;
   g(4, 3) = Color::RED;
   g(4, 4) = Color::RED;
   g(4, 5) = Color::RED;
   g(4, 6) = Color::GREEN;

   g(5, 0) = Color::WHITE;
   g(5, 1) = Color::WHITE;
   g(5, 2) = Color::WHITE;
   g(5, 3) = Color::RED;
   g(5, 4) = Color::RED;
   g(5, 5) = Color::GREEN;
   g(5, 6) = Color::GREEN;

   g(6, 0) = Color::WHITE;
   g(6, 1) = Color::BLUE;
   g(6, 2) = Color::WHITE;
   g(6, 3) = Color::RED;
   g(6, 4) = Color::RED;
   g(6, 5) = Color::RED;
   g(6, 6) = Color::RED;
   g(6, 7) = Color::RED;
   g(6, 8) = Color::RED;

   g(7, 0) = Color::WHITE;
   g(7, 1) = Color::BLUE;
   g(7, 2) = Color::BLUE;
   g(7, 3) = Color::BLUE;
   g(7, 4) = Color::BLUE;
   g(7, 5) = Color::RED;
   g(7, 6) = Color::RED;

   g(8, 0) = Color::WHITE;
   g(8, 1) = Color::BLUE;
   g(8, 2) = Color::BLUE;
   g(8, 3) = Color::BLACK;
   g(8, 4) = Color::BLUE;
   g(8, 5) = Color::BLUE;
   g(8, 6) = Color::BLUE;
   g(8, 7) = Color::BLUE;

   g(9, 0) = Color::WHITE;
   g(9, 1) = Color::BLUE;
   g(9, 2) = Color::BLUE;

   return g;
}

int main()
{
    Grid g = create_initial_grid();

    std::cout << "Before: " << "\n";

    g.draw(std::cout);

    std::cout << "After: " << "\n";

    g.fill(1, 7, Color::RED);

    g.draw(std::cout);
}
```

In order to see how the change in container will affect behavior, we need a way of observing the behavior each time through the loop. We can utilize our `draw` function to visualize the state of the grid. Add the following two lines right after we change the color of the cell: 

```cpp
std::cin.get();
draw(std::cout);
```

This code will wait for you to press `Enter` then draw the grid out to `std::cout`.

After applying the code change above, rebuild and rerun the code. You should be able to press `Enter` and see the state of the grid each time through the loop.

Run the code using a `std::queue` and observe how the cells are filled.

Change the code to use a `std::stack` and observe how the cells are filled.

1. __(2 points)__ What differences do you see using a queue vs stack?
2. __(3 points)__ Does using one over the other matter for this particular problem? Why or why not?

Submit your answers to me via Slack or email prior to the deadline.