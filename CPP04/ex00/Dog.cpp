/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:52:26 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 18:42:15 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &original) : Animal(original)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = original;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &c)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF" << std::endl;
}
