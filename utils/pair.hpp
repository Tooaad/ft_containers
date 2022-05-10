/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:19:13 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/09 18:25:05 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
template <class T1, class T2>
	class Pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	_first;
			second_type	_second;
		 
		public:
			Pair() : _first(), _second() {std::cout << "'1" << std::endl;}

			Pair(const first_type& a, const second_type& b) : _first(a), _second(b) {}
			
			template<class U, class V>
				Pair(const Pair<U,V>& pr) : _first(pr._first), _second(pr._second) {}


			Pair& operator=(const Pair& pr) {
				this->_first = pr._first;
				this->_second = pr._second;
				return *this;
			}

			T1&	getFirst() const {
				return _first;
			}
		};

	template <class T1,class T2>
  		ft::Pair<T1,T2> make_pair(T1 x, T2 y)
  		{
    		return (Pair<T1,T2>(x,y));
  		}

	template <class T1, class T2>
		bool operator== (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}

	template <class T1, class T2>
		bool operator!= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return !(lhs==rhs);
		}
	
	template <class T1, class T2>
		bool operator<  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}

	template <class T1, class T2>
		bool operator<= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return !(rhs<lhs);
		}
	
	template <class T1, class T2>
		bool operator>  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return rhs<lhs;
		}

	template <class T1, class T2>
		bool operator>= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs) {
			return !(lhs < rhs);
		}
}