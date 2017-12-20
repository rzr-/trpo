typedef struct Stack Stack;

struct Stack { 
	int data;
	Stack *next;
}; 

/*init stack if structure is empty*/ 
void init_Stack (Stack **_root, int value) {
    Stack *ptr = calloc(1, sizeof(Stack));
    ptr->next = *_root;
    (*_root) = ptr; 
    (*_root)->data = value;
}

/*push element into the stack*/
void push (Stack **_root, int value) {
    if(*_root == NULL) {                   
        init_Stack(_root, value);
        return;
    }
    Stack *ptr = calloc(1, sizeof(Stack));
    *ptr = **_root;
    (*_root)->data = value;
    (*_root)->next = ptr;

}

/*check if stack is empty*/
int is_empty (Stack *_root) {
    return _root == NULL;
}

/*returns the top element of the stack*/
int top (Stack *_root) {                     
    if(!is_empty(_root))
        return _root->data;
    else printf("Stack is empty.\n");
    return 0; 
}

/*pops the element at the top*/
void pop (Stack **_root) {
    if (!is_empty( (*_root) )) {
        Stack *temp = calloc(1, sizeof(Stack));
        temp = (*_root);
        (*_root) = (*_root)->next;
        free(temp);
    }
    else printf("Stack is empty.\n");
}

/*returns the number of elements in the stack*/
int size (Stack *_root) {
    Stack *ptr = calloc(1, sizeof(Stack));
    ptr = _root; 
    int count = 0;
    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    free(ptr);
    return count;
}

void print (Stack *_root) {
    if (!is_empty(_root)) {
        Stack *ptr = calloc(1, sizeof(Stack));
        ptr = _root;
        printf("[%d]", ptr->data);
        ptr = ptr->next;
        while(ptr != NULL) {
            printf(", [%d]",ptr->data);
            ptr = ptr->next;
        }
        free(ptr);
        printf ("\n");
    }
    else printf("Stack is empty.\n");
}