#include "Menu.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Menu::Menu() {
    count = 0;  // 在函数体里赋值
}

// 插入菜品
bool Menu:: insertDish(const Dish& dish) {
    if (count >= MAX_DISHES) {
        cout << "菜单已满，无法添加更多菜品！" << endl;
        return false;
    }
    
    // 检查是否已存在相同编号的菜品
    for (int i = 0; i < count; i++) {
        if (dishes[i].getId() == dish.getId()) {
            cout << "编号为 " << dish.getId() << " 的菜品已存在！" << endl;
            return false;
        }
    }
    
    dishes[count++] = dish;
    cout << "菜品添加成功！" << endl;
    return true;
}

// 删除菜品
bool Menu::deleteDish(int id) {
    for (int i = 0; i < count; i++) {
        if (dishes[i].getId() == id) {
            // 将后面的菜品前移
            for (int j = i; j < count - 1; j++) {
                dishes[j] = dishes[j + 1];
            }
            count--;
            cout << "菜品删除成功！" << endl;
            return true;
        }
    }
    cout << "未找到编号为 " << id << " 的菜品！" << endl;
    return false;
}

// 修改菜品
bool Menu::modifyDish(int id, const Dish& dish) {
    for (int i = 0; i < count; i++) {
        if (dishes[i].getId() == id) {
            dishes[i] = dish;
            cout << "菜品修改成功！" << endl;
            return true;
        }
    }
    cout << "未找到编号为 " << id << " 的菜品！" << endl;
    return false;
}

// 根据编号查询
Dish* Menu::searchDish(int id) {
    for (int i = 0; i < count; i++) {
        if (dishes[i].getId() == id) {
            return &dishes[i];
        }
    }
    return nullptr;
}

// 根据名称查询
void Menu::searchDishByName(const char* name) {
    bool found = false;
    cout << "\n查询结果：" << endl;
    cout << string(70, '-') << endl;
    cout << left << setw(8) << "编号"
         << setw(20) << "菜名"
         << setw(12) << "类别"
         << setw(12) << "口味"
         << "价格" << endl;
    cout << string(70, '-') << endl;
    
    for (int i = 0; i < count; i++) {
        if (strstr(dishes[i].getName(), name) != nullptr) {
            dishes[i].display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "未找到包含 \"" << name << "\" 的菜品！" << endl;
    }
    cout << string(70, '-') << endl;
}

// 显示所有菜品
void Menu::displayAll() const {
    if (count == 0) {
        cout << "菜单为空！" << endl;
        return;
    }
    
    cout << "\n当前菜单（共 " << count << " 道菜品）：" << endl;
    cout << string(70, '-') << endl;
    cout << left << setw(8) << "编号"
         << setw(20) << "菜名"
         << setw(12) << "类别"
         << setw(12) << "口味"
         << "价格" << endl;
    cout << string(70, '-') << endl;
    
    for (int i = 0; i < count; i++) {
        dishes[i].display();
    }
    cout << string(70, '-') << endl;
}

int Menu::getCount() const {
    return count;
}

const Dish& Menu::getDish(int index) const {
    return dishes[index];
}

// 初始化示例数据
void Menu::initSampleData() {
    insertDish(Dish(1001, "宫保鸡丁", HOT_DISH, SPICY, 38.0));
    insertDish(Dish(1002, "红烧肉", HOT_DISH, SWEET, 48.0));
    insertDish(Dish(1003, "麻婆豆腐", HOT_DISH, SPICY, 28.0));
    insertDish(Dish(2001, "拍黄瓜", COLD_DISH, COMMON, 15.0));
    insertDish(Dish(2002, "凉拌木耳", COLD_DISH, SALTY, 18.0));
    insertDish(Dish(3001, "北京烤鸭", SPECIAL_DISH, COMMON, 128.0));
    insertDish(Dish(4001, "米饭", STAPLE_FOOD, COMMON, 3.0));
    insertDish(Dish(4002, "炒饭", STAPLE_FOOD, COMMON, 18.0));
    insertDish(Dish(5001, "可乐", BEVERAGE, SWEET, 8.0));
    insertDish(Dish(5002, "啤酒", BEVERAGE, COMMON, 10.0));
}