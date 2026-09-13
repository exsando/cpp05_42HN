/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:08:08 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 11:13:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(const std::string& name, bool sign_stat,
				const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& rhs);
		~Form();

		const std::string&	getName() const;
		bool				getIfSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void	beSigned(Bureaucrat& signer);
		void	signForm(Bureaucrat& signer);

		class GradeTooHighExecp : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowExecp : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);
#endif
