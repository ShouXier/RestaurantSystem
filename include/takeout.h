#ifndef TAKEOUT_H
#define TAKEOUT_H

#include "order.h"
#include "bill.h"

/* 外卖订单结构体（使用组合实现继承） */
typedef struct {
    Order base;              /* 基础订单信息 */
    char address[100];       /* 配送地址 */
    char postscript[200];    /* 备注 */
    Bill bill;               /* 账单 */
} Takeout;

/* 初始化函数 */
void takeout_init(Takeout* takeout);
void takeout_init_with_data(Takeout* takeout, int num, const char* name, 
                            const char* phone, const char* addr, const char* ps);

/* Setter 函数 */
void takeout_set_address(Takeout* takeout, const char* addr);
void takeout_set_postscript(Takeout* takeout, const char* ps);

/* Getter 函数 */
const char* takeout_get_address(const Takeout* takeout);
const char* takeout_get_postscript(const Takeout* takeout);
Bill* takeout_get_bill(Takeout* takeout);
const Bill* takeout_get_bill_const(const Takeout* takeout);

/* 输入和显示 */
void takeout_set(Takeout* takeout);
void takeout_get(const Takeout* takeout);
void takeout_display(const Takeout* takeout);

#endif
