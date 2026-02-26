/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:19:09 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 21:42:25 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T> void easyfind(T &container, int value)
{
	if (std::find(container.begin(), container.end(), value) != container.end())
	{
		std::cout << "Value found" << std::endl;
	}
	else
	{
		throw NoValueFound();
	}
}

#endif