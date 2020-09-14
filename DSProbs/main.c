//
//  main.c
//  DSProbs
//
//  Created by VEENA on 13/09/20.
//  Copyright © 2020 VEENA. All rights reserved.
//

#include <stdio.h>

typedef struct  node{
    void *dataPtr;
    struct node* link;
    
}NODE;

NODE* createNode(void *itemPtr){
  
    NODE* nodePtr;
    nodePtr = (NODE*) malloc(sizeof(NODE));
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;

}

void* larger (void* dataPtr1, void* dataPtr2, int(*ptrToCmpFun)(void*, void*)) {
    if((*ptrToCmpFun)(dataPtr1, dataPtr2) > 0) return dataPtr1;
    else return dataPtr2;
}

int compare (void* ptr1, void* ptr2){
    if(*(int* )ptr1 >= *(int*)ptr2)
        return 1;
    else
        return -1;
}



int main(int argc, const char * argv[]) {
    
    
    
    int i = 7;
    int j = 8;
    int lrg;
    
    lrg = (*(int*)larger(&i, &j, compare));
    
    printf("Larger value is : %d\n", lrg);
    
    
 
    int* newData;
    int* nodeData;
    NODE* node;
    
    newData = (int*)malloc(sizeof(int));
    *newData = 7;
    node = createNode(newData);
    
    newData = (int*)malloc(sizeof(int));
    *newData = 75;
    node->link = createNode(newData);
    
    nodeData = (int*)node->dataPtr;
    printf("Data from node 1 : %d\n", *nodeData);
    
    nodeData = (int*)node->link->dataPtr;
    printf("Data from node 2 : %d\n", *nodeData);
    
   return 0;
}
