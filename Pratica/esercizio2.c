#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Esercizzio su l'utilizzo dei punattori*/

char *reduce(char* array, int n); 

char *reduce(char* array,int n){
    char *result = malloc(n*sizeof(char));
    int k = 0; 
    for(int i = 0; i < n; i++){
        if((array[i] >= 'a' && array[i]<='z') || (array[i] >= 'A' && array[i] <= 'Z')){
          result[k++] = array[i];   
        }
    }
    result[k] = '\0';
    return result;
}

int main(){
    char str[] = {'a','b','0','!','K'};
    int len = sizeof(str)/sizeof(str[0]); 
    char *reduce_str = reduce(str,len); 
    printf("%s\n", reduce_str);
    free(reduce_str); 
    return 0; 
    
}