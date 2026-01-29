/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:57:27 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 17:16:53 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm *(*FormCreator)(std::string const &);

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Default Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Default Intern copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

static AForm *createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) const
{
	static const std::string names[] = {"shrubbery creation", "robotomy request",
										"presidential pardon"};
	static const FormCreator creators[] = {&createShrubbery, &createRobotomy,
										   &createPresidential};
	int i = 0;
	while (i < 3)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (creators[i](target));
		}
		i++;
	}

	throw FormBadName();
	return (NULL);
}

const char *Intern::FormBadName::what() const throw()
{
	return ("Error : formName provided is not supported. Try <shrubbery creation> "
			"<robotomy request> <presidential pardon>");
}
