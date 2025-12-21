/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:37:46 by npederen          #+#    #+#             */
/*   Updated: 2025/12/21 16:12:13 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor with all parameters called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->attackDamage = c.attackDamage;
		this->energyPoint = c.energyPoint;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoint > 0)
	{
		if (this->energyPoint >= 1)
		{
			std::string plural = "points";
			if (this->attackDamage == 1)
				plural = "point";
			std::cout << "ScavTrap " << this->name << " attacks " << target
					  << ", causing " << this->attackDamage << " " << plural
					  << " of damage!" << std::endl;
			this->energyPoint--;
			std::cout << this->energyPoint << " energy remaining on " << this->name
					  << std::endl;
		}
		else
			std::cout << this->name << " has not enough energy to attack!" << std::endl;
	}
	else
		std::cout << this->name << " cannot attack because of his death." << std::endl;
}

void ScavTrap::guardGuate()
{
	if (this->hitPoint > 0)
	{
		if (this->energyPoint >= 1)
		{
			std::cout << "ScavTrap " << this->name << " gate keeper mode activating !"
					  << std::endl;
			this->energyPoint--;
			std::cout << this->energyPoint << " energy remaining on " << this->name
					  << std::endl;
		}
		else
			std::cout << this->name << " has not enough energy to guard!" << std::endl;
	}
	else
		std::cout << this->name << " cannot guard because of his death." << std::endl;
}
