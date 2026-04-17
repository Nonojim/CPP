/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:27:41 by npederen          #+#    #+#             */
/*   Updated: 2026/04/17 21:30:14 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		std::stack<double> _stack;
		int isOperator(const std::string &str);
		double solveOperation(double a, double b, const std::string &token);

	public:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		void solveExpression(const std::string &str);
};

#endif