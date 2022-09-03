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

#include "../includes/iterator_traits.hpp"

namespace ft {
template <typename T>
	class vectorIter {

		public:		
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			vectorIter() : _ptr() {}
			explicit vectorIter(pointer x) : _ptr(x) {}
			template <class U>
			vectorIter(const vectorIter<U> &iter) : _ptr(iter.base()) {}
			~vectorIter() {}

			template <class U>
			vectorIter&	operator=(const vectorIter<U>& other) {
				this->_ptr = other._ptr;
				return *this;
			}

			pointer base() const { return _ptr; }

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator[](difference_type pos) const {return *(*this + pos); }

			vectorIter& operator++() { _ptr++; return *this; }  
			vectorIter operator++(int) { vectorIter tmp = *this; ++(*this); return tmp; }
			vectorIter& operator--() { _ptr--; return *this; }  
			vectorIter operator--(int) { vectorIter tmp = *this; --(*this); return tmp; }
			vectorIter& operator+=(difference_type pos) { this->_ptr += pos; return *this; }  
			vectorIter& operator-=(difference_type pos) { this->_ptr -= pos; return *this; }  
			vectorIter operator+(difference_type pos) const { return vectorIter(this->_ptr + pos); }
			vectorIter operator-(difference_type pos) const { return vectorIter(this->_ptr - pos); }

		private:
			pointer _ptr;
	};
	
	template <class A, class B>
	bool operator==(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() == b.base(); }
			
	template <class A, class B>
	bool operator!=(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() != b.base(); }
			
	template <class A, class B>
	bool operator<(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() < b.base(); }
		
	template <class A, class B>
	bool operator>(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() > b.base(); }
			
	template <class A, class B>
	bool operator<=(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() <= b.base(); }
			
	template <class A, class B>
	bool operator>=(const vectorIter<A>& a, const vectorIter<B>& b) { return a.base() >= b.base(); } 

	template <typename A, typename B>
	ptrdiff_t		operator-(const vectorIter<A>& lhs, const vectorIter<B>& rhs) {
		return rhs.base() - lhs.base();
	}

	template <typename A>
	vectorIter<A>		operator+(typename vectorIter<A>::difference_type n, const vectorIter<A>& rhs) {
		return (vectorIter<A>)(rhs.base() - n);
	}     

}
