# 3. Псевдоними

Псевдонимът (`reference`) е **алтернативно име за вече съществуваща променлива**. За разлика от указателя, той не е
отделна променлива — той е буквално друго име за същото място в паметта. Декларира се с `&` след типа:

```cpp
int x = 5;
int& r = x;   // r е псевдоним за x — сочат едно и също място в паметта

r = 10;       // променя x
std::cout << x;  // отпечатва 10
```

Три начина за използване:

- псевдонимът може да бъде **предаван на функция** (избягва се копиране);
- псевдонимът може да бъде **връщан като резултат** от функция (позволява присвояване от лявата страна);
- може да бъде създаван **независим псевдоним** (рядко — вижте Пример 0).

> Псевдонимът не е указател. Когато обект се подава чрез псевдоним, операторът за достъп до член си остава **точка**
> (`.`), а не стрелка (`->`).

---

## Пример 0: самостоятелен псевдоним и разлика с указател

```cpp
#include <iostream>

int main() {
    int x = 5;

    int& ref = x;     // псевдоним — ref и x са едно и също
    int* ptr = &x;    // указател — ptr съдържа адреса на x

    ref = 10;
    std::cout << "x чрез псевдоним: " << ref << "\n";  // 10
    std::cout << "x директно:       " << x   << "\n";  // 10

    *ptr = 20;
    std::cout << "x чрез указател:  " << *ptr << "\n"; // 20
    std::cout << "x директно:       " << x    << "\n"; // 20

    // Ключова разлика: псевдонимът не може да бъде пренасочен
    int y = 99;
    // ref = y;    // НЕ пренасочва ref към y — копира стойността на y в x
    ptr = &y;      // OK — указателят може да се пренасочи към y

    std::cout << "x след ref = y: " << x << "\n";   // 20 (не 99!)
    std::cout << "y чрез ptr:     " << *ptr << "\n"; // 99

    return 0;
}
```

**Резултати:**

```text
x чрез псевдоним: 10
x директно:       10
x чрез указател:  20
x директно:       20
x след ref = y: 20
y чрез ptr:     99
```

---

## 1. Псевдоним като параметър на функция

Когато обект се предава **по стойност**, се създава копие и се извиква деструкторът му при излизане от функцията.
При класове с динамична памет това може да доведе до двойно освобождаване (`double free`).

При предаване **по псевдоним** не се създава копие — функцията работи директно с оригиналния обект.
Ако обектът не трябва да се променя, се използва `const&`.

### Пример 1: по стойност vs. по псевдоним — кога се извиква деструкторът

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double balance)
        : owner(owner), balance(balance) {
        std::cout << "Конструктор: " << owner << "\n";
    }

    ~BankAccount() {
        std::cout << "Деструктор:  " << owner << "\n";
    }

    double getBalance() const { return balance; }
    const std::string& getOwner() const { return owner; }

    void deposit(double amount) { balance += amount; }
    void deposit(double amount, double fee) { balance += amount - fee; }
};

// Приема по СТОЙНОСТ — създава копие, деструкторът се извиква при излизане
void printByValue(BankAccount acc) {
    std::cout << "[by value] " << acc.getOwner()
              << ": " << acc.getBalance() << " лв.\n";
}

// Приема по ПСЕВДОНИМ — без копие, без излишен деструктор
void printByRef(const BankAccount& acc) {
    std::cout << "[by ref]   " << acc.getOwner()
              << ": " << acc.getBalance() << " лв.\n";
}

int main() {
    BankAccount acc("Иван Петров", 1000.0);
    acc.deposit(500.0);
    acc.deposit(200.0, 5.0);

    std::cout << "\n--- Извикване по стойност ---\n";
    printByValue(acc);   // деструкторът на копието се извиква тук!

    std::cout << "\n--- Извикване по псевдоним ---\n";
    printByRef(acc);     // без копие, без деструктор

    std::cout << "\n--- Край на main ---\n";
    return 0;
}
```

**Резултати:**

```text
Конструктор: Иван Петров

