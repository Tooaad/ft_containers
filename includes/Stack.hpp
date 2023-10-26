/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:25:45 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/15 12:39:45 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/Vector.hpp"
#include "../utils/utils.hpp"

namespace ft {
template <class T, class Container = vector<T> > 
	class stack {
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
		
		protected:
			container_type c;
			
		public:
			virtual ~stack() {}
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}
			stack(const stack& stack) : c(stack.c) {}
			stack& operator=(const stack& stack) {
				this->c = stack.c;
				return *this;
			}
			reference top() { return c.back(); }
			const_reference top() const { return c.back(); }

			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			
			void push(const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }

			template <class T1, class C1>
    			friend bool operator==(const stack<T1, C1>& x, const stack<T1, C1>& y);

    		template <class T1, class C1>
				friend bool operator< (const stack<T1, C1>& x, const stack<T1, C1>& y);
	};

	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.c == rhs.c;
		}
	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Container>
		bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.c < rhs.c;
		}
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return rhs < lhs;
		}
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs < rhs);
		}
}