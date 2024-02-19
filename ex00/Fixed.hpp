/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:36:54 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/15 13:19:58 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# pragma once // Include guard

# include <iostream>

class Fixed {
	private: // Class data members
		int number_value_;
		static const int fractional_bits_ = 8;

	public:
		Fixed(void); // Default constructor
		Fixed(const Fixed &other); // Copy constructor
		Fixed	&operator=(const Fixed &other); // Copy assignment operator
		~Fixed(void); // Destructor

		int getRawBits(void) const; // Accessor function (getter)
		void setRawBits(int const raw); // Mutator function (setter)
};

#endif
