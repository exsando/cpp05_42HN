/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:08:08 by asando            #+#    #+#             */
/*   Updated: 2026/09/07 20:23:18 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrate.hpp"

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		const std::string&	getName() const;
		bool				getIfSigned() const;
		const int			getGradeToSign() const;
		const int			getGrageToExecute() const;

		void	beSigned(Bureaucrat& signer);
		void	signForm(Bureaucrat& signer);
};
#endif
