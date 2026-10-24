# 4. Наследяване

Наследяването позволява един клас да **преизползва** дефиницията на друг и да я разширява. Класът, от
който се наследява, се нарича **базов** (или родителски), а класът, който наследява — **производен** (или
дъщерен).

```cpp
class ИмеПроизводен : тип-достъп ИмеБазов {
    // допълнителни полета и методи
};
```

Трите нива на достъп при наследяване:

| Наследяване | `public` в базов | `protected` в базов | `private` в базов |
|-------------|------------------|---------------------|-------------------|
| `public`    | `public`         | `protected`         | недостъпно        |
| `protected` | `protected`      | `protected`         | недостъпно        |
| `private`   | `private`        | `private`           | недостъпно        |

> `private` членовете на базовия клас **никога** не са достъпни директно в производния клас —
> само чрез `public`/`protected` методи на базовия клас.

---

## 1. Конструктори и деструктори при наследяване

При създаване на обект от производен клас:

1. Първо се изпълнява конструкторът на **базовия** клас.
2. После — конструкторът на **производния** клас.

При унищожаване — редът е **обратен**: производен → базов.

Конструкторът на базовия клас се извиква явно чрез списъка за инициализация:

```cpp
ПроизводенКлас(параметри) : БазовКлас(аргументи) {
    // тяло на производния конструктор
}
```

### Пример 1: ред на конструкторите и деструкторите

Проследяваме реда, в който се изпълняват конструкторите и деструкторите при тристепенна йерархия.

```cpp
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age)
        : name(name), age(age) {
        std::cout << "Animal(\"" << name << "\") конструктор\n";
    }

    ~Animal() {
        std::cout << "Animal(\"" << name << "\") деструктор\n";
    }

    void describe() const {
        std::cout << "Животно: " << name << ", възраст: " << age << " г.\n";
    }
};

class Pet : public Animal {
protected:
    std::string ownerName;

public:
    Pet(const std::string& name, int age, const std::string& owner)
        : Animal(name, age), ownerName(owner) {
        std::cout << "Pet(\"" << name << "\") конструктор\n";
    }

    ~Pet() {
        std::cout << "Pet(\"" << name << "\") деструктор\n";
    }

    void describe() const {
        Animal::describe();
        std::cout << "  Стопанин: " << ownerName << "\n";
    }
};

class Dog : public Pet {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& owner,
        const std::string& breed)
        : Pet(name, age, owner), breed(breed) {
        std::cout << "Dog(\"" << name << "\") конструктор\n";
    }

    ~Dog() {
        std::cout << "Dog(\"" << name << "\") деструктор\n";
    }

    void describe() const {
        Pet::describe();
        std::cout << "  Порода: " << breed << "\n";
    }
};

int main() {
    std::cout << "--- Създаване ---\n";
    Dog d("Рекс", 3, "Иван Петров", "Немска овчарка");

    std::cout << "\n--- Описание ---\n";
    d.describe();

    std::cout << "\n--- Унищожаване ---\n";
    return 0;
}
```

**Резултати:**

```text
--- Създаване ---
Animal("Рекс") конструктор
Pet("Рекс") конструктор
Dog("Рекс") конструктор

--- Описание ---
Животно: Рекс, възраст: 3 г.
  Стопанин: Иван Петров
  Порода: Немска овчарка

--- Унищожаване ---
Dog("Рекс") деструктор
Pet("Рекс") деструктор
Animal("Рекс") деструктор
```

---

## 2. Достъп до членовете на базовия клас

Производният клас достъпва наследените `public` и `protected` членове директно по име.
Когато производният клас **предефинира** метод на базовия, оригиналният може да се извика
с явна квалификация: `БазовКлас::метод()`.

### Пример 2: йерархия на банкови сметки

`Account` е базов клас с основни операции. `SavingsAccount` и `CreditAccount` го разширяват,
като добавят специфично поведение и предефинират `describe()`.

