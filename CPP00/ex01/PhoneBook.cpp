/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:28:54 by npederen          #+#    #+#             */
/*   Updated: 2025/11/22 14:28:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->count = 0;
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
}
int	PhoneBook::getCounter(void)
{
	return (this->count);
}


void	PhoneBook::showContacts(void)
{
	int i = 0;
	while (i < this->count)
		this->contacts[i++].displayContactTab();
}

void PhoneBook::showDataContact(int index)
{
	contacts[index].displayContactData();
}