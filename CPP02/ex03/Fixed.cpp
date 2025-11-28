/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:32 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 20:10:43 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value * (1 << fractional);
}

Fixed::Fixed(const float value)
{
	this->value = static_cast<int>(roundf(value * (1 << this->fractional)));
}

Fixed::Fixed(const Fixed &original)
{
	*this = original;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &c)
{
	if (this != &c)
		this->value = c.getRawBits();
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	value++;
	return (copy);
}

Fixed &Fixed::operator--(void)
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	value--;
	return (copy);
}

Fixed Fixed::operator+(const Fixed &c) const
{
	return (this->toFloat() + c.toFloat());
}

Fixed Fixed::operator-(const Fixed &c) const
{
	return (this->toFloat() - c.toFloat());
}

Fixed Fixed::operator*(const Fixed &c) const
{
	return (this->toFloat() * c.toFloat());
}

Fixed Fixed::operator/(const Fixed &c) const
{
	return (this->toFloat() / c.toFloat());
}

bool Fixed::operator>(const Fixed &c) const
{
	return (this->toFloat() > c.toFloat());
}

bool Fixed::operator<(const Fixed &c) const
{
	return (this->toFloat() < c.toFloat());
}

bool Fixed::operator>=(const Fixed &c) const
{
	return (this->toFloat() >= c.toFloat());
}

bool Fixed::operator<=(const Fixed &c) const
{
	return (this->toFloat() <= c.toFloat());
}

bool Fixed::operator==(const Fixed &c) const
{
	return (this->toFloat() == c.toFloat());
}

bool Fixed::operator!=(const Fixed &c) const
{
	return (this->toFloat() != c.toFloat());
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
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

Fixed &Fixed::min(Fixed &c1, Fixed &c2)
{
	if (c1 > c2)
		return (c2);
	else
		return (c1);
}

const Fixed &Fixed::min(const Fixed &c1, const Fixed &c2)
{
	if (c1 > c2)
		return (c2);
	else
		return (c1);
}

Fixed &Fixed::max(Fixed &c1, Fixed &c2)
{
	if (c1 > c2)
		return (c1);
	else
		return (c2);
}

const Fixed &Fixed::max(const Fixed &c1, const Fixed &c2)
{
	if (c1 > c2)
		return (c1);
	else
		return (c2);
}

std::ostream &operator<<(std::ostream &os, const Fixed &c)
{
	os << c.toFloat();
	return (os);
}
