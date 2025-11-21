/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:29:45 by npederen          #+#    #+#             */
/*   Updated: 2025/11/21 12:30:17 by npederen         ###   ########.fr       */
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
		Contact contacts[8];
		int count; 
	public:
		PhoneBook(void);
		~PhoneBook(void);
	
};

#endif