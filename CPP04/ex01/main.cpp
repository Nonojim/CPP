/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:46:48 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 19:54:15 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int arraySize = 4;
	Animal *animals[arraySize];

	std::cout << "=== Creating Animals ===" << std::endl;
	for (int i = 0; i < arraySize; ++i)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Testing makeSound ===" << std::endl;
	for (int i = 0; i < arraySize; ++i)
		animals[i]->makeSound();

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog *originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I want bones");

	Dog copyDog(*originalDog);
	copyDog.getBrain()->setIdea(0, "I want meat");

	std::cout << "Original Dog idea: " << originalDog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Copy Dog idea:     " << copyDog.getBrain()->getIdea(0) << std::endl;

	Cat *originalCat = new Cat();
	originalCat->getBrain()->setIdea(0, "I want fish");

	Cat copyCat(*originalCat);
	copyCat.getBrain()->setIdea(0, "I want milk");

	std::cout << "Original Cat idea: " << originalCat->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Copy Cat idea:     " << copyCat.getBrain()->getIdea(0) << std::endl;

	delete originalDog;
	delete originalCat;

	std::cout << "\n=== Deleting Animals ===" << std::endl;
	for (int i = 0; i < arraySize; ++i)
		delete animals[i];

	return 0;
}
