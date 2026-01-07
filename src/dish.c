#include "dish.h"
#include <stdio.h>
#include <string.h>

/* 初始化菜品 */
void dish_init(Dish* dish) {
    dish->id = 0;
    dish->name[0] = '\0';
    dish->category = HOT_DISH;
    dish->flavor = COMMON;
    dish->price = 0.0;
}

/* 使用数据初始化菜品 */
void dish_init_with_data(Dish* dish, int id, const char* name, 
                         Category cat, Flavor flv, double price) {
    dish->id = id;
    strncpy(dish->name, name, 49);
    dish->name[49] = '\0';
    dish->category = cat;
    dish->flavor = flv;
    dish->price = price;
}

/* Setter 函数实现 */
void dish_set_id(Dish* dish, int id) {
    dish->id = id;
}

void dish_set_name(Dish* dish, const char* name) {
    strncpy(dish->name, name, 49);
    dish->name[49] = '\0';
}

void dish_set_category(Dish* dish, Category cat) {
    dish->category = cat;
}

void dish_set_flavor(Dish* dish, Flavor flv) {
    dish->flavor = flv;
}

void dish_set_price(Dish* dish, double price) {
    dish->price = price;
}

/* Getter 函数实现 */
int dish_get_id(const Dish* dish) {
    return dish->id;
}

const char* dish_get_name(const Dish* dish) {
    return dish->name;
}

Category dish_get_category(const Dish* dish) {
    return dish->category;
}

Flavor dish_get_flavor(const Dish* dish) {
    return dish->flavor;
}

double dish_get_price(const Dish* dish) {
    return dish->price;
}

/* 获取类别字符串 */
const char* dish_get_category_string(const Dish* dish) {
    switch (dish->category) {
        case HOT_DISH:  return "热菜";
        case COLD_DISH: return "凉菜";
        case SPECIAL_DISH: return "特色菜";
        case STAPLE_FOOD: return "主食";
        case BEVERAGE: return "饮品";
        default: return "未知";
    }
}

/* 获取口味字符串 */
const char* dish_get_flavor_string(const Dish* dish) {
    switch (dish->flavor) {
        case SPICY: return "辣";
        case SALTY: return "咸";
        case SWEET:  return "甜";
        case COMMON: return "适合各种口味";
        default: return "未知";
    }
}

/* 显示菜品信息 */
void dish_display(const Dish* dish) {
    printf("%-8d%-20s%-12s%-12s￥%.2f\n",
           dish->id,
           dish->name,
           dish_get_category_string(dish),
           dish_get_flavor_string(dish),
           dish->price);
}

/* 输入菜品信息 */
void dish_input(Dish* dish) {
    int cat, flv, c;
    
    printf("请输入菜品编号: ");
    scanf("%d", &dish->id);
    /* 清除输入缓冲区 */
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("请输入菜品名称: ");
    fgets(dish->name, 50, stdin);
    dish->name[strcspn(dish->name, "\n")] = '\0';  /* 移除换行符 */
    
    printf("请选择类别 (1-热菜 2-凉菜 3-特色菜 4-主食 5-饮品): ");
    scanf("%d", &cat);
    dish->category = (Category)cat;
    
    printf("请选择口味 (1-辣 2-咸 3-甜 4-适合各种口味): ");
    scanf("%d", &flv);
    dish->flavor = (Flavor)flv;
    
    printf("请输入价格: ");
    scanf("%lf", &dish->price);
    /* 清除输入缓冲区 */
    while ((c = getchar()) != '\n' && c != EOF);
}
