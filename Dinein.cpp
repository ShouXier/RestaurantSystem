#include "Dinein.h"
#include <iostream>
#include <cstring>

using namespace std;

Dinein:: Dinein() : Order(), tableNumber(0), peopleCount(0) {
    strcpy(reserveTime, "");
}

Dinein:: Dinein(int num, const char* name, const char* phone, 
               int table, int people, const char* time)
    : Order(num, name, phone), tableNumber(table), peopleCount(people) {
    strncpy(this->reserveTime, time, 19);
    this->reserveTime[19] = '\0';
}

void Dinein::setTableNumber(int table) {
    tableNumber = table;
}

void Dinein:: setPeopleCount(int people) {
    peopleCount = people;
}

void Dinein::setReserveTime(const char* time) {
    strncpy(this->reserveTime, time, 19);
    this->reserveTime[19] = '\0';
}

int Dinein:: getTableNumber() const {
    return tableNumber;
}

int Dinein::getPeopleCount() const {
    return peopleCount;
}

const char* Dinein::getReserveTime() const {
    return reserveTime;
}

Bill& Dinein::getBill() {
    return cost;
}

const Bill& Dinein::getBill() const {
    return cost;
}

void Dinein::set() {
    Order::set();
    
    cout << "请输入桌号: ";
    cin >> tableNumber;
    
    cout << "请输入用餐人数: ";
    cin >> peopleCount;
    
    cin.ignore();
    cout << "请输入预约时间（可选）: ";
    cin.getline(reserveTime, 20);
}

void Dinein::get() const {
    Order::get();
    cout << "桌号: " << tableNumber << endl;
    cout << "用餐人数:  " << peopleCount << endl;
    if (strlen(reserveTime) > 0) {
        cout << "预约时间: " << reserveTime << endl;
    }
}

void Dinein::display() const {
    cout << "\n========== 堂食订单 ==========" << endl;
    get();
    cost.display();
}