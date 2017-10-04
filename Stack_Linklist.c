#include <stdio.h>
#include <stdlib.h>



struct Node{
	int data;
	struct Node *next;
};


void push();
void pop();
void display();
void peek();


struct Node *top = NULL;


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
	printf("Enter the element to be inserted:\n");
    scanf("%d",&item);

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p==NULL)
    {
    	printf("\nOut of Memory Space:\n");
    }else{
    	p->data = item;
    	p->next = top;
    	top = p;
    }  
}

void pop(){
	int item;
	struct Node *p;
	if(top==NULL){
		printf("Stack Underflow:\n");
	}else{
		
        item = top->data;
        p = top;
        top = top->next;
        free(p);
        printf("The poped element: %d\t\n",item);
	}
}

void display(){
	struct Node *p;
	if (top == NULL)
	{
		printf("Stack is Empty:\n");
	}else{
		p = top;
		while(p!=NULL){
			printf("%d\n",p->data);
			p = p->next;
		}
	}
}

void peek(){
	if (top == NULL)
	{
		printf("Stack is Empty:\n");
	}else{
		
		printf("The topmost element of the stack is %d\n",top->data);
	}
}
