#include "order.h"
#include <stdio.h>
#include <string.h>

/* 初始化订单 */
void order_init(Order* order) {
    order->number = 0;
    order->name[0] = '\0';
    order->phone_number[0] = '\0';
}

/* 使用数据初始化订单 */
void order_init_with_data(Order* order, int num, const char* name, const char* phone) {
    order->number = num;
    strncpy(order->name, name, 19);
    order->name[19] = '\0';
    strncpy(order->phone_number, phone, 11);
    order->phone_number[11] = '\0';
}

/* Setter 函数 */
void order_set_number(Order* order, int num) {
    order->number = num;
}

void order_set_name(Order* order, const char* name) {
    strncpy(order->name, name, 19);
    order->name[19] = '\0';
}

void order_set_phone_number(Order* order, const char* phone) {
    strncpy(order->phone_number, phone, 11);
    order->phone_number[11] = '\0';
}

/* Getter 函数 */
int order_get_number(const Order* order) {
    return order->number;
}

const char* order_get_name(const Order* order) {
    return order->name;
}

const char* order_get_phone_number(const Order* order) {
    return order->phone_number;
}

/* 显示订单 */
void order_display(const Order* order) {
    printf("订单编号: %d\n", order->number);
    printf("顾客姓名: %s\n", order->name);
    printf("联系电话: %s\n", order->phone_number);
}
