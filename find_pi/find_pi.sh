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
cd $PROJECT/bvw546/lecture_materials/find_pi

# This fixes common MPI errors
export DAPL_DBG_TYPE="0"

# Echo
echo "#-#-#Job started on `hostname` at `date` "

# Compile
mpicc find_pi.c -o find_pi.out

# Echo for debugging
echo "#-#-#Compilation completed and execution started at `date`"

# Run
mpirun -n 2 find_pi.out > log.find_pi.out

# Echo for debugging 
echo "#-#-#Job Ended at `date`"

