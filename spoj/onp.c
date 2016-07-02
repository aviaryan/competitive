// algo - http://csis.pace.edu/~wolf/CS122/infix-postfix.htm
// Solved in school :-)

#include<stdio.h>
#include<ctype.h>
#define SZ 100

typedef struct stack
{
 int data[SZ];
 int top;
} stack;

int priority(char x){
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/' || x == '%')
		return 2;
	if (x == '^')
		return 3;

	return 4;
}


void init(stack *s){
	 s->top=-1;
}


int empty(stack *s){
	if(s->top==-1)
		return 1;
	else 
		return 0;
}


int full(stack *s){
	if(s->top==SZ-1)
		return 1;
	else 
 		return 0;
}


void push(stack *s,char x){
	s->top=s->top+1;
	s->data[s->top]=x;
}


char pop(stack *s){
	 int x;
	 x=s->data[s->top];
	 s->top=s->top-1;
	 return x;
}


char top(stack * s){
	 return(s->data[s->top]);
}

int main()
{
	int t;
	scanf("%d ", &t);

	while (t--){
		stack s;
		char x;
		int token;
		init(&s);
		
		//printf("Expression to convert to postfix\n");
		while((token=getchar())!='\n')
		{
			if(isalnum(token))
				 printf("%c",token);
			else
				if(token == '(')
					push(&s,'(');
				 else
				 {
					if(token == ')')
						while((x=pop(&s))!='(')
							printf("%c",x);
					else
					{
						while(priority(token)<=priority(top(&s)) && !empty(&s))
						{
							x=pop(&s);
							printf("%c",x);
						}
						push(&s,token);
					}
				}
		}
		while(!empty(&s))
		{
			x=pop(&s);
			printf("%c",x);
		}
		printf("\n");
	}
	return 0;
}



