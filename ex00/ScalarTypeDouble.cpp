/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeDouble.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:12 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:03:41 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeDouble.hpp"
#include <sstream>

ScalarTypeDouble::ScalarTypeDouble(void) {

}

ScalarTypeDouble::ScalarTypeDouble(ScalarTypeDouble const &src) {

	(void) src;
}

ScalarTypeDouble::~ScalarTypeDouble(void) {

}

ScalarTypeDouble	&ScalarTypeDouble::operator=(ScalarTypeDouble const &src) {

	(void) src;
	return (*this);
}

ScalarType	*ScalarTypeDouble::createType(void) {

	return (new ScalarTypeDouble());
}

bool	ScalarTypeDouble::checkInvalidArgument(Scalar &type) {

	std::string	s = type.getS();

	for (size_t	i = 0; i < s.length(); i++) {
		if ((s[i] == '-' || s[i] == '+') && i != 0 && s[i - 1] != 'e') {
			return (true);
		}
		if (s[i] == '.' && s.find_first_of('e') < i)
			return (true);
		if (s[i] == 'e' && s[i + 1] == '\0')
			return (true);
	}
	return (false);
}

void	ScalarTypeDouble::enterConversion(Scalar &type) {

	if (checkInvalidArgument(type)) {
		type.setT(TYPE_INVALID);
		return ;
	}
	convert(type);
}

void	ScalarTypeDouble::convert(Scalar &type) {

	double				d;
	long				l;
	std::stringstream	ss(type.getS());

	ss >> d;
	type.setD(d);
	type.setStates(TYPE_DBL, TYPE_DBL);

	l = static_cast<long>(d);

	type.setC(static_cast<char>(d));
	if (l > std::numeric_limits<char>::max() || l < std::numeric_limits<char>::min())
		type.setStates(TYPE_CHAR, TYPE_IMPOSSIBLE);
	else if (l < ' ' || l > '~')
		type.setStates(TYPE_CHAR, TYPE_NONDISPLAYABLE);
	else
		type.setStates(TYPE_CHAR, TYPE_CHAR);

	type.setI(static_cast<int>(d));
	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		type.setStates(TYPE_INT, TYPE_IMPOSSIBLE);
	else
		type.setStates(TYPE_INT, TYPE_INT);

	type.setF(static_cast<float>(d));
	type.setStates(TYPE_FLT, TYPE_FLT);
}
