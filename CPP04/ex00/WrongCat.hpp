/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:10:08 by npederen          #+#    #+#             */
/*   Updated: 2025/12/18 22:16:21 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat &operator=(const WrongCat &c);
		void makeSound(void) const;
};

#endif