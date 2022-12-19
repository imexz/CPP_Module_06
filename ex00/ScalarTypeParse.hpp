/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeParse.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:47:14 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/08 17:05:33 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPEPARSE_HPP
# define SCALARTYPEPARSE_HPP

#include "ScalarType.hpp"

class ScalarTypeParse : public ScalarType {

	private:

		static std::string	&rtrim(std::string	&s, const char *t) {
			s.erase(s.find_last_not_of(t) + 1);
			return (s);
		}

		static std::string	&ltrim(std::string &s, const char *t) {
			s.erase(0, s.find_first_not_of(t));
			return (s);
		}

		static std::string	&trim(std::string &s, const char *t) {
			return (ltrim(rtrim(s, t), t));
		}

	public:

		ScalarTypeParse(void);
		ScalarTypeParse(ScalarTypeParse const &src);
		~ScalarTypeParse(void);

		ScalarTypeParse		&operator=(ScalarTypeParse const &src);

		static ScalarType	*createType(void);
		void				enterConversion(Scalar &type);
		void				convert(Scalar &type);
		bool				checkSpecialCases(Scalar &type);
		static void			skipWhitespaces(Scalar &type);

};

#endif
