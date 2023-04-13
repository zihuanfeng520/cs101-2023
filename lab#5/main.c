#include <stdio.h>

void multi(int i, int j) {
    printf("%d*%d=%d ", i, j, i*j);
    if (j == 9) {
        printf("\n");
        return;
    } else {
        multi(i, j+1);
    }
}

void table(int i) {
    if (i == 10) {
        return;
    }
    multi(i, 1);
    table(i+1);
}

int main() {
    table(1);
    return 0;
}
