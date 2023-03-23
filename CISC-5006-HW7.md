# CISC-5006 Data Structures

## Homework 7 -  Due 03/28/2023 8 PM EST


### Description
---
In this homework assignment, we will test our depth of knowledge of the topics covered in our previous lecture.


### Assignment
---

__(5 points)__ In class, we talked about a `put` function for `SortedArrayList` that keeps the list sorted at all times by:

1. Finding a proper location for the new item in the sorted list.
2. Creating space for the new element by moving down all the list elements that will follow it.
3. Putting the new element in the list.
4. Incrementing the size of the list.

For your homework, you'll be implementing `put` below. Your implementation should have all 4 general steps above. 

Your homework will be graded on these 5 cases being handled:

1. Putting into an empty list.
2. Putting into a non-empty list.
3. Putting into a list that's full e.g. there's no more room left in the list.
4. Putting into the end of a list.
5. Putting into the beginning or middle of the list.

Of course, `put` must maintain the invariant of keeping the list sorted before and after the `put`. Each of these cases is worth 1 point.

```cpp
class SortedArrayList
{
public:
    SortedArrayList()
        : elems_(nullptr)
        , size_(0)
        , capacity_(0)

    void put(int elem)
    {
        // TODO: implement
    }

private:
    void resize()
    {
        // avoid doubling zero and set an initial capacity of 10
        const size_t new_capacity = capacity_ == 0 ? 10 : capacity_ * 2;

        // allocate a new piece of memory and copy the elements over
        int *new_elems = new int[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_elems[i] = elems_[i];
        }

        // destroy the old elements and take over the new ones
        if (elems_ != nullptr) {
            delete[] elems_;
        }
        elems_ = new_elems;

        // finally, update our capacity
        capacity_ = new_capacity;
    }
    
private:
    int *elems_; // pointer to the first element
    size_t size_; // the number of elements present
    size_t capacity_; // the number of elements allocated
};
```

Copy the code above into a `cpp` file of your choice and implement `put`. Submit your `cpp` file to me via Slack or email prior to the deadline.