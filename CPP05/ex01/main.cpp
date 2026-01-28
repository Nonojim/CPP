/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:54:08 by npederen          #+#    #+#             */
/*   Updated: 2026/01/28 19:18:32 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout
	<< "\n---- Default constructor set to <unnamed name> and both grades to 1  ---- "
	<< std::endl;
	try
	{
		Form john;
		std::cout << john << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Constructor with name and both grades to 1  ---- " << std::endl;
	try
	{
		Form john("John");
		std::cout << john << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Constructor with name & set to the lowest rank(150) ---- "
			  << std::endl;
	try
	{
		Form maurice("Maurice", 150, 150);
		std::cout << maurice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Constructor with name and grades provided ----" << std::endl;
	try
	{
		Form jim("Jim", 1, 150);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Same but grades are out of range (200) ----" << std::endl;
	try
	{
		Form jim("Jim", 200, 200);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Same but grades are out of range (0) ----" << std::endl;
	try
	{
		Form jim("Jim", 0, 0);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Try to sign form grade (1) with Jim grade(150) ----"
			  << std::endl;
	try
	{
		Bureaucrat jim("Jim", 150);
		std::cout << jim << std::endl;
		Form liquidation("Liquidation judiciaire", 1, 1);
		std::cout << liquidation << std::endl;
		liquidation.beSigned(jim);
		std::cout << liquidation << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Jim(1) will sign form(150) ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 1);
		std::cout << jim << std::endl;
		Form tP("Tp purchase order", 150, 150);
		std::cout << tP << std::endl;
		jim.signForm(tP);
		std::cout << tP << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Jim(150) will sign form(1) ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 150);
		std::cout << jim << std::endl;
		Form liquidation("Liquidation judiciaire", 1, 1);
		jim.signForm(liquidation);
		std::cout << liquidation << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}