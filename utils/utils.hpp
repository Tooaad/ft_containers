/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:09:40 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/17 11:52:18 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	template <typename T>
	void swap(T& x, T& y) {
		const T swap = x;
		x = y;
		y = swap;
	} 

	template <bool Cond, class T = void>
	struct enable_if {};
	
	template <class T>
	struct enable_if<true, T> { typedef T type; };
	
	/*-- Is Integral --*/
	template <typename T>
	struct	is_integral{ static bool const value = false; };

	template <>	struct	is_integral<bool>{ static bool const value = true; };
	template <>	struct	is_integral<char>{ static bool const value = true; };
	template <>	struct	is_integral<wchar_t>{ static bool const value = true; };
	template <>	struct	is_integral<signed char>{ static bool const value = true; };
	template <>	struct	is_integral<short int>{ static bool const value = true; };
	template <>	struct	is_integral<int>{ static bool const value = true; };
	template <>	struct	is_integral<long int>{ static bool const value = true; };
	template <>	struct	is_integral<long long int>{ static bool const value = true; };
	template <>	struct	is_integral<unsigned char>{ static bool const value = true; };
	template <>	struct	is_integral<unsigned short int>{ static bool const value = true; };
	template <>	struct	is_integral<unsigned int>{ static bool const value = true; };
	template <>	struct	is_integral<unsigned long int>{ static bool const value = true; };
	template <>	struct	is_integral<unsigned long long int>{ static bool const value = true; };

}