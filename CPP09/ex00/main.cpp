/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:12:28 by npederen          #+#    #+#             */
/*   Updated: 2026/04/15 18:43:23 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: could not open file !" << std::endl;
		return (1);
	}

	// try
	//{
	BitcoinExchange btc;
	btc.loadDb("data.csv");
	// btc.processInputFile(argv[1]);
	//}
	// catch (const std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//	return (1);
	//}
	return (0);
}
