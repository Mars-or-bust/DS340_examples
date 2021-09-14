#include <mpi.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {

   int n;
   float x, start, end, h, my_pi, pi; 
   MPI_Init(&argc, &argv);

   // Get the number of processes
   int world_size;
   MPI_Comm_size(MPI_COMM_WORLD, &world_size);

   // Get the rank of the process
   int world_rank;
   MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

   if (world_rank == 0)
   {      
      printf("How many intervals? ");
      scanf("%d", &n);
   }

   MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

   my_pi = 0;
   h = (float) 1/n; // Size of each slice
   start = (world_rank*1/world_size)-1; // Slices for this PE
   end = ((world_rank+1)*1/world_size)-1;


   for (x = start; x < end; x= x +h)
      my_pi = my_pi + h *2 * sqrt(1-x*x);

   pi;

   MPI_Reduce(&my_pi, &pi, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

   if (world_rank==0){

      printf("Pi is approximately %f\n", pi);
      printf("Error is %f\n", pi - 3.14159265358979323846);
   }
   // Finalize the MPI environment. No more MPI calls can be made after this
   MPI_Finalize();
}
