/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:13:06 by npederen          #+#    #+#             */
/*   Updated: 2025/11/18 13:39:54 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
		if (argc == 1)
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		else
		{
			int i = 1;
			while (argv[i])
			{
				int j = 0;
				while (argv[i][j])
				{
					std::cout << (char)std::toupper(argv[i][j++]);
				}
				i++;
			}
			std::cout << std::endl;
		}
	return (0);
}