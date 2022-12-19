/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:57:34 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:02:25 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"
#include "ScalarTypeParse.hpp"
#include "ScalarTypeChar.hpp"
#include "ScalarTypeInt.hpp"
#include "ScalarTypeFloat.hpp"
#include "ScalarTypeDouble.hpp"
#include <sstream>
#include <cmath>

Scalar::Scalar(void) : _s(""), _type(new ScalarTypeParse()), _t(TYPE_INVALID), _c(0),
	_i(0), _f(0), _d(0) {

	for (int i = 0; i < 4; i++) {
		_states[i] = i;
	}
}

Scalar::Scalar(std::string s) : _s(s), _type(new ScalarTypeParse()), _t(TYPE_INVALID),_c(0),
	_i(0), _f(0), _d(0) {

	for (int i = 0; i < 4; i++) {
		_states[i] = i;
	}
}

Scalar::Scalar(Scalar const &src) {

	std::string	types[] = {
		"ScalarTypeChar", "ScalarTypeInt", "ScalarTypeFloat", "ScalarTypeDouble", "ScalarTypeParse"
	};
	ScalarType	*(*createScalarType[]) (void) = {
		ScalarTypeChar::createType,
		ScalarTypeInt::createType,
		ScalarTypeFloat::createType,
		ScalarTypeDouble::createType,
		ScalarTypeParse::createType
	};
	_s = src._s;
	std::string	type = typeid(src).name();
	for (size_t i = 0; i < (sizeof(types) / sizeof(types[0])); i++) {
		if (type == types[i]) {
			_type = createScalarType[i]();
		}
	}
	_t = src._t;
	_c = src._c;
	_i = src._i;
	_f = src._f;
	_d = src._d;
	for (int i = 0; i < 4; i++) {
		_states[i] = src._states[i];
	}
}

Scalar::~Scalar(void) {

	delete _type;
}

Scalar	&Scalar::operator=(Scalar const &src) {

	delete _type;
	std::string	types[] = {
		"ScalarTypeChar", "ScalarTypeInt", "ScalarTypeFloat", "ScalarTypeDouble", "ScalarTypeParse"
	};
	ScalarType	*(*createScalarType[]) (void) = {
		ScalarTypeChar::createType,
		ScalarTypeInt::createType,
		ScalarTypeFloat::createType,
		ScalarTypeDouble::createType,
		ScalarTypeParse::createType
	};
	_s = src._s;
	std::string	type = typeid(src).name();
	for (size_t i = 0; i < (sizeof(types) / sizeof(types[0])); i++) {
		if (type == types[i]) {
			_type = createScalarType[i]();
		}
	}
	_t = src._t;
	_c = src._c;
	_i = src._i;
	_f = src._f;
	_d = src._d;
	for (int i = 0; i < 4; i++) {
		_states[i] = src._states[i];
	}
	return (*this);
}

void	Scalar::transitionToType(ScalarType *newType) {

	delete _type;
	_type = newType;
	_type->enterConversion(*this);
}

std::string	&Scalar::getS(void) {

	return (_s);
}

char	Scalar::getC(void) const {

	return (_c);
}

int	Scalar::getI(void) const {

	return (_i);
}

float Scalar::getF(void) const {

	return (_f);
}

double Scalar::getD(void) const {

	return (_d);
}

enum e_types	Scalar::getT(void) const {

	return (_t);
}

int	Scalar::getStates(int idx) const {

	if (idx < 4 && idx >= 0)
		return (_states[idx]);
	return (-1);
}

bool	Scalar::setC(char c) {

	_c = c;
	return (true);
}

bool	Scalar::setI(int i) {

	_i = i;
	return (true);
}

bool	Scalar::setF(float f) {

	_f = f;
	return (true);
}

bool	Scalar::setD(double d) {

	_d = d;
	return (true);
}

bool	Scalar::setT(enum e_types t) {

	_t = t;
	return (true);
}

bool	Scalar::setStates(int idx, int value) {

	if (idx >= 0 && idx < 4  && value >= 0 && value < 7) {
		_states[idx] = value;
		return (true);
	}
	return (false);
}

std::ostream	&operator<<(std::ostream &o, Scalar const &src) {

	std::stringstream ss;
	std::string temp;

	if (src.getT() == TYPE_INVALID) {
		o << "Invalid Argument" << std::endl;
		return (o);
	}
	switch (src.getStates(TYPE_CHAR))
	{
	case TYPE_CHAR:
		o << "char: " << src.getC() << std::endl;
		break;

	case TYPE_NONDISPLAYABLE:
		o << "char: Non displayable" << std::endl;
		break;
	case TYPE_IMPOSSIBLE:
		o << "char: impossible" << std::endl;
	}

	switch (src.getStates(TYPE_INT))
	{
	case TYPE_INT:
		o << "int: " << src.getI() << std::endl;
		break;

	case TYPE_IMPOSSIBLE:
		o << "int: impossible" << std::endl;
		break;
	}

	if (src.getStates(TYPE_FLT) == TYPE_FLT) {
		ss << "float: " << src.getF();
		temp = ss.str();
		if (!(std::isnan(src.getF()) || std::isinf(src.getF())) \
			&& temp.find('.') == std::string::npos)
			ss << ".0";
		ss << "f" << std::endl;
	}
	else if (src.getStates(TYPE_FLT) == TYPE_IMPOSSIBLE) {
		ss << "float: impossible" << std::endl;
	}
	o << ss.str();
	ss.str(std::string());
	ss.clear();

	if (src.getStates(TYPE_DBL) == TYPE_DBL) {
		ss << "double: " << src.getD();
		temp = ss.str();
		if (!(std::isnan(src.getD()) || std::isinf(src.getD())) \
			&& temp.find('.') == std::string::npos)
			ss << ".0";
	}
	else if (src.getStates(TYPE_DBL) == TYPE_IMPOSSIBLE) {
		ss << "double: impossible" << std::endl;
	}
	o << ss.str();
	ss.str(std::string());
	ss.clear();
	o << std::endl;
	return (o);
}
