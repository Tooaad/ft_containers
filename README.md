# ft_containers
Recreation of a Map, Stack, and Vector in C++98

#### [First approach to a STL Containers](https://stackoverflow.com/questions/7758580/writing-your-own-stl-container "First approach of a STL Containers")

## Tests
Tests have been made for Map and Vector only, both tests check functionality and time.

### Deployment
Copy the srcs folder and Makefile into your root project, compile, and execute!

##### WARNING: You may need to change your name containers to capital letters to make the test work.
Run `$> make && ./containers`

While executing, you should scroll up to see which section test is running and tap any key to skip to the next test.

> _test folder contains other tests that are not the ones displayed here

## Tricky stuff
- *Map.find* with a 0 without being inserted should not be found otherwise your algorithm is wrong
- Insert the same key several times and print where the value
- How does operator[] works on the map? If you look for something that does not exist, you should insert it and return it and can overwrite the searched value

## Results
#### Speed Test

[![SpeedTest](https://i.gyazo.com/39712888a5a59661e8e12ae83c36b1a6.png)](https://gyazo.com/39712888a5a59661e8e12ae83c36b1a6)

https://github.com/Tooaad/ft_containers/assets/60491687/53501cc7-6e55-4300-b80f-3bac9e4b50a2

https://github.com/Tooaad/ft_containers/assets/60491687/f389e3c7-4c3a-4b8b-a434-7bf2479f5ed1
> MapTest and VectorTest run in the same simulation

### References
- [Understanding Iterators and Iterator Traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits "Understanding Iterators and Iterator Traits") 
- [Code Sample of how to build your own iterator pt1](https://www.cplusplus.com/reference/iterator/iterator/ "Code Sample of how to build your own iterator pt1")
-  [Rebind explanation](https://stackoverflow.com/questions/14148756/what-does-template-rebind-do "Rebind explanation")
- [Delete node for a RBTree](https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea "Delete node for a RBTree")
- [Red-Black Tree Visualizatino](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html "Red-Black Tree Visualizatino")


<!--
# Vector Tasks
> https://bajamircea.github.io/coding/cpp/2020/04/20/how-vector-works-basic.html
- Orthodox Canonical Form
- Iterator function
- Capacity functions
- References functions
- Modifiers functions
- Allocator
- Others

# map
- Orthodox Canonical Form
- Iterator function
- Capacity functions
- [] Operator
- Modifiers functions
- Observers
- Allocator

# Stack
- Only Constructor! (It is not Orthodox Canonical)
- Member Functions
- Relational Operators
-->
