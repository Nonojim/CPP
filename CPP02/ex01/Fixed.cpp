/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:32 by npederen          #+#    #+#             */
/*   Updated: 2025/11/27 20:39:01 by npederen         ###   ########.fr       */
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
	this->value = value;
}

Fixed::Fixed(const float value)
{
	this->value = static_cast<int32_t>(roundf(value * (1 << this->fractional)));
	std::cout << this->value << std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float &Fixed::operator<<(const Fixed &c)
{
	(void)c;
	std::cout << "Copy assignment operator called" << std::endl;
	return ((float)this->value);
}

Fixed &Fixed::operator=(const Fixed &c)
{
	std::cout << "<< operator called >>" << std::endl;
	this->value = c.getRawBits();
	return (*this);
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