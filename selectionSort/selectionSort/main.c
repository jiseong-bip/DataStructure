//
//  main.c
//  selectionSort
//
//  Created by 전지성 on 2023/05/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void selectionSort(int list[], int n)
{
    int temp;
    
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j)
            if(list[j] < list[i])
                SWAP(list[j], list[i], temp);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; ++i)
        list[i] = rand()%100;
    
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");
    selectionSort(list, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", list[i]);
    }

    return 0;
}
