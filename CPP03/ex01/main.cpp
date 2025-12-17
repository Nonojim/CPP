/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:22:44 by npederen          #+#    #+#             */
/*   Updated: 2025/12/17 14:30:42 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap one("Jim");
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
	return (0);
}