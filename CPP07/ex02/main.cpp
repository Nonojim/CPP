/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:59:13 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 21:03:49 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{

	Array<int> a(5);

	unsigned int i = 0;
	while (i < a.size())
	{
		a[i] = i * 10;
		i++;
	}
	print(a);
	Array<int> b = a;
	print(b);

	b[0] = 999;

	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	print(a);
	print(b);

	try
	{
		std::cout << "trying OOR index" << std::endl;
		std::cout << a[42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
