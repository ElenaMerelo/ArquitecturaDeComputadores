
//Compilacion: 

#include <stdio.h>
#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main()
{
    int i, n=7;
    int a[n], v;

    for(i=0; i<n; i++) a[i]=i+1;

    #pragma omp parallel for lastprivate(v)
    for(i=0; i<n; i++)
    {
        v=a[i];
        printf("thread %d v=%d \n", omp_get_thread_num(), v);
    }

    printf("\n Fuera de la construccion 'parallel for' v=%d\n", v);
}