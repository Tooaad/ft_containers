/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/09/13 13:05:18 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapTests.hpp"
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
        intmap std;
        _intmap ft;

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
        intmap std(std_intstr_arr, std_intstr_arr + 3, std::less<int>());
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 3, std::less<int>());

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        intmap std2(std.begin(), std.end());
        _intmap ft2(ft.begin(), ft.end());
        
        PRINT_AL(std2, 0);
        PRINT_AL(ft2, 1);
    }
    if (nextTes())
        return ;
    {
        strmap std(std_strstr_arr, std_strstr_arr + 8);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 8);
        
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        strmap std1(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft1(ft_strstr_arr, ft_strstr_arr + strstr_size);

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
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        intmap std1(std);
        _intmap ft1(ft);

        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);
    }
    if (nextTes())
        return ;
    {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);
        
        strmap std1(std);
        _strmap ft1(ft);

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

        std = std1;
        ft = ft1;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std1 = intmap(std_intstr_arr, std_intstr_arr + intstr_size);
        ft1 = _intmap(ft_intstr_arr, ft_intstr_arr + intstr_size);

        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);

        std = std1;
        ft = ft1;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std = intmap(std_intstr_arr, std_intstr_arr + 10);
        ft = _intmap(ft_intstr_arr, ft_intstr_arr + 10);

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std1 = std;
        ft1 = ft;

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

        std = std1;
        ft = ft1;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std1 = strmap(std_strstr_arr, std_strstr_arr + strstr_size);
        ft1 = _strmap(ft_strstr_arr, ft_strstr_arr + strstr_size);

        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
        COMPAR(std, ft);

        std = std1;
        ft = ft1;

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std = strmap(std_strstr_arr, std_strstr_arr + 10);
        ft = _strmap(ft_strstr_arr, ft_strstr_arr + 10);

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std1 = std;
        ft1 = ft;

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
            std::string& x = std.at(6);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 0);
        }
        try {
            std::string& x = ft.at(6);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 1);
        }
    }
    PRINT_LIN("", "", 0);
    {
        strmap std(std_strstr_arr, std_strstr_arr + strstr_size);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + strstr_size);

        std.insert(std::make_pair("Hello", "World"));
        ft.insert(ft::make_pair("Hello", "World"));
        
        try {
            std::string& x = std.at("Hello");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 0);
        }
        try {
            std::string& x = ft.at("Hello");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 1);
        }
    }
    PRINT_LIN("", "", 0);
    {
        strmap std(std_strstr_arr, std_strstr_arr + 1);
        _strmap ft(ft_strstr_arr, ft_strstr_arr + 1);

        try {
            std::string& x = std.at("");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 0);
        }
        try {
            std::string& x = ft.at("");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 1);
        }
    }
    PRINT_LIN("", "", 0);
    {
        const intmap std;
        const _intmap ft;

        try {
            const std::string& x = std.at(6);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 0);
        }
        try {
            const std::string& x = std.at(6);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 6, 1);
        }
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
            const std::string& x = std.at(64);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 64, 0);
        }
        try {
            const std::string& x = ft.at(64);

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", 64, 1);
        }
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
            const std::string& x = std.at("Hello");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 0);
        }
        try {
            const std::string& x = ft.at("Hello");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "Hello", 1);
        }
    }
    PRINT_LIN("", "", 0);
    {
        const strmap std(std_strstr_arr, std_strstr_arr + 1);
        const _strmap ft(ft_strstr_arr, ft_strstr_arr + 1);

        try {
            const std::string& x = std.at("");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 0);
        }
        try {
            const std::string& x = ft.at("");

            PRINT_LIN("At:", x, 0);
        } catch (std::out_of_range& e) {
            PRINT_LIN("Out of range exception", "", 1);
        }
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
        PRINT_LIN("Value:", std[64], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft[64], 1);
        PRINT_SIZ(ft);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std[64] = "Hello";
        ft[64] = "Hello";

        PRINT_SIZ(std);
        PRINT_LIN("Value:", std[64], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft[64], 1);
        PRINT_SIZ(ft);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        PRINT_SIZ(std);
        PRINT_LIN("Value:", std[0], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft[0], 1);
        PRINT_SIZ(ft);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std[0] = "ABCDEF";
        ft[0] = "ABCDEF";

        PRINT_SIZ(std);
        PRINT_LIN("Value:", std[64], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft[64], 1);
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
        PRINT_LIN("Value:", std["CBCId4lUU6oYms60JkNr"], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft["CBCId4lUU6oYms60JkNr"], 1);
        PRINT_SIZ(ft);
        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std["1IRLC9sfQI5AzDYeotLd"] = "World";
        ft["1IRLC9sfQI5AzDYeotLd"] = "World";

        PRINT_SIZ(std);
        PRINT_LIN("Value:", std["1IRLC9sfQI5AzDYeotLd"], 0);
        PRINT_SIZ(std);
        PRINT_SIZ(ft);
        PRINT_LIN("Value:", ft["1IRLC9sfQI5AzDYeotLd"], 1);
        PRINT_SIZ(ft);
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

        std.clear();
        ft.clear();

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std.insert(std_strstr_arr, std_strstr_arr + 16);
        ft.insert(ft_strstr_arr, ft_strstr_arr + 16);

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);
        COMPAR(std, ft);

        std.clear();
        ft.clear();

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

        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        COMPAR(std, ft);

        std.insert(std::make_pair("Hello", "World"));
        ft.insert(ft::make_pair("Hello", "World"));

        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
        COMPAR(std, ft);


        // ERASE SIN TERMINAR
        // std.erase(std.begin());
        // ft.erase(ft.begin());

        // PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        // PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
    }

    {
        intmap std(std_intstr_arr, std_intstr_arr + intstr_size);
        _intmap ft(ft_intstr_arr, ft_intstr_arr + intstr_size);

        PRINT_LIN("Empty:", std.empty() ? "true" : "false", 0);
        PRINT_LIN("Empty:", ft.empty() ? "true" : "false", 1);
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

        intmap::size_type c = std.count(64);
        _intmap::size_type c1 = ft.count(64);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        c = std.count(145);
        c1 = ft.count(145);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        c = std.count(11);
        c1 = ft.count(11);

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


        c = std.count(34);
        c1 = ft.count(34);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        c = std.count(2);
        c1 = ft.count(2);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        c = std.count(9);
        c1 = ft.count(9);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        // std.erase(9);
        // ft.erase(9);

        // c = std.count(9);
        // c1 = ft.count(9);

        // PRINT_LIN("STD:", c, 0);
        // PRINT_LIN("FT:", c1, 1);

        c = std.count(10);
        c1 = ft.count(10);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);

        c = std.count(22);
        c1 = ft.count(22);

        PRINT_LIN("STD:", c, 0);
        PRINT_LIN("FT:", c1, 1);
    }
}

void runMapTests() {

    countTest();        //
    emptyMapTest();
    clearMapTest();
    atMapTest();
    opIndexTest();
    opEqualsTest();
    ctorCopyTest();
    ctorRangeTest();
    ctorTest();
    
}