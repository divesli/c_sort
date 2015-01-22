/***************************************************************************
 * 
 * Copyright (c) 2015 xxx.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
/**
 * @file Merge.c
 * @author divesli(divesli@xxx.cn)
 * @date 2015/01/22 15:07:28
 * @version $Revision$ 
 * @filecoding UTF-8 
 * @brief 
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeArray(int srcArr[], int tmpArr[], int s, int m, int e) {
    int i = s, j = m + 1, k = s, x;
    while(i != m + 1 && j != e + 1) {
        if (srcArr[i] < srcArr[j]) {
            tmpArr[k++] = srcArr[i++];
        } else {
            tmpArr[k++] = srcArr[j++];
        }
    } 
    while (i != m + 1) {
        tmpArr[k++] = srcArr[i++];
    }
    while (j != e + 1) {
        tmpArr[k++] = srcArr[j++];
    }

    for(x = s; x <= e; x++) {
        srcArr[x] = tmpArr[x];
    }
}

void mergeSort(int srcArr[], int tmpArr[], int s, int e) {
    int m;
    if (s < e) {
        m = (s + e)/ 2;
        mergeSort(srcArr, tmpArr, s, m);
        mergeSort(srcArr, tmpArr, m+1, e);
        mergeArray(srcArr, tmpArr, s, m, e);
    }
}


int main() {
    int max = 100000;
    int i, a[max], b[max];
    srand((unsigned int) time(NULL));
    for(i = 0; i < max; i++) {
        a[i] = (int)((float)max * rand()/(RAND_MAX + 1.0));
    }
    mergeSort(a,b,0,max-1);
//    for(i = 0; i < max; i++) {
//        printf("%d ",a[i]);
//    }
//    printf("\n");
    return 0;
}
