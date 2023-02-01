# CISC-5006 Data Structures

## Homework 3 -  Due 02/07/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in lecture 3. In this homework, there will be no code to write. Please submit your answers in a text file with a name of your choosing.


### Assignment
---
1. __(2 points)__ Explain what `f` is doing to `str`. In particular, pay attention towards explaining how memory is accessed.

```cpp
void f(char *str, size_t length)
{
    for (size_t i = 0, j = length - 1; i != j; ++i, --j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;        
    }
}
```

2. __(1 point)__ Given:

```cpp
void f(int& a)
{
    a = a + 1;
}
```

Is it possible to call `f` like this? Explain your reasoning. If it's not possible, how could we fix the call to `f`?

```cpp
int main()
{
    f(12);
}
```

3. __(1 point)__ What is the value of `rx` below? Explain your reasoning.

```cpp
int main()
{
    int x = 12;
    int *px = &x;

    *px = 14;
    int& rx = x;

    rx += 1;
}
```

4. __(1 point)__ Does this code delete _all_ of the memory pointed to by `mem`? Why or why not? If not, how can we fix the code so that it deletes _all_ of the memory?

```cpp
int main()
{
    int *mem = new int[10];
    delete mem;
}
```

5. Submit your written answers to me via Slack or email by the deadline.