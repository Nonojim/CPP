/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:31:54 by npederen          #+#    #+#             */
/*   Updated: 2025/12/21 12:45:42 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : type("Brain")
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = original;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &c)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	if (this != &c)
	{
		int i = 0;
		while (i++ < 100)
			this->ideas[i] = c.ideas[i];
	}
	return (*this);
}
