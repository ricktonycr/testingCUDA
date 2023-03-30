#include<thrust/host_vector.h>
#include<thrust/device_vector.h>
#include<thrust/device_ptr.h>
#include "examplewindow.h"
#include <gtkmm/application.h>

#define N 1024

void add(int* a, int* b, int* c);

int main(int argc, char *argv[]){
    int a[N], b[N], c[N];
    int *dev_a, *dev_b, *dev_c;

    cudaMalloc( (void**)&dev_a, N * sizeof(int) );
    cudaMalloc( (void**)&dev_b, N * sizeof(int) );
    cudaMalloc( (void**)&dev_c, N * sizeof(int) );

    for (int i = 0; i < N; i++){
        a[i] = -i;
        b[i] =  i * i;
    }

    cudaMemcpy(dev_a, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N * sizeof(int), cudaMemcpyHostToDevice);

    add( dev_a, dev_b, dev_c );

    cudaMemcpy(c, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++){
        printf( "%d + %d = %d\n", a[i], b[i], c[i] );
    }
    
    cudaFree( dev_a );
    cudaFree( dev_b );
    cudaFree( dev_c );

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    ExampleWindow window;

    //Shows the window and returns when it is closed.
    return app->run(window);
}