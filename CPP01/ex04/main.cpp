/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:11:16 by npederen          #+#    #+#             */
/*   Updated: 2025/11/25 14:50:48 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	std::ifstream file;
	std::stringstream str;
	str << argv[1] << ".replace";
	std::ofstream file(str.str());
	file.open(argv[1]);
}