#include "utils.h"
#include "hanoi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_stacks(int (*stacks)[MAX_H], int h)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_H; j++) {
                stacks[i][j] = (i == 0 && j < h) ? h - j : 0;
        }
    }
}

static int h_of_peg(int *peg)
{
    int i = 0;
    while (i < MAX_H) {
        if (peg[i] == 0) {
            break;
        }
        i++;
    }
    return i;
}

static void move_p_q(int (*stacks)[MAX_H], int p, int q)
{
    int hp = h_of_peg(stacks[p]);
    int hq = h_of_peg(stacks[q]);

    if (hp == 0 || hq == MAX_H) {
        printf("Error: stacks crash during move_p_q\n");
        exit(1);
    }

    stacks[q][hq] = stacks[p][hp - 1]; // push
    stacks[p][hp - 1] = 0; // pop
}

static int get_aux_peg_num(int p, int q)
{
    if (p < 0 || p > 2 || q < 0 || q > 2 || p == q) {
        printf("Error: wrong format p q\n");
    }
    
    return ~(p ^ q) & (int)3;
}

void shift_p_q(int (*stacks)[MAX_H], int p, int q, int n, int width, int h)
{
    if (n == 1) {
        move_p_q(stacks, p, q);
        print_stack(stacks, width, h);
        return;
    }
    int aux = get_aux_peg_num(p, q);
    shift_p_q(stacks, p, aux, n - 1, width, h);
    move_p_q(stacks, p, q);
    print_stack(stacks, width, h);
    shift_p_q(stacks, aux, q, n - 1, width, h);
}

static void print_disk(int len, int radius, bool buttom)
{
    char pad = buttom ? '_' : ' ';
    int pre = (len - (2 * radius + 1))/2;
    int i;

    for (i = 0; i < pre; i++) {
        printf("%c", pad);
    }
    if (radius == 0) {
        printf("|");
    } else {
        printf("|");
        for (i = 0; i < radius - 1; i++) {
            printf("%c", pad);
        }
        printf("%d", radius);
        for (i = 0; i < radius - 1; i++) {
            printf("%c", pad);
        }
        printf("|");
    }
    for (i = 0; i < len - (2 * radius + 1) - pre; i++) {
        printf("%c", pad);
    }
}

static void print_layer(int width, int *arr, bool buttom)
{
    int wid = width / 3;
    int max = 0;

    for (int i = 0; i < 3; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    if (2 * max + 1 > wid) {
        printf("Error: disk trucated\n");
        exit(1);
    }

    print_disk(wid, arr[0], buttom);
    print_disk(wid, arr[1], buttom);
    print_disk(width - 2 * wid, arr[2], buttom);
    for (int i = 0; i < (buttom ? 4 : 1); i++) {
        printf("\n");
    }
}

void print_stack(int (*stacks)[MAX_H], int width, int h)
{
    int arr[3];
    int i;

    for (i = 0; i < h; i++) {
        arr[0] = stacks[0][h - i - 1];
        arr[1] = stacks[1][h - i - 1];
        arr[2] = stacks[2][h - i - 1];
        print_layer(width, arr, (i == h - 1) ? true : false);
    }
}