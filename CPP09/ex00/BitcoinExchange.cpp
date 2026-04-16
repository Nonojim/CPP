/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:01 by npederen          #+#    #+#             */
/*   Updated: 2026/04/16 20:19:18 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_data = src.getData();
	return (*this);
}

std::map<std::string, float> BitcoinExchange::getData(void) const
{
	return (this->_data);
}

int BitcoinExchange::validDate(const std::string &date) const
{
	if (date.length() != 10)
		return (0);
	if (date[4] != '-' && date[7] != '-')
		return (0);
	int i = 0;
	while (i < 10)
	{
		if (i != 4 && i != 7)
		{
			if (date[i] < '0' || date[i] > '9')
				return (0);
		}
		i++;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if ((month % 2 == 0 && day > 30 && month < 8) ||
		(month % 2 != 0 && day > 30 && month >= 8))
		return (0);
	if (month == 2 && day > 29)
		return (0);
	else if ((!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28 &&
			  month == 2))
		return (0);

	return (1);
}

int BitcoinExchange::validExcValue(const std::string &value, const int mode) const
{
	double number;
	char *end;
	number = (std::strtod(value.c_str(), &end));
	if (*end != '\0')
		return (0);
	if (mode == 1)
	{
		if (number < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			return (2);
		}
		if (number > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			return (3);
		}
	}
	return (1);
}

void BitcoinExchange::loadDb(const std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		std::cout << "Error: cannot open csv file !" << std::endl;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string value;
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		if (!validDate(date))
		{
			std::cout << "Error: invalid date in csv file => " << date << ", " << value
					  << std::endl;
		}
		if (!validExcValue(value, 0))
		{

			std::cout << "Error: bad database input => " << line << std::endl;
		}
		_data[date] = static_cast<float>(std::strtod(value.c_str(), NULL));
	}
	file.close();
}

float BitcoinExchange::getExcRate(const std::string fileName) const
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		std::cout << "Error: cannot open input file !" << std::endl;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string value;
		date = line.substr(0, line.find(" | "));
		value = line.substr(line.find(" | ") + 3);
		if (!validDate(date))
		{
			std::cout << "Error: bad input date => " << date << " | " << value
					  << std::endl;
			continue;
		}
		int ret = 0;
		if ((ret = validExcValue(value, 1)) != 1)
		{
			if (ret == 0)
				std::cout << "Error: bad input value => " << line << std::endl;
			continue;
		}
		float rate = 0;
		std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
		if (it != _data.end() && it->first == date)
		{
			rate = it->second;
			std::cout << date << " => " << value << " = "
					  << rate * static_cast<float>(std::atof(value.c_str())) << std::endl;
		}
		else if (it == _data.begin())
			std::cout << "Error: date is older than the oldest in the database !"
					  << std::endl;
		else
		{
			it--;
			rate = it->second;
			std::cout << date << " => " << value << " = "
					  << rate * static_cast<float>(std::atof(value.c_str())) << std::endl;
		}
	}
	file.close();
	return (0);
}