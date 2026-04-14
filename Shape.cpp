#include "Shape.h"
#include <iostream>
#include <cmath>

void Shape::display() const {
    std::cout << "Shape" << std::endl;
}


Rectangle::Rectangle(double w, double h)
    : width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << width << " x " << height << ")" << std::endl;
}


Circle::Circle(double r)
    : radius(r) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

void Circle::display() const {
    std::cout << "Circle (radius: " << radius << ")" << std::endl;
}