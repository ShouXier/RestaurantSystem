#include "TakeoutSystem.h"
#include <iostream>
#include <cstring>

using namespace std;

TakeoutSystem::TakeoutSystem(Takeout** p, int n, Menu* m) : totalNumber(n), menu(m) {
    list = new Takeout[MAX_TAKEOUT_ORDERS];
    *p = list;
}

TakeoutSystem::~TakeoutSystem() {
    delete[] list;
}

int TakeoutSystem::generateOrderNumber() {
    static int orderCounter = 10000;
    return ++orderCounter;
}

void TakeoutSystem::insertTakeout(Takeout* p, int& n) {
    if (n >= MAX_TAKEOUT_ORDERS) {
        cout << "订单系统已满！" << endl;
        return;
    }
    
    cout << "\n========== 新建外卖订单 ==========" << endl;
    
    Takeout newOrder;
    newOrder.setNumber(generateOrderNumber());
    
    char name[20], phone[12], address[100], ps[200];
    
    cin.ignore();
    cout << "请输入顾客姓名: ";
    cin.getline(name, 20);
    newOrder.setName(name);
    
    cout << "请输入联系电话: ";
    cin.getline(phone, 12);
    newOrder.setPhoneNumber(phone);
    
    cout << "请输入配送地址: ";
    cin.getline(address, 100);
    newOrder.setAddress(address);
    
    cout << "请输入附言（可选，直接回车跳过）: ";
    cin.getline(ps, 200);
    newOrder.setPostscript(ps);
    
    // 添加菜品到账单
    cout << "\n开始添加菜品..." << endl;
    menu->displayAll();
    
    char continueAdd = 'y';
    while (continueAdd == 'y' || continueAdd == 'Y') {
        int dishId, quantity;
        cout << "\n请输入菜品编号:  ";
        cin >> dishId;
        
        Dish* dish = menu->searchDish(dishId);
        if (dish == nullptr) {
            cout << "未找到该菜品！" << endl;
            cin.ignore();
            cout << "是否继续添加菜品？(y/n): ";
            cin >> continueAdd;
            continue;
        }
        
        cout << "请输入份数: ";
        cin >> quantity;
        
        newOrder.getBill().addItem(*dish, quantity);
        
        cin.ignore();
        cout << "是否继续添加菜品？(y/n): ";
        cin >> continueAdd;
    }
    
    // 设置配送费
    newOrder.getBill().setDeliveryFee(newOrder.getBill().calculateDeliveryFee());
    
    p[n] = newOrder;
    n++;
    
    cout << "\n外卖订单创建成功！订单编号: " << newOrder.getNumber() << endl;
    newOrder.display();
}

