/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:00:17 by npederen          #+#    #+#             */
/*   Updated: 2026/01/28 19:18:30 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // https://www.geeksforgeeks.org/cpp/what-are-forward-declarations-in-c/

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExec;

	public:
		Form();
		Form(const std::string &name);
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExec);
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		const std::string getName(void) const;
		unsigned int getSignGrade(void) const;
		unsigned int getExecGrade(void) const;
		bool getFormStatus(void) const;
		void beSigned(const Bureaucrat &src);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &c);

#endif