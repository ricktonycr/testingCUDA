#include<thrust/host_vector.h>
#include<thrust/device_vector.h>
#include<thrust/device_ptr.h>

#define blocksize 512
#define maxblocks 65535

__global__ void funcKernel(int size, int* a1, int* a2, int* a3)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    while (i < size)
    {
        a3[i]=a1[i]+a2[i];
    }
}

void func(int size, int* a1, int* a2, int* a3)
{
    int gridsize = size / blocksize + 1;
    if (gridsize > maxblocks) gridsize = maxblocks;

    funcKernel << <gridsize, blocksize >> > (size, a1, a2, a3);
}

void FillWithValue(int* arr, int size, int val)
{

    thrust::device_ptr<int> d = thrust::device_pointer_cast(arr);
    thrust::fill(d, d + size, val);
}