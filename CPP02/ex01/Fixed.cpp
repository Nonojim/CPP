/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:32 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 15:51:51 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value * (1 << fractional);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(roundf(value * (1 << this->fractional)));
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed &Fixed::operator=(const Fixed &c)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = c.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &c)
{
	os << c.toFloat();
	return (os);
}

float Fixed::toFloat(void) const
{
	int i = fractional;
	float fval = value;
	while (i-- > 0)
		fval /= 2;
	return (fval);
}

int Fixed::toInt(void) const
{
	int i = fractional;
	int newVal = value;
	while (i-- > 0)
		newVal /= 2;
	return (newVal);
}