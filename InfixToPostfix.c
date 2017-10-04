#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100



char stack[MAX];
int top = -1;



int precedence(char);
int scan_type(char);
int stack_empty();
void push(char);
char pop();


int main (){
	char infix[100], postfix[100],scan_ch,pop_ch;
	int l,i,k;


	printf("Enter Infix Expression-\n");
	gets(infix);
	l = strlen(infix);
	i=0;
	k=0;
	while(i<l){

		scan_ch = infix[i];
		switch(scan_type(scan_ch)){
				
			case 1:

				postfix[k] = scan_ch;
				k = k+1;
				break;
			case 2:

				push(scan_ch);
				break;
			case 3:

				pop_ch = pop();
				while(!stack_empty() && pop_ch!='('){
					postfix[k] = pop_ch;
					k = k+1;
					pop_ch = pop();
				}
				break;
			case 4:

				if (stack_empty())
				{
					push(scan_ch);
				}else{
					if(precedence(scan_ch)>precedence(stack[top])){
						push(scan_ch);
					}else{
						while(!stack_empty() && (precedence(stack[top])>=precedence(scan_ch))){
							postfix[k] = pop();
							k = k+1;
						}
						push(scan_ch);
					}
					
				}
				break;
		}

		i++;
	}
	while(top !=-1){
		postfix[k] = pop();
		k = k+1;
	}
	printf("Postfix Expression:-  ");
	for (int i = 0; i < k; ++i)
	{
		printf("%c",postfix[i]);
	}
	printf("\n");

}

char pop(){
	char ch;
	if(top==-1){
		printf("Stack Underflow:\n");
	}else{
		
        ch = stack[top];
        top = top-1;
	}
	return ch;
}

void push(char ch){
	if(top==MAX-1){
		printf("Stack Overflow:\n");
	}else{
        top = top+1;
        stack[top] = ch;
	}
}

int stack_empty(){
	if (top == -1)
	{
		return 1;
	}else{
		return 0;
	}
}



int scan_type(char ch){
	int x;
	if (isalpha(ch))
	{
		x=1;//operand
	}else {
		if (ch=='(')
		{
			x=2;//left_bracket
		}else if(ch==')'){
			x=3;//right_bracket
		}else{
			x=4;//operator
		}
	}
	return x;
}

int precedence(char ch){
	int priority;

	switch(ch){
		case '^':
			priority = 5;
			break;
		case '+':
			priority = 1;
			break;
		case '-':
			priority = 2;
			break;
		case '*':
			priority = 3;
			break;
		case '/':
			priority = 4;
			break;
		case '(':
			priority = 0;
			break;
	}
	return priority;
}
