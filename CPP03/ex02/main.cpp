/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:22:44 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 18:18:38 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap one("Mage");
	ScavTrap two("Est");
	FragTrap three("Lent");
	two.guardGuate();
	one.takeDamage(0);
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.attack("Bullshark");
	one.beRepaired(999);
	three.highFivesGuys();
	return (0);
}