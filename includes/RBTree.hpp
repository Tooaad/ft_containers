/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:02:55 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/12 11:55:47 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/TreeIter.hpp"
#include "../utils/pair.hpp"
#include "../utils/utils.hpp"
#include "../includes/ReverseIter.hpp"
#define COUN 4

namespace ft
{
	template <class pair, class Compare, class Alloc>
	class RBTree
	{
	public:
		typedef pair 												value_type;
		typedef Compare 											key_compare;
		typedef Alloc 												allocator;
		typedef size_t 												size_type;
		typedef ptrdiff_t 											difference_type;
		typedef ft::Node<pair>										node_type;
		typedef typename Alloc::template rebind<node_type>::other 	node_alloc;
		typedef std::allocator<node_alloc> 							node_traits;
		typedef typename node_alloc::pointer 						pointer;
		typedef typename node_alloc::const_pointer 					const_pointer;
		typedef typename ft::TreeIter<pointer, pair> 				iterator;
		typedef typename ft::TreeIter<const_pointer, pair>			const_iterator;
		typedef typename ft::ReverseIter<iterator> 					reverse_iterator;
		typedef typename ft::ReverseIter<const_iterator> 			const_reverse_iterator;

	private:
		pointer _root;
		pointer _nil;
		size_type _size;
		key_compare _comp;
		node_alloc _node_alloc;

	public:

		explicit RBTree(const key_compare &comp = key_compare(), const node_alloc &node_allocator = node_alloc())
			: _root(0), _size(0), _comp(comp), _node_alloc(node_allocator)
		{
			_nil = _node_alloc.allocate(1);
			_node_alloc.construct(_nil, value_type());
			_nil->_color = BLACK;
		}

		RBTree(const RBTree &otherTree)
		{
			*this = otherTree;
		}

		RBTree& operator=(const RBTree &otherTree)
		{
			if (this != &otherTree)
			{
				clear();
				if (this->_nil)
					deallocate_node(this->_nil);
				this->_node_alloc = otherTree._node_alloc;
				this->_comp = otherTree._comp;
				this->_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, value_type());
				_nil->_color = BLACK;
				this->_root = 0;
				for (const_iterator it = otherTree.begin(); it != otherTree.end(); it++)
					insert(*it);
			}
			return *this;
		}

