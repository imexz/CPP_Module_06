/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeFloat.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:56 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:07:02 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPEFLOAT_HPP
# define SCALARTYPEFLOAT_HPP

# include "ScalarType.hpp"

class ScalarTypeFloat : public ScalarType {

	private:

		bool	checkInvalidArgument(Scalar &type);

	public:

		ScalarTypeFloat(void);
		ScalarTypeFloat(ScalarTypeFloat const &src);
		ScalarTypeFloat(std::string s);
		~ScalarTypeFloat(void);

		ScalarTypeFloat		&operator=(ScalarTypeFloat const &src);

		static ScalarType	*createType(void);
		void				enterConversion(Scalar &type);
		void				convert(Scalar &type);

};

#endif
