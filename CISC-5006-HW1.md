# CISC-5006 Data Structures

## Homework 1 -  Due 01/24/2023 8 PM EST


### Description
---
In this homework assignment, we will make sure we have set up the tools we need to succeed in the rest of the class. We will write some C++ source, install required tools, familiarize ourselves with them, and build our first program. If you're on PC, I __highly__ recommend familiarizing yourself with [WSL](https://learn.microsoft.com/en-us/windows/wsl/install). It will make your development experience _much_ better.


### Assignment
---
1. Install `g++` (our C++ compiler of choice) on your machine. I recommend installing [Visual Studio Code](https://code.visualstudio.com/) and [the C++ extension](https://code.visualstudio.com/docs/languages/cpp) as well. VSCode is cross-platform, free, and comes with pretty good C++ support.

2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) on your machine.

3. [Install CMake](https://cmake.org/install/) on your machine and ensure it is on your `PATH`.

4. Create a new folder to store all your source files for this homework.

5. Inside of the folder created above, initialize a Git repo.

6. Create a C++ source file `homework1.cpp` with the contents:

```cpp
#include <iostream>

int main()
{
    std::cout << "hello world!" << "\n";
}
```

You may recognize this as a basic hello world program.


7. Create a file called `CMakeLists.txt` alongside `homework1.cpp` above with the following contents:

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(homework1 VERSION 1.0.0)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_WARNING_FLAGS "-Wall -Wextra -Wpedantic")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_WARNING_FLAGS}")

ADD_EXECUTABLE(${PROJECT_NAME} homework1.cpp)
```

This is a very basic CMake file for building simple C++ programs and will be the basis of any CMake written in future. I _highly_ encourage you to spend some time experimenting with this file and researching what each line does.

8. CMake follows a _out of source_ build model which means that we build our code in a different place than where the source is. In your current directory:

```sh
$> mkdir build # create the build directory
$> cmake -S . -B build # generate the build system files (e.g. `Makefile`)
$> cmake --build build # start the build
```

After executing the above, you will have an executable called `homework1` located in the `build` directory.

9. Make sure you can run this program: `./build/homework`. The program should print "hello world".

10. Create a `.gitignore` file and add the `build` directory to it since we don't want to commit any build artifacts.

11. Commit your changes into Git. This should be your first commit in the history and should contain:
    - a `.gitignore` file
    - a `homework1.cpp` C++ source file
    - a `CMakeLists.txt` CMake file

12. Now, change the above C++ program to print "good bye world" instead. Ensure that your program builds warning and error free.

13. Commit those changes into Git. You should now have two commits in your history.

14. Zip the below contents of your directory into a zip archive named `cisc-5006-<first_name>-<last_name>.zip` and either Slack (privately) or email me the zip archive. For example, if I was submitting the assignment, the zip archive name would be `cisc-5006-tamer-aly.zip`. __Please ensure your zip file name matches this naming convention__. For completeness' sake, the zip archive should contain all of the following:
    - the `.git` folder
    - `.gitignore` file
    - `CMakeLists.txt`
    - `homework1.cpp` C++ source file
