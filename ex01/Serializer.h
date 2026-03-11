/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:41:15 by htrindad          #+#    #+#             */
/*   Updated: 2026/03/11 20:02:41 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include <iostream>

struct Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &ref);
		Serializer &operator=(const Serializer &ref);
	public:
		static uintptr_t	serialize(const Data *ptr);
		static Data		*deserialize(const uintptr_t raw);
};
