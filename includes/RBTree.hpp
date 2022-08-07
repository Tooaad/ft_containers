/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/08/07 14:06:21 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TREEITER NOW HAS 2 PARAMS some iterators have 3

#pragma once

#include "../includes/TreeIter.hpp"
#include "../utils/pair.hpp"
#include "allocator_traits.hpp"
#define COUNT 4

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

		// private:
		pointer _root;
		pointer _nil;
		size_type _size;
		key_compare _comp;
		node_alloc _node_alloc;

		// public:

		explicit RBTree(const key_compare &comp = key_compare(), const node_alloc &node_allocator = node_alloc())
			: _size(0), _comp(comp), _node_alloc(node_allocator)
		{
			std::cout << "A Tree has been successfully created" << std::endl;
			_nil = _node_alloc.allocate(1);
			_node_alloc.construct(_nil, value_type());
			_nil->_color = BLACK;
			// _nil->_parent = _nil;
			// _root = _nil;
			// _nil->_left = _root;
			// _nil->_right = _root;
			// _root->_parent = _nil;
			std::cout << "---" << _nil << std::endl;
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

		~RBTree() {
			// deallocate_node(_nil);
		}

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
			if (!this->_root)
			{
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
							rotateLeft(parent);
							ft::swap(parent, tmp);
						}
						rotateRight(grandParent);
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
							rotateRight(parent);
							ft::swap(parent, tmp);
						}
						rotateLeft(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
						break;
					}
				}
			}
			this->_root->_color = BLACK;
			return ft::make_pair(iterator(this->_root), true);
		}

		void rotateRight(pointer parent)
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

		void rotateLeft(pointer parent)
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

		void nodeTransplant(pointer nodeToRemove, pointer nodeToTransplant)
		{
			std::cout << "----------------" << std::endl;
			if (!nodeToRemove->_parent)
				_root = nodeToTransplant;
			else if (nodeToRemove->isLeft())
				nodeToRemove->_parent->_left = nodeToTransplant;
			else
				nodeToRemove->_parent->_right = nodeToTransplant;
			nodeToTransplant->_parent = nodeToRemove->_parent;
		}

		bool setNil(pointer& node) {
			if (node)
				return true;
			node = _nil;
			return true;
		}

		void deleteFix(pointer &nodeToRemove)
		{
			pointer nodeAux;
			
			while (nodeToRemove != this->_root && nodeToRemove->_color == BLACK)
			{
				
				std::cout << "++++++" <<  nodeToRemove->_parent->_value._first << std::endl;
				if (nodeToRemove->isLeft())
				{
					nodeAux = nodeToRemove->_parent->_right;
					if (nodeAux->_color == RED)
					{
						nodeAux->_color = BLACK;
						nodeToRemove->_parent->_color = RED;
						//----
							
						//----
						rotateLeft(nodeToRemove->_parent);
						nodeAux = nodeToRemove->_parent->_right;
					}
					if (nodeAux->_left->_color == BLACK && nodeAux->_right->_color == BLACK)
					{
						nodeAux->_color = RED;
						//----
							
						//----
						nodeToRemove = nodeToRemove->_parent;
					}
					else
					{
						if (setNil(nodeAux->_right) && nodeAux->_right->_color == BLACK)
						{
							nodeAux->_left->_color = BLACK;
							nodeAux->_color = RED;
							//----
							
							//----
							nodeAux->rightRotate(this->_root);
							
							nodeAux = nodeToRemove->_parent->_right;
						}
						nodeAux->_color = nodeToRemove->_parent->_color;
						nodeToRemove->_parent->_color = BLACK;
						nodeAux->_right->_color = BLACK;
					//----
						nodeAux->_right->_right = NULL;
						nodeToRemove->_parent->_left = NULL;
					//----
						rotateLeft(nodeAux->_parent);
						nodeToRemove = this->_root;
					}
				}
				else 
				{
					nodeAux = nodeToRemove->_parent->_left;
					if (nodeAux->_color == 1)
					{
						nodeAux->_color = 0;
						nodeToRemove->_parent->_color = 1;
					//----
							
					//----
						rotateRight(nodeToRemove->_parent);
						nodeAux = nodeToRemove->_parent->_left;
					}
					if (nodeAux->_left->_color == 0 && nodeAux->_right->_color == 0)
					{
						nodeAux->_color = 1;
						//----
						
						//----
						nodeToRemove = nodeToRemove->_parent;
					}
					else
					{
						if (setNil(nodeAux->_left) && nodeAux->_left->_color == 0)
						{
							nodeAux->_right->_color = 0;
							nodeAux->_color = 1;
						//----
							
						//----
							rotateLeft(nodeAux->_parent);
							nodeAux = nodeToRemove->_parent->_left;
						}
						nodeAux->_color = nodeToRemove->_parent->_color;
						nodeToRemove->_parent->_color = 0;
						nodeAux->_left->_color = 0;
					//----
						nodeAux->_left->_left = NULL;
						nodeToRemove->_parent->_right = NULL;
					//----
						rotateRight(nodeAux->_parent);
						nodeToRemove = this->_root;
					}
				}
			}
			nodeToRemove->_color = 0;
		}

			void erase(pointer & nodeToRemove)
			{
				pointer nodeAux, copyRemove;
				copyRemove = nodeToRemove;
				int copy_color = copyRemove->_color;
				if (!nodeToRemove->_left)
				{
					if (!nodeToRemove->_right) {
						nodeAux = _nil;
						std::cout << "<" << std::endl;
						nodeAux->_parent = nodeToRemove->_parent;
						nodeToRemove->_parent->_left = nodeAux;
						// nodeToRemove->_parent->_right = nodeAux;
					}
					else {
						nodeAux = nodeToRemove->_right;
						nodeTransplant(nodeToRemove, nodeToRemove->_right);
					}
					std::cout << "1:" << std::endl;
				}
				else if (!nodeToRemove->_right)
				{
					if (!nodeToRemove->_left) {
						nodeAux = _nil;
						std::cout << "<" << std::endl;
						nodeAux->_parent = nodeToRemove->_parent;
						nodeToRemove->_parent->_right = nodeAux;
						// nodeToRemove->_parent->_left = nodeAux;
					}
					else {
						nodeAux = nodeToRemove->_left;
						nodeTransplant(nodeToRemove, nodeToRemove->_left);
					}
					std::cout << "2:" << std::endl;
				}
				else
				{
					copyRemove = nodeToRemove->subMin();
					copy_color = copyRemove->_color;
					copyRemove->_right = _nil;
					nodeAux = copyRemove->_right;
					
					if (copyRemove->_parent == nodeToRemove)
						nodeAux->_parent = copyRemove;
					else
					{
						nodeTransplant(copyRemove, copyRemove->_right);
						copyRemove->_right = nodeToRemove->_right;
						copyRemove->_right->_parent = copyRemove;
					}
					nodeTransplant(nodeToRemove, copyRemove);
					copyRemove->_left = nodeToRemove->_left;
					copyRemove->_left->_parent = copyRemove;
					copyRemove->_color = nodeToRemove->_color;
					// copyRemove->_right = NULL;
				}
				deallocate_node(nodeToRemove);
				if (copy_color == BLACK)
					deleteFix(nodeAux);
			//----
				else {
					if (nodeAux->isLeft())
						nodeAux->_parent->_left = NULL;
					else
						nodeAux->_parent->_right = NULL;
				}
			//----
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
			pointer find(const K &value)
			{
				pointer tmp = this->_root;
				while (tmp)
				{
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
				std::cout << std::endl;
				for (int i = COUNT; i < space; i++)
					std::cout << " ";
				std::cout << root->_value._second;
				if (root->_color == 0)
					std::cout << "-N" << "\n";
				else 
					std::cout << "-R" << "\n";

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
