/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:09:29 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:06:50 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPE_HPP
# define SCALARTYPE_HPP

# include <string>
# include <iostream>
# include "Scalar.hpp"

class Scalar;

class ScalarType {

	public:

		ScalarType(void);
		ScalarType(ScalarType const &src);
		virtual	~ScalarType(void);

		ScalarType	&operator=(ScalarType const &src);

		virtual void	enterConversion(Scalar &type) = 0;
		virtual void	convert(Scalar &type) = 0;
};

#endif
