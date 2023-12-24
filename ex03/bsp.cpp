/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:38:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 03:22:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

float	crossProduct(Point const p1, Point const p2, Point const p3)
{
	float	x1 = p2.getX() - p1.getX();
	float	y1 = p2.getY() - p1.getY();
	float	x2 = p3.getX() - p1.getX();
	float	y2 = p3.getY() - p1.getY();
	return (x1 * y2 - x2 * y1);
}

bool	isPointInsideTriangle(Point const v1, Point const v2, \
								Point const v3, Point const point)
{
	int	ret1;
	int	ret2;
	int	ret3;

	ret1 = crossProduct(point, v1, v2);
	ret2 = crossProduct(point, v2, v3);
	ret3 = crossProduct(point, v3, v1);
	if (ret1 > 0 && ret2 > 0 && ret3 > 0)
		return (true);
	if (ret1 == 0 || ret2 == 0 || ret3 == 0)
		std::cout << "Point " << point << " matches with one of Edges" << std::endl;
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	ret;

	if (point == a || point == b || point == c)
	{
		std::cout << "Point " << point << " matches with one of Vertexes" << std::endl;
		return (false);
	}
	ret = crossProduct(a, b, c);
	if (ret == 0)
	{
		std::cout << "This is not a triangle" << std::endl;
		return (false);
	}
	else if (ret > 0)
		return (isPointInsideTriangle(a, b, c, point));
	else
		return (isPointInsideTriangle(a, c, b, point));
}
