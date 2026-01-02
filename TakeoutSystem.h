#ifndef TAKEOUT_SYSTEM_H
#define TAKEOUT_SYSTEM_H

#include "Takeout.h"
#include "Menu.h"

const int MAX_TAKEOUT_ORDERS = 100;

class TakeoutSystem {
private: 
    Takeout* list;              // 订单数组指针
    int totalNumber;            // 订单总数
    Menu* menu;                 // 菜单引用

public:
    // 构造函数和析构函数
    TakeoutSystem(Takeout** p, int n, Menu* m);
    ~TakeoutSystem();
    
    // 订单操作
    void insertTakeout(Takeout* p, int& n);      // 插入订单
    void deleteTakeout(Takeout* p, int& n);      // 删除订单
    void modifyTakeout(Takeout* p, int n);       // 修改订单
    void searchTakeout(Takeout* p, int n);       // 查询订单
    void displayAll(Takeout* p, int n);          // 显示所有订单
    
    // 辅助方法
    void set(int n);
    void get(Takeout** p, int& n);
    
    // 生成订单编号
    int generateOrderNumber();
};

#endif