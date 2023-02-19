# CISC-5006 Data Structures

## Homework 5 -  Due 02/28/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in our previous lecture.


### Assignment
---
1. __(2 points)__ Does the below class demonstrate encapsulation well? Explain your reasoning. If not, fix the class so it does.

```cpp
class Rocket
{
public:
    int weight;
    std::string name;

    Rocket(int weight, std::string name)
        : weight(weight), name(name) {}
    //  ^-- this is called a member initializer list
    // It's an efficient way to initialize a class' members
    // Note that you can use the same name as the member in the constructor parameter
    // See https://en.cppreference.com/w/cpp/language/constructor for more info

    // this is not a factual calculation by the way
    int calculate_fuel_consumption() const
    {    
        if (name == "voyager") {
            return weight * 4;
        }
        
        return name.length() + weight * 3;
    }
};
```

2. __(3 points)__ In class, we wrote a recursive implementation of `size()` for IntList. Implement the _iterative_ version of `size()` below:

```cpp
struct IntList
{
    IntList *next;
    int value;
};

// Returns the size of @list iteratively
// An empty list should return a size of 0.
int size(IntList *list)
{
    // TODO: implement
}
```

3. Submit your answers to me via Slack or email by the deadline.