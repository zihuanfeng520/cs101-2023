#include <stdio.h>
#include <time.h>

void move(int n, char from_rod, char to_rod, char aux_rod, FILE* fp) {
    static int count = 0;
    if (n == 1) {
        count++;
        time_t now = time(0);
        struct tm * timeinfo;
        char buffer [80];
        timeinfo = localtime(&now);
        strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", timeinfo);
        fprintf(fp, "%d (%s) : 1P from %c to %c\n", count, buffer, from_rod, to_rod);
        return;
    }
    move(n-1, from_rod, aux_rod, to_rod, fp);
    count++;
    time_t now = time(0);
    struct tm * timeinfo;
    char buffer [80];
    timeinfo = localtime(&now);
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", timeinfo);
    fprintf(fp, "%d (%s) : %dP from %c to %c\n", count, buffer, n, from_rod, to_rod);
    move(n-1, aux_rod, to_rod, from_rod, fp);
}

int main() {
    FILE* fp;
    fp = fopen("hanoi.txt", "w");
    time_t start_time = time(0);
    struct tm * timeinfo;
    char buffer [80];
    timeinfo = localtime(&start_time);
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", timeinfo);
    fprintf(fp, "Start time: %s\n", buffer);
    move(20, 'A', 'C', 'B', fp);
    time_t end_time = time(0);
    timeinfo = localtime(&end_time);
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", timeinfo);
    fprintf(fp, "End time: %s\n", buffer);
    int total_time = (int)(end_time - start_time);
    fprintf(fp, "Completed Tower of Hanoi for 20 disks\n");
    fprintf(fp, "Total time: %d seconds\n", total_time);
    fclose(fp);
    return 0;
}
