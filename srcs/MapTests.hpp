/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:49:05 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/08 22:36:36 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <chrono>
#include "../includes/map.hpp"

template <typename Iter, typename Iter2>
int compareMap(Iter first, Iter last, Iter2 first_, Iter2 last_)
{
    Iter it = first;
    Iter2 it_ = first_;
    for (;it != last || it_ != last_; ++it, ++it_) {
        if (it->second != it_->second) {
            std::cout << it->second << " ======== " << it_->second << std::endl;
            std::cout << "\x1b[31m--------------❌❌❌❌❌❌❌❌❌❌❌-------------\x1b[0m" << std::endl << std::endl;
            exit(1);
        }
    }
    return 0;
}

template <typename It>
void print_map(It first, It last, int type)
{
    for (int i = 0; first != last; ++first) {
        if (type == 0)
            std::cout << "\x1b[34m " << "K: " << first->first << " V: " << first->second << "\x1b[0m ";
        else
            std::cout << "\x1b[35m " << "K: " << first->first << " V: " << first->second << "\x1b[0m ";
        std::cout << std::setw(6);
        if (++i % 2 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

#define COMPAR(std, ft)                                                                                   \
    {                                                                                                     \
        if (compareMap(std.begin(), std.end(), ft.begin(), ft.end())) {                                   \
            return ;                                                                                      \
        }                                                                                                 \
        if ((std.size() != ft.size())) {                                                                  \
            std::cout << "\x1b[31m--------------❌❌❌❌❌❌❌❌❌❌❌-------------\x1b[0m" << std::endl;     \
        exit(1);                                                                                          \
        }                                                                                                 \
        else                                                                                              \
             std::cout << "\x1b[32m------------------✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓-------------------\x1b[0m" << std::endl; \
    }

#define PRINT_LIN(msg, value, type)                                                                \
    {                                                                                              \
        if (type == 0)                                                                             \
            std::cout << "\x1b[34m " << msg << " " << (value) << "\x1b[0m ";                       \
        else                                                                                       \
            std::cout << "\x1b[35m " << msg << " " << (value) << "\x1b[0m ";                       \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_MAP(map, type)                                                                       \
    {                                                                                              \
        std::cout << "\nmap content:\n";                                                           \
        print_map(map.begin(), map.end(), type);                                                   \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_SIZ(c)                                                                               \
    {                                                                                              \
        std::cout << "Size: " << c.size() << std::endl;                                            \
    }

#define PRINT_AL(map, type)                                                                        \
    {                                                                                              \
        PRINT_SIZ(map);                                                                            \
        PRINT_MAP(map, type);                                                                      \
    }

#define PRINT_INS_PAIR(p, type)                                                                    \
    {                                                                                              \
        PRINT_PAIR_REF(*p.first, type);                                                            \
        PRINT_LIN("Inserted:", p.second ? "true" : "false", type);                                 \
    }

#define PRINT_PAIR_PTR(p, type)                                                                     \
    {                                                                                               \
        PRINT_LIN("Key:", (p)->first, type);                                                        \
        PRINT_LIN("Value:", (p)->second, type);                                                     \
    }

#define PRINT_PAIR_REF(p, type)                                                                    \
    {                                                                                              \
        PRINT_LIN("Key:", (p).first, type);                                                        \
        PRINT_LIN("Value:", (p).second, type);                                                     \
    }

#define PRINT_BOUND(b, end, type)                                                                  \
    {                                                                                              \
        if (b != end) {                                                                            \
            PRINT_PAIR_REF(*b, type);                                                              \
        } else {                                                                                   \
            PRINT_LIN("End iterator", "", type);                                                  \
        }                                                                                          \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_EQ_RANGE(p, end, type)                                                               \
    {                                                                                              \
        if (type == 0)                                                                             \
            std::cout << "--------------------------------\n";                                     \
        PRINT_BOUND(p.first, end, type);                                                           \
        PRINT_BOUND(p.second, end, type);                                                          \
    }

#define TIMER_(t1, t2)                                                                                    \
    {                                                                                                     \
            std::cout << "\x1b[32m " << t1.count() << "\x1b[0m ";                                        \
            std::cout << " vs ";                                                                          \
            std::cout << "\x1b[32m " << t2.count() << "\x1b[0m " << std::endl;                           \
    }

template <typename T>
void init_array_int_str(std::pair<int, std::string>* arr, std::size_t size)
{
    std::string x[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = std::make_pair(i, x[i]);
    }
}

template <typename T>
void init_array_int_str(ft::pair<int, std::string>* arr, std::size_t size)
{
    std::string x[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = ft::make_pair(i, x[i]);
    }
}

template <typename T>
void init_array_str_str(std::pair<std::string, std::string>* arr, std::size_t size)
{
    std::string x[32] = { "RxWAUMME3GtF9Zbv3a4M", "WC96vs7Z6I6TfdGxObUg", "2beuhrfBZvjdkmfqV9yn",
                          "AuIhF3lUgwT0OMy8DuUx", "dVW2KAL06gB4s7rEf508", "jnsp7MGfl5wZNZVfQSvp",
                          "p26Kfhz0Iof6rJDy27vc", "bnWXfp2eexq7MPpcmRSI", "tMEU0L6RNvqDAaV6HN0e",
                          "POcbaPteUMFfltrwdu7r", "epDGhJZoKoL4i1HO67XS", "o83N1RTIeOafqBfqeAYh",
                          "aYRtwuDT8k7k7iIfTrtU", "fEPXIREoFGKXqnNKySG5", "QrqmIbVVIQzf8WKBxiga",
                          "k5NSg0Dq0b9ewfrhYdy7", "Tf9dsqBADfMeWVQGG3Zk", "dS2LouElpUXsXNCClr4B",
                          "tsvf3JaWNg5JlSDZs1Dm", "oWurB8fBAIBQq1ZnlFiR", "8YllXP80XunEXhqnjkZc",
                          "Spt36tVcEkIFjwogWli0", "c25H1u6DF9RVdagn81DA", "AjWfT7TlXgzSKOywpoTH",
                          "ZwTg8WNnmXOJKdW6ZeJv", "E9aYpoCXd1kbSWhdLOnf", "QN1iAuoSNQ5WvHeSeSSL",
                          "7g5wfNllowIaqMUVjywr", "b38gJrosdk9xEQ2K8Gbu", "KdVdRVLHJg9Bazc4cpM7",
                          "COJeGmQEzjXwqKCAnd6J", "2k6XCpXEkP7QoST6uYoy" };

    std::string y[32] = { "TZ3QuE3ZNUbFrEpQhgcY", "BX2lyPzOWRIznb34T5OT", "v7lPrSeDokdBIUXR9QGh",
                          "nAQxkuEYL5k1Er7FspKu", "r8T4oZaWBI1m7sPBEDz3", "pdxM9tJrYZskZla7L7yM",
                          "dIIx6eKTfygu24SNKa32", "tw04BOo705mdWxuDciNO", "q94icFprhKrrFXLvjEN3",
                          "uM25BWUl14NTlTwFsNIv", "2oTV9fXUESLQqzvsPFmd", "W6ASLRzrlOggx5b7CtYN",
                          "bz4BQ7rLU203RNwwmbMK", "jfWgRPiuy1P3NGDPWmbe", "PgtdYLdGuneYEUgMA8SB",
                          "eaaFugCSOOU5my4y4SkG", "gGd4FiUEJwgvhOCSHu9g", "9K0ZhqlbyDCJXYXHoEIN",
                          "VTmk8m7rbEGl8ntGpTCQ", "eRJ98PUF2tSMX6zpDOi4", "wFMJIDAbjYnJkxMxkAtL",
                          "JCOXV4iPcIt72DcNnbuY", "LsnOUrHHD2FNFH5DMvbc", "YVPp2jPqK3jmif7yY14r",
                          "JBMhRRtLY3QX3x1ZVDCs", "Uwo5PD2RLMx5ByW9Rscq", "O4Q6DPBJHOelMtBKc9GQ",
                          "Bq0H2eqnuCYqyj9F5Lkn", "P2fJf0TYN92iUXkwELjG", "f656ltXlumpc7YyPVjan",
                          "YQfr76LAA1xKokfq8HpL", "6utvLeZ9t0IM4OkdfAQ2" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = std::make_pair(x[i], y[i]);
    }
}

template <typename T>
void init_array_str_str(ft::pair<std::string, std::string>* arr, std::size_t size)
{
    std::string x[32] = { "RxWAUMME3GtF9Zbv3a4M", "WC96vs7Z6I6TfdGxObUg", "2beuhrfBZvjdkmfqV9yn",
                          "AuIhF3lUgwT0OMy8DuUx", "dVW2KAL06gB4s7rEf508", "jnsp7MGfl5wZNZVfQSvp",
                          "p26Kfhz0Iof6rJDy27vc", "bnWXfp2eexq7MPpcmRSI", "tMEU0L6RNvqDAaV6HN0e",
                          "POcbaPteUMFfltrwdu7r", "epDGhJZoKoL4i1HO67XS", "o83N1RTIeOafqBfqeAYh",
                          "aYRtwuDT8k7k7iIfTrtU", "fEPXIREoFGKXqnNKySG5", "QrqmIbVVIQzf8WKBxiga",
                          "k5NSg0Dq0b9ewfrhYdy7", "Tf9dsqBADfMeWVQGG3Zk", "dS2LouElpUXsXNCClr4B",
                          "tsvf3JaWNg5JlSDZs1Dm", "oWurB8fBAIBQq1ZnlFiR", "8YllXP80XunEXhqnjkZc",
                          "Spt36tVcEkIFjwogWli0", "c25H1u6DF9RVdagn81DA", "AjWfT7TlXgzSKOywpoTH",
                          "ZwTg8WNnmXOJKdW6ZeJv", "E9aYpoCXd1kbSWhdLOnf", "QN1iAuoSNQ5WvHeSeSSL",
                          "7g5wfNllowIaqMUVjywr", "b38gJrosdk9xEQ2K8Gbu", "KdVdRVLHJg9Bazc4cpM7",
                          "COJeGmQEzjXwqKCAnd6J", "2k6XCpXEkP7QoST6uYoy" };

    std::string y[32] = { "TZ3QuE3ZNUbFrEpQhgcY", "BX2lyPzOWRIznb34T5OT", "v7lPrSeDokdBIUXR9QGh",
                          "nAQxkuEYL5k1Er7FspKu", "r8T4oZaWBI1m7sPBEDz3", "pdxM9tJrYZskZla7L7yM",
                          "dIIx6eKTfygu24SNKa32", "tw04BOo705mdWxuDciNO", "q94icFprhKrrFXLvjEN3",
                          "uM25BWUl14NTlTwFsNIv", "2oTV9fXUESLQqzvsPFmd", "W6ASLRzrlOggx5b7CtYN",
                          "bz4BQ7rLU203RNwwmbMK", "jfWgRPiuy1P3NGDPWmbe", "PgtdYLdGuneYEUgMA8SB",
                          "eaaFugCSOOU5my4y4SkG", "gGd4FiUEJwgvhOCSHu9g", "9K0ZhqlbyDCJXYXHoEIN",
                          "VTmk8m7rbEGl8ntGpTCQ", "eRJ98PUF2tSMX6zpDOi4", "wFMJIDAbjYnJkxMxkAtL",
                          "JCOXV4iPcIt72DcNnbuY", "LsnOUrHHD2FNFH5DMvbc", "YVPp2jPqK3jmif7yY14r",
                          "JBMhRRtLY3QX3x1ZVDCs", "Uwo5PD2RLMx5ByW9Rscq", "O4Q6DPBJHOelMtBKc9GQ",
                          "Bq0H2eqnuCYqyj9F5Lkn", "P2fJf0TYN92iUXkwELjG", "f656ltXlumpc7YyPVjan",
                          "YQfr76LAA1xKokfq8HpL", "6utvLeZ9t0IM4OkdfAQ2" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = ft::make_pair(x[i], y[i]);
    }
}

#define SETUP_MAP_ARRAYS()                                                                         \
    std::pair<int, std::string> std_intstr_arr[64];                                                \
    ft::pair<int, std::string> ft_intstr_arr[64];                                                  \
    init_array_int_str<void>(std_intstr_arr, 64);                                                  \
    init_array_int_str<void>(ft_intstr_arr, 64);                                                   \
    std::pair<std::string, std::string> std_strstr_arr[32];                                        \
    ft::pair<std::string, std::string> ft_strstr_arr[32];                                          \
    init_array_str_str<void>(std_strstr_arr, 32);                                                  \
    init_array_str_str<void>(ft_strstr_arr, 32);                                                   \
    std::size_t intstr_size = 64;                                                                  \
    std::size_t strstr_size = 32;                                                                  \
    (void)std_intstr_arr;                                                                          \
    (void)ft_intstr_arr;                                                                           \
    (void)std_strstr_arr;                                                                          \
    (void)ft_strstr_arr;                                                                           \
    (void)intstr_size;                                                                             \
    (void)strstr_size;                                                                             \
    std::__1::chrono::steady_clock::time_point start;                                              \
    std::__1::chrono::steady_clock::time_point end;                                                \
    std::chrono::duration<double, std::milli> t1;                                                  \
    std::chrono::duration<double, std::milli> t2;                                                  \

typedef std::map<int, std::string, std::less<int> > intmap;
typedef std::map<std::string, std::string, std::less<std::string> > strmap;
typedef ft::map<int, std::string, std::less<int> > _intmap;
typedef ft::map<std::string, std::string, std::less<std::string> > _strmap;

void runMapTests();