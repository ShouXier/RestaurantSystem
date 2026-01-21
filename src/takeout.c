#include "takeout.h"
#include <stdio.h>
#include <string.h>

/* 初始化外卖订单 */
void takeout_init(Takeout* takeout) {
    order_init(&takeout->base);
    takeout->address[0] = '\0';
    takeout->postscript[0] = '\0';
    bill_init(&takeout->bill);
}

/* 使用数据初始化外卖订单 */
void takeout_init_with_data(Takeout* takeout, int num, const char* name, 
                            const char* phone, const char* addr, const char* ps) {
    order_init_with_data(&takeout->base, num, name, phone);
    strncpy(takeout->address, addr, 99);
    takeout->address[99] = '\0';
    strncpy(takeout->postscript, ps, 199);
    takeout->postscript[199] = '\0';
    bill_init(&takeout->bill);
}

/* Setter 函数 */
void takeout_set_address(Takeout* takeout, const char* addr) {
    strncpy(takeout->address, addr, 99);
    takeout->address[99] = '\0';
}

void takeout_set_postscript(Takeout* takeout, const char* ps) {
    strncpy(takeout->postscript, ps, 199);
    takeout->postscript[199] = '\0';
}

/* Getter 函数 */
const char* takeout_get_address(const Takeout* takeout) {
    return takeout->address;
}

const char* takeout_get_postscript(const Takeout* takeout) {
    return takeout->postscript;
}

Bill* takeout_get_bill(Takeout* takeout) {
    return &takeout->bill;
}

const Bill* takeout_get_bill_const(const Takeout* takeout) {
    return &takeout->bill;
}

/* 输入外卖订单信息 */
void takeout_set(Takeout* takeout) {
    printf("请输入顾客姓名: ");
    fgets(takeout->base.name, 20, stdin);
    takeout->base.name[strcspn(takeout->base.name, "\n")] = '\0';
    
    printf("请输入联系电话: ");
    fgets(takeout->base.phone_number, 12, stdin);
    takeout->base.phone_number[strcspn(takeout->base.phone_number, "\n")] = '\0';
    
    printf("请输入配送地址: ");
    fgets(takeout->address, 100, stdin);
    takeout->address[strcspn(takeout->address, "\n")] = '\0';
    
    printf("请输入备注 (可选): ");
    fgets(takeout->postscript, 200, stdin);
    takeout->postscript[strcspn(takeout->postscript, "\n")] = '\0';
}

/* 获取外卖订单信息（显示基本信息） */
void takeout_get(const Takeout* takeout) {
    order_display(&takeout->base);
    printf("配送地址: %s\n", takeout->address);
    printf("备注: %s\n", takeout->postscript);
}

/* 显示完整外卖订单 */
void takeout_display(const Takeout* takeout) {
    printf("\n==================== 外卖订单详情 ====================\n");
    takeout_get(takeout);
    bill_display(&takeout->bill);
    printf("====================================================\n");
}
