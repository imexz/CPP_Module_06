/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeInt.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:07 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:03:05 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeInt.hpp"
#include <sstream>

ScalarTypeInt::ScalarTypeInt(void) {

}

ScalarTypeInt::ScalarTypeInt(ScalarTypeInt const &src) {

	(void) src;
}

ScalarTypeInt::~ScalarTypeInt(void) {

}

ScalarTypeInt	&ScalarTypeInt::operator=(ScalarTypeInt const &src) {

	(void) src;
	return (*this);
}

ScalarType	*ScalarTypeInt::createType(void) {

	return (new ScalarTypeInt());
}

void	ScalarTypeInt::enterConversion(Scalar &type) {

	std::stringstream	ss(type.getS());
	long				l;

	ss >> l;
	if (ss.fail() || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
		for (int i = 0; i < 4; i++) {
			type.setStates(i, TYPE_IMPOSSIBLE);
		}
		return ;
	}
	type.setI(l);
	type.setStates(TYPE_INT, TYPE_INT);
	convert(type);
}

void	ScalarTypeInt::convert(Scalar &type) {

	int	i;

	i = type.getI();
	type.setC(static_cast<char>(i));
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		type.setStates(TYPE_CHAR, TYPE_IMPOSSIBLE);
	else if (i < ' ' || i > '~')
		type.setStates(TYPE_CHAR, TYPE_NONDISPLAYABLE);
	type.setF(static_cast<float>(i));
	type.setStates(TYPE_FLT, TYPE_FLT);
	type.setD(static_cast<double>(i));
	type.setStates(TYPE_DBL, TYPE_DBL);
}
