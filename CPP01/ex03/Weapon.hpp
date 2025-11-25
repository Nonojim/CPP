/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:09:10 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 14:08:47 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string);
		~Weapon();
		const std::string &getType(void) const;
		void setType(std::string);
};

#endif