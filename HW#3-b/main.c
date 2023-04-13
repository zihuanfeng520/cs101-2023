#include <stdio.h>
#include <string.h>

typedef struct my_mm {
    int* ptr;     // 指向記憶體空間起始位址
    size_t size;  // 記憶體空間大小
} my_mm_t;

int g_mem[10];
my_mm_t mms[10];  // 管理 10 個記憶體空間

int* my_calloc(int n, int size) {
    // 找出第一個大小足夠的記憶體空間
    int i;
    for (i = 0; i < 10; i++) {
        if (mms[i].ptr == NULL || mms[i].size < n * size) {
            continue;
        }
        else {
            // 分配記憶體空間
            int* p = mms[i].ptr;
            memset(p, 0, n * size);
            mms[i].ptr += n * size;
            mms[i].size -= n * size;
            // 印出剩餘記憶體空間大小
            printf("剩餘記憶體空間大小：%ld\n", mms[i].size);
            return p;
        }
    }
    // 沒有足夠的記憶體空間
    printf("無足夠記憶體空間可分配！\n");
    return NULL;
}

void my_free(int* p) {
    // 尋找指定指標所屬的記憶體空間
    int i;
    for (i = 0; i < 10; i++) {
        if (p >= mms[i].ptr && p < mms[i].ptr + mms[i].size) {
            // 釋放記憶體空間
            mms[i].size += p - mms[i].ptr;
            mms[i].ptr = p;
            // 印出剩餘記憶體空間大小
            printf("剩餘記憶體空間大小：%ld\n", mms[i].size);
            return;
        }
    }
    // 指定指標不屬於任何已分配的記憶體空間
    printf("無法釋放指定指標所屬的記憶體空間！\n");
}

int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 3);
    return 0;
}
