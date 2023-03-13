# CISC-5006 Data Structures

## Homework 6 -  Due 03/21/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in our previous lecture.


### Assignment
---
1. __(2 points)__ Let `n` be the length of `a` and `m` be the length of `b`. What is the runtime big O of `f`? Explain your reasoning.

```cpp
std::vector<int> f(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;
    for (auto i : a) {
        for (auto j : b) {
            result.push_back(i * j);
        }
    }

    return result;
}
```

2. __(2 points)__ We can also use big O notation to see how the memory requirements of an algorithm will scale with respect to the input size. What is the spatial big O of `f` above? Explain your reasoning.

3. __(1 point)__ In [the documentation for vector<>::push_back](https://en.cppreference.com/w/cpp/container/vector/push_back), the runtime complexity is listed as "amortized constant". What does "amortized" mean in this context?

4. Submit your answers to me via Slack or email by the deadline.