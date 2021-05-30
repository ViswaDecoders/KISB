#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


#define MAX_EXP 200
#define MAX_TOKEN 30
#define MIN_DOUBLE -12345

char *expression[MAX_TOKEN];

struct expstack{
    char *stack[MAX_TOKEN];
    int top;
};

struct expstack * newexpstack(){
    struct expstack* temp=(struct expstack *)malloc(sizeof(struct expstack));
    if(!temp){
        printf("ERR:\nArithmatic Expression Evalution Stack Creation Failed\nInsufficient Memory\n");
        return temp;
    }
    temp->top=-1;
    return temp;
}
int isEmpyt(struct expstack *e);
void dealloc(struct expstack * e);
int isEmpty(struct expstack *e);

void dealloc(struct expstack * e){
    for(int i=0;i<=e->top;i++){
        free(e->stack[i]);
    }
}
int isEmpty(struct expstack *e){
    return e->top==-1;
}

void push(struct expstack *e,char *val){
    if(e->top+1<MAX_TOKEN){
        e->stack[++(e->top)]=val;
    }
    else{
        printf("ERR:\nArithmatic Expression Evaluation Stack Overflow\n");
    }
}
char * pop(struct expstack *e){
    if(!isEmpty(e)){
        return e->stack[e->top--];
    }
    else{
        printf("ERR:\nArithmatic Expression Evaluation Stack Underflow\n");
    }
}
// void remove_endOfLine(char line[]) {
// 	int i = 0;
// 	while (line[i] != '\n')
// 		i++;
// 	line[i] = '\0';
// }

int operator(char *op){
    return (!strcmp(op,"+") || !strcmp(op,"-") || !strcmp(op,"*") || !strcmp(op,"/") || !strcmp (op,"^") || !strcmp(op,"(") || !strcmp(op,")")); 
}

int format_expression(char *cli_line){
    //extracts the expression for the command statement
    printf("%s\n",cli_line);
    char *exp=strtok(cli_line," ");
    exp=strtok(NULL," ");
    int index=0;
    while(exp){
        expression[index++]=exp;
        exp=strtok(NULL," ");
    }
    expression[index]=NULL;
    return index;
}

int precedence(char *op){
    if(!strcmp(op,"(")){
        return 0;
    }
    else if(!strcmp(op,"+")||!strcmp(op,"-")){
        return 1;
    }
    else if (!strcmp(op,"*")|| !strcmp(op,"/"))
    {
        return 2;
    }
    else if (!strcmp(op,"^"))
    {
        return 3;
    }
    return -1;
}

double evaluate(double op1,double op2,char *opernad){
    if(!strcmp(opernad,"+")){
        return op1+op2;
    }
    else if (!strcmp(opernad,"-"))
    {
        return op1-op2;
    }
    else if(!strcmp(opernad,"*")){
        return op1*op2;
    }
    else if(!strcmp(opernad,"^")){
        return pow(op1,op2);
    }
    else if(!strcmp(opernad,"/")){
        if(op2==0){
            printf("ERR:Division By Zero\nPlease Check The Expression\n");
            return MIN_DOUBLE;}
        return op1/op2;
    }
    
}


void evalExpression(char *expression[]){
    //evaluates the expression
    struct expstack *operandStack=newexpstack();
    struct expstack *operatorStack=newexpstack();
    if(operandStack && operandStack){
        int index=0;
        index=0;
        while(expression[index]){
            if(!operator(expression[index])){
                push(operandStack,expression[index]);
            }
            else if(!strcmp(expression[index],"(")){
                push(operatorStack,expression[index]);
            }
            else{
                if(!strcmp(expression[index],")")){
                    //while operator stack top is not (
                    //pop 2 operand pop one operator
                    //apply oprnd2 operator operand1
                    //push result in operand stack
                    while(strcmp(operatorStack->stack[operatorStack->top],"(")){
                        
                        double op1=atof(pop(operandStack));
                        double op2=atof(pop(operandStack));
                        char *oper=pop(operatorStack);
                        double result=evaluate(op2,op1,oper);
                        if(result!=MIN_DOUBLE){
                            char *res1=(char *)malloc(sizeof(char)*MAX_TOKEN+10);
                            sprintf(res1,"%f",result);
                            push(operandStack,res1);
                        }
                        else{
                            return ;
                        }
                    }
                    pop(operatorStack);
                }
                else{
                    //while operator stack is not empty and top has same or greater precedence than current op
                    ////pop 2 operand pop one operator
                    //apply oprnd2 operator operand1
                    //push result in operand stack
                    //end of while
                    //push this op into stack
                    while (!isEmpty(operatorStack) && precedence(operatorStack->stack[operatorStack->top])>=precedence(expression[index]))
                    {  
                        double op1=atof(pop(operandStack));
                        double op2=atof(pop(operandStack));
                        double result=evaluate(op2,op1,pop(operatorStack));
                        if(result!=MIN_DOUBLE){
                            char res[MAX_TOKEN+10];
                            sprintf(res,"%f",result);
                            push(operandStack,res);
                        }
                        else{
                            return ;
                        }
                    }
                    push(operatorStack,expression[index]);
                    
                }
               
            }
            index++;
        }
    
        while(!isEmpty(operatorStack)){
                        double op1=atof(pop(operandStack));
                        double op2=atof(pop(operandStack));
                        char *oper=pop(operatorStack);
                        double result=evaluate(op2,op1,oper);
                        if(result!=MIN_DOUBLE){
                            char res[MAX_TOKEN+10];
                            sprintf(res,"%f",result);
                            push(operandStack,res);
                        }
                        else{
                            return ;
                        }
    
        }
        printf("result: %lf\n",atof(operandStack->stack[operandStack->top]));
    }

}

// int main(){
// char cli_line[MAX_EXP];
// fgets(cli_line,MAX_EXP,stdin);
// remove_endOfLine(cli_line);
// int result=format_expression(cli_line);
// if(result){
//     evalExpression(expression);
// }
// }