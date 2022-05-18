/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/18 20:49:43 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "TreeIter.hpp"
#include "../utils/pair.hpp"
#include "allocator_traits.hpp"

namespace ft {
template <class Pair, class Compare, class Alloc>
	class RBTree
	{
		public:
			typedef Pair												value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator;
			typedef size_t												size_type;
			typedef ptrdiff_t											difference_type;
			typedef ft::Node<Pair>										node_type;
			typedef typename Alloc::template rebind<node_type>::other	node_alloc;
			typedef ft::allocator<node_alloc>							node_traits;
			typedef typename node_alloc::pointer						pointer;
			typedef typename node_alloc::const_pointer					const_pointer;
			typedef typename ft::TreeIter<pointer, Pair>				iterator;
			typedef typename ft::TreeIter<const_pointer, Pair>			const_iterator;
			typedef typename ft::ReverseIter<iterator>					reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>			const_reverse_iterator;
			
			pointer		 	_root;
			size_type		_size;
			key_compare 	_comp;
			node_alloc		_node_alloc;
			
			explicit RBTree(const key_compare& comp = key_compare() , const node_alloc& node_allocator = node_alloc())
				: _root(0), _size(0), _comp(comp), _node_alloc(node_allocator) {
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

			pointer createNode(const value_type& value) {
				pointer newNod = _node_alloc.allocate(1);
				_node_alloc.construct(newNod, value);
				return newNod;
			}

			void deallocate_node(pointer node) {
				if (!this->_root) {
					deallocate_node(this->_root->_left);
					deallocate_node(this->_root->_right);
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);						
				}
			}
			
			ft::Pair<iterator, bool> insert(const value_type& value) {
				if (!this->_root) {
					this->_root = createNode(value);
					this->_root->_color = 0;
					return ft::make_pair(iterator(this->_root, this->_root, 0), true);
				}
				pointer tmp = this->_root;
				pointer tmp_parent;
				while (tmp) {
					// New node Key is larger than the current -> goRight 
					if (this->_comp(tmp->_value, value)) {
						tmp_parent = tmp;
						tmp = tmp->_right;
					}
					// New node Key is smaller than the current -> goLeft 
					else if (this->_comp(value, tmp->_value)) {
						tmp_parent = tmp;
						tmp = tmp->_left;
					}
					else 
						return ft::make_pair(iterator(tmp, this->_root, 0), false);
				}
				tmp = createNode(value);
				pointer newNode = tmp;
				newNode->_color = RED;
				if (this->_comp(tmp_parent->_value, value)) {
					tmp_parent->_right = newNode;
					newNode->_parent = tmp_parent;
				}
				else {
					tmp_parent->_left = newNode;
					newNode->_parent = tmp_parent;
				}
				// Adjusting color, father exists and it is RED
				while (tmp_parent && tmp_parent->_color == RED) {
					pointer grandParent = tmp_parent->_parent;
					if (grandParent->_left == tmp_parent) {
						pointer uncle = grandParent->_right;
						// Uncle exists and is RED. Father and Uncle are black
						// Ancestor is set to RED. If not, black node of each path will change 
						if (uncle && uncle->_color == RED) {
							tmp_parent->_color = BLACK;
							uncle->_color = BLACK;
							grandParent->_color = RED;
							tmp = grandParent;
							tmp_parent = tmp->_parent;
						}
						// Uncle does not exist or is black
						else {
							if (tmp_parent->_left == tmp) { // Right rotation
								rotateRight(grandParent);
								tmp_parent->_color = BLACK;
								grandParent->_color = RED;
							}
							else {
								rotateLeft(tmp_parent);
								rotateRight(grandParent);
								grandParent->_color = RED;
								tmp->_color = BLACK;
							}
							break;
						}
					}
					// Parent is grandParent left child
					else {
						pointer uncle = grandParent->_left;
						if (uncle && uncle->_color == RED) {
							uncle->_color = BLACK;
							tmp_parent->_color = BLACK;
							grandParent->_color = RED;
							tmp = grandParent;
							tmp_parent = tmp->_parent;
						}
						else {
							if (tmp_parent->_right == tmp) {
								rotateLeft(grandParent);
								tmp_parent->_color = BLACK;
								grandParent->_color = RED;
							}
							else {
								rotateRight(tmp_parent);
								rotateLeft(grandParent);
								tmp->_color = BLACK;
								grandParent->_color = RED;
							}
							break;
						}
					}
				}
				this->_root->_color = BLACK;
				return ft::make_pair(iterator(newNode, this->_root, 0), true);
			}

			void rotateRight(pointer parent) {
				pointer tmpL = parent->_left;
				pointer tmpLR = tmpL->_right;
				pointer tmpParent = parent->_parent;
				parent->_left = tmpLR;
				tmpL->_right = parent;
				// Update parent of two nodes at the same time
				if (tmpLR)
					tmpLR->_parent = parent;
				parent->_parent = tmpL;
				// Parent may be a separete tree
				if (this->_root == parent) {
					this->_root = tmpL;
					this->_root->_parent = 0;
				}
				else {
					// Parent is a left subtree
					if (tmpParent->_left == parent)
						tmpParent->_left = tmpL;
					// Parent is a right subtree
					else
						tmpParent->_right = tmpL;
					// Adjust parent node of tmpParent 
					tmpL->_parent = tmpParent;
				}
			}

			void rotateLeft(pointer parent) {
				pointer tmpR = parent->_right;
				pointer tmpRL = tmpR->_left;
				pointer tmpParent = parent->_parent;
				parent->_left = tmpRL;
				tmpR->_right = parent;
				parent->_parent = tmpR;
				// Update parent of two nodes at the same time
				if (tmpRL)
					tmpRL->_parent = parent;
				parent->_parent = tmpR;
				// Parent may be a separete tree
				if (this->_root == parent) {
					this->_root = tmpR;
					this->_root->_parent = 0;
				}
				else {
					// Parent is a left subtree
					if (tmpParent->_left == parent)
						tmpParent->_left = tmpR;
					// Parent is a right subtree
					else
						tmpParent->_right = tmpR;
					// Adjust parent node of tmpParent 
					tmpR->_parent = tmpParent;
				}
			}

			// key_compare& value_compare() { return this->_root->_data->second; }

	// ITERATORS
			iterator begin() {pointer nil; return iterator(min(), this->_root(), nil); }
			const_iterator begin() const { pointer nil; return const_iterator(min(), this->_root(), nil); }
			
			iterator end() { pointer nil; return iterator(max(), this->_root(), nil); } 
			const_iterator end() const { pointer nil; return const_iterator(max(), this->_root(), nil); } 
			
			reverse_iterator rbegin() { return reverse_iterator(this->end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
			
			reverse_iterator rend() { return reverse_iterator(this->begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
	
	// CAPACITY
			void increment_size() { this->_size++; }

			size_type size() const { return this->_size; }
			
			size_type max_size() const { return std::min<size_type>(node_traits::max_size(this->_node_alloc), std::numeric_limits<difference_type>::max()); }
			
			bool empty() const { pointer nil; return this->_root == nil; }

	// MODIFIERS

			void clear() { 
				if (this->size() > 0) {
					pointer nil;
					deallocate_node(this->_root);
					this->_size = 0;
					this->_root = nil;
				}
			}

	// OPERATIONS 

			pointer min() {
				pointer tmp = this->_root;

				while (this->_root && this->tmp->_left)
					tmp = this->tmp->_left;
				return tmp;
			}
		
			pointer max() {
				pointer tmp = this->_root;

				while (this->_root && this->tmp->_right)
					tmp = this->tmp->_right;
				return tmp;
			}
	};
}