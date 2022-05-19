/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/19 02:01:08 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "TreeIter.hpp"
#include "../utils/pair.hpp"
#include "allocator_traits.hpp"

namespace ft
{
	template <class Pair, class Compare, class Alloc>
	class RBTree
	{
	public:
		typedef Pair value_type;
		typedef Compare key_compare;
		typedef Alloc allocator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef ft::Node<Pair> node_type;
		typedef typename Alloc::template rebind<node_type>::other node_alloc;
		typedef ft::allocator<node_alloc> node_traits;
		typedef typename node_alloc::pointer pointer;
		typedef typename node_alloc::const_pointer const_pointer;
		typedef typename ft::TreeIter<pointer, Pair> iterator;
		typedef typename ft::TreeIter<const_pointer, Pair> const_iterator;
		typedef typename ft::ReverseIter<iterator> reverse_iterator;
		typedef typename ft::ReverseIter<const_iterator> const_reverse_iterator;

		pointer _root;
		size_type _size;
		key_compare _comp;
		node_alloc _node_alloc;

		explicit RBTree(const key_compare &comp = key_compare(), const node_alloc &node_allocator = node_alloc())
			: _root(0), _size(0), _comp(comp), _node_alloc(node_allocator)
		{
			std::cout << "'2" << std::endl;
		}

		RBTree(const RBTree &otherTree)
		{
			*this = otherTree;
		}

		RBTree &operator=(const RBTree &otherTree)
		{
			// if (this != &otherTree) {
			// 	this->value_compare() = otherTree.value_compare();
			// 	if (this->node_alloc() != otherTree.node_alloc())
			// 		clear();
			// 	this->node_alloc() = otherTree.node_alloc();

			// }

			if (this != &otherTree)
			{
				this->_root = otherTree._root;
				this->_size = otherTree._size;
				this->_node_alloc = otherTree._node_alloc;
				this->_comp = otherTree._comp;
			}

			return *this;
		}

		~RBTree() {}

		pointer createNode(const value_type &value)
		{
			pointer newNod = _node_alloc.allocate(1);
			_node_alloc.construct(newNod, value);
			return newNod;
		}

		void deallocate_node(pointer node)
		{
			if (!this->_root)
			{
				deallocate_node(this->_root->_left);
				deallocate_node(this->_root->_right);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}
		}

		void p_swap(pointer &one, pointer &two) 
		{
			pointer const tmp = one;
			one = two;
			two = tmp;
		}

