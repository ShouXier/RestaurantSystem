#include "Order.h"
#include <iostream>
#include <cstring>

using namespace std;

Order::Order() : number(0) {
    strcpy(name, "");
    strcpy(phoneNumber, "");
}

Order::Order(int num, const char* name, const char* phone) : number(num) {
    strncpy(this->name, name, 19);
    this->name[19] = '\0';
    strncpy(this->phoneNumber, phone, 11);
    this->phoneNumber[11] = '\0';
}

Order::~Order() {}

void Order::setNumber(int num) {
    number = num;
}

void Order::setName(const char* name) {
    strncpy(this->name, name, 19);
    this->name[19] = '\0';
}

void Order::setPhoneNumber(const char* phone) {
    strncpy(this->phoneNumber, phone, 11);
    this->phoneNumber[11] = '\0';
}

int Order::getNumber() const {
    return number;
}

const char* Order::getName() const {
    return name;
}

const char* Order::getPhoneNumber() const {
    return phoneNumber;
}

void Order:: set() {
    cout << "请输入订单编号:  ";
    cin >> number;
    cin.ignore();
    
    cout << "请输入顾客姓名: ";
    cin.getline(name, 20);
    
    cout << "请输入联系电话:  ";
    cin.getline(phoneNumber, 12);
}

void Order::get() const {
    cout << "订单编号: " << number << endl;
    cout << "顾客姓名: " << name << endl;
    cout << "联系电话: " << phoneNumber << endl;
}

void Order::display() const {
    get();
}