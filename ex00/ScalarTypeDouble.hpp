/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeDouble.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:58 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:07:07 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPEDOUBLE_HPP
# define SCALARTYPEDOUBLE_HPP

# include "ScalarType.hpp"

class ScalarTypeDouble : public ScalarType {

	private:

		bool	checkInvalidArgument(Scalar &type);

	public:

		ScalarTypeDouble(void);
		ScalarTypeDouble(ScalarTypeDouble const &src);
		ScalarTypeDouble(std::string s);
		~ScalarTypeDouble(void);

		ScalarTypeDouble	&operator=(ScalarTypeDouble const &src);

		static ScalarType	*createType(void);
		void				enterConversion(Scalar &type);
		void				convert(Scalar &type);

};

#endif
