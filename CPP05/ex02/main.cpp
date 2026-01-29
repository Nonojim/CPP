/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:54:08 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 16:07:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "\n---- John can sign & execute the shrubbery form ---- " << std::endl;
	try
	{
		Bureaucrat john("John", 137);
		std::cout << john << std::endl;
		ShrubberyCreationForm form("forest");
		std::cout << form << std::endl;
		john.signForm(form);
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- John cannot sign the form ---- " << std::endl;
	try
	{
		Bureaucrat john("John", 121);
		std::cout << john << std::endl;
		PresidentialPardonForm form("Nolan");
		std::cout << form << std::endl;
		john.signForm(form);
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- John cannot execute the form ---- " << std::endl;
	try
	{
		Bureaucrat john("John", 20);
		std::cout << john << std::endl;
		PresidentialPardonForm form;
		std::cout << form << std::endl;
		john.signForm(form);
		john.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Form sign and execute by AForm methods ---- " << std::endl;
	try
	{
		Bureaucrat john("John", 20);
		std::cout << john << std::endl;
		RobotomyRequestForm form("Tung Tung Tsaour");
		form.beSigned(john);
		std::cout << form << std::endl;
		form.execute(john);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//	std::cout << "\n---- Uncomment to see that form cannot exec by themselves ---- "
	//			  << std::endl;
	//	try
	//	{
	//		RobotomyRequestForm form;
	//		std::cout << form << std::endl;
	//		form.execute();
	//	}
	//	catch (const std::exception &e)
	//	{
	//		std::cerr << e.what() << std::endl;
	//	}

	return (0);
}