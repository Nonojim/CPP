/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:34:06 by npederen          #+#    #+#             */
/*   Updated: 2025/11/22 17:55:14 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account :: Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _nbAccounts << ";amount:"
		<< _amount << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account :: ~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;

}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	//how many sec since unix
	time_t now = time(NULL);
	//struct containing a calendar date
	tm* t = localtime(&now);
	char buffer[18];
	//formating date YearMonthDay_HourMinute_Seconde
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", t);
	std::cout << buffer;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:"
		<< _amount << ";deposit:" << deposit << ";amount:"
		<< _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:" << withdrawal << ";amount:"
			<< _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (0);
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:" << "refused" << std::endl;
		return (1);
	}
}
