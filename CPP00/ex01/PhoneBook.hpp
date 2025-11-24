/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:29:45 by npederen          #+#    #+#             */
/*   Updated: 2025/11/24 18:04:16 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		count;
		int		size;
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	addToPhoneBook(std::string firstName, std::string lastName,
				std::string nickName, std::string secret, std::string number);
		void	showContacts(void);
		int		getCounter(void);
		Contact &getContact(int index);
		void	showDataContact(int index);

};

#endif