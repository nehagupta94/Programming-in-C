#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INT_SIZE sizeof(int) * 8

/* Binary logic has been adapted from 
https://codeforwin.org/2016/01/c-program-to-convert-decimal-to-binary-number-system-using-bitwise-operator.html
and has been implemented with my understanding */

void binaryArray(int n, int array[], int size){
    int index=INT_SIZE - 1, i,count = 0, p;
    do
    {
        // Right Shift 
        p = n >> index;
        
        // Store LSB
        array[31-index] = p & 1;
        index--;
    }while(index >= 0);
}

void binaryPrinter(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
    }
}

unsigned int countOnes(int num){
    int index=INT_SIZE - 1, i,count = 0, p;
    int bin[INT_SIZE];
    do
    {
        // Right Shift 
        p = num >> index;
        
        // Store LSB
        bin[index] = p & 1;
        
        if(bin[index]==1){
            count ++;
        }
        
        // Decrement index
        index--;
    }
    while(index >= 0);

    return count;
}

int myStrStr(char haystack[], char needle[], char buffer[]){
    int i=0,j=0,flag=0;
    memset(&buffer[0],0,255);
    // return 0 if haystack or needle is empty
    if(*haystack == '\0' || *needle == '\0'){
      return flag;
    }
    // if needle is greater than haystack, return 0
    if(strlen(needle)>strlen(haystack)){
        return flag;
    }
    do{
    	// if haystack not matching to needle, increment i and let j be 0
      if(haystack[i]!=needle[j]){
        i++;
        j=0;
      }
      	// if haystack and needle is matching, enter element in buffer and increment j and i
      else if (haystack[i]==needle[j]){
        buffer[j]=needle[j];
        j++;
        i++;
      }
    }
    while(needle[j]!='\0'); // loop till the needle j is not empty
    if(strlen(buffer)==strlen(needle)){ // if string length of buffer is equal to needle, return 1
        flag=1;
    }
    return flag;
}
