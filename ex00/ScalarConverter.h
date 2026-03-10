/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:38:55 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/10 20:30:27 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <cctype>
#include <cctype>
#include <cmath>

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
	public:
		static void convert(const std::string &str); // Main method
};
