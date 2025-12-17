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

ClapTrap::ClapTrap() : name("Bob"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	this->maxHp = hitPoint;
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	this->maxHp = hitPoint;
	std::cout << "ClapTrap constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, int hitPoint, int energyPoint,
				   int attackDamage)
	: name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage)
{
	this->maxHp = hitPoint;
	std::cout << "ClapTrap constructor with all parameters called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << "ClapTrap copy assignement operator called" << std::endl;
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
		if (amount >= this->maxHp)
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
		if ((this->hitPoint + amount) <= this->maxHp)
			this->hitPoint += amount;
		else
			this->hitPoint = this->maxHp;
		std::cout << "ClapTrap " << this->name << " repaired for " << amount << " "
				  << plural << " of health!" << std::endl;
		std::cout << this->hitPoint << "hp remaining on " << this->name << "!"
				  << std::endl;
		this->energyPoint--;
		std::cout << this->energyPoint << " energy remaining on " << this->name
				  << std::endl;
	}
	else
		std::cout << this->name << " has not enough energy to repair!" << std::endl;
}
