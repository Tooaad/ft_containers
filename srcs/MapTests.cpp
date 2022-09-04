/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:58 by gpernas-          #+#    #+#             */
/*   Updated: 2022/09/04 21:19:28 by gpernas-         ###   ########.fr       */
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
    }
    if (nextTes())
        return ;
}

void ctorRangeTest() {
    SETUP_MAP_ARRAYS();
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl;
    std::cout << "\x1b[41m                    CTOR TEST                   \x1b[0m" << std::endl;
    std::cout << "\x1b[33m************************************************\x1b[0m" << std::endl << std::endl;
    {
        intmap std(std_intstr_arr, std_intstr_arr + 1, std::less<int>());
        _intmap ft(ft_intstr_arr, ft_intstr_arr + 1, std::less<int>());

        PRINT_AL(std, 0);
        PRINT_AL(ft, 1);

        intmap std2(std.begin(), std.end());
        _intmap ft2(ft.begin(), ft.end());
        
        PRINT_AL(std2, 0);
        PRINT_AL(ft2, 1);
    }
    if (nextTes())
        return ;
    {
        strmap std1(std_strstr_arr, std_strstr_arr + 8);
        _strmap ft1(ft_strstr_arr, ft_strstr_arr + 8);

        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);

        strmap std2(std_strstr_arr, std_strstr_arr + 8);
        _strmap ft2(ft_strstr_arr, ft_strstr_arr + 8);
        PRINT_AL(std1, 0);
        PRINT_AL(ft1, 1);
    }
    if (nextTes())
        return ;
}

void runMapTests() {

    ctorRangeTest();
    ctorTest();
    
}