		~RBTree() {
			clear();
			if (_nil)
				deallocate_node(_nil);
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

		void deallocate_tree(pointer node) {
			if (node && node != _nil) {
				deallocate_tree(node->_left);
				deallocate_tree(node->_right);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}
		}

		// MODIFIERS
		void clear()
		{
			if (this->size() > 0) {
				deallocate_tree(this->_root);
				this->_size = 0;
			}
			this->_root = NULL;
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			if (!this->_root)
			{
				this->_root = createNode(value);
				this->_root->_color = BLACK;
				this->_size++;
				return ft::make_pair(iterator(this->_root, _nil), true);
			}	
			pointer tmp = this->_root;
			while (tmp && tmp->_right)
				tmp = tmp->_right;
			delNil(tmp->_parent->_right);
			delNil(tmp);
			
			tmp = this->_root;
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
				// If a Key already exists returns the oldest one
				else
				{
					return ft::make_pair(iterator(tmp, _nil), false);
				}
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
			this->_size++;
			return ft::make_pair(iterator(newNode, _nil), true);
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

		void delNil(pointer& node) {
			if (node && node != _nil)
				return ;
			node = NULL;
		}

		void deleteFix(pointer &nodeToRemove)
		{
			pointer nodeAux;
			while (nodeToRemove != this->_root && nodeToRemove->_color == BLACK)
			{
				if (nodeToRemove->isLeft())
				{
					nodeAux = nodeToRemove->_parent->_right;
					if (nodeAux->_color == RED)
					{
						nodeAux->_color = BLACK;
						nodeToRemove->_parent->_color = RED;

						rotateLeft(nodeToRemove->_parent);
						nodeAux = nodeToRemove->_parent->_right;
					}
					if (setNil(nodeAux->_left) && setNil(nodeAux->_right)
						&& nodeAux->_left->_color == BLACK && nodeAux->_right->_color == BLACK)
					{
						nodeAux->_color = RED;
						delNil(nodeAux->_left);
						delNil(nodeAux->_right);
						delNil(nodeAux->_parent->_left);
						nodeToRemove = nodeToRemove->_parent;
					}
					else
					{
						delNil(nodeAux->_left);
						delNil(nodeAux->_right);
						if (setNil(nodeAux->_right) && nodeAux->_right->_color == BLACK)
						{
							nodeAux->_left->_color = BLACK;
							nodeAux->_color = RED;

							rotateRight(nodeAux);
							nodeAux = nodeToRemove->_parent->_right;
						}
						nodeAux->_color = nodeToRemove->_parent->_color;
						nodeToRemove->_parent->_color = BLACK;
						nodeAux->_right->_color = BLACK;
						delNil(nodeAux->_right->_right);
						delNil(nodeToRemove->_parent->_left);
						delNil(nodeAux->_left);
						rotateLeft(nodeToRemove->_parent);
						nodeToRemove = this->_root;
					}
				}
				else 
				{
					nodeAux = nodeToRemove->_parent->_left;
					if (nodeAux->_color == RED)
					{
						nodeAux->_color = BLACK;
						nodeToRemove->_parent->_color = RED;

						rotateRight(nodeToRemove->_parent);
						nodeAux = nodeToRemove->_parent->_left;
					}
					if (setNil(nodeAux->_left) && setNil(nodeAux->_right) &&
						nodeAux->_left->_color == BLACK && nodeAux->_right->_color == BLACK)
					{
						nodeAux->_color = RED;
						delNil(nodeAux->_left);
						delNil(nodeAux->_right);
						delNil(nodeAux->_parent->_right);
						nodeToRemove = nodeToRemove->_parent;
					}
					else
					{
						delNil(nodeAux->_left);
						delNil(nodeAux->_right);
						if (setNil(nodeAux->_left) && nodeAux->_left->_color == BLACK)
						{
							nodeAux->_right->_color = BLACK;
							nodeAux->_color = RED;

							rotateLeft(nodeAux);
							nodeAux = nodeToRemove->_parent->_left;
						}
						nodeAux->_color = nodeToRemove->_parent->_color;
						nodeToRemove->_parent->_color = BLACK;
						nodeAux->_left->_color = BLACK;
						delNil(nodeAux->_left->_left);
						delNil(nodeToRemove->_parent->_right);
						delNil(nodeAux->_right);
						rotateRight(nodeToRemove->_parent);
						nodeToRemove = this->_root;
					}
				}
			}
			nodeToRemove->_color = BLACK;
		}

		void erase(pointer& nodeToRemove)
			{
				pointer tmp = this->_root;
				while (tmp && tmp->_right)
					tmp = tmp->_right;
				delNil(tmp->_parent->_right);
				delNil(tmp);
				//-----
				pointer nodeAux, copyRemove, nilAux;
				nilAux = _node_alloc.allocate(1);
				_node_alloc.construct(nilAux, value_type());
				nilAux->_color = BLACK;
				copyRemove = nodeToRemove;
				int copy_color = copyRemove->_color;
				if (!nodeToRemove->_left)
				{
					if (!nodeToRemove->_right) {
						nodeAux = nilAux;
					}
					else
						nodeAux = nodeToRemove->_right;
					nodeTransplant(nodeToRemove, nodeAux);
				}
				else if (!nodeToRemove->_right)
				{
					if (!nodeToRemove->_left) {
						nodeAux = nilAux;
					}
					else
						nodeAux = nodeToRemove->_left;
					nodeTransplant(nodeToRemove, nodeAux); 
				}
				else
				{
					copyRemove = nodeToRemove->subMin();
					copy_color = copyRemove->_color;
					if (!copyRemove->_right) {
						copyRemove->_right = nilAux;
					}
					nodeAux = copyRemove->_right;
					if (copyRemove->_parent == nodeToRemove) {
						nodeAux->_parent = copyRemove;
					}
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
				}
				this->_size--;
				_node_alloc.destroy(nodeToRemove);
				_node_alloc.deallocate(nodeToRemove, 1);
				ft::swap(this->_nil, nilAux);
				if (copy_color == BLACK)
					deleteFix(nodeAux);
				else
				{
					if (nodeAux->_parent->_left == nodeAux)
						nodeAux->_parent->_left = NULL;
					if (nodeAux->_parent->_right == nodeAux)
						nodeAux->_parent->_right = NULL;
				}
				ft::swap(_nil, nilAux);
				_node_alloc.destroy(nilAux);
				_node_alloc.deallocate(nilAux, 1);
				if (this->_size > 0)
					iterator(this->_root, _nil);
				else
					this->_root = NULL;
			}

			// ITERATORS
			iterator begin() { if (!this->_root) return iterator(_nil); return iterator(min()); }
			const_iterator begin() const { if (!this->_root) return iterator(_nil); return const_iterator(min()); }

			iterator end() { return iterator(_nil); }
			const_iterator end() const { return const_iterator(_nil); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			// CAPACITY
			
			size_type size() const { return this->_size; }

			size_type max_size() const { return _node_alloc().max_size(); }

			bool empty() const { return !this->_root; }

			// OPERATIONS
			// map->Tree->Iter->Node->pair

			template <class K>
			ft::pair<pointer, bool> find(const K &value)
			{
				pointer tmp = this->_root;
				while (tmp)
				{
					if (tmp->_value.first < value)
						tmp = tmp->_right;
					else if (value < tmp->_value.first)
						tmp = tmp->_left;
					else
						return ft::make_pair(tmp, true);
				}
				return ft::make_pair(end().baseNode(), false);
			}
			
			template <class K>
			ft::pair<pointer, bool> find(const K &value) const
			{
				pointer tmp = this->_root;
				while (tmp)
				{
					if (tmp->_value.first < value)
						tmp = tmp->_right;
					else if (value < tmp->_value.first)
						tmp = tmp->_left;
					else
						return ft::make_pair(tmp, true);
				}
				return ft::make_pair(_nil, false);
			}

			void swap(RBTree& otherTree) {
				ft::swap(_root, otherTree._root);
				ft::swap(_size, otherTree._size);
				ft::swap(_nil, otherTree._nil);
				ft::swap(_node_alloc, otherTree._node_alloc);
				ft::swap(_comp, otherTree._comp);
			}


			pointer min() const
			{
				pointer tmp = this->_root;

				while (this->_root && tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}

			pointer max() const
			{
				pointer tmp = this->_root;

				while (this->_root && tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}

			pointer getTreeRoot() const {
				return this->_root;
			}

			void print2DUtil(pointer root, int space)
			{
				// Base case
				if (root == NULL)
					return;

				// Increase distance between levels
				space += COUN;

				// Process right child first
				print2DUtil(root->_right, space);

				// Print current node after space
				// coun
				std::cout << std::endl;
				for (int i = COUN; i < space; i++)
					std::cout << " ";
				std::cout << root->_value.first;
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
				// Pass initial space coun as 0
				print2DUtil(root, 0);
			}
		};
	}
