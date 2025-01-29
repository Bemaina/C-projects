#include <stdio.h>

int main(void)
{
    int num1, num2;
    char op;         //operation
    float res;       //result

    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);

    printf("Enter operation:(+,-,x,/)\n");
    scanf(" %c", &op);

    switch(op)
    {
        case '+':
            res = num1 + (float)num2;
            break;
        case '-':
            res = num1 - (float)num2;
            break;
        case 'x':
            res = num1 * (float)num2;
            break;
        case '/':
            if(num2 == 0)
            {
                printf("Error!Division by zero\n");
                return 1;
            }else{
                res = num1 / (float)num2;
                break;
            }
        default:
            printf("Error!Invalid opperand\n");
    }
    printf("%d %c %d = %.2f\n", num1, op, num2, res);
    
    return 0;
}