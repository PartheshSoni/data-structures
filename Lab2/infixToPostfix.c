#include <stdio.h>
#include <string.h>
#define MAX 100
int tos=-1;

char stack[MAX];
void push(char x){
    if(tos==99)
        printf("Stack overflow!");

    else{
        tos++;
        stack[tos]=x;
    }
}

char pop(){
    if(tos==-1){
        printf("Stack underflow!");
        return '!';
    }
    else{

        return stack[tos--];

    }
}

char peek(){
    return stack[tos];
}

int getPriority(char x){
    if(x=='*'||x=='/'||x=='%')
    return 1;
    else if(x=='+'||x=='-')
    return 0;
	return -1;
}

int rank(char x){
    if(x>=65&&x<91||x>=97&&x<=122||x>=48&&x<=56){
        return 1;
    }
    else if(x=='*'||x=='/'||x=='%'||x=='+'||x=='-')
        return -1;
    return 0;
}
void main(){
    char infix[100], postfix[100];
    printf("Enter the infix expression for conversion into postfix: ");
    scanf("%s", infix);
    strcpy(postfix, "");
    push('(');
    strcat(infix, ")");


    int i=0, j=0;
    char temp;

    int r=0;
    for(i=0; infix[i]!='\0'; i++){
        r+=rank(infix[i]);

    }

    int flag=0;
    if(r==1){
     printf("$  Postfix\n");
	printf("(\n");
    for(i=0; infix[i]!='\0'; i++){

	/*printf("%c ", infix[i]);
	int h=0;
	for( h=0; h<j; h++)
		printf("%c", postfix[h]);
	printf("\n");*/
        if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(peek()!='('){
                postfix[j]=pop();
                j++;
            }
            pop();
        }
        else if(isdigit(infix[i])||isalpha(infix[i])){
            postfix[j]=infix[i];
            j++;
        }
        else if(getPriority(infix[i])==1||getPriority(infix[i]==0)){
            while(peek()!='('&&getPriority(peek())>=getPriority(infix[i])){
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);

        }
printf("%c ",infix[i]);
	int h=0;
	for( h=0; h<j; h++)
		printf("%c", postfix[h]);
	printf("\n");
    }
    /*while(peek()!='('){
        postfix[j]=pop();
        j++;
    }*/
    postfix[j]='\0';
	printf("\n\n");
	printf("Answer...\n");
    puts(postfix);
    }
   else printf("\nExpression invalid!\n");
}
