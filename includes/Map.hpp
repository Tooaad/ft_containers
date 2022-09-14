/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:56:24 by gpernas-          #+#    #+#             */
/*   Updated: 2022/09/14 17:32:37 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional> // For binary_function
#include <iostream>
#include "../utils/pair.hpp"
#include "../utils/utils.hpp"
#include "RBTree.hpp"
#include "ReverseIter.hpp"

namespace ft {
template <class Key, class Value, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, Value> > >
	class map {
		public:
			typedef Key													key_type;
			typedef Value												mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef ft::Node<value_type>								node_type;
			typedef node_type*											node_pointer;
			typedef typename Allocator::reference						reference;
			typedef typename Allocator::const_reference					const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;
			typedef typename Allocator::difference_type					difference_type;
			typedef typename Allocator::size_type						size_type;
	
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					key_compare comp;
					bool operator()(const value_type& x, const value_type& y) const
						{ return comp(x.first, y.first); }
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
			
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
				: _tree(), _alloc(alloc), _comp(comp) {}

			template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _alloc(alloc), _comp(comp) {
					insert(first, last);
				}
			
			map(const map& x) { *this = x; }

			~map() {}

			map& operator= (const map& x) {
				if(this != &x) {
					this->_tree = x._tree;
					this->_comp = x._comp;
					this->_alloc = x._alloc;
					
				}
				return *this;
			}

			tree_type& getTree() {
				return this->_tree;
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

			// BUSCA LA CLAVE NO LA POSICION
			mapped_type& operator[](const key_type& k) 
			{
				if (this->_tree.find(k).second == false)
					((this->insert(ft::make_pair(k,mapped_type()))));
				return (this->_tree.find(k).first->_value.second);
			}

			mapped_type& at(const key_type& k)
			{
				if (this->_tree.find(k).second == false)
					throw std::out_of_range("Index out of range");
				return (this->_tree.find(k).first->_value.second);
			}
			
			const mapped_type& at(const key_type& k) const
			{
				if (this->_tree.find(k).second == false)
					throw std::out_of_range("Index out of range");
				return (this->_tree.find(k).first->_value.second);
			}

	//	Modifiers

			ft::pair<iterator, bool> insert(const value_type& val) {
				this->_tree.increment_size();
				return this->_tree.insert(val);
			}

			//PROBAR
			iterator insert(iterator position, const value_type& val) {
				(void) position;
				return insert(val).first;
			}

			template <class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					for(InputIterator it = first; it != last; it++) {
						insert(*it);
					}
				}

			void erase(iterator position) {
				this->_tree.decrement_size();
				return this->_tree.erase(position._root);
			}
			
			size_type erase(const key_type& k) {
				node_pointer element = _tree.find(k);
				if (!element || (element == end()._root && k != end()._root->_value.first))
					return 0;
				this->_tree.erase(element);
				_tree.print2D(this->_tree._root);
				return 1;
			}
			
			template <class InputIterator>
			void erase(iterator first, iterator last) {
				for(InputIterator it = first; it != last; it++) {
					erase(*it);
				}
			}

			void swap(map& x) {
				ft::swap(this->_alloc, x._alloc);
				ft::swap(this->_comp, x._comp);
				ft::swap(this->_tree, x._tree);
			}

			void clear() { this->_tree.clear(); }

			key_compare key_comp() const { return this->_comp; }

			value_compare value_comp() const { return value_compare(this->_comp); }


			iterator find(const key_type& k) { return iterator(this->_tree.find(k).first); }
			const_iterator find(const key_type& k) const { return const_iterator(this->_tree.find(k).first); }
			
			size_type count(const key_type& k) {
				iterator found = this->find(k);
				if (found == end() && k != end()._root->_value.first)
					return 0;
				return 1;
			}
			iterator lower_bound(const key_type& k) { return find(k); }
			const_iterator lower_bound(const key_type& k) const { return find(k); }
			iterator upper_bound(const key_type& k) { return ++find(k); }
			const_iterator upper_bound(const key_type& k) const { return ++find(k); }
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {return ft::make_pair(lower_bound(k), upper_bound(k)); }
			ft::pair<iterator,iterator> equal_range(const key_type& k) { return ft::make_pair(lower_bound(k), upper_bound(k)); }
			allocator_type get_allocator() const { return allocator_type(this->_tree._node_alloc); }
	};
}