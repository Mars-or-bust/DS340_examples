#!/bin/bash

# The PBS directives
#SBATCH -N 1
#SBATCH -p GPU
#SBATCH -n 8
#SBATCH -t 00:01:00
#  Memory Request
#SBATCH --mem=2gb

# Change to project directory
cd $PROJECT/bvw546/lecture_materials/tf

# This fixes common MPI errors
export DAPL_DBG_TYPE="0"

# Echo
echo "#-#-#Job started on `hostname` at `date` "

# Compile
python mnist.py > log.mnist

# Echo for debugging 
echo "#-#-#Job Ended at `date`"

