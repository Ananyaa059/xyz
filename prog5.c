#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int main() {
int n, i;
time_t st, et;
st = clock();
printf("Enter the number of students : ");
//scanf_s("%d", &n);
scanf("%d", &n);

double* arr = (double*)malloc(n * sizeof(double));
double arr_max = 0;

#pragma omp parallel for
for (i = 0; i < n; i++) {
srand(i);
arr[i] = (double)(rand() % 10000)/10 ;
}
printf("CGPA of students : ");
for (i = 0; i < n; i++)
printf("%.2lf ", arr[i]);
printf("\n");

#pragma omp parallel for
for (i = 0; i < n; i++) {
#pragma omp critical
if (arr_max < arr[i])
arr_max = arr[i];
}

et = clock();
printf("Student with highest CGPA = %.2lf\n", arr_max);
printf("Time Taken : %.2lfms\n", ((double)(et - st) * 1000 / CLOCKS_PER_SEC));
}
/*#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
int main(){
int i,n;
time_t st=clock();
printf("enter no. of students: ");
scanf("%d",&n);
double*arr=(double*)malloc(n*sizeof(double));
double arr_max=0;
#pragma omp parallel for
for(i=0;i<n;i++){
srand(i);
arr[i]=(double)(rand()%10000)/10;
}
printf("CGPA of students: ");
for(i=0;i<n;i++){
printf("%.2lf ",arr[i]);
}
printf("\n");
#pragma omp parallel for
for(i=0;i<n;i++){
#pragma omp critical
if(arr_max < arr[i])
arr_max=arr[i];
}
time_t et=clock();
printf("student with max cgpa %.2lf \n",arr_max);
printf("total time %.2lf ms\n",((double)(et-st)/CLOCKS_PER_SEC * 1000));
}*/