void TakeoutSystem::deleteTakeout(Takeout* p, int& n) {
    if (n == 0) {
        cout << "没有任何订单！" << endl;
        return;
    }
    
    int orderNum;
    cout << "请输入要删除的订单编号: ";
    cin >> orderNum;
    
    for (int i = 0; i < n; i++) {
        if (p[i].getNumber() == orderNum) {
            // 将后面的订单前移
            for (int j = i; j < n - 1; j++) {
                p[j] = p[j + 1];
            }
            n--;
            cout << "订单删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该订单！" << endl;
}

void TakeoutSystem::modifyTakeout(Takeout* p, int n) {
    if (n == 0) {
        cout << "没有任何订单！" << endl;
        return;
    }
    
    int orderNum;
    cout << "请输入要修改的订单编号:  ";
    cin >> orderNum;
    
    for (int i = 0; i < n; i++) {
        if (p[i].getNumber() == orderNum) {
            cout << "\n当前订单信息：" << endl;
            p[i].display();
            
            cout << "\n请选择要修改的内容：" << endl;
            cout << "1. 顾客信息" << endl;
            cout << "2. 配送地址" << endl;
            cout << "3. 附言" << endl;
            cout << "4. 账单" << endl;
            cout << "请选择:  ";
            
            int choice;
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1: {
                    char name[20], phone[12];
                    cout << "请输入新的顾客姓名:  ";
                    cin.getline(name, 20);
                    p[i].setName(name);
                    cout << "请输入新的联系电话: ";
                    cin.getline(phone, 12);
                    p[i].setPhoneNumber(phone);
                    break;
                }
                case 2: {
                    char address[100];
                    cout << "请输入新的配送地址: ";
                    cin.getline(address, 100);
                    p[i].setAddress(address);
                    break;
                }
                case 3: {
                    char ps[200];
                    cout << "请输入新的附言: ";
                    cin.getline(ps, 200);
                    p[i]. setPostscript(ps);
                    break;
                }
                case 4: {
                    cout << "\n账单修改选项：" << endl;
                    cout << "1. 添加菜品" << endl;
                    cout << "2. 删除菜品" << endl;
                    cout << "3. 修改数量" << endl;
                    cout << "请选择: ";
                    int billChoice;
                    cin >> billChoice;
                    
                    if (billChoice == 1) {
                        menu->displayAll();
                        int dishId, quantity;
                        cout << "请输入菜品编号: ";
                        cin >> dishId;
                        Dish* dish = menu->searchDish(dishId);
                        if (dish != nullptr) {
                            cout << "请输入份数: ";
                            cin >> quantity;
                            p[i].getBill().addItem(*dish, quantity);
                            p[i].getBill().setDeliveryFee(p[i].getBill().calculateDeliveryFee());
                        }
                    } else if (billChoice == 2) {
                        int dishId;
                        cout << "请输入要删除的菜品编号: ";
                        cin >> dishId;
                        p[i].getBill().removeItem(dishId);
                        p[i].getBill().setDeliveryFee(p[i].getBill().calculateDeliveryFee());
                    } else if (billChoice == 3) {
                        int dishId, quantity;
                        cout << "请输入菜品编号: ";
                        cin >> dishId;
                        cout << "请输入新的份数: ";
                        cin >> quantity;
                        p[i].getBill().modifyQuantity(dishId, quantity);
                        p[i].getBill().setDeliveryFee(p[i].getBill().calculateDeliveryFee());
                    }
                    break;
                }
                default:
                    cout << "无效选择！" << endl;
                    return;
            }
            
            cout << "订单修改成功！" << endl;
            p[i].display();
            return;
        }
    }
    cout << "未找到该订单！" << endl;
}

void TakeoutSystem:: searchTakeout(Takeout* p, int n) {
    if (n == 0) {
        cout << "没有任何订单！" << endl;
        return;
    }
    
    cout << "\n查询方式：" << endl;
    cout << "1. 按订单编号查询" << endl;
    cout << "2. 按顾客姓名查询" << endl;
    cout << "3. 按电话号码查询" << endl;
    cout << "请选择: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    bool found = false;
    
    switch (choice) {
        case 1: {
            int orderNum;
            cout << "请输入订单编号: ";
            cin >> orderNum;
            for (int i = 0; i < n; i++) {
                if (p[i].getNumber() == orderNum) {
                    p[i].display();
                    found = true;
                    break;
                }
            }
            break;
        }
        case 2: {
            char name[20];
            cout << "请输入顾客姓名: ";
            cin.getline(name, 20);
            for (int i = 0; i < n; i++) {
                if (strstr(p[i].getName(), name) != nullptr) {
                    p[i].display();
                    found = true;
                }
            }
            break;
        }
        case 3: {
            char phone[12];
            cout << "请输入电话号码: ";
            cin.getline(phone, 12);
            for (int i = 0; i < n; i++) {
                if (strcmp(p[i].getPhoneNumber(), phone) == 0) {
                    p[i]. display();
                    found = true;
                }
            }
            break;
        }
        default:
            cout << "无效选择！" << endl;
            return;
    }
    
    if (!found) {
        cout << "未找到匹配的订单！" << endl;
    }
}

void TakeoutSystem::displayAll(Takeout* p, int n) {
    if (n == 0) {
        cout << "没有任何订单！" << endl;
        return;
    }
    
    cout << "\n========== 所有外卖订单（共 " << n << " 个）==========" << endl;
    for (int i = 0; i < n; i++) {
        p[i].display();
        cout << endl;
    }
}

void TakeoutSystem::set(int n) {
    totalNumber = n;
}

void TakeoutSystem::get(Takeout** p, int& n) {
    *p = list;
    n = totalNumber;
}