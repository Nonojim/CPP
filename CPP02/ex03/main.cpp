/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:05 by npederen          #+#    #+#             */
/*   Updated: 2026/01/20 15:34:18 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// https://www.calculator.net/triangle-calculator.html?vc=45&vx=0.1&vy=&va=90&vz=&vb=45&angleunits=d&x=Calculate

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << "Test point (" << p.getPosX() << ", " << p.getPosY() << ") : ";
	if (bsp(a, b, c, p))
		std::cout << "\033[32mINSIDE\033[0m" << std::endl;
	else
		std::cout << "\033[31mOUTSIDE\033[0m" << std::endl;
}

int main(void)
{

	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	std::cout << "\n=== Triangle A(0,0)  B(5,0)  C(0,5) ===\n" << std::endl;

	// inside
	test(a, b, c, Point(1, 3.8f)); // inside

	// Point on an edge
	test(a, b, c, Point(2.5f, 0.1f)); // on AB
	test(a, b, c, Point(0.1f, 2.5f)); // on AC

	// Point on a apex
	test(a, b, c, Point(0, 0)); // A
	test(a, b, c, Point(5, 0)); // B
	test(a, b, c, Point(0, 5)); // C

	// outside
	test(a, b, c, Point(5, 5));
	test(a, b, c, Point(-1, -1));
	test(a, b, c, Point(3, 3));

	// linear triangle
	Point d1(0, 0);
	Point d2(1, 1);
	Point d3(2, 2);
	std::cout << "\n=== linear triangle ===\n" << std::endl;
	test(d1, d2, d3, Point(1, 1));
	return (0);
}