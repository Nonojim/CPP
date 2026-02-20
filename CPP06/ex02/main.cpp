/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:15:42 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 14:36:26 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*dynamic_cast is primarily used to perform “safe downcasting,” i.e.,
to determine whether an object is of a particular type in an inher
itance hierarchy. It is the only cast that cannot be performed us
ing the old-style syntax. It is also the only cast that may have a
significant runtime cost.*/

// dynamic_cast need the class to have a virtual fonction to get acess to runtime type
// information

Base *generate(void)
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "A generated" << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << "B generated" << std::endl;
		return (new B);
	}
	else if (random == 2)
	{
		std::cout << "C generated" << std::endl;
		return (new C);
	}
	std::cout << "A generated" << std::endl;
	return (new A);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A reference" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B reference" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C reference" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
}

int main(void)
{
	Base *unknown;

	unknown = generate();
	identify(unknown);
	identify(*unknown);
	delete (unknown);
	return (0);
};