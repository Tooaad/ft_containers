/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:35:59 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/19 02:13:30 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <iostream>
#include <algorithm>

void print (const std::string & n) { std::cout << " " << n; };
void print2 (const int & n) { std::cout << n << " "; };
void cleaks() { system("leaks containers"); }


int main()
{
	atexit(cleaks);
	ft::Vector<int> mvector1(7, 1);
	ft::Vector<int> mvector2;
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
/*
	mvector1.insert(mvector2.begin() + 1, 8);
	std::cout << "Result: should insert 8 in 2nd position: " << "\n";
	std::for_each(mvector2.begin(), mvector2.end(), print2); std::cout << "\n";
	mvector2.insert(mvector2.begin(), mvector1.begin(), mvector1.end());
	
// // ERASE
// 	mvector2.erase(mvector2.begin()+2 , mvector2.end());
// 	std::for_each(mvector2.begin(), mvector2.end(), print2);
	
	*/
	
	return 0;
	
}