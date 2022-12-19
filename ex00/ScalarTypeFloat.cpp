/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeFloat.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:09 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:03:21 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeFloat.hpp"
#include <sstream>

ScalarTypeFloat::ScalarTypeFloat(void) {

}

ScalarTypeFloat::ScalarTypeFloat(ScalarTypeFloat const &src) {

	(void) src;
}

ScalarTypeFloat::~ScalarTypeFloat(void) {

}

ScalarTypeFloat	&ScalarTypeFloat::operator=(ScalarTypeFloat const &src) {

	(void) src;
	return (*this);
}

ScalarType	*ScalarTypeFloat::createType(void) {

	return (new ScalarTypeFloat());
}

bool	ScalarTypeFloat::checkInvalidArgument(Scalar &type) {

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

void	ScalarTypeFloat::enterConversion(Scalar &type) {

	size_t	len;

	if (checkInvalidArgument(type)) {
		type.setT(TYPE_INVALID);
		return ;
	}
	len = type.getS().length();
	type.getS().erase(len - 1, 1);
	convert(type);
}

void	ScalarTypeFloat::convert(Scalar &type) {

	float				f;
	long				l;
	std::stringstream	ss(type.getS());

	ss >> f;
	type.setF(f);
	type.setStates(TYPE_FLT, TYPE_FLT);

	l = static_cast<long>(f);

	type.setC(static_cast<char>(f));
	if (l > std::numeric_limits<char>::max() || l < std::numeric_limits<char>::min())
		type.setStates(TYPE_CHAR, TYPE_IMPOSSIBLE);
	else if (l < ' ' || l > '~')
		type.setStates(TYPE_CHAR, TYPE_NONDISPLAYABLE);
	else
		type.setStates(TYPE_CHAR, TYPE_CHAR);

	type.setI(static_cast<int>(f));
	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		type.setStates(TYPE_INT, TYPE_IMPOSSIBLE);
	else
		type.setStates(TYPE_INT, TYPE_INT);

	type.setD(static_cast<double>(f));
	type.setStates(TYPE_DBL, TYPE_DBL);
}
