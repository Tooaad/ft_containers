/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/09 20:36:55 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTests.hpp"
#include <list>
#include <ios>

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
        start = std::chrono::high_resolution_clock::now();
        strvector std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strvector ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(s_string, s_string);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(s_string, s_string);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        longvector std;
        end = std::chrono::high_resolution_clock::now();
        
        t1 = end - start;

        start = std::chrono::high_resolution_clock::now();
        _longvector ft;
        end = std::chrono::high_resolution_clock::now();

        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 

        start = std::chrono::high_resolution_clock::now();
        std.assign(b_long, b_long + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(b_long, b_long + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 

        start = std::chrono::high_resolution_clock::now();
        std.assign(s_long, s_long + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(s_long, s_long + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft); 
    }
    if (nextTest())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        intvector std(s_int, s_int + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft(s_int, s_int + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        std.assign(b_int, b_int + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        ft.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        ft.assign(b_int, b_int + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        intvector std(s_int, s_int + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft(s_int, s_int + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        std.assign(std.begin(), std.begin() + 21);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        ft.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        ft.assign(ft.begin(), ft.begin() + 21);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        std.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        std.assign(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        ft.push_back(64);
        start = std::chrono::high_resolution_clock::now();
        ft.assign(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        std.assign(0, 'c');
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(0, 'c');
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(64, 'A');
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(64, 'A');
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(32, '5');
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(32, '5');
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(49, '8');
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(49, '8');
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(77, '2');
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(77, '2');
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        strvector std;
        _strvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.assign(0, "");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(0, "");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(64, "vector-string");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(64, "vector-string");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        std.assign(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(65, "HelloWorld");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(65, "HelloWorld");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        doublevector std;
        _doublevector ft;

        start = std::chrono::high_resolution_clock::now();
        std.assign(b_double, b_double + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(b_double, b_double + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(65, 1.234567);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(65, 1.234567);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(65, 8765.234567);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(65, 8765.234567);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.assign(s_double, s_double + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.assign(s_double, s_double + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
        strvector std;
        strvector std1;
        _strvector ft;
        _strvector ft1;

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = strvector(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = _strvector(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std1 = strvector(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft1 = _strvector(s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std1, 0);
        CHECK_AND_PRINT_ALL(ft1, 1);
        COMPARE(std, ft);
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
            start = std::chrono::high_resolution_clock::now();
            charvector::reference c = std.at(38);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Wrong out of range exception", 38, 1);
        }
         try {
            start = std::chrono::high_resolution_clock::now();
            _charvector::reference c1 = ft.at(38);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Wrong out of range exception", 38, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
    {
        intvector std(99, 64);
        _intvector ft(99, 64);

        try {
            start = std::chrono::high_resolution_clock::now();
            intvector::reference c = std.at(99);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Out of range exception", 99, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            _intvector::reference c1 = ft.at(99);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Out of range exception", 99, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
    {
        longvector std;
        _longvector ft;

        try {
            start = std::chrono::high_resolution_clock::now();
            longvector::reference c = std.at(0);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;

            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Out of range exception", 0, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            _longvector::reference c1 = ft.at(0);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;

            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Out of range exception", 0, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
    {
        const charvector std(64, 'a');
        const _charvector ft(64, 'a');

        try {
            start = std::chrono::high_resolution_clock::now();
            charvector::const_reference c = std.at(38);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Wrong out of range exception", 38, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            _charvector::const_reference c1 = ft.at(38);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Wrong out of range exception", 38, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
    {
        const intvector std(99, 64);
        const _intvector ft(99, 64);

        try {
            start = std::chrono::high_resolution_clock::now();
            intvector::const_reference c = std.at(99);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Out of range exception", 99, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            _intvector::const_reference c1 = ft.at(99);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
             end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Out of range exception", 99, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
    {
        const longvector std;
        const _longvector ft;

        try {
            start = std::chrono::high_resolution_clock::now();
            longvector::const_reference c = std.at(0);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("At:", c, 0);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Out of range exception", 0, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            _longvector::const_reference c1 = ft.at(0);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("At:", c1, 1);
        } catch (std::out_of_range& e) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Out of range exception", 0, 1);
        }
        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", std.back(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", ft.back(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", std.back(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", ft.back(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", std.back(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", ft.back(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        start = std::chrono::high_resolution_clock::now();
        longvector::const_reference b = std.back();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", std.back(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Back:", ft.back(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

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
        start = std::chrono::high_resolution_clock::now();
        intvector std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        intvector std(1, 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft(1, 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        intvector std(64, 420);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft(64, 420);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
    std::cout << "\x1b[41m                    CTOR-COPY TEST              \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        start = std::chrono::high_resolution_clock::now();
        doublevector std(b_double, b_double + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _doublevector ft(b_double, b_double + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        doublevector std1(std);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _doublevector ft1(ft);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
        start = std::chrono::high_resolution_clock::now();
        strvector std(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strvector ft(b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        strvector std1(std);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strvector ft1(ft);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
        start = std::chrono::high_resolution_clock::now();
        intvector std(0, 123);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft(0, 123);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
        start = std::chrono::high_resolution_clock::now();
        intvector std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        intvector::iterator it = std.erase(std.begin() + 26);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::iterator it1 = ft.erase(ft.begin() + 26);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.erase(std.end() - 1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.erase(ft.end() - 1); // REVISAR TEST
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.erase(std.begin());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.erase(ft.begin());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        CHECK_AND_PRINT_ALL(std, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(1, 5);
        _intvector ft(1, 5);

        start = std::chrono::high_resolution_clock::now();
        intvector::iterator it = std.erase(std.begin());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::iterator it1 = ft.erase(ft.begin());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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
        longvector std(b_int, b_int + b_size);
        _longvector ft(b_int, b_int + b_size);
        
        start = std::chrono::high_resolution_clock::now();
        std.erase(std.end(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.end(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin() + 5, std.begin() + 5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin() + 5, ft.begin() + 5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin() + 26, std.end() - 1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin() + 26, ft.end() - 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(37, -5);
        _intvector ft(37, -5);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin() + 1, std.begin() + 2);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin() + 1, ft.begin() + 2);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        longvector std;
        _longvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin() + 2, std.begin() + 2);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin() + 2, ft.begin() + 2);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.begin());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.begin());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.end(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.end(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.end() - 1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.end() - 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin() + 3, std.begin() + 55);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin() + 3, ft.begin() + 55);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        strvector::iterator it = std.erase(std.begin() + 9);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strvector::iterator it1 = ft.erase(ft.begin() + 9);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", std.front(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", ft.front(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Front:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Front:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        longvector std(123, 543);
        longvector ft(123, 543);

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", std.front(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", ft.front(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Front:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Front:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(1, 9);
        const longvector ft(1, 9);

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", std.front(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", ft.front(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Front:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Front:", 0, 1);
        }
    }
    if (nextTest())
        return ;
    {
        const longvector std(123, 543);
        const longvector ft(123, 543);

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", std.front(), 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Front:", ft.front(), 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        if (&std.front() != &std[0]) {
            PRINT_LINE("Front:", 0, 0);
        }
        if (&ft.front() != &ft[0]) {
            PRINT_LINE("Front:", 0, 1);
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

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Index 0:", std[0], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Index 0:", ft[0], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        start = std::chrono::high_resolution_clock::now();
        intvector::reference value = std[26];
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::reference value1 = ft[26];
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        PRINT_LINE("Index 26:", value, 0);
        PRINT_LINE("Index 26:", value1, 1);

        value = -64;
        value1 = -64;

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        intvector::reference value2 = std[31];
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::reference value3 = ft[31];
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        PRINT_LINE("Index 31:", value2, 0);
        PRINT_LINE("Index 31:", value3, 1);

        value2 = -1;
        value3 = -1;

        CHECK_AND_PRINT_ALL(ft, 0);
        CHECK_AND_PRINT_ALL(std, 1);
        
        start = std::chrono::high_resolution_clock::now();
        std[14] = 0;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft[14] = 0;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        const intvector std(s_int, s_int + s_size);
        const _intvector ft(s_int, s_int + s_size);

        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Index 0:", std[0], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LINE("Index 0:", ft[0], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        start = std::chrono::high_resolution_clock::now();
        intvector::const_reference value = std[26];
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::const_reference value1 = ft[26];
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        PRINT_LINE("Index 26:", value, 0);
        PRINT_LINE("Index 26:", value1, 1);

        start = std::chrono::high_resolution_clock::now();
        intvector::const_reference value2 = std[31];
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::const_reference value3 = ft[31];
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

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

        start = std::chrono::high_resolution_clock::now();
        std.pop_back();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.pop_back();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);

        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);


        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; ++i)
            std.pop_back();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; ++i)
            ft.pop_back();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 26; ++i)
            std.push_back(45.0123);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 26; ++i)
            ft.push_back(45.0123);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.push_back(6);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.push_back(6);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.push_back(-4356.8933);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.push_back(-4356.8933);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        std.resize(14, "HelloWorld");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(14, "HelloWorld");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(6, "ABC");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(6, "ABC");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(14, b_string[18]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(14, b_string[18]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(16, b_string[57]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(16, b_string[57]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(64, "I-like-vectors");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(64, "I-like-vectors");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
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

        start = std::chrono::high_resolution_clock::now();
        std.reserve(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(45);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(45);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(65);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(65);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(79);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(79);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std(s_int, s_int + s_size);
        _intvector ft(s_int, s_int + s_size);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(32);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(32);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(33);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(33);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.reserve(1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.reserve(1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void insertTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   INSERT TEST                  \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std;
        _strvector ft;

        start = std::chrono::high_resolution_clock::now();
        strvector::iterator it = std.insert(std.end(), b_string[54]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strvector::iterator it1 = ft.insert(ft.end(), b_string[54]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), b_string[23]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), b_string[23]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin(), b_string[19]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin(), b_string[19]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin() + 1, b_string[0]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin() + 1, b_string[0]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin() + 1, b_string[1]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin() + 1, b_string[1]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin() + 2, b_string[2]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin() + 2, b_string[2]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin() + 3, b_string[3]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin() + 3, b_string[3]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft); 

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.begin() + 2, b_string[4]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.begin() + 2, b_string[4]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), b_string[5]);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), b_string[5]);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        intvector std;
        _intvector ft;

        start = std::chrono::high_resolution_clock::now();
        intvector::iterator it = std.insert(std.begin(), 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::iterator it1 = ft.insert(ft.begin(), 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), 420);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), 420);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void insertRangeTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                INSERT RANGE TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strvector std;
        _strvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), std.begin(), std.begin());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), ft.begin(), ft.begin());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), b_string, b_string + 10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), b_string, b_string + 10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 20, b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 20, b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), b_string + 10, b_string + 15);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        ft.insert(ft.end(), b_string + 10, b_string + 15);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        std::list<int> li(s_int, s_int + s_size);

        intvector std(5, 1);
        _intvector ft(5, 1);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 3, li.begin(), li.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 3, li.begin(), li.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void insertSizeTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                INSERT SIZE TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std;
        _intvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), 0, 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), 0, 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), 0, 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), 0, 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), 10, 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), 10, 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), 5, -1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), 5, -1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 1, 1, -9);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 1, 1, -9);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 7, 21, 88);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 7, 21, 88);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), 0, 2);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), 0, 2);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), 0, 4);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), 0, 4);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), 18, 420);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), 18, 420);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        std::list<int> li(s_int, s_int + s_size);

        intvector std(5, 1);
        _intvector ft(5, 1);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 3, 30, 10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 3, 30, 10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        strvector std(5000, "Test");
        _strvector ft(5000, "Test");

        try {
            start = std::chrono::high_resolution_clock::now();
            std.insert(std.begin() + 115, (std::size_t)std::numeric_limits<std::ptrdiff_t>::max(),
                     "123");
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
        } catch (std::length_error&) {
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            PRINT_LINE("Out of range exception", 0, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            ft.insert(ft.begin() + 115, (std::size_t)std::numeric_limits<std::ptrdiff_t>::max(),
                     "123");
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
        } catch (std::length_error&) {
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            PRINT_LINE("Out of range exception", 0, 1);
        }
        TIMER(t1, t2);
    }
    if (nextTest())
        return ;
}

void insertMixTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                 INSERT MIX TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intvector std;
        _intvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), s_int, s_int + s_size - 10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), s_int, s_int + s_size - 10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 5, 9, -1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 5, 9, -1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        intvector::iterator it = std.insert(std.begin(), 64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intvector::iterator it1 = ft.insert(ft.begin(), 64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        PRINT_LINE("It:", *it, 0);
        PRINT_LINE("It:", *it1, 1);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        itComp(*it, *it1);
        COMPARE(std, ft);

        for (int i = 0; i < 23; ++i) {
            it = std.insert(std.begin() + i + 2, i);
            it1 = ft.insert(ft.begin() + i + 2, i);
            PRINT_LINE("It:", *it, 0);
            PRINT_LINE("It:", *it1, 1);
            CHECK_AND_PRINT_ALL(std, 0);
            CHECK_AND_PRINT_ALL(ft, 1);
            itComp(*it, *it1);
            COMPARE(std, ft);
        }

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), 12, 42);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), 12, 42);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 12, b_int, b_int + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 12, b_int, b_int + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), 69);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), 69);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
    {
        strvector std;
        _strvector ft;

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end(), s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end(), s_string, s_string + s_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.end() - 10, b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.end() - 10, b_string, b_string + b_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin(), "Hello");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin(), "Hello");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 1, "World");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 1, "World");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std.begin() + 2, 9, "!");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft.begin() + 2, 9, "!");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void reverseIteratorCompTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m          REVERSE ITER COMPARATOR TEST          \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        _intvector ft(b_int, b_int + b_size);

        _intvector::reverse_iterator it = ft.rbegin();
        _intvector::reverse_iterator it2 = ft.rbegin();
        _intvector::const_reverse_iterator cit = ft.rbegin();
        _intvector::const_reverse_iterator cit2 = ft.rbegin();

        if (it == ft.rbegin()) {
            PRINT_LINE("Equal iterators", 0, 1);
        }
        if (cit == ft.rbegin()) {
            PRINT_LINE("Equal const iterators", 0, 1);
        }
        if (cit == it) {
           PRINT_LINE("Equal const iterators", 0, 1);
        }

        ++it;
        cit += 6;

        if (it != ft.rend()) {
            PRINT_LINE("Not Equal iterators", 0, 1);
        }
        if (cit != ft.rend()) {
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

void swapTest() {
    SETUP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m          REVERSE ITER COMPARATOR TEST          \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
        {
        strvector std(s_string, s_string + s_size);
        strvector std1(b_string, b_string + b_size);
        _strvector ft(s_string, s_string + s_size);
        _strvector ft1(b_string, b_string + b_size);

        start = std::chrono::high_resolution_clock::now();
        std.swap(std1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.swap(ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std::swap(std, std1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft::swap(ft, ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(0);
        std.swap(std1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(0);
        ft.swap(ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.resize(0);
        std::swap(std, std1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.resize(0);
        ft::swap(ft, ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER(t1, t2);
        CHECK_AND_PRINT_ALL(std, 0);
        CHECK_AND_PRINT_ALL(ft, 1);
        COMPARE(std, ft);
    }
    if (nextTest())
        return ;
}

void runVectTests() {
    
    insertTest();
    insertSizeTest();
    insertRangeTest();
    insertMixTest();
    reserveTest();
    assignTest();
    assignRangeTest();
    assignMixedTest();
    atTest();               //
    backTest();             //
    clearTest();
    ctor_copy();            //
    frontTest();            //
    emptyTest();
    eraseTest();
    eraseRangeTest();
    eraseMixTest();
    indexOpTest();
    iteratorCompTest();     //
    operatorEquals();
    pushbackTest();
    popbackTest();
    resizeTest();
    reverseIteratorCompTest();
    swapTest();
    
}
