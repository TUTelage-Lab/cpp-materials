# 2. Предефинирани функции. Приятелски функции

## 1. Предефинирани функции (Function Overloading)

Езикът C++ позволява няколко функции да носят едно и също име, стига да се различават по **брой, тип или ред на
параметрите**. Компилаторът избира точното предефинирано копие на базата на подадените аргументи — това се нарича
**статичен полиморфизъм** (решава се по време на компилация).

Правила:

- Две функции **не могат** да се различават само по тип на върнатия резултат.
- Параметрите трябва да се различават по тип, брой или ред.
- Компилаторът търси **най-точното** съвпадение; ако намери повече от едно еднакво добро — грешка при компилация.

### Пример 1: клас `BankAccount` — предефиниране на `deposit()`

Имаме банкова сметка. Искаме да можем да внасяме сума по три начина:

- само сума (без комисиона);
- сума + фиксирана комисиона;
- сума + процентна комисиона (double).

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double initialBalance)
        : owner(owner), balance(initialBalance) {}

    // Вариант 1: внасяне без комисиона
    void deposit(double amount) {
        balance += amount;
        std::cout << "Внесени " << amount << " лв. Баланс: " << balance << " лв.\n";
    }

    // Вариант 2: внасяне с фиксирана комисиона
    void deposit(double amount, double fee) {
        balance += amount - fee;
        std::cout << "Внесени " << amount << " лв., комисиона " << fee
                  << " лв. Баланс: " << balance << " лв.\n";
    }

    // Вариант 3: внасяне с процентна комисиона
    void deposit(double amount, double feePercent, bool isPercent) {
        double fee = isPercent ? amount * feePercent / 100.0 : feePercent;
        balance += amount - fee;
        std::cout << "Внесени " << amount << " лв., комисиона " << feePercent
                  << "%. Баланс: " << balance << " лв.\n";
    }

    double getBalance() const { return balance; }
    const std::string& getOwner() const { return owner; }
};

int main() {
    BankAccount acc("Иван Петров", 1000.0);

    acc.deposit(500.0);                  // извиква вариант 1
    acc.deposit(200.0, 5.0);             // извиква вариант 2
    acc.deposit(300.0, 1.5, true);       // извиква вариант 3

    return 0;
}
```

**Резултати:**

```text
Внесени 500 лв. Баланс: 1500 лв.
Внесени 200 лв., комисиона 5 лв. Баланс: 1695 лв.
Внесени 300 лв., комисиона 1.5%. Баланс: 1990.5 лв.
```

### Пример 2: клас `Logger` — предефиниране на `log()`

Логер, който може да записва съобщения от различен тип.

```cpp
#include <iostream>
#include <string>

class Logger {
private:
    std::string prefix;

public:
    explicit Logger(const std::string& prefix) : prefix(prefix) {}

    // Логване на текст
    void log(const std::string& message) {
        std::cout << "[" << prefix << "] " << message << "\n";
    }

    // Логване на цяло число
    void log(int code) {
        std::cout << "[" << prefix << "] Код: " << code << "\n";
    }

    // Логване на текст + код
    void log(const std::string& message, int code) {
        std::cout << "[" << prefix << "] " << message << " (код: " << code << ")\n";
    }

    // Логване на текст + стойност от тип double
    void log(const std::string& message, double value) {
        std::cout << "[" << prefix << "] " << message << " = " << value << "\n";
    }
};

int main() {
    Logger logger("APP");

    logger.log("Стартиране на приложението");
    logger.log(200);
    logger.log("Грешка при свързване", 503);
    logger.log("Използвана памет (MB)", 128.5);

    return 0;
}
```

**Резултати:**

```text
[APP] Стартиране на приложението
[APP] Код: 200
[APP] Грешка при свързване (код: 503)
[APP] Използвана памет (MB) = 128.5
```

---

## 2. Приятелски функции (`friend`)

Приятелската функция **не е член-функция** на класа, но има достъп до неговите `private` и `protected` членове.
Декларира се вътре в класа с ключовата дума `friend`, но се **дефинира извън него** като обикновена функция.

Кога се използва:

- Когато една функция трябва да достъпи `private` данни на **два или повече** различни класа.
- Когато искаме да предефинираме оператори, които изискват достъп до `private` данни (ще видим в Лаб 6).

> Приятелските функции не получават указателя `this` — затова обектът трябва да се подаде **явно** като параметър.

### 2.1. Независима функция — приятелска за два класа

#### Пример 3: сравняване на банкова сметка и кредит

```cpp
#include <iostream>
#include <string>

class Loan; // Предварителна декларация — нужна е, защото BankAccount използва Loan

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double balance)
        : owner(owner), balance(balance) {}

    // Приятелска функция — има достъп до private членовете и на двата класа
    friend void printFinancialSummary(const BankAccount& acc, const Loan& loan);
};

class Loan {
private:
    std::string owner;
    double debt;
    double interestRate; // в проценти

public:
    Loan(const std::string& owner, double debt, double interestRate)
        : owner(owner), debt(debt), interestRate(interestRate) {}

    friend void printFinancialSummary(const BankAccount& acc, const Loan& loan);
};

