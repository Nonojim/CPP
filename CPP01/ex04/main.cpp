/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:11:16 by npederen          #+#    #+#             */
/*   Updated: 2025/12/19 16:50:57 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string search_and_replace(std::string infileContent, std::string to_search,
							   std::string to_replace)
{
	size_t index = 0;
	while ((index = infileContent.find(to_search, index)) != std::string::npos)
	{
		infileContent.erase(index, to_search.length());
		infileContent.insert(index, to_replace);
		index += to_replace.length();
	}
	return (infileContent);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '\0' || argv[3][0] == '\0')
		{
			std::cout << "Please do not enter empty strings" << std::endl;
			return (1);
		}
		std::ifstream infile;
		infile.open(argv[1]);
		if (!infile.is_open())
		{
			std::cerr << "This inputFile cannot be open : " << argv[1] << std::endl;
			return (1);
		}
		std::stringstream str;
		str << argv[1] << ".replace";
		std::ofstream outfile(str.str().c_str());
		if (!outfile.is_open())
		{
			std::cerr << "The outpout file cannot be open" << std::endl;
			return (1);
		}
		// std::istreambuf_iterator<char>(infile) point to the first char of the file
		// std::istreambuf_iterator<char>() a sentinel to know when read stop (EOF)
		// double parenthesis on first iterator cause compiler think its a function
		// without them
		std::string infileContent((std::istreambuf_iterator<char>(infile)),
								  std::istreambuf_iterator<char>());
		outfile << search_and_replace(infileContent, argv[2], argv[3]);
	}
	else
	{
		std::cerr << "Wrong number of arguments !" << std::endl
				  << "Please follow example : ./replaceString <filename> <strtoreplace> "
					 "<replacementstr>"
				  << std::endl;
		return (1);
	}
	return (0);
}