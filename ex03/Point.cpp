/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:11:27 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 03:18:21 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x_(0), y_(0) {
};

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {
};

Point::Point(const Point &other) : x_(other.x_), y_(other.y_) {
};

// Returns a new Point object with the x and y values of the other object.
Point	Point::operator=(const Point &other) {
	return (Point(other.get_x(), other.get_y()));
};

Point::~Point(void) {
};

Fixed	Point::get_x(void) const {
	return (x_);
};

Fixed	Point::get_y(void) const {
	return (y_);
};
