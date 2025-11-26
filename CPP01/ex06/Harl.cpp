/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:32:22 by npederen          #+#    #+#             */
/*   Updated: 2025/11/26 21:02:21 by npederen         ###   ########.fr       */
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

// the comment </* fall through */> is for the compiler to tell him its intentionnal
void Harl::complain(std::string level)
{

	int i = -1;
	if (level == "DEBUG")
		i = 0;
	else if (level == "INFO")
		i = 1;
	else if (level == "WARNING")
		i = 2;
	else if (level == "ERROR")
		i = 3;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fn[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	switch (i)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*fn[i])();
		std::cout << std::endl;
		/* fall through */

	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*fn[i])();
		std::cout << std::endl;
		/* fall through */

	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*fn[i])();
		std::cout << std::endl;
		/* fall through */

	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*fn[i])();
		std::cout << std::endl;
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}