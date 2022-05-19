/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:35:59 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/19 02:03:03 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
// #include "Stack.hpp"
#include "Map.hpp"
#include "RBTree.hpp"
#include <iostream>
#include <algorithm>
// #include <vector>

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
	
	ft::Map<int, int> mmap;
	ft::RBTree<ft::Pair<int, int>, std::less<int>, std::allocator<ft::Pair<int, int> > > t;
	ft::Pair<int, int> p3 = ft::make_pair(4, 4);
	ft::Pair<int, int> p1 = ft::make_pair(1, 1);
	ft::Pair<int, int> p2 = ft::make_pair(2, 2);
	

	mmap.insert(p1);
	std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p2);
	std::cout << mmap[0] << " " << mmap.size() << std::endl;
	mmap.insert(p3);
	std::cout << mmap[0] << " " << mmap.size() << std::endl;

	return 0;
	
}