/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:11:21 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 04:48:28 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# pragma once

# include "Fixed.hpp"

class	Point {
	private:
		Fixed const	x_;
		Fixed const	y_;

	public:
		Point(void); // initializes x and y to 0
		Point(const Fixed x, const Fixed y); // initializes to the given values
		Point(const Point &other); // copy constructor
		Point	operator=(const Point &other); // copy assignment operator overload
		~Point(void); // destructor

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};

#endif
