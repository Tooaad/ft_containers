/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:18:11 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/09 10:35:45 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft {
	template <typename T>
	class ReverseIter {

		public:		
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			ReverseIter() : _ptr(nullptr) {}
			explicit ReverseIter(pointer x) : _ptr(x) {}
			template <class U>
			ReverseIter(const ReverseIter<U> &iter) : _ptr(iter._ptr) {}
			~ReverseIter() {}

			template <class U>
			ReverseIter&	operator=(const ReverseIter<U>& other) {
				this->_ptr = other._ptr;
				return *this;
			}

			ReverseIter base() const {return _ptr;}

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator[](difference_type pos) const {return *(*this + pos); }

			ReverseIter& operator++() { _ptr--; return *this; }  
			ReverseIter operator++(int) { ReverseIter tmp = *this; --(*this); return tmp; }
			ReverseIter& operator--() { _ptr++; return *this; }  
			ReverseIter operator--(int) { ReverseIter tmp = *this; ++(*this); return tmp; }
			ReverseIter& operator+=(difference_type pos) { this->_ptr -= pos; return *this; }  
			ReverseIter& operator-=(difference_type pos) { this->_ptr += pos; return *this; }  
			ReverseIter operator+(difference_type pos) const { return ReverseIter(this->_ptr - pos); }
			ReverseIter operator-(difference_type pos) const { return ReverseIter(this->_ptr + pos); }

		private:
			pointer _ptr;
	};
	
	template <class A, class B>
	bool operator==(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() == b.base(); }
			
	template <class A, class B>
	bool operator!=(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() != b.base(); }
			
	template <class A, class B>
	bool operator<(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() < b.base(); }
		
	template <class A, class B>
	bool operator>(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() > b.base(); }
			
	template <class A, class B>
	bool operator<=(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() <= b.base(); }
			
	template <class A, class B>
	bool operator>=(const ReverseIter<A>& a, const ReverseIter<B>& b) { return a.base() >= b.base(); }

}
