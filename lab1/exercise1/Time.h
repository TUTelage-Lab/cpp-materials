#ifndef LAB1_TIME_H
#define LAB1_TIME_H


class Time {
private:
    short hour, minute, second;

public:
    Time();

    ~Time();

    void setTime(short hour, short minute, short second);

    void printTime() const;
};


#endif //LAB1_TIME_H
