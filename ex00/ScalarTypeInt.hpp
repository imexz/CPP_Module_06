/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeInt.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:53 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:06:58 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPEINT_HPP
# define SCALARTYPEINT_HPP

# include "ScalarType.hpp"

class ScalarTypeInt : public ScalarType {

	private:

	public:

		ScalarTypeInt(void);
		ScalarTypeInt(ScalarTypeInt const &src);
		~ScalarTypeInt(void);

		ScalarTypeInt		&operator=(ScalarTypeInt const &src);

		static ScalarType	*createType(void);
		void				enterConversion(Scalar &type);
		void				convert(Scalar &type);

};

#endif
