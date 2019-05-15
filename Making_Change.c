#include<stdio.h>
#include<math.h>
#define INF 9999

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int Making_Change(int n,int d[n],int amount)
{
	int c[n][amount+1];
	for(int i=0;i<n;i++)
		c[i][0]=0;
	for(int i=0;i<n;i++)
		for(int j=1;j<=amount;j++)
			{
				if((i==0)&&(j<d[i]))
					c[i][j]=INF;
				else if(i==0)
					c[i][j]=1+c[i][j-d[i]];
				else if(j<d[i])
					c[i][j]=c[i-1][j];
				else
                    c[i][j]=min((1+c[i][j-d[i]]),(c[i-1][j]));
            }
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<amount+1;j++)
				printf("%d ",c[i][j]);
			printf("\n");
		}
	return c[n-1][amount];
}

int main()
{
	int n,a;
	printf("Enter no. of currency notes\n");
	scanf("%d",&n);
	int d[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter value of note %d\n",(i+1));
		scanf("%d",&d[i]);
	}
	printf("Enter change\n");
	scanf("%d",&a);
	printf("No. of notes are %d\n",Making_Change(n,d,a));
    return 0;
}
