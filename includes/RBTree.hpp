/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:56 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "TreeIter.hpp"
#include "../utils/pair.hpp"

namespace ft {
template <class Pair, class Compare, class Alloc>
	class RBTree
	{
		public:
			typedef Pair												value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator;
			typedef size_t												size_type;
			typedef ft::Node<Pair>										node_type;
			typedef typename Alloc::template rebind<node_type>::other	node_allocator;
			typedef typename node_allocator::pointer					pointer;
			typedef typename node_allocator::const_pointer				const_pointer;
			typedef typename ft::TreeIter<pointer, Pair>				iterator;
			typedef typename ft::TreeIter<const_pointer, Pair>			const_iterator;
			typedef typename ft::ReverseIter<iterator>					reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>			const_reverse_iterator;
			
			pointer		 	_root;
			size_type		_size;
			key_compare 	_comp;
			node_allocator	_node_alloc;
			
			explicit RBTree(const key_compare& comp = key_compare() , const node_allocator& node_alloc = node_allocator())
				: _root(0), _size(0), _comp(comp), _node_alloc(node_alloc) {
					std::cout << "'2" << std::endl;
				}

			RBTree(const RBTree& otherTree) {
					*this = otherTree;
			}
			
			RBTree& operator=(const RBTree& otherTree) {
				// if (this != &otherTree) {
				// 	this->value_compare() = otherTree.value_compare();
				// 	if (this->node_alloc() != otherTree.node_alloc())
				// 		clear();
				// 	this->node_alloc() = otherTree.node_alloc();
	
				// }

				if (this != &otherTree) {
					this->_root = otherTree._root;
					this->_size = otherTree._size;
					this->_node_alloc = otherTree._node_alloc;
					this->_comp = otherTree._comp;
				}
				
				return *this;
			}
			
			~RBTree() {}

			pointer createNode(const value_type& insPair) {
				pointer newNod = _node_alloc.allocate(1);
				_node_alloc.construct(newNod, insPair);
				return newNod;
			}
			
			ft::Pair<node_type*, bool> insert(const value_type& insPair) {
				if (!this->_root) {
					this->_root = createNode(insPair);
					this->_root->_color = 0;
					this->_size++;
					return ft::make_pair(this->_root, true);
				}
				else {
					// pointer	tmp = root;
					
				}
				return ft::make_pair(this->_root, true);
			}
			// key_compare& value_compare() { return this->_root->_data->second; }
	
	};
}