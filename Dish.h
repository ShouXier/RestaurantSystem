#ifndef DISH_H
#define DISH_H

#include <string>
using namespace std;

// 菜品类别枚举
enum Category {
    HOT_DISH = 1,      // 热菜
    COLD_DISH,         // 凉菜
    SPECIAL_DISH,      // 特色菜
    STAPLE_FOOD,       // 主食
    BEVERAGE           // 饮品
};

// 口味枚举
enum Flavor {
    SPICY = 1,         // 辣
    SALTY,             // 咸
    SWEET,             // 甜
    COMMON             // 大众口味
};

class Dish {
private:
    int id;                    // 编号
    char name[50];             // 菜名
    Category category;         // 类别
    Flavor flavor;             // 口味
    double price;              // 价格

public:
    // 构造函数
    Dish();
    Dish(int id, const char* name, Category cat, Flavor flv, double price);
    
    // Setter 方法
    void setId(int id);
    void setName(const char* name);
    void setCategory(Category cat);
    void setFlavor(Flavor flv);
    void setPrice(double price);
    
    // Getter 方法
    int getId() const;
    const char* getName() const;
    Category getCategory() const;
    Flavor getFlavor() const;
    double getPrice() const;
    
    // 辅助方法
    string getCategoryString() const;
    string getFlavorString() const;
    
    // 显示菜品信息
    void display() const;
    
    // 输入菜品信息
    void input();
};

#endif