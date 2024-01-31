#include <stdio.h>
#include "hanoi.h"
#include "utils.h"

int main(void)
{
    int stacks[3][MAX_H];
    int h;
    int width;

    printf("Input the number of disks:\n");
    scanf("%d", &h);
    width = 8 * h + 10;
    printf("The steps for %d disks are:\n", h);

    init_stacks(stacks, h);
    print_stack(stacks, width, h);
    shift_p_q(stacks, 0, 2, h, width, h);

    printf("Done\n");
    
    return 0;
}
