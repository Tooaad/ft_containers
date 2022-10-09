/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:18:57 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/09 20:33:09 by gpernas-         ###   ########.fr       */
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
			~Node() { }

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
				return tmp;
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

		protected:
			node_ptr	_root;

		public:
			TreeIter() : _root(0) {}
			explicit TreeIter(node_ptr root) : _root(root) {}
			explicit TreeIter(node_ptr root, node_ptr nil): _root(root) {
				if (nil) {
					node_ptr last = max(getRoot(root));
					last->_right = nil;
					nil->_parent = last;
				}
			}
			template <class N, class P>
			TreeIter(const TreeIter<N, P>& it) {
				this->_root = it.baseNode();
			}
			~TreeIter() {}

			template <class U, class P>
			TreeIter&	operator=(const TreeIter<U, P>& other) {
				this->_root = other.baseNode();
				return *this;
			}
			pointer base() const { return this; }
			node_ptr baseNode() const { return _root; }
			TreeIter& operator++() {
				if (this->_root->_right)
					this->_root = min(this->_root->_right);
					
				else {
					node_ptr tmp = this->_root;
					node_ptr tmpParent = this->_root->_parent;
					if (!tmpParent->_left && !tmpParent->_parent->_left)
						this->_root->_right->_color = BLACK;
					while (tmpParent && tmp == tmpParent->_right) {
						tmp = tmp->_parent;
						tmpParent = tmpParent->_parent;
					}
					this->_root = tmpParent;
				}

				return *this;
			}
			TreeIter operator++(int) { TreeIter tmp(*this); ++(*this); return tmp; }

			TreeIter& operator--()
			{
				// The next access is the first node in the middle order in the right tree
				if (this->_root->_left)
					this->_root = max(this->_root->_left);
					
				else {
					node_ptr tmp = this->_root;
					node_ptr tmpParent = this->_root->_parent;
					if (!tmpParent->_right && !tmpParent->_parent->_right)
						this->_root->_right->_color = BLACK;
					while (tmpParent && tmp == tmpParent->_left) {
						tmp = tmp->_parent;
						tmpParent = tmpParent->_parent;
					}
					this->_root = tmpParent;
				}
				return *this;
			}

			TreeIter operator--(int) {TreeIter tmp(*this); --(*this); return tmp;}

			node_ptr getRoot(node_ptr n) {
				while (n->_parent)
					n = n->_parent;
				return n;
			}

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
			
			reference operator*() const { return const_cast<reference> (_root->_value); }
			pointer operator->() const { return const_cast<pointer> (&_root->_value); }
			
	};
	
	template <typename U, typename V, typename P1, typename P2>
	bool	operator==(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() == b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator!=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() != b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator>(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() > b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator<(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() < b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator>=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() >= b.baseNode(); }

	template <typename U, typename V, typename P1, typename P2>
	bool	operator<=(const TreeIter<U,P1>& a, const TreeIter<V,P2>& b) { return a.baseNode() <= b.baseNode(); }

}