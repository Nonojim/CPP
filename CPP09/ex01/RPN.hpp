/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:27:41 by npederen          #+#    #+#             */
/*   Updated: 2026/04/17 15:42:58 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<double> _stack;

	public:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
};

#endif