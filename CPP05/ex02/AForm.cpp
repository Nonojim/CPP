/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:00:03 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 13:42:23 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unnamed AForm"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string &name)
	: _name(name), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm constructor with name provided called" << std::endl;
}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _isSigned(0), _gradeToSign(Bureaucrat::validateGrade(gradeToSign)),
	  _gradeToExec(Bureaucrat::validateGrade(gradeToExec))
{
	std::cout << "AForm constructor with name and grades provided called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &src)
	: _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "Default AForm copy constructor called" << std::endl;

	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &c)
{
	std::string str;
	if (c.getAFormStatus())
		str = "The AForm is signed.";
	else
		str = "The AForm is not signed.";
	os << c.getName() << ", AForm grade to be signed " << c.getSignGrade()
	   << ", AForm grade to be execute " << c.getExecGrade() << "." << std::endl
	   << str;
	return (os);
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

unsigned int AForm::getSignGrade(void) const
{
	return (this->_gradeToSign);
}

unsigned int AForm::getExecGrade(void) const
{
	return (this->_gradeToExec);
}

bool AForm::getAFormStatus(void) const
{
	return (this->_isSigned);
}
void AForm::setAFormStatus(bool status)
{
	this->_isSigned = status;
}

const std::string AForm::getTarget(void) const
{
	return (this->_target);
}

void AForm::setTarget(std::string target)
{
	this->_target = target;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error : The grade of the bureaucrat must be higher or equal than the grade "
			"of the AForm.");
}

void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->getSignGrade())
		this->_isSigned = 1;
	else
		throw GradeTooLowException();
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Error : The form is not signed");
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > this->_gradeToExec)
		throw GradeTooLowException();
	executeAction();
}
