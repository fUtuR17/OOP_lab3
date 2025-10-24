#include "Square.h"
#include <cmath>
#include <iostream>

Square::Square(double x, double y, double r) 
    : Figure(x, y, r, 6) {}

double Square::area() const {
    return (2 * radius * radius);
}

void Square::printVertices(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        double angle = 2 * M_PI * i / 4;
        double x = center_x + radius * std::cos(angle);
        double y = center_y + radius * std::sin(angle);
        os << "(" << x << ", " << y << ") ";
    }
}

void Square::readFromStream(std::istream& is) {
    is >> center_x >> center_y >> radius;
    sides = 4;
}

Square::Square(const Square& other) : Figure(other) {}

Square::Square(Square&& other) noexcept : Figure(std::move(other)) {}

Square& Square::operator=(const Square& other) {
    Figure::operator=(other);
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    Figure::operator=(std::move(other));
    return *this;
}