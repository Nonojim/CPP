/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:51:56 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 19:27:56 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &original);
		Cat &operator=(const Cat &c);
		void makeSound(void) const;
		Brain *getBrain(void) const;
};

#endif