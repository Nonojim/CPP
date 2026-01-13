/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:31:54 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 19:55:21 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << "Brain copy constructor called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = original.ideas[i];
		i++;
	}
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
		while (i < 100)
		{
			this->ideas[i] = c.ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i > -1 && i < 101)
		return (this->ideas[i]);
	return (0);
}

void Brain::setIdea(int i, std::string const &str)
{
	if (i > -1 && i < 101)
		this->ideas[i] = str;
}
