#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#define MAX 100



int stack[MAX];
int top = -1;


int evaluatePostfix(char *);
void push(int);
char pop();


int main (){
	char postfix[100];

	printf("Enter Postfix Expression-\n");
	gets(postfix);
	int result = evaluatePostfix(postfix);
	printf ("Value of Postfix Expression  %s is  %d\n", postfix, result);

}


int evaluatePostfix(char *postfix){

	int i,l,val,val1,val2;
	l = strlen(postfix);

	i=0;
	
	while(i<l){
		if (isalpha(postfix[i])){
			printf("Enter the value of %c\n", postfix[i]);
			scanf("%d",&val);
            push(val);
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            
            switch (postfix[i])
            {
             case '+': push(val2 + val1); break;
             case '-': push(val2 - val1); break;
             case '*': push(val2 * val1); break;
             case '/': push(val2/val1);   break;
            }
        }
    
		i++;
	}
	return pop();


}



char pop(){
	int item;
	if(top==-1){
		printf("Stack Underflow:\n");
		return 0;
	}else{
		
        item = stack[top];
        top = top-1;
	}
	return item;
}

void push(int item){
	if(top==MAX-1){
		printf("Stack Overflow:\n");
	}else{
        top = top+1;
        stack[top] = item;
	}
}





