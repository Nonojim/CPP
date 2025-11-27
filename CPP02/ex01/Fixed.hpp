/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:21 by npederen          #+#    #+#             */
/*   Updated: 2025/11/27 20:39:06 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		float &operator<<(const Fixed &c);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
