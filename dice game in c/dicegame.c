#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

ROUNDTYPE getRoundType() {
    int rand_num = getRandomNumber(0, 9);
    if (rand_num < 2) {
        return BONUS;
    } else if (rand_num < 5) {
        return DOUBLE;
    } else {
        return REGULAR;
    }
}

int getRoundPoints(ROUNDTYPE roundType) {
    int rand_num = getRandomNumber(1, 10);
    if (roundType == BONUS) {
        return 200;
    } else if (roundType == DOUBLE) {
        return rand_num * 10 * 2;
    } else {
        return rand_num * 10;
    }
}

void printPlayerPoints(int p1, int p2) {
    printf("P1 : %d\nP2 : %d\n", p1, p2);
}

void printRoundInfo(ROUNDTYPE t, int dice, int points) {
    printf("Type : ");
    switch (t) {
        case BONUS:
            printf("BONUS\n");
            break;
        case DOUBLE:
            printf("DOUBLE\n");
            break;
        case REGULAR:
            printf("REGULAR\n");
            break;
    }
    printf("DICE : %d\nPOINTS : %d\n", dice, points);
}