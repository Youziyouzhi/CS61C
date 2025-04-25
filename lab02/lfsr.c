#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    // 1.先确定MSB的值 通过bit 0， 2， 3， 5的XOR来确定bit15的值
    // 2.整体像右边移动一位
    // 3.给第15bit赋值
    
    // solution 1 silly and stupid
    // uint16_t mark0 = *reg;
    // uint16_t mark2 = *reg;
    // uint16_t mark3 = *reg;
    // uint16_t mark5 = *reg;
    
    // *reg = *reg >> 1;
    // *reg &= ~(1U << 15);

    // *reg |= ((mark0 & 1) ^ (mark2 >> 2 & 1) ^ (mark3 >> 3 & 1) ^ (mark5 >> 5 & 1)) << 15;

    uint16_t bit;
    uint16_t start = *reg;

    bit = ((start >> 0) ^ (start >> 2) ^ (start >> 3) ^ (start >> 5)) & 1U;
    *reg = (*reg >> 1) | (bit << 15);
}

