# include <stdlib.h>
# include <stdio.h>
# include <time.h>
 
int main()
{
    int m, n=2;
    int i, j, temp;
    int num[7];
    FILE* fp;
    fp= fopen("lotto.txt", "w+");
    
    srand(time(NULL));
    for (m=1; m<=n; m++)
    {
        for(i=0; i<7; i++)
        {
            temp= (rand()%69)+1;
            for(j=0; j<i; j++)
            {
                if(temp== num[j])
                {
                    i--;
                }
            }
            if(temp!= num[j])
            {
                num[i]= temp;
            }
        }
        fprintf(fp, "lotto");
        for(i=0; i<6; i++)
        {
            fprintf(fp, "%3d", num[i]);
        }
        fprintf(fp, "%3d\n", num[i]/10+1);
    }
    fclose(fp);
    
    return 0;
}
