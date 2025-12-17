/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen this->npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:41 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 13:42:08 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
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

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoint > 0)
	{
		if (this->energyPoint >= 1)
		{
			std::string plural = "points";
			if (this->attackDamage == 1)
				plural = "point";
			std::cout << "ClapTrap " << this->name << " attacks " << target
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > 0)
	{
		std::string plural = "points";
		if (amount == 1)
			plural = "point";
		if (amount >= 10)
			this->hitPoint = 0;
		else
			this->hitPoint -= amount;
		std::cout << "ClapTrap " << this->name << " take " << amount << " " << plural
				  << " of damage!" << std::endl;
		std::cout << this->hitPoint << "hp remaining on " << this->name << "!"
				  << std::endl;
	}
	else
		std::cout
		<< "Bad news " << this->name
		<< " is getting attacked. Good news is, he is already dead so he takes no damages"
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint >= 1)
	{
		std::string plural = "points";
		if (amount == 1)
			plural = "point";
		if ((this->hitPoint + amount) <= 10)
			this->hitPoint += amount;
		else
			this->hitPoint = 10;
		std::cout << "ClapTrap " << this->name << " repaired for " << amount << " "
				  << plural << " of damage!" << std::endl;
		std::cout << this->hitPoint << "hp remaining on " << this->name << "!"
				  << std::endl;
		this->energyPoint--;
		std::cout << this->energyPoint << " energy remaining on " << this->name
				  << std::endl;
	}
	else
		std::cout << this->name << " has not enough energy to repair!" << std::endl;
}
