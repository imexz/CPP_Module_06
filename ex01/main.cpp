/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:16:40 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 18:29:59 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main(void) {

	uintptr_t	uintptr;
	Data		*data = new Data();
	Data		*data_reinterp;

	data->x = 42;
	uintptr = serialize(data);
	std::cout << "uintptr_t value: " << uintptr << std::endl;
	data_reinterp = deserialize(uintptr);

	std::cout << "data address:          " << data << std::endl;
	std::cout << "data_reinterp address: " << data_reinterp << std::endl;
	std::cout << "data->x          = " <<data->x << std::endl;
	std::cout << "data_reinterp->x = " << data_reinterp->x << std::endl;

	delete data;
	return (0);
}