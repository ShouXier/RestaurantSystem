#ifndef MENU_H
#define MENU_H

#include "dish.h"

#define MAX_DISHES 100

/* 菜单结构体 */
typedef struct {
    Dish dishes[MAX_DISHES];    /* 菜品数组 */
    int count;                  /* 当前菜品数量 */
} Menu;

/* 初始化函数 */
void menu_init(Menu* menu);

/* 菜单操作 */
int menu_insert_dish(Menu* menu, const Dish* dish);           /* 添加菜品 */
int menu_delete_dish(Menu* menu, int id);                     /* 删除菜品 */
int menu_modify_dish(Menu* menu, int id, const Dish* dish);   /* 修改菜品 */
Dish* menu_search_dish(Menu* menu, int id);                   /* 按编号查询 */
void menu_search_dish_by_name(Menu* menu, const char* name);  /* 按名称查询 */
void menu_display_all(const Menu* menu);                      /* 显示所有菜品 */

/* 获取菜品数量 */
int menu_get_count(const Menu* menu);

/* 通过索引获取菜品 */
const Dish* menu_get_dish(const Menu* menu, int index);

/* 初始化示例数据 */
void menu_init_sample_data(Menu* menu);

#endif
