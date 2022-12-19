/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeParse.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:47:33 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 16:57:15 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypeParse.hpp"
#include "ScalarTypeChar.hpp"
#include "ScalarTypeInt.hpp"
#include "ScalarTypeFloat.hpp"
#include "ScalarTypeDouble.hpp"

ScalarTypeParse::ScalarTypeParse(void) {

}

ScalarTypeParse::ScalarTypeParse(ScalarTypeParse const &src) {

	(void) src;
}

ScalarTypeParse::~ScalarTypeParse(void) {

}

ScalarTypeParse	&ScalarTypeParse::operator=(ScalarTypeParse const &src) {

	(void) src;
	return (*this);
}

ScalarType	*ScalarTypeParse::createType(void) {

	return (new ScalarTypeParse());
}

void	ScalarTypeParse::skipWhitespaces(Scalar &type) {

	const char	*ws = "\t\n\r\f\v";

	type.getS() = trim(type.getS(), ws);
	if (type.getS().find_first_not_of(" ") == std::string::npos)
		type.getS().erase(0, type.getS().length() - 1);
	else
		type.getS() = trim(type.getS(), " ");
}

void	ScalarTypeParse::enterConversion(Scalar &type) {

	std::string	s;
	size_t	pos;

	skipWhitespaces(type);
	s = type.getS();
	if (checkSpecialCases(type)) {
		if (type.getT() == TYPE_FLT)
			type.transitionToType(new ScalarTypeFloat());
		else if (type.getT() == TYPE_DBL)
			type.transitionToType(new ScalarTypeDouble());
	}
	else if (s.length() == 1 && s.find_first_not_of("0123456789") == 0) {
		type.setT(TYPE_CHAR);
		type.transitionToType(new ScalarTypeChar());
	}
	else if (s.find_first_not_of("-0123456789") == std::string::npos) {
		pos = s.find_first_of("-");
		if ((pos != std::string::npos && pos != 0) || pos != s.find_last_of("-")) {
			return ;
		}
		type.setT(TYPE_INT);
		type.transitionToType(new ScalarTypeInt());
	}
	else if (s.find_first_not_of("-+0123456789.e") == std::string::npos) {
		if (s.find_first_of(".") != s.find_last_of(".") \
			|| s.find_first_of("e") != s.find_last_of("e")) {
				return ;
		}
		type.setT(TYPE_DBL);
		type.transitionToType(new ScalarTypeDouble());
	}
	else if (s.find_first_not_of("-+0123456789.ef") == std::string::npos \
		&& s.find_first_of("f") != std::string::npos) {
		pos = s.find_first_of("f");
		if (pos  != s.length() - 1 || pos != s.find_last_of("f") \
			|| s.find_first_of(".") != s.find_last_of(".") \
			|| s.find_first_of("e") != s.find_last_of("e")) {
				return ;
		}
		type.setT(TYPE_FLT);
		type.transitionToType(new ScalarTypeFloat());
	}
}

void	ScalarTypeParse::convert(Scalar &type) {

	(void) type;
}

bool	ScalarTypeParse::checkSpecialCases(Scalar &type) {

	std::string	input = type.getS();
	if (input == "-inff" ||  input == "+inff" || input == "nanf") {
		type.setT(TYPE_FLT);
		type.setStates(0, TYPE_IMPOSSIBLE);
		type.setStates(1, TYPE_IMPOSSIBLE);
		type.setStates(2, TYPE_FLT);
		type.setStates(3, TYPE_DBL);
		return (true);
	}
	else if (input == "-inf" || input == "+inf" || input == "nan") {
		type.setT(TYPE_DBL);
		type.setStates(0, TYPE_IMPOSSIBLE);
		type.setStates(1, TYPE_IMPOSSIBLE);
		type.setStates(2, TYPE_FLT);
		type.setStates(3, TYPE_DBL);
		return (true);
	}
	return (false);
}
