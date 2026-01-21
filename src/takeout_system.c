#include "takeout_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 初始化外卖管理系统 */
void takeout_system_init(TakeoutSystem* sys, Menu* menu) {
    sys->list = (Takeout*)malloc(MAX_TAKEOUT_ORDERS * sizeof(Takeout));
    if (sys->list == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    sys->total_number = 0;
    sys->menu = menu;
}

/* 销毁外卖管理系统 */
void takeout_system_destroy(TakeoutSystem* sys) {
    if (sys->list != NULL) {
        free(sys->list);
        sys->list = NULL;
    }
    sys->total_number = 0;
}

/* 生成订单号 */
int takeout_system_generate_order_number(void) {
    static int order_counter = 10000;
    return ++order_counter;
}

/* 添加订单 */
void takeout_system_insert(TakeoutSystem* sys) {
    int dish_id, quantity, c;
    char continue_add;
    Dish* dish;
    
    if (sys->total_number >= MAX_TAKEOUT_ORDERS) {
        printf("订单系统已满！\n");
        return;
    }
    
    printf("\n========== 新建外卖订单 ==========\n");
    
    Takeout* new_order = &sys->list[sys->total_number];
    takeout_init(new_order);
    order_set_number(&new_order->base, takeout_system_generate_order_number());
    
    /* 输入顾客信息 */
    takeout_set(new_order);
    
    /* 添加菜品到账单 */
    printf("\n开始添加菜品...\n");
    menu_display_all(sys->menu);
    
    continue_add = 'y';
    while (continue_add == 'y' || continue_add == 'Y') {
        printf("\n请输入菜品编号: ");
        scanf("%d", &dish_id);
        
        dish = menu_search_dish(sys->menu, dish_id);
        if (dish == NULL) {
            printf("未找到该菜品！\n");
            /* 清除输入缓冲区 */
            while ((c = getchar()) != '\n' && c != EOF);
            printf("是否继续添加菜品？(y/n): ");
            scanf("%c", &continue_add);
            continue;
        }
        
        printf("请输入数量: ");
        scanf("%d", &quantity);
        
        bill_add_item(&new_order->bill, dish, quantity);
        
        /* 清除输入缓冲区 */
        while ((c = getchar()) != '\n' && c != EOF);
        printf("是否继续添加菜品？(y/n): ");
        scanf("%c", &continue_add);
    }
    
    /* 计算配送费 */
    bill_set_delivery_fee(&new_order->bill, bill_calculate_delivery_fee(&new_order->bill));
    
    sys->total_number++;
    
    printf("\n外卖订单创建成功！订单号: %d\n", order_get_number(&new_order->base));
    takeout_display(new_order);
}

/* 删除订单 */
void takeout_system_delete(TakeoutSystem* sys) {
    int order_num, i, j;
    
    if (sys->total_number == 0) {
        printf("没有任何订单！\n");
        return;
    }
    
    printf("请输入要删除的订单编号: ");
    scanf("%d", &order_num);
    
    for (i = 0; i < sys->total_number; i++) {
        if (order_get_number(&sys->list[i].base) == order_num) {
            /* 将后面的订单前移 */
            for (j = i; j < sys->total_number - 1; j++) {
                sys->list[j] = sys->list[j + 1];
            }
            sys->total_number--;
            printf("订单删除成功！\n");
            return;
        }
    }
    printf("未找到该订单！\n");
}

/* 修改订单 */
void takeout_system_modify(TakeoutSystem* sys) {
    int order_num, choice, bill_choice, dish_id, quantity, i;
    Takeout* order;
    char name[20], phone[12], address[100], ps[200];
    Dish* dish;
    
    if (sys->total_number == 0) {
        printf("没有任何订单！\n");
        return;
    }
    
    printf("请输入要修改的订单编号: ");
    scanf("%d", &order_num);
    
    for (i = 0; i < sys->total_number; i++) {
        if (order_get_number(&sys->list[i].base) == order_num) {
            order = &sys->list[i];
            printf("\n当前订单信息：\n");
            takeout_display(order);
            
            printf("\n请选择要修改的内容：\n");
            printf("1. 顾客信息\n");
            printf("2. 配送地址\n");
            printf("3. 备注\n");
            printf("4. 账单\n");
            printf("请选择: ");
            
            scanf("%d", &choice);
            while (getchar() != '\n');
            
            switch (choice) {
                case 1:
                    printf("请输入新的顾客姓名: ");
                    fgets(name, 20, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    order_set_name(&order->base, name);
                    printf("请输入新的联系电话: ");
                    fgets(phone, 12, stdin);
                    phone[strcspn(phone, "\n")] = '\0';
                    order_set_phone_number(&order->base, phone);
                    break;
                    
                case 2:
                    printf("请输入新的配送地址: ");
                    fgets(address, 100, stdin);
                    address[strcspn(address, "\n")] = '\0';
                    takeout_set_address(order, address);
                    break;
                    
                case 3:
                    printf("请输入新的备注: ");
                    fgets(ps, 200, stdin);
                    ps[strcspn(ps, "\n")] = '\0';
                    takeout_set_postscript(order, ps);
                    break;
                    
                case 4:
                    printf("\n账单修改选项：\n");
                    printf("1. 添加菜品\n");
                    printf("2. 删除菜品\n");
                    printf("3. 修改数量\n");
                    printf("请选择: ");
                    scanf("%d", &bill_choice);
                    
                    if (bill_choice == 1) {
                        menu_display_all(sys->menu);
                        printf("请输入菜品编号: ");
                        scanf("%d", &dish_id);
                        dish = menu_search_dish(sys->menu, dish_id);
                        if (dish != NULL) {
                            printf("请输入数量: ");
                            scanf("%d", &quantity);
                            bill_add_item(&order->bill, dish, quantity);
                            bill_set_delivery_fee(&order->bill, bill_calculate_delivery_fee(&order->bill));
                        }
                    } else if (bill_choice == 2) {
                        printf("请输入要删除的菜品编号: ");
                        scanf("%d", &dish_id);
                        bill_remove_item(&order->bill, dish_id);
                        bill_set_delivery_fee(&order->bill, bill_calculate_delivery_fee(&order->bill));
                    } else if (bill_choice == 3) {
                        printf("请输入菜品编号: ");
                        scanf("%d", &dish_id);
                        printf("请输入新的份数: ");
                        scanf("%d", &quantity);
                        bill_modify_quantity(&order->bill, dish_id, quantity);
                        bill_set_delivery_fee(&order->bill, bill_calculate_delivery_fee(&order->bill));
                    }
                    break;
                    
                default:
                    printf("无效选项！\n");
                    return;
            }
            
            printf("订单修改成功！\n");
            takeout_display(order);
            return;
        }
    }
    printf("未找到该订单！\n");
}

/* 查询订单 */
void takeout_system_search(TakeoutSystem* sys) {
    int choice, order_num, i;
    char name[20], phone[12];
    int found = 0;
    
    if (sys->total_number == 0) {
        printf("没有任何订单！\n");
        return;
    }
    
    printf("\n查询方式：\n");
    printf("1. 按订单编号查询\n");
    printf("2. 按顾客姓名查询\n");
    printf("3. 按电话号码查询\n");
    printf("请选择: ");
    
    scanf("%d", &choice);
    while (getchar() != '\n');
    
    switch (choice) {
        case 1:
            printf("请输入订单号: ");
            scanf("%d", &order_num);
            for (i = 0; i < sys->total_number; i++) {
                if (order_get_number(&sys->list[i].base) == order_num) {
                    takeout_display(&sys->list[i]);
                    found = 1;
                    break;
                }
            }
            break;
            
        case 2:
            printf("请输入顾客姓名: ");
            fgets(name, 20, stdin);
            name[strcspn(name, "\n")] = '\0';
            for (i = 0; i < sys->total_number; i++) {
                if (strstr(order_get_name(&sys->list[i].base), name) != NULL) {
                    takeout_display(&sys->list[i]);
                    found = 1;
                }
            }
            break;
            
        case 3:
            printf("请输入电话号码: ");
            fgets(phone, 12, stdin);
            phone[strcspn(phone, "\n")] = '\0';
            for (i = 0; i < sys->total_number; i++) {
                if (strcmp(order_get_phone_number(&sys->list[i].base), phone) == 0) {
                    takeout_display(&sys->list[i]);
                    found = 1;
                }
            }
            break;
            
        default:
            printf("无效选项！\n");
            return;
    }
    
    if (!found) {
        printf("未找到匹配的订单！\n");
    }
}

/* 显示所有订单 */
void takeout_system_display_all(TakeoutSystem* sys) {
    int i;
    
    if (sys->total_number == 0) {
        printf("没有任何订单！\n");
        return;
    }
    
    printf("\n========== 所有外卖订单（共 %d 单）==========\n", sys->total_number);
    for (i = 0; i < sys->total_number; i++) {
        takeout_display(&sys->list[i]);
        printf("\n");
    }
}
