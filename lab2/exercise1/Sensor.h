#ifndef LAB2_SENSOR_H
#define LAB2_SENSOR_H
#include <string>


class Sensor {
private:
    double celsius;

public:
    explicit Sensor(double celsius);

    double read() const;

    double read(char scale) const;

    void read(double &fahrenheit, double &kelvin) const;

    void describe() const;

    void describe(const std::string &location) const;

    void describe(const std::string &location, char scale) const;
};


#endif //LAB2_SENSOR_H
