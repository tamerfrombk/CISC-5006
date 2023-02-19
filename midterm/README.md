# CISC-5006 Data Structures

## Midterm Assignment -  Due 03/07/2023 8 PM EST


### Description
---
In our midterm assignment, we'll be implementing a (much) simpler version of `std::string` using a linked list approach. There are two sections to this assignment:

1. Implementing the [LinkedString](/midterm/include/linked_string.h) class
2. Answering the questions below.

Each part will be worth 10 points for a combined total of 20 points.

### Setup

The midterm assignment follows a slightly different setup than we're used to. 

1. Create a folder on your computer to store your assignment and initialize a git repo in it.
2. Copy all of the files in [midterm](/midterm/) into that directory. After copying, your folder should contain:
    - include/linked_string.h
    - test/catch_amalgamated.cpp
    - test/catch_amalgamated.hpp
    - test/CMakeLists.txt
    - test/tests.cpp
    - CMakeLists.txt
    - main.cpp
    - README.md

3. Create a `build` directory to store our build artifacts.
4. Create a `.gitignore` file to ignore `build/`.
5. Generate the build: `cmake -S . -B build`
6. Execute the build: `cmake --build build`
    - This may take a while the first time you run this as the testing library has to be built.
    - You'll also notice that there are some warnings printed out. They're due to the functions being stubbed.
7. At this point, you'll have two different executables:
    - `build/midterm` --  this is the driver program
    - `build/test/tests` -- these are the tests
8. At this point, you're done with setup. I recommend making your first commit here.

The test framework we are using is called [Catch2](https://github.com/catchorg/Catch2). It's a relatively lightweight and fast testing framework that's quick to adopt to new projects. In our build, we use some common conventions of CMake projects:

1. We have a separate CMakeLists file for building the tests.
2. We have an `include` folder that stores our common header files so both our driver program and test program can use them.
3. We keep the `Catch2` files in `test` because they're only used by test files and we don't want them polluting our other build.

### Assignment
---
1. __(10 points)__ The first part of your assignment will be to fill in the stub class in `include/linked_string.h` and get all of the tests in `test/tests.cpp` to pass. These tests _must_ pass in order to get full marks. Some things to consider:
    - each failing test docks you a point.
    - each remaining warning also docks you a point.
    - feel free to add additional tests of your own!
        - the included tests are definitely not exhaustive
    - you are __NOT__ allowed to use `std::list` to implement `LinkedString` as that defeats the purpose of this assignment
        - however, feel free to use it as a reference implementation

---

__(10 points)__ The second part of your assignment consists of answering the following questions. Please create a seperate text file containing your answers.
    
1. `std::string` is essentially implemented as a dynamic array of characters whereas `LinkedString` is implementing a string as a linked list of characters.
    - __(2 points)__ What is the memory layout of the elements of a linked list versus a dynamic array?
    - __(2 points)__ How does this affect the runtime performance of each implementation on a modern computer?
    - __(2 points)__ When would we want to use a linked list over a dynamic array?

If you're willing to see this performance implication yourself, consider using the [benchmark](https://github.com/catchorg/Catch2/blob/devel/docs/benchmarks.md) provided by Catch.

2. __(1 point)__ Are clients of `LinkedString` able to see `head_`? Why or why not?

3. __(2 points)__ Why would allowing clients of `LinkedString` to directly modify `head_` be a bad idea?

4. __(1 point)__ Why are some methods marked `const`? What is the significance of that?

### Submitting your work

Zip the entire directory (minus `build/` of course) and email/Slack it to me prior to the deadline. The zip should include:
- include/linked_string.h
- test/catch_amalgamated.cpp
- test/catch_amalgamated.hpp
- test/CMakeLists.txt
- test/tests.cpp
- CMakeLists.txt
- main.cpp
- README.md
- .git/
- .gitignore

### Resources

All of the resources on the class repo are always available. Here are some resources that are useful to this specific assignment:

- [Linked List vs Array Performance](https://dzone.com/articles/performance-of-array-vs-linked-list-on-modern-comp)
- [Iteration vs Recursion](https://www.geeksforgeeks.org/difference-between-recursion-and-iteration/)
- [Memory Fragmentation](https://stackoverflow.com/questions/3770457/what-is-memory-fragmentation)
- [Modern Computer Architecture](https://en.wikipedia.org/wiki/Computer_architecture)