/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:38:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 03:21:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point(void): x(0), y(0)
{}
Point::Point(float const xval, float const yval): x(xval), y(yval)
{}
Point::Point(Point const &obj): x(obj.x), y(obj.y)
{}
Point	&Point::operator=(const Point &obj)
{
	if (this != &obj)
	{
		const_cast<Fixed&>(x) = obj.x;
		const_cast<Fixed&>(y) = obj.y;
	}
	return (*this);
}
Point::~Point(void)
{}

std::ostream	&operator<<(std::ostream &os, const Point &obj)
{
	os << "(" << obj.x << ", " << obj.y << ")";
	return (os);
}

bool 	Point::operator==(const Point& other) const
{
	return (this->x == other.x && this->y == other.y);
}

float	Point::getX(void) const
{
	return (this->x.toFloat());
}
float	Point::getY(void) const
{
	return (this->y.toFloat());
}
