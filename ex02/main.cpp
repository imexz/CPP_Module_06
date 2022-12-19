/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:39:24 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 19:47:14 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <exception>

Base	*generate(void) {

	srand(time(NULL));
	int	randIdx = rand() % 3;
	switch (randIdx)
	{
	case 0:
		std::cout << "created A" << std::endl;
		return (new A());
	case 1:
		std::cout << "created B" << std::endl;
		return (new B());
	default:
		std::cout << "created C" << std::endl;
		return (new C());
	}
}

void	identify(Base *p) {

	try {

		A	*a;
		B	*b;
		C	*c;

		a = dynamic_cast<A*>(p);
		if (a != NULL) {
			std::cout << "A" << std::endl;
		}
		b = dynamic_cast<B*>(p);
		if (b != NULL) {
			std::cout << "B" << std::endl;
		}
		c = dynamic_cast<C*>(p);
		if (c != NULL) {
			std::cout << "C" << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	identify(Base &p) {

	try {
		A &a = dynamic_cast<A&>(p);
		(void) a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void) b;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void) c;
			}
			catch (std::exception &e) {
				std::cout << "Exception: " << e.what() << std::endl;
				return ;
			}
			std::cout << "C" << std::endl;
			return ;
	}
		std::cout << "B" << std::endl;
		return ;
	}
	std::cout << "A" << std::endl;
}

int	main(void) {

	Base	*b;

	b = generate();
	identify(b);
	identify(*b);

	delete b;
	return (0);
}
