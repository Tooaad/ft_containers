/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:49:05 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/09 20:13:12 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <chrono>
#include "../includes/Vector.hpp"

template <typename Iter, typename Iter2>
int compareVect(Iter first, Iter last, Iter2 first_, Iter2 last_)
{
    Iter it = first;
    Iter2 it_ = first_;
    for (;it != last || it_ != last_; ++it, ++it_) {
        if (*it != *it_) {
            std::cout << *it << " ======== " << *it_ << std::endl;
            std::cout << "\x1b[31m--------------❌❌❌❌❌❌❌❌❌❌❌-------------\x1b[0m" << std::endl << std::endl;
            exit(1);
        }
    }
    return 0;
}
template <typename T>
void itComp(T std, T ft)
    {
        if (std != ft)
        {
            std::cout << std << " ======== " << ft << std::endl;
            std::cout << "\x1b[31m--------------❌❌❌❌❌❌❌❌❌❌❌-------------\x1b[0m" << std::endl << std::endl;
            exit(1);
        }
    } 

#define TIMER(t1, t2)                                                                                    \
    {                                                                                                     \
            std::cout << "\x1b[32m " << t1.count() << "\x1b[0m ";                                        \
            std::cout << " vs ";                                                                          \
            std::cout << "\x1b[32m " << t2.count() << "\x1b[0m " << std::endl;                           \
    }
    
#define COMPARE(std, ft)                                                                                  \
    {                                                                                                     \
        if (compareVect(std.begin(), std.end(), ft.begin(), ft.end())) {                                  \
            return ;                                                                                      \
        }                                                                                                 \
        if ((std.capacity() != ft.capacity() || std.size() != ft.size())) {                               \
            std::cout << "\x1b[31m--------------❌❌❌❌❌❌❌❌❌❌❌-------------\x1b[0m" << std::endl;     \
        exit(1);                                                                                          \
        }                                                                                                 \
        else                                                                                              \
             std::cout << "\x1b[32m------------------✓✓✓✓✓✓✓✓✓✓✓-------------------\x1b[0m" << std::endl; \
    }

template <typename Iter>
void print_range(Iter first, Iter last, int type)
{
    int i = 0;
    for (Iter it = first; it != last; ++it) {
        if (type == 0)
            std::cout << "\x1b[34m " << *it << "\x1b[0m ";
        else
            std::cout << "\x1b[36m " << *it << "\x1b[0m ";
        std::cout << std::setw(6);
        if (++i % 2 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

#define PRINT_VEC(vec, type)                                                                       \
    {                                                                                              \
        std::cout << "\nVector content:\n";                                                        \
        print_range(vec.begin(), vec.end(), type);                                                 \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_SIZE(c)                                                                              \
    {                                                                                              \
        std::cout << "Capc: " << c.capacity() << std::endl;                                        \
        std::cout << "Size: " << c.size() << std::endl;                                            \
    }

#define PRINT_LINE(msg, value, type)                                                               \
    {                                                                                              \
        if (type == 0)                                                                             \
            std::cout << "\x1b[34m " << msg << " " << (value) << "\x1b[0m ";                       \
        else                                                                                       \
            std::cout << "\x1b[36m " << msg << " " << (value) << "\x1b[0m ";                       \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_ALL(vec, type)                                                                       \
    {                                                                                              \
        PRINT_SIZE(vec);                                                                           \
        PRINT_VEC(vec, type);                                                                      \
    }

#define CHECK_CAPACITY(vec)                                                                        \
    {                                                                                              \
        if ((vec.capacity() < vec.size())) {                                                       \
           std::cout << "Capacity is smaller than size"  << std::endl;                             \
        } else {                                                                                   \
            std::cout << "Capacity ok"  << std::endl;                                              \
        }                                                                                          \
    }

#define CHECK_AND_PRINT_ALL(vec, type)                                                             \
    {                                                                                              \
        CHECK_CAPACITY(vec);                                                                       \
        PRINT_ALL(vec, type);                                                                      \
    }

template <typename ForwardIt, typename T>
void iota(ForwardIt first, ForwardIt last, T value = T())
{
    while (first != last) {
        *first++ = value;
        ++value;
    }
}

template <typename T>
void init_array(T* arr, std::size_t size)
{
    iota(arr, arr + size, (T)rand());
}

#define SETUP_ARRAY(type, name, size)                                                              \
    type name[size];                                                                               \
    init_array(name, size);

#define SETUP_ARRAYS()                                                                             \
    SETUP_ARRAY(long, s_long, 32);                                                                 \
    SETUP_ARRAY(long, b_long, 64);                                                                 \
    SETUP_ARRAY(int, s_int, 32);                                                                   \
    SETUP_ARRAY(int, b_int, 64);                                                                   \
    SETUP_ARRAY(double, s_double, 32);                                                             \
    SETUP_ARRAY(double, b_double, 64);                                                             \
    char s_char[32];                                                                               \
    iota(s_char, s_char + 32, '@');                                                                \
    char b_char[64];                                                                               \
    iota(b_char, b_char + 64, '$');                                                                \
    std::size_t s_size = 32;                                                                       \
    std::size_t b_size = 64;                                                                       \
    (void)s_size;                                                                                  \
    (void)b_size;                                                                                  \
    std::__1::chrono::steady_clock::time_point start;                                              \
    std::__1::chrono::steady_clock::time_point end;                                                \
    std::chrono::duration<double, std::milli> t1;                                                  \
    std::chrono::duration<double, std::milli> t2;                                                  \
    std::string s_string[32] = {                                                                   \
        "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB",                    \
        "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1",                    \
        "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng",                    \
        "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",                    \
        "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr",                    \
        "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4",                    \
        "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq",                    \
        "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",                    \
        "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6",                    \
        "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj",                    \
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"                                             \
    };                                                                                             \
    std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    };                                                                                             \
    (void)s_string;                                                                                \
    (void)b_string;

typedef ft::vector<std::string> _strvector;
typedef ft::vector<int> _intvector;
typedef ft::vector<long> _longvector;
typedef ft::vector<double> _doublevector;
typedef ft::vector<char> _charvector;

typedef std::vector<std::string> strvector;
typedef std::vector<int> intvector;
typedef std::vector<long> longvector;
typedef std::vector<double> doublevector;
typedef std::vector<char> charvector;

void runVectTests();