/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:11:05 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 13:39:47 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // https://www.geeksforgeeks.org/cpp/what-are-forward-declarations-in-c/

class AForm
{
	private:
		const std::string _name;
		std::string _target;
		bool _isSigned;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExec;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string &name);
		AForm(const std::string &name, unsigned int gradeToSign,
			  unsigned int gradeToExec);
		virtual ~AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		const std::string getName(void) const;
		unsigned int getSignGrade(void) const;
		unsigned int getExecGrade(void) const;
		bool getAFormStatus(void) const;
		void setAFormStatus(bool status);
		const std::string getTarget(void) const;
		void setTarget(std::string target);
		void beSigned(const Bureaucrat &src);
		void execute(Bureaucrat const &executor) const;
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &c);

#endif