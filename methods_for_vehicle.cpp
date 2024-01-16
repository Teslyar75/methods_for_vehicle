//4) Реализовать иерархию классов "Транспортное средство".
//В абстрактном базовом классе реализовать набор чисто виртуальных методов
//(ввод - вывод, расход топлива, получение стоимости, установка стоимости,
//грузоподъёмность, количество мест для пассажиров).
//Потомки переопределяют чисто виртуальные методы.
//Создать массив указателей базового класса.Каждый элемент указывает на объект потомка.
//Поочерёдно вызывая методы в переборном цикле, освобождаем память.


#include <iostream>
using namespace std;

class TransportVehicle {
protected:
    double fuelConsumption;
    double cost;
    double payload;
    int passengerCapacity;

public:
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual double getFuelConsumption() const = 0;
    virtual double getCost() const = 0;
    virtual void setCost(double newCost) = 0;
    virtual double getPayload() const = 0;
    virtual int getPassengerCapacity() const = 0;
    virtual ~TransportVehicle() {}
};

class Car : public TransportVehicle {
public:
    void input() override {
        cout << "Введите расход топлива (л/100 км): ";
        cin >> fuelConsumption;
        cout << "Введите стоимость автомобиля в гривне: ";
        cin >> cost;
        cout << "Введите грузоподъёмность (кг): ";
        cin >> payload;
        cout << "Введите количество мест для пассажиров: ";
        cin >> passengerCapacity;
    }

    void output() const override {
        cout << "Легковой автомобиль:\n";
        cout << "Расход топлива: " << fuelConsumption << " л/100 км\n";
        cout << "Стоимость: " << cost << " гривен\n";
        cout << "Грузоподъёмность: " << payload << " кг\n";
        cout << "Количество мест для пассажиров: " << passengerCapacity << "\n";
    }

    double getFuelConsumption() const override {
        return fuelConsumption;
    }

    double getCost() const override {
        return cost;
    }

    void setCost(double newCost) override {
        cost = newCost;
    }

    double getPayload() const override {
        return payload;
    }

    int getPassengerCapacity() const override {
        return passengerCapacity;
    }
};

class Truck : public TransportVehicle {
public:
    void input() override {
        cout << "Введите расход топлива (л/100 км): ";
        cin >> fuelConsumption;
        cout << "Введите стоимость грузовика: ";
        cin >> cost;
        cout << "Введите грузоподъёмность (кг): ";
        cin >> payload;
        cout << "Введите количество мест для пассажиров: ";
        cin >> passengerCapacity;
    }

    void output() const override {
        cout << "Грузовик:\n";
        cout << "Расход топлива: " << fuelConsumption << " л/100 км\n";
        cout << "Стоимость: " << cost << " гривен\n";
        cout << "Грузоподъёмность: " << payload << " кг\n";
        cout << "Количество мест для пассажиров: " << passengerCapacity << "\n";
    }

    double getFuelConsumption() const override {
        return fuelConsumption;
    }

    double getCost() const override {
        return cost;
    }

    void setCost(double newCost) override {
        cost = newCost;
    }

    double getPayload() const override {
        return payload;
    }

    int getPassengerCapacity() const override {
        return passengerCapacity;
    }
};

int main() {
    setlocale(0, "");

    const int arraySize = 2;
    TransportVehicle* vehicles[arraySize];
    vehicles[0] = new Car();
    vehicles[1] = new Truck();

    for (int i = 0; i < arraySize; ++i) {
        vehicles[i]->input();
    }

    for (int i = 0; i < arraySize; ++i) {
        vehicles[i]->output();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete vehicles[i];
    }
}