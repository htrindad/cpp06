/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:38:55 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/07 17:29:34 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>

typedef enum e_type
{
	S,
	C,
	I,
	F,
	D,
	INV = -1
}	type_t;

class ScalarConverter
{
	private:
		ScalarConverter(); // The class is not meant to be instatiated
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter &operator=(const ScalarConverter &ref);
		~ScalarConverter();
		static type_t getType(const std::string &nbr, std::size_t &len)
	public:
		static void convert(const std::string &str); // Main method
};
