/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:47:35 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 23:26:48 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _dArray;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);

		void print();
		void addNumber(int N);
		void addSet(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		class ExceptionNoStorageLeft : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("No storage left to store your numbers.");
				}
		};

		class ExceptionLessThanTwo : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Two value are needed to get a Span.");
				}
		};
};

#endif