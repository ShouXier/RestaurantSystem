#include "bill.h"
#include <stdio.h>
#include <string.h>

/* 初始化账单项 */
void bill_item_init(BillItem* item) {
    dish_init(&item->dish);
    item->quantity = 0;
}

/* 使用数据初始化账单项 */
void bill_item_init_with_data(BillItem* item, const Dish* dish, int quantity) {
    item->dish = *dish;
    item->quantity = quantity;
}

/* 获取账单项小计 */
double bill_item_get_subtotal(const BillItem* item) {
    return dish_get_price(&item->dish) * item->quantity;
}

/* 初始化账单 */
void bill_init(Bill* bill) {
    int i;
    bill->item_count = 0;
    bill->delivery_fee = 0.0;
    
    for (i = 0; i < MAX_BILL_ITEMS; i++) {
        bill_item_init(&bill->items[i]);
    }
}

/* 添加账单项 */
int bill_add_item(Bill* bill, const Dish* dish, int quantity) {
    int i;
    
    if (quantity <= 0) {
        printf("数量必须大于0！\n");
        return 0;
    }
    
    /* 检查是否已存在该菜品 */
    for (i = 0; i < bill->item_count; i++) {
        if (bill->items[i].dish.id == dish->id) {
            bill->items[i].quantity += quantity;
            printf("已更新菜品数量！\n");
            return 1;
        }
    }
    
    /* 添加新菜品 */
    if (bill->item_count >= MAX_BILL_ITEMS) {
        printf("账单已满，无法添加更多菜品！\n");
        return 0;
    }
    
    bill_item_init_with_data(&bill->items[bill->item_count], dish, quantity);
    bill->item_count++;
    printf("菜品添加成功！\n");
    return 1;
}

/* 删除账单项 */
int bill_remove_item(Bill* bill, int dish_id) {
    int i, j;
    
    for (i = 0; i < bill->item_count; i++) {
        if (bill->items[i].dish.id == dish_id) {
            /* 将后面的项前移 */
            for (j = i; j < bill->item_count - 1; j++) {
                bill->items[j] = bill->items[j + 1];
            }
            bill->item_count--;
            printf("菜品删除成功！\n");
            return 1;
        }
    }
    printf("未找到该菜品！\n");
    return 0;
}

/* 修改数量 */
int bill_modify_quantity(Bill* bill, int dish_id, int new_quantity) {
    int i;
    
    if (new_quantity <= 0) {
        printf("数量必须大于0！\n");
        return 0;
    }
    
    for (i = 0; i < bill->item_count; i++) {
        if (bill->items[i].dish.id == dish_id) {
            bill->items[i].quantity = new_quantity;
            printf("数量修改成功！\n");
            return 1;
        }
    }
    printf("未找到该菜品！\n");
    return 0;
}

/* 清空账单 */
void bill_clear(Bill* bill) {
    bill->item_count = 0;
    bill->delivery_fee = 0.0;
}

/* 计算菜品总计 */
double bill_calculate_subtotal(const Bill* bill) {
    int i;
    double subtotal = 0.0;
    
    for (i = 0; i < bill->item_count; i++) {
        subtotal += bill_item_get_subtotal(&bill->items[i]);
    }
    
    return subtotal;
}

/* 计算配送费（总计的10%） */
double bill_calculate_delivery_fee(const Bill* bill) {
    return bill_calculate_subtotal(bill) * 0.1;
}

/* 计算总计 */
double bill_calculate_total(const Bill* bill) {
    return bill_calculate_subtotal(bill) + bill->delivery_fee;
}

/* 显示账单 */
void bill_display(const Bill* bill) {
    int i;
    double subtotal, total;
    
    if (bill->item_count == 0) {
        printf("账单为空！\n");
        return;
    }
    
    printf("\n账单明细：\n");
    printf("----------------------------------------------------------------------\n");
    printf("%-20s%-12s%-8s%-12s\n", "菜品名称", "单价", "数量", "小计");
    printf("----------------------------------------------------------------------\n");
    
    for (i = 0; i < bill->item_count; i++) {
        printf("%-20s￥%-10.2f%-8d￥%.2f\n",
               bill->items[i].dish.name,
               bill->items[i].dish.price,
               bill->items[i].quantity,
               bill_item_get_subtotal(&bill->items[i]));
    }
    
    printf("----------------------------------------------------------------------\n");
    
    subtotal = bill_calculate_subtotal(bill);
    printf("菜品小计: ￥%.2f\n", subtotal);
    
    if (bill->delivery_fee > 0) {
        printf("配送费: ￥%.2f\n", bill->delivery_fee);
        total = bill_calculate_total(bill);
        printf("总计: ￥%.2f\n", total);
    } else {
        printf("总计: ￥%.2f\n", subtotal);
    }
}

/* Getter 函数 */
int bill_get_item_count(const Bill* bill) {
    return bill->item_count;
}

const BillItem* bill_get_item(const Bill* bill, int index) {
    if (index >= 0 && index < bill->item_count) {
        return &bill->items[index];
    }
    return NULL;
}

/* Setter 函数 */
void bill_set_delivery_fee(Bill* bill, double fee) {
    bill->delivery_fee = fee;
}
