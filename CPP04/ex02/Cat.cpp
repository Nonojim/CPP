/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:52:00 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 19:28:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &original) : Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*original.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->brain);
}

Cat &Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &c)
	{
		Animal::operator=(c);
		delete brain;
		brain = new Brain(*c.brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW MEOW" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}