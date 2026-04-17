/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:27:33 by npederen          #+#    #+#             */
/*   Updated: 2026/04/17 21:41:19 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src) : _stack(src._stack)
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_stack = src._stack;
	return (*this);
}

int RPN::isOperator(const std::string &str)
{
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (1);
	return (0);
}

double RPN::solveOperation(double a, double b, const std::string &token)
{
	if (token == "+")
		return (a + b);
	if (token == "-")
		return (a - b);
	if (token == "*")
		return (a * b);
	if (token == "/")
		return (a / b);
	return (0);
}

void RPN::solveExpression(const std::string &str)
{
	std::istringstream iss(str);
	std::string token;
	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (_stack.size() >= 2)
			{
				double b = _stack.top();
				_stack.pop();
				double a = _stack.top();
				_stack.pop();
				_stack.push(solveOperation(a, b, token));
			}
			else
			{
				std::cout << "Error" << std::endl;
				return;
			}
		}
		else
		{
			if (token >= "0" && token <= "9")
				_stack.push(atof(token.c_str()));
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}
