/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:54:08 by npederen          #+#    #+#             */
/*   Updated: 2026/01/28 15:56:27 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	std::cout << "\n---- Default constructor set to John doe and grade : 150 ---- "
			  << std::endl;
	try
	{
		Bureaucrat john;
		std::cout << john << std::endl;
		john.decrGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Constructor with name set to the lowest rank(150) ---- "
			  << std::endl;
	try
	{
		Bureaucrat maurice("Maurice");
		maurice.incrGrade();
		std::cout << "Maurice is promoted." << std::endl;
		std::cout << maurice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Constructor with name and grade provided ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 1);
		jim.decrGrade();
		std::cout << "Jim is demoted." << std::endl;
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Same but grade is out of range (200) ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 200);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Same but grade is out of range (0) ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 0);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Jim will try to promote at grade 1 ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 1);
		jim.incrGrade();
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Jim will try to demote at grade 150 ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim");
		std::cout << jim << std::endl;
		jim.decrGrade();
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Bonus : Jim will demote at grade 150 from 100 ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 100);
		jim.decrGrade(50);
		std::cout << "Jim is demoted." << std::endl;
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Bonus : Jim will promote at grade 1 from 150 ----" << std::endl;
	try
	{
		Bureaucrat jim("Jim");
		std::cout << jim << std::endl;
		jim.incrGrade(149);
		std::cout << "Jim is promoted." << std::endl;
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}