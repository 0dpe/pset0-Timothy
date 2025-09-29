#include <string>
#include <iostream>

using std::string;

struct Car {
    string make;
    string model;
    int year;
};

Car makeCar(string make, string model, int year) {
    Car c;
    c.make = make;
    c.model = model;
    c.year = year;

    return c;
}

int main() {
    Car c = makeCar("Toyota", "Corolla", 2015);
    std::cout << c.make << " " << c.model << " " << c.year << std::endl;
}