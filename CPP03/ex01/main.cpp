/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:22:44 by npederen          #+#    #+#             */
/*   Updated: 2026/01/21 15:36:09 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap one("Jim");
	one.guardGuate();
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
	ScavTrap two(one);
	two.attack("Bullshark");
	return (0);
}