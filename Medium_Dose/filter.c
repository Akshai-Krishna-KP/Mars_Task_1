#include<stdio.h>
#include<stdlib.h>
#define N 100

//comparing function used for qsort
int comp(const void *a, const void *b){
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}

// Function to read sensor data from log.txt
int read_data(double data[], int max_size){
    //define a ptr for file and open it in read mode.
    FILE *file = fopen("sensor_log.txt", "r");
    if(!file){
        printf("File opening failed succesfully\n");
        return 0;
    }

    //count the number of data and add the data into data array.
    int count = 0;
    while(count < max_size && fscanf(file, "%lf", &data[count]) == 1){
        count++;
    }
    fclose(file);//close the file.
    return count;
}

//Muchiko Filter ( Mean Filter )
void muchiko_filter(double data[], double result[], int n, int wSize){
    if(wSize > n)   return;//invallid window size detected
    
    //find the mean between windoe size
    for(int i = 0; i <= n - wSize; i++){
        double sum  = 0.0;
        for(int j = i; j < wSize && j < n; j++){
            sum += data[j];
        }
        result[i] = sum/n;//update the result to array
    }
}

//Sanchiko Filter ( Median Filter )
double sanchiko_filter(double data[], double result[], int n, int wSize){
    if(wSize > n)   return;//invallid window size detected
    
    //find the median between window size
    for(int i = 0; i <= n - wSize; i++){
        //create a temporary array to preserve orginal data
        double temp[n];
        for(int j = 0; j < wSize; j++)
            temp[i] = data[i];

        qsort(temp, wSize, sizeof(double), comp);//sort the array
        
        //check if the window size if even or not
        if(wSize % 2 == 0){
            result[i] = (temp[wSize/2 -1] + temp[wSize/2]) / 2.0;
        }
        else{
            result[i] = temp[wSize/2];
        }
    }
}

//MAIN function
int main(){
    //define data array and get value from file
    double data[N];
    int n = read_data(data, N);
    int wSize
    
    //check the validity of n and window size
    if(n == 0 || n < wSize){
        printf("Insufficient data\n");
        return 1;
    }

    //dynamically making a array for results
    double *muchiko_result = (double*)malloc((n - m + 1) * sizeof(double));
    double *sanchiko_result = (double*)malloc((n - m + 1) * sizeof(double));
    if (!muchiko_result || !sanchiko_result) {
        perror("Memory allocation failed");
        return 1;
    }

    //get teh result after doing the filtering
    muchiko_filter(data, muchiko_result, n, wSize);
    sanchiko_filter(data, muchiko_result, n, wSize);

    //print out the result
    printf("Muchiko Filter:-\n");
    for(int i = 0; i < n - wSize; i++){
        printf("%.2f ", muchiko_result[i]);
    }
    printf("\n");
    printf("Sanchiko Filter:-\n");
    for(int i = 0; i < n - wSize; i++){
        printf("%.2f ", sanchiko_result[i]);
    }
    printf("\n\n");

    printf("Muchiko Filter will give a smooth data result. but a single extreme will ruin the accuracy\n");
    printf("Sanchiko Filter will remove spikes in data and reduce noise, but not be smooth\n");
    printf("Best option will be to use the filter according to the need/n or maybe in hybrid depending on the situation.\n");

    result 0;
}