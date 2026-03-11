/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:44:19 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/11 19:52:25 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

//CDO
Serializer::Serializer() { std::cout << "You ain't supposed to see this\n"; }
Serializer::~Serializer() { std::cout << "Stop being pedantic\n"; }
Serializer::Serializer(const Serializer &ref)
{
	(void)ref;
	std::cout << "STOOOOOOOOOOOOOOOOOOP!!!!\n"; 
}
Serializer &Serializer::operator=(const Serializer &ref)
{
	(void)ref;
	std::cout << "If you're reading this, you're gay...\n";
	return *this;
}

// Methods

uintptr_t	Serializer::deserialize(const Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data		*Serializer::serialize(const uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
