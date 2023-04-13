#include <stdio.h>

void multi(int i, int j) {
    printf("%d*%d=%-2d ", i, j, i*j);
}

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            multi(i, j);
        }
        printf("\n");
    }
    return 0;
}
