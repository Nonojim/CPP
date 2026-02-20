/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:55:47 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 14:11:13 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;

	data.id = 0;
	data.name = "Jim";

	Data *srcPtr = &data;

	std::cout << "src pointer               : " << srcPtr << std::endl;
	uintptr_t raw = Serializer::serialize(srcPtr);

	Data *restoredPtr = Serializer::deserialize(raw);

	std::cout << "pointer after deserialize : " << restoredPtr << std::endl;

	if (srcPtr == restoredPtr)
		std::cout << "Success: pointers are equal!" << std::endl;
	else
		std::cout << "Error: pointers are different!" << std::endl;

	return (0);
}