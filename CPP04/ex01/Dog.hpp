/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:52:10 by npederen          #+#    #+#             */
/*   Updated: 2025/12/21 12:40:57 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	private:
		Brain *attribute;

	protected:
		std::string type;

	public:
		Dog();
		~Dog();
		Dog(const Dog &original);
		Dog &operator=(const Dog &c);
		void makeSound(void) const;
};

#endif