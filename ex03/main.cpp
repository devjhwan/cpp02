/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:21:18 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 03:22:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point const	v1(0, 0);
	Point const	v2(5, 10);
	Point const	v3(10, 0);
	Point const	p[5] = {Point(5, 5), Point(0, 5), Point(v1), \
						Point(5, 0), Point(1, 1)};
	std::cout << "Vertex: " << v1 << ", " << v2 << ", " << v2 << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (bsp(v1, v2, v3, p[i]))
			std::cout << "Point " << p[i] << " is inside of triangle" << std::endl;
		else
			std::cout << "Point " << p[i] << " is outside of triangle" << std::endl;
	}
	return (0);
}
