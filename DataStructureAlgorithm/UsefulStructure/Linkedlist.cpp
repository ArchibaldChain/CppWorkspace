#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    LinkedNode nextNode;

} LinkedNode;

int main(){
    LinkedNode head;
    head.value = 0;
    int n = 6;
    LinkedNode Node[n];
    head.nextNode = Node[0];
    for(int i = 0; i < n; i++)
    {
        Node[i].value = i+1;
        if(i < n-1)
        Node[i].nextNode = Node[i+1];
    }
    
}

