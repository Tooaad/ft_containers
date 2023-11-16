# ft_containers
Recreation of a Map, Stack and Vector in C++98

#### [First approach to a STL Containers](https://stackoverflow.com/questions/7758580/writing-your-own-stl-container "First approach of a STL Containers")


## Tests
Tests have been made for Map and Vector only, both tests checks functionality and time.

### Deployment
Simply copy the srcs folder and Makefile into your root project, comiple and execute!

#####WARNING: Yoy may need to change your name containers to capital letters to made the test work.
Run `$make && ./containers`

While executing, you might need to scroll up to see which section test is running, tap any key to skip to the next test.


### References
- [Understanding Iterators and Iterator Traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits "Understanding Iterators and Iterator Traits") 
- [Code Sample of how to build your own iterator pt1](https://www.cplusplus.com/reference/iterator/iterator/ "Code Sample of how to build your own iterator pt1")
-  [Rebind explanation](https://stackoverflow.com/questions/14148756/what-does-template-rebind-do "Rebind explanation")
- [Delete node for a RBTree](https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea "Delete node for a RBTree")
- [Red-Black Tree Visualizatino](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html "Red-Black Tree Visualizatino")

# Tricky stuff
- *Map.find* with a 0 without being inserted should not be founded otherwise your algorithm is wrong
- Insert same key several times and print where is the value
- How does operator[] works on the map? If you look for something that does not exist, should insert it and return it and can overwrite the searched value




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
