/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:11:32 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 04:02:17 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BSP stands for binary space partitioning.
// It is a method to divide a space into two parts, and is commonly used in
// computer graphics to determine which objects are visible and which are not.
// This is a simple version of the algorithm,
// only checking whether a point is inside a triangle.

#include "Fixed.hpp"
#include "Point.hpp"

// The area of a triangle is given by the formula:
// 1/2 * |(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))| translated to:
// |(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2|
Fixed	CalculateArea(Point const a, Point const b, Point const c) {
	/*Fixed	area = (a.get_x() * (b.get_y() - c.get_y())
				  + b.get_x() * (c.get_y() - a.get_y())
				  + c.get_x() * (a.get_y() - b.get_y()) / 2.0f); // * 0.5f*/
	Fixed	area = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y()) 
				 - (b.get_y() - a.get_y()) * (c.get_x() - a.get_x());
	if (area < 0)
		area = area * -1; // Absolute value
	return (area);
};

// Checks if a given point is within the area of a triangle a-b-c.
// If the sum of the areas of the three triangles formed by the point and the
// three vertices is equal to the triangle's area, then the point is inside.
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	TotalArea = CalculateArea(a, b, c);
	Fixed	ab = CalculateArea(point, a, b);
	Fixed	bc = CalculateArea(point, b, c);
	Fixed	ca = CalculateArea(point, c, a);

	if (ab + bc + ca == TotalArea)
		return (true);
	return (false);
};
