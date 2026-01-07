#ifndef DINEIN_SYSTEM_H
#define DINEIN_SYSTEM_H

#include "dinein.h"
#include "menu.h"

#define MAX_DINEIN_ORDERS 100

/* 堂食管理系统结构体 */
typedef struct {
    Dinein* list;               /* 订单数组指针 */
    int total_number;           /* 订单总数 */
    Menu* menu;                 /* 菜单引用 */
} DineinSystem;

/* 初始化和销毁函数 */
void dinein_system_init(DineinSystem* sys, Menu* menu);
void dinein_system_destroy(DineinSystem* sys);

/* 订单管理 */
void dinein_system_insert(DineinSystem* sys);        /* 添加订单 */
void dinein_system_delete(DineinSystem* sys);        /* 删除订单 */
void dinein_system_modify(DineinSystem* sys);        /* 修改订单 */
void dinein_system_search(DineinSystem* sys);        /* 查询订单 */
void dinein_system_display_all(DineinSystem* sys);   /* 显示所有订单 */

/* 生成订单号 */
int dinein_system_generate_order_number(void);

#endif
