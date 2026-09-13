/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:08:08 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 11:51:43 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(const std::string& name, bool sign_stat,
				const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& rhs);
		~AForm();

		const std::string&	getName() const;
		bool				getIfSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void	beSigned(Bureaucrat& signer);
		void	signForm(Bureaucrat& signer);
		virtual void	execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighExecp : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowExecp : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif
