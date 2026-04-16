/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:01 by npederen          #+#    #+#             */
/*   Updated: 2026/04/16 14:49:00 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called" << std::endl;
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

std::map<std::string, double> BitcoinExchange::getData(void) const
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
	// std::cout << year << " " << month << " " << day << " " << std::endl;
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

int BitcoinExchange::validExcValue(const std::string &value) const
{
	// std::cout << "string: " << value << std::endl;
	double n;
	char *e;
	n = (std::strtod(value.c_str(), &e));
	if (*e != '\0')
		return (0);
	return (1);
}

void BitcoinExchange::loadDb(const std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		std::cout << "Error: cannot open csv file !" << std::endl;
	std::string line;
	std::cout << "date,exchange_rate" << std::endl;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string value;
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		if (!validDate(date))
		{
			std::cout << "Error: invalid date in csv file -> " << date << ", " << value
					  << std::endl;
		}
		if (!validExcValue(value))
		{

			std::cout << "Error: invalid value in csv file -> " << date << ", " << value
					  << std::endl;
		}
	}
	file.close();
}
