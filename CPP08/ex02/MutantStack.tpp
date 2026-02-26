/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:58:48 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 20:21:16 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T> MutantStack<T>::MutantStack()
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T> MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor called" << std::endl;
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	(void)src;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

#endif