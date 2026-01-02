#ifndef TAKEOUT_H
#define TAKEOUT_H

#include "Order.h"
#include "Bill.h"

class Takeout : public Order {
private:
    char address[100];       // 配送地址
    char postscript[200];    // 附言
    Bill cost;               // 账单

public:
    // 构造函数
    Takeout();
    Takeout(int num, const char* name, const char* phone, 
            const char* addr, const char* ps);
    
    // Setter 方法
    void setAddress(const char* addr);
    void setPostscript(const char* ps);
    
    // Getter 方法
    const char* getAddress() const;
    const char* getPostscript() const;
    Bill& getBill();
    const Bill& getBill() const;
    
    // 重写虚函数
    void set() override;
    void get() const override;
    void display() const override;
};

#endif