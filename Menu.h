#ifndef MENU_H
#define MENU_H

#include "Dish.h"

const int MAX_DISHES = 100;

class Menu {
private:
    Dish dishes[MAX_DISHES];    // 菜品数组
    int count;                  // 当前菜品数量

public:
    // 构造函数
    Menu();
    
    // 菜单操作
    bool insertDish(const Dish& dish);           // 插入菜品
    bool deleteDish(int id);                     // 删除菜品
    bool modifyDish(int id, const Dish& dish);   // 修改菜品
    Dish* searchDish(int id);                    // 根据编号查询
    void searchDishByName(const char* name);     // 根据名称查询
    void displayAll() const;                     // 显示所有菜品
    
    // 获取菜品数量
    int getCount() const;
    
    // 根据索引获取菜品
    const Dish& getDish(int index) const;
    
    // 初始化示例数据
    void initSampleData();
};

#endif