#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure {
public:
    Square(double x = 0, double y = 0, double r = 1);
    
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    
    // Конструкторы и операторы
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
};

#endif