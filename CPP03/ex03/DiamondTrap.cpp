/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:21:56 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 18:50:05 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("Bob"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	this->maxHp = hitPoint;
	std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : FragTrap(), ScavTrap()
{
	std::string new_name;
	new_name = name + "_clap_name";
	this->name = new_name;
	
	std::cout << "constructor with name called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name, int hitPoint, int energyPoint,
						 int attackDamage)
	: name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage)
{
	this->maxHp = hitPoint;
	std::cout << "DiamondTrap constructor with all parameters called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &c)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &c)
	{
		this->name = c.name;
		this->hitPoint = c.hitPoint;
		this->attackDamage = c.attackDamage;
		this->energyPoint = c.energyPoint;
		this->maxHp = c.maxHp;
	}
	return (*this);
}
