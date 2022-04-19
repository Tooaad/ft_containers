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
	class VectorIter {

		public:		
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			VectorIter() : _ptr(nullptr) {}
			explicit VectorIter(pointer x) : _ptr(x) {}
			template <class U>
			VectorIter(const VectorIter<U> &iter) : _ptr(iter._ptr) {}
			~VectorIter() {}

			template <class U>
			VectorIter&	operator=(const VectorIter<U>& other) {
				this->_ptr = other._ptr;
				return *this;
			}

			pointer base() const {return _ptr;}

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator[](difference_type pos) const {return *(*this + pos); }

			VectorIter& operator++() { _ptr++; return *this; }  
			VectorIter operator++(int) { VectorIter tmp = *this; ++(*this); return tmp; }
			VectorIter& operator--() { _ptr--; return *this; }  
			VectorIter operator--(int) { VectorIter tmp = *this; --(*this); return tmp; }
			VectorIter& operator+=(difference_type pos) { this->_ptr += pos; return *this; }  
			VectorIter& operator-=(difference_type pos) { this->_ptr -= pos; return *this; }  
			VectorIter operator+(difference_type pos) const { return VectorIter(this->_ptr + pos); }
			VectorIter operator-(difference_type pos) const { return VectorIter(this->_ptr - pos); }

		private:
			pointer _ptr;
	};
	
	template <class A, class B>
	bool operator==(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() == b.base(); }
			
	template <class A, class B>
	bool operator!=(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() != b.base(); }
			
	template <class A, class B>
	bool operator<(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() < b.base(); }
		
	template <class A, class B>
	bool operator>(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() > b.base(); }
			
	template <class A, class B>
	bool operator<=(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() <= b.base(); }
			
	template <class A, class B>
	bool operator>=(const VectorIter<A>& a, const VectorIter<B>& b) { return a.base() >= b.base(); }    

}


	// public:
	// 	typedef typename ft::iter_traits<T>::difference_type	diference_type;
	// 	typedef typename ft::iter_traits<T>::value_type 		value_type;
	// 	typedef typename ft::iter_traits<T>::reference 			reference;
	// 	typedef typename ft::iter_traits<T>::pointer			pointer;
	// 	typedef typename std::random_access_iter_tag			iter_category;
		
	// private:
	// 	pointer _ptr;
		
	// public:
	// 	Iter(): _ptr(0) {}
	// 	Iter(pointer ptr): _ptr(ptr) {}
	// 	~Iter() {}
	// 	Iter&	operator=(Iter const & iter) {
	// 		this->_ptr = iter._ptr;
	// 		return *this;
	// 	}
	// 	template <typename E>
	// 	Iter(const Iter<E> &iter): _ptr(iter._ptr) {}

	// 	// pointer getPtr() const {
	// 	// 	return this->_ptr;
	// 	// }
		
	// 	Iter&	operator++() {++_ptr; return *this;}
	// 	Iter&	operator++(int) {
	// 		Iter temp(*this);
	// 		++(*this);
	// 		return temp;
	// 	}
	// 	Iter&	operator--() {--_ptr; return *this;}
	// 	Iter&	operator--(int) {
	// 		Iter temp(*this);
	// 		--(*this);
	// 		return temp;
	// 	}
	// 	friend bool	operator==(const Iter& a, const Iter& b) {
	// 		return a._ptr == b._ptr;
	// 	}
	// 	friend bool	operator!=(const Iter& a, const Iter& b) {
	// 		return a._ptr != b._ptr;
	// 	}
	// 	reference	operator*() const {return this->*_ptr;}
	// 	pointer		operator->() const {return this->_ptr;}
		

	// };