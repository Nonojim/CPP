/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:53:10 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 20:06:56 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &original);
		Animal &operator=(const Animal &c);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0; //fonction pure rend la classe abstraite
};

#endif