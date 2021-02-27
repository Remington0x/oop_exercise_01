#include <iostream>
#include "rectangle.hpp"

int main() {
    std::cout << "Enter coordinates of first rectangle in order x-left, y-left, x-right, y-right\n";
    double xl, xr, yl, yr;
    std::cin >> xl >> yl >> xr >> yr;

    std::cout << "x-left = " << xl << " y-left = " << yl << " x-right = " << xr << " y-right = " << yr << std::endl;
    Rectangle rec = Rectangle(xl, yl, xr, yr);

    std::cout << "Square = " << rec.getSquare() << " Perimeter = " << rec.getPerimeter() << std::endl;

    std::cout << "Enter values to move rectangle (x, y)\n";
    double mvx, mvy;
    std::cin >> mvx >> mvy;
    rec.move(mvx, mvy);
    std::cout << "x-left = " << rec.xl << " y-left = " << rec.yl;
    std::cout << " x-right = " << rec.xr << " y-right = " << rec.yr << std::endl;

    std::cout << "Enter values to change dimensions of rectangle (x, y)\n";
    std::cin >> mvx >> mvy;
    rec.changeDimensions(mvx, mvy);
    std::cout << "x-left = " << rec.xl << " y-left = " << rec.yl;
    std::cout << " x-right = " << rec.xr << " y-right = " << rec.yr << std::endl;

    std::cout << "Enter coordinates of second rectangle in order x-left, y-left, x-right, y-right\n";
    std::cin >> xl >> yl >> xr >> yr;
    std::cout << "x-left = " << xl << " y-left = " << yl << " x-right = " << xr << " y-right = " << yr << std::endl;
    Rectangle rec2 = Rectangle(xl, yl, xr, yr);

    std::cout << "Square1 = " << rec.getSquare() << " Square2 = " << rec2.getSquare() << std::endl;
    std::cout << ((rec.isSquareLarger(rec2)) ? "Square1 > Square2\n" : "Square2 >= Square1\n");

    std::cout << "Perimeter1 = " << rec.getPerimeter() << " Perimeter2 = " << rec2.getPerimeter() << std::endl;
    std::cout << ((rec.isPerimeterLarger(rec2)) ? "Perimeter1 > Perimeter2\n" : "Perimeter2 >= Perimeter1\n");

    bool code;
    Rectangle rec3 = rec.intersection(rec2, code);
    if (code) {
        std::cout << "Intersection coordinates:\n";
        std::cout << "x-left = " << rec3.xl << " y-left = " << rec3.yl;
        std::cout << " x-right = " << rec3.xr << " y-right = " << rec3.yr << std::endl;
    } else {
        std::cout << "intersection failed\n";
    }

    rec3 = rec.uni(rec2);
    std::cout << "Union coordinates:\n";
    std::cout << "x-left = " << rec3.xl << " y-left = " << rec3.yl;
    std::cout << " x-right = " << rec3.xr << " y-right = " << rec3.yr << std::endl;

    return 0;
}
