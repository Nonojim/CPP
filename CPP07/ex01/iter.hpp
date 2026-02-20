/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:29:00 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 19:46:28 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

// https://en.cppreference.com/w/cpp/algorithm/for_each.html

#include <cstddef>
#include <iostream>

template <typename T, typename F> void iter(T *array, size_t length, F f)
{
	size_t i = 0;
	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

template <typename T> void increment(T &x)
{
	++x;
}

template <typename T> void print(const T &x)
{
	std::cout << x << std::endl;
}

#endif