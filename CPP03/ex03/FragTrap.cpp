/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:09:57 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 19:36:19 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor with all parameters called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = original;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->attackDamage = c.attackDamage;
		this->energyPoint = c.energyPoint;
	}
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (this->hitPoint > 0)
	{
		if (this->energyPoint >= 1)
		{
			std::string plural = "points";
			if (this->attackDamage == 1)
				plural = "point";
			std::cout << "FragTrap " << this->name << " attacks " << target
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

void FragTrap::highFivesGuys()
{
	if (this->hitPoint > 0)
	{
		if (this->energyPoint >= 1)
		{
			std::cout << "FragTrap " << this->name << " Hey guys lets high five !"
					  << std::endl;
			this->energyPoint--;
			std::cout << this->energyPoint << " energy remaining on " << this->name
					  << std::endl;
		}
		else
			std::cout << this->name << " has not enough energy to high five anyone!"
					  << std::endl;
	}
	else
		std::cout << this->name << " cannot high five because of his death." << std::endl;
}