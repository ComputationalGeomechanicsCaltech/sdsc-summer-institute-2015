#include <stdlib.h>

void saxpy(int n,
           float a,
           float *x,
           float *y)
{
#pragma acc kernels 
  for (int i = 0; i < n; ++i)
    y[i] = a * x[i] + y[i];
}

int main(int argc, char **argv)
{
  int N = 1<<20; // 1 million floats

  
  float *x = (float*)malloc(N * sizeof(float));
  float *y = (float*)malloc(N * sizeof(float));


  for (int i = 0; i < N; ++i) 
    {
      x[i] = 2.0f;
      y[i] = 1.0f;
    }


  saxpy(N, 3.0f, x, y);

  return 0;
}
