#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

void Knapsack_0_1(int N,int W,int w[N][2])
{
    int m[N+1][W+1];
    for(int i=0;i<N+1;i++)
        m[i][0]=0;
    for(int j=1;j<W+1;j++)
        m[0][j]=0;
    for(int i=1;i<N+1;i++)
        for(int j=1;j<W+1;j++)
        {
            if(w[i-1][0]<=j)
                m[i][j]=max(m[i-1][j],w[i-1][1]+m[i-1][j-w[i-1][0]]);
            else
                m[i][j]=m[i-1][j];
        }
    for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                printf("%d ",m[i][j]);
            }
        printf("\n");
        }
}

int main()
{
    int N,W;
    printf("Enter no. of elements\n");
    scanf("%d",&N);
    printf("Enter total weight\n");
    scanf("%d",&W);
    int w[N][2];
    for(int i=0;i<N;i++)
            {
                printf("Enter weight for element %d\n",(i+1));
                scanf("%d",&w[i][0]);
                printf("Enter value for element %d\n",(i+1));
                scanf("%d",&w[i][1]);
            }
    Knapsack_0_1(N,W,w);
    return 0;
}
