/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:18:11 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/06 01:43:47 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator_traits.hpp>

namespace ft {
	template <typename t>
	class Iter {
		
	public:
		typedef typename ft::iterator_traits<T>::difference_type	diference_type;
		typedef typename ft::iterator_traits<T>::value_type 		value_type;
		typedef typename ft::iterator_traits<T>::reference 			reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef typename std::random_access_iterator_tag			iterator_category;
		
	private:
		int* _ptr;
		
	public:
		Iter(): _ptr(0) {}
		Iter(int *ptr): _ptr(ptr) {}
		~Iter() {}
		Iter&	operator=(Iter const & ptr) {
			this->_ptr = ptr;
			return *this;
		}

		int* getPtr() const {
			return this->_ptr;
		}
		
		

	};
}

