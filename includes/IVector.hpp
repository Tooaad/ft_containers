/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IVector.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:32:54 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/19 11:29:07 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include "VectorIter.hpp"
#include "ReverseIter.hpp"

template <class T, class Allocator = std::allocator<T> >
class Integers
{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef typename ft::VectorIter<pointer>			iterator;
		typedef typename ft::VectorIter<const_pointer>		const_iterator;
		typedef typename ft::ReverseIter<iterator>			reverse_iterator;
		typedef typename ft::ReverseIter<const_iterator>	const_reverse_iterator;
		typedef typename Allocator::difference_type			difference_type;
		typedef typename Allocator::size_type				size_type;


		// #1 Default Constructor ✔️
		// #2 Fill Constructor ✔️
		// #3 Range Constructor ✔️
		// #4 Copy Constructor ✔️
		
/* ~ */	virtual ~Integers() {}
		
/* ~ */	virtual Integers& operator=(const Integers& otherVector) const = 0;

/* ✔️✔️✔️ */ virtual iterator				begin() const = 0;
/* ✔️ */ virtual const_iterator			begin() const = 0;
/* ✔️✔️✔️ */ virtual iterator				end() const = 0;
/* ✔️ */ virtual const_iterator			end() const = 0;
/* ✔️ */ virtual reverse_iterator		rbegin() const = 0;
/* ✔️ */ virtual const_reverse_iterator	rbegin() const = 0;
/* ✔️ */ virtual reverse_iterator		rend() const = 0;
/* ✔️ */ virtual const_reverse_iterator	rbegin() const = 0;

/* ✔️✔️✔️ */ virtual size_type 				size() const = 0;
/* ✔️✔️✔️ */ virtual size_type				max_size() const = 0;
/* ✔️✔️✔️ */ virtual size_type				resize() const = 0;
/* ✔️✔️✔️ */ virtual size_type				capacity() const = 0;
/* ✔️ */ virtual bool					empty()	const = 0;
/* ✔️✔️✔️✔ */ virtual void					reserve(size_type n) const = 0;
		
/* ✔️✔️✔️ */ virtual reference      		operator[](size_type n) const = 0;
/* ✔️ */ virtual const_reference		operator[](size_type n) const = 0;
/* ✔️✔️✔️ */ virtual reference       		at(size_type n) const = 0;
/* ✔️ */ virtual const_reference		at(size_type n) const = 0;
/* ✔️✔️✔️ */ virtual reference		    	front() const = 0;
/* ✔️ */ virtual const_reference 		front() const = 0;
/* ✔️✔️✔️ */ virtual reference		       	back() const = 0;
/* ✔️ */ virtual const_reference 		back() const = 0;

		template <class InputIterator>
/* ✔️✔️✔️ */ 	virtual void assign(InputIterator first, InputIterator last) const = 0;
/* ✔️✔️✔️ */ virtual void assign(size_type n, const value_type& u) const = 0;
/* ✔️✔️✔️ */ virtual void push_back(const value_type& x) const = 0;
/* ✔️✔️✔️ */ virtual void pop_back() const = 0;
/* ✔️✔️✔️ */ virtual iterator insert(const_iterator position, const value_type& x) const = 0;
/* ✔️✔️✔️ */	virtual iterator insert(const_iterator position, size_type n, const value_type& x) const = 0;
    	template <class InputIterator>
/* ✔️✔️✔️ */  	virtual iterator insert(const_iterator position, InputIterator first, InputIterator last) const = 0;;
/* ✔️✔️✔️ */ virtual iterator erase(const_iterator position) const = 0;
/* ✔️✔️✔️ */ virtual iterator erase(const_iterator first, const_iterator last) const = 0;
/* ✔️✔️✔️ */	virtual void swap(vector& x) const = 0;
/* ✔️✔️✔️ */ virtual void clear() const = 0;

/* ✔️ */	virtual allocator_type get_allocator() const = 0;

		// Relational Operators + Swap2

};