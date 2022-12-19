/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:17:54 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 06:31:05 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"
#include "ScalarTypeParse.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Invalid amount of arguments" << std::endl;
		return (1);
	}
	Scalar	scalar(argv[1]);

	scalar.transitionToType(new ScalarTypeParse());
	std::cout << scalar << std::endl;
	return (0);
}
