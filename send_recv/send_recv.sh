#!/bin/bash

# The PBS directives
#SBATCH -N 2
#SBATCH -p RM
#SBATCH -n 8
#SBATCH -t 00:01:00
#  Memory Request
#SBATCH --mem=2gb

# Load the MPI module 
module load openmpi

# Change to MPI project directory
cd $PROJECT/lecture_materials/send_recv

# This fixes common MPI errors
export DAPL_DBG_TYPE="0"

# Echo
echo "#-#-#Job started on `hostname` at `date` "

# Compile
mpicc send_recv.c -o send_recv.out

# Echo for debugging
echo "#-#-#Compilation completed and execution started at `date`"

# Run
mpirun -n 2 send_recv.out > log.send_recv.out

# Echo for debugging 
echo "#-#-#Job Ended at `date`"

