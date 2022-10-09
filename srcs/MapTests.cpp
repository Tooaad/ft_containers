/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/09 13:25:00 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapTests.hpp"
#include <list>
#include <ios>


int nextTes() {
    std::string action;
    std::getline(std::cin, action);
    if (action == "q") {
        std::cout << "\33c\e[3J" << std::endl;
        return 1;
    }
    std::cout << "\33c\e[3J" << std::endl;
    return 0;
}

void ctorTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                    CTOR TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        start = std::chrono::high_resolution_clock::now();
        intmap std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void ctorRangeTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                CTOR RANGE TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        start = std::chrono::high_resolution_clock::now();
        intmap std(std_intstr_arr, std_intstr_arr + 3, std::less<int>());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 3, std::less<int>());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        intmap std2(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap ft2(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);      
        PRINT_AL(std2, 0);
        PRINT_AL(ft2, 1);
    }
    if (nextTes())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        strmap std(std_strstr_arr, std_strstr_arr + 8);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 8);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        start = std::chrono::high_resolution_clock::now();
        strmap std1(std_strstr_arr, std_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap ft1(ft_strstr_arr, ft_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
    }
    if (nextTes())
        return ;
}

void ctorCopyTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                 CTOR COPY TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        start = std::chrono::high_resolution_clock::now();
        intmap std(std_intstr_arr, std_intstr_arr + 3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 3);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        intmap std1(std);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap ft1(ft);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        start = std::chrono::high_resolution_clock::now();
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        start = std::chrono::high_resolution_clock::now();
        strmap std1(std);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap ft1(ft);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void opEqualsTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                 OPERATOR= TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std;
        intmap std1;
        _intmap ft;
        _intmap ft1;

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = intmap(std_intstr_arr, std_intstr_arr + intstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = _intmap(ft_intstr_arr, ft_intstr_arr + intstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std1 = std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft1 = ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = intmap(std_intstr_arr, std_intstr_arr + 10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = _intmap(ft_intstr_arr, ft_intstr_arr + 10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std1 = std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft1 = ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        strmap std;
        strmap std1;
        _strmap ft;
        _strmap ft1;

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std1 = strmap(std_strstr_arr, std_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft1 = _strmap(ft_strstr_arr, ft_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = std1;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = ft1;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std = strmap(std_strstr_arr, std_strstr_arr + 10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft = _strmap(ft_strstr_arr, ft_strstr_arr + 10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std1 = std;
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft1 = ft;
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}
void atMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                     AT TEST                    \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std;
        _intmap ft;

        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = std.at(6);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = ft.at(6);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);

        std.insert(std::make_pair("Hello", "World"));
        ft.insert(ft::make_pair("Hello", "World"));
        
        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = std.at("Hello");
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = ft.at("Hello");
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        strmap std(std_strstr_arr, std_strstr_arr + 1);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 1);

        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = std.at("");
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            std::string& x = ft.at("");
            end = std::chrono::high_resolution_clock::now();
            t2= end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        const intmap std;
        const _intmap ft;

        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = std.at(6);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = ft.at(6);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        intmap std1(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft1(ft_intstr_arr, ft_intstr_arr + intstr_size);

        std1.insert(std::make_pair(64, "64"));
        ft1.insert(ft::make_pair(64, "64"));
        
        const intmap std(std1);
        const _intmap ft(ft1);

        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = std.at(64);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 64, 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = ft.at(64);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 64, 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        strmap std1(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft1(ft_strstr_arr, ft_strstr_arr + strstr_size);

        std1.insert(std::make_pair("Hello", "World"));
        ft1.insert(ft::make_pair("Hello", "World"));
        
        const strmap std(std1);
        const _strmap ft(ft1);

        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = std.at("Hello");
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = ft.at("Hello");
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 1);
        }
        TIMER_(t1, t2);
    }
    PRINT_LIN("", "", 0);
    {
        const strmap std(std_strstr_arr, std_strstr_arr + 1);
        const _strmap ft(ft_strstr_arr, ft_strstr_arr + 1);

        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = std.at("");
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
            
            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 0);
        }
        try {
            start = std::chrono::high_resolution_clock::now();
            const std::string& x = ft.at("");
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            
            PRINT_LIN("At:", x, 1);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 1);
        }
        TIMER_(t1, t2);
    }
    if (nextTes())
        return ;
}

void opIndexTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                 OPERATOR[] TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std[64], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft[64], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        PRINT_SIZ(ft);
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std[64] = "Hello";
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft[64] = "Hello";
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        
        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std[64], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft[64], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        PRINT_SIZ(ft);
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std[0], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft[0], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        PRINT_SIZ(ft);
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std[0] = "ABCDEF";
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft[0] = "ABCDEF";
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std[64], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft[64], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        PRINT_SIZ(ft);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);

        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std["CBCId4lUU6oYms60JkNr"], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft["CBCId4lUU6oYms60JkNr"], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        PRINT_SIZ(ft);
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std["1IRLC9sfQI5AzDYeotLd"] = "World";
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft["1IRLC9sfQI5AzDYeotLd"] = "World";
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_SIZ(std);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", std["1IRLC9sfQI5AzDYeotLd"], 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Value:", ft["1IRLC9sfQI5AzDYeotLd"], 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        PRINT_SIZ(ft);
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void clearMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   CLEAR TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strmap std;
        _strmap ft;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr, std_strstr_arr + 15);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr, ft_strstr_arr + 15);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.clear();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.clear();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft); 
    }
    if (nextTes())
        return ;
}

void emptyMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   EMPTY TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strmap std;
        _strmap ft;

        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        COMPAR(std, ft);

        std.insert(std::make_pair("Hello", "World"));
        ft.insert(ft::make_pair("Hello", "World"));

        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        COMPAR(std, ft);

        std.erase(std.begin());
        ft.erase(ft.begin());

        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        COMPAR(std, ft);
    }

    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);
        
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}
void countTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                   COUNT TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        start = std::chrono::high_resolution_clock::now();
        intmap::size_type c = std.count(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::size_type c1 = ft.count(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);
        
        start = std::chrono::high_resolution_clock::now();
        c = std.count(145);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(145);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(11);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(11);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        std.insert(std::make_pair(34, "seiurhg8347wo83twerw"));
        std.insert(std::make_pair(2, "dsghesrzarherheat43"));
        std.insert(std::make_pair(9, "awgfawe4t3A4YSDFGAS"));
        std.insert(std::make_pair(3, "dzfg45yrthsdfgshju"));
        std.insert(std::make_pair(22, "j564wedfshgj6ee5yegrs"));
        std.insert(std::make_pair(10, "cfngcvcx56;oiliuee"));

        std::cout << "-----" << std::endl;
        ft.insert(ft::make_pair(34, "seiurhg8347wo83twerw"));
        ft.insert(ft::make_pair(2, "dsghesrzarherheat43"));
        ft.insert(ft::make_pair(9, "awgfawe4t3A4YSDFGAS"));
        ft.insert(ft::make_pair(3, "dzfg45yrthsdfgshju"));
        ft.insert(ft::make_pair(22, "j564wedfshgj6ee5yegrs"));
        ft.insert(ft::make_pair(10, "cfngcvcx56;oiliuee"));

        start = std::chrono::high_resolution_clock::now();
        c = std.count(34);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(34);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(2);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(2);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(9);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(9);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        std.erase(9);
        ft.erase(9);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(9);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(9);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(10);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(10);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        start = std::chrono::high_resolution_clock::now();
        c = std.count(22);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        c1 = ft.count(22);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);
    }
    if (nextTes())
        return ;
}

void lowerBoundTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                LOWERBOUND TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        std.insert(std::make_pair(34, "kljd9834iuhwet"));
        std.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
        std.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
        std.insert(std::make_pair(89548945894, "jtt5454wujtjse"));
        std.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
        std.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        std.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        std.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
        std.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        std.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        std.insert(std::make_pair(453834782, "juytje54yaerdrj"));
        std.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
        std.insert(std::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

        ft.insert(ft::make_pair(34, "kljd9834iuhwet"));
        ft.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
        ft.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
        ft.insert(ft::make_pair(89548945894, "jtt5454wujtjse"));
        ft.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
        ft.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        ft.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        ft.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
        ft.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        ft.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        ft.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
        ft.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
        ft.insert(ft::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

        start = std::chrono::high_resolution_clock::now();
        intmap::iterator b = std.lower_bound(98583944);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::iterator b1 = ft.lower_bound(98583944);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(239485948);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(239485948);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(19458942);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(19458942);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(19458941);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(19458941);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(19458943);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(19458943);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);
        
        start = std::chrono::high_resolution_clock::now();        
        b = std.lower_bound(-1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(-1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(3);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(4);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(4);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.lower_bound(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.lower_bound(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);
    }
    if (nextTes())
        return ;
}

void upperBoundTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                UPPERBOUND TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        std.insert(std::make_pair(34, "kljd9834iuhwet"));
        std.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
        std.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
        std.insert(std::make_pair(89548945894, "jtt5454wujtjse"));
        std.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
        std.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        std.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        std.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
        std.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        std.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        std.insert(std::make_pair(453834782, "juytje54yaerdrj"));
        std.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
        std.insert(std::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

        ft.insert(ft::make_pair(34, "kljd9834iuhwet"));
        ft.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
        ft.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
        ft.insert(ft::make_pair(89548945894, "jtt5454wujtjse"));
        ft.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
        ft.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        ft.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        ft.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
        ft.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        ft.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        ft.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
        ft.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
        ft.insert(ft::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

        start = std::chrono::high_resolution_clock::now();
        intmap::iterator b = std.upper_bound(98583944);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::iterator b1 = ft.upper_bound(98583944);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(239485948);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(239485948);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(19458942);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(19458942);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(19458941);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(19458941);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(19458943);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(19458943);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);
        
        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(-1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(-1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(3);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        start = std::chrono::high_resolution_clock::now();
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(4);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(4);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        b = std.upper_bound(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        b1 = ft.upper_bound(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_BOUND(b, std.end(), 0);
        PRINT_BOUND(b1, ft.end(), 1);
    }
    if (nextTes())
        return ;
}

void eqRangeTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                EQUAL_RANGE TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        std.insert(std::make_pair(34, "kljd9834iuhwet"));
        std.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
        std.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
        std.insert(std::make_pair(1954894589, "jtt5454wujtjse"));
        std.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
        std.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        std.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        std.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
        std.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        std.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        std.insert(std::make_pair(453834782, "juytje54yaerdrj"));
        std.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
        std.insert(std::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        ft.insert(ft::make_pair(34, "kljd9834iuhwet"));
        ft.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
        ft.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
        ft.insert(ft::make_pair(1954894589, "jtt5454wujtjse"));
        ft.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
        ft.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        ft.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        ft.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
        ft.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        ft.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        ft.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
        ft.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
        ft.insert(ft::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        start = std::chrono::high_resolution_clock::now();
        std::pair<intmap::iterator, intmap::iterator> eq = std.equal_range(98583944);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();ft::pair<_intmap::iterator, _intmap::iterator>
        eq1 = ft.equal_range(98583944);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(209485948);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(209485948);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458942);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458942);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458941);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458941);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458943);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458943);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(-1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(-1);
                end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(3);
                end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(4);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(4);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        std.insert(std::make_pair(std::numeric_limits<int>::max(), "max"));
        ft.insert(ft::make_pair(std::numeric_limits<int>::max(), "max"));

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);
    }
    if (nextTes())
        return ;
    {
        intmap temp(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap tem(ft_intstr_arr, ft_intstr_arr + intstr_size);

        temp.insert(std::make_pair(34, "kljd9834iuhwet"));
        temp.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
        temp.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
        temp.insert(std::make_pair(1954894589, "jtt5454wujtjse"));
        temp.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
        temp.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        temp.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        temp.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
        temp.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        temp.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        temp.insert(std::make_pair(453834782, "juytje54yaerdrj"));
        temp.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
        temp.insert(std::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        tem.insert(ft::make_pair(34, "kljd9834iuhwet"));
        tem.insert(ft::make_pair(34, "kljd9834iuhwet"));
        tem.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
        tem.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
        tem.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
        tem.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
        tem.insert(ft::make_pair(1954894589, "jtt5454wujtjse"));
        tem.insert(ft::make_pair(1954894589, "jtt5454wujtjse"));
        tem.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
        tem.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
        tem.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        tem.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        tem.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        tem.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        tem.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
        tem.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
        tem.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        tem.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        tem.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        tem.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        tem.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
        tem.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
        tem.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
        tem.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
        tem.insert(ft::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));
        tem.insert(ft::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        const intmap std(temp);
        const _intmap ft(tem);

        start = std::chrono::high_resolution_clock::now();
        std::pair<intmap::const_iterator, intmap::const_iterator> eq = std.equal_range(98583944);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();ft::pair<_intmap::const_iterator, _intmap::const_iterator>
        eq1 = ft.equal_range(98583944);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(209485948);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(209485948);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458942);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458942);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458941);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458941);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(19458943);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(19458943);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(-1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(-1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(3);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(4);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(4);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);

        start = std::chrono::high_resolution_clock::now();
        eq = std.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        eq1 = ft.equal_range(std::numeric_limits<int>::max());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_EQ_RANGE(eq, std.end(), 0);
        PRINT_EQ_RANGE(eq1, ft.end(), 1);
    }
    if (nextTes())
        return ;
}
void valueCompTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                VALUE_COMP TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
{
        strmap std(std_strstr_arr, std_strstr_arr + 15);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 15);

        strmap::iterator it = std.begin();
        strmap::const_iterator cit = std.begin();
        
        _strmap::iterator it1 = ft.begin();
        _strmap::const_iterator cit1 = ft.begin();
        
        start = std::chrono::high_resolution_clock::now();
        strmap::value_compare comp = std.value_comp();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap::value_compare comp1 = ft.value_comp();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        

        if (comp(*it, *cit)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(*it1, *cit1)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }

        it++;
        cit++; cit++;
        
        it1++;
        cit1++; cit1++;

        if (comp(*it, *cit)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(*it1, *cit1)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }

        it++;
        
        it1++;

        if (comp(*it, *cit)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(*it1, *cit1)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }
 
    }

    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        intmap::iterator it = std.begin();
        intmap::iterator it1 = std.begin();
        start = std::chrono::high_resolution_clock::now();
        intmap::value_compare comp = std.value_comp();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        _intmap::iterator it2 = ft.begin();
        _intmap::iterator it3 = ft.begin();
        start = std::chrono::high_resolution_clock::now();
        _intmap::value_compare comp1 = ft.value_comp();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (comp(*it, *it1)) {
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(*it2, *it3)) {
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }

        it++;
        it1++; it1++;
        
        it2++;
        it3++; it3++;

        if (comp(*it, *it1)) {
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(*it2, *it3)) {
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }
    }
    if (nextTes())
        return ;
}

void swapMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      SWAP TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + 32);
        intmap std1;
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 32);
        _intmap ft1;

        start = std::chrono::high_resolution_clock::now();
        std::swap(std, std1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft::swap(ft, ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std.clear();
        start = std::chrono::high_resolution_clock::now();
        std1.swap(std);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        ft.clear();
        start = std::chrono::high_resolution_clock::now();
        ft.swap(ft1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;

        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void keyCompTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      KEYCOMP TEST              \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 6);

        strmap::iterator it = std.begin();
        strmap::const_iterator cit = std.begin();
        start = std::chrono::high_resolution_clock::now();
        strmap::key_compare comp = std.key_comp();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;

        _strmap::iterator it1 = ft.begin();
        _strmap::const_iterator cit1 = ft.begin();
        start = std::chrono::high_resolution_clock::now();
        _strmap::key_compare comp1 = ft.key_comp();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        
        if (comp(it->first, cit->first)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(it1->first, cit->first)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }
        
        it++;
        cit++; cit++;
        
        it1++;
        cit1++; cit1++;
        
        if (comp(it->first, cit->first)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(it1->first, cit->first)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }

        it++;
        
        it1++;

        if (comp(it->first, cit->first)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(it1->first, cit->first)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }
    }
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        intmap::iterator it = std.begin();
        intmap::iterator it1 = std.begin();
        start = std::chrono::high_resolution_clock::now();
        intmap::key_compare comp = std.key_comp();
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;

        _intmap::iterator it2 = ft.begin();
        _intmap::iterator it3 = ft.begin();
        start = std::chrono::high_resolution_clock::now();
        _intmap::key_compare comp1 = ft.key_comp();
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        
        if (comp(it->first, it1->first)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(it2->first, it3->first)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }

        it++;
        it1++; it1++;
        
        it2++;
        it3++; it3++;

        if (comp(it->first, it1->first)) {        
            PRINT_LIN("LESS", "", 0);
        } else {
            PRINT_LIN("NOT LESS", "", 0);
        }

        if (comp1(it2->first, it3->first)) {        
            PRINT_LIN("LESS", "", 1);
        } else {
            PRINT_LIN("NOT LESS", "", 1);
        }
    }
    if (nextTes())
        return ;
}

void findTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      FIND TEST                 \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
        {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);

        start = std::chrono::high_resolution_clock::now();
        strmap::iterator it = std.find("ABCD");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap::iterator it1 = ft.find("ABCD");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
            PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }

        std.insert(std::make_pair("12345", "etsriueruy394w"));
        std.insert(std::make_pair("abcd", "sfdge4ta4tqtawefa"));
        std.insert(std::make_pair("123", "adfgagrawetawtawef"));
        std.insert(std::make_pair("1234", "asdfgaetfawfasdf"));
        std.insert(std::make_pair("ab", "adfawtawefgzsdfg"));
        std.insert(std::make_pair("yz", "gftrjr5y4agwe3ta"));
        std.insert(std::make_pair("64", "mhj,i;y9o67eysetrgerg"));

        ft.insert(ft::make_pair("12345", "etsriueruy394w"));
        ft.insert(ft::make_pair("abcd", "sfdge4ta4tqtawefa"));
        ft.insert(ft::make_pair("123", "adfgagrawetawtawef"));
        ft.insert(ft::make_pair("1234", "asdfgaetfawfasdf"));
        ft.insert(ft::make_pair("ab", "adfawtawefgzsdfg"));
        ft.insert(ft::make_pair("yz", "gftrjr5y4agwe3ta"));
        ft.insert(ft::make_pair("64", "mhj,i;y9o67eysetrgerg"));

        start = std::chrono::high_resolution_clock::now();
        it = std.find("12345");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.find("12345");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
            PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }
        
        start = std::chrono::high_resolution_clock::now();
        it = std.find("1234");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.find("1234");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
            PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        it = std.find("123");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.find("123");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
            PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        it = std.find("123");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.find("123");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
            PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        it = std.find("z");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.find("z");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (it != std.end()) {
             PRINT_PAIR_REF(*it, 0);
        }
        if (it1 != ft.end()) {
            PRINT_PAIR_REF(*it1, 1);
        }

        const strmap cm(std);
        const _strmap cm1(ft);

        start = std::chrono::high_resolution_clock::now();
        strmap::const_iterator cit = cm.find("abcd");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap::const_iterator cit1 = cm1.find("abcd");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        cit = std.find("64");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        cit1 = ft.find("64"); 
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        cit = std.find("12345");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        cit1 = ft.find("12345");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);
        
        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        cit = std.find("1234");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        cit1 = ft.find("1234");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }

        cit = std.find("123");
        cit1 = ft.find("123");

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }

        start = std::chrono::high_resolution_clock::now();
        cit = std.find("123");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        cit1 = ft.find("123");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        TIMER_(t1, t2);

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit, 0);
        }
        if (cit1 != cm1.end()) {
            PRINT_PAIR_REF(*cit1, 1);
        }
    }
    if (nextTes())
        return ;
    {
        const intmap cm;
        const _intmap cm1;

        if (cm.find(0) != cm.end()) {
            start = std::chrono::high_resolution_clock::now();
            PRINT_PAIR_PTR(cm.find(0), 0);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
        }
        if (cm1.find(0) != cm1.end()) {
            start = std::chrono::high_resolution_clock::now();
            PRINT_PAIR_PTR(cm1.find(0), 1);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
            TIMER_(t1, t2);
        }

        intmap std;
        _intmap ft;

        std.insert(std::make_pair(123, "Hello"));
        ft.insert(ft::make_pair(123, "Hello"));

        if (std.find(0) != std.end()) {
            start = std::chrono::high_resolution_clock::now();
            PRINT_PAIR_PTR(std.find(0), 0);
            end = std::chrono::high_resolution_clock::now();
            t1 = end - start;
        }
        if (ft.find(0) != ft.end()) {
            start = std::chrono::high_resolution_clock::now();
            PRINT_PAIR_PTR(ft.find(123), 1);
            end = std::chrono::high_resolution_clock::now();
            t2 = end - start;
        }
        TIMER_(t1, t2);
    }
    if (nextTes())
        return ;
}


void insertMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      INSERT TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        typedef std::pair<intmap::iterator, bool> std_ins_pair;
        typedef ft::pair<_intmap::iterator, bool> ft_ins_pair;

        intmap std;
        _intmap ft;

        start = std::chrono::high_resolution_clock::now();
        std_ins_pair p = std.insert(std::make_pair(64, "64str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft_ins_pair p1 = ft.insert(ft::make_pair(64, "64str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair(64, "Double"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair(64, "Double"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair(0, "0str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair(0, "0str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair(-23, "-23str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair(-23, "-23str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair(64, "dfgs"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair(64, "dfgs"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;
    }
    if (nextTes())
        return ;
    {
        typedef std::pair<strmap::iterator, bool> std_ins_pair;
        typedef ft::pair<_strmap::iterator, bool> ft_ins_pair;

        strmap std;
        _strmap ft;

        start = std::chrono::high_resolution_clock::now();
        std_ins_pair p = std.insert(std::make_pair("64", "64str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft_ins_pair p1 = ft.insert(ft::make_pair("64", "64str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair("64n", "Double"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair("64n", "Double"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair("0n", "0str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair("0n", "0str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair("-23n", "-23str"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair("-23n", "-23str"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

        std::cout << " " << std.end()->first << std::endl;
        std::cout << " " << ft.end().baseNode()->_value.first << std::endl;

        start = std::chrono::high_resolution_clock::now();
        p = std.insert(std::make_pair("64n", "dfgs"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        p1 = ft.insert(ft::make_pair("64n", "dfgs"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_INS_PAIR(p, 0);
        PRINT_INS_PAIR(p1, 1);

    }
    if (nextTes())
        return ;
}

void insertRangeMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      INSERT-RANGE TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
     {
        strmap std;
        _strmap ft;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr, std_strstr_arr + 5);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr, ft_strstr_arr + 5);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr + 5, std_strstr_arr + 14);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr + 5, ft_strstr_arr + 14);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr, std_strstr_arr + 9);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr, ft_strstr_arr + 9);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr + 26, std_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr + 26, ft_strstr_arr + strstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_strstr_arr + 14, std_strstr_arr + 26);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_strstr_arr + 14, ft_strstr_arr + 26);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        intmap std;
        _intmap ft;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_intstr_arr + 16, std_intstr_arr + 16);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_intstr_arr + 16, ft_intstr_arr + 16);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_intstr_arr + 1, std_intstr_arr + 7);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_intstr_arr + 1, ft_intstr_arr + 7);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_intstr_arr, std_intstr_arr + 1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_intstr_arr, ft_intstr_arr + 1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_intstr_arr, std_intstr_arr + 17);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_intstr_arr, ft_intstr_arr + 17);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.insert(std_intstr_arr, std_intstr_arr + intstr_size);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.insert(ft_intstr_arr, ft_intstr_arr + intstr_size);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void insertPosMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      INSERT-POS TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std;
        _intmap ft;

        start = std::chrono::high_resolution_clock::now();
        intmap::iterator it = std.insert(std.end(), std::make_pair(64, "Gamepak"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::iterator it1 = ft.insert(ft.end(), ft::make_pair(64, "Gamepak"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_PAIR_REF(*it, 0);
        PRINT_PAIR_REF(*it1, 1);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), std::make_pair(64, "Test"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), ft::make_pair(64, "Test"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_PAIR_REF(*it, 0);
        PRINT_PAIR_REF(*it1, 1);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), std::make_pair(100, "100$"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), ft::make_pair(100, "100$"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_PAIR_REF(*it, 0);
        PRINT_PAIR_REF(*it1, 1);

        it = std.end();
        it1 = ft.end();
        --it;
        --it1;

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(it, std::make_pair(100, "12345"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(it1, ft::make_pair(100, "12345"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_PAIR_REF(*it, 0);
        PRINT_PAIR_REF(*it1, 1);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(it, std::make_pair(69, "420"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(it1, ft::make_pair(69, "420"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_PAIR_REF(*it, 0);
        PRINT_PAIR_REF(*it1, 1);
    }
    if (nextTes())
        return ;
}

void eraseMapTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                      ERASE TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + 25);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 25);

        ft.getTree().print2D(ft.getTree().getTreeRoot());

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);

        intmap::iterator it = std.begin();
        _intmap::iterator it1 = ft.begin();
        
        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        it = std.begin();
        it1 = ft.begin();

        for (int i = 0; i < 21; i++) {
            it++;
            it1++;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.end();
        it1 = ft.end();

        for (int i = 0; i < 1; i++) {
            it--;
            it1--;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.end();
        it1 = ft.end();

        for (int i = 0; i < 3; i++) {
            it--;
            it1--;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.end();
        it1 = ft.end();

        for (int i = 0; i < 1; i++) {
            it--;
            it1--;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.begin();
        it1 = ft.begin();

        for (int i = 0; i < 1; i++) {
            it++;
            it1++;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.begin();
        it1 = ft.begin();
        
        start = std::chrono::high_resolution_clock::now();
        std.erase(it);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        ft.getTree().print2D(ft.getTree().getTreeRoot());
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        for (it = std.begin(); it != std.end(); it = std.begin()) {
            std.erase(it);
            PRINT_AL(std, 0);
        }
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        
        start = std::chrono::high_resolution_clock::now();
        for (it1 = ft.begin(); it1 != ft.end(); it1 = ft.begin()) {
            ft.erase(it1);
            PRINT_AL(ft, 1);
        }
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        it = std.insert(std.end(), std::make_pair(64, "Test"));
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        it1 = ft.insert(ft.end(), ft::make_pair(64, "Test"));
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void eraseMapRangeTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  ERASE-RANGE TEST               \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        strmap std;
        _strmap ft;

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std.insert(std_strstr_arr, std_strstr_arr + strstr_size);
        ft.insert(ft_strstr_arr, ft_strstr_arr + strstr_size);
        
        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        intmap::iterator it(std.begin());
        intmap::iterator en(it);
        _intmap::iterator it1(ft.begin());
        _intmap::iterator en1(it1);

        en++;
        en1++;

        start = std::chrono::high_resolution_clock::now();
        std.erase(it, en);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1, en1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.begin();
        en = it;
        it1 = ft.begin();
        en1 = it1;

        for (int i = 0; i < 24; i++) {
            it++;
            it1++;
        }
        
        for (int i = 0; i < 30; i++) {
            en++;
            en1++;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it, en);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1, en1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.begin();
        en = it;
        it1 = ft.begin();
        en1 = it1;

        for (int i = 0; i < 34; i++) {
            it++;
            it1++;
        }
        
        for (int i = 0; i < 55; i++) {
            en++;
            en1++;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it, en);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1, en1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        it = std.begin();
        en = it;
        it1 = ft.begin();
        en1 = it1;
        for (int i = 0; i < 1; i++) {
            en++;
            en1++;
        }

        start = std::chrono::high_resolution_clock::now();
        std.erase(it, en);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(it1, en1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void eraseMapKeyTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                  ERASE KEY TEST                \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std;
        _intmap ft;

        start = std::chrono::high_resolution_clock::now();
        intmap::size_type size = std.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::size_type size1 = ft.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }

    {
        intmap std(std_intstr_arr, std_intstr_arr + 16);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 16);

        start = std::chrono::high_resolution_clock::now();
        intmap::size_type size = std.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _intmap::size_type size1 = ft.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        std.erase(std.begin(), std.end());
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        ft.erase(ft.begin(), ft.end());
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        std.insert(std::make_pair(23, "23n"));
        std.insert(std::make_pair(25, "asdasdfsdfsafdsf"));
        std.insert(std::make_pair(1, "asdssdfdfdffffff"));
        std.insert(std::make_pair(2, "dsfdffffdfdfdsdfdffa"));
        std.insert(std::make_pair(3, "sssdfs"));
        std.insert(std::make_pair(75, "dfse"));
        std.insert(std::make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
        std.insert(std::make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
        std.insert(std::make_pair(-23, "sdffgdfgrefet34thfgheewt"));
        std.insert(std::make_pair(0, "98y4rtuohwidsjusdossefsse"));

        ft.insert(ft::make_pair(23, "23n"));
        ft.insert(ft::make_pair(25, "asdasdfsdfsafdsf"));
        ft.insert(ft::make_pair(1, "asdssdfdfdffffff"));
        ft.insert(ft::make_pair(2, "dsfdffffdfdfdsdfdffa"));
        ft.insert(ft::make_pair(3, "sssdfs"));
        ft.insert(ft::make_pair(75, "dfse"));
        ft.insert(ft::make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
        ft.insert(ft::make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
        ft.insert(ft::make_pair(-23, "sdffgdfgrefet34thfgheewt"));
        ft.insert(ft::make_pair(0, "98y4rtuohwidsjusdossefsse"));

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(64);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(0);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(0);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(75);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(75);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(1);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(1);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(2);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(2);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(3);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(3);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(23);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(23);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(23);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(23);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(30);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(30);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(-22);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(-22);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        start = std::chrono::high_resolution_clock::now();
        size = std.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(25);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(25);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(-23);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase(25);
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase(25);
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        strmap std;
        _strmap ft;

        start = std::chrono::high_resolution_clock::now();
        strmap::size_type size = std.erase("");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        _strmap::size_type size1 = ft.erase("");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std.insert(std::make_pair("", ""));
        std.insert(std::make_pair("123", "kjhgfdsdffghsfghdfgh"));
        std.insert(std::make_pair("1234", "gfdsadgg"));
        std.insert(std::make_pair("123456789123456789123456789", "49857459898674568464"));
        std.insert(std::make_pair("0", "2345456456456456"));
        std.insert(std::make_pair("", ""));
        std.insert(std::make_pair("", "9459845984598498"));
        std.insert(std::make_pair("000000000000000000000000", "1111111111111111111111111111"));

        ft.insert(ft::make_pair("", ""));
        ft.insert(ft::make_pair("123", "kjhgfdsdffghsfghdfgh"));
        ft.insert(ft::make_pair("1234", "gfdsadgg"));
        ft.insert(ft::make_pair("123456789123456789123456789", "49857459898674568464"));
        ft.insert(ft::make_pair("0", "2345456456456456"));
        ft.insert(ft::make_pair("", ""));
        ft.insert(ft::make_pair("", "9459845984598498"));
        ft.insert(ft::make_pair("000000000000000000000000", "1111111111111111111111111111"));

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("1");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("1");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("123");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("123");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("123");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("123");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("1234");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("1234");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("123456789123456789123456789");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("123456789123456789123456789");

        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("000000000000000000000000");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("000000000000000000000000");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("0");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("0");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        start = std::chrono::high_resolution_clock::now();
        size = std.erase("000000000000000000000000");
        end = std::chrono::high_resolution_clock::now();
        t1 = end - start;
        start = std::chrono::high_resolution_clock::now();
        size1 = ft.erase("000000000000000000000000");
        end = std::chrono::high_resolution_clock::now();
        t2 = end - start;
        
        TIMER_(t1, t2);
        PRINT_LIN("Erased?:", size, 0);
        PRINT_LIN("Erased?:", size1, 1);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
}

void runMapTests() {

    lowerBoundTest();
    upperBoundTest();
    eqRangeTest();
    ctorTest();
    eraseMapTest();
    eraseMapKeyTest();
    eraseMapRangeTest();
    insertPosMapTest();
    insertRangeMapTest();
    insertMapTest();
    findTest();
    keyCompTest();      //
    valueCompTest();    //
    opIndexTest();
    swapMapTest();
    atMapTest();
    opEqualsTest();
    ctorCopyTest();
    countTest();        //
    emptyMapTest();
    clearMapTest();
    ctorRangeTest();
    
}