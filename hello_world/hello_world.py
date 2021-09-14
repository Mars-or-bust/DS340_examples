from mpi4py import MPI

comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()

print("Hello world from processor " + str(rank) +
      " rank " + str(size) + " out of %d processors\n")
