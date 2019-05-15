#include<stdio.h>
#define n 6

void print_out_parens(int s[n][n],int i,int j){
	if(i==j)
		printf("A%d",i+1);
	else{
		printf("(");
		print_out_parens(s,i,s[i][(n-1)-j]);
		print_out_parens(s,s[i][(n-1)-j]+1,j);
		printf(")");
	}
}

void matrix_chain(int m[n][n],int s[n][n],int p[]){
	int i,j,k,l,q;
	for(i=0;i<n;i++)
		m[i][(n-1)-i] = 0;
	for(l=1;l<n;l++)
	{
		for(i=0;i<n-l;i++)
		{
			j = i+l;
			m[i][(n-1)-j] = -1;
			for(k=i;k<=j-1;k++)
			{
				q = m[i][(n-1)-k] + m[k+1][(n-1)-j] + p[i]*p[k+1]*p[j+1];
				if(q<m[i][(n-1)-j] || m[i][(n-1)-j]==-1)
				{
					m[i][(n-1)-j] = q;
					s[i][(n-1)-j] = k;
				}
			}
		}
	}
	printf("\nOptimal Solution: ");
	print_out_parens(s,0,n-1);
}

int main(){
	int p[n+1],m[n][n],s[n][n],i;
	printf("Enter the size(p) of matrices: ");
	for(i=0;i<n+1;i++)
		scanf("%d",&p[i]);
	matrix_chain(m,s,p);
}


