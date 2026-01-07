#ifndef TAKEOUT_SYSTEM_H
#define TAKEOUT_SYSTEM_H

#include "takeout.h"
#include "menu.h"

#define MAX_TAKEOUT_ORDERS 100

/* 外卖管理系统结构体 */
typedef struct {
    Takeout* list;              /* 订单数组指针 */
    int total_number;           /* 订单总数 */
    Menu* menu;                 /* 菜单引用 */
} TakeoutSystem;

/* 初始化和销毁函数 */
void takeout_system_init(TakeoutSystem* sys, Menu* menu);
void takeout_system_destroy(TakeoutSystem* sys);

/* 订单管理 */
void takeout_system_insert(TakeoutSystem* sys);      /* 添加订单 */
void takeout_system_delete(TakeoutSystem* sys);      /* 删除订单 */
void takeout_system_modify(TakeoutSystem* sys);      /* 修改订单 */
void takeout_system_search(TakeoutSystem* sys);      /* 查询订单 */
void takeout_system_display_all(TakeoutSystem* sys); /* 显示所有订单 */

/* 生成订单号 */
int takeout_system_generate_order_number(void);

#endif
