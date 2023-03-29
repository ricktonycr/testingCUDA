cmake_minimum_required(VERSION 2.8)
project(proj LANGUAGES CXX CUDA)

set (CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

#### use cuda ####
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS};-gencode arch=compute_50,code=sm_50;-lineinfo; -cudart=static; -Xptxas; -v")

include_directories($ENV{CUDA_INCLUDE_DIRECTORY})
link_directories($ENV{CUDA_LIBRARY_DIRECTORY})

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

ADD_EXECUTABLE(
proj 
src/cudafile.cu
src/main.cpp)

target_link_libraries(proj 
    ${GTKMM_LIBRARIES}  )