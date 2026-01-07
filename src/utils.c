#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 清屏函数 */
void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* 暂停屏幕 */
void pause_screen(void) {
    int c;
    printf("\n按回车键继续...");
    /* 清除所有已有输入 */
    while ((c = getchar()) != '\n' && c != EOF);
    /* 等待用户按回车 */
    if (c != EOF) {
        getchar();
    }
}

/* 打印标题 */
void print_header(const char* title) {
    int len = strlen(title);
    int total_width = 60;
    int padding = (total_width - len) / 2;
    
    printf("\n");
    for (int i = 0; i < total_width; i++) printf("=");
    printf("\n");
    
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s\n", title);
    
    for (int i = 0; i < total_width; i++) printf("=");
    printf("\n");
}

/* 清除输入缓冲区 */
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* 继续清除 */
    }
}
