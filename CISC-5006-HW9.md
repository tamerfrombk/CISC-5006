# CISC-5006 Data Structures

## Homework 9 -  Due 04/11/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in our previous lecture.


### Assignment
---
In class, we did not go over the three most common methods of tree traversal:

1. In order traversal
2. Post order traversal
3. Pre order traversal

Research these traversal methods and use one or more of them to answer the questions below. For both questions, assume we've defined a BST as:

```cpp
template <class Key>
class BST
{
private:
  struct Node
  {
    Key key;
    Node *left, *right;
    Node(Key key, Node *left = nullptr, Node *right = nullptr)
      : key(key), left(left), right(right) {}
  } root_; // the root
  
public:
  	void insert(const Key& key) { ... }
    bool find(const Key& key)   { ... }
    void remove(const Key& key) { ... }
};
```

1. __(2 points)__ Implement a member function on `BST` that returns the number of nodes in the tree. If the tree is empty, return 0. What is the big O of this function?

2. __(3 points)__ Implement a member function on `BST` that returns the values in the nodes of the tree in __reverse__ sorted order. For example, if our BST was:

```
    2
   / \ 
  1   3
```

Then we'd expect to return `3,2,1`. 

What is the big O of your algorithm?

__HINT__: think about using another data structure to help.


---

When you're finished, include all of your code in a `cpp` file and submit the cpp file to me over Slack or email prior to the deadline.