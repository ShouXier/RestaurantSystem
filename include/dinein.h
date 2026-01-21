#ifndef DINEIN_H
#define DINEIN_H

#include "order.h"
#include "bill.h"

/* 堂食订单结构体（使用组合实现继承） */
typedef struct {
    Order base;              /* 基础订单信息 */
    int table_number;        /* 桌号 */
    int people_count;        /* 用餐人数 */
    char reserve_time[20];   /* 预约时间 */
    Bill bill;               /* 账单 */
} Dinein;

/* 初始化函数 */
void dinein_init(Dinein* dinein);
void dinein_init_with_data(Dinein* dinein, int num, const char* name, 
                           const char* phone, int table, int people, const char* time);

/* Setter 函数 */
void dinein_set_table_number(Dinein* dinein, int table);
void dinein_set_people_count(Dinein* dinein, int people);
void dinein_set_reserve_time(Dinein* dinein, const char* time);

/* Getter 函数 */
int dinein_get_table_number(const Dinein* dinein);
int dinein_get_people_count(const Dinein* dinein);
const char* dinein_get_reserve_time(const Dinein* dinein);
Bill* dinein_get_bill(Dinein* dinein);
const Bill* dinein_get_bill_const(const Dinein* dinein);

/* 输入和显示 */
void dinein_set(Dinein* dinein);
void dinein_get(const Dinein* dinein);
void dinein_display(const Dinein* dinein);

#endif
