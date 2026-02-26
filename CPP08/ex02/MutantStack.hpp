/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:30:25 by npederen          #+#    #+#             */
/*   Updated: 2026/02/26 20:17:06 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{

	public:
		MutantStack();
		MutantStack(unsigned int n);
		~MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack &operator=(const MutantStack &src);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		};
		iterator end()
		{
			return this->c.end();
		};
};

#include "MutantStack.tpp"

#endif