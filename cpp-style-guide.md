# CISC-5006 C++ Style Guide


### C++ Coding Style

 In general, I'm open to a variety of coding styles; I'm less concerned with whether you place your braces on a new line or the same line and more concerned with the overall readability of your code. As long as you're consistent and reasonable with your style, I am fine with you coding in whatever style you wish.

 With that being said, I found the [Stanford C++ Education Style Guide](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1218/resources/style_guide.html) to be an excellent resource about good C++ style.

### RAII

[What is RAII?](https://en.cppreference.com/w/cpp/language/raii) 

Given this is a data structures class, we will be learning how to manage data in memory and that will often mean dynamically allocating and freeing memory. I will be paying close attention to how you manage your resources in your assignments; submitting programs with memory or other resource leaks in them will result in a significantly lower mark than properly managing your resources. I'd strongly recommend learning how to use [valgrind](https://valgrind.org/docs/manual/quick-start.html) to detect resource leaks in your programs to assist in your programming.