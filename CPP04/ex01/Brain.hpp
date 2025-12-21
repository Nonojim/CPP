/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:26:24 by npederen          #+#    #+#             */
/*   Updated: 2025/12/21 12:51:51 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain &original);
		Brain &operator=(const Brain &c);
};

#endif