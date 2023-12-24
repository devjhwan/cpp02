/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:38:49 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 03:18:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point(void);
	Point(float const xval, float const yval);
	Point(Point const &obj);
	Point				&operator=(const Point &obj);
	~Point(void);
	friend std::ostream	&operator<<(std::ostream &os, const Point &obj);
	bool 				operator==(const Point& other) const;
	float				getX(void) const;
	float				getY(void) const;
};


#endif
