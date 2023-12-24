/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:21:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 01:35:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(/* args */)
{
	this->value = 0;
}
Fixed::Fixed(const int raw)
{
	this->value = raw << this->bits;
}
Fixed::Fixed(const float raw)
{
	this->value = roundf(raw * (1 << this->bits));
}
Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}
Fixed::~Fixed()
{}

Fixed	&Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->value = obj.value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

bool 	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}
bool 	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}
bool 	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}
bool 	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}
bool 	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}
bool 	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}
Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return (tmp);
}
Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}
void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1<<this->bits));
}

const Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	return ((a.value < b.value) ? (a) : (b));
}
const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a.value < b.value) ? (a) : (b));
}
const Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	return ((a.value > b.value) ? (a) : (b));
}
const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a.value > b.value) ? (a) : (b));
}
