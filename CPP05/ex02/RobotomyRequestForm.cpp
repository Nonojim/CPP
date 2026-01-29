/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:31:34 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 15:24:17 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget("Default");
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
	std::cout << "RobotomyRequestForm constructor with target provided called"
			  << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Default RobotomyRequestForm copy constructor called" << std::endl;

	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->setAFormStatus(src.getAFormStatus());
		this->setTarget(src.getTarget());
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "BRRRRRRRRR BRRRRRRRRRR PATAPIM " << this->getTarget() << " has been robotomized successfully 50 %of the time." << std::endl;
		else std::cout
				  << this->getTarget() << " robotomy failed hard to tell if u are lucky are not." << std::endl;
}
