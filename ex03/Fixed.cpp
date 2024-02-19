/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:44:36 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 03:17:28 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : number_value_(0) {
}

// Converts an int to a fixed-point value.
Fixed::Fixed(const int value) : number_value_(value << fractional_bits_) {
}

// Converts a float to a fixed-point value (roundf rounds to the nearest int).
Fixed::Fixed(const float value) : number_value_(roundf(value * (1 << fractional_bits_))) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	number_value_ = other.number_value_;
	return (*this);
}

//* Start of new operator overloads.
bool	Fixed::operator>(const Fixed &other) const {
	if (number_value_ > other.number_value_)
		return (true);
	return (false);
	// Smaller syntax: return (number_value_ > other.number_value_);
}

bool	Fixed::operator<(const Fixed &other) const {
	if (number_value_ < other.number_value_)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const {
	if (number_value_ >= other.number_value_)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const {
	if (number_value_ <= other.number_value_)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const {
	if (number_value_ == other.number_value_)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const {
	if (number_value_ != other.number_value_)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed	sum;
	sum.setRawBits(number_value_ + other.getRawBits());
	return (sum);
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	difference;
	difference.setRawBits(number_value_ - other.getRawBits());
	return (difference);
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed	product;
	product.setRawBits((number_value_ * other.getRawBits()) >> fractional_bits_);
	// Or multiply then divide by 256 (2^8).
	return (product);
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed	quotient;
	quotient.setRawBits((number_value_ << fractional_bits_) / other.getRawBits());
	// Or divide then multiply by 256 (2^8), or divide by other.getRawBits().
	return (quotient);
}

Fixed	&Fixed::operator++(void) {
	number_value_++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temporary = *this;
	number_value_++;
	return (temporary);
}

Fixed	&Fixed::operator--(void) {
	number_value_--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temporary = *this;
	number_value_--;
	return (temporary);
}
//* End of new operator overloads.

Fixed::~Fixed(void) {
}

int Fixed::getRawBits(void) const {
	return (number_value_);
}

void Fixed::setRawBits(int const raw) {
	number_value_ = raw;
}

// Converts the fixed-point value to int.
int Fixed::toInt(void) const {
	return (number_value_ >> fractional_bits_);
}

// Converts the fixed-point value to float.
float Fixed::toFloat(void) const {
	return ((float)number_value_ / (1 << fractional_bits_)); // Copilot
	// return (static_cast<float>(number_value_) / getPower(2, fractional_bits_)); // 2^fractional_bits_ = 2^8 = 256
	// return (float(number_value_) / 256); // 256 = 2^8 (fractional_bits_ = 8);
}

//* Start of min and max functions.
Fixed	&Fixed::min(Fixed &value1, Fixed &value2) {
	if (value1.number_value_ < value2.number_value_)
		return (value1);
	return (value2);
	// Simpler put: return (value1.number_value_ < value2.number_value_ ? value1 : value2);
};

const Fixed	&Fixed::min(const Fixed &value1, const Fixed &value2) {
	if (value1.number_value_ < value2.number_value_)
		return (value1);
	return (value2);
};

Fixed	&Fixed::max(Fixed &value1, Fixed &value2) {
	if (value1.number_value_ > value2.number_value_)
		return (value1);
	return (value2);
	// Simpler put: return (value1.number_value_ > value2.number_value_ ? value1 : value2);
};

const Fixed	&Fixed::max(const Fixed &value1, const Fixed &value2) {
	if (value1.number_value_ > value2.number_value_)
		return (value1);
	return (value2);
};
//* End of min and max functions.

// Operator overloading for stream insertion.
// In other words, to make std::cout << Fixed work.
std::ostream &operator<<(std::ostream &output, const Fixed &value) {
	output << value.toFloat();
	return (output);
}
