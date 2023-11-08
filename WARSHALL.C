
/*Warshall algorithm for finding the all pair shortest paths*/
/* Here 1 indicates there is an arc between i to j*/
/*and 0 indicates there is no arc between i to j*/
#include <stdio.h>
#include <conio.h>
#define N 3


int main()
{
	int cost[N][N],path[N][N],p[N][N];
	int i,j,k;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("Enter the cost between %d and %d :",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	/*warshalls algorithm starts*/
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(cost[i][j]==-1)				//-1 or any neg number
				path[i][j]=0;
			else
				path[i][j]=1;
		}

	for(k=0;k<N;k++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(path[i][j]==0)
				{
					path[i][j]=path[i][k]&&path[k][j];
				}
			}
		}
	}
	/*End of warshalls algorithm*/
	printf("\n The sortest paths are : \n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" %d",path[i][j]);
		}
		printf("\n");
	}

}
