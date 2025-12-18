/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:51:56 by npederen          #+#    #+#             */
/*   Updated: 2025/12/18 16:15:40 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	protected:
		std::string type;

	public:
		Cat();
		~Cat();
		Cat(const Cat &original);
		Cat &operator=(const Cat &c);
};

#endif