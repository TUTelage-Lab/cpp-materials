# 4. Четирите принципа на ООП

Обектно-ориентираното програмиране се гради върху четири основни принципа: **енкапсулация**, **наследяване**,
**абстракция** и **полиморфизъм**. Заедно те позволяват изграждане на йерархии от
класове, в които общото поведение е дефинирано веднъж и преизползвано навсякъде.

```cpp
class Shape {                          // абстракция — дефинира интерфейс
protected:
    std::string color;                 // енкапсулация — скрит детайл
public:
    virtual double area() const = 0;   // полиморфизъм — runtime dispatch
    virtual ~Shape() = default;
};

class Circle : public Shape {          // наследяване — преизползва Shape
    double radius;
public:
    Circle(double r, const std::string& c) : Shape(c), radius(r) {}
    double area() const override { return M_PI * radius * radius; }
};
```

---

## 1. Енкапсулация

Енкапсулацията скрива вътрешното представяне на обекта зад контролиран публичен интерфейс.
Полетата се декларират `private` — достъпни само чрез методи на класа. Така класът може да
налага инварианти (напр. балансът не може да е отрицателен) и да промени вътрешното си
представяне, без да засяга останалия код.

### Пример 1: банкова сметка с защитен баланс

```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;       // недостъпно отвън — само чрез методи

public:
    BankAccount(const std::string& owner, double initialBalance)
        : owner(owner), balance(initialBalance) {}

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
    const std::string& getOwner() const { return owner; }
};

int main() {
    BankAccount acc("Иван Петров", 1000.0);

    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.withdraw(2000.0);   // отказано — недостатъчна наличност

    // acc.balance = -100;  // ГРЕШКА при компилация — balance е private

    std::cout << "Краен баланс: " << acc.getBalance() << " лв.\n";
    return 0;
}
```

**Резултати:**

```text
Внесени 500 лв. Баланс: 1500 лв.
Изтеглени 200 лв. Баланс: 1300 лв.
Недостатъчна наличност.
Краен баланс: 1300 лв.
```

---

## 2. Наследяване

