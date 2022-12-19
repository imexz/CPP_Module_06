/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:09:31 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/06 18:02:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"

ScalarType::ScalarType(void) {

}

ScalarType::ScalarType(ScalarType const &src) {

	(void) src;
}

ScalarType::~ScalarType(void) {

}

ScalarType	&ScalarType::operator=(ScalarType const &src) {

	(void) src;
	return (*this);
}
