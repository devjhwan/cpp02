/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:21:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/24 01:30:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed				&operator=(const Fixed &obj);
	friend std::ostream	&operator<<(std::ostream &os, const Fixed &obj);
	bool 				operator>(const Fixed& other) const;
	bool 				operator<(const Fixed& other) const;
	bool 				operator>=(const Fixed& other) const;
	bool 				operator<=(const Fixed& other) const;
	bool 				operator==(const Fixed& other) const;
	bool 				operator!=(const Fixed& other) const;
	Fixed				operator+(const Fixed& other) const;
	Fixed				operator-(const Fixed& other) const;
	Fixed				operator*(const Fixed& other) const;
	Fixed				operator/(const Fixed& other) const;
	Fixed				&operator++();
	Fixed				operator++(int);
	Fixed				&operator--();
	Fixed				operator--(int);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
	static const Fixed	&min(Fixed& a, Fixed& b);
	static const Fixed	&min(const Fixed& a, const Fixed& b);
	static const Fixed	&max(Fixed& a, Fixed& b);
	static const Fixed	&max(const Fixed& a, const Fixed& b);
};

#endif
