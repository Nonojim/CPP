/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:27 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 21:45:35 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> void easyfind(T &container, int value);

class NoValueFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("No corresponding value found.");
		}
};

#include "easyfind.tpp"

#endif