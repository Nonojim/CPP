/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:01 by npederen          #+#    #+#             */
/*   Updated: 2026/03/02 15:39:50 by npederen         ###   ########.fr       */
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

std::map<std::string, double> BitcoinExchange::getData(const BitcoinExchange &src) const
{
	return (this->_data);
}
