/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:59:13 by npederen          #+#    #+#             */
/*   Updated: 2026/02/25 14:16:39 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{

	Array<int> a(5);
	Array<std::string> stringArr;

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
	print(stringArr);

	try
	{
		std::cout << "trying OOR index" << std::endl;
		std::cout << stringArr[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
