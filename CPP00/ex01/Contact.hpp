/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:29:45 by npederen          #+#    #+#             */
/*   Updated: 2025/11/21 18:38:28 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();
		std::string	truncateStrTen(std::string str);
		void		displayContactTab(void);
		void		displayContactData(void);
		void		addContact(std::string firstName, std::string lastName,
		std::string nickName, std::string secret, std::string number, int index);

};

#endif