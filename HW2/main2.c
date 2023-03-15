# include <stdio.h>
# include <string.h>

int main()
{
    FILE* fp;
    FILE* pfp;
    char a[1000];
    int b= 0;
    
    fp= fopen("main2.txt", "w");
    pfp= fopen("main2.c", "r");
    
    while (fgets(a+b, 1000-b, pfp))
    {
        b= b+strlen(a+b);
    }
    
    fprintf(fp, "%s", a);
    fclose(fp);
    fclose(pfp);
    
    return 0;
}
