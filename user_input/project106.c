#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int adj_matrix[5500][5500];

int main()
{
    int i,j,k,n;
    srand(time(NULL));

    ///takes input from user promptly
    printf("How many vertices ? : ");
    scanf("%d",&n);

    ///generates random elements
    for( i=1; i<=n; i++)
    {
        for( j=1; j<=n; j++)
        {
            k=rand()%2 ;

            adj_matrix[i][j]=k ;
        }

    }

    int in_deg =0;
    int out_deg = 0 ;


    ///finds summation of in_degree
    int start = clock() ;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if ( adj_matrix[j][i] == 1 )
                in_deg++;
        }
    }

    ///finds summation of out_degree
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if ( adj_matrix[i][j] == 1 )
                out_deg++;

        }
    }

    int end= clock();

    double result= ( (double)(end-start) ) /CLOCKS_PER_SEC ;


    printf("In-Degrees : %d\nOut-Degrees : %d\nComputational time : %0.1lf nano sec\n",in_deg, out_deg,result*1000000000);

    printf("\nSum of in-degrees and out-degrees are equal ( Showed )" );

    return 0;

}
