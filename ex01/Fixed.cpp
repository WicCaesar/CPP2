/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:44:36 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/15 14:05:35 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : number_value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Converts an int to a fixed-point value.
Fixed::Fixed(const int value) : number_value_(value << fractional_bits_) {
	std::cout << "Int constructor called" << std::endl;
}

// Converts a float to a fixed-point value (roundf rounds to the nearest int).
Fixed::Fixed(const float value) : number_value_(roundf(value * (1 << fractional_bits_))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	number_value_ = other.number_value_;
	// OR number_value_ = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (number_value_);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	number_value_ = raw;
}

// Converts the fixed-point value to int.
int Fixed::toInt(void) const {
	return (number_value_ >> fractional_bits_);
}

// Converts the fixed-point value to float.
float Fixed::toFloat(void) const {
	return ((float)number_value_ / (1 << fractional_bits_));
}

// Operator overloading for stream insertion.
// In other words, to make std::cout << Fixed work.
std::ostream &operator<<(std::ostream &output, const Fixed &value) {
	output << value.toFloat();
	return (output);
}
