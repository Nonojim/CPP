/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:21 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 17:13:42 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>
#include <string>

class Fixed
{
	private:
		int value;
		static const int fractional = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &original);
		~Fixed();

		Fixed &operator=(const Fixed &c);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		bool operator>(const Fixed &c) const;
		bool operator<(const Fixed &c) const;
		bool operator>=(const Fixed &c) const;
		bool operator<=(const Fixed &c) const;
		bool operator==(const Fixed &c) const;
		bool operator!=(const Fixed &c) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &c1, Fixed &c2);
		static const Fixed &min(const Fixed &c1, const Fixed &c2);
		static Fixed &max(Fixed &c1, Fixed &c2);
		static const Fixed &max(const Fixed &c1, const Fixed &c2);
};
// you can put in the class in static to access private members without getter
std::ostream &operator<<(std::ostream &o, const Fixed &c);

#endif