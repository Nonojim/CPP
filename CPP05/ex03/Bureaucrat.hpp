/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:56:39 by npederen          #+#    #+#             */
/*   Updated: 2026/01/29 13:44:47 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		const std::string getName(void) const;
		unsigned int getGrade(void) const;
		static unsigned int validateGrade(unsigned int grade);
		void decrGrade(void);
		void decrGrade(unsigned int n);
		void incrGrade(void);
		void incrGrade(unsigned int n);
		void signForm(AForm &src);
		void executeForm(AForm const &form) const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &c);

#endif