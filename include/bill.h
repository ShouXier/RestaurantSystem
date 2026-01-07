#ifndef BILL_H
#define BILL_H

#include "dish.h"

#define MAX_BILL_ITEMS 50

/* 账单项结构 */
typedef struct {
    Dish dish;          /* 菜品 */
    int quantity;       /* 数量 */
} BillItem;

/* 账单结构体 */
typedef struct {
    BillItem items[MAX_BILL_ITEMS];    /* 账单项数组 */
    int item_count;                     /* 账单项数量 */
    double delivery_fee;                /* 配送费 */
} Bill;

/* 初始化函数 */
void bill_init(Bill* bill);
void bill_item_init(BillItem* item);
void bill_item_init_with_data(BillItem* item, const Dish* dish, int quantity);

/* 账单项操作 */
double bill_item_get_subtotal(const BillItem* item);

/* 账单操作 */
int bill_add_item(Bill* bill, const Dish* dish, int quantity);       /* 添加账单项 */
int bill_remove_item(Bill* bill, int dish_id);                       /* 删除账单项 */
int bill_modify_quantity(Bill* bill, int dish_id, int new_quantity); /* 修改数量 */
void bill_clear(Bill* bill);                                         /* 清空账单 */

/* 计算方法 */
double bill_calculate_subtotal(const Bill* bill);     /* 计算菜品总计 */
double bill_calculate_delivery_fee(const Bill* bill); /* 计算配送费（总计的10%） */
double bill_calculate_total(const Bill* bill);        /* 计算总计 */

/* 显示账单 */
void bill_display(const Bill* bill);

/* Getter 函数 */
int bill_get_item_count(const Bill* bill);
const BillItem* bill_get_item(const Bill* bill, int index);

/* Setter 函数 */
void bill_set_delivery_fee(Bill* bill, double fee);

#endif
