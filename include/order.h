#ifndef ORDER_H
#define ORDER_H

/* 订单基础结构体 */
typedef struct {
    int number;                 /* 编号 */
    char name[20];              /* 顾客姓名 */
    char phone_number[12];      /* 联系电话 */
} Order;

/* 初始化函数 */
void order_init(Order* order);
void order_init_with_data(Order* order, int num, const char* name, const char* phone);

/* Setter 函数 */
void order_set_number(Order* order, int num);
void order_set_name(Order* order, const char* name);
void order_set_phone_number(Order* order, const char* phone);

/* Getter 函数 */
int order_get_number(const Order* order);
const char* order_get_name(const Order* order);
const char* order_get_phone_number(const Order* order);

/* 显示订单 */
void order_display(const Order* order);

#endif
