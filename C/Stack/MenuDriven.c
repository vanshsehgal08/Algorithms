#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -9999

// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK{
    int *arr;
    int size;
    int top;
}mySTACK;

//Defining function isEmpty
int isEmpty(mySTACK *s){
    if(s->top == -1){
            return 1;
        }
    else{
        return 0;
    }
}

//Defining function isFull
int isFull(mySTACK *s){
    if(s->top == s->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

//Defining push operation
void push(mySTACK *s){
    int element;
    printf("Enter The Element to push: ");
    scanf("%d", &element);
    if(isFull(s)){
        printf("\t STACK overflow \n");
    }
    else{
        s->top++;
        s->arr[s->top] = element;
        printf("%d Pushed to Stack\n", element);
    }
}

//Defining pop operation
int pop(mySTACK *s){
    int element;
    if(isEmpty(s)){
        printf("\n STACK Underflow \n");
        return INT_MIN;
    }
    else{
        element = s->arr[s->top];
        s->top--;
        return element;
    }
}

//Defining peek operation
int peek(mySTACK *s){
    int i;
    printf("Where you want to peek: ");
    scanf("%d", &i);
    int arrayInd = s->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        printf("%d", s->arr[arrayInd]);
        return 0;
    }
}

//Defining show stack operation
void show(mySTACK *s){
    int i;
    printf("\t STACK elements are: ");
    if (isEmpty(s)){
        printf("Stack is Empty");
        printf("\n");
    }
    else{
        for(i=0; i<=s->top; i++)
            printf("%d ", s->arr[i]);
        printf("\n");
    }
}

//Defining top operation
int top(mySTACK *s){
    int element;
    if(isEmpty(s)){
        printf("\n STACK Underflow \n");
        return INT_MIN;
    }
    else{
        element = s->arr[s->top];
        printf("Top Element is: %d", element);
        return 0;
    }
}

//Delete Stack
void delete(mySTACK *s){
    if(s){
        if(s->arr){
            free(s->arr);
        }
        free(s);
    }
}

int main(){
    int ch;
    int size;
    printf("Enter size of stack: ");
    scanf("%d",&size);
    struct STACK *s = (struct STACK *) malloc(sizeof(struct STACK));
    s->size = size;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    while (1){
        printf("\n*** Stack Menu ***");
        printf("\n\n1.Insert\n2.Pop\n3.Display\n4.Peek\n5.Delete\n6.Top Element\n7.Exit");
        printf("\n\nEnter your choice(1-6):\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            show(s);
            break;
        case 4:
            peek(s);
            break;
        case 5:
            delete(s);
        case 6:
            top(s);
            break;
        case 7:
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
    return 0;
}
