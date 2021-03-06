#include < stdio.h>
#include "mpi.h"
#include < math.h>

int main(argc,argv)
int argc;
char *argv[];
{
    int  n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    printf("Process ', %d, ' of ', %d, ' is alive
",myid,numprocs);

    while (1)
    {
        if (myid == 0) {
            printf("Enter the number of intervals: (0 quits) 
");
            scanf("%d",&n);
        }

        MPI_Bcast(**************************************);
        if (n == 0) 
            break;
  
        else {
        h   = 1.0 / (double) n;
        sum = 0.0;
        for (i = myid + 1; i < = n; i += numprocs) {
            x = h * ((double)i - 0.5);
            sum += 4.0 / (1.0 + x*x);
        }
        mypi = h * sum;
    
        MPI_Reduce(************************************);
    
        if (myid == 0)
            printf("pi is approximately %.16f, Error is %.16f
",
                   pi, fabs(pi - PI25DT));
        }
    }
    MPI_Finalize();
    return 0;
}