```cpp
#include <iostream>
#include <string>

class Account {
protected:
    std::string owner;
    double balance;
    std::string iban;

public:
    Account(const std::string& owner, const std::string& iban, double initialBalance)
        : owner(owner), iban(iban), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) { std::cout << "Невалидна сума.\n"; return; }
        balance += amount;
        std::cout << "Внесени " << amount << " лв. Баланс: " << balance << " лв.\n";
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            std::cout << "Недостатъчна наличност.\n";
            return false;
        }
        balance -= amount;
        std::cout << "Изтеглени " << amount << " лв. Баланс: " << balance << " лв.\n";
        return true;
    }

    double getBalance() const { return balance; }

    void describe() const {
        std::cout << "IBAN: " << iban << "  |  Титуляр: " << owner
                  << "  |  Баланс: " << balance << " лв.\n";
    }
};

class SavingsAccount : public Account {
private:
    double interestRate; // годишен процент
    int lockMonths;      // срок на заключване

public:
    SavingsAccount(const std::string& owner, const std::string& iban,
                   double initialBalance, double rate, int months)
        : Account(owner, iban, initialBalance),
          interestRate(rate), lockMonths(months) {}

    // Блокира теглене — само начислява лихва
    void applyInterest() {
        double interest = balance * interestRate / 100.0;
        balance += interest;
        std::cout << "Начислена лихва: " << interest << " лв. Нов баланс: "
                  << balance << " лв.\n";
    }

    void describe() const {
        Account::describe(); // извикваме базовия метод
        std::cout << "  [Спестовна] Лихва: " << interestRate
                  << "%, срок: " << lockMonths << " мес.\n";
    }
};

class CreditAccount : public Account {
private:
    double creditLimit;
    double usedCredit;

public:
    CreditAccount(const std::string& owner, const std::string& iban,
                  double initialBalance, double limit)
        : Account(owner, iban, initialBalance), creditLimit(limit), usedCredit(0) {}

    // Позволява теглене и отвъд баланса — до кредитния лимит
    bool withdrawWithCredit(double amount) {
        double available = balance + (creditLimit - usedCredit);
        if (amount > available) {
            std::cout << "Надвишен кредитен лимит.\n";
            return false;
        }
        if (amount <= balance) {
            return Account::withdraw(amount); // стандартно теглене
        }
        double fromCredit = amount - balance;
        balance = 0;
        usedCredit += fromCredit;
        std::cout << "Изтеглени " << amount << " лв. (от кредит: "
                  << fromCredit << " лв.)\n";
        return true;
    }

    void describe() const {
        Account::describe();
        std::cout << "  [Кредитна] Лимит: " << creditLimit
                  << " лв., използван: " << usedCredit << " лв.\n";
    }
};

int main() {
    SavingsAccount savings("Мария Иванова", "BG80BNBG96611020345678", 10000.0, 3.5, 12);
    CreditAccount  credit("Георги Попов",  "BG18RZBB91550123456789",  500.0, 2000.0);

    std::cout << "=== Спестовна сметка ===\n";
    savings.describe();
    savings.deposit(2000.0);
    savings.applyInterest();
    std::cout << "\n";

    std::cout << "=== Кредитна сметка ===\n";
    credit.describe();
    credit.withdrawWithCredit(400.0);  // от баланс
    credit.withdrawWithCredit(300.0);  // частично от кредит
    credit.withdrawWithCredit(2000.0); // надвишава лимита
    std::cout << "\n";
    credit.describe();

    return 0;
}
```

**Резултати:**

