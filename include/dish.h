#ifndef DISH_H
#define DISH_H

/* 菜品类别枚举 */
typedef enum {
    HOT_DISH = 1,      /* 热菜 */
    COLD_DISH,         /* 凉菜 */
    SPECIAL_DISH,      /* 特色菜 */
    STAPLE_FOOD,       /* 主食 */
    BEVERAGE           /* 饮品 */
} Category;

/* 口味枚举 */
typedef enum {
    SPICY = 1,         /* 辣 */
    SALTY,             /* 咸 */
    SWEET,             /* 甜 */
    COMMON             /* 适合各种口味 */
} Flavor;

/* 菜品结构体 */
typedef struct {
    int id;                    /* 编号 */
    char name[50];             /* 名称 */
    Category category;         /* 类别 */
    Flavor flavor;             /* 口味 */
    double price;              /* 价格 */
} Dish;

/* 初始化函数 */
void dish_init(Dish* dish);
void dish_init_with_data(Dish* dish, int id, const char* name, 
                         Category cat, Flavor flv, double price);

/* Setter 函数 */
void dish_set_id(Dish* dish, int id);
void dish_set_name(Dish* dish, const char* name);
void dish_set_category(Dish* dish, Category cat);
void dish_set_flavor(Dish* dish, Flavor flv);
void dish_set_price(Dish* dish, double price);

/* Getter 函数 */
int dish_get_id(const Dish* dish);
const char* dish_get_name(const Dish* dish);
Category dish_get_category(const Dish* dish);
Flavor dish_get_flavor(const Dish* dish);
double dish_get_price(const Dish* dish);

/* 辅助函数 */
const char* dish_get_category_string(const Dish* dish);
const char* dish_get_flavor_string(const Dish* dish);

/* 显示和输入 */
void dish_display(const Dish* dish);
void dish_input(Dish* dish);

#endif
