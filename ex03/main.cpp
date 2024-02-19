/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:30:37 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 04:47:45 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

// jongoad
void	verdict(Point const a, Point const b, Point const c, Point const p) {
	if (bsp(a, b, c, p))
		std::cout << "‣ O ponto está dentro do triângulo. ◬" << std::endl;
	else
		std::cout << "‣ O ponto está fora do triângulo. ⧊" << std::endl;
}

int	main(void) {
	Point a(0.0f, 0.0f);
	Point b(0.0f, 5.0f);
	Point c(5.0f, 2.5f);
	Point p(-1.0f, 2.5f);

	verdict(a, b, c, Point(2.3f, 4.2f)); // Outside
	verdict(a, b, c, Point(1.0f, 2.5f)); // Inside
	verdict(a, b, c, Point(0.0f, 2.5f)); // Over the edge
	verdict(a, b, c, Point(0.0f, 0.0f)); // Over the vertex
	verdict(a, b, c, Point(2.0f, 1.5f)); // Inside
	verdict(a, b, c, Point(-1.0f, 2.5f)); // Outside
};

/* //gmasid
void print_triangle(Point const a, Point const b, Point const c, Point const point) {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			Point P(i, j);
			if (point.get_x().toFloat() == P.get_x().toFloat() && point.get_y().toFloat() == P.get_y().toFloat())
				std::cout << " P ";
			else if (a.get_x().toFloat() == P.get_x().toFloat() && a.get_y().toFloat() == P.get_y().toFloat())
				std::cout << " * ";
			else if (b.get_x().toFloat() == P.get_x().toFloat() && b.get_y().toFloat() == P.get_y().toFloat())
				std::cout << " * ";
			else if (c.get_x().toFloat() == P.get_x().toFloat() && c.get_y().toFloat() == P.get_y().toFloat())
				std::cout << " * ";
			else if (bsp(a, b, c, P) == true)
				std::cout << " . ";
			else
				std::cout << "	 ";
		}
		std::cout << std::endl;
	}
}

int main() {
	Point A(5, 10);
	Point B(20, 0);
	Point C(20, 20);

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			Point P(i, j);
			print_triangle(A, B, C, P);
			std::cout << "Point(" << P.get_x() << ", " << P.get_y() << ")";
			std::cout << " => is inside: " << (bsp(A, B, C, P) ? "true" : "false") << std::endl;
			std::cout << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}
	}
	return 0;
}
*/
