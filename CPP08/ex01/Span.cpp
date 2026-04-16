/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:47:05 by npederen          #+#    #+#             */
/*   Updated: 2026/04/16 20:49:16 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	// std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	// std::cout << "Size specified Span constructor called" << std::endl;
}

Span::~Span()
{
	// std::cout << "Default Span destructor called" << std::endl;
}

Span::Span(const Span &src)

{
	// std::cout << "Default Span copy constructor called" << std::endl;

	*this = src;
}

Span &Span::operator=(const Span &src)
{
	// std::cout << "Span copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_size = src._size;
		this->_dArray = src._dArray;
	}
	return (*this);
}

void Span::print()
{
	for (std::vector<int>::iterator it = _dArray.begin(); it != _dArray.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

void Span::addNumber(int N)
{
	if ((this->_dArray.size() + 1) > this->_size)
		throw ExceptionNoStorageLeft();
	else
		this->_dArray.push_back(N);
}

int Span::shortestSpan(void) const
{
	if (this->_dArray.size() < 2)
		throw ExceptionLessThanTwo();

	Span tmp(*this);
	std::vector<int>::iterator min = min_element(tmp._dArray.begin(), tmp._dArray.end());
	int firstMin = *min;
	tmp._dArray.erase(min);
	std::vector<int>::iterator secMin =
	min_element(tmp._dArray.begin(), tmp._dArray.end());
	int secondMin = *secMin;

	return (secondMin - firstMin);
}

int Span::longestSpan(void) const
{
	if (this->_dArray.size() < 2)
		throw ExceptionLessThanTwo();

	int min = *min_element(this->_dArray.begin(), this->_dArray.end());
	int max = *max_element(this->_dArray.begin(), this->_dArray.end());

	return (max - min);
}

void Span::addSet(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (static_cast<unsigned int>(end - begin) > (this->_size - this->_dArray.size()))
		throw ExceptionNoStorageLeft();
	else
		this->_dArray.insert(_dArray.end(), begin, end);
}
