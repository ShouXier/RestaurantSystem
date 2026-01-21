#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "takeout_system.h"
#include "dinein_system.h"
#include "utils.h"

/* 全局菜单变量 */
Menu global_menu;

/* 菜单管理系统界面 */
void menu_management(void) {
    int choice, id;
    Dish new_dish;
    Dish* dish;
    char name[50];
    
    while (1) {
        clear_screen();
        print_header("菜单管理系统");
        
        printf("\n1. 添加菜品\n");
        printf("2. 删除菜品\n");
        printf("3. 修改菜品\n");
        printf("4. 查询菜品\n");
        printf("5. 显示所有菜品\n");
        printf("0. 返回主菜单\n");
        printf("\n请选择操作: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                dish_input(&new_dish);
                menu_insert_dish(&global_menu, &new_dish);
                pause_screen();
                break;
                
            case 2:
                printf("请输入要删除的菜品编号: ");
                scanf("%d", &id);
                menu_delete_dish(&global_menu, id);
                pause_screen();
                break;
                
            case 3:
                printf("请输入要修改的菜品编号: ");
                scanf("%d", &id);
                dish = menu_search_dish(&global_menu, id);
                if (dish != NULL) {
                    printf("\n当前菜品信息：\n");
                    dish_display(dish);
                    printf("\n请输入新的菜品信息：\n");
                    dish_input(&new_dish);
                    menu_modify_dish(&global_menu, id, &new_dish);
                } else {
                    printf("未找到该菜品！\n");
                }
                pause_screen();
                break;
                
            case 4:
                printf("\n查询方式：\n");
                printf("1. 按编号查询\n");
                printf("2. 按名称查询\n");
                printf("请选择: ");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    printf("请输入菜品编号: ");
                    scanf("%d", &id);
                    dish = menu_search_dish(&global_menu, id);
                    if (dish != NULL) {
                        printf("\n查询结果：\n");
                        dish_display(dish);
                    } else {
                        printf("未找到该菜品！\n");
                    }
                } else if (choice == 2) {
                    while (getchar() != '\n');
                    printf("请输入菜品名称: ");
                    fgets(name, 50, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    menu_search_dish_by_name(&global_menu, name);
                }
                pause_screen();
                break;
                
            case 5:
                menu_display_all(&global_menu);
                pause_screen();
                break;
                
            case 0:
                return;
                
            default:
                printf("无效选项！\n");
                pause_screen();
        }
    }
}

/* 外卖订单管理系统界面 */
void takeout_management(void) {
    TakeoutSystem takeout_sys;
    int choice;
    
    takeout_system_init(&takeout_sys, &global_menu);
    
    while (1) {
        clear_screen();
        print_header("外卖订单管理系统");
        
        printf("\n1. 新建外卖订单\n");
        printf("2. 删除外卖订单\n");
        printf("3. 修改外卖订单\n");
        printf("4. 查询外卖订单\n");
        printf("5. 显示所有外卖订单\n");
        printf("0. 返回主菜单\n");
        printf("\n请选择操作: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                takeout_system_insert(&takeout_sys);
                pause_screen();
                break;
                
            case 2:
                takeout_system_delete(&takeout_sys);
                pause_screen();
                break;
                
            case 3:
                takeout_system_modify(&takeout_sys);
                pause_screen();
                break;
                
            case 4:
                takeout_system_search(&takeout_sys);
                pause_screen();
                break;
                
            case 5:
                takeout_system_display_all(&takeout_sys);
                pause_screen();
                break;
                
            case 0:
                takeout_system_destroy(&takeout_sys);
                return;
                
            default:
                printf("无效选项！\n");
                pause_screen();
        }
    }
}

/* 堂食订单管理系统界面 */
void dinein_management(void) {
    DineinSystem dinein_sys;
    int choice;
    
    dinein_system_init(&dinein_sys, &global_menu);
    
    while (1) {
        clear_screen();
        print_header("堂食订单管理系统");
        
        printf("\n1. 新建堂食订单\n");
        printf("2. 删除堂食订单\n");
        printf("3. 修改堂食订单\n");
        printf("4. 查询堂食订单\n");
        printf("5. 显示所有堂食订单\n");
        printf("0. 返回主菜单\n");
        printf("\n请选择操作: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                dinein_system_insert(&dinein_sys);
                pause_screen();
                break;
                
            case 2:
                dinein_system_delete(&dinein_sys);
                pause_screen();
                break;
                
            case 3:
                dinein_system_modify(&dinein_sys);
                pause_screen();
                break;
                
            case 4:
                dinein_system_search(&dinein_sys);
                pause_screen();
                break;
                
            case 5:
                dinein_system_display_all(&dinein_sys);
                pause_screen();
                break;
                
            case 0:
                dinein_system_destroy(&dinein_sys);
                return;
                
            default:
                printf("无效选项！\n");
                pause_screen();
        }
    }
}

/* 主菜单界面 */
void main_menu(void) {
    int choice;
    
    while (1) {
        clear_screen();
        
        printf("\n");
        printf("============================================================\n");
        printf("                                                            \n");
        printf("                  餐馆订餐管理系统                          \n");
        printf("                                                            \n");
        printf("                Restaurant Management System                \n");
        printf("                                                            \n");
        printf("============================================================\n");
        
        printf("\n============================================================\n");
        printf("  1. 菜单管理系统 (Menu Management)                        \n");
        printf("  2. 外卖订单管理系统 (Takeout Order Management)            \n");
        printf("  3. 堂食订单管理系统 (Dine-in Order Management)            \n");
        printf("  0. 退出系统 (Exit)                                        \n");
        printf("============================================================\n");
        
        printf("\n请选择模块 (Please select): ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                menu_management();
                break;
                
            case 2:
                takeout_management();
                break;
                
            case 3:
                dinein_management();
                break;
                
            case 0:
                printf("\n感谢使用餐馆订餐管理系统！再见！\n");
                return;
                
            default:
                printf("\n无效选项，请重新输入。\n");
                pause_screen();
        }
    }
}

/* 主程序 */
int main(void) {
    /* 初始化示例菜单数据 */
    printf("正在初始化系统...\n");
    menu_init(&global_menu);
    menu_init_sample_data(&global_menu);
    printf("系统初始化完成！\n");
    
    /* 启动主菜单 */
    main_menu();
    
    return 0;
}
