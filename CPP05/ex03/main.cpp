/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:54:08 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 17:28:21 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout
	<< "\n---- John can sign & execute the robotomy form created by an intern ---- "
	<< std::endl;
	try
	{
		Bureaucrat john("john", 1);
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		std::cout << john << std::endl;
		john.signForm(*rrf);
		john.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

std::cout
	<< "\n---- wrong nameForm provided to the intern ---- "
	<< std::endl;
	try
	{
		Bureaucrat john("john", 18);
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("vacation request", "Nolan");
		std::cout << *rrf << std::endl;
		std::cout << john << std::endl;
		john.signForm(*rrf);
		john.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}