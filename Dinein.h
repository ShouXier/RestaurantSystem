#ifndef DINEIN_H
#define DINEIN_H

#include "Order.h"
#include "Bill.h"

class Dinein : public Order {
private:
    int tableNumber;         // 桌号
    int peopleCount;         // 用餐人数
    char reserveTime[20];    // 预约时间
    Bill cost;               // 账单

public:
    // 构造函数
    Dinein();
    Dinein(int num, const char* name, const char* phone, 
           int table, int people, const char* time);
    
    // Setter 方法
    void setTableNumber(int table);
    void setPeopleCount(int people);
    void setReserveTime(const char* time);
    
    // Getter 方法
    int getTableNumber() const;
    int getPeopleCount() const;
    const char* getReserveTime() const;
    Bill& getBill();
    const Bill& getBill() const;
    
    // 重写虚函数
    void set() override;
    void get() const override;
    void display() const override;
};

#endif