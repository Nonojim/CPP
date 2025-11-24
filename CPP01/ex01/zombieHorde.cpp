/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:52:59 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 22:25:58 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;

	Zombie *zombieHorde = new Zombie[N];
	while (i < N)
		zombieHorde[i++].setName(name);
	return (zombieHorde);
}
