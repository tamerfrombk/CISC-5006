# CISC-5006 Data Structures

## Homework 2 -  Due 01/31/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in lecture 2 and expand on that knowledge using standard library functions and reference. We will write a computer program that will assist you in determining your letter grades for this course.


### Assignment
---
1. Set up a homework directory like we did in Homework 1. Name your source file `homework2.cpp` and update your build files accordingly. I recommend creating an initial commit here.

2. Copy the below into `homework2.cpp` and ensure your program builds and runs. You will notice warnings pop up when building `homework2.cpp` at this stage; that's OK. They are there because we have not implemented most of the functionality yet. I recommend creating another commit after copying the below into `homework2.cpp`.


```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>


// Determine if the string pointed at by @str is an integer.
// @str is assumed to be non NULL.
static bool is_integer(const char *str)
{
    while (*str != '\0') {
        if (!std::isdigit(*str)) {
            return false;
        }
        str++;
    }

    return true;
}

/*
    Determine the letter grade using Fordham's Grading Policy:
    A: [93%, 100%]
    A-: [90%, 93%)
    B+: [87%, 90%)
    B: [83%, 87%)
    B-: [80%, 83%)
    C+: [77%, 80%)
    C: [73%, 77%)
    C-: [70%, 73%)
    D: [60%, 70%)
    F: [0%, 60%)

    For example:
        - if @total_points is 81, the function should return the string "B-"
        - if @total_points is 100, the function should return the string "A"
        - if @total_points is 73, the function should return the string "C"
*/
static std::string determine_letter_grade(int total_points)
{
    // TODO: implement this function
    return "TODO: implement determine_letter_grade()";
}

// Calculates the sum of @points.
static int sum(const std::vector<int>& points)
{
    // TODO: implement this function
    // HINT: use a range for-loop (https://en.cppreference.com/w/cpp/language/range-for)
    return 0;
}

int main(int argc, char **argv)
{
    std::vector<int> points;

    // QUESTION 1: Why are we starting our for loop counter at 1? Explain your reasoning.
    for (int i = 1; i < argc; ++i) {
        // TODO: implement a loop that adds the arguments provided to main into the vector
        // if the argument is an integer. If the argument is not an integer, print an error message out to standard error (std::cerr) and exit the program.
        
        // HINT: you'll need to use std::stoi (https://en.cppreference.com/w/cpp/string/basic_string/stol)
        // to convert the string argument to an integer to add to the vector of points.
    }

    // QUESTION 2: Why const here?
    const int total_points = sum(points);

    std::cout << "Your letter grade is: " << determine_letter_grade(total_points) << ".\n";
}
```

3. __(3 points)__ Implement the code where the `TODO: implement` comments are while keeping in mind our [style guide](/cpp-style-guide.md). Break the problem down into pieces and slowly build your solution. I recommend adding commits when you've made significant milestones in the implementation; I'll leave it to you to determine what "significant" means. You are responsible for considering basic edge cases and reporting errors if necessary. Here are some edge cases to consider. Can you think of more?
    - using a string program argument
    - using a floating point program argument
    - providing program arguments that sum to less than 0 or greater than 100
    - providing no program arguments

4. __(2 points)__ Answer the two questions in the comments of the assignment. You can leave your answer in the source code via comments. Please make it clear what your answers are by marking them with `ANSWER:` or something similar.

5. Zip the below contents of your homework folder into a zip file `cisc-5006-<first_name>-<last_name>.zip` and Slack or email it to me by the deadline above.
    - `.git/`
    - `.gitignore`
    - `homework2.cpp`
    - `CMakeLists.txt`