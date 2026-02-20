/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:59:04 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 20:46:27 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		T *_data;
		unsigned int _size;
		class IndexOOR : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Index out of range");
				}
		};

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &src);
		Array &operator=(const Array &src);

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int size() const;
};

#include "Array.tpp"

#endif