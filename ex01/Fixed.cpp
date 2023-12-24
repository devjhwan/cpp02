/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:21:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 01:22:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(/* args */)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}
Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = raw << this->bits;
}
Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(raw * (1 << this->bits));
}
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->value = obj.value;
	return (*this);
}
std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1<<this->bits));
}
