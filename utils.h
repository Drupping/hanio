#ifndef UTILS_H
#define UTILS_H

#include "hanoi.h"

// 初始化汉诺塔
void init_stacks(int (*stacks)[MAX_H], int h);

// 从 p 号桩从上到下 n 层搬到 q 号桩
void shift_p_q(int (*stacks)[MAX_H], int p, int q, int n, int width, int h);

// 打印当前的图像栈，width为输出宽度，h为总高度
void print_stack(int (*stacks)[MAX_H], int width, int h);

#endif /* UTILS_H */