#include "dinein.h"
#include <stdio.h>
#include <string.h>

/* 初始化堂食订单 */
void dinein_init(Dinein* dinein) {
    order_init(&dinein->base);
    dinein->table_number = 0;
    dinein->people_count = 0;
    dinein->reserve_time[0] = '\0';
    bill_init(&dinein->bill);
}

/* 使用数据初始化堂食订单 */
void dinein_init_with_data(Dinein* dinein, int num, const char* name, 
                           const char* phone, int table, int people, const char* time) {
    order_init_with_data(&dinein->base, num, name, phone);
    dinein->table_number = table;
    dinein->people_count = people;
    strncpy(dinein->reserve_time, time, 19);
    dinein->reserve_time[19] = '\0';
    bill_init(&dinein->bill);
}

/* Setter 函数 */
void dinein_set_table_number(Dinein* dinein, int table) {
    dinein->table_number = table;
}

void dinein_set_people_count(Dinein* dinein, int people) {
    dinein->people_count = people;
}

void dinein_set_reserve_time(Dinein* dinein, const char* time) {
    strncpy(dinein->reserve_time, time, 19);
    dinein->reserve_time[19] = '\0';
}

/* Getter 函数 */
int dinein_get_table_number(const Dinein* dinein) {
    return dinein->table_number;
}

int dinein_get_people_count(const Dinein* dinein) {
    return dinein->people_count;
}

const char* dinein_get_reserve_time(const Dinein* dinein) {
    return dinein->reserve_time;
}

Bill* dinein_get_bill(Dinein* dinein) {
    return &dinein->bill;
}

const Bill* dinein_get_bill_const(const Dinein* dinein) {
    return &dinein->bill;
}

/* 输入堂食订单信息 */
void dinein_set(Dinein* dinein) {
    printf("请输入顾客姓名: ");
    fgets(dinein->base.name, 20, stdin);
    dinein->base.name[strcspn(dinein->base.name, "\n")] = '\0';
    
    printf("请输入联系电话: ");
    fgets(dinein->base.phone_number, 12, stdin);
    dinein->base.phone_number[strcspn(dinein->base.phone_number, "\n")] = '\0';
    
    printf("请输入桌号: ");
    scanf("%d", &dinein->table_number);
    while (getchar() != '\n');
    
    printf("请输入用餐人数: ");
    scanf("%d", &dinein->people_count);
    while (getchar() != '\n');
    
    printf("请输入预约时间 (例如: 18:30): ");
    fgets(dinein->reserve_time, 20, stdin);
    dinein->reserve_time[strcspn(dinein->reserve_time, "\n")] = '\0';
}

/* 获取堂食订单信息（显示基本信息） */
void dinein_get(const Dinein* dinein) {
    order_display(&dinein->base);
    printf("桌号: %d\n", dinein->table_number);
    printf("用餐人数: %d\n", dinein->people_count);
    printf("预约时间: %s\n", dinein->reserve_time);
}

/* 显示完整堂食订单 */
void dinein_display(const Dinein* dinein) {
    printf("\n==================== 堂食订单详情 ====================\n");
    dinein_get(dinein);
    bill_display(&dinein->bill);
    printf("====================================================\n");
}
