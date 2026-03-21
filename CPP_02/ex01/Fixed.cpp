/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:31:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 09:28:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int     Fixed::getRawBits(void) const
{
        std::cout << "getRawBits member function called" << std::endl;
        return (this->number);
}

void    Fixed::setRawBits(int const raw)
{
        this->number = raw;
}
     
Fixed::Fixed(void) : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	number = n << bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	number = roundf(num * (1 << bits));
}

int	Fixed::toInt(void) const
{
	return (number >> bits);
}

float	Fixed::toFloat(void) const
{
	return (float)number / (1 << bits);
}

Fixed::Fixed(const Fixed &another)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = another.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->number = other.getRawBits();
	return (*this);
}
