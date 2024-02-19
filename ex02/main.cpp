/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:30:37 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/15 20:07:20 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::clog << "b a seguir "; //! APAGAR
	std::cout << b << std::endl;
	std::clog << "a: " << a << std::endl; //! APAGAR
	std::clog << "b: " << b << std::endl; //! APAGAR
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

/*
#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int main( void ) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|   Fixed Point Number Tester    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Testing Code Provided in Subject PDF-----" CLEAR << std::string(2, '\n');

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	a.~Fixed();
	b.~Fixed();


	std::cout << RED"-----Testing Comparison Operators-----" CLEAR << std::string(2, '\n');

	Fixed c(10.5f);
	Fixed e(15.125f);
	std::cout << std::endl;

	std::cout << RED"-----Less Than-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " < " << e << std::endl;
	std::cout << "Result: " << (c < e) << std::string(2, '\n');

	std::cout << "Input: " << e << " < " << c << std::endl;
	std::cout << "Result: " << (e < c) << std::string(2, '\n');

	std::cout << "Input: " << c << " < " << c << std::endl;
	std::cout << "Result: " << (c < c) << std::string(2, '\n');

	std::cout << RED"-----Greater Than-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " > " << e << std::endl;
	std::cout << "Result: " << (c > e) << std::string(2, '\n');

	std::cout << "Input: " << e << " > " << c << std::endl;
	std::cout << "Result: " << (e > c) << std::string(2, '\n');

	std::cout << "Input: " << c << " > " << c << std::endl;
	std::cout << "Result: " << (c > c) << std::string(2, '\n');

	std::cout << RED"-----Less Than or Equal To-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " <= " << e << std::endl;
	std::cout << "Result: " << (c <= e) << std::string(2, '\n');

	std::cout << "Input: " << e << " < " << c << std::endl;
	std::cout << "Result: " << (e <= c) << std::string(2, '\n');

	std::cout << "Input: " << c << " < " << c << std::endl;
	std::cout << "Result: " << (c <= c) << std::string(2, '\n');

	std::cout << RED"-----Greater Than or Equal To-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " >= " << e << std::endl;
	std::cout << "Result: " << (c >= e) << std::string(2, '\n');

	std::cout << "Input: " << e << " >= " << c << std::endl;
	std::cout << "Result: " << (e >= c) << std::string(2, '\n');

	std::cout << "Input: " << c << " >= " << c << std::endl;
	std::cout << "Result: " << (c >= c) << std::string(2, '\n');

	std::cout << RED"-----Equal To-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " == " << e << std::endl;
	std::cout << "Result: " << (c == e) << std::string(2, '\n');

	std::cout << "Input: " << e << " == " << c << std::endl;
	std::cout << "Result: " << (e == c) << std::string(2, '\n');

	std::cout << "Input: " << c << " == " << c << std::endl;
	std::cout << "Result: " << (c == c) << std::string(2, '\n');

	std::cout << RED"-----Not Equal To-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " != " << e << std::endl;
	std::cout << "Result: " << (c != e) << std::string(2, '\n');

	std::cout << "Input: " << e << " != " << c << std::endl;
	std::cout << "Result: " << (e != c) << std::string(2, '\n');

	std::cout << "Input: " << c << " != " << c << std::endl;
	std::cout << "Result: " << (c != c) << std::string(2, '\n');

	std::cout << RED"-----Testing Arithmetic Operators-----" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Addition-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " + " << e << std::endl;
	std::cout << "Result: " << (c + e) << std::string(2, '\n');

	std::cout << RED"-----Subtraction-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " - " << e << std::endl;
	std::cout << "Result: " << (c - e) << std::string(2, '\n');

	std::cout << RED"-----Multiplication-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " * " << e << std::endl;
	std::cout << "Result: " << (c * e) << std::string(2, '\n');

	std::cout << RED"-----Division-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << c << " / " << e << std::endl;
	std::cout << "Result: " << (c / e) << std::string(2, '\n');

	std::cout << RED"-----Increment & Decrement Operators-----" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Pre-Increment-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << "++" << e << std::endl;
	std::cout << "Result: " << ++e << std::string(2, '\n');

	std::cout << RED"-----Post-Increment-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << e  << "++" << std::endl;
	std::cout << "Result: " << e++ << std::string(2, '\n');

	std::cout << RED"-----Pre-Decrement-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << "--" << e << std::endl;
	std::cout << "Result: " << --e << std::string(2, '\n');

	std::cout << RED"-----Post-Increment-----" CLEAR << std::string(2, '\n');
	std::cout << "Input: " << e << "--" << std::endl;
	std::cout << "Result: " << e-- << std::string(2, '\n');

	return 0;
}
*/
