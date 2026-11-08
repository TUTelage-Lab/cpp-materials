#include <iostream>

#include "example1/Vector2D.h"
#include "example2/Fraction.h"
#include "example3/Matrix.h"
#include "example4/Polynomial.h"
#include "exercise1/Complex.h"
#include "exercise2/ConfigMap.h"
#include "exercise2/CircularBuffer.h"
#include "exercise2/LoggedPtr.h"
#include "exercise3/DynArray.h"

namespace {
    class BankAccount {
        std::string owner;
        double balance;

    public:
        BankAccount(std::string owner, double balance) : owner(std::move(owner)), balance(balance) {
        }

        void deposit(double amount) {
            balance += amount;
            std::cout << owner << " deposit " << amount << " — balance: " << balance << "\n";
        }

        void describe() const {
            std::cout << "Account owner: " << owner << ", balance: " << balance << "\n";
        }
    };
}

static void callExample1();

static void callExample2();

static void callExample3();

static void callExample4();

static void callExercise1();

static void callExercise2();

static void callExercise3();

int main() {
    callExample1();
    std::cout << "\n";
    callExample2();
    std::cout << "\n";
    callExample3();
    std::cout << "\n";
    callExample4();
    std::cout << "\n";
    callExercise1();
    std::cout << "\n";
    callExercise2();
    std::cout << "\n";
    callExercise3();
    return 0;
}

static void callExample1() {
    Vector2D v1(3.0, 4.0), v2(1.0, 2.0), v3(0.5, 0.5);

    std::cout << "v1 = ";
    v1.print();
    std::cout << "\n";
    std::cout << "v2 = ";
    v2.print();
    std::cout << "\n";

    Vector2D sum = v1 + v2;
    std::cout << "v1 + v2 = ";
    sum.print();
    std::cout << "\n";

    // chain operation: v1 + v2 - v3
    Vector2D chain = v1 + v2 - v3;
    std::cout << "v1 + v2 - v3 = ";
    chain.print();
    std::cout << "\n";

    Vector2D scaled = v1 * 2.0;
    std::cout << "v1 * 2 = ";
    scaled.print();
    std::cout << "\n";

    std::cout << "|v1| = " << v1.magnitude() << "\n";
    std::cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << "\n";
    std::cout << "v1 != v2: " << (v1 != v2 ? "true" : "false") << "\n";
}

static void callExample2() {
    Fraction a(1, 2), b(1, 3), c(2, -4); // c is reduced to -1/2

    std::cout << "a = ";
    a.print();
    std::cout << "\n";
    std::cout << "b = ";
    b.print();
    std::cout << "\n";
    std::cout << "c = ";
    c.print();
    std::cout << " (from 2/-4)\n";

    Fraction sum = a + b;
    std::cout << "a + b = ";
    sum.print();
    std::cout << "\n";

    Fraction diff = a - b;
    std::cout << "a - b = ";
    diff.print();
    std::cout << "\n";

    Fraction prod = a * b;
    std::cout << "a * b = ";
    prod.print();
    std::cout << "\n";

    Fraction quot = a / b;
    std::cout << "a / b = ";
    quot.print();
    std::cout << "\n";

    // (1/2 + 1/3) * 2/1
    Fraction chain = (a + b) * Fraction(2);
    std::cout << "(a + b) * 2 = ";
    chain.print();
    std::cout << "\n";

    std::cout << "a == c: " << (a == c ? "true" : "false") << "\n";
}

