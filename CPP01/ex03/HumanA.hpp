/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:09:39 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 13:58:06 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
#define HumanA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		HumanA();
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string, Weapon &weapon);
		~HumanA();
		void attack(void);
};
#endif