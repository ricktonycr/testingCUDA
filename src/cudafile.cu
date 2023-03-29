#include<thrust/host_vector.h>
#include<thrust/device_vector.h>
#include<thrust/device_ptr.h>

#define blocksize 512
#define maxblocks 65535
#define N 1024

__global__ void addKernel(int* a, int* b, int* c){
    int i = blockIdx.x;

    if(i < N){
        c[i] = a[i] + b[i];
    }
}

void add(int* a, int* b, int* c){
    addKernel<<<N,1>>>( a, b, c );
}