		ft::Pair<iterator, bool> insert(const value_type &value)
		{
			if (!this->_root) {
				this->_root = createNode(value);
				this->_root->_color = BLACK;
				return ft::make_pair(iterator(this->_root, this->_root, 0), true);
			}
			pointer tmp = this->_root;
			pointer parent;
			while (tmp)
			{
				// New node Key is larger than the current -> go_Right
				if (this->_comp(tmp->_value, value))
				{
					parent = tmp;
					tmp = tmp->_right;
				}
				// New node Key is smaller than the current -> go_Left
				else if (this->_comp(value, tmp->_value))
				{
					parent = tmp;
					tmp = tmp->_left;
				}
				else
					return ft::make_pair(iterator(tmp, this->_root, 0), false);
			}
			tmp = createNode(value);
			pointer newNode = tmp;
			newNode->_color = RED;
			if (this->_comp(parent->_value, value))
			{
				parent->_right = newNode;
				newNode->_parent = parent;
			}
			else
			{
				parent->_left = newNode;
				newNode->_parent = parent;
			}
			// Adjusting color, father exists and it is RED
			while (parent && parent->_color == RED)
			{
				pointer grandParent = parent->_parent;
				if (grandParent->_left == parent)
				{
					pointer uncle = grandParent->_right;
					// Uncle exists and is RED. Father and Uncle are black
					// Ancestor is set to RED. If not, black node of each path will change
					if (uncle && uncle->_color == RED)
					{
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandParent->_color = RED;
						tmp = grandParent;
						parent = tmp->_parent;
					}
					// Uncle does not exist or is black
					else
					{
						if (parent->_right == tmp)
						{ // _Right rotation
							rotate_Left(parent);
							p_swap(parent, tmp);
						}
						rotate_Right(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
				
						break;
					}
				}
				// Parent is grandParent _left child
				else
				{
					pointer uncle = grandParent->_left;
					if (uncle && uncle->_color == RED)
					{
						uncle->_color = BLACK;
						parent->_color = BLACK;
						grandParent->_color = RED;
						tmp = grandParent;
						parent = tmp->_parent;
					}
					else
					{
						if (parent->_left == tmp)
						{
							rotate_Right(parent);
							p_swap(parent, tmp);
						}
						rotate_Left(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
						
						break;
					}
				}
			}
			this->_root->_color = BLACK;
			return ft::make_pair(iterator(newNode, this->_root, 0), true);
		}

		void rotate_Right(pointer parent)
		{
			pointer tmpL = parent->_left;
			pointer tmpLR = tmpL->_right;
			pointer tmpParent = parent->_parent;
			parent->_left = tmpLR;
			// Update parent of two nodes at the same time
			if (tmpLR)
				tmpLR->_parent = parent;
			tmpL->_right = parent;
			parent->_parent = tmpL;
			// Parent may be a separete tree
			if (this->_root == parent)
			{
				this->_root = tmpL;
				this->_root->_parent = 0;
			}
			else
			{
				// Parent is a _left subtree
				if (tmpParent->_left == parent)
					tmpParent->_left = tmpL;
				// Parent is a _right subtree
				else
					tmpParent->_right = tmpL;
				// Adjust parent node of tmpParent
				tmpL->_parent = tmpParent;
			}
		}

		void rotate_Left(pointer parent)
		{
			pointer tmpR = parent->_right;
			pointer tmpRL = tmpR->_left;
			pointer tmpParent = parent->_parent;
			parent->_right = tmpRL;
			// Update parent of two nodes at the same time
			if (tmpRL)
				tmpRL->_parent = parent;
			tmpR->_left = parent;
			parent->_parent = tmpR;
			// Parent may be a separete tree
			if (this->_root == parent)
			{
				this->_root = tmpR;
				this->_root->_parent = 0;
			}
			else
			{
				// Parent is a _left subtree
				if (tmpParent->_left == parent)
					tmpParent->_left = tmpR;
				// Parent is a _right subtree
				else
					tmpParent->_right = tmpR;
				// Adjust parent node of tmpParent
				tmpR->_parent = tmpParent;
			}
		}

		// key_compare& value_compare() { return this->_root->__value->second; }

		// ITERATORS
		iterator begin()
		{
			pointer nil;
			return iterator(min(), this->_root(), nil);
		}
		const_iterator begin() const
		{
			pointer nil;
			return const_iterator(min(), this->_root(), nil);
		}

		iterator end()
		{
			pointer nil;
			return iterator(max(), this->_root(), nil);
		}
		const_iterator end() const
		{
			pointer nil;
			return const_iterator(max(), this->_root(), nil);
		}

		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// CAPACITY
		void increment_size() { this->_size++; }

		size_type size() const { return this->_size; }

		size_type max_size() const { return std::min<size_type>(node_traits::max_size(this->_node_alloc), std::numeric_limits<difference_type>::max()); }

		bool empty() const { return !this->_root; }

		// MODIFIERS

		void clear()
		{
			if (this->size() > 0)
			{
				pointer nil;
				deallocate_node(this->_root);
				this->_size = nil;
				this->_root = nil;
			}
		}

		// OPERATIONS

		pointer min()
		{
			pointer tmp = this->_root;

			while (this->_root && this->tmp->_left)
				tmp = this->tmp->_left;
			return tmp;
		}

		pointer max()
		{
			pointer tmp = this->_root;

			while (this->_root && this->tmp->_right)
				tmp = this->tmp->_right;
			return tmp;
		}
	};
}

// 				void	rotate_Left(pointer node) {
// 	pointer	tmp_Right = node->_right;

// 	node->_right = tmp_Right->_left;
// 	if (tmp_Right->_left != 0)
// 		tmp_Right->_left->_parent = node;
// 	tmp_Right->_parent = node->_parent;
// 	updateChildren(node, tmp_Right);
// 	tmp_Right->_left = node;
// 	node->_parent = tmp_Right;
// }

// void	rotate_Right(pointer node) {
// 	pointer	tmp_Left = node->_left;

// 	node->_left = tmp_Left->_right;
// 	if (tmp_Left->_right != 0)
// 		tmp_Left->_right->_parent = node;
// 	tmp_Left->_parent = node->_parent;
// 	updateChildren(node, tmp_Left);
// 	tmp_Left->_right = node;
// 	node->_parent = tmp_Left;
// }

// void	updateChildren(pointer node, pointer tmp) {
// 	if (node->_parent == 0)
// 		_root = tmp;
// 	else if (node->isLeft())
// 		node->_parent->_left = tmp;
// 	else
// 		node->_parent->_right = tmp;
// }

// void	swapColor(pointer n1, pointer n2) {
// 	bool	tmp;

// 	tmp = n1->_color;
// 	n1->_color = n2->_color;
// 	n2->_color = tmp;
// }

// void	rewire() {
// 	_root->_parent = 0;
// }

// ft::Pair<iterator, bool> insert(const value_type& value) {
// 	if (!this->_root) {
// 		this->_root = createNode(value);
// 		this->_root->_color = BLACK;
// 		return ft::make_pair(iterator(this->_root, this->_root, 0), true);
// 	}
// 	else {
// 		pointer tmp = this->_root;
// 		while (tmp) {
// 			if (_comp(tmp->_value, value)) {
// 				if (tmp->_right == 0)
// 					break ;
// 				tmp = tmp->_right;
// 			}
// 			else if (_comp(value, tmp->_value)) {
// 				if (tmp->_left == 0)
// 					break ;
// 				tmp = tmp->_left;
// 			}
// 			else {
// 				rewire();
// 				return ft::make_pair(iterator(tmp, _root, 0), false);
// 			}
// 		}
// 		if (_comp(tmp->_value, value)) {
// 			tmp->_right = createNode(value);
// 			tmp->_right->_parent = tmp;
// 			tmp = tmp->_right;
// 		}
// 		else if (_comp(value, tmp->_value)) {
// 			tmp->_left = createNode(value);
// 			tmp->_left->_parent = tmp;
// 			tmp = tmp->_left;
// 		}
// 		fixInsert(tmp);
// 		_size++;
// 		rewire();
// 		return ft::make_pair(iterator(tmp, _root, 0), true);
// 	}
// }

// void	fixInsert(pointer node) {
// 	if (node != _root && node->_color == RED && node->_parent->_color == RED) {
// 		if (node->getUncle() && node->getUncle()->_color == RED)
// 			colorCase(node->_parent, node->getUncle(), node->getGrandParent());
// 		else if (node->_parent != _root && node->_parent->isLeft())
// 			_leftCase(node, node->_parent, node->getGrandParent());
// 		else if (node->_parent != _root && node->_parent->isRight())
// 			_rightCase(node, node->_parent, node->getGrandParent());
// 	}
// 	_root->_color = BLACK;
// 	rewire();
// }

// void	colorCase(pointer parent, pointer uncle, pointer grandParent) {
// 	uncle->_color = BLACK;
// 	parent->_color = BLACK;
// 	grandParent->_color = RED;
// 	fixInsert(grandParent);
// }

// void	_leftCase(pointer node, pointer parent, pointer grandParent) {
// 	if (!node->isLeft()) {
// 		rotate_Left(parent);
// 		node = parent;
// 		parent = node->_parent;
// 	}
// 	rotate_Right(grandParent);
// 	swapColor(parent, grandParent);
// 	fixInsert(parent);
// }

// void	_rightCase(pointer node, pointer parent, pointer grandParent) {
// 	if (node->isLeft()) {
// 		rotate_Right(parent);
// 		node = parent;
// 		parent = node->_parent;
// 	}
// 	rotate_Left(grandParent);
// 	swapColor(parent, grandParent);
// 	fixInsert(parent);
// }