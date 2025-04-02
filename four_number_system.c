#include<stdio.h>
#include<math.h>

//define struct for Quaternion
typedef struct{
    double w, x, y, z;
}quaternion;

//define struct for euler 
typedef struct{
    double x, y, z;
}euler;

//Function to convert euler to quaternion
quaternion eulertoquaternion(euler e){
    double cr = cos(e.x * 0.5);
    double sr = sin(e.x * 0.5);
    double cp = cos(e.y * 0.5);
    double sp = sin(e.y * 0.5);
    double cy = cos(e.z * 0.5);
    double sy = sin(e.z * 0.5);

    //convert to Quaternion using formula
    quaternion q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;
    
    return q;
}

int main(){
    //get euler angle from user
    euler e;
    printf("Roll:");
    scanf("%lf", &e.x);
    printf("Pitch:");
    scanf("%lf", &e.y);
    printf("Yaw:");
    scanf("%lf", &e.z);

    //Perfrom conversion
    quaternion q = eulertoquaternion(e);

    //printf the result
    printf("Quaternion : (%lf, %lf, %lf, %lf)\n", q.w, q.x, q.y, q.z);

    return 0;
}