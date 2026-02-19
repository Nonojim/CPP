/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:23:49 by npederen          #+#    #+#             */
/*   Updated: 2026/02/19 21:51:03 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void ScalarConverter::print(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::printChar(double value)
{
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	if (std::isnan(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	float f = static_cast<float>(value);

	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

bool ScalarConverter::isSpecial(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff");
}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() != 1 || std::isdigit(str[0]))
		return (false);
	else
		return (true);
}

bool ScalarConverter::isInt(const std::string &str)
{
	char *end_ptr;

	long int value = strtol(str.c_str(), &end_ptr, 0);
	if (value > INT_MAX || value < INT_MIN || *end_ptr != '\0')
		return (false);
	else
		return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{

	char *end_str;
	int i = 0;
	int counter = 0;
	double value = std::strtod(str.c_str(), &end_str);

	if (*end_str != 'f' || *(end_str + 1) != '\0' || end_str == str.c_str())
		return (false);
	while (str[i])
	{
		if (str[i] == '.' && std::isdigit(str[i + 1]) != 0)
			counter++;
		i++;
	}
	if (counter != 1)
		return (false);
	if (std::isnan(value) || std::isinf(value))
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char *end_str;
	int i = 0;
	int counter = 0;
	double value = std::strtod(str.c_str(), &end_str);

	if (*end_str != '\0' || end_str == str.c_str())
		return (false);
	while (str[i])
	{
		if (str[i] == '.' && std::isdigit(str[i + 1]) != 0)
			counter++;
		i++;
	}
	if (counter != 1)
		return (false);
	if (std::isnan(value) || std::isinf(value))
		return (false);
	return (true);
}

ScalarConverter::e_type ScalarConverter::get_type(std::string string)
{
	if (isSpecial(string))
		return (DOUBLE);
	else if (isChar(string))
		return (CHAR);
	else if (isInt(string))
		return (INT);
	else if (isFloat(string))
		return (FLOAT);
	else if (isDouble(string))
		return (DOUBLE);
	else
		return (OTHER);
}

void ScalarConverter::convert(std::string string)
{
	e_type type = get_type(string);
	std::cout << type << std::endl;
	double value;
	switch (type)
	{
	case CHAR:
		value = static_cast<double>(string[0]);
		break;

	case INT:
		value = static_cast<double>(atoi(string.c_str()));
		break;

	case FLOAT:
		value = static_cast<double>(std::atof(string.c_str()));
		break;

	case DOUBLE:
		value = std::atof(string.c_str());
		break;

	default:
		throw ScalarConverter::BadInput();
	}
	print(value);
}

const char *ScalarConverter::BadInput::what() const throw()
{
	return ("Error : bad type try a double, float, an int or a printable char");
}
