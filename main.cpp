// This code was written with the assistance of AI.
// AI was used to help improve and fix bugs in the code.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include "Shape.h"
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& s : shapes) {
        s->display();
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Area: " << s->getArea() << "\n\n";
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cout << "Invalid rectangle data on line " << lineNum << "\n";
            }
        }
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cout << "Invalid circle data on line " << lineNum << "\n";
            }
        }
        else if (!type.empty()) {
            std::cout << "Unknown shape type on line " << lineNum << "\n";
        }
    }

    printAllAreas(shapes);
    return 0;
}