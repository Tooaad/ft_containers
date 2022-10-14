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
	class ReverseIterMap {

		public:
			typedef T													iterator_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			ReverseIterMap(void) : _ptr() {}
			explicit ReverseIterMap(T x) : _ptr(x) {}
			template <class U>
			ReverseIterMap(const ReverseIterMap<U>& iter) : _ptr(iter.base()) {}
			~ReverseIterMap() {}

			template <class U>
			ReverseIterMap&	operator=(const ReverseIterMap<U>& other) {
				this->_ptr = other.base();
				return *this;
			}

			T base() const { return this->_ptr; }

			reference operator*() const { T tmp = this->_ptr; return *(--tmp); }
			pointer operator->() const { return (&(*(*this))); }
			reference operator[](difference_type pos) const {return *(*this + pos); }

			ReverseIterMap& operator++() { _ptr--; return *this; }  
			ReverseIterMap operator++(int) { ReverseIterMap tmp = *this; --(*this); return tmp; }
			ReverseIterMap& operator--() { _ptr++; return *this; }  
			ReverseIterMap operator--(int) { ReverseIterMap tmp = *this; ++(*this); return tmp; }
			ReverseIterMap& operator+=(difference_type pos) { this->_ptr -= pos; return *this; }  
			ReverseIterMap& operator-=(difference_type pos) { this->_ptr += pos; return *this; }  
			ReverseIterMap operator+(difference_type pos) const { return ReverseIterMap(this->_ptr - pos); }
			ReverseIterMap operator-(difference_type pos) const { return ReverseIterMap(this->_ptr + pos); }

		private:
			T _ptr;
	};
	
	template <class A, class B>
	bool operator==(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() == b.base(); }
			
	template <class A, class B>
	bool operator!=(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() != b.base(); }
			
	template <class A, class B>
	bool operator<(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() < b.base(); }
		
	template <class A, class B>
	bool operator>(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() > b.base(); }
			
	template <class A, class B>
	bool operator<=(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() <= b.base(); }
			
	template <class A, class B>
	bool operator>=(const ReverseIterMap<A>& a, const ReverseIterMap<B>& b) { return a.base() >= b.base(); }

	template <typename A, typename B>
	ptrdiff_t		operator-(const ReverseIterMap<A>& lhs, const ReverseIterMap<B>& rhs) {
		return rhs.base() - lhs.base();
	}

	template <typename A>
	ReverseIterMap<A>		operator+(typename ReverseIterMap<A>::difference_type n, const ReverseIterMap<A>& rhs) {
		return (ReverseIterMap<A>)(rhs.base() - n);
	}

}
