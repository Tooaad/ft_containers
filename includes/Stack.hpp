/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:25:45 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/02 23:23:38 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft {
template <class T, class Container = Vector<T> > 
	class Stack {
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
		
		protected:
			container_type c;
			
		public:
			explicit Stack(const container_type& char ctnr = container_type()) : c(ctnr) {}
			virtual ~Stack() {}
			Stack(const Stack& stack) : c(stack.c) {}
			Stack& operator=(const Stack& stack) {
				this->c = stack.c;
				return *this;
			}
			bool empty() const { return c.empty(); }
			size_type size const { return c.size(); }
			reference top() { return c.back(); }
			const_reference top() { return c.back(); }
			void push(const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }

			template <class T1, class C1>
    			friend bool operator==(const stack<T1, C1>& x, const stack<T1, C1>& y);

    		template <class T1, class C1>
				friend bool operator< (const stack<T1, C1>& x, const stack<T1, C1>& y);
	};

	template <class T, class Container>
		bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
	template <class T, class Container>
		bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Container>
		bool operator< (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Container>
		bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Container>
		bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
		}
	template <class T, class Container>
		bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
			return !(lhs < rhs);
		}
}