```text
=== Спестовна сметка ===
IBAN: BG80BNBG96611020345678  |  Титуляр: Мария Иванова  |  Баланс: 10000 лв.
Внесени 2000 лв. Баланс: 12000 лв.
Начислена лихва: 420 лв. Нов баланс: 12420 лв.

=== Кредитна сметка ===
IBAN: BG18RZBB91550123456789  |  Титуляр: Георги Попов  |  Баланс: 500 лв.
  [Кредитна] Лимит: 2000 лв., използван: 0 лв.
Изтеглени 400 лв. Баланс: 100 лв.
Изтеглени 300 лв. (от кредит: 200 лв.)
Надвишен кредитен лимит.

IBAN: BG18RZBB91550123456789  |  Титуляр: Георги Попов  |  Баланс: 0 лв.
  [Кредитна] Лимит: 2000 лв., използван: 200 лв.
```

---

## 3. `protected` достъп

Полета и методи, декларирани като `protected`, са достъпни в производните класове, но не и
извън йерархията. Това е средното ниво между `private` (само в класа) и `public` (навсякъде).

### Пример 3: геометрични фигури с `protected` помощни методи

```cpp
#include <iostream>
#include <cmath>

class Shape {
protected:
    std::string color;

    // Помощен метод — достъпен само в йерархията
    void printLabel(const std::string& shapeName) const {
        std::cout << shapeName << " [" << color << "]: ";
    }

public:
    explicit Shape(const std::string& color) : color(color) {}

    virtual void printArea() const = 0; // чисто виртуален — ще видим в Лаб 5
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius, const std::string& color)
        : Shape(color), radius(radius) {}

    void printArea() const override {
        printLabel("Кръг");
        std::cout << "радиус=" << radius
                  << ", площ=" << M_PI * radius * radius << "\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h, const std::string& color)
        : Shape(color), width(w), height(h) {}

    void printArea() const override {
        printLabel("Правоъгълник");
        std::cout << width << "x" << height
                  << ", площ=" << width * height << "\n";
    }
};

class RightTriangle : public Shape {
private:
    double base, height;

public:
    RightTriangle(double base, double height, const std::string& color)
        : Shape(color), base(base), height(height) {}

    void printArea() const override {
        printLabel("Правоъгълен триъгълник");
        std::cout << "основа=" << base << ", височина=" << height
                  << ", площ=" << 0.5 * base * height << "\n";
    }
};

int main() {
    Circle        c(5.0, "червен");
    Rectangle     r(4.0, 6.0, "син");
    RightTriangle t(3.0, 8.0, "зелен");

    c.printArea();
    r.printArea();
    t.printArea();

    return 0;
}
```

**Резултати:**

```text
Кръг [червен]: радиус=5, площ=78.5398
Правоъгълник [син]: 4x6, площ=24
Правоъгълен триъгълник [зелен]: основа=3, височина=8, площ=12
```

---

## Задачи за самостоятелна работа

### Задача 1 — Транспортна компания

Дефинирайте йерархия от класове за управление на превозни средства в транспортна компания.

**Базов клас `Vehicle`** с `protected` полета:

- `std::string licensePlate` — регистрационен номер;
- `std::string brand` — марка;
- `int year` — година на производство;
- `double fuelLevel` — ниво на гориво в литри;
- `double fuelCapacity` — максимален резервоар.

Методи:

- конструктор с всички параметри;
- `void refuel(double liters)` — зарежда гориво (не надвишава капацитета);
- `bool canTravel(double km, double consumption) const` — проверява дали горивото стига за дадено разстояние при
  зададен разход (л/100 км);
- `void describe() const` — отпечатва регистрационния номер, марка, година и ниво на гориво.

**Производен клас `Truck`** с допълнителни `private` полета:

- `double maxLoad` — максимален товар в кг;
- `double currentLoad` — текущ товар в кг.

Методи:

- конструктор, предаващ параметрите на `Vehicle`;
- `bool load(double kg)` — натоварва товара (проверява лимита);
- `void unload()` — разтоварва напълно;
- `void describe() const` — извиква `Vehicle::describe()`, след което отпечатва товара.

**Производен клас `Bus`** с допълнителни `private` полета:

- `int maxPassengers` — максимален брой пътници;
- `int currentPassengers` — текущи пътници;
- `std::string route` — маршрут (напр. `"София – Пловдив"`).

