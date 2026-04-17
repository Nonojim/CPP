/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:29:14 by npederen          #+#    #+#             */
/*   Updated: 2026/04/17 21:03:13 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error ! Please follow example : ./RPN <RPN expression>"
				  << std::endl;
		return (1);
	}
	RPN rpn;
	rpn.solveExpression(argv[1]);
	return (0);
}