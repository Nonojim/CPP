/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:22 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 16:28:34 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string name;
		int hitPoint;
		int energyPoint;
		int attackDamage;
		unsigned int maxHp;

	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const std::string name, int hitPoint, int energyPoint, int attackDamage);
		ClapTrap(const ClapTrap &original);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &c);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif