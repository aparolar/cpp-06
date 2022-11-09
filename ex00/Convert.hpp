/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:07:47 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/09 20:07:53 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <limits.h>

# define DISPLAY_MIN  33
# define DISPLAY_MAX 126

class Convert
{
	private:
		double _value;
	
	public:
		Convert();
		Convert(Convert const &toCopy);
		Convert(const char* value);
		~Convert();

		Convert& operator=(Convert const &toCopy);
		
		void toChar();
		void toInt();
		void toFloat();
		void toDouble();
};

#endif
