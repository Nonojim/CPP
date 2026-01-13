/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:52:00 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 18:42:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &original) : Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = original;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW MEOW" << std::endl;
}
