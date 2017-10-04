#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;



void push();
void pop();
void display();
void peek();


int main(){
	int choice;

	while(1){

		printf("\n---------------------------------------\n");
                printf("\n 1.Push     \n");
                printf("\n 2.Pop   \n");
                printf("\n 3.Display    \n");
                printf("\n 4.Peek    \n");
                       
                printf("\n 8.Exit       \n");
        printf("\n---------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n---------------------------------------\n");

		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 8:
			    exit(0);
                break;          
            default:
                printf("\n Wrong Choice:\n");
                break;
		}
	}
}




void push(){
	int item;

	if(top==MAX-1){
		printf("Stack Overflow:\n");
	}else{
		printf("Enter the element to be inserted:\n");
        scanf("%d",&item);
        top = top+1;
        stack[top] = item;
	}
}

void pop(){
	int item;

	if(top==-1){
		printf("Stack Underflow:\n");
	}else{
		
        item = stack[top];
        top = top-1;
        printf("The poped element: %d\t\n",item);
	}
}

void display(){
	if (top == -1)
	{
		printf("Stack is Empty:\n");
	}else{
		for (int i = top; i >=0; i--)
		{
			 printf("%d\n",stack[i]);
		}
	}
}
void peek(){
	if (top == -1)
	{
		printf("Stack is Empty:\n");
	}else{
		
		printf("The topmost element of the stack is %d\n",stack[top]);
	}
}
