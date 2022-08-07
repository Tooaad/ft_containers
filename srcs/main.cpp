/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:35:59 by gpernas-          #+#    #+#             */
/*   Updated: 2022/08/07 12:45:46 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vector.hpp"
#include "../includes/Stack.hpp"
#include "../includes/Map.hpp"
#include "../includes/RBTree.hpp"
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <stack>

void print (const std::string & n) { std::cout << " " << n; };
void print2 (const int & n) { std::cout << n << " "; };
void cleaks() { system("leaks containers"); }

int main()
{
	// atexit(cleaks);
	// ft::Vector<int> mvector1(0, 10);
	// ft::Vector<int> mvector2;

/*
// Begin & End normal
	std::cout << "Instantiate Vector with 2 params with value 1: "; 
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	std::cout << "Instantiate Vector with no params: ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "\n";
// // PUSHB
	mvector2.push_back(10);
	mvector2.push_back(11);
	mvector2.push_back(12);
	mvector2.push_back(13);
	std::cout << "Add 10, 11, 12, 13 to the Empty Vector ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "\n";

// // POPB
	mvector2.pop_back();
	mvector1.pop_back();
	std::cout << "Removes last element from Vector2(no 13) ";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "Removes last element from Vector1(only 1) ";
	std::for_each(mvector1.begin(), mvector1.end(), print2); std::cout << "\n";
	std::cout << "\n";

// ElementAccess
	std::cout << "Element Access: " << "\n";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	std::cout << "Vector element [0]: " << mvector2[0] << "\n";
	std::cout << "Vector element at 0: " << mvector2.at(0) << "\n";
	std::cout << "Vector element front: " << mvector2.front() << "\n";
	std::cout << "Vector element back: " << mvector2.back() << "\n";
	std::cout << "Vector element size: " << mvector2.size() << "\n";
	std::cout << "Vector element capacity: " << mvector2.capacity() << "\n"; 
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
	ft::Vector<int> mvector3;
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

	ft::Vector<int> mvector4;

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

// MY MAP ------------------------------------------------------------
	
	ft::Map<int, int> mmap;
	ft::Pair<int, int> p3 = ft::make_pair(2, 2);
	ft::Pair<int, int> p2 = ft::make_pair(5, 5);
	ft::Pair<int, int> p4 = ft::make_pair(9, 9);
	ft::Pair<int, int> p5 = ft::make_pair(10, 10);
	ft::Pair<int, int> p6 = ft::make_pair(30, 30);
	ft::Pair<int, int> p7 = ft::make_pair(25, 25);
	ft::Pair<int, int> p8 = ft::make_pair(40, 40);
	ft::Pair<int, int> p9 = ft::make_pair(38, 38);
	

	// std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p3);
	// std::cout << &mmap.find(1)._root->_value._first << " " << &mmap.begin()._root->_value._first << std::endl;
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
	// std::cout << mmap[1] << " " << mmap.size() << std::endl;


	ft::RBTree<ft::Pair<const int, int>, ft::Map<int, int>::value_compare, std::__1::allocator<ft::Pair<const int, int> > > tree = mmap.getTree();
	ft::RBTree<ft::Pair<const int, int>, ft::Map<int, int>::value_compare, std::__1::allocator<ft::Pair<const int, int> > >::iterator it;

	// std::cout << it._root->_value._second << std::endl;
	tree.print2D(tree._root);
	mmap.erase(10);
	// std::cout << tree.max() << std::endl;
	// mmap.erase(30);
	// std::cout << "   " << tree._root->_value._second << "\n" <<
	// " " << tree._root->_left->_value._second << "   " << tree._root->_right->_value._second << "\n" <<
	// tree._root->_left->_left->_value._second << " " << tree._root->_left->_right->_value._second << " " << tree._root->_right->_left->_value._second << " " << tree._root->_right->_right->_value._second
	// << "\n	" << tree._root->_right->_right->_right->_value._second << std::endl;
	// it = mmap.find(8);
	// std::cout << it._root->_value._first << std::endl;


	// std::cout << mmap.getTree()._root->_left->_value._first;
	// mmap.getTree().min();



//  -----------------------------------------------------------------------------

/*
	ft::Stack<int> stackk;

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