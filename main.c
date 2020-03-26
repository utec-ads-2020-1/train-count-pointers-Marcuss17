#include <stdio.h>
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
void count(int **p[]);
void sort(int arr[10]);

int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  sort(intVar);
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}

void count(int **p[]){
    int i = 0;
    int sizeOfAlready = 5;
    int *alreadyChecked[sizeOfAlready];   
    int m = 0;
    int count = 1;
    int aux = 0;
    int passBy = 0;
    int aux1;
    while(p[i] != NULL){
        passBy = 0;
        count = 0;
        int j = 0;
        for(int  k = 0; k < sizeOfAlready; k++){
            if(&(**p[i]) == alreadyChecked[k]){
                i++;
                passBy = 1;
                break;
            }
        }
        if(passBy == 0){
            while(p[j] != NULL){
                if(&(**p[i]) == &(**p[j])){
                    alreadyChecked[aux] = &(**p[i]);
                    aux1 = **p[i];
                    aux++;
                    count++;
                }
                j++;
            }
        }
        printf("%d %d\n",aux1,count);
        i++;
    }
}
    
void sort(int arr[4]){
    int aux;
    printf("\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0;j <4-i-1 ;j++){
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        } 
    } 
    printf("\n");
}
