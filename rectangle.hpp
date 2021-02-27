#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <algorithm>

class Rectangle {
private:
    bool is_point_on(double x, double y, Rectangle &rec);
public:
    double xl, yl, xr, yr;

    Rectangle(double Xl, double Yl, double Xr, double Yr) : xl(Xl), yl(Yl), xr(Xr), yr(Yr) {};
    ~Rectangle() {};

    double getSquare();
    double getPerimeter();
    void move(double x, double y);
    void changeDimensions(double x, double y);
    bool isSquareLarger(Rectangle &rec2);
    bool isPerimeterLarger(Rectangle &rec2);
    Rectangle intersection(Rectangle rec2, bool &code);
    Rectangle uni(Rectangle rec2);
};

#endif