static void callExample3() {
    Matrix a(2, 2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;

    Matrix b(2, 2);
    b(0, 0) = 5;
    b(0, 1) = 6;
    b(1, 0) = 7;
    b(1, 1) = 8;

    Matrix x = a;
    std::cout << "x = a:\n" << x << "\n";

    x += b;
    std::cout << "x += b:\n" << x << "\n";

    std::cout << "a + b:\n" << a + b << "\n";
    std::cout << "a * 3:\n" << a * 3 << "\n";

    Matrix p(2, 3);
    p(0, 0) = 1;
    p(0, 1) = 2;
    p(0, 2) = 3;
    p(1, 0) = 4;
    p(1, 1) = 5;
    p(1, 2) = 6;

    Matrix q(3, 2);
    q(0, 0) = 1;
    q(0, 1) = 2;
    q(1, 0) = 3;
    q(1, 1) = 4;
    q(2, 0) = 5;
    q(2, 1) = 6;

    std::cout << "p (2x3):\n" << p << "\n";
    std::cout << "q (3x2):\n" << q << "\n";
    std::cout << "p * q (2x2):\n" << p * q << "\n";
}

static void callExample4() {
    Polynomial p1(2);
    p1[2] = 3;
    p1[1] = 2;
    p1[0] = 1; // 3x^2 + 2x + 1

    Polynomial p2(3);
    p2[3] = 1;
    p2[1] = -1;
    p2[0] = 4; // x^2 - x + 4

    std::cout << "p1 = " << p1 << "\n";
    std::cout << "p2 = " << p2 << "\n";
    std::cout << "p1 + p2 = " << p1 + p2 << "\n";

    // modify via operator[] and verify operator= (deep copy)
    Polynomial p3 = p1;
    p3[0] = 99;
    std::cout << "p3 (copy of p1, p3[0]=99) = " << p3 << "\n";
    std::cout << "p1 unchanged = " << p1 << "\n";
}

static void callExercise1() {
    Complex z1(3.0, 4.0), z2(1.0, -2.0);

    std::cout << "z1 = " << z1 << "\n";
    std::cout << "z2 = " << z2 << "\n";
    std::cout << "z1 + z2 = " << z1 + z2 << "\n";
    std::cout << "z1 - z2 = " << z1 - z2 << "\n";
    std::cout << "z1 * z2 = " << z1 * z2 << "\n";
    std::cout << "z1 / z2 = " << z1 / z2 << "\n";
    std::cout << "-z1 = " << -z1 << "\n";
    std::cout << "(z1 + z2) * (-z1) = " << (z1 + z2) * (-z1) << "\n";
    std::cout << "|z1| = " << z1.magnitude() << "\n";
    std::cout << "|z2| = " << z2.magnitude() << "\n";
}

static void callExercise2() {
    ConfigMap cfg;
    cfg["host"] = "localhost";
    cfg["port"] = "5432";
    cfg["db"] = "mydb";
    cfg["user"] = "admin";
    std::cout << cfg;

    ConfigMap copy = cfg;
    copy["host"] = "remotehost";
    std::cout << "original host: " << cfg["host"] << "\n";
    std::cout << "copy host:     " << copy["host"] << "\n";

    std::cout << "\n";

    CircularBuffer buf(5);
    for (int i = 1; i <= 7; i++) {
        buf.push(i * 1.0);
    }
    std::cout << "buf after pushing 1-7 (capacity 5): " << buf << "\n";
    std::cout << "buf[0] (newest) = " << buf[0] << "\n";
    std::cout << "buf[4] (oldest) = " << buf[4] << "\n";

    std::cout << "\n";

    LoggedPtr p(new BankAccount("Andrei", 1000.0));
    p->deposit(500.0);
    p->describe();

    LoggedPtr<BankAccount> p2(nullptr);
    p2 = p; // ownership transfer: p becomes nullptr
    std::cout << "transferred to p2:\n";
    p2->describe();
}

static void callExercise3() {
    DynArray a(5), b(3);
    a.push(1);
    a.push(2);
    a.push(3);
    b.push(4);
    b.push(5);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    a[0] = 10;
    std::cout << "a after a[0]=10: " << a << "\n";

    DynArray c = a + b;
    std::cout << "a + b = " << c << "\n";

    DynArray a2(3);
    a2.push(10);
    a2.push(2);
    a2.push(3);
    std::cout << "a == a2: " << (a == a2 ? "true" : "false") << "\n";
    std::cout << "a != b:  " << (a != b ? "true" : "false") << "\n";
}
