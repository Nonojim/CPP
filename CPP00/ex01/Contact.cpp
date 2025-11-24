/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:29:42 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:07:34 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}

void Contact::addContact(std::string firstName, std::string lastName, std::string nickName, std::string secret, std::string number, int index)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->darkestSecret = secret;
	this->phoneNumber = number;
	this->index = index;
}

std::string Contact::truncateStrTen(std::string str)
{
	std::string truncateStr;
	
	if (str.length() > 10)
	{
		truncateStr = str.substr(0, 9);
		truncateStr[9] = '.';
		return (truncateStr);
	}
	return (str);
}

void	Contact::displayContactTab(void)
{
	std::cout << std::setw(10) << std::right << this->index << "|"
		<< std::setw(10) << truncateStrTen(this->firstName) << "|"
		<< std::setw(10) << truncateStrTen(this->lastName) << "|"
		<< std::setw(10) << truncateStrTen(this->nickName) << std::endl;
}

void Contact::displayContactData(void)
{
	std::cout << "firstName : " << this->firstName << std::endl;
	std::cout << "lastName : " << this->lastName << std::endl;
	std::cout << "nickName : " << this->nickName << std::endl;
	std::cout << "phoneNumber : " << this->phoneNumber << std::endl;
	std::cout << "darkestSecret : " << this->darkestSecret << std::endl;
}
