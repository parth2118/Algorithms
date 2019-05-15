#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

void all_pair_shortest_path(int n,int v[n][n])
{
    int k=0;
    int t[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            t[i][j]=0;
    while(k<n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if((i!=k)&&(j!=k))
                {
                    if(((v[i][k])+(v[k][j]))<(v[i][j]))
                        t[i][j]=k+1; //(k+1) as we are interested in vertex no. and not it's index
                    v[i][j]=min((v[i][j]),(v[i][k])+(v[k][j]));
                }
            }
        k++;
    }
        for(int i=0;i<n;i++)
           {
            for(int j=0;j<n;j++)
                printf("%d ",v[i][j]);
            printf("\n");
           }
           printf("Traceback matrix\n");
        for(int i=0;i<n;i++)
           {
            for(int j=0;j<n;j++)
                printf("%d ",t[i][j]);
            printf("\n");
           }
        printf("All Shortest paths are:\n");
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(t[i][j]==0)
                        printf("%d-->%d weight:%d\n",i+1,j+1,v[i][j]);
                    else{
                        int q=t[i][j];
                        printf("%d-->%d-->%d weight:%d\n",i+1,q,j+1,v[i][q-1]+v[q-1][j]);
                    }
                }

            }

}

void main()
{
    int n;
    printf("Enter the no. of vertices:\n");
    scanf("%d",&n);
    int v[n][n];
    printf("Enter the adjacency matrix(Enter 999 if edge is not present)\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                if(i==j)
                    v[i][j]=0;
                else
                    {
                        printf("Enter weight for edge %d-->%d\n",i+1,j+1);
                        scanf("%d",&v[i][j]);
                    }
            }
    all_pair_shortest_path(n,v);
}
