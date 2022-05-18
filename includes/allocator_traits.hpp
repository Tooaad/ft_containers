/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:15:48 by gpernas-          #+#    #+#             */
/*   Updated: 2022/05/13 00:44:40 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

namespace ft {
    template <class T> class allocator;

    template <>
    class allocator<void>
    {
    public:
        typedef void              value_type;
        typedef value_type*       pointer;
        typedef value_type const* const_pointer;
        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        template <class U>
        struct rebind
        {
            typedef allocator<U> other;
        };
    };

    template <class T>
    class allocator
    {
    public:
        typedef T                 value_type;
        typedef value_type&       reference;
        typedef value_type const& const_reference;
        typedef value_type*       pointer;
        typedef value_type const* const_pointer;
        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        template <class U>
        struct rebind
        {
            typedef allocator<U> other;
        };

        template <class U> allocator(allocator<U> const& ) throw() {}

        pointer
        allocate(size_type n, allocator<void>::const_pointer = 0)
        {
            return static_cast<pointer>(::operator new (n*sizeof(value_type)));
        }

        void
        deallocate(pointer p, size_type)
        {
            ::operator delete(p);
        }

        void
        construct(pointer p, value_type const& val)
        {
            ::new(p) value_type(val);
        }

        void
        destroy(pointer p)
        {
            p->~value_type();
        }

        size_type
        max_size() const throw()
        {
            return std::numeric_limits<size_type>::max() / sizeof(value_type);
        }

        pointer
        address(reference x) const
        {
            return &x;
        }

        const_pointer
        address(const_reference x) const
        {
            return &x;
        }
    };

    template <class T, class U>
    bool
    operator==(allocator<T> const&, allocator<U> const&)
    {
        return true;
    }

    template <class T, class U>
    bool
    operator!=(allocator<T> const& x, allocator<U> const& y)
    {
        return !(x == y);
    }
}