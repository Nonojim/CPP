/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:12:28 by npederen          #+#    #+#             */
/*   Updated: 2026/04/16 21:53:26 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: input file missing !" << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	btc.loadDb("data.csv");
	btc.getExcRate(argv[1]);
	return (0);
}
