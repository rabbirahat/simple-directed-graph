#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{

    printf("\t\t\t============================================================\n");
    printf("\t\t\t\tAn adjacency matrix of simple directed graph.\n");
    printf("\t\t\t============================================================\n");


    int counter, n=1000;
    for(counter=0; counter<5; counter++)
    {

        printf("\t\t\t============================================================\n");
        printf("\t\t\t\t\t\t %d Vertices\n", n);
        printf("\t\t\t============================================================\n");

        int i;
        int ** adj;

        adj = (int**)malloc(sizeof(int*)*5000);
        for (i = 0; i < 5000; i++)
            adj[i] = (int*)malloc(sizeof(int)*5000);

        int  row, column, vertex, totaloutdegree=0, totalindegree=0, indegree=0, outdegree=0;
        double start,duration,end,nano=pow(10,9);


        srand(time(0));

        printf("Generating random graph for %d vertices...\n", n);

        for(row=0; row<n; row++)
        {
            for(column=0; column<n; column++)
            {
                if(row==column)
                {
                    adj[row][column]=0;
                }
                else
                {
                    adj[row][column]=rand()%2;
                }
            }
        }
        printf("Graph generation complete.\n\n");

        start=clock();

        for(row=0; row<n; row++)
        {
            for(column=0; column<n; column++)
            {
                outdegree+= adj[row][column];
            }
        }

        for(row=0; row<n; row++)
        {
            for(column=0; column<n; column++)
            {
                indegree += adj[column][row];
            }
        }

        end=clock();
        duration=(((end-start)/CLOCKS_PER_SEC)*nano);

        printf("Sum of out degrees is: %d\n", outdegree);
        printf("Sum of in degrees is: %d\n", indegree);

        printf("So, it is shown that the sum of out degrees and the sum of in degrees are equal.\n");

        printf("\n\n\nTime For %d vertices =%.2f nanosecond.\n\n",n,duration);


        for (i = 0; i < 5000; i++)
            free(adj[i]);
        free(adj);

        n +=1000;
    }

    return 0;

}

