/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:42:40 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 14:06:02 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*reinterpret_cast is intended for low-level casts that yield implemen
tation-dependent (i.e., unportable) results, e.g., casting a pointer
to an int. Such casts should be rare outside low-level code.*/

Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}