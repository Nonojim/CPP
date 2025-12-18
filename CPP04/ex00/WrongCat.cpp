/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:10:11 by npederen          #+#    #+#             */
/*   Updated: 2025/12/18 22:15:24 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = original;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat copy assignement operator called" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Mooo MOOOO? This cat must be sick" << std::endl;
}
