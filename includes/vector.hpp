#pragma once

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "VectorIter.hpp"
#include "ReverseIter.hpp"
#include "../utils/utils.hpp"

namespace ft {
template <class T, class Allocator = std::allocator<T> >
	class Vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef typename ft::VectorIter<pointer>			iterator;
			typedef typename ft::VectorIter<const_pointer>		const_iterator;
			typedef typename ft::ReverseIter<iterator>			reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>	const_reverse_iterator;
			typedef typename Allocator::difference_type			difference_type;
			typedef typename Allocator::size_type				size_type;

		private:
			T*				_data;
			size_type		_size;
			size_type		_capacity;
			Allocator		_alloc;
		
		public:

			explicit Vector(const allocator_type& alloc = allocator_type())
				: _data(0), _size(0), _capacity(0), _alloc(alloc) {
				// this->_data = this->_alloc.allocate(_capacity);
				}

			// SegFault si intentas iniciar con 0
			explicit Vector(size_type n, const value_type& value, const allocator_type& alloc = allocator_type())
				: _size(n), _capacity(n), _alloc(alloc) {
					this->_data = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						this->_alloc.construct(&this->_data[i], value);
				}
			
			template <class InputIterator>
				Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				: _alloc(alloc) {
					size_type n;
					
					for (InputIterator it = first; it < last; it++)
						n++;
					this->_data = _alloc.allocate(n);
					this->_capacity = n;
					for (InputIterator it = first; it != last; it++)
						push_back(*it);
				}
			
			Vector(const Vector& otherVector) {
				this->_size = otherVector._size;
				this->_capacity = otherVector._capacity;
				this->_alloc = otherVector._alloc;
				this->_data = _alloc.allocate(_capacity);

				for (iterator it = otherVector.begin(); it < otherVector.end(); it++)
					push_back(*it);
			}

			~Vector() {
				this->_alloc.destroy(this->_data);
				this->_alloc.deallocate(this->_data, this->_capacity);
			}

			Vector&	operator=(const Vector& otherVector) {
				// clear();
				if (otherVector._size > this->_capacity)
					this->_capacity = otherVector._capacity;

				this->_size = otherVector._size;
				this->_data = _alloc.allocate(_capacity);

				for (size_type i = 0; i < otherVector.size(); i++)
					this->_alloc.construct(&this->_data[i], otherVector._data[i]);
				return *this;
			}

	//		ITERATORS

