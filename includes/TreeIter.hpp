/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:18:57 by gpernas-          #+#    #+#             */
/*   Updated: 2022/09/16 20:06:24 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/iterator_traits.hpp"

static const int BLACK = 0;
static const int RED = 1;

namespace ft {
template <class T>
	class Node {

		public:
			Node*	_right;
			Node*	_left; 
			Node*	_parent;
			T		_value;
			bool	_color;
			
			// Prueba
			Node() {}
			Node(const T& val) : _right(0), _left(0), _parent(0), _value(val), _color(RED) {}
			Node(const Node& otherNode) : _right(otherNode._right), _left(otherNode._right), _parent(otherNode._parent), _color(otherNode._color) {}
			Node& operator=(const Node& otherNode) {
				if (this != &otherNode) {
					this->_right = otherNode._right;
					this->_left = otherNode._left;
					this->_parent = otherNode._parent;
					this->_value = otherNode._value;
					this->_color = otherNode._color;
				}
				return *this;
			}
			~Node() {}

			Node* subMax()
			{
				Node* tmp = this->_left;
				while (tmp->_right)
					tmp = tmp->_right;
				tmp->_parent->_right = NULL;
				return tmp;
			}
			
			Node* subMin()
			{
				Node* tmp = this->_right;
				while (tmp->_left)
					tmp = tmp->_left;
				// tmp->_parent->_left = NULL;
				return tmp;
			}

			// void rewire(Node* node) // this = 38 || node = 30
			// {
			// 	this->_right = node->_right;
			// 	this->_left = node->_left;
			// 	this->_parent = node->_parent;
			// 	node->_parent->_right = this;
			// 	node->_right->_parent = this;
			// 	node->_left->_parent = this;  
			// 	node->_right = NULL;
			// 	node->_left = NULL;
			// }

			void leftRotate(Node* _root) {
				Node* nodeAux = this->_right;
				this->_right = nodeAux->_left;
				if (nodeAux->_left != NULL)
					nodeAux->_left->_parent = this;
				nodeAux->_parent = this->_parent;
				if (!this->_parent)
					_root = nodeAux;
				else if (this == this->_parent->_left)
					this->_parent->_left = nodeAux;
				else
					this->_parent->_right = nodeAux;
				nodeAux->_left = this;
				this->_parent = nodeAux;		
			}

			void rightRotate(Node* _root) {
				Node* nodeAux = this->_left;
				this->_left = nodeAux->_right;
				if (nodeAux->_right != NULL)
					nodeAux->_right->_parent = this;
				nodeAux->_parent = this->_parent;
				if (!this->_parent)
					_root = nodeAux;
				else if (this == this->_parent->_right)
					this->_parent->_right = nodeAux;
				else
					this->_parent->_left = nodeAux;
				nodeAux->_right = this;
				this->_parent = nodeAux;		
			}
			bool	isLeft() {
				if (this->_parent && this->_parent->_left)
					return this->_parent->_left == this;
				return false;
			}

			bool	isRight() {
				if (this->_parent && this->_parent->_right)
					return this->_parent->_right == this;
				return false;
			}
	};

	
template <class Node, class pair >
	class TreeIter {
		public:
			typedef pair												value_type;
			typedef value_type*											pointer;
			typedef value_type&											reference;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			typedef typename ft::iterator_traits<Node>::value_type		node;
			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
			typedef typename ft::iterator_traits<Node>::pointer			node_ptr;
			typedef typename ft::iterator_traits<Node>::reference		reference_ptr;

		// protected:
			node_ptr	_root;
			// node_ptr	_nil;
		public:
			TreeIter() : _root(0) {}
			explicit TreeIter(node_ptr root) : _root(root) {}
			explicit TreeIter(node_ptr root, node_ptr nil): _root(root) {
				if (nil) {
					node_ptr last = max(_root);
					last->_right = nil;
					nil->_parent = last;
				}
			}
			template <class N, class P>
			TreeIter(const TreeIter<N, P>& it) {
				this->_root = it._root;
				// this->_nil = it._nil;
			}
			~TreeIter() {}

			template <class U, class P>
			TreeIter&	operator=(const TreeIter<U, P>& other) {
				this->_root = other._root;
				// this->_nil = other._nil;
				return *this;
			}
			pointer base() const { return this; }
			node_ptr baseNode() const { return _root; }
			TreeIter& operator++() {
				if (this->_root->_right) {
					node_ptr tmp = this->_root->_right;
					tmp = min(tmp);
					// std::cout << "\n" << tmp->_value._first << std::endl;
					this->_root = tmp;
				}
				else {
					node_ptr tmp = this->_root;
					node_ptr tmpParent = this->_root->_parent;
					while (tmpParent && tmp == tmpParent->_right) {
						tmp = tmp->_parent;
						tmpParent = tmpParent->_parent;
					}
					this->_root = tmpParent;
				}
				return *this;
			}
			TreeIter operator++(int) { TreeIter tmp(*this); ++(*this); return tmp; }
/*
			TreeIter& operator--() { 
				if (this->_node->_parent->_parent == this->_node && this->_node->color == 1)
					this->_node = this->_node->_left;
					
				else if (this->_node->_left) { 
					this->_node = max(this->tmp);
				}
				else {
					node_ptr tmp_parent = this->_node->parent;
					while (tmp_parent->_left == this->_node) {
						this->_node = tmp_parent->_parent;
						tmp_parent = tmp_parent->_parent;
					} 
					this->_node = tmp_parent;
				}			
				return *this;
			}  
			TreeIter operator--(int) { TreeIter tmp(*this); --(*this); return tmp; }
*/
			
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
			
			reference operator*() const { return const_cast<reference
			>(_root->_value); }
			pointer operator->() const { return &_root->_value; }
			
	};
	
	template <typename U, typename V, typename P1, typename P2>
	bool	operator==(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() == b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator!=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() != b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool		operator>(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() > b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool		operator<(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() < b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool		operator>=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() >= b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool		operator<=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() <= b.baseNode(); }

	// template <typename U, typename V, typename P1, typename P2>
	// ptrdiff_t		operator-(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) {
	// 	return a.baseNode() - b.baseNode();
	// }

	// template <typename U, typename P1>
	// TreeIter<U,P1>		operator+(typename TreeIter<U,P1>::difference_type n, const TreeIter<U,P1>& b) {
	// 	return (TreeIter<U,P1>)(b.baseNode() + n);
	// }

}