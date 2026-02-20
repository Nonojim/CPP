/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:42:54 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 14:05:58 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

/*uintptr_t un unsigned int ayant la propriété que tout pointeur valide vers void peut
 * être converti en ce type, puis reconverti en pointeur vers void, et que le résultat
 * sera égal au pointeur d'origine.*/

struct Data
{
		int id;
		std::string name;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif