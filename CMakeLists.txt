cmake_minimum_required(VERSION 2.8)
project(proj LANGUAGES CXX CUDA)

set (CMAKE_CXX_STANDARD 14)

#### use cuda ####
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS};-gencode arch=compute_50,code=sm_50;-lineinfo; -cudart=static; -Xptxas; -v")

include_directories($ENV{CUDA_INCLUDE_DIRECTORY})
link_directories($ENV{CUDA_LIBRARY_DIRECTORY})

ADD_EXECUTABLE(
proj 
src/cudafile.cu
src/main.cpp)