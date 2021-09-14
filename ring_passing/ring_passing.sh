#!/bin/bash

# The PBS directives
#SBATCH -N 6
#SBATCH -p RM
#SBATCH -n 8
#SBATCH -t 00:01:00
#  Memory Request
#SBATCH --mem=2gb

# Load the MPI module 
module load openmpi

# Change to MPI project directory
cd $PROJECT/bvw546/lecture_materials/ring_passing

# This fixes common MPI errors
export DAPL_DBG_TYPE="0"

# Echo
echo "#-#-#Job started on `hostname` at `date` "

# Compile
mpicc ring_passing.c -o ring_passing.out

# Echo for debugging
echo "#-#-#Compilation completed and execution started at `date`"

# Run
mpirun -n 6 ring_passing.out > log.ring_passing.out

# Echo for debugging 
echo "#-#-#Job Ended at `date`"

