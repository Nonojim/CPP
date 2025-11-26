/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:32:22 by npederen          #+#    #+#             */
/*   Updated: 2025/11/26 20:07:20 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor called" << std::endl;
	;
}

Harl::~Harl(void)
{
	std::cout << "Destructor called" << std::endl;
	;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put "
				 "enough bacon in my burger ! If you did, I wouldnt be asking for more !"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming "
				 "for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now."
			  << std::endl;
}

void Harl::complain(std::string level)
{

	int i = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fn[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	(void)fn;
	while (level != levels[i] && i < 4)
		i++;
	if (i < 4)
		(this->*fn[i])();
}