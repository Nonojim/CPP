/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:21:56 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 19:42:43 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor with name called" << std::endl;
	this->name = name;
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &c)
{
	std::cout << "Diamond copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->name = c.name;
		this->ClapTrap::name = c.ClapTrap::name;
		this->hitPoint = c.hitPoint;
		this->attackDamage = c.attackDamage;
		this->energyPoint = c.energyPoint;
		this->maxHp = c.maxHp;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My clap name is " << ClapTrap::name << " and my DiamondTrap name is "
			  << this->name << std::endl;
}