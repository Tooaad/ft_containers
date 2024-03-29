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
			typedef T													iterator_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			ReverseIter(void) : _ptr() {}
			explicit ReverseIter(pointer x) : _ptr(x) {}
			template <class U>
			ReverseIter(const ReverseIter<U>& iter) : _ptr(iter.base()) {}
			~ReverseIter() {}

			template <class U>
			ReverseIter&	operator=(const ReverseIter<U>& other) {
				this->_ptr = other.base();
				return *this;
			}

			pointer base() const { return this->_ptr; }

			reference operator*() const { pointer tmp = this->_ptr; return *(--tmp); }
			pointer operator->() const { return (&(*(*this))); }
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

	template <typename A, typename B>
	ptrdiff_t		operator-(const ReverseIter<A>& lhs, const ReverseIter<B>& rhs) {
		return rhs.base() - lhs.base();
	}

	template <typename A>
	ReverseIter<A>		operator+(typename ReverseIter<A>::difference_type n, const ReverseIter<A>& rhs) {
		return (ReverseIter<A>)(rhs.base() - n);
	}

}
