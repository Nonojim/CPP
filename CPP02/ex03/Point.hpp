/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:38:14 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 20:06:19 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cstdlib>

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const Fixed fp1, const Fixed fp2);
		Point(const Point &original);
		~Point();
		Point &operator=(const Point &data);
		const Fixed &getPosX(void) const;
		const Fixed &getPosY(void) const;
};

#endif