			iterator begin() { return iterator(this->_data); }
			const_iterator begin() const { return const_iterator(this->_data); }
			iterator end() { return iterator(this->_data + this->_size); } 
			const_iterator end() const { return const_iterator(this->_data + this->_size); } 
			reverse_iterator rbegin() { return reverse_iterator(this->_data + this->_size); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_data + this->_size); }
			reverse_iterator rend() { return reverse_iterator(this->_data); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->_data); } 

	//		CAPACITY	

			size_type size() const {
				return this->_size;
			}

			size_type max_size() const {
				return this->_alloc.max_size();
			}

			void resize(size_type n, value_type val = value_type()) {	
				if (n > this->size()) {
					size_type oldCapacity = this->_capacity;
					pointer newData;
					
					reserve(n);
					// std::cout << this->size() << "-" << this->capacity() << "\n";
					newData = this->_alloc.allocate(this->capacity());
					for (size_type i = 0; i < this->size(); i++)
						this->_alloc.construct(&newData[i], this->_data[i]);

					while (this->size() > this->capacity())
						push_back(val);
					this->_alloc.deallocate(this->_data, oldCapacity);
					this->_data = newData;
				}
				else if (n < this->size())
					while (this->size() < this->capacity())
						pop_back();
			}

			size_type capacity() const {
				return this->_capacity;
			}

			bool empty() const {
				return (this->begin() == this->end());
			}

			void reserve(size_type n) {
				if (n < 32)
					n *= 2;
				if (n > this->max_size())
					throw std::length_error("Trying to allocate more than the allowed max_size");
				if (n > this->capacity())
					this->_capacity = n;
			}

	//		ELEMENT ACCESS
			reference operator[](size_type n) { return this->_data[n]; }
			const_reference operator[](size_type n) const { return this->_data[n]; }
			reference at(size_type n) {
				if (!this->_data[n])
					throw std::out_of_range("Index out of range");
				return  this->_data[n];
			}
			const_reference at(size_type n) const {
				if (!this->_data[n])
					throw std::out_of_range("Index out of range");
				return  this->_data[n];
			}
			reference front() {	return this->_data[0]; }
			const_reference front() const { return this->_data[0]; }
			reference back() { return this->_data[this->size() - 1]; }
			const_reference back() const { return this->_data[this->size() - 1]; }

	//		MODIFIERS

			template <class InputIterator>
				void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
					size_type n = 0;
					for (InputIterator it = first; it < last; it++)
						n++;
					clear();
					if (n > this->capacity())
						resize(n);
					for (InputIterator it = first; it < last; it++)
						push_back(*it);
			}

			void assign(size_type n, const value_type& value) {
				clear();
				if (n > this->capacity())
					resize(n);
				for (size_type i = 0; i < n; i++)
					push_back(value);
			}

			void push_back(const value_type& val) {
				// std::cout << this->size() << "." << this->capacity() << "\n";
				if (this->size() == this->capacity())
					resize(this->size() + 1, val);
				this->_alloc.construct(&this->_data[this->size()], val);
				this->_size++;

			}

			void pop_back() {
				this->_size--;
				this->_alloc.destroy(&this->_data[this->size()]);
			}

			iterator insert(iterator position, const value_type& val) {
				if (position == this->end())
				{
					push_back(val);
					return position;
				}
				ft::Vector<T> newVector;

				reserve(this->capacity() + 1);
				for (iterator it = this->begin(); it < position; it++)
					newVector.push_back(*it);
				newVector.push_back(val);
				for (iterator it = position; it < this->end(); it++)
					newVector.push_back(*it);

				*this = newVector;
				return position;
			}

			void insert(iterator position, size_type n, const value_type& val) {
				if (position == this->end())
				{
					for (size_type i = 0; i < n; i++)
						this->push_back(val);
					return ;
				}
				ft::Vector<T> newVector;

				reserve(this->capacity() + 1);
				for (iterator it = this->begin(); it < position; it++)
					newVector.push_back(*it);
				for (size_type i = 0; i < n; i++)
					newVector.push_back(val);
				for (iterator it = position; it < this->end(); it++)
					newVector.push_back(*it);

				*this = newVector;
			}

			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
					if (position == this->end())
					{
						for (InputIterator it = first; it < last; it++)
							this->push_back(*it);
						return ;
					}
					ft::Vector<T> newVector;

					reserve(this->capacity() + 1);
					for (iterator it = this->begin(); it < position; it++)
						newVector.push_back(*it);
					for (InputIterator i = first; i < last; i++)
						newVector.push_back(*i);
					for (iterator it = position; it < this->end(); it++)
						newVector.push_back(*it);

					*this = newVector;
				}

			iterator erase (iterator position) {
				iterator it = this->begin();
				size_type posElem = 0;

				while (it != position) {
					it++;
					posElem++;
				}

				this->_alloc.destroy(this->_data + posElem);
				for (; posElem < this->end(); posElem++)
					this->_alloc.construct(&this->_data[posElem], this->_data[posElem + 1]);
				this->size--;
				return it;
			}

			iterator erase (iterator first, iterator last) {
				size_type diff = last.base() - first.base();
				size_type init = first.base() - this->_data;
				size_type trim = (this->_data + this->size()) - last.base();

				if (trim > 0) {
					for (size_type i = last.base() - this->_data, j = init; i < this->size() - 1; i++, j++) {
						this->_alloc.construct(&this->_data[j], this->_data[i]);
					}
				}
				for (size_type i = trim; i < this->size() - 1; i++)	
					this->_alloc.destroy(&this->_data[i]);
				
				this->_size -= diff;
				return first;
			}

			void swap(Vector &otherVector) {
				swap(this->_alloc, otherVector._alloc);
				swap(this->_data, otherVector.data);
				swap(this->_size, otherVector._size);
				swap(this->_capacity, otherVector._capacity);
			}

			void clear() {
				while (this->_size > 0)
					pop_back();
			}

			// ALLOCATOR


			allocator_type get_allocator() const {
				return this->_alloc;
			}

	};

	template<typename T, class Alloc>
	void	swap(ft::Vector<T, Alloc>& x, ft::Vector<T, Alloc>& y) {
		x.swap(y);
	}
}