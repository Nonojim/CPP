/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:20:02 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:27:05 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie {

	private :
		const std::string name;
	public :
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void	announce(void) const;
};