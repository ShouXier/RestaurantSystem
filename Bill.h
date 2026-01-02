#ifndef BILL_H
#define BILL_H

#include "Dish.h"

const int MAX_BILL_ITEMS = 50;

// 账单项结构
struct BillItem {
    Dish dish;          // 菜品
    int quantity;       // 份数
    
    BillItem() : quantity(0) {}
    BillItem(const Dish& d, int q) : dish(d), quantity(q) {}
    
    double getSubtotal() const {
        return dish.getPrice() * quantity;
    }
};

class Bill {
private:
    BillItem items[MAX_BILL_ITEMS];    // 账单项数组
    int itemCount;                      // 账单项数量
    double deliveryFee;                 // 配送费

public:
    // 构造函数
    Bill();
    
    // 账单操作
    bool addItem(const Dish& dish, int quantity);      // 添加账单项
    bool removeItem(int dishId);                       // 删除账单项
    bool modifyQuantity(int dishId, int newQuantity);  // 修改数量
    void clear();                                      // 清空账单
    
    // 计算方法
    double calculateSubtotal() const;     // 计算菜品总价
    double calculateDeliveryFee() const;  // 计算配送费（总价的10%）
    double calculateTotal() const;        // 计算总价
    
    // 显示方法
    void display() const;
    
    // Getter 方法
    int getItemCount() const;
    const BillItem& getItem(int index) const;
    
    // Setter 方法
    void setDeliveryFee(double fee);
};

#endif