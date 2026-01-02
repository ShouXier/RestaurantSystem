#include "Bill.h"
#include <iostream>
#include <iomanip>

using namespace std;

Bill::Bill() : itemCount(0), deliveryFee(0.0) {}

// 添加账单项
bool Bill::addItem(const Dish& dish, int quantity) {
    if (quantity <= 0) {
        cout << "数量必须大于0！" << endl;
        return false;
    }
    
    // 检查是否已存在该菜品
    for (int i = 0; i < itemCount; i++) {
        if (items[i].dish.getId() == dish.getId()) {
            items[i].quantity += quantity;
            cout << "已将 " << dish.getName() << " 的数量增加 " << quantity << endl;
            return true;
        }
    }
    
    // 添加新菜品
    if (itemCount >= MAX_BILL_ITEMS) {
        cout << "账单已满，无法添加更多菜品！" << endl;
        return false;
    }
    
    items[itemCount++] = BillItem(dish, quantity);
    cout << "已添加 " << dish.getName() << " × " << quantity << endl;
    return true;
}

// 删除账单项
bool Bill::removeItem(int dishId) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].dish. getId() == dishId) {
            // 将后面的项前移
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            itemCount--;
            cout << "已删除该菜品" << endl;
            return true;
        }
    }
    cout << "未找到该菜品！" << endl;
    return false;
}

// 修改数量
bool Bill::modifyQuantity(int dishId, int newQuantity) {
    if (newQuantity <= 0) {
        cout << "数量必须大于0！" << endl;
        return false;
    }
    
    for (int i = 0; i < itemCount; i++) {
        if (items[i].dish.getId() == dishId) {
            items[i]. quantity = newQuantity;
            cout << "数量已修改为 " << newQuantity << endl;
            return true;
        }
    }
    cout << "未找到该菜品！" << endl;
    return false;
}

// 清空账单
void Bill:: clear() {
    itemCount = 0;
    deliveryFee = 0.0;
}

// 计算菜品总价
double Bill::calculateSubtotal() const {
    double subtotal = 0.0;
    for (int i = 0; i < itemCount; i++) {
        subtotal += items[i].getSubtotal();
    }
    return subtotal;
}

// 计算配送费
double Bill::calculateDeliveryFee() const {
    return calculateSubtotal() * 0.1;  // 配送费为总价的10%
}

// 计算总价
double Bill::calculateTotal() const {
    return calculateSubtotal() + deliveryFee;
}

// 显示账单
void Bill::display() const {
    if (itemCount == 0) {
        cout << "账单为空！" << endl;
        return;
    }
    
    cout << "\n========== 账单详情 ==========" << endl;
    cout << left << setw(8) << "编号"
         << setw(20) << "菜名"
         << setw(8) << "单价"
         << setw(8) << "份数"
         << "小计" << endl;
    cout << string(60, '-') << endl;
    
    for (int i = 0; i < itemCount; i++) {
        cout << left << setw(8) << items[i].dish.getId()
             << setw(20) << items[i].dish.getName()
             << "?" << setw(7) << fixed << setprecision(2) << items[i].dish.getPrice()
             << setw(8) << items[i].quantity
             << "?" << fixed << setprecision(2) << items[i].getSubtotal() << endl;
    }
    
    cout << string(60, '-') << endl;
    cout << right << setw(45) << "菜品总价:  " << "?" << fixed << setprecision(2) << calculateSubtotal() << endl;
    cout << right << setw(45) << "配送费: " << "?" << fixed << setprecision(2) << deliveryFee << endl;
    cout << right << setw(45) << "总计: " << "?" << fixed << setprecision(2) << calculateTotal() << endl;
    cout << "==============================" << endl;
}

int Bill::getItemCount() const {
    return itemCount;
}

const BillItem& Bill:: getItem(int index) const {
    return items[index];
}

void Bill::setDeliveryFee(double fee) {
    deliveryFee = fee;
}