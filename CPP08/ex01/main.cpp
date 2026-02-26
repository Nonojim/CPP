/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:47:19 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 23:35:52 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(15);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "\n---- PRINTING ALL ---- " << std::endl;
		sp.print();
		std::cout << "\n---- PRINTING THE SHORTEST ---- " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "\n---- PRINTING THE LONGEST ---- " << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		int tmpArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::vector<int> set(tmpArray, tmpArray + 10);
		sp.addSet(set.begin(), set.end());
		std::cout << "\n---- PRINTING AFTER ADDING 10 nbrs ---- " << std::endl;
		sp.print();
		std::cout << "\n---- PRINTING THE SHORTEST ---- " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "\n---- PRINTING THE LONGEST ---- " << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}