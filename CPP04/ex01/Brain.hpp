/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:26:24 by npederen          #+#    #+#             */
/*   Updated: 2026/01/13 19:35:54 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain &original);
		Brain &operator=(const Brain &c);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string const &str);
};

#endif