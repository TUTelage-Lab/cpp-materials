#ifndef LAB3_SENSOR_H
#define LAB3_SENSOR_H
#include <string>


class Sensor {
private:
    std::string location;
    double *readings;
    int capacity, count = 0;

public:
    Sensor(const std::string &location, int capacity);

    ~Sensor();

    double &record(int i);

    const double &get(int i) const;

    void print() const;
};


#endif //LAB3_SENSOR_H
