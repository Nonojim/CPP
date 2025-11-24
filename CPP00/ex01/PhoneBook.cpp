/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:28:54 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:05:20 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	this->size = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::addToPhoneBook(std::string firstName, std::string lastName,
			std::string nickName, std::string secret, std::string number)
{
	if (this->count == 8)
		this->count = 0;
	this->contacts[this->count].addContact(firstName, lastName, nickName, secret, number, count);
	this->count++;
	if (this->size < 8)
		this->size++;
}
int	PhoneBook::getCounter(void)
{
	return (this->count);
}


void	PhoneBook::showContacts(void)
{
	int i = 0;
	while (i < this->size)
		this->contacts[i++].displayContactTab();
}

void PhoneBook::showDataContact(int index)
{
	this->contacts[index].displayContactData();
}