Наследяването позволява един клас да **преизползва** дефиницията на друг и да я разширява.
Класът, от който се наследява, се нарича **базов** (или родителски), а класът, който наследява — **производен** (или
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

При създаване на обект от производен клас конструкторът на **базовия** клас се изпълнява пръв,
после — на **производния**. При унищожаване редът е **обратен**. Конструкторът на базовия клас
се извиква явно чрез списъка за инициализация:

```cpp
ПроизводенКлас(параметри) : БазовКлас(аргументи) { ... }
```

Полета, декларирани като `protected`, са достъпни в производните класове, но не и извън
йерархията — средното ниво между `private` и `public`.

### Пример 2: йерархия на банкови сметки

`Account` е базов клас с основни операции. `SavingsAccount` и `CreditAccount` го разширяват,
добавяйки специфично поведение. Производните класове достъпват `protected` полетата на базовия
директно по име и извикват базовата версия на метода с `Account::describe()`.

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
        : owner(owner), iban(iban), balance(initialBalance) {
        std::cout << "Account(\"" << owner << "\") конструктор\n";
    }

    ~Account() {
        std::cout << "Account(\"" << owner << "\") деструктор\n";
    }

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

    void describe() const {
        std::cout << "IBAN: " << iban << "  |  Титуляр: " << owner
                  << "  |  Баланс: " << balance << " лв.\n";
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    int lockMonths;

public:
    SavingsAccount(const std::string& owner, const std::string& iban,
                   double initialBalance, double rate, int months)
        : Account(owner, iban, initialBalance),
          interestRate(rate), lockMonths(months) {
        std::cout << "SavingsAccount(\"" << owner << "\") конструктор\n";
    }

    ~SavingsAccount() {
        std::cout << "SavingsAccount(\"" << owner << "\") деструктор\n";
    }

    void applyInterest() {
        double interest = balance * interestRate / 100.0;
        balance += interest;
        std::cout << "Начислена лихва: " << interest << " лв. Нов баланс: "
                  << balance << " лв.\n";
    }

    void describe() const {
        Account::describe();   // извикваме базовия метод
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
        : Account(owner, iban, initialBalance), creditLimit(limit), usedCredit(0) {
        std::cout << "CreditAccount(\"" << owner << "\") конструктор\n";
    }

    ~CreditAccount() {
        std::cout << "CreditAccount(\"" << owner << "\") деструктор\n";
    }

    bool withdrawWithCredit(double amount) {
        double available = balance + (creditLimit - usedCredit);
        if (amount > available) { std::cout << "Надвишен кредитен лимит.\n"; return false; }
        if (amount <= balance) return Account::withdraw(amount);
        double fromCredit = amount - balance;
        balance = 0;
        usedCredit += fromCredit;
        std::cout << "Изтеглени " << amount << " лв. (от кредит: " << fromCredit << " лв.)\n";
        return true;
    }

    void describe() const {
        Account::describe();
        std::cout << "  [Кредитна] Лимит: " << creditLimit
                  << " лв., използван: " << usedCredit << " лв.\n";
    }
};

int main() {
    std::cout << "--- Създаване ---\n";
    SavingsAccount savings("Мария Иванова", "BG80BNBG96611020345678", 10000.0, 3.5, 12);
    CreditAccount  credit("Георги Попов",  "BG18RZBB91550123456789",  500.0, 2000.0);

    std::cout << "\n=== Спестовна сметка ===\n";
    savings.describe();
    savings.deposit(2000.0);
    savings.applyInterest();

    std::cout << "\n=== Кредитна сметка ===\n";
    credit.describe();
    credit.withdrawWithCredit(400.0);
    credit.withdrawWithCredit(300.0);
    credit.withdrawWithCredit(2000.0);
    std::cout << "\n";
    credit.describe();

    std::cout << "\n--- Унищожаване ---\n";
    return 0;
}
```

**Резултати:**

```text
--- Създаване ---
Account("Мария Иванова") конструктор
SavingsAccount("Мария Иванова") конструктор
Account("Георги Попов") конструктор
CreditAccount("Георги Попов") конструктор

=== Спестовна сметка ===
IBAN: BG80BNBG96611020345678  |  Титуляр: Мария Иванова  |  Баланс: 10000 лв.
  [Спестовна] Лихва: 3.5%, срок: 12 мес.
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

--- Унищожаване ---
CreditAccount("Георги Попов") деструктор
Account("Георги Попов") деструктор
SavingsAccount("Мария Иванова") деструктор
Account("Мария Иванова") деструктор
```

---

## 3. Абстракция

Абстракцията дефинира **какво** прави един обект, без да разкрива **как**. Функция, декларирана с
`= 0`, е **чисто виртуална**. Клас, съдържащ поне една такава функция, е **абстрактен** — не може
да се инстанцира директно. Той задава интерфейс, който всеки производен клас е длъжен да
имплементира.

```cpp
class AbstractBase {
public:
    virtual void doWork() const = 0;   // производните класове ТРЯБВА да я дефинират
    virtual ~AbstractBase() = default;
};

// AbstractBase obj;  // ГРЕШКА — абстрактен клас
```

> **Правило:** Ако даден клас съдържа поне една виртуална функция, деструкторът му трябва да е
> `virtual`. В противен случай при `delete` чрез базов указател деструкторът на производния
> клас не се извиква и паметта изтича.

### Пример 3: система за заплати

`Employee` дефинира интерфейса за изчисляване на заплата чрез чисто виртуалния `calcSalary()`.
`printPayslip()` е имплементирана веднъж в базовия клас и я извиква — всеки производен клас
дефинира само своята формула.

```cpp
#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    std::string id;

public:
    Employee(const std::string& name, const std::string& id)
        : name(name), id(id) {}

    virtual double calcSalary() const = 0;

    void printPayslip() const {
        std::cout << "=== " << name << " [" << id << "] ===\n";
        std::cout << "  Заплата: " << calcSalary() << " лв.\n";
    }

    const std::string& getName() const { return name; }
    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
    int hoursWorked;
    double hourlyRate;
public:
    HourlyEmployee(const std::string& name, const std::string& id,
                   int hours, double rate)
        : Employee(name, id), hoursWorked(hours), hourlyRate(rate) {}

    double calcSalary() const override { return hoursWorked * hourlyRate; }

    void printPayslip() const override {
        std::cout << "=== " << name << " [" << id << "] — Почасов ===\n";
        std::cout << "  Часове: " << hoursWorked
                  << ", ставка: " << hourlyRate << " лв./ч.\n";
        std::cout << "  Заплата: " << calcSalary() << " лв.\n";
    }
};

class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(const std::string& name, const std::string& id, double salary)
        : Employee(name, id), monthlySalary(salary) {}

    double calcSalary() const override { return monthlySalary; }

    void printPayslip() const override {
        std::cout << "=== " << name << " [" << id << "] — Фиксирана заплата ===\n";
        std::cout << "  Заплата: " << calcSalary() << " лв.\n";
    }
};

class CommissionEmployee : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(const std::string& name, const std::string& id,
                       double base, double rate)
        : Employee(name, id), baseSalary(base), salesAmount(0), commissionRate(rate) {}

    void recordSale(double amount) { salesAmount += amount; }

    double calcSalary() const override {
        return baseSalary + salesAmount * commissionRate / 100.0;
    }

    void printPayslip() const override {
        std::cout << "=== " << name << " [" << id << "] — Комисиона ===\n";
        std::cout << "  База: " << baseSalary
                  << " лв., продажби: " << salesAmount
                  << " лв. (" << commissionRate << "%)\n";
        std::cout << "  Заплата: " << calcSalary() << " лв.\n";
    }
};

