#include<stdio.h>
#include<stdlib.h>
#define N 11
#define MAX_QUEUE (N * N)

typedef struct{
    int x, y;
}point;

typedef struct{
    point parent;
    int visited;
}node;

int map[N][N];
node path[N][N];
point queue[MAX_QUEUE];
int front = -1, rear = -1;

void enqueue(point p){
    queue[++rear] = p;
}

point dequeue(){
    return queue[++front];
}

int valid_checker(int x, int y){
    return (x >= 0) && (x < N) && (y >= 0) && (y < N) && (map[x][y]) && !path[x][y].visited;
}

void print_map(const char *filename){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = 1;
        }
    }

    FILE *file = fopen(filename, "r");
    if(!file){
        printf("Opening File failed successfully\n");
        exit(1);
    }

    int north, east, south, west;
    int centerX = N/2, centerY = N/2;
    while(fscanf(file, "%d %d %d %d", &north, &east, &south, &west) == 4){
        int x = centerX + east - west;
        int y = centerY + south - north;
        if(x >= 0 && x < N && y >= 0 && y < N){
            map[y][x] = 0;
        }
    }
    fclose(file);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void pathway(point end){
    point stack[MAX_QUEUE];
    int top = -1;
    
    point temp = end;
    while(!(temp.x == -1 && temp.y == -1)){
        stack[++top] = temp;
        temp = path[temp.x][temp.y].parent;
    }

    for(int i = top -1; i >= 0; --i){
        printf("[%d, %d]", stack[i].x, stack[i].y);
        if(i > 0) printf(" -> ");
    }
    printf("\n");
}

int find_shortest_path(point start, point end){
    enqueue(start);
    path[start.x][start.y].visited = 1;
    path[start.x][start.y].parent = (point){-1, -1};

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (front < rear) {
        point curr = dequeue();
        if(curr.x == end.x && curr.y == end.y)
            return 1;

        for(int i = 0; i < 4; ++i) {
            int nextX = curr.x + dir[i][0];
            int nextY = curr.y + dir[i][1];

            if (valid_checker(nextX, nextY)) {
                path[nextX][nextY].visited = 1;
                path[nextX][nextY].parent = curr;
                enqueue((point){nextX, nextY});
            }
        }
    }

    return 0;
}

int main(){
    printf("Arena Map :- \n");
    print_map("sample.txt");

    point start = {0, 0}, end = {10,10};
    
    printf("The shortest Path:-\n");
    if(find_shortest_path(start, end)){
        pathway(end);
    }
    else{
        printf("No Pathway found\n");
    }

    return 0;
}