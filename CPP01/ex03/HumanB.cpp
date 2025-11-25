/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:10:32 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 02:37:34 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	std::cout << "Constructor HumanB called" << std::endl;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << "Constructor called HumanB named " << this->name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destructor HumanB called" << std::endl;
}

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attack with their " << this->weapon->getType()
				  << std::endl;
	else
		std::cout << "attack with their bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << this->name << " equip " << weapon.getType() << std::endl;
}