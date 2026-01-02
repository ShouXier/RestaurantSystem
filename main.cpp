#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "TakeoutSystem.h"
#include "DineinSystem.h"
#include "Utils.h"

using namespace std;

// 全局菜单对象
Menu globalMenu;

// 菜单管理系统界面
void menuManagement() {
    while (true) {
        clearScreen();
        printHeader("菜单管理系统");
        
        cout << "\n1. 插入菜品" << endl;
        cout << "2. 删除菜品" << endl;
        cout << "3. 修改菜品" << endl;
        cout << "4. 查询菜品" << endl;
        cout << "5. 显示所有菜品" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "\n请选择操作: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Dish newDish;
                newDish.input();
                globalMenu.insertDish(newDish);
                pauseScreen();
                break;
            }
            case 2: {
                int id;
                cout << "请输入要删除的菜品编号:  ";
                cin >> id;
                globalMenu.deleteDish(id);
                pauseScreen();
                break;
            }
            case 3: {
                int id;
                cout << "请输入要修改的菜品编号: ";
                cin >> id;
                Dish* dish = globalMenu.searchDish(id);
                if (dish != nullptr) {
                    cout << "\n当前菜品信息：" << endl;
                    dish->display();
                    cout << "\n请输入新的菜品信息：" << endl;
                    Dish newDish;
                    newDish.input();
                    globalMenu.modifyDish(id, newDish);
                } else {
                    cout << "未找到该菜品！" << endl;
                }
                pauseScreen();
                break;
            }
            case 4: {
                cout << "\n查询方式：" << endl;
                cout << "1. 按编号查询" << endl;
                cout << "2. 按名称查询" << endl;
                cout << "请选择:  ";
                int searchChoice;
                cin >> searchChoice;
                
                if (searchChoice == 1) {
                    int id;
                    cout << "请输入菜品编号:  ";
                    cin >> id;
                    Dish* dish = globalMenu. searchDish(id);
                    if (dish != nullptr) {
                        cout << "\n查询结果：" << endl;
                        dish->display();
                    } else {
                        cout << "未找到该菜品！" << endl;
                    }
                } else if (searchChoice == 2) {
                    char name[50];
                    cin.ignore();
                    cout << "请输入菜品名称: ";
                    cin. getline(name, 50);
                    globalMenu.searchDishByName(name);
                }
                pauseScreen();
                break;
            }
            case 5:
                globalMenu.displayAll();
                pauseScreen();
                break;
            case 0:
                return;
            default:
                cout << "无效选择！" << endl;
                pauseScreen();
        }
    }
}

// 外卖订单管理系统界面
void takeoutManagement() {
    Takeout* p = nullptr;
    TakeoutSystem mysys(&p, 0, &globalMenu);
    int number = 0;
    
    while (true) {
        clearScreen();
        printHeader("外卖订单管理系统");
        
        cout << "\n1. 新建外卖订单" << endl;
        cout << "2. 删除外卖订单" << endl;
        cout << "3. 修改外卖订单" << endl;
        cout << "4. 查询外卖订单" << endl;
        cout << "5. 显示所有外卖订单" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "\n请选择操作: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                mysys.insertTakeout(p, number);
                pauseScreen();
                break;
            case 2:
                mysys.deleteTakeout(p, number);
                pauseScreen();
                break;
            case 3:
                mysys.modifyTakeout(p, number);
                pauseScreen();
                break;
            case 4:
                mysys.searchTakeout(p, number);
                pauseScreen();
                break;
            case 5:
                mysys.displayAll(p, number);
                pauseScreen();
                break;
            case 0:
                return;
            default:
                cout << "无效选择！" << endl;
                pauseScreen();
        }
    }
}

// 堂食订单管理系统界面
void dineinManagement() {
    Dinein* p = nullptr;
    DineinSystem mysys(&p, 0, &globalMenu);
    int number = 0;
    
    while (true) {
        clearScreen();
        printHeader("堂食订单管理系统");
        
        cout << "\n1. 新建堂食订单" << endl;
        cout << "2. 删除堂食订单" << endl;
        cout << "3. 修改堂食订单" << endl;
        cout << "4. 查询堂食订单" << endl;
        cout << "5. 显示所有堂食订单" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "\n请选择操作: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                mysys.insertDinein(p, number);
                pauseScreen();
                break;
            case 2:
                mysys.deleteDinein(p, number);
                pauseScreen();
                break;
            case 3:
                mysys.modifyDinein(p, number);
                pauseScreen();
                break;
            case 4:
                mysys.searchDinein(p, number);
                pauseScreen();
                break;
            case 5:
                mysys. displayAll(p, number);
                pauseScreen();
                break;
            case 0:
                return;
            default: 
                cout << "无效选择！" << endl;
                pauseScreen();
        }
    }
}

// 主菜单界面
void mainMenu() {
    while (true) {
        clearScreen();
        
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════════════╗" << endl;
        cout << "║                                                          ║" << endl;
        cout << "║                  餐馆订餐管理系统                         ║" << endl;
        cout << "║                                                          ║" << endl;
        cout << "║                Restaurant Management System              ║" << endl;
        cout << "║                                                          ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════╝" << endl;
        
        cout << "\n┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  1. 菜单管理系统 (Menu Management)                     │" << endl;
        cout << "│  2. 外卖订单管理系统 (Takeout Order Management)        │" << endl;
        cout << "│  3. 堂食订单管理系统 (Dine-in Order Management)        │" << endl;
        cout << "│  0. 退出系统 (Exit)                                    │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        
        cout << "\n请选择功能模块 (Please select): ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                menuManagement();
                break;
            case 2:
                takeoutManagement();
                break;
            case 3:
                dineinManagement();
                break;
            case 0:
                cout << "\n感谢使用餐馆订餐管理系统！再见！" << endl;
                return;
            default:
                cout << "\n无效选择！请重新输入。" << endl;
                pauseScreen();
        }
    }
}

int main() {
    // 初始化示例菜单数据
    cout << "正在初始化系统..." << endl;
    globalMenu.initSampleData();
    cout << "系统初始化完成！" << endl;
    
    // 进入主菜单
    mainMenu();
    
    return 0;
}