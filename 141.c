#include <stdio.h>
#include <math.h>

int isProgressive(double a, double b, double c){
    // printf("%f %f %f\n", a, b, c);
    if(c == 0){
        return -1;
    }
    else if(a*c == b*b){
        return 1;
    }
    else{
        return -1;
    }
}

void sort(double arr[3]){
    double tmp;
    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){
            if(arr[i]<arr[j]){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main( void ) {
    double arr[3];
    double val = 0;
    double n;
    for (int N = 0; N <= pow(10, 6); N++){
        n = pow(N, 2);
        printf("\r%d, %f, %f", N, n, val);
        for(int d=1; d <= N; d++){
            arr[0] = d;
            arr[1] = floor(n/d);
            arr[2] = n - arr[0]*arr[1];
            sort(arr);
            if(isProgressive(arr[0], arr[1], arr[2]) == 1){
                val += n;
                printf("\r%d: %f: %f\n", N, n, val);
                for(int i=0; i<3; i++){
                    printf("_%f_", arr[i]);
                }
                printf("\n");
                break;
            }
        }
    }
    printf("\n***%f***\n", val);
}