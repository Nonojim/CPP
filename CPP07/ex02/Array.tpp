/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:06:39 by npederen          #+#    #+#             */
/*   Updated: 2026/02/20 21:05:11 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T> Array<T>::Array()
{
	_data = NULL;
	_size = 0;
}

template <typename T> Array<T>::Array(unsigned int n)
{
	_data = new T[n];
	_size = n;
}

template <typename T> Array<T>::Array(const Array &src)
{
	_size = src._size;
	if (_size == 0)
		_data = NULL;
	else
	{
		_data = new T[_size];
		unsigned int i = 0;
		while (i < _size)
		{
			_data[i] = src._data[i];
			i++;
		}
	}
}

template <typename T> Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _data;

		_size = src._size;

		if (_size == 0)
			_data = NULL;
		else
		{
			_data = new T[_size];
			unsigned int i = 0;
			while (i < _size)
			{
				_data[i] = src._data[i];
				i++;
			}
		}
	}
	return (*this);
}

template <typename T> Array<T>::~Array()
{
	delete[] _data;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOOR();
	return (_data[index]);
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw IndexOOR();
	return (_data[index]);
}

template <typename T> unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T> void print(Array<T> &arr)
{
	unsigned int i = 0;
	while (i < arr.size())
	{
		std::cout << arr[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

#endif