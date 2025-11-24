/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:19:41 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:47:02 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	std::cout << "Not dynamic" << std::endl;
	Zombie reda("reda");
	reda.announce();
	std::cout << "Very dynamic zombie" << std::endl;
	Zombie *cheratif = newZombie("cheratif");
	cheratif->announce();
	delete (cheratif);
	randomChump("loulou");
	return (0);
}