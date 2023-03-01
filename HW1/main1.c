#include <stdio.h>

int main()
{
    char a[]="AABBBCCCCddd";
    int num=0;
    
    printf("%c", a[0]);
    for (int b=1 ; b<(unsigned long)sizeof(a) ; b++)
    {
        if (a[b] == a[b-1])
        {
            num++;
        }
        else
        {
            printf("%d%c", num+1, a[b]);
            num = 0;
        }
    }
    
    return 0;
}
