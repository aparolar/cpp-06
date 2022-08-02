/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/02 11:28:18 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string name;
	int			value;
	float		posx;
	float		posy;
};

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data 		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

void		printDataValues(Data *ptr)
{
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "value: " << ptr->value << std::endl;
	std::cout << "posx: " << ptr->posx << std::endl;
	std::cout << "posy: " << ptr->posy << std::endl;
}

int main(void)
{
	Data 		data;
	Data		*data2;
	uintptr_t	ptr;

	data.name = "Circle";
	data.value = 66;
	data.posx = 55.0f;
	data.posy = 105.0f;
	
	std::cout << "Printing Data values" << std::endl;
	printDataValues(&data);
	std::cout << "serializing to *ptr" << std::endl;
	ptr = serialize(&data);
	std::cout << "deserealize from *ptr" << std::endl;
	data2 = deserialize(ptr);
	std::cout << "Printing Data2 values" << std::endl;
	printDataValues(data2);

	return (0);
}
