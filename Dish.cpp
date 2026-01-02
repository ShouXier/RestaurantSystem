#include "Dish.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// 默认构造函数
Dish::Dish() : id(0), category(HOT_DISH), flavor(COMMON), price(0.0) {
    strcpy(name, "");
}

// 参数化构造函数
Dish:: Dish(int id, const char* name, Category cat, Flavor flv, double price)
    : id(id), category(cat), flavor(flv), price(price) {
    strncpy(this->name, name, 49);
    this->name[49] = '\0';
}

// Setter 方法实现
void Dish::setId(int id) {
    this->id = id;
}

void Dish::setName(const char* name) {
    strncpy(this->name, name, 49);
    this->name[49] = '\0';
}

void Dish::setCategory(Category cat) {
    this->category = cat;
}

void Dish::setFlavor(Flavor flv) {
    this->flavor = flv;
}

void Dish:: setPrice(double price) {
    this->price = price;
}

// Getter 方法实现
int Dish::getId() const {
    return id;
}

const char* Dish::getName() const {
    return name;
}

Category Dish::getCategory() const {
    return category;
}

Flavor Dish::getFlavor() const {
    return flavor;
}

double Dish::getPrice() const {
    return price;
}

// 获取类别字符串
string Dish::getCategoryString() const {
    switch (category) {
        case HOT_DISH:  return "热菜";
        case COLD_DISH: return "凉菜";
        case SPECIAL_DISH: return "特色菜";
        case STAPLE_FOOD: return "主食";
        case BEVERAGE: return "饮品";
        default: return "未知";
    }
}

// 获取口味字符串
string Dish::getFlavorString() const {
    switch (flavor) {
        case SPICY: return "辣";
        case SALTY: return "咸";
        case SWEET:  return "甜";
        case COMMON: return "大众口味";
        default: return "未知";
    }
}

// 显示菜品信息
void Dish::display() const {
    cout << left << setw(8) << id
         << setw(20) << name
         << setw(12) << getCategoryString()
         << setw(12) << getFlavorString()
         << "?" << fixed << setprecision(2) << price << endl;
}

// 输入菜品信息
void Dish::input() {
    cout << "请输入菜品编号: ";
    cin >> id;
    cin.ignore();
    
    cout << "请输入菜品名称: ";
    cin.getline(name, 50);
    
    cout << "请选择类别 (1-热菜 2-凉菜 3-特色菜 4-主食 5-饮品): ";
    int cat;
    cin >> cat;
    category = static_cast<Category>(cat);
    
    cout << "请选择口味 (1-辣 2-咸 3-甜 4-大众口味): ";
    int flv;
    cin >> flv;
    flavor = static_cast<Flavor>(flv);
    
    cout << "请输入价格: ";
    cin >> price;
    cin.ignore();
}