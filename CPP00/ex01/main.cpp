/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:05:36 by npederen          #+#    #+#             */
/*   Updated: 2025/11/22 17:00:10 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

//https://stackoverflow.com/questions/12772076/what-is-the-operator-for-in-c

std::string	askData(std::string input)
{
	std::cin >> std::ws;
	std::getline(std::cin, input);
	return (input);
}

void	addContact(PhoneBook &pagesJaunes)
{
	std::string	firstname, lastname, nickname, secret, number;
	
	std::cout << "firstname ?" << std::endl;
	firstname = askData(firstname);
	std::cout << "lastname ?" << std::endl;
	lastname = askData(lastname);
	std::cout << "nickname ?" << std::endl;
	nickname = askData(nickname);
	std::cout << "secret ?" << std::endl;
	secret = askData(secret);
	std::cout << "number ?" << std::endl;
	number = askData(number);
	pagesJaunes.addToPhoneBook(firstname, lastname, nickname, secret, number);
}

void	searchContact(PhoneBook &pagesJaunes)
{
	int	index;
	std::string str;
	if (pagesJaunes.getCounter() == 0)
	{
		std::cout << "No contact registered" << std::endl;
		return ;
	}
	std::cout << "     index| firstname|  lastname|  nickname" << std::endl;
	pagesJaunes.showContacts();
	while (1)
	{
		std::cout << "Please enter the desired index or EXIT" << std::endl;
		if (std::getline(std::cin, str) == false)
			break ;
		if (str == "EXIT")
			break ;
		else if (str[0] >= 48 && str[0] <= 55 && str.length() == 1)
		{
			index = str[0] - 48;
			pagesJaunes.showDataContact(index);
			break ;
		}
		else
			std::cout << "Please enter a valid index between 0 and 7 inclusive" << std::endl;
	}
}

int	main(void)
{
	PhoneBook	pagesJaunes;
	std::string option;
	std::cout << "Hi this your phonebook" << std::endl;
	while (1)
	{
		std::cout << "Do you want to SEARCH, ADD or EXIT ?" << std::endl;
		if (std::getline(std::cin, option) == false)
			return (0);
		if (option == "SEARCH")
			searchContact(pagesJaunes);
		else if (option == "ADD")
			addContact(pagesJaunes);
		else if (option == "EXIT")
			return (0);
	}
	return (0);
}
