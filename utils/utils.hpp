/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:09:40 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/21 00:57:48 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
namespace ft
{

	template <typename T>
	void swap(T &x, T &y)
	{
		const T swap = x;
		x = y;
		y = swap;
	}

	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
        		    InputIterator2 first2) 
		{
			while (first1!=last1) {
    			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      				return false;
    			++first1; ++first2;
  			}
  			return true;
		}

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
        		                    InputIt2 first2, InputIt2 last2,
                		            Compare comp)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        	if (comp(*first1, *first2)) return true;
        	if (comp(*first2, *first1)) return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}

	template <bool Cond, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/*-- Is Integral --*/
	template <typename T>
	struct is_integral
	{
		static bool const value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<char>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<wchar_t>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<signed char>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<short int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<long int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<long long int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<unsigned char>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<unsigned short int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<unsigned int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<unsigned long int>
	{
		static bool const value = true;
	};
	template <>
	struct is_integral<unsigned long long int>
	{
		static bool const value = true;
	};

}