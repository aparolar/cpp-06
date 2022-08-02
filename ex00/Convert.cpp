/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:07:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/02 09:42:01 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(const char *value)
{
	_value = std::atof(value);
}

void Convert::toChar()
{
	std::cout << "char: ";
	if (_value < CHAR_MIN || _value > CHAR_MAX)
		std::cout << "Impossible";
	else if (_value < DISPLAY_MIN || _value > DISPLAY_MAX)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(_value) << "'";
	std::cout << std::endl;
}

void Convert::toInt()
{
	std::cout << "int: ";
	if (_value >= INT_MIN && _value <= INT_MAX)
		std::cout << static_cast<int>(_value);
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Convert::toFloat()
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_value) << "f";
	std::cout << std::endl;
}

void Convert::toDouble()
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << _value;
	std::cout << std::endl;
}