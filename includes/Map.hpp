/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:56:24 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/04 20:50:49 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional> // For binary_function
#include <iostream>
#include "../utils/pair.hpp"
#include "TreeIter.hpp"

namespace ft {
template <class Key, class Value, class Compare = std::less<Key>, class Allocator = std::allocator<ft::Pair<const Key, Value> > >
	class Map {
		public:
			typedef Key													key_type;
			typedef Value												mapped_type;
			typedef ft::Pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef typename Allocator::reference						reference;
			typedef typename Allocator::const_reference					const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;
			typedef typename ft::TreeIter<pointer, value_type>			iterator;
			typedef typename ft::TreeIter<const_pointer, value_type>	const_iterator;
			typedef typename ft::ReverseIter<iterator>					reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>			const_reverse_iterator;
			typedef typename Allocator::difference_type					difference_type;
			typedef typename Allocator::size_type						size_type;
	
			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c);
				public:
					bool operator()(const value_type& x, const value_type& y) const
						{ return x == y; }
			}
			
	
	};
}