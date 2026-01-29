/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:07:57 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 16:05:10 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget("Default");
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget(target);
	std::cout << "PresidentialPardonForm constructor with target provided called"
			  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Default PresidentialPardonForm copy constructor called" << std::endl;

	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->setAFormStatus(src.getAFormStatus());
		this->setTarget(src.getTarget());
	}
	return (*this);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
