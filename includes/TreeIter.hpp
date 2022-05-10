/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:18:57 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/09 18:51:04 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"


namespace ft {
template <class T>
	class Node {

		public:
			Node*	_right;
			Node*	_left; 
			Node*	_parent;
			T		_value;
			bool	_color;
			// 0 = Black, 1 = Red
			
			// Prueba
			Node() {}
			Node(const T& val) : _right(0), _left(0), _parent(0), _value(val), _color(1) {}
			Node& operator=(const Node& otherNode) {
				std::cout << "Node" << std::endl;
				this->_right = otherNode._right;
				this->_left = otherNode._left;
				this->_parent = otherNode._parent;
				this->_value = otherNode._value;
				this->_color = otherNode._color;
			}
			~Node() {}
	};

	
template <class Node, class Pair >
	class TreeIter {
		public:
			typedef Pair												value_type;
			typedef value_type*											pointer;
			typedef value_type&											reference;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			typedef typename ft::iterator_traits<Node>::value_type		node;
			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
			typedef typename ft::iterator_traits<Node>::pointer			node_ptr;
			typedef typename ft::iterator_traits<Node>::reference		reference_ptr;
			
			TreeIter() : _node(), _root(), _nil()  {}
			explicit TreeIter(node_ptr node, node_ptr root, node_ptr nil) : _node(node), _root(root), _nil(nil) {}
			template <class N, class P>
			TreeIter(TreeIter<N, P> it) {
				this->_node = it._node;
				this->_root = it._root;
				this->_nil = it._nil;
			}
			~TreeIter() {}

			template <class U, class P>
			TreeIter&	operator=(const TreeIter<U, P>& other) {
				this->_node = other._node;
				this->_root = other._root;
				this->_nil = other._nil;
				return *this;
			}

			reference operator*() const { return this->_node->_data; }
			pointer operator->() const { return &this->_node->_data; }

			TreeIter& operator++() { 
				if (this->_node->_right) {
					node_ptr* tmp = this->_node->right;
					tmp = min(this->tmp);
					this->_node = tmp;
				}
				else {
					Node* tmp = this->_parent;
					if (tmp->right == this->_node) {	
						while (this->_node == tmp->_right) {
							this->_node = tmp;
							tmp = tmp->_parent;
						} 
					}
					if (this->_node->right != tmp)
						this->_node = tmp;

				}			
				return *this;
			}
			TreeIter operator++(int) { TreeIter tmp(*this); ++(*this); return tmp; }
			TreeIter& operator--() { 
				if (this->_node->_parent->_parent == this->_node && this->_node->color == 1)
					this->_node = this->_node->_left;
					
				else if (this->_node->_left) { 
					this->_node = max(this->tmp);
				}
				else {
					Node* tmp_parent = this->_node->parent;
					while (tmp_parent->_left == this->_node) {
						this->_node = tmp_parent->_parent;
						tmp_parent = tmp_parent->_parent;
					} 
					this->_node = tmp_parent;
				}			
				return *this;
			}  
			TreeIter operator--(int) { TreeIter tmp(*this); --(*this); return tmp; }
			node_ptr min(node_ptr n) {
				while (n->_left)
					n = n->_left;
				return n;
			}

			node_ptr max(node_ptr n) {
				while (n->_right)
					n = n->_right;
				return n;
			}

		private:
			node_ptr	_node;
			node_ptr	_root;
			node_ptr	_nil;
			
	};
	
	// template <class A, class B>
	// bool operator==(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() == b.base(); }
			
	// template <class A, class B>
	// bool operator!=(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() != b.base(); }
			
	// template <class A, class B>
	// bool operator<(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() < b.base(); }
		
	// template <class A, class B>
	// bool operator>(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() > b.base(); }
			
	// template <class A, class B>
	// bool operator<=(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() <= b.base(); }
			
	// template <class A, class B>
	// bool operator>=(const TreeIter<A>& a, const TreeIter<B>& b) { return a.base() >= b.base(); }    

}