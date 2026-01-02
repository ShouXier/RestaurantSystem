#ifndef DINEIN_SYSTEM_H
#define DINEIN_SYSTEM_H

#include "Dinein.h"
#include "Menu.h"

const int MAX_DINEIN_ORDERS = 100;

class DineinSystem {
private: 
    Dinein* list;               // 订单数组指针
    int totalNumber;            // 订单总数
    Menu* menu;                 // 菜单引用

public:
    // 构造函数和析构函数
    DineinSystem(Dinein** p, int n, Menu* m);
    ~DineinSystem();
    
    // 订单操作
    void insertDinein(Dinein* p, int& n);        // 插入订单
    void deleteDinein(Dinein* p, int& n);        // 删除订单
    void modifyDinein(Dinein* p, int n);         // 修改订单
    void searchDinein(Dinein* p, int n);         // 查询订单
    void displayAll(Dinein* p, int n);           // 显示所有订单
    
    // 辅助方法
    void set(int n);
    void get(Dinein** p, int& n);
    
    // 生成订单编号
    int generateOrderNumber();
};

#endif