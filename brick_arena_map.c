#include<stdio.h>
#include<stdlib.h>
#define N 11

void create_map(char *mapfile, int map[N][N]){
    //initialize all point in map to 1
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = 1;
        }
    }

    //open the file in reading mode
    FILE *file = fopen(mapfile, "r");
    if(file == NULL){
        printf("File opening failed successfully\n");
        return;
    }

    //take the center of the map matrix as initial position.
    int init_point = (N - 1) / 2;
    //get value from file in row order
    int north, south, west, east;
    while(fscanf(file, "%d %d %d %d", &north, &east, &south, &west) == 4){
        //marking the obstacles
        int x = init_point, y = init_point;
        if(north > 0 && north < (N + 1) / 2){
            x = x - north;
        }
        if(east > 0 && east < (N + 1) / 2){
            y = y + east;
        }
        if(south > 0 && south < (N + 1) / 2){
            x = x + south;
        }
        if(west > 0 && west < (N + 1) / 2){
            y = y - west;
        }

        map[x][y] = 0;
    }

    map[init_point][init_point] = 5;
    fclose(file);
}

//Function to print the map
void printf_map(int map[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d  ", map[i][j]);
        }
        printf("\n");//newline
    }
    printf("\n");//newline
}

//MAIN function
int main(){
    int map[N][N];
    create_map("sample.txt", map);
    printf_map(map);

    return 0;
}
