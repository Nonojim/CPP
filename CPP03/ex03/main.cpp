/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:22:44 by npederen          #+#    #+#             */
/*   Updated: 2025/12/18 15:37:37 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap one("Mage");
	DiamondTrap two("Est");
	DiamondTrap three("Lent");
	
	one.whoAmI();
	two.whoAmI();
	three.whoAmI();
	DiamondTrap four(one);
	four.whoAmI();
	four.attack("BullShark");
	four.guardGuate();
	four.highFivesGuys();
	return (0);
}