Методи:

- конструктор, предаващ параметрите на `Vehicle`;
- `void boardPassengers(int n)` — качва пътници (не надвишава максимума);
- `void exitPassengers(int n)` — слиза пътници;
- `void describe() const` — извиква `Vehicle::describe()`, след което отпечатва маршрута и пътниците.

Демонстрирайте в `main()`:

1. Създайте по два обекта от `Truck` и `Bus`.
2. Заредете ги с гориво, натоварете товар / качете пътници.
3. Проверете с `canTravel()` дали превозните средства могат да извършат зададен маршрут.
4. Отпечатайте информация за всяко превозно средство с `describe()`.

---

### Задача 2 — Система за управление на служители

Дефинирайте йерархия за счетоводна система на фирма.

**Базов клас `Employee`** с `protected` полета:

- `std::string name` — три имена;
- `std::string id` — служебен номер (уникален);
- `int hoursWorked` — отработени часове за месеца.

Методи:

- конструктор с `name`, `id`;
- `void logHours(int hours)` — добавя отработени часове (не повече от 240 на месец);
- `double calcSalary() const` — изчислява заплатата (**чисто виртуален** — всеки подклас дефинира своя формула);
- `void printPayslip() const` — отпечатва фиш: служебен номер, имена, часове и заплата.

> Забележка: `virtual` и `override` ще разгледаме подробно в Лаб 5 — за тази задача е достатъчно да
> дефинирате `calcSalary()` като обикновен виртуален метод и да го предефинирате в производните класове.

**Производен клас `HourlyEmployee`** (почасово заплащане):

- допълнително `private` поле `double hourlyRate` — ставка за час;
- `calcSalary()` → `hoursWorked * hourlyRate`;
- конструктор с `name`, `id`, `hourlyRate`.

**Производен клас `SalariedEmployee`** (фиксирана заплата):

- допълнително `private` поле `double monthlySalary`;
- `calcSalary()` → `monthlySalary` (не зависи от часовете);
- конструктор с `name`, `id`, `monthlySalary`.

**Производен клас `CommissionEmployee`** (продавач на комисиона):

- допълнителни `private` полета `double baseSalary` и `double salesAmount` (сума продажби за месеца);
- `double commissionRate` — процент комисиона;
- `calcSalary()` → `baseSalary + salesAmount * commissionRate / 100`;
- `void recordSale(double amount)` — добавя продажба;
- конструктор с `name`, `id`, `baseSalary`, `commissionRate`.

Демонстрирайте в `main()`:

1. Създайте поне по един обект от всеки тип.
2. Добавете отработени часове и продажби.
3. Отпечатайте фишовете на всички служители.
4. Намерете служителя с **най-висока** заплата за месеца.

---

## Допълнителни задачи

### Задача 3 — Библиотечна система

Дефинирайте йерархия за библиотечен каталог.

**Базов клас `LibraryItem`** с `protected` полета `title` (string), `author` (string), `year` (int),
`isAvailable` (bool, по подразбиране `true`).

Методи:

- конструктор с `title`, `author`, `year`;
- `void checkout()` — отбелязва артикула като зает (ако е свободен);
- `void returnItem()` — отбелязва артикула като върнат;
- `void describe() const` — отпечатва заглавие, автор, година и наличност.

**Производен клас `Book`** с `private` поле `int pages`.
Предефинирайте `describe()` — извикайте `LibraryItem::describe()`, добавете брой страници.

**Производен клас `DVD`** с `private` поля `int durationMinutes` и `std::string genre`.
Предефинирайте `describe()` — добавете продължителност и жанр.

**Производен клас `AudioBook`** с `private` полета `int durationMinutes` и `std::string narrator`.
Предефинирайте `describe()` — добавете продължителност и четец.

Демонстрирайте: създайте по два обекта от всеки тип, заемете и върнете някои от тях, след което
отпечатайте каталога.
