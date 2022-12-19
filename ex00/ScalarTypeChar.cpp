/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeChar.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:05 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:02:51 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeChar.hpp"

ScalarTypeChar::ScalarTypeChar(void) {

}

ScalarTypeChar::ScalarTypeChar(ScalarTypeChar const &src) {

	(void) src;
}

ScalarTypeChar::~ScalarTypeChar(void) {

}

ScalarTypeChar	&ScalarTypeChar::operator=(ScalarTypeChar const &src) {

	(void) src;
	return (*this);
}

ScalarType	*ScalarTypeChar::createType(void) {

	return (new ScalarTypeChar());
}

void	ScalarTypeChar::enterConversion(Scalar &type) {

	type.setC(type.getS()[0]);
	type.setStates(TYPE_CHAR, TYPE_CHAR);
	if (type.getC() < ' ' || type.getC() > '~') {
		type.setStates(TYPE_CHAR, TYPE_NONDISPLAYABLE);
	}
	convert(type);
}

void	ScalarTypeChar::convert(Scalar &type) {

	char	c;

	c = type.getC();
	type.setI(static_cast<int>(c));
	type.setStates(TYPE_INT, TYPE_INT);
	type.setF(static_cast<float>(c));
	type.setStates(TYPE_FLT, TYPE_FLT);
	type.setD(static_cast<double>(c));
	type.setStates(TYPE_DBL, TYPE_DBL);
}
