/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:38:04 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 20:06:37 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed fp1, const Fixed fp2) : x(fp1), y(fp2)
{
}

Point::Point(const Point &original) : x(original.x), y(original.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &point)
{
	(void)point;
	std::cerr << "ERROR : all private members are type const" << std::endl;
	std::exit(1);
}

const Fixed &Point::getPosX(void) const
{
	return (this->x);
}

const Fixed &Point::getPosY(void) const
{
	return (this->y);
}
