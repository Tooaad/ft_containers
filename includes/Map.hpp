/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:56:24 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/19 01:36:31 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional> // For binary_function
#include <iostream>
#include "../utils/pair.hpp"
#include "RBTree.hpp" 

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
			// typedef typename ft::TreeIter<pointer, value_type>			iterator;
			// typedef typename ft::TreeIter<const_pointer, value_type>	const_iterator;
			// typedef typename ft::ReverseIter<iterator>					reverse_iterator;
			// typedef typename ft::ReverseIter<const_iterator>			const_reverse_iterator;
			typedef typename Allocator::difference_type					difference_type;
			typedef typename Allocator::size_type						size_type;
	
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					key_compare comp;
					bool operator()(const value_type& x, const value_type& y) const
						{ return comp(x._first, y._first); }
			};

			typedef ft::RBTree<value_type, value_compare, allocator_type>	tree_type;
			typedef typename tree_type::iterator							iterator;
			typedef typename tree_type::const_iterator						const_iterator;
			typedef typename ft::ReverseIter<iterator>						reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>				const_reverse_iterator;			

		private:
			tree_type		_tree;
			allocator_type	_alloc;
			key_compare		_comp;

		public:
			
			explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
				: _tree(), _alloc(alloc), _comp(comp) {}

			template <class InputIterator>
				Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _alloc(alloc), _comp(comp) {
					insert(first, last);
				}
			
			Map(const Map& x) : _tree(x._tree) {
				insert(x.begin(), x.end());
			}

			~Map() {}

			Map& operator= (const Map& x) {
				if(this != &x) {
					this->_tree.clear();
					this->_tree = x._tree;
					this->_alloc = x._alloc;
					
				}
				return *this;
			}

	//	ITERATORS

			iterator begin() { return this->_tree.begin(); }
			const_iterator begin() const { return this->_tree.begin(); }
			iterator end() { return this->_tree.end(); } 
			const_iterator end() const { return this->_tree.end(); } 
			reverse_iterator rbegin() { return this->_tree.rbegin(); }
			const_reverse_iterator rbegin() const { return this->_tree.rbegin(); }
			reverse_iterator rend() { return this->_tree.rend(); }
			const_reverse_iterator rend() const { return this->_tree.rend(); } 
			
	//	CAPACITY

			bool empty() const {
				return (this->_tree.size() == 0);
			}

			size_type size() const {
				return this->_tree.size();
			}

			size_type max_size() const {
				return this->_tree.max_size();
			}

			mapped_type& operator[](const key_type& k) 
			{ 
				std::cout << "--" << (*((this->_tree.insert(ft::make_pair(k, mapped_type())))._first)._root)._value._second <<std::endl;
				std::cout << "--" << (*((this->_tree.insert(ft::make_pair(k, mapped_type())))._first)._root)._left->_value._second <<std::endl;
				if (this->_tree.size() > 1)
					std::cout << "--" << (*((this->_tree.insert(ft::make_pair(k, mapped_type())))._first)._root)._right->_value._second <<std::endl;


				return (*((this->_tree.insert(ft::make_pair(k, mapped_type())))._first)._root)._value._second;

			}

	//	Modifiers

			ft::Pair<iterator, bool> insert(const value_type& val) {
				this->_tree.increment_size();
				return this->_tree.insert(val);
				
			}

			iterator insert(iterator position, const value_type& val) {
				(void) position;
				this->_tree.increment_size();
				return this->_tree.insert(val)._first;
			}

			template <class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					for(InputIterator it = first; it != last; it++) {
						this->_tree.increment_size();
						insert(*it);
					}
				}


			void erase(iterator position) {
				(void) position;
			}
			
			size_type erase(const key_type& k) {
				(void) k;
				return ;
			}

			void erase(iterator first, iterator last) {
				(void)first;
				(void)last;
			}

			void swap(Map& x) {
				ft::swap(this->_alloc, x._alloc);
				ft::swap(this->_comp, x._comp);
				// this->_tree.swap(x._tree);
			}

			void clear() { this->_tree.clear(); }

			key_compare key_comp() const { return this->_comp; }

			value_compare value_comp() const { return value_compare(this->_comp); }


			// iterator find(const key_type& k) {}
			// const_iterator find(const key_type& k) const {}
			size_type count(const key_type& k) const {
				if (this->_root.find(ft::make_pair(k, mapped_type())) != NULL)
					return 1;
				return 0;
			}
			// iterator lower_bound(const key_type& k) {}
			// const_iterator lower_bound(const key_type& k) const {}
			// iterator upper_bound(const key_type& k) {}
			// const_iterator upper_bound(const key_type& k) const {}
			// ft::Pair<const_iterator, const_iterator> equal_range(const key_type& k) const {}
			// ft::Pair<iterator,iterator> equal_range(const key_type& k) {}
			allocator_type get_allocator() const { return allocator_type(this->_tree._node_alloc); }
	};
}