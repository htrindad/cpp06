/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:36:47 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/13 18:53:26 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <exception>
#include "A.h"
#include "B.h"
#include "C.h"

Base	*generate()
{
	const int	r = std::rand() % 3;

	switch (r)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cerr << "Something went wrong\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (std::exception &e) { std::cerr << "This is not type A\n"; }
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (std::exception &e) { std::cerr << "This is not type B\n"; }
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (std::exception &e) { std::cerr << "This is not type C\n"; }
}

int	main()
{
	Base	*stuff[11];

	for (std::size_t i = 0; i < 10; i++)
		stuff[i] = generate();
	stuff[10] = NULL;
	for (std::size_t i = 0; i < 10; i++)
		identify(stuff[i]);
	std::cout << '\n';
	for (std::size_t i = 0; i < 10; i++)
		identify(*stuff[i]);
	delete[] stuff;
	return 0;
}
