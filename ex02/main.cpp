/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/12/04 10:08:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void)
{
	srand(time(NULL));
	switch(rand() % 3)
	{
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
		default: return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is class A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer is class B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer is class C" << std::endl;
}

void identifyReference(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference is class A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Reference is class B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "Reference is class C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int main (void)
{
	Base *base;

	base = generate();
	identify(base);
	identifyReference(*base);

	delete base;
	return (0);
}
