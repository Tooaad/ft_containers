/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:35:59 by gpernas-          #+#    #+#             */
/*   Updated: 2022/09/14 18:42:41 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTests.hpp"
#include "MapTests.hpp"
#include "../includes/vector.hpp"
#include "../includes/stack.hpp"
#include "../includes/map.hpp"
#include "../includes/RBTree.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

void cleaks() { system("leaks containers"); }

int main()
{
	// runTests();
	runMapTests();
	// atexit(cleaks);

// std::string b_string[64] = { "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf", "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1", "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t", "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv", "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb", "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7", "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx", "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q", "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij", "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2", "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb", "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00", "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W", "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ", "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG", "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy", "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck", "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93", "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo", "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd", "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs", "gzaapTWW7i9EZjjzLeK6" };
// std::size_t b_size = 64;
// std::string s_string[32] = { "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB", "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1", "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng", "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79", "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr", "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4", "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq", "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO", "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6", "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj", "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik" };
// std::size_t s_size = 32;
// double b_double[64]; init_array(b_double, 64);
// double s_double[32]; init_array(s_double, 32);


// 	ft::vector<double> mv;
// 	ft::vector<std::string> mv1;
// 	// ft::vector<int> mvector1(0, 10);

// 	std::vector<double> v;
// 	std::vector<std::string> v1;
// 	// std::vector<int> vector1(0, 10);

// 	v1.assign(b_string, b_string + b_size);
// 	mv1.assign(b_string, b_string + b_size);

// 	std::cout << v1.capacity() << "-" << v1.size() << " "; std::for_each(v1.begin(), v1.end(), print); std::cout << std::endl; std::cout << std::endl;
// 	std::cout << mv1.capacity() << "-" << mv1.size() << " "; std::for_each(mv1.begin(), mv1.end(), print); std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;

// 	v1.assign(65, "HelloWorld");
// 	mv1.assign(65, "HelloWorld");

// 	std::cout << v1.capacity() << "-" << v1.size() << " "; std::for_each(v1.begin(), v1.end(), print); std::cout << std::endl; std::cout << std::endl;
// 	std::cout << mv1.capacity() << "-" << mv1.size() << " "; std::for_each(mv1.begin(), mv1.end(), print); std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;

// 	v1.assign(s_string, s_string + s_size);
// 	mv1.assign(s_string, s_string + s_size);

// 	std::cout << v1.capacity() << "-" << v1.size() << " "; std::for_each(v1.begin(), v1.end(), print); std::cout << std::endl; std::cout << std::endl;
// 	std::cout << mv1.capacity() << "-" << mv1.size() << " "; std::for_each(mv1.begin(), mv1.end(), print); std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;

// 	std::cout << "yyyyyy" << std::endl;

	// mv.assign(b_double, b_double + b_size);
	// v.assign(b_double, b_double + b_size);

	// std::cout << v.capacity() << "-" << v.size() << " "; std::for_each(v.begin(), v.end(), print4); std::cout << std::endl; std::cout << std::endl;
	// std::cout << mv.capacity() << "-" << mv.size() << " "; std::for_each(mv.begin(), mv.end(), print4); std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;

	// v.assign(65, 1.234567);
	// mv.assign(65, 1.234567);

	// std::cout << v.capacity() << "-" << v.size() << " "; std::for_each(v.begin(), v.end(), print4); std::cout << std::endl; std::cout << std::endl;
	// std::cout << mv.capacity() << "-" << mv.size() << " "; std::for_each(mv.begin(), mv.end(), print4); std::cout << std::endl; std::cout << std::endl;

	// v.assign(65, 8765.234567);
	// mv.assign(65, 8765.234567);

	// std::cout << v.capacity() << "-" << v.size() << " "; std::for_each(v.begin(), v.end(), print4); std::cout << std::endl; std::cout << std::endl;
	// std::cout << mv.capacity() << "-" << mv.size() << " "; std::for_each(mv.begin(), mv.end(), print4); std::cout << std::endl; std::cout << std::endl;

	// v.assign(s_double, s_double + s_size);
	// mv.assign(s_double, s_double + s_size);

	// std::cout << v.capacity() << "-" << v.size() << " "; std::for_each(v.begin(), v.end(), print4); std::cout << std::endl; std::cout << std::endl;
	// std::cout << mv.capacity() << "-" << mv.size() << " "; std::for_each(mv.begin(), mv.end(), print4); std::cout << std::endl; std::cout << std::endl;

// ReverseIter

	// mvector2.push_back(1);
	// mvector2.push_back(2);
	// mvector2.push_back(3);
	// mvector2.push_back(4);

	// std::for_each(mvector2.begin(), mvector2.end(), print2);
	// std::cout << std::endl;
	// std::for_each(mvector2.rbegin(), mvector2.rend(), print2);


// RESIZE

	// std::cout << " " << mvector2.capacity() << " " << mvector2.size() << std::endl;
	// std::cout << " " << vector2.capacity() << " " << vector2.size() << std::endl;
	// std::cout << " " << mvector2.capacity() << " " << mvector2.size() << std::endl;


	// mvector2.resize(99, 1);
	// mvector1.resize(99, 1);
	// vector2.resize(99, 1);

	// std::cout << std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << " " << mvector2.capacity() << " " << mvector2.size() << std::endl;
	// std::cout << std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << " " << mvector1.capacity() << " " << mvector1.size() << std::endl;
	// std::cout << std::for_each(vector2.begin(), vector2.end(), print2); std::cout << " " << vector2.capacity() << " " << vector2.size() << std::endl;
	// std::cout << mvector2[0] << " " << mvector2.capacity() << " " << mvector2.size() << std::endl;

/*
// Begin & End normal
	std::cout << "Instantiate vector with 2 params with value 1: "; 
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	std::cout << "Instantiate vector with no params: ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "\n";
// // PUSHB
	mvector2.push_back(10);
	mvector2.push_back(11);
	mvector2.push_back(12);
	mvector2.push_back(13);
	std::cout << "Add 10, 11, 12, 13 to the Empty vector ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "\n";

// // POPB
	mvector2.pop_back();
	mvector1.pop_back();
	std::cout << "Removes last element from vector2(no 13) ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "Removes last element from vector1(only 1) ";
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	std::cout << "\n";

// ElementAccess
	std::cout << "Element Access: " << "\n";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "vector element [0]: " << mvector2[0] << "\n";
	std::cout << "vector element at 0: " << mvector2.at(0) << "\n";
	std::cout << "vector element front: " << mvector2.front() << "\n";
	std::cout << "vector element back: " << mvector2.back() << "\n";
	std::cout << "vector element size: " << mvector2.size() << "\n";
	std::cout << "vector element capacity: " << mvector2.capacity() << "\n"; 
	std::cout << "\n";
	
// // ASSIGN
	std::cout << "Assign: " << "\n";
	std::cout << "Result: 1 should erase and 10 11 12 should set: " << "\n";
	mvector1.assign(mvector2.begin(), mvector2.end());
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	std::cout << "Result: 1 should erase and 100 100 should set: " << "\n";
	mvector1.assign(3, 100);
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";

// // INSERT
	mvector1.insert(mvector1.begin() + 1, 8);
	std::cout << "Result: should insert 8 in 2nd position: " << "\n";
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	mvector1.insert(mvector1.begin(), mvector2.begin(), mvector2.end());
	std::cout << "Result: should insert 10 11 12 at the beginning of the vector1: " << "\n";
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	ft::vector<int> mvector3;
	mvector3.insert(mvector3.begin(), 2, 8);
	mvector3.insert(mvector3.begin() + 1, 1, 7);
	std::cout << "Result: should insert 10 11 12 at the beginning of the vector1: " << "\n";
	std::for_each(mvector3.begin(), mvector3.end(), print2); std::cout << "\n";
	
// // ERASE
	
	mvector3.erase(mvector3.begin() , mvector3.end());
	std::cout << "Result: erase all the elements in vector3: " << "\n";
	std::for_each(mvector3.begin(), mvector3.end(), print2); std::cout << "\n";
	std::cout << "vector2: "; std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	mvector2.erase(mvector2.begin());
	std::cout << "Result: 10 value is erase from vector2: " << "\n";
	std::for_each(mvector2.begin(), mvector2.end(), print2);
	std::cout << "\n";
	
// // SWAP

	std::cout << "vector2: "; std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "vector3: "; std::for_each(mvector3.begin(), mvector3.end(), print2); std::cout << "\n";
	mvector2.swap(mvector3);
	std::cout << "vector3: "; std::for_each(mvector3.begin(), mvector3.end(), print2); std::cout << "\n";
	std::cout << "vector2: "; std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	
// // Relational Operators

	ft::vector<int> mvector4;

	std::cout << "Operator==: ";
	(mvector2==mvector4)? std::cout << "True" << "\n" : std::cout << "False" << "\n";
	std::cout << "Operator!=: ";
	(mvector2!=mvector4)? std::cout << "True" << "\n" : std::cout << "False" << "\n";
	std::cout << "Operator>: ";
	(mvector3>mvector4)? std::cout << "True" << "\n" : std::cout << "False" << "\n";
	std::cout << "Operator<: ";
	(mvector3<mvector4)? std::cout << "True" << "\n" : std::cout << "False" << "\n";
	

 -----------------------------------------------------------------------------
*/	

