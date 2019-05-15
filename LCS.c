#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int c;
	int b;
};

void lcs(char x[], char y[], int m, int n, struct node c[m][n]){
	for(int i = 0; i<m; i++)
		c[i][0].c = c[i][0].b = 0;

	for(int i = 0; i<n; i++)
		c[0][i].c = c[0][i].b = 0;

	for(int  i = 1; i<m; i++){
		for(int j = 1; j<n; j++){

			int v1 = c[i-1][j].c;
			int v2 = c[i][j-1].c;
			if(x[i-1]==y[j-1]){
				c[i][j].c = c[i-1][j-1].c + 1;
				c[i][j].b = 3;
			}

			else if (v1>=v2){
				c[i][j].c = c[i-1][j].c;
				c[i][j].b = 2;
			}

			else{
				c[i][j].c = c[i][j-1].c;
				c[i][j].b = 1;			
			}
			
		}
	}
	
	int i = m-1;
	int j = n-1;
	int index = c[m-1][n-1].c;
	printf("The longest sequence length is : %d\n", index);
	char ans[index];
	while(i>0 && j>0){
		int v = c[i][j].b;
		if(v == 3){
			ans[index-1]=x[i-1];
			i--; j--; index--;
		}
		else if(v == 2)
			i--;
		else
			j--;
	}
	index = c[m-1][n-1].c;
	printf("The sequence is : ");
	for(i=0;i<index;i++)
		printf("%c",ans[i]);
	printf("\n");
}

void main(){ 
	char X[20];
	printf("Enter the first string : ");
	scanf("%[^\n]%*c", X); 
 	char Y[20]; 
	printf("Enter the second string : ");
	scanf("%[^\n]%*c", Y);
 	int m = strlen(X);
  	int n = strlen(Y); 
	struct node c[m+1][n+1];
	lcs(X,Y,m+1,n+1,c);
}
