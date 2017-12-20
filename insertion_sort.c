#include <stdio.h>
#include <stdlib.h>
#include "custom-stack.h"

Stack *sorted = NULL;
Stack *root = NULL;

void insertion_sort() {
    int x, y;
    x = top(root); 
    push(&sorted, x);
    pop(&root); 
    while(!is_empty(root)) {
        x = top(sorted);
        y = top(root);
        pop(&root); 
        while(x > y && !is_empty(sorted)) {
            x = top(sorted); 
            pop(&sorted);    
            push(&root, x);
        }
        push(&sorted, y); 
    }
    root = sorted; 
}

void read_input () {
    int p;

    while (scanf("%d", &p) != -1)
    {
        push(&root, p);
    }
    insertion_sort();
    print(root);
}

int main() {
    read_input();
    return 0;
}