/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:36:54 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/15 13:19:47 by cnascime         ###   ########.fr       */
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
		Fixed(const int value); // Parameterized constructor (int)
		Fixed(const float value); // Parameterized constructor (float)
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other); // Copy assignment operator (overload)
		// Overload here means that the operator is being redefined to work with the class I created.
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

// Subject asked for "an overload of the insertion operator (<<) that inserts a 
// floating-point representation of the fixed-point value into the output stream
// object passed as parameter". In other words, I have to make the classes I
// create work with the << operator so I can print them (std::cout, cerr, clog).
std::ostream	&operator<<(std::ostream &output, const Fixed &value);
// The << operator is being redefined (overloaded) to work with the Fixed class.

#endif
