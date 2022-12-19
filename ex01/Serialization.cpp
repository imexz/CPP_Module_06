/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:11:58 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 18:23:55 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Data::Data(void) : x(0), y(0), z(0) {

}

Data::Data(Data const &src) : x(src.x), y(src.y), z(src.z) {

}

Data::~Data(void) {

}

Data	&Data::operator=(Data const &src) {

	x = src.x;
	y = src.y;
	z = src.z;
	return (*this);
}

uintptr_t	serialize(Data *ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data*>(raw));
}


