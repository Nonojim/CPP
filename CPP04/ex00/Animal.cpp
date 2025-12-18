/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:52:53 by npederen          #+#    #+#             */
/*   Updated: 2025/12/18 16:25:29 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &original)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = original;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &c)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	if (this->type == "Dog")
		std::cout << "WOOF WOOF" << std::endl;
	if (this->type == "Cat")
		std::cout << "MEOW MEOW" << std::endl;
}