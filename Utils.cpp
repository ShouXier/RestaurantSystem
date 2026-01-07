#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void clearScreen() {
    system("cls");
}

void pauseScreen() {
    cout << "\n按回车键继续... ";
    cin.ignore();
    cin.get();
}

void printHeader(const char* title) {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║          " << title;
    int len = 60 - 20 - strlen(title);
    for (int i = 0; i < len; i++) cout << " ";
    cout << "║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
}