/***************************************************************************
 * 
 * Copyright (c) 2015 xxx.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
/**
 * @file Quick.c
 * @author divesli(divesli@xxx.cn)
 * @date 2015/01/22 15:38:48
 * @version $Revision$ 
 * @filecoding UTF-8 
 * @brief 
 *  
 */

#include <stdio.h>
#include <stdlib.h>

void quickSort(int * a, int low, int high){  
    int pos;  
    if(low < high){  
        pos = findPos(a, low, high);  
        quickSort(a, low, pos-1);  
        quickSort(a, pos+1, high);  
    }  
}  

int findPos (int * a, int low, int high){  
    int val = a[low];  

    while(low < high){  
        while(low < high && a[high] >= val){  
            --high;  
        }  
        a[low] = a[high];  

        while(low < high && a[low] <= val){  
            ++low;  
        }  
        a[high] = a[low];  
    }  
    a[low] = val;  
    return low;  
}


int main() {
    int max = 100000;
    int i, a[max];
    srand((unsigned int) time(NULL));
    for(i = 0; i < max; i++) {
        a[i] = (int)((float)max * rand()/(RAND_MAX + 1.0));
    }
    quickSort(a,0,max-1);
//    for(i = 0; i < max; i++) {
//        printf("%d ",a[i]);
//    }
//    printf("\n");
    return 0;
}
