//
// Created by Ivan Nikolov on 25.09.26.
//

#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H


class Triangle {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c);

    double face() const;

    void show(const char *) const;

    ~Triangle();
};


#endif //LAB1_TRIANGLE_H
