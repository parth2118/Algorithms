#include<stdio.h>
 	 	
void calculate_time(int a1[],int a2[],int t1[],int t2[],int e1,int e2,int x1,int x2,int n)
{
	int f1[n],f2[n],l1[n],l2[n],f,l,i;
	f1[0] = e1 + a1[0];
	f2[0] = e2 + a2[0];
	for(i=1;i<n;i++)
	{
		if ((f1[i-1]+a1[i]) <= (f2[i-1]+t2[i-1]+a1[i]))
		{
			f1[i] = f1[i-1]+a1[i];
			l1[i] = 1;
		}
		else
		{
			f1[i] = f2[i-1]+t2[i-1]+a1[i];
			l1[i] = 2;
		}
		if ((f2[i-1]+a2[i]) <= (f1[i-1]+t1[i-1]+a2[i]))
		{
			f2[i] = f2[i-1]+a2[i];
			l2[i] = 2;
		}
		else
		{
			f2[i] = f1[i-1]+t1[i-1]+a2[i];
			l2[i] = 1;
		}
		if ((f1[n-1]+x1) <= (f2[n-1]+x2))
		{
			f = f1[n-1]+x1;
			l = 1;
		}
		else
		{
			f = f2[n-1]+x2;
			l = 2;
		}
	}

	printf("f1: ");
	for(i=0;i<n;i++)
		printf("\t%d",f1[i]);
	printf("\n");
	printf("f2: ");
	for(i=0;i<n;i++)
		printf("\t%d",f2[i]);
	printf("\n");
	printf("Total time taken is: %d\n",f);
	i = l;
	printf("Path traced: \n");
	printf("Line %d station %d\n",i,n);
	for(int j=n-2;j>0;j--)
	{
		if(i==1)
			i = l1[j];
		else
			i = l2[j];
		printf("Line %d station %d\n",i,j);
	}
}

int main()
{
	int n,i;
	printf("Enter the no. of stations: ");
	scanf("%d",&n);
	int a1[n],a2[n],t1[n-1],t2[n-1],e1,e2,x1,x2;
	printf("\nEnter the cost of entries of stations: ");
	scanf("%d %d",&e1,&e2);
	printf("\nEnter the cost of exits of stations: ");
	scanf("%d %d",&x1,&x2);
	printf("\nEnter the processing cost of stations of a1: ");
	for(i=0;i<n;i++)
		scanf("%d",&a1[i]);
	printf("\nEnter the processing cost of stations of a2: ");
	for(i=0;i<n;i++)
		scanf("%d",&a2[i]);
	printf("\nEnter the line changing costs from station a1: ");
	for(i=0;i<n-1;i++)
		scanf("%d",&t1[i]);
	printf("\nEnter the line changing costs from station a2: ");
	for(i=0;i<n-1;i++)
		scanf("%d",&t2[i]);
	calculate_time(a1,a2,t1,t2,e1,e2,x1,x2,n);
}