

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    
    MPI_Init(NULL, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    
    int token;
    if (world_rank != 0) {
        //TODO - Receive the token from your previous neighbor
        // Use MPI_STATUS_IGNORE as MPI_Status
        MPI_Recv();
        
        //TODO - Complete the print command
        printf("Process %d received token %d from process %d\n",
               );
    } else {
        // Set the token's value if you are process 0
        token = -1;
    }
    // TODO - Send the token to your neighbor
    MPI_Send();

    // TODO - Now process 0 receives from the last process.
    if (world_rank == 0) {
        // TODO - Implement the receive command
        MPI_Recv();
        // TODO - Complete the print command
        printf("Process %d received token %d from process %d\n",
               );
    }
    //TODO - Finalize the MPI environment
    
}

