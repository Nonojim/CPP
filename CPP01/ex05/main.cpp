/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:32:19 by npederen          #+#    #+#             */
/*   Updated: 2025/11/26 20:10:20 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "input <DEBUG>" << std::endl;
	harl.complain("DEBUG");
	std::cout << "input <INFO>" << std::endl;
	harl.complain("INFO");
	std::cout << "input <WARNING>" << std::endl;
	harl.complain("WARNING");
	std::cout << "input <ERROR>" << std::endl;
	harl.complain("ERROR");
	std::cout << "input <badInput>" << std::endl;
	harl.complain("badInput");
}