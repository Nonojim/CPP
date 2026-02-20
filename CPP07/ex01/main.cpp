/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:17:42 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 19:54:48 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4};
	iter(arr, 4, print<int>);
	iter(arr, 4, increment<int>);
	std::cout << std::endl;
	iter(arr, 4, print<int>);
	const int arr2[] = {10, 20, 30};
	std::cout << std::endl;
	iter(arr2, 3, print<int>);
	std::string arr3[] = {"Sirius 35 DS"};
	iter(arr3, 1, print<std::string>);

	return (0);
}