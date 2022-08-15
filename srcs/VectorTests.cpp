/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/08/15 17:17:56 by gpernas-         ###   ########.fr       */
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

void runTests() {
    assignTest();
    assignRangeTest();
    assignMixedTest();

}

        // std::cout << std[0] << "----" << ft[0] << std::endl;
        // exit(1);