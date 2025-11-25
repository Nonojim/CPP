/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:10:26 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 02:33:11 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "Constructor called HumanA named " << this->name << std::endl;
	std::cout << this->name << " get this weapon :" << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor HumanA called" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attack with their " << this->weapon.getType()
			  << std::endl;
}
