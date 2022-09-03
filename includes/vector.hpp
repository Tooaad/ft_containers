#pragma once

#include <stdexcept>
#include <iostream>
#include "vectorIter.hpp"
#include "ReverseIter.hpp"
#include "../utils/utils.hpp"

namespace ft {
template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef typename ft::vectorIter<pointer>			iterator;
			typedef typename ft::vectorIter<const_pointer>		const_iterator;
			typedef typename ft::ReverseIter<iterator>			reverse_iterator;
			typedef typename ft::ReverseIter<const_iterator>	const_reverse_iterator;
			typedef typename Allocator::difference_type			difference_type;
			typedef typename Allocator::size_type				size_type;

		private:
			T*				_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
		
		public:

			explicit vector(const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0), _alloc(alloc) {
					this->_data = this->_alloc.allocate(this->_capacity);
				}

			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
					this->_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						this->_alloc.construct(&this->_data[i], value);
				}
			
			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				: _size(0), _alloc(alloc) {
					size_type n = 0;
					
					for (InputIterator it = first; it != last; it++)
						n++;
					this->_data = _alloc.allocate(n);
					this->_capacity = n;
					for (InputIterator it = first; it != last; it++)
						push_back(*it);
				}
			
			vector(const vector& othervector) {
				this->_size = othervector._size;
				this->_capacity = othervector._capacity;
				this->_alloc = othervector._alloc;
				this->_data = _alloc.allocate(_capacity);

				for (size_type i = 0; i < this->_size; i++)
					_alloc.construct(&this->_data[i], othervector._data[i]);
			}

			virtual ~vector() {
				this->_alloc.destroy(this->_data);
				this->_alloc.deallocate(this->_data, this->_capacity);
			}

			vector&	operator=(const vector& othervector) {
				if (this != &othervector) {
					clear();
					this->_alloc.deallocate(this->_data, capacity());
					if (othervector._size > this->_capacity)
						this->_capacity = othervector._capacity;

					this->_size = othervector._size;
					this->_data = _alloc.allocate(_capacity);

					for (size_type i = 0; i < othervector.size(); i++)
						this->_alloc.construct(&this->_data[i], othervector._data[i]);
				}
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
				if (n > capacity()) {
					size_type oldCapacity = this->_capacity;
					reserve(oldCapacity * 2 > n && size() > 0? capacity() * 2 : n);
					pointer newData = this->_alloc.allocate(capacity());

					// Para copiar lo antiguo en lo nuevo
					for (size_type i = 0; i < size(); i++)
						this->_alloc.construct(&newData[i], this->_data[i]);
					this->_alloc.deallocate(this->_data, oldCapacity);
					this->_data = newData;
				}
				while (size() > capacity() || n < size())
					pop_back();
				
				while (size() < n && val != value_type())
					push_back(val);
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("Trying to allocate more than the allowed max_size");
				if (capacity() <= n)
					this->_capacity = n;
			}

			size_type capacity() const {
				return this->_capacity;
			}

			bool empty() const {
				return (this->begin() == this->end());
			}


	//		ELEMENT ACCESS
			reference operator[](size_type n) { return this->_data[n]; }
			const_reference operator[](size_type n) const { return this->_data[n]; }
			reference at(size_type n) {
				if (n >= size())
					throw std::out_of_range("Index out of range");
				return  this->_data[n];
			}
			const_reference at(size_type n) const {
				if (n >= size())
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
					clear();
					for (InputIterator it = first; it != last; it++)
						n++;
					if (n > capacity())
						resize(n);
					for (InputIterator it = first; it != last; it++)
						push_back(*it);
			}

			void assign(size_type n, const value_type& value) {
				clear();
				if (n > capacity())
					resize(n);

				while (size() < n)
					push_back(value);
			}

			void push_back(const value_type& val) {
				if (size() == capacity())
					resize(capacity() < 1 ? 1 : capacity() * 2);
				this->_alloc.construct(&this->_data[size()], val);
				this->_size++;
			}

 
			void pop_back() {
				if (!this->empty()) {
					this->_size--;
					this->_alloc.destroy(&this->_data[this->size()]);
				}
			}

			iterator insert(iterator position, const value_type& val) {
				if (position == end())
				{
					push_back(val);
					return end() - 1;
				}
				ft::vector<T> newvector;
				
				if (size() + 1 > capacity())
					reserve(capacity() * 2 > 1 + size() && size() > 0? capacity() * 2 : 1 + size());

				for (iterator it = begin(); it < position; it++)
					newvector.push_back(*it);

				newvector.push_back(val);
				iterator aux = newvector.end() - 1;

				for (iterator it = position; it < end(); it++)
					newvector.push_back(*it);

				*this = newvector;
				return aux;
			}

			void insert(iterator position, size_type n, const value_type& val) {
				if (position == end())
				{
					if (empty())
						resize(n, val);
					else
						for (size_type i = 0; i < n; i++)
							this->push_back(val);
					return ;
				}
				ft::vector<T> newvector;
				if (size() + n > capacity())
					reserve(capacity() * 2 > n + size() && size() > 0? capacity() * 2 : n + size());

				for (iterator it = begin(); it < position; it++)
					newvector.push_back(*it);
				for (size_type i = 0; i < n; i++)
					newvector.push_back(val);
				for (iterator it = position; it < end(); it++)
					newvector.push_back(*it);

				*this = newvector;
			}

			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
					size_type n = 0;
					for (InputIterator it = first; it != last; it++)
						n++;
					if (position == end())
					{
						if (empty())
							resize(n);
						for (InputIterator it = first; it != last; it++)
							this->push_back(*it);
						return ;
					}
					ft::vector<T> newvector;
					if (size() + n > capacity())
						reserve(capacity() * 2 > n + size() && size() > 0? capacity() * 2 : n + size());

					for (iterator it = begin(); it < position; it++)
						newvector.push_back(*it);
					for (InputIterator i = first; i != last; i++)
						newvector.push_back(*i);
					for (iterator it = position; it < end(); it++)
						newvector.push_back(*it);

					*this = newvector;
				}

			iterator erase (iterator position) {
				iterator it = this->begin();
				size_type posElem = 0;
				while (it != position) {
					it++;
					posElem++;
				}

				this->_alloc.destroy(this->_data + posElem);
				for (; posElem < size() - 1; posElem++)
					this->_alloc.construct(&this->_data[posElem], this->_data[posElem + 1]);
				this->_size--;
				return it;
			}

			iterator erase(iterator first, iterator last) {
				if (first == last)
					return first;
				size_type diff = last.base() - first.base();
				size_type init = first.base() - this->_data;
				iterator tmp = this->end();

				for (size_type i = 0; i < size() - 1; i++) {
					if (init + diff < size()) 
						this->_alloc.construct(&_data[init], _data[diff + init]);
					init++;
				}
				this->_size -= diff;
				if (first == tmp)
					return this->end();
				return first;
			}

			void swap(vector &othervector) {
				ft::swap(this->_alloc, othervector._alloc);
				ft::swap(this->_data, othervector._data);
				ft::swap(this->_size, othervector._size);
				ft::swap(this->_capacity, othervector._capacity);
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

	template <class T, class Alloc>
		bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class T, class Alloc>
		bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return !(lhs == rhs);
		}

	template <class T, class Alloc>
		bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Alloc>
		bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Alloc>
		bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
		}

	template <class T, class Alloc>
		bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return !(lhs < rhs);
		}

	template<typename T, class Alloc>
	void	swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y) {
		x.swap(y);
	}
}

