#include "Takeout.h"
#include <iostream>
#include <cstring>

using namespace std;

Takeout::Takeout() : Order() {
    strcpy(address, "");
    strcpy(postscript, "");
}

Takeout::Takeout(int num, const char* name, const char* phone, 
                 const char* addr, const char* ps)
    : Order(num, name, phone) {
    strncpy(this->address, addr, 99);
    this->address[99] = '\0';
    strncpy(this->postscript, ps, 199);
    this->postscript[199] = '\0';
}

void Takeout::setAddress(const char* addr) {
    strncpy(this->address, addr, 99);
    this->address[99] = '\0';
}

void Takeout:: setPostscript(const char* ps) {
    strncpy(this->postscript, ps, 199);
    this->postscript[199] = '\0';
}

const char* Takeout::getAddress() const {
    return address;
}

const char* Takeout:: getPostscript() const {
    return postscript;
}

Bill& Takeout::getBill() {
    return cost;
}

const Bill& Takeout::getBill() const {
    return cost;
}

void Takeout::set() {
    Order::set();
    
    cout << "ÇëÊäÈëÅäËÍµØÖ·: ";
    cin.getline(address, 100);
    
    cout << "ÇëÊäÈë¸½ÑÔ£¨¿ÉÑ¡£©: ";
    cin.getline(postscript, 200);
}

void Takeout::get() const {
    Order::get();
    cout << "ÅäËÍµØÖ·: " << address << endl;
    if (strlen(postscript) > 0) {
        cout << "¸½ÑÔ: " << postscript << endl;
    }
}

void Takeout::display() const {
    cout << "\n========== ÍâÂô¶©µ¥ ==========" << endl;
    get();
    cost.display();
}