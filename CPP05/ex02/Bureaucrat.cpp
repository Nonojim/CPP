/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:56:40 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 13:55:49 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor with name provided called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	: _name(name), _grade(validateGrade(grade))
{
	std::cout << "Bureaucrat constructor with name and grade provided called"
			  << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Default Bureaucrat copy constructor called" << std::endl;

	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &c)
{
	os << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return (os);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

unsigned int Bureaucrat::validateGrade(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error : The grade must not be under 150 (the lowest)");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error : The grade must not exceed 1 (the highest).");
}

void Bureaucrat::decrGrade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

void Bureaucrat::decrGrade(unsigned int n)
{
	if ((this->_grade + n) <= 150)
		this->_grade += n;
	else
		throw GradeTooLowException();
}

void Bureaucrat::incrGrade(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::incrGrade(unsigned int n)
{
	if ((this->_grade - n) >= 1)
		this->_grade -= n;
	else
		throw GradeTooHighException();
}

void Bureaucrat::signForm(AForm &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << this->getName() << " signed " << src.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << src.getName() << " because "
				  << std::endl
				  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName()
				  << " because " << std::endl
				  << e.what() << std::endl;
	}
}
