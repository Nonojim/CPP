/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:23:47 by npederen          #+#    #+#             */
/*   Updated: 2026/02/19 21:51:30 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		static void convert(std::string str);

		class BadInput : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		static bool isFloat(const std::string &str);

	private:
		enum e_type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			OTHER
		};

		static e_type get_type(std::string string);
		static bool isSpecial(const std::string &str);
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isDouble(const std::string &str);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

		static void print(double value);
};

#endif