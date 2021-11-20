/*
4.Given set of time intervals, the task is to find the intervals which don’t overlap with the given set of intervals.
interval arr[] = { {1, 3}, {2, 4}, {3, 5}, {7, 9} } 
[5, 7]
*/

#include <stdio.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int A[1000][2];
    void sort(int N)
	{
		int i,j;
        for(i=0;i<N-1;i++)
		{
            for(j=0;j<N-i-1;j++)
			{
                if((A[i][0] > A[i+1][0]) || (A[i][0] == A[i+1][0] && A[i][1] > A[i+1][1]) )
				{
                    int t = A[i][0];
                    A[i][0] = A[i+1][0];                
                    A[i+1][0] = t;
                    t = A[i][1];
                    A[i][1] = A[i+1][1];
                    A[i+1][1] = t;
                }
            }
        }
    }
    int main()
	{
        int N;
        printf("\n Enter total no. of pairs : ");
        scanf("%d",&N);
        int i,st,end;  
		printf("\n Enter pairs : ");  
        for(i = 0 ; i < N; i++)
		{
            scanf("%d %d",&A[i][0],&A[i][1]);        
        }
        sort(N);
        int l = 1 , r = A[0][0];
        for(i = 0 ; i < N ; i++)
		{        
            if(A[i][0] >= l && A[i][1] > r)
			{ 
                if(abs(max(r,A[i][0]) - l) >= 1)           
                    printf(" %d , %d\n",l,max(r,A[i][0]));
                l = max(A[i][0],A[i][1]);
                r = l;
            }
            else{
                l = A[i][1];
                r = l;
            }        
        }
        return 0;
    }