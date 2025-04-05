#include<stdio.h>
#include<ctype.h>

//A program that decode a encrypted message
/*
Logic : * All letters should be uppercase or converted to uppercase
        * Letter are changed to i'th letter before, where i is the position
          of the letter from left to right.
*/

//Function to decode
void decode(char *msg){
    for(int i = 0; msg[i] != '\0'; i++){
        msg[i] = toupper(msg[i]);  //make the letter uppercase
        //if char goes beyond A change to Z
        if(msg[i] - i < 'A'){
            int diff = 'A' - (msg[i] - i); //difference from 'A'
            msg[i] = 'Z' - diff + 1;
            continue;
        }
        msg[i] -= (i + 1);
    }
}


int main(){
    //get the encrypted message
    char message[100];
    scanf("%[^\n]s",message);

    //decode the message.
    decode(message);

    //print the decoded message
    printf("%s\n",message);

    return 0;

}