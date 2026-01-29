/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:15:49 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 15:02:34 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget("Default");
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << "ShrubberyCreationForm constructor with target provided called"
			  << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Default ShrubberyCreationForm copy constructor called" << std::endl;

	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->setAFormStatus(src.getAFormStatus());
		this->setTarget(src.getTarget());
	}
	return (*this);
}

// https://ascii.co.uk/art/tree
void ShrubberyCreationForm::executeAction() const
{
	const char *tree[] = {"            .        +          .      .          .   ",
						  "     .            _        .                    .     ",
						  "  ,              /;-._,-.____        ,-----.__        ",
						  " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,    ",
						  "  `                 \\   _|`\"=:_::.`.);  \\ __/ /       ",
						  "                      ,    `./  \\:. `.   )==-'  .     ",
						  "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           . ",
						  ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o         ",
						  "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .  ",
						  "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7 ",
						  "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/  ",
						  "              \\:  `  X` _| _,\\/'   .-'                ",
						  ".               \":._:`\\____  /:'  /      .           .",
						  "                    \\::.  :\\/: '  /              +    ",
						  "   .                 `.:.  /:'  }      .              ",
						  "           .           ):_(:;   \\           .         ",
						  "                      /:. _/ ,  |                     ",
						  "                   . (|::.     ,`                  .  ",
						  "     .                |::.    {\\                      ",
						  "                      |::.\\  \\ `.                     ",
						  "                      |:::(\\    |                     ",
						  "              O       |:::/{ }  |                  (o ",
						  "               )  ___/#\\::`/ (O \"==._____   O, (O  /` ",
						  "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~ ",
						  "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~     "};
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream outPutFile(fileName.c_str());
	int i = 0;
	while (i < 25)
	{
		outPutFile << tree[i] << " " << tree[i] << " " << tree[i] << std::endl;
		i++;
	}
	outPutFile.close();
}
