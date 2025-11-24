/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:53:20 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 23:03:45 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int i = 0;
	int nbZombies = 12;
	Zombie *horde = zombieHorde(nbZombies, "Reda");
	while (i < nbZombies)
		horde[i++].announce();
	delete[] horde;
	std::cout << i << " zombies lived then die" << std::endl;
	return (0);
}
