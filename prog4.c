#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int n;
    printf("Number of terms: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Enter a number greater than or equal to 2\n");
        return 1;
    }

    // Allocate an array for the Fibonacci series
    int *a = (int *)malloc(n * sizeof(int));
    a[0] = 0;
    a[1] = 1;

    clock_t st = clock(); // Start time
    omp_set_num_threads(2);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            printf("ID of thread involved in computation of Fibonacci series = %d\n", thread_id);
            for (int i = 2; i < n; i++) {
                a[i] = a[i - 1] + a[i - 2];
            }
        }

        #pragma omp barrier // Ensure thread 1 waits until thread 0 is done

        if (thread_id == 1) {
            printf("ID of thread involved in displaying of Fibonacci series = %d\n", thread_id);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }

    clock_t et = clock(); // End time
    double time_taken = (double)(et - st) / CLOCKS_PER_SEC * 1000; // Time in milliseconds
    printf("Time taken: %f ms\n", time_taken);

    return 0;
}