int main() {
    HourlyEmployee     h("Иван Петров",   "E001", 168, 12.50);
    SalariedEmployee   s("Мария Иванова", "E002", 3200.0);
    CommissionEmployee c("Георги Попов",  "E003", 1500.0, 5.0);
    c.recordSale(18000.0);

    Employee* staff[3] = { &h, &s, &c };

    std::cout << "--- Фишове ---\n";
    for (Employee* e : staff) {
        e->printPayslip();
        std::cout << "\n";
    }

    Employee* best = staff[0];
    for (Employee* e : staff)
        if (e->calcSalary() > best->calcSalary()) best = e;

    std::cout << "Най-висока заплата: " << best->getName()
              << " — " << best->calcSalary() << " лв.\n";

    return 0;
}
```

**Резултати:**

```text
--- Фишове ---
=== Иван Петров [E001] — Почасов ===
  Часове: 168, ставка: 12.5 лв./ч.
  Заплата: 2100 лв.

=== Мария Иванова [E002] — Фиксирана заплата ===
  Заплата: 3200 лв.

=== Георги Попов [E003] — Комисиона ===
  База: 1500 лв., продажби: 18000 лв. (5%)
  Заплата: 2400 лв.

Най-висока заплата: Мария Иванова — 3200 лв.
```

---

## 4. Полиморфизъм

Полиморфизмът позволява **различни обекти да се третират по еднакъв начин** чрез указател или
псевдоним към базовия клас, като всеки обект изпълнява собствената си версия на метода.
Функция, декларирана с `virtual`, се диспечира **по време на изпълнение** въз основа на реалния
тип на обекта.

```cpp
Base* p = new Derived;
p->greet();  // извиква Derived::greet(), не Base::greet()
delete p;
```

> Ключовата дума `override` е незадължителна, но препоръчителна — компилаторът проверява дали
> наистина предефинираме съществуващ виртуален метод.

### Пример 4: йерархия от геометрични фигури

Достъпваме различни фигури чрез `Shape*` — C++ избира правилната версия на `area()` и
`describe()` по **реалния тип** на обекта. `Shape` е абстрактен (съдържа `area() = 0`), затова
деструкторът му е `virtual` — без него `delete` чрез `Shape*` би пропуснал деструктора на
производния клас.

```cpp
#include <iostream>
#include <cmath>
#include <string>

class Shape {
protected:
    std::string color;

public:
    explicit Shape(const std::string& color) : color(color) {}

    virtual double area() const = 0;

    virtual void describe() const {
        std::cout << "Shape [" << color << "], area=" << area() << "\n";
    }

    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double radius, const std::string& color)
        : Shape(color), radius(radius) {}

    double area() const override { return M_PI * radius * radius; }

    void describe() const override {
        std::cout << "Circle  [" << color << "] radius=" << radius
                  << ", area=" << area() << "\n";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double width, double height, const std::string& color)
        : Shape(color), width(width), height(height) {}

    double area() const override { return width * height; }

    void describe() const override {
        std::cout << "Rectangle [" << color << "] " << width << "x" << height
                  << ", area=" << area() << "\n";
    }
};

class Triangle : public Shape {
protected:
    double a, b, c;
public:
    Triangle(double a, double b, double c, const std::string& color)
        : Shape(color), a(a), b(b), c(c) {}

