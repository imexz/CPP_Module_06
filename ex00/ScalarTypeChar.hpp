/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeChar.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:41 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:06:55 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPECHAR_HPP
# define SCALARTYPECHAR_HPP

# include "ScalarType.hpp"

class ScalarTypeChar : public ScalarType {

	private:

	public:

		ScalarTypeChar(void);
		ScalarTypeChar(ScalarTypeChar const &src);
		~ScalarTypeChar(void);

		ScalarTypeChar		&operator=(ScalarTypeChar const &src);

		static ScalarType	*createType(void);
		void				enterConversion(Scalar &type);
		void				convert(Scalar &type);

};

#endif
