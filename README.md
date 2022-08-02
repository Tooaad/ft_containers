# ft_containers

### First Steps:
#### How do I make a STL Container?
- Google says: https://stackoverflow.com/questions/7758580/writing-your-own-stl-container
this is a great template to begin with.


# General Tasks
- Remake Iterator, Reverse Iterator & Iterator Traits
- Pairs & Make_Pair
- Optimal Tree Structure to order key map insertions

# Vector Tasks
> https://bajamircea.github.io/coding/cpp/2020/04/20/how-vector-works-basic.html
- Orthodox Canonical Form
- Iterator function
- Capacity functions
- References functions
- Modifiers functions
- Allocator
- Others

# Map
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


### References
- Very important to start: https://stackoverflow.com/questions/7758580/writing-your-own-stl-container
- Understanding Iterators and Iterator Traits: https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
- Code Sample of how to build your own iterator pt1: https://www.cplusplus.com/reference/iterator/iterator/
- Code Sample of how to build your own iterator pt2 - more deep: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

https://en.cppreference.com/w/cpp/language/converting_constructor


- TreeIter: https://cdmana.com/2021/12/202112300642463009.html
- TreeIter+: https://programmer.ink/think/use-a-red-black-tree-to-encapsulate-set-and-map-at-the-same-time.html
https://github.com/Hedenghui/cpp/blob/b9b5976aa8a821d191e115cb2bb790d78743b168/myrbtree.h
 
https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
https://howardhinnant.github.io/allocator_boilerplate.html

- Delete node: https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea

- https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

# Cosas a pillar
- Prueba map.find con un 0 (sin insertarlo en el mapa) -> lo encuentra esta mal
- Probar a meter el mismo key varias veces e imprimir donde estan valor
- Como funciona el operator[], que hace