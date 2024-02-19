/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:36:54 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/15 14:23:48 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# pragma once

# include <iostream>
# include <cmath> // roundf

class Fixed {
	private:
		int number_value_;
		static const int fractional_bits_ = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		// Assignment operator overload
		Fixed	&operator=(const Fixed &other);
		// Logic operator overload
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		// Arithmetic operator overload
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		// Increment and decrement operator overload
		Fixed	&operator++(void); // Pre-increment
		Fixed	operator++(int); // Post-increment, requires a value
		Fixed	&operator--(void); // Pre-decrement
		Fixed	operator--(int); // Post-decrement, requires a value
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
		
		static Fixed		&min(Fixed &value1, Fixed &value2);
		static const Fixed	&min(const Fixed &value1, const Fixed &value2);
		static Fixed		&max(Fixed &value1, Fixed &value2);
		static const Fixed	&max(const Fixed &value1, const Fixed &value2);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &value);

#endif
