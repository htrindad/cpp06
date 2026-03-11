/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:52:44 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/11 20:04:48 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include "Data.h"

int main()
{
	Data data;
	Data *ptr;
	Data *rest;
	uintptr_t raw;

	ptr = &data;
	raw = Serializer::serialize(ptr);
	rest = Serializer::deserialize(raw);
	if (rest == ptr)
		std::cout << "Uncorrupted\n";
	else
		return (std::cout << "Corrupted\n", 1);
	return 0;
}
