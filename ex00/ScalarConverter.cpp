/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:42:41 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/07 17:34:59 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

//CDO
ScalarConverter::ScalarConverter() { std::cout << "Default constructor called\nYou're not supposed to see this\n"; }
ScalarConverter::~ScalarConverter() { std::cout << "Default destructor called\nYou're not supposed to see this\n"; }
ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	(void)ref;
	std::cout << "Copy constructor called\nYou're not supposed to see this\n";
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	std::cout << "Copy operator overload called\nYou're not supposed to see this";
	return *this;
}

//Methods
// Private

static bool	isSpecial(const std::string &nbr)
{
	if (nbr == "nan" || nbr == "nanf" || nbr == "+inf" \
		|| nbr == "+inff" || nbr == "-inf" || str == "-inff")
		return true;
	return false;
}

static bool	isChar(const std::string &nbr, const std::size_t &len)
{
	if (len == 1 && !std::isdigit(nbr))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

static bool	isInt(const std::string &nbr, const std::size_t &len, const std::size_t &dot)
{
	int	i = 0;
	bool	f = false;

	if (str[0] == '-')
}

type_t	ScalarConverter::getType(const std::string &nbr, std::size_t &len)
{
	size_t	inf[2];

	inf[0] = nbr.find('.');
	inf[1] = nbr.find('f');
	if (inf[0] == std::string::npos)
	{
		if (isSpecial(nbr))
			return S;
		
	}
}

//Public

void	ScalarConverter::convert(const std::string &str)
{

}
