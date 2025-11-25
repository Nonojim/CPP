/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:09:25 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 02:27:40 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Constructor Weapon called" << std::endl;
};

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Constructor Weapon called" << std::endl;
};

Weapon::~Weapon()
{
	std::cout << "Destructor Weapon called" << std::endl;
};

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string const &Weapon::getType(void)
{
	return (this->type);
}