/*
	std::map<int, int> map;
	std::pair<int, int> a3 = std::make_pair(8, 1);
	// std::pair<int, int> a2 = std::make_pair(4, 2);
	// std::pair<int, int> a4 = std::make_pair(10, 3);
	
	map.insert(a3);
	// map.insert(a2);
	// map.insert(a4);

	std::cout << &map.find(8)->first << " " << &map.begin()->first << std::endl;
	
	// std::cout << map[8] << " " << map.size() << std::endl;

	// return 0;

// MY map ------------------------------------------------------------
	
	ft::map<int, int> mmap;
	ft::pair<int, int> p3 = ft::make_pair(2, 2);
	ft::pair<int, int> p2 = ft::make_pair(5, 5);
	ft::pair<int, int> p4 = ft::make_pair(9, 9);
	ft::pair<int, int> p5 = ft::make_pair(10, 10);
	ft::pair<int, int> p6 = ft::make_pair(30, 30);
	ft::pair<int, int> p7 = ft::make_pair(25, 25);
	ft::pair<int, int> p8 = ft::make_pair(40, 40);
	ft::pair<int, int> p9 = ft::make_pair(38, 38);
	
	ft::pair<int, int> p10 = ft::make_pair(22, 22);
	ft::pair<int, int> p11 = ft::make_pair(11, 11);
	ft::pair<int, int> p12 = ft::make_pair(31, 31);
	ft::pair<int, int> p13 = ft::make_pair(33, 33);
	ft::pair<int, int> p14 = ft::make_pair(42, 42);


	// std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p3);
	// std::cout << &mmap.find(1)._root->_value.first << " " << &mmap.begin()._root->_value.first << std::endl;
	// return 0;
	// std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p2);
	// std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p4);
	mmap.insert(p5);
	mmap.insert(p6);
	mmap.insert(p7);
	mmap.insert(p8);
	mmap.insert(p9);
	mmap.insert(p10);
	mmap.insert(p11);
	mmap.insert(p12);
	mmap.insert(p13);
	mmap.insert(p14);
	// std::cout << mmap[1] << " " << mmap.size() << std::endl;


	ft::RBTree<ft::pair<const int, int>, ft::map<int, int>::value_compare, std::__1::allocator<ft::pair<const int, int> > > tree = mmap.getTree();
	ft::RBTree<ft::pair<const int, int>, ft::map<int, int>::value_compare, std::__1::allocator<ft::pair<const int, int> > >::iterator it;

	// std::cout << it._root->_value.second << std::endl;
	tree.print2D(tree._root);
	mmap.erase(2);
	
	// Errores con  2, 5

	// std::cout << tree.max() << std::endl;
	// mmap.erase(30);
	// std::cout << "   " << tree._root->_value.second << "\n" <<
	// " " << tree._root->_left->_value.second << "   " << tree._root->_right->_value.second << "\n" <<
	// tree._root->_left->_left->_value.second << " " << tree._root->_left->_right->_value.second << " " << tree._root->_right->_left->_value.second << " " << tree._root->_right->_right->_value.second
	// << "\n	" << tree._root->_right->_right->_right->_value.second << std::endl;
	// it = mmap.find(8);
	// std::cout << it._root->_value.first << std::endl;


	// std::cout << mmap.getTree()._root->_left->_value.first;
	// mmap.getTree().min();

*/

//  -----------------------------------------------------------------------------

/*
	ft::stack<int> st;

	if (st.empty())
		std::cout << "True";
	else
		std::cout << "False";

    st.push(34);

    std::cout << "Size:" << st.size() << std::endl;
    std::cout << "Empty:" << st.empty();
	if (st.empty())
		std::cout << "True";
	else
		std::cout << "False";
	std::cout << std::endl;
    std::cout << "Top:" << st.top() << std::endl;

	st.push(64);

	std::cout << stackk.empty() << std::endl;
 	std::cout << stackk.size() << std::endl;
	stackk.push(1);
	stackk.push(2);
	stackk.push(3);
	std::cout << "added 3 elements" << std::endl;
	std::cout << stackk.size() << std::endl;
	stackk.top() -= 2;
	std::cout << "Next element is now: " << stackk.top() << std::endl;
	stackk.pop();
	std::cout << stackk.size() << std::endl;
*/

	return 0;
	
}