// Независима приятелска функция — достъпва private полета и на двата класа
void printFinancialSummary(const BankAccount& acc, const Loan& loan) {
    double netWorth = acc.balance - loan.debt;
    std::cout << "=== Финансово резюме за: " << acc.owner << " ===\n";
    std::cout << "  Баланс по сметка:  " << acc.balance << " лв.\n";
    std::cout << "  Дълг по кредит:    " << loan.debt << " лв. ("
              << loan.interestRate << "% лихва)\n";
    std::cout << "  Нетна стойност:    " << netWorth << " лв.\n";
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
=== Финансово резюме за: Мария Иванова ===
  Баланс по сметка:  5000 лв.
  Дълг по кредит:    12000 лв. (4.5% лихва)
  Нетна стойност:    -7000 лв.
```

### 2.2. Член-функция на един клас — приятелска за друг клас

Когато искаме само **определена метода** на клас `A` да има достъп до `private` членовете на клас `B`,
декларираме именно нея като `friend` в `B`, с пълното й квалифицирано име (`A::method`).

#### Пример 4: клас `Warehouse` и клас `Audit`

```cpp
#include <iostream>
#include <string>

class Warehouse; // Предварителна декларация

class Audit {
private:
    std::string auditorName;

public:
    explicit Audit(const std::string& name) : auditorName(name) {}

    // Тази член-функция ще бъде приятелска за Warehouse
    void inspect(const Warehouse& w);
};

class Warehouse {
private:
    std::string name;
    int itemCount;
    double totalValue;

public:
    Warehouse(const std::string& name, int items, double value)
        : name(name), itemCount(items), totalValue(value) {}

    // Само Audit::inspect има достъп до private данните — не целият клас Audit
    friend void Audit::inspect(const Warehouse& w);
};

void Audit::inspect(const Warehouse& w) {
    std::cout << "=== Одит от: " << auditorName << " ===\n";
    std::cout << "  Склад:         " << w.name << "\n";
    std::cout << "  Брой артикули: " << w.itemCount << "\n";
    std::cout << "  Обща стойност: " << w.totalValue << " лв.\n";
    std::cout << "  Ср. стойност:  " << w.totalValue / w.itemCount << " лв./бр.\n";
}

int main() {
    Warehouse w1("Склад София", 340, 85000.0);
    Warehouse w2("Склад Пловдив", 120, 22000.0);
    Audit auditor("Петър Стоянов");

    auditor.inspect(w1);
    std::cout << "\n";
    auditor.inspect(w2);

    return 0;
}
```

**Резултати:**

```text
=== Одит от: Петър Стоянов ===
  Склад:         Склад София
  Брой артикули: 340
  Обща стойност: 85000 лв.
  Ср. стойност:  250 лв./бр.

=== Одит от: Петър Стоянов ===
  Склад:         Склад Пловдив
  Брой артикули: 120
  Обща стойност: 22000 лв.
  Ср. стойност:  183.333 лв./бр.
```

---

## Задачи за самостоятелна работа

### Задача 1 — Метеорологична станция

Дефинирайте клас `Sensor` (сензор), който измерва температура. Класът има `private` поле `celsius` (double) и подходящ
конструктор.

**Предефинирайте** член-функцията `read()`:

| Сигнатура                                       | Описание                                                                        |
|-------------------------------------------------|---------------------------------------------------------------------------------|
| `double read()`                                 | Връща стойността в Целзий                                                       |
| `double read(char scale)`                       | Конвертира в `'F'` (Фаренхайт: `C * 9/5 + 32`) или `'K'` (Келвин: `C + 273.15`) |
| `void read(double& fahrenheit, double& kelvin)` | Връща и двете стойности едновременно чрез псевдоними                            |

**Предефинирайте** член-функцията `describe()`:

| Сигнатура                                                | Описание                                               |
|----------------------------------------------------------|--------------------------------------------------------|
| `void describe()`                                        | Отпечатва само стойността в Целзий                     |
| `void describe(const std::string& location)`             | Отпечатва локацията и стойността: `"[location]: X °C"` |
| `void describe(const std::string& location, char scale)` | Отпечатва локацията и стойността в избраната скала     |

Демонстрирайте всички варианти в `main()` с поне два сензора (на различни локации).

---

### Задача 2 — Система за записване в курсове

Дефинирайте клас `Student` с `private` полета: `name` (string), `facultyNumber` (char[10]).

Дефинирайте клас `Course` с `private` полета: `title` (string), `maxStudents` (int), `currentStudents` (int).

**Част А — независима приятелска функция:**

Дефинирайте функция `enroll(Student& s, Course& c)`, приятелска и за двата класа, която:

- Проверява дали има свободни места (`currentStudents < maxStudents`);
- При успех — увеличава `currentStudents` и отпечатва потвърждение;
- При неуспех — отпечатва конкретната причина за отказ.

**Част Б — член-функция като приятелска:**

Добавете клас `Registrar` с член-функция `printReport(const Course& c)`, декларирана като приятелска **само на
`Course`** (не на целия клас), която отпечатва:

- Заглавие на курса;
- Брой записани / максимален брой студенти;
- Процент запълненост.

Демонстрирайте в `main()`: запишете поне трима студенти с различен успех, след което извикайте `printReport()`.

---

## Допълнителни задачи

### Задача 5 — Стек с предефинирани функции

Напишете клас `Stack` за символи. Предефинирайте функцията `load()`:

- `void load()` — напълва стека с малки букви `a-z`;
- `void load(bool upper)` — ако `upper` е `true`, напълва с главни букви `A-Z`;
- `void load(char from, char to)` — напълва стека с букви в диапазона `[from, to]`.

### Задача 6 — Споделен ресурс

Два класа `Printer` и `Scanner` споделят едно USB устройство (моделирано като `bool usbInUse`).

Напишете приятелска функция `bool isUsbBusy(const Printer& p, const Scanner& s)`, която връща `true`, ако някой от двата
класа в момента използва USB. Демонстрирайте с обекти в `main()`.
