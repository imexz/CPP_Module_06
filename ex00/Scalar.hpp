/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:57:32 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:07:20 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include "ScalarTypeUtils.hpp"

class ScalarType;

class Scalar {

	private:

		std::string		_s;
		ScalarType		*_type;
		enum e_types	_t;
		char			_c;
		int				_i;
		float			_f;
		double			_d;
		int				_states[4];

	public:

		Scalar(void);
		Scalar(std::string s);
		Scalar(Scalar const &src);
		~Scalar(void);

		Scalar			&operator=(Scalar const &src);

		void			transitionToType(ScalarType *newType);
		std::string		&getS(void);
		char			getC(void) const;
		int				getI(void) const;
		float			getF(void) const;
		double			getD(void) const;
		enum e_types	getT(void) const;
		int				getStates(int idx) const;
		bool			setC(char c);
		bool			setI(int i);
		bool			setF(float f);
		bool			setD(double d);
		bool			setT(enum e_types t);
		bool			setStates(int idx, int value);

};

std::ostream	&operator<<(std::ostream &o, Scalar	const &src);

#endif
