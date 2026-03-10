/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:42:41 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/10 20:35:47 by htrindad         ###   ########.fr       */
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
		|| nbr == "+inff" || nbr == "-inf" || nbr == "-inff")
		return true;
	return false;
}

static bool	isChar(const std::string &nbr, const std::size_t &len)
{
	if (len == 1 && !std::isdigit(nbr[0]))
		return true;
	if (len == 3 && nbr[0] == '\'' && nbr[2] == '\'')
		return true;
	return false;
}

static bool	isInt(const std::string &nbr, const std::size_t &len)
{
	int	i = 0;
	bool	f = false;

	if (nbr[0] == '-' || nbr[0] == '+')
	{
		i++;
		f = true;
	}
	while ((nbr[i] && len > 0 && len < 12) || (nbr[i] && !f && len > 0 && len < 11))
		if (!std::isdigit(nbr[i++]))
			return false;
	return true;
}

static bool	isFloat(const std::string &nbr, const std::size_t &len, const std::size_t &dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!std::isdigit(nbr[j]))
		{
			if (j)
				return false;
			if (!j && nbr[j] != '+' && nbr[j] != '-')
				return false;
		}
	}
	for (std::size_t i = dot + 1; i < len; i++)
	{
		if (!std::isdigit(nbr[i]) && nbr[i] != 'f')
			return false;
		if (nbr[i] == 'f' && i != len - 1)
			return false;
	}
	return true;
}

type_t getType(const std::string &nbr, std::size_t &len)
{
	std::size_t	inf[2];

	inf[0] = nbr.find('.');
	inf[1] = nbr.find('f');
	if (inf[0] == std::string::npos)
	{
		if (isSpecial(nbr))
			return S;
		if (isChar(nbr, len))
			return C;
		if (isInt(nbr, len))
			return I;
	}
	if (inf[1] != std::string::npos && inf[0] != std::string::npos)
	{
		if (isFloat(nbr, len, inf[0]))
			return F;
	}
	else if (inf[1] == std::string::npos && inf[0] != std::string::npos)
		return D;
	return INV;
}

static void	printSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: nanf\n"
			<< "double: nan\n";
	else if (str == "+inf" || str == "+inff")
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: +inff\n"
			<< "double: +inf\n";
	else if (str == "-inf" || str == "-inff")
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: -inff\n"
			<< "double: -inf\n";
}

static void	convertChar(const std::string &str, const std::size_t &len)
{
	char c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout
			<< '\'' << c << "'\n"
			<< "int: " << static_cast<int>(c) << '\n'
			<< "float: " << static_cast<float>(c) << ".0f\n"
			<< "double: " << static_cast<double>(c) << ".0\n";
	else
		std::cout << "Non displayable\n";
}

static void	convertInt(const std::string &nbr)
{
	const long l = std::atol(nbr.c_str());

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible\n";
	else
	{
		if (std::isprint(l))
			std::cout << '\'' << static_cast<char>(l) << "'\n";
		else
			std::cout << "Non displayable\n";
	}
	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(l) << '\n';
	std::cout
		<< "float: " << static_cast<float>(l) << ".0f\n"
		<< "double: " << static_cast<double>(l) << ".0\n";
}

static void	convertFloat(const std::string &nbr)
{
	const double 	f = std::atof(nbr.c_str());
	const bool	t = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible\n";
	else
	{
		if (std::isprint(f))
			std::cout << '\'' << static_cast<char>(f) << "'\n";
		else
			std::cout << "Non displayable\n";
	}
	std::cout << "int: ";
	if (static_cast<long>(f) < INT_MIN || static_cast<long>(f) > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(f) << '\n';
	std::cout << "float: ";
	if (f < FLT_MIN || f > FLT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << f << (t ? ".0f" : "f") << '\n';
	std::cout << "double: " << static_cast<double>(f) << (t ? ".0" : "") << '\n';
}

static void	convertDouble(const std::string &nbr)
{
	const double 	d = std::atof(nbr.c_str());
	const bool	t = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible\n";
	else
	{
		if (std::isprint(d))
			std::cout << '\'' << static_cast<char>(d) << "'\n";
		else
			std::cout << "Non displayable\n";
	}
	std::cout << "int: ";
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << '\n';
	std::cout << "float: ";
	if (d < FLT_MIN || d > FLT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<float>(d) << (t ? ".0f" : "f") << '\n';
	std::cout << "double: ";
	if (d < DBL_MIN || d > DBL_MAX)
		std::cout << "impossible\n";
	else
		std::cout << d << '\n';
}

// Public

void	ScalarConverter::convert(const std::string &str)
{
	std::size_t	len = str.length();
	const type_t	type = getType(str, len);

	switch (type)
	{
		case INV:
			std::cerr << "Invalid input\n";
			break ;
		case S:
			printSpecial(str);
			break ;
		case C:
			convertChar(str, len);
			break ;
		case I:
			convertInt(str);
			break ;
		case F:
			convertFloat(str);
			break ;
		case D:
			convertDouble(str);
			break ;
	}
}
