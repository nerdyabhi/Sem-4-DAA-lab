#include <stdio.h>
# define n 4


int min(int a , int b)
{
	if(a>=b) return b;
	return a;
}

int main()
{
	
	int cost[n][n] = 
	{
		{0, 3, 99 , 7},
		{8, 0, 2 , 99},
		{5, 99, 0 , 1},
		{2, 99, 99 , 0}
	};
	
	
	int ans[n][n];
	
	int i=0 , j=0 , k=0;
	for(i =0; i<n; i++)
	{
		for(j =0; j<n; j++)
		{
			ans[i][j] = cost[i][j];
		}
	}
	
	//--------------
	
	for(k=0; k<n; k++)
	{
			for(i =0; i<n; i++)
		{
			for(j =0; j<n; j++)
			{
				ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
			}
		}
	}
	//----------------------
	
	for(i =0; i<n; i++)
	{
		for(j =0; j<n; j++)
		{
			printf("%d\t" , ans[i][j]);
		}
		printf("\n");
	}
}