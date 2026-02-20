/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:13:40 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 16:19:03 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/*
Template functions: swap, min, max

Requirements on type T:
- Must be copy constructible
- Must support operator=
- For min: must support operator<
- For max: must support operator>
*/

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T const &min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T const &max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
