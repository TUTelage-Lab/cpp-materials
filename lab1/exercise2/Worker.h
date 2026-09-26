#ifndef LAB1_WORKER_H
#define LAB1_WORKER_H


class Worker {
private:
    const char *id, *name, *position;
    short yearsOfService;

    // Dynamic array — size determined at runtime
    double *salaries;
    int salariesCount;

    // Static array — size fixed at compile time
    double salariesArray[1000];
    int salariesArrayCount;

public:
    Worker(const char *id, const char *name);

    Worker(const char *id, const char *name, const char *position);

    ~Worker();

    // Getters
    const char *getId() const;

    const char *getName() const;

    const char *getPosition() const;

    short getYearsOfService() const;

    // Setters
    void setId(const char *id);

    void setName(const char *name);

    void setPosition(const char *position);

    void setYearsOfService(short yearsOfService);

    void setSalaries(const double *s, int count);

    void setSalariesArray(const double *s, int count);

    // Methods — dynamic array
    double getAvgSalary() const;

    double getMinSalary() const;

    // Methods — static array
    double getAvgSalaryArray() const;

    double getMinSalaryArray() const;
};


#endif //LAB1_WORKER_H
