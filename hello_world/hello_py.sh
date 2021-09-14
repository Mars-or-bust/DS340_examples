#!/bin/bash

# The PBS directives
#SBATCH -N 6
#SBATCH -p RM
#SBATCH -n 8
#SBATCH -t 00:01:00
#  Memory Request
#SBATCH --mem=2gb

# Pip install requirements
module load openmpi
module load python
python -m ensurepip --upgrade
python -m pip install mpi4py


# Change to MPI project directory
cd $PROJECT/lecture_materials/hello_world

# This fixes common MPI errors
export DAPL_DBG_TYPE="0"

# Echo
echo "#-#-#Job started on `hostname` at `date` "

# Run
mpiexec -n 6 python hello_py.sh > log.hello_world_python.out


# Echo for debugging 
echo "#-#-#Job Ended at `date`"