    double area() const override {
        double p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void describe() const override {
        std::cout << "Triangle [" << color << "] a=" << a
                  << ", b=" << b << ", c=" << c
                  << ", area=" << area() << "\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, const std::string& color)
        : Triangle(a, b, c, color) {}

    double area() const override { return a * b / 2; }

    void describe() const override {
        std::cout << "RightTriangle [" << color << "] a=" << a
                  << ", b=" << b << ", area=" << area() << "\n";
    }
};

int main() {
    Circle        c(5.0,           "red");
    Rectangle     r(4.0, 6.0,      "blue");
    Triangle      t(3.0, 4.0, 5.0, "green");
    RightTriangle rt(3.0, 4.0, 5.0,"white");

    Shape* shapes[4] = { &c, &r, &t, &rt };

    for (Shape* s : shapes)
        s->describe();

    double total = 0;
    for (Shape* s : shapes) total += s->area();
    std::cout << "\nОбща площ: " << total << "\n";

    return 0;
}
```

**Резултати:**

```text
Circle  [red] radius=5, area=78.5398
Rectangle [blue] 4x6, area=24
Triangle [green] a=3, b=4, c=5, area=6
RightTriangle [white] a=3, b=4, area=6

Обща площ: 114.54
```

---

## Задачи за самостоятелна работа

### Задача 1 — Мрежови устройства (многократно наследяване)

Задачата демонстрира **трипластова йерархия** и **многократно наследяване**.

#### Ниво 1 — абстрактен базов клас `Device`

- `protected` полета `std::string name`, `std::string model`;
- конструктор `Device(const std::string& name, const std::string& model)`;
- чисто виртуална функция `virtual void status() const = 0` — отпечатва текущото състояние;
- виртуална функция `virtual double powerConsumption() const = 0` — консумация в ватове;
- не-виртуален метод `void describe() const` — отпечатва името, модела и консумацията (извиква `powerConsumption()`
  вътрешно);
- виртуален деструктор.

#### Ниво 2 — два специализирани класа, наследяващи `Device`

**`NetworkDevice`** добавя:

- `protected` полета `std::string ipAddress`, `int bandwidthMbps`;
- `void connect()` — отпечатва IP адреса и bandwidthMbps при свързване;
- `void disconnect()`.

**`StorageDevice`** добавя:

- `protected` полета `double capacityGB`, `double usedGB`;
- `bool write(double sizeGB)` — записва данни (проверява свободното място);
- `void erase()` — изтрива всички данни (`usedGB = 0`);
- `double usedPercent() const`.

#### Ниво 3 — клас `NAS`, наследяващ и двата класа от ниво 2

`NAS` наследява едновременно `NetworkDevice` и `StorageDevice` (многократно наследяване).

- добавя `private` поле `int raidLevel`;
- имплементира `status()` — отпечатва IP, RAID ниво, използвано място и консумация;
- имплементира `powerConsumption()` — базова стойност плюс допълнение спрямо RAID нивото.

Демонстрирайте в `main()`:

1. Създайте два обекта `NAS`.
2. Свържете ги с `connect()`, запишете данни с `write()`.
3. Отпечатайте информация с `describe()` и `status()`.
4. Намерете устройството с по-висока консумация.

---

### Задача 2 — Транспортна компания

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
- `bool canTravel(double km, double consumption) const` — проверява дали горивото стига за
  дадено разстояние при зададен разход (л/100 км);
- `void describe() const` — отпечатва регистрационния номер, марка, година и ниво на гориво.

**Производен клас `Truck`** с допълнителни `private` полета `double maxLoad`, `double currentLoad`.

Методи:

- конструктор, предаващ параметрите на `Vehicle`;
- `bool load(double kg)` — натоварва товара (проверява лимита);
- `void unload()` — разтоварва напълно;
- `void describe() const` — извиква `Vehicle::describe()`, след което отпечатва товара.

**Производен клас `Bus`** с допълнителни `private` полета `int maxPassengers`,
`int currentPassengers`, `std::string route`.

Методи:

- конструктор, предаващ параметрите на `Vehicle`;
- `void boardPassengers(int n)` — качва пътници (не надвишава максимума);
- `void exitPassengers(int n)` — слиза пътници;
- `void describe() const` — извиква `Vehicle::describe()`, след което отпечатва маршрута и
  пътниците.

Демонстрирайте в `main()`:

1. Създайте по два обекта от `Truck` и `Bus`.
2. Заредете ги с гориво, натоварете товар / качете пътници.
3. Проверете с `canTravel()` дали превозните средства могат да извършат зададен маршрут.
4. Отпечатайте информация за всяко превозно средство с `describe()`.

---

## Допълнителни задачи

### Задача 3 — Банкова система

Дефинирайте абстрактен базов клас `Account` с `protected` полета `std::string owner`,
`std::string iban`, `double balance`, конструктор и:

- чисто виртуална функция `double calcMonthlyFee() const`;
- виртуална функция `virtual bool withdraw(double amount)` — стандартно теглене с проверка за
  наличност;
- не-виртуален метод `void applyFee()` — приспада таксата от баланса;
- не-виртуален метод `void describe() const` — отпечатва IBAN, титуляр, баланс и месечна такса.

Дефинирайте три производни класа:

- **`CurrentAccount`** — фиксирана месечна такса 2.50 лв.; стандартно теглене.
- **`SavingsAccount`** — без месечна такса; `withdraw()` е блокирано ако балансът би паднал
  под 100 лв.
- **`PremiumAccount`** — такса = 0.1% от баланса; `withdraw()` позволява овърдрафт до 5 000 лв. (балансът може да стане
  отрицателен до `-5000`).

Демонстрирайте в `main()`:

1. Създайте масив `Account* accounts[3]`, по един от всеки тип, заредени с начален баланс.
2. Приложете месечните такси с `applyFee()`.
3. Опитайте теглене от всяка сметка — включително теглене, което нарушава правилата.
4. Отпечатайте крайното състояние на всяка сметка с `describe()`.
5. Освободете паметта с `delete`.
