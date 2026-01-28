/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:00:03 by npederen          #+#    #+#             */
/*   Updated: 2026/01/28 19:18:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("unnamed form"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string &name)
	: _name(name), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form constructor with name provided called" << std::endl;
}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _isSigned(0), _gradeToSign(Bureaucrat::validateGrade(gradeToSign)),
	  _gradeToExec(Bureaucrat::validateGrade(gradeToExec))
{
	std::cout << "Form constructor with name and grades provided called" << std::endl;
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}

Form::Form(const Form &src)
	: _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "Default Form copy constructor called" << std::endl;

	*this = src;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &c)
{
	std::string str;
	if (c.getFormStatus())
		str = "The form is signed.";
	else
		str = "The form is not signed.";
	os << c.getName() << ", form grade to be signed " << c.getSignGrade()
	   << ", form grade to be execute " << c.getExecGrade() << "." << std::endl
	   << str;
	return (os);
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

unsigned int Form::getSignGrade(void) const
{
	return (this->_gradeToSign);
}

unsigned int Form::getExecGrade(void) const
{
	return (this->_gradeToExec);
}

bool Form::getFormStatus(void) const
{
	return (this->_isSigned);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error : The grade of the bureaucrat must be higher or equal than the grade "
			"of the form.");
}

void Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->getSignGrade())
		this->_isSigned = 1;
	else
		throw GradeTooLowException();
}