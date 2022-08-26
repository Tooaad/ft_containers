/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/08/27 00:34:30 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"
#include "VectorTests.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>

int nextTest() {
    std::string action;
    std::getline(std::cin, action);
    if (action == "q") {
        std::cout << "\33c\e[3J" << std::endl;
        return 1;
    }
    std::cout << "\33c\e[3J" << std::endl;
    return 0;
}

void assignRangeTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m               ASSIGN RANGE TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std;
        _strvector ft;
   
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(b_string, b_string + b_size);
        ft.assign(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(s_string, s_string + s_size);
        ft.assign(s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(s_string, s_string);
        ft.assign(s_string, s_string);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        longvector std;
        _longvector ft;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 

        std.assign(b_long, b_long + b_size);
        ft.assign(b_long, b_long + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 

        std.assign(s_long, s_long + s_size);
        ft.assign(s_long, s_long + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 
    }
    if (nextTest())
        return ;
    {
        intvector std(s_int, s_int + s_size);
        _intvector ft(s_int, s_int + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 

        std.push_back(64);
        std.assign(b_int, b_int + b_size);
        ft.push_back(64);
        ft.assign(b_int, b_int + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(s_int, s_int + s_size);
        _intvector ft(s_int, s_int + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(64);
        std.assign(std.begin(), std.begin() + 21);
        ft.push_back(64);
        ft.assign(ft.begin(), ft.begin() + 21);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(64);
        std.assign(std.begin(), std.end());
        ft.push_back(64);
        ft.assign(ft.begin(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void assignTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  ASSIGN TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        charvector std;
        _charvector ft;

        std.assign(0, 'c');
        ft.assign(0, 'c');

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(64, 'A');
        ft.assign(64, 'A');

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(32, '5');
        ft.assign(32, '5');

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(49, '8');
        ft.assign(49, '8');

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(77, '2');
        ft.assign(77, '2');

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        strvector std;
        _strvector ft;

        std.assign(0, "");
        ft.assign(0, "");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(64, "vector-string");
        ft.assign(64, "vector-string");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void assignMixedTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                ASSIGN MIXED TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std;
        _strvector ft;

        std.assign(b_string, b_string + b_size);
        ft.assign(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(65, "HelloWorld");
        ft.assign(65, "HelloWorld");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(s_string, s_string + s_size);
        ft.assign(s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        doublevector std;
        _doublevector ft;

        std.assign(b_double, b_double + b_size);
        ft.assign(b_double, b_double + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(65, 1.234567);
        ft.assign(65, 1.234567);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(65, 8765.234567);
        ft.assign(65, 8765.234567);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.assign(s_double, s_double + s_size);
        ft.assign(s_double, s_double + s_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void operatorEquals() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  OPERATOR= TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std1;
        strvector std2;
        _strvector ft1;
        _strvector ft2;

        std1 = std2;
        ft1 = ft2;

        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);
        

        std2 = strvector(b_string, b_string + b_size);
        ft2 = _strvector(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(std2, 0);
        CHECK_AND_PRINT_ALL(ft2, 1);

        std1 = std2;
        ft1 = ft2;

        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);

        std2 = strvector(s_string, s_string + s_size);
        ft2 = _strvector(s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(std2, 0);
        CHECK_AND_PRINT_ALL(ft2, 1);

        std1 = std2;
        ft1 = ft2;

        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);
    }
    if (nextTest())
        return ;
}

void atTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      AT TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        charvector std(64, 'a');
        _charvector ft(64, 'a');

        try {
            charvector::reference c = ft.at(38);
            _charvector::reference c1 = ft.at(38);
            PRINT_LINE("At:", c, 0);
            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 38, 1);
        }
    }
    if (nextTest())
        return ;
    {
        intvector std(99, 64);
        _intvector ft(99, 64);

        try {
            _intvector::reference c1 = ft.at(99);

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99, 1);
        }
        try {
            intvector::reference c = std.at(99);

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99, 0);
        }
    }
    if (nextTest())
        return ;
    {
        longvector std;
        _longvector ft;

        try {
            _longvector::reference c1 = ft.at(0);

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0, 1);
        }
        try {
            longvector::reference c = std.at(0);

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0, 0);
        }
    }
    if (nextTest())
        return ;
    {
        const charvector std(64, 'a');
        const _charvector ft(64, 'a');


        try {
            _charvector::const_reference c1 = ft.at(38);

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 38, 1);
        }
        try {
            charvector::const_reference c = std.at(38);

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 38, 0);
        }
    }
    if (nextTest())
        return ;
    {
        const intvector std(99, 64);
        const _intvector ft(99, 64);

        try {
            _intvector::const_reference c1 = ft.at(99);

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99, 1);
        }
        try {
            intvector::const_reference c = std.at(99);

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99, 0);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std;
        const _longvector ft;

        try {
            _longvector::const_reference c1 = ft.at(0);

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0, 1);
        }
        try {
            longvector::const_reference c = std.at(0);

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0, 0);
        }
    }
    if (nextTest())
        return ;
}

void backTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      BACK TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        longvector std(1, 9);
        _longvector ft(1, 9);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.back() != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.back() != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        longvector std(123, 543);
        _longvector ft(123, 543);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.back() != &std[122]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.back() != &ft[122]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(1, 9);
        const _longvector ft(1, 9);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        longvector::const_reference b = std.back();
        _longvector::const_reference b1 = ft.back();
        if (&b != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&b1 != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(123, 543);
        const _longvector ft(123, 543);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        longvector::const_reference b = std.back();
        _longvector::const_reference b1 = ft.back();
        if (&b != &std[122]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&b1 != &ft[122]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
}

void clearTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                    CLEAR TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std;
        _intvector ft;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.clear();
        ft.clear();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(1, 64);
        _intvector ft(1, 64);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.clear();
        ft.clear();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.clear();
        ft.clear();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(64, 420);
        _intvector ft(64, 420);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.clear();
        ft.clear();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.clear();
        ft.clear();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void ctor_copy() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                    CTOR TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        doublevector std(b_double, b_double + b_size);
        _doublevector ft(b_double, b_double + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        doublevector std1(std);
        _doublevector ft1(ft);

        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);

        if (&std[0] == &std1[0]) {
           PRINT_LINE("Copy ctor doesn't do a deep copy!", 0, 0);
        }
        if (&ft[0] == &ft1[0]) {
            PRINT_LINE("Copy ctor doesn't do a deep copy!", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        strvector std(b_string, b_string + b_size);
        _strvector ft(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        strvector std1(std);
        _strvector ft1(ft);

        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);

        if (&std[0] == &std1[0]) {
           PRINT_LINE("Copy ctor doesn't do a deep copy!", 0, 0);
        }
        if (&ft[0] == &ft1[0]) {
            PRINT_LINE("Copy ctor doesn't do a deep copy!", 0, 1);
        }
    }
    if (nextTest())
        return ;
}
void emptyTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                    CLEAR TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std(0, 123);
        _intvector ft(0, 123);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        if (std.empty()) {
            PRINT_LINE("EMPTY!", 0, 0);
        }
        if (ft.empty()) {
            PRINT_LINE("EMPTY!", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        intvector std;
        _intvector ft;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);

        if (std.empty()) {
            PRINT_LINE("EMPTY!", 0, 0);
        }
        if (ft.empty()) {
            PRINT_LINE("EMPTY!", 0, 1);
        }
    }
    if (nextTest())
        return ;
}

void eraseTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   ERASE TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std(b_int, b_int + b_size - 5);
        _intvector ft(b_int, b_int + b_size - 5);

        intvector::iterator it = std.erase(std.begin() + 26);
        _intvector::iterator it1 = ft.erase(ft.begin() + 26);

        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        it = std.erase(it);
        it1 = ft.erase(it1);

        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        it = std.erase(std.end() - 1);
        it1 = ft.erase(ft.end() - 1); // REVISAR TEST

        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        it = std.erase(std.begin());
        it1 = ft.erase(ft.begin());

        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(1, 5);
        _intvector ft(1, 5);

        intvector::iterator it = std.erase(std.begin());
        _intvector::iterator it1 = ft.erase(ft.begin());

        if (it != std.end()) {
            PRINT_LINE("Wrong iterator", *it, 0);
        }
        CHECK_AND_PRINT_ALL(std, 0);
        if (it1 != ft.end()) {
            PRINT_LINE("Wrong iterator", *it1, 1);
        }
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void eraseRangeTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                ERASE RANGE TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;

    {
        longvector std;
        _longvector ft;

        std.erase(std.begin(), std.end());
        ft.erase(ft.begin(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        longvector std(b_int, b_int + b_size);
        _longvector ft(b_int, b_int + b_size);

        std.erase(std.end(), std.end());
        ft.erase(ft.end(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin() + 5, std.begin() + 5);
        ft.erase(ft.begin() + 5, ft.begin() + 5);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin() + 26, std.end() - 1);
        ft.erase(ft.begin() + 26, ft.end() - 1);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(37, -5);
        _intvector ft(37, -5);

        std.erase(std.begin() + 1, std.begin() + 2);
        ft.erase(ft.begin() + 1, ft.begin() + 2);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin(), std.end());
        ft.erase(ft.begin(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void eraseMixTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                ERASE MIX TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std(b_string, b_string + b_size);
        _strvector ft(b_string, b_string + b_size);

        std.erase(std.begin() + 2, std.begin() + 2);
        ft.erase(ft.begin() + 2, ft.begin() + 2);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin(), std.begin());
        ft.erase(ft.begin(), ft.begin());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.end(), std.end());
        ft.erase(ft.end(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin());
        ft.erase(ft.begin());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.end() - 1);
        ft.erase(ft.end() - 1);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);


        std.erase(std.begin() + 3, std.begin() + 16);
        ft.erase(ft.begin() + 3, ft.begin() + 16);
        
        // std::cout << *(std.begin() + 17) << "---" << *(ft.begin() + 17) << std::endl;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        strvector::iterator it = std.erase(std.begin() + 9);
        _strvector::iterator it1 = ft.erase(ft.begin() + 9);

        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.erase(std.begin(), std.end());
        ft.erase(ft.begin(), ft.end());

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void frontTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   FRONT TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        longvector std(1, 9);
        _longvector ft(1, 9);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        longvector std(123, 543);
        longvector ft(123, 543);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(1, 9);
        const longvector ft(1, 9);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(123, 543);
        const longvector ft(123, 543);

        PRINT_LINE("Back:", std.back(), 0);
        PRINT_LINE("Back:", ft.back(), 1);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Back:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Back:", 0, 1);
        }
    }
    if (nextTest())
        return ;
}

void indexOpTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                OPERATOR[] TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;

    {
        intvector std(s_int, s_int + s_size);
        _intvector ft(s_int, s_int + s_size);

        PRINT_LINE("Index 0:", std[0], 0);
        PRINT_LINE("Index 0:", ft[0], 1);

        intvector::reference value = std[26];
        _intvector::reference value1 = ft[26];

        PRINT_LINE("Index 26:", value, 0);
        PRINT_LINE("Index 26:", value1, 1);

        value = -64;
        value1 = -64;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        intvector::reference value2 = std[31];
        _intvector::reference value3 = ft[31];

        PRINT_LINE("Index 31:", value2, 0);
        PRINT_LINE("Index 31:", value3, 1);

        value2 = -1;
        value3 = -1;

        CHECK_AND_PRINT_ALL(ft, 0);
        CHECK_AND_PRINT_ALL(std, 1);

        std[14] = 0;
        ft[14] = 0;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        const intvector std(s_int, s_int + s_size);
        const _intvector ft(s_int, s_int + s_size);

        PRINT_LINE("Index 0:", std[0], 0);
        PRINT_LINE("Index 0:", ft[0], 1);

        intvector::const_reference value = std[26];
        _intvector::const_reference value1 = ft[26];

        PRINT_LINE("Index 26:", value, 0);
        PRINT_LINE("Index 26:", value1, 1);

        intvector::const_reference value2 = std[31];
        _intvector::const_reference value3 = ft[31];

        PRINT_LINE("Index 31:", value2, 0);
        PRINT_LINE("Index 31:", value3, 1);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void iteratorCompTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m              ITER COMPARATOR TEST              \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        _intvector ft(b_int, b_int + b_size);

        _intvector::iterator it = ft.begin();
        _intvector::iterator it2 = ft.begin();
        _intvector::const_iterator cit = ft.begin();
        _intvector::const_iterator cit2 = ft.begin();

        if (it == ft.begin()) {
            PRINT_LINE("Equal iterators", 0, 1);
        }
        if (cit == ft.begin()) {
            PRINT_LINE("Equal const iterators", 0, 1);
        }
        if (cit == it) {
           PRINT_LINE("Equal const iterators", 0, 1);
        }

        ++it;
        cit += 6;

        if (it != ft.end()) {
            PRINT_LINE("Not Equal iterators", 0, 1);
        }
        if (cit != ft.end()) {
            PRINT_LINE("Not Equal const iterators", 0, 1);
        }
        if (cit != it) {
            PRINT_LINE("Not Equal const iterators", 0, 1);
        }

        if (it < it + 1) {
            PRINT_LINE("Less Than", 0, 1);
        }
        if (it + 1 < it) {
            PRINT_LINE("Less Than.", 0, 1);
        }
        if (it < it) {
            PRINT_LINE("Less Than..", 0, 1);
        }
        if (cit < cit + 1) {
            PRINT_LINE("Less Than...", 0, 1);
        }
        if (cit + 1 < cit) {
            PRINT_LINE("Less Than....", 0, 1);
        }
        if (cit < cit) {
            PRINT_LINE("Less Than.....", 0, 1);
        }
        if (it2 < cit2 + 1) {
            PRINT_LINE("Less Than......", 0, 1);
        }
        if (it2 < cit2) {
            PRINT_LINE("Less Than.......", 0, 1);
        }

        if (it <= it + 1) {
            PRINT_LINE("Less Than or equal", 0, 1);
        }
        if (it + 1 <= it) {
            PRINT_LINE("Less Than or equal.", 0, 1);
        }
        if (it <= it) {
            PRINT_LINE("Less Than or equal..", 0, 1);
        }
        if (cit <= cit + 1) {
            PRINT_LINE("Less Than or equal...", 0, 1);
        }
        if (cit + 1 <= cit) {
            PRINT_LINE("Less Than or equal...", 0, 1);
        }
        if (cit <= cit) {
            PRINT_LINE("Less Than or equal....", 0, 1);
        }
        if (it2 <= cit2 + 1) {
            PRINT_LINE("Less Than or equal.....", 0, 1);
        }
        if (it2 <= cit2) {
            PRINT_LINE("Less Than or equal......", 0, 1);
        }

        if (it > it + 1) {
            PRINT_LINE("Greater Than", 0, 1);
        }
        if (it + 1 > it) {
            PRINT_LINE("Greater Than.", 0, 1);
        }
        if (it > it) {
            PRINT_LINE("Greater Than..", 0, 1);
        }
        if (cit > cit + 1) {
            PRINT_LINE("Greater Than...", 0, 1);
        }
        if (cit + 1 > cit) {
            PRINT_LINE("Greater Than....", 0, 1);
        }
        if (cit > cit) {
            PRINT_LINE("Greater Than.....", 0, 1);
        }
        if (it2 + 1 > cit2) {
            PRINT_LINE("Greater Than.....", 0, 1);
        }
        if (it2 > cit2) {
            PRINT_LINE("Greater Than......", 0, 1);
        }

        if (it >= it + 1) {
            PRINT_LINE("Greater Than or equal", 0, 1);
        }
        if (it + 1 >= it) {
            PRINT_LINE("Greater Than or equal.", 0, 1);
        }
        if (it >= it) {
            PRINT_LINE("Greater Than or equal..", 0, 1);
        }
        if (cit >= cit + 1) {
            PRINT_LINE("Greater Than or equal...", 0, 1);
        }
        if (cit + 1 >= cit) {
            PRINT_LINE("Greater Than or equal....", 0, 1);
        }
        if (cit >= cit) {
            PRINT_LINE("Greater Than or equal.....", 0, 1);
        }
        if (it2 >= cit2 + 1) {
            PRINT_LINE("Greater Than or equal......", 0, 1);
        }
        if (it2 + 1 >= cit2) {
            PRINT_LINE("Greater Than or equal.......", 0, 1);
        }
        if (it2 >= cit2) {
            PRINT_LINE("Greater Than or equal........", 0, 1);
        }
    }
    if (nextTest())
        return ;
}

void popbackTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  POPBACK TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        longvector std(s_long, s_long + s_size);
        _longvector ft(s_long, s_long + s_size);

        std.pop_back();
        ft.pop_back();

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        for (int i = 0; i < 10; ++i) {
            std.pop_back();
            ft.pop_back();
        }

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void pushbackTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                 PUSHBACK TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        doublevector std;
        _doublevector ft;

        for (int i = 0; i < 26; ++i) {
            std.push_back(45.0123);
            ft.push_back(45.0123);
        }
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(6);
        ft.push_back(6);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(-4356.8933);
        ft.push_back(-4356.8933);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void resizeTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  RESIZE TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std;
        _strvector ft;

        std.resize(14, "HelloWorld");
        ft.resize(14, "HelloWorld");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.resize(6, "ABC");
        ft.resize(6, "ABC");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.resize(14, b_string[18]);
        ft.resize(14, b_string[18]);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.resize(16, b_string[57]);
        ft.resize(16, b_string[57]);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.resize(64, "I-like-vectors");
        ft.resize(64, "I-like-vectors");

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void reserveTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  RESERVE TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std;
        _intvector ft;

        std.reserve(64);
        ft.reserve(64);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(64);
        ft.reserve(64);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(0);
        ft.reserve(0);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(45);
        ft.reserve(45);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(65);
        ft.reserve(65);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(79);
        ft.reserve(79);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }

    {
        intvector std(s_int, s_int + s_size);
        _intvector ft(s_int, s_int + s_size);

        std.reserve(0);
        ft.reserve(0);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(32);
        ft.reserve(32);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(48);
        ft.reserve(48);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.reserve(1);
        ft.reserve(1);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
}

void runTests() {

    reserveTest();
    resizeTest();

    // eraseMixTest();             //TEST
    // eraseRangeTest();           //TEST
    // eraseTest();                //TEST
    //INSERT FINAL
    
    pushbackTest();
    assignTest();
    assignRangeTest();
    assignMixedTest();
    operatorEquals();       //
    atTest();               //
    backTest();             //
    emptyTest();
    clearTest();
    ctor_copy();            //
    frontTest();            //
    indexOpTest();
    iteratorCompTest();     //
    popbackTest();

}

        // std::cout << std[0] << "----" << ft[0] << std::endl;
        // exit(1);