--- Извикване по стойност ---
[by value] Иван Петров: 1695 лв.
Деструктор:  Иван Петров        ← копието се унищожава тук

--- Извикване по псевдоним ---
[by ref]   Иван Петров: 1695 лв.

--- Край на main ---
Деструктор:  Иван Петров        ← оригиналът се унищожава тук
```

### Пример 2: `friend` функция с псевдоними

Приятелска функция, която приема два обекта по `const&` и ги сравнява, без да ги копира.

```cpp
#include <iostream>
#include <string>

class Loan;

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double balance)
        : owner(owner), balance(balance) {}

    friend void printFinancialSummary(const BankAccount& acc, const Loan& loan);
};

class Loan {
private:
    std::string owner;
    double debt;
    double interestRate;

public:
    Loan(const std::string& owner, double debt, double rate)
        : owner(owner), debt(debt), interestRate(rate) {}

    friend void printFinancialSummary(const BankAccount& acc, const Loan& loan);
};

// const& — нито копие, нито промяна; достъп до private чрез friend
void printFinancialSummary(const BankAccount& acc, const Loan& loan) {
    double netWorth = acc.balance - loan.debt;
    std::cout << "=== " << acc.owner << " ===\n";
    std::cout << "  Баланс:       " << acc.balance << " лв.\n";
    std::cout << "  Дълг:         " << loan.debt
              << " лв. (" << loan.interestRate << "% лихва)\n";
    std::cout << "  Нетна стойност: " << netWorth << " лв.\n";
}

int main() {
    BankAccount acc("Мария Иванова", 5000.0);
    Loan loan("Мария Иванова", 12000.0, 4.5);

    printFinancialSummary(acc, loan);
    return 0;
}
```

**Резултати:**

```text
=== Мария Иванова ===
  Баланс:       5000 лв.
  Дълг:         12000 лв. (4.5% лихва)
  Нетна стойност: -7000 лв.
```

---

## 2. Псевдоним като върнат резултат от функция

Функция, която връща `T&`, може да стои от **лявата страна на присвояване**. Това е техника за изграждане
на класове с индексиране (като масиви, таблици, регистри).

> **Внимание:** никога не връщай псевдоним към локална променлива — тя се унищожава при излизане от функцията.

### Пример 3: клас `Sensor` с масив от показания — връщане на псевдоним

Разширяваме `Sensor` от Лаб 2 с история на показанията. `operator[]` връща псевдоним, което позволява директно
записване в масива.

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

class Sensor {
private:
    std::string location;
    double* readings;
    int capacity;
    int count;

public:
    Sensor(const std::string& location, int capacity)
        : location(location), capacity(capacity), count(0) {
        readings = new double[capacity];
        std::cout << "Sensor [" << location << "] създаден\n";
    }

    ~Sensor() {
        delete[] readings;
        std::cout << "Sensor [" << location << "] унищожен\n";
    }

    // Връща псевдоним — може да се използва от лявата страна на присвояване
    double& record(int i) {
        if (i < 0 || i >= capacity) {
            std::cout << "Грешка: индекс извън граница!\n";
            std::exit(1);
        }
        if (i >= count) count = i + 1;
        return readings[i];
    }

    // Връща константен псевдоним — само четене
    const double& get(int i) const {
        if (i < 0 || i >= count) {
            std::cout << "Грешка: индекс извън граница!\n";
            std::exit(1);
        }
        return readings[i];
    }

    void printAll() const {
        std::cout << "Sensor [" << location << "]: ";
        for (int i = 0; i < count; i++)
            std::cout << readings[i] << (i < count - 1 ? ", " : "\n");
    }
};

int main() {
    Sensor s("София", 5);

    // record() връща псевдоним — присвояването записва директно в масива
    s.record(0) = 22.5;
    s.record(1) = 23.1;
    s.record(2) = 21.8;
    s.record(3) = 24.0;
    s.record(4) = 22.9;

    s.printAll();

    // get() връща const& — само четене, не може да се присвоява
    std::cout << "Показание [2]: " << s.get(2) << "\n";
    // s.get(2) = 99.9;  // ГРЕШКА при компилация — const&

    // Извън граница — грешка по време на изпълнение
    s.record(10) = 0.0;

    return 0;
}
```

