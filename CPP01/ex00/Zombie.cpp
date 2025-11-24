/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:20:20 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:44:01 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "constructor for a Zombie called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called for " << this->name << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "constructor for " << name << " called" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
