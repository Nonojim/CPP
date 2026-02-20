/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:23:22 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 13:38:34 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*static_cast peut être utilisé pour forcer des conversions implicites (par exemple, un
 * objet non constant en objet constant , un entier en double, etc.). Il peut également
 * être utilisé pour effectuer l'inverse de nombreuses conversions de ce type (par
 * exemple, des pointeurs void* en pointeurs typés, des pointeurs vers la base en
 * pointeurs vers le dérivé), mais il ne peut pas convertir des objets constants en objets
 * non constants. (Seul const_cast peut le faire.)
 */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}