**Резултати:**

```text
Sensor [София] създаден
Sensor [София]: 22.5, 23.1, 21.8, 24, 22.9
Показание [2]: 21.8
Грешка: индекс извън граница!
```

---

## Задачи за самостоятелна работа

### Задача 1 — Система за оценки

Дефинирайте клас `Student` с `private` полета:

- `std::string name` — името на студента;
- `std::string facultyNumber` — факултетен номер;
- `double* grades` — динамичен масив от оценки;
- `int capacity` — капацитет на масива;
- `int gradeCount` — брой добавени оценки.

Класът трябва да има:

- конструктор `Student(const std::string& name, const std::string& fn, int capacity = 10)` — заделя масива с `new`;
- деструктор, който освобождава масива с `delete[]`;
- метод `void addGrade(double grade)` — добавя оценка в масива;
- метод `double& getBest()` — **псевдоним** към най-високата оценка (позволява директна корекция);
- метод `const double& getByIndex(int i) const` — **константен псевдоним** за четене на оценка по индекс;
- метод `double getAverage() const` — средна оценка;
- метод `void print() const` — отпечатва името, факултетния номер и всички оценки.

Демонстрирайте:

1. Създайте поне трима студенти и добавете по няколко оценки на всеки.
2. Намерете студента с най-висок среден успех.
3. Използвайте `getBest()`, за да увеличите най-добрата му оценка с `0.25` (ако не е вече `6.00`).
4. Напишете функция `void summarize(const Student& s)`, която приема студент по `const&` и го отпечатва — без копиране.

---

### Задача 2 — Регистър на курсове

Дефинирайте два класа:

**`Student`** с `private` полета `std::string name` и `std::string facultyNumber`, и конструктор
`Student(const std::string& name, const std::string& fn)`.

**`Course`** с `private` полета:

- `std::string title` — заглавие на курса;
- `int maxStudents` — максимален брой места;
- `int currentStudents` — брой записани студенти;
- `Student** enrolled` — динамичен масив от указатели към записани студенти.

Класът `Course` трябва да има:

- конструктор `Course(const std::string& title, int maxStudents)` — заделя `enrolled` с `new`;
- деструктор, който освобождава `enrolled` (но **не** самите студенти);
- метод `void enroll(Student& s)` — записва студент (проверява дали има свободни места);
- метод `Student& getEnrolled(int i)` — **псевдоним** към записан студент по индекс;
- метод `const Student& getEnrolled(int i) const` — константен вариант (предефинирана функция);
- приятелска функция `void transfer(Student& s, Course& from, Course& to)`, декларирана `friend` и в двата класа, която
  премахва студента от `from`, добавя го в `to` и отпечатва съобщение;
- приятелска функция `void printReport(const Course& c)`, която отпечатва заглавието, брой записани / максимален брой
  и процент запълненост, като достъпва `private` полетата директно.

Демонстрирайте: създайте два курса, запишете трима студенти в единия, прехвърлете един в другия, извикайте
`printReport()` и за двата.

---

## Допълнителни задачи

### Задача 3 — Таблица с резултати

Дефинирайте клас `ScoreTable` с `private` полета:

- `double** table` — двумерен динамичен масив (редове = играчи, колони = рундове);
- `int rows`, `int cols` — размери на таблицата.

Класът трябва да има:

- конструктор `ScoreTable(int rows, int cols)` — заделя паметта ред по ред;
- деструктор — освобождава паметта ред по ред;
- метод `double& at(int row, int col)` — **псевдоним** за запис;
- метод `const double& at(int row, int col) const` — константен вариант за четене;
- метод `void fillRow(int row, const double* scores, int count)` — попълва ред, като използва `at()`;
- приятелска функция `void compareRows(const ScoreTable& t, int row1, int row2)`, която изчислява и сравнява средните
  резултати на двата реда, без да копира таблицата.
