#include "Worker.h"

Worker::Worker(const char *id, const char *name) : id(id), name(name) {
}

Worker::Worker(const char *id, const char *name, const char *position) {
    this->id = id;
    this->name = name;
    this->position = position;
}

Worker::~Worker() {
    delete[] salaries;
}

const char *Worker::getId() const {
    return id;
}

const char *Worker::getName() const {
    return name;
}

const char *Worker::getPosition() const {
    return position;
}

short Worker::getYearsOfService() const {
    return yearsOfService;
}

void Worker::setId(const char *id) {
    this->id = id;
}

void Worker::setName(const char *name) {
    this->name = name;
}

void Worker::setPosition(const char *position) {
    this->position = position;
}

void Worker::setYearsOfService(short y) {
    yearsOfService = y;
}

void Worker::setSalaries(const double *newSalaries, int count) {
    salaries = new double[count];
    salariesCount = count;
    for (int i = 0; i < count; i++) {
        salaries[i] = newSalaries[i];
    }
}

void Worker::setSalariesArray(const double *newSalaries, int count) {
    salariesArrayCount = count;
    for (int i = 0; i < salariesArrayCount; i++) {
        salariesArray[i] = newSalaries[i];
    }
}

double Worker::getAvgSalary() const {
    if (salariesCount == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < salariesCount; i++) {
        sum += salaries[i];
    }
    return sum / salariesCount;
}

double Worker::getMinSalary() const {
    if (salariesCount == 0) {
        return 0.0;
    }

    double min = salaries[0];
    for (int i = 1; i < salariesCount; i++) {
        if (salaries[i] < min) {
            // TODO: Is this the best way to compare doubles?
            min = salaries[i];
        }
    }

    return min;
}

double Worker::getAvgSalaryArray() const {
    if (salariesArrayCount == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < salariesArrayCount; i++) {
        sum += salariesArray[i];
    }
    return sum / salariesArrayCount;
}

double Worker::getMinSalaryArray() const {
    if (salariesArrayCount == 0) {
        return 0.0;
    }

    double min = salariesArray[0];
    for (int i = 1; i < salariesArrayCount; i++) {
        if (salariesArray[i] < min) {
            min = salariesArray[i];
        }
    }
    return min;
}
