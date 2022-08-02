/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/08/02 13:28:54 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TREEITER NOW HAS 2 PARAMS some iterators have 3

#pragma once

#include "TreeIter.hpp"
#include "../utils/pair.hpp"
#include "allocator_traits.hpp"
#define COUNT 4

namespace ft
{
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

	// private:
		pointer		_root;
		size_type	_size;
		key_compare	_comp;
		node_alloc	_node_alloc;

	// public:

		explicit RBTree(const key_compare &comp = key_compare(), const node_alloc &node_allocator = node_alloc())
			: _root(0), _size(0), _comp(comp), _node_alloc(node_allocator)
		{
			std::cout << "A Tree has been successfully created" << std::endl;
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
			if (this->_root != node)
			{
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}
		}

		ft::Pair<iterator, bool> insert(const value_type &value)
		{
			if (!this->_root) {
				this->_root = createNode(value);
				this->_root->_color = BLACK;
				return ft::make_pair(iterator(this->_root), true);
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
				// else
				// 	return ft::make_pair(iterator(tmp, this->_root, 0), false);
			}
			tmp = createNode(value);
			pointer newNode = tmp;
			newNode->_color = RED;
	// From here functions should be divide as different movements
	// nodes have been moved 
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
	// Decides where to put the node on the last leaf, left or right
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
							ft::swap(parent, tmp);
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
							ft::swap(parent, tmp);
						}
						rotate_Left(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
						
						break;
					}
				}
			}
			this->_root->_color = BLACK;
			return ft::make_pair(iterator(this->_root), true);
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

		void nodeTransplant(pointer nodeToRemove, pointer nodeToTransplant) {
			if (nodeToRemove->_parent == NULL)
				_root = nodeToTransplant;
			else if (nodeToRemove->_parent->_left && nodeToRemove->_parent->_left == nodeToRemove->_left)
				nodeToRemove->_parent->_left = nodeToTransplant;
			else
				nodeToRemove->_parent->_right = nodeToTransplant;
			nodeToTransplant->_parent = nodeToRemove->_parent;
		}

		void erase(pointer &nodeToRemove) {
			// pointer nil = NULL;
			if (nodeToRemove->_color == RED) {
				pointer subMinNode = nodeToRemove->subMin();
				subMinNode->rewire(nodeToRemove);
				deallocate_node(nodeToRemove);	
				
				// if (!nodeToRemove->_right || !nodeToRemove->_left) {
				// 	std::cout << "Erase last Red node" << std::endl;
				// 	nodeTransplant(nodeToRemove, nil);
				// }
			}
		}

		// ITERATORS
		iterator begin() { return iterator(min()); }
		const_iterator begin() const { return const_iterator(min()); }

		iterator end() { return iterator(max()); }
		const_iterator end() const { return const_iterator(max()); }

		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// CAPACITY
		void increment_size() { this->_size++; }
		
		void decrement_size() { this->_size--; }

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
		// Map->Tree->Iter->Node->Pair

		template <class K>
		pointer find(const K& value) {
			pointer tmp = this->_root;
			while (tmp) {
				if (tmp->_value._first < value)
					tmp = tmp->_right;
				else if (value < tmp->_value._first)
					tmp = tmp->_left;
				else
					return tmp;
			}
			std::cout << "not found" << std::endl;
			return NULL;
		}

		pointer min()
		{
			pointer tmp = this->_root;

			while (this->_root && tmp->_left)
				tmp = tmp->_left;
			return tmp;
		}

		pointer max()
		{
			pointer tmp = this->_root;

			while (this->_root && tmp->_right)
				tmp = tmp->_right;
			return tmp;
		}

			void print2DUtil(pointer root, int space)
			{
				// Base case
				if (root == NULL)
					return;
			
				// Increase distance between levels
				space += COUNT;
			
				// Process right child first
				print2DUtil(root->_right, space);
			
				// Print current node after space
				// count
				std::cout<<std::endl;
				for (int i = COUNT; i < space; i++)
					std::cout<<" ";
				std::cout<<root->_value._second<<"\n";
			
				// Process left child
				print2DUtil(root->_left, space);
			}
			
			// Wrapper over print2DUtil()
			void print2D(pointer root)
			{
				// Pass initial space count as 0
				print2DUtil(root, 0);
			}
		
	};
}
