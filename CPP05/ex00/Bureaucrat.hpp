/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:56:39 by npederen          #+#    #+#             */
/*   Updated: 2026/01/28 15:53:10 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
		Bureaucrat(const Bureaucrat &original);
		Bureaucrat &operator=(const Bureaucrat &original);
		const std::string getName(void) const;
		unsigned int getGrade(void) const;
		unsigned int validateGrade(unsigned int grade) const;
		void decrGrade(void);
		void decrGrade(unsigned int n);
		void incrGrade(void);
		void incrGrade(unsigned int n);
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