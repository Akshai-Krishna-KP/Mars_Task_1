#include<stdio.h>
#include<stdlib.h>
#define N 100

//comparing function needed for qsort
int comp(const void *a, const void *b){
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}

int read_data(const char* filename, double data[], int max_size){
    FILE *file = fopen(filename, "r");
    if(!file){
        printf("File opening failed successfully\n");
        return 0;
    }

    int count = 0;
    while(count < max_size && fscanf(file, "%lf", &data[count]) == 1){
        count++;
    }
    fclose(file);
    return count;
}

void munchiko_filter(double munchiko_result[], double data[], int n, int wSize){

    for(int i=0; i <= n - wSize; i++){
        double sum = 0.0;
        for(int j = 0; j < wSize && j < n; j++){
            sum += data[i + j];
        }
        munchiko_result[i] = sum/wSize;
    }

}

void sanchiko_filter(double sanchiko_result[], double data[], int n, int wSize){
    for(int i = 0; i <= n - wSize; i++){
        double temp[wSize];
        for(int j=0; j < wSize; j++){
            temp[j] = data[i + j];
        }
        qsort(temp, wSize, sizeof(double), comp);
 
        if(wSize % 2 == 0){
            sanchiko_result[i] = (temp[wSize/2 - 1] + temp[wSize/2]) / 2.0;
        }
        else{
            sanchiko_result[i] = temp[wSize/2];
        }
    }
}

int main(){
    double data[N];
    int n = read_data("sensor_log.txt" ,data, N);
    
    int wSize;
    printf("Enter the Window Size:");
    scanf("%d", &wSize);

    double munchiko_result[n - (wSize-1)], sanchiko_result[n - (wSize-1)];
    munchiko_filter(munchiko_result, data, n, wSize);
    sanchiko_filter(sanchiko_result, data, n, wSize);

    //print out the result
    printf("Muchiko Filter:-\n");
    for(int i = 0; i < n - wSize + 1; i++){
        printf("%.2f ", munchiko_result[i]);
    }
    printf("\n");
    printf("Sanchiko Filter:-\n");
    for(int i = 0; i < n - wSize + 1; i++){
        printf("%.2f ", sanchiko_result[i]);
    }
    printf("\n\n");

    printf("Muchiko Filter will give a smooth data result. but a single extreme will ruin the accuracy\n");
    printf("Sanchiko Filter will remove spikes in data and reduce noise, but not be smooth\n");
    printf("Best option will be to use the filter according to the need/n or maybe in hybrid depending on the situation.\n");

    return 0;
}