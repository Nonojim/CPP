/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:22:05 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 18:48:51 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const std::string name, int hitPoint, int energyPoint,
					int attackDamage);
		DiamondTrap(const DiamondTrap &original);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &c);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif