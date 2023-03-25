#include<thrust/host_vector.h>
#include<thrust/device_vector.h>
#include<thrust/device_ptr.h>

void func(int size, int* a1, int* a2, int* a3);
void FillWithValue(int* arr, int size, int val);

int main()
{

    int size=1000;
    int *arr1, *arr2, *arr3;
    
    cudaMalloc((void**)&arr1, size * sizeof(int));
    FillWithValue(arr1,size,1);

    cudaMalloc((void**)&arr2, size * sizeof(int));
    FillWithValue(arr2,size,2);

    cudaMalloc((void**)&arr3, size * sizeof(int));

    int* harr = new int [size];
    cudaMemcpy(harr,arr1,size*sizeof(int),cudaMemcpyDeviceToHost);
    fprintf(stdout, "%d\n",harr[0]);

    func(size, arr1, arr2, arr3);

    int* harr2 = new int [size];
    cudaMemcpy(harr2, arr3, size*sizeof(int), cudaMemcpyDeviceToHost);
    fprintf(stdout, "%d\n",harr2[0]);
    cudaError_t err = cudaGetLastError();
    if (cudaSuccess != err)
        fprintf(stderr, "Cuda error: %s.\n", cudaGetErrorString(err));
    

    return 1;

}