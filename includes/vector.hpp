/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:25:42 by gpernas-          #+#    #+#             */
/*   Updated: 2022/04/06 01:22:49 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <string>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class Vector {

	public:
		typedef Allocator allocator_type;
		typedef typename Allocator::value_type value_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::difference_type difference_type;
		typedef typename Allocator::size_type size_type;
		
		
		
		
	};
}