#include "menu.h"
#include <stdio.h>
#include <string.h>

/* 初始化菜单 */
void menu_init(Menu* menu) {
    menu->count = 0;
}

/* 添加菜品 */
int menu_insert_dish(Menu* menu, const Dish* dish) {
    int i;
    
    if (menu->count >= MAX_DISHES) {
        printf("菜单已满，无法添加更多菜品！\n");
        return 0;
    }
    
    /* 检查是否已存在相同编号的菜品 */
    for (i = 0; i < menu->count; i++) {
        if (menu->dishes[i].id == dish->id) {
            printf("编号为 %d 的菜品已存在！\n", dish->id);
            return 0;
        }
    }
    
    menu->dishes[menu->count] = *dish;
    menu->count++;
    printf("菜品添加成功！\n");
    return 1;
}

/* 删除菜品 */
int menu_delete_dish(Menu* menu, int id) {
    int i, j;
    
    for (i = 0; i < menu->count; i++) {
        if (menu->dishes[i].id == id) {
            /* 将后面的菜品前移 */
            for (j = i; j < menu->count - 1; j++) {
                menu->dishes[j] = menu->dishes[j + 1];
            }
            menu->count--;
            printf("菜品删除成功！\n");
            return 1;
        }
    }
    printf("未找到编号为 %d 的菜品！\n", id);
    return 0;
}

/* 修改菜品 */
int menu_modify_dish(Menu* menu, int id, const Dish* dish) {
    int i;
    
    for (i = 0; i < menu->count; i++) {
        if (menu->dishes[i].id == id) {
            menu->dishes[i] = *dish;
            printf("菜品修改成功！\n");
            return 1;
        }
    }
    printf("未找到编号为 %d 的菜品！\n", id);
    return 0;
}

/* 按编号查询 */
Dish* menu_search_dish(Menu* menu, int id) {
    int i;
    
    for (i = 0; i < menu->count; i++) {
        if (menu->dishes[i].id == id) {
            return &menu->dishes[i];
        }
    }
    return NULL;
}

/* 按名称查询 */
void menu_search_dish_by_name(Menu* menu, const char* name) {
    int i;
    int found = 0;
    
    printf("\n查询结果：\n");
    printf("----------------------------------------------------------------------\n");
    printf("%-8s%-20s%-12s%-12s%s\n", "编号", "名称", "类别", "口味", "价格");
    printf("----------------------------------------------------------------------\n");
    
    for (i = 0; i < menu->count; i++) {
        if (strstr(menu->dishes[i].name, name) != NULL) {
            dish_display(&menu->dishes[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("未找到包含 \"%s\" 的菜品！\n", name);
    }
    printf("----------------------------------------------------------------------\n");
}

/* 显示所有菜品 */
void menu_display_all(const Menu* menu) {
    int i;
    
    if (menu->count == 0) {
        printf("菜单为空！\n");
        return;
    }
    
    printf("\n菜单列表：\n");
    printf("----------------------------------------------------------------------\n");
    printf("%-8s%-20s%-12s%-12s%s\n", "编号", "名称", "类别", "口味", "价格");
    printf("----------------------------------------------------------------------\n");
    
    for (i = 0; i < menu->count; i++) {
        dish_display(&menu->dishes[i]);
    }
    
    printf("----------------------------------------------------------------------\n");
    printf("共 %d 道菜品\n", menu->count);
}

/* 获取菜品数量 */
int menu_get_count(const Menu* menu) {
    return menu->count;
}

/* 通过索引获取菜品 */
const Dish* menu_get_dish(const Menu* menu, int index) {
    if (index >= 0 && index < menu->count) {
        return &menu->dishes[index];
    }
    return NULL;
}

/* 初始化示例数据 */
void menu_init_sample_data(Menu* menu) {
    Dish dish;
    
    dish_init_with_data(&dish, 101, "宫保鸡丁", HOT_DISH, SPICY, 38.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 102, "鱼香肉丝", HOT_DISH, SPICY, 32.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 103, "糖醋里脊", HOT_DISH, SWEET, 42.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 201, "凉拌黄瓜", COLD_DISH, SALTY, 12.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 202, "皮蛋豆腐", COLD_DISH, SALTY, 18.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 301, "北京烤鸭", SPECIAL_DISH, COMMON, 128.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 302, "水煮鱼", SPECIAL_DISH, SPICY, 88.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 401, "米饭", STAPLE_FOOD, COMMON, 3.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 402, "馒头", STAPLE_FOOD, COMMON, 2.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 501, "可乐", BEVERAGE, SWEET, 8.0);
    menu_insert_dish(menu, &dish);
    
    dish_init_with_data(&dish, 502, "雪碧", BEVERAGE, SWEET, 8.0);
    menu_insert_dish(menu, &dish);
    
    printf("示例菜单初始化完成！\n");
}
