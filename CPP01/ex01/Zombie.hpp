/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:53:37 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 23:19:50 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void setName(std::string name);
		std::string getName(void);
		void announce(void) const;
};