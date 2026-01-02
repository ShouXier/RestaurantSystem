#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

class Order {
protected:
    int number;                 // 编号
    char name[20];              // 顾客姓名
    char phoneNumber[12];       // 联系电话

public:
    // 构造函数
    Order();
    Order(int num, const char* name, const char* phone);
    
    // 虚析构函数
    virtual ~Order();
    
    // Setter 方法
    void setNumber(int num);
    void setName(const char* name);
    void setPhoneNumber(const char* phone);
    
    // Getter 方法
    int getNumber() const;
    const char* getName() const;
    const char* getPhoneNumber() const;
    
    // 虚函数
    virtual void set();
    virtual void get() const;
    virtual void display() const;
};

#endif