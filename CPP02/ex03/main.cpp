/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:05 by npederen          #+#    #+#             */
/*   Updated: 2025/11/28 20:40:08 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);

//test by gpt
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

	// Point p(1.5f, 1);
	// Point a(0, 0);
	// Point b(4, 4);
	// Point c(8, 0);
	//
	// std::cout << bsp(a, b, c, p) << std::endl;
	//main by gpt
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	std::cout << "\n=== Triangle A(0,0)  B(5,0)  C(0,5) ===\n" << std::endl;

	// 1) Point clearly inside the triangle
	test(a, b, c, Point(1, 3.8f)); // inside

	// 2) Point on an edge
	test(a, b, c, Point(2.5f, 0)); // on AB
	test(a, b, c, Point(0, 2.5f)); // on AC

	// 3) Point on a vertex
	test(a, b, c, Point(0, 0)); // A
	test(a, b, c, Point(5, 0)); // B
	test(a, b, c, Point(0, 5)); // C

	// 4) Outside
	test(a, b, c, Point(5, 5));
	test(a, b, c, Point(-1, -1));
	test(a, b, c, Point(3, 3));

	// 5) Degenerate triangle (colinear)
	Point d1(0, 0);
	Point d2(1, 1);
	Point d3(2, 2); // aligned
	std::cout << "\n=== Degenerate triangle (colinear points) ===\n" << std::endl;
	test(d1, d2, d3, Point(1, 1));
	return (0);
}