   
 #include<stdio.h>
 #include<stdlib.h>
struct Node{
    int val;
    struct Node *next;
};
typedef struct Node node;

typedef struct{
    node *top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *head = (MinStack*)malloc(sizeof(MinStack));
    head->top = NULL;
    return head;
}
node *makenode(int val){
    node *new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    return  new;
}

void minStackPush(MinStack* obj, long val) {
    node *p = makenode(val);
    p->next = obj->top;
    obj->top = p;
}

void minStackPop(MinStack* obj) {
    node *tofree = obj->top;
    if(obj->top == NULL){
        free(tofree);
        return;
    }
    obj->top = obj->top->next;
    free(tofree);
}

int minStackTop(MinStack* obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    if(obj->top == NULL) return 0;
    int min = obj->top->val;
    node *curr = obj->top;
    while(curr != NULL){
        if( min > curr->val){
            min = curr->val;
        }
        curr = curr->next;
    }
    return min; 
}

void minStackFree(MinStack* obj) {
    while(obj->top != NULL){
        minStackPop(obj);
    }
    free(obj);
   
}
