#include "rectangle.hpp"

double Rectangle::getSquare() {
    return (xr - xl) * (yr - yl);
}

double Rectangle::getPerimeter() {
    return 2 * (xr - xl + yr - yl);
}

void Rectangle::move(double x, double y) { //на сколько по x и y сдвинуть
    xr += x;
    xl += x;
    yr += y;
    yl += y;
}

void Rectangle::changeDimensions(double x, double y) { //увеличить на х по ОХ и на y по OY
    xr += x;
    yr += y;
}

bool Rectangle::isSquareLarger(Rectangle &rec2) {
    double square1 = getSquare();
    double square2 = rec2.getSquare();
    if (square1 > square2) {
        return true;
    } else {
        return false;
    }
}

bool Rectangle::isPerimeterLarger(Rectangle &rec2) {
    double perimeter1 = getPerimeter();
    double perimeter2 = rec2.getPerimeter();
    if (perimeter1 > perimeter2) {
        return true;
    } else {
        return false;
    }
}

Rectangle Rectangle::intersection(Rectangle rec2, bool &code) {
    code = true;
    double int_x_left = 0;
    double int_x_right = 0;
    double int_y_left = 0;
    double int_y_right = 0;
    bool a, b, c, d;
    a = is_point_on(xl, yr, rec2); //upper left
    b = is_point_on(xr, yr, rec2); //upper right
    c = is_point_on(xl, yl, rec2); //down left
    d = is_point_on(xr, yl, rec2); //down right

    if (a) {
        //std::cout << "a is on the rec2\n";
        if (b) {    //rec2 limits only on bottom
            //std::cout << "ab is on the rec2\n";
            if (d) {    //that means that rec fully placed on rec2
                //std::cout << "abcd is on the rec2\n";
                int_x_left = xl;
                int_y_left = yl;
                int_x_right = xr;
                int_y_right = yr;
            } else {
                int_x_left = xl;
                int_y_left = rec2.yl;
                int_x_right = xr;
                int_y_right = yr;
            }
        } else
        if (c) {    //rec2 limits only on right border
            //std::cout << "ac is on the rec2\n";
            int_x_left = xl;
            int_y_left = yl;
            int_x_right = rec2.xr;
            int_y_right = yr;
        } else {    //that means only a placed on the rec2
            //std::cout << "a is on the rec2\n";
            int_x_left = xl;
            int_y_left = rec2.yl;
            int_x_right = rec2.xr;
            int_y_right = yr;
        }
    } else
    if (b) {
        //std::cout << "b is on the rec2\n";
        if (c) {
            //std::cout << "bc is on the rec2\n";
            int_x_left = rec2.xl;
            int_y_left = yl;
            int_x_right = xr;
            int_y_right = yr;
        } else {    //only b
            //std::cout << "b is on the rec2\n";
            int_x_left = rec2.xl;
            int_y_left = rec2.yl;
            int_x_right = xr;
            int_y_right = yr;
        }
    } else
    if (c) {
        //std::cout << "c is on the rec2\n";
        if (d) {
            //std::cout << "cd is on the rec2\n";
            int_x_left = xl;
            int_y_left = yl;
            int_x_right = xr;
            int_y_right = rec2.yr;
        } else {    //only c
            //std::cout << "c is on the rec2\n";
            int_x_left = xl;
            int_y_left = yl;
            int_x_right = rec2.xr;
            int_y_right = rec2.yr;
        }
    } else
    if (d) {    //only d
        //std::cout << "d is on the rec2\n";
        int_x_left = rec2.xl;
        int_y_left = yl;
        int_x_right = xr;
        int_y_right = rec2.yr;
    } else
    if (is_point_on(rec2.xl, rec2.yr, *this)) {
        int_x_left = rec2.xl;
        int_y_left = rec2.yl;
        int_x_right = rec2.xr;
        int_y_right = rec2.yr;
    } else {
        code = false;
    }

    //std::cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << " code = " << code << std::endl;

    Rectangle rec_int = Rectangle(int_x_left, int_y_left, int_x_right, int_y_right);
    //code = true;

    return rec_int;

}

Rectangle Rectangle::uni(Rectangle rec2) {
    double uxl, uyl, uxr, uyr;
    uxl = std::min(xl, rec2.xl);
    uyl = std::min(yl, rec2.yl);
    uxr = std::max(xr, rec2.xr);
    uyr = std::max(yr, rec2.yr);

    Rectangle rec_un = Rectangle(uxl, uyl, uxr, uyr);

    return rec_un;
}

bool Rectangle::is_point_on(double x, double y, Rectangle &rec) {
    if ((x >= rec.xl) && (x <= rec.xr) && (y >= rec.yl) && (y <= rec.yr)) {
        return true;
    } else {
        return false;
    }
}
