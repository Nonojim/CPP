/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:34:06 by npederen          #+#    #+#             */
/*   Updated: 2025/11/22 17:20:27 by npederen         ###   ########.fr       */
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
	std::cout << "[19920104_091532]" << " index:" << _nbAccounts << ";amount:"
		<< _amount << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account :: ~Account(void)
{
	std::cout << "[19920104_091532]" << " index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;

}

void Account::displayAccountsInfos()
{
	std::cout << "[19920104_091532]" << " accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
	std::cout << "[19920104_091532]" << " index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "[19920104_091532]" << " index:" << _accountIndex << ";p_amount:"
		<< _amount << ";deposit:" << deposit << ";amount:"
		<< _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;

}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "[19920104_091532]" << " index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:" << withdrawal << ";amount:"
			<< _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (0);
	}
	else
	{
		std::cout << "[19920104_091532]" << " index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:" << "refused" << std::endl;
		return (1);
	}

}
