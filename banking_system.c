#include <stdio.h>
#include <string.h>

struct person
{
    char name[50];
    char id[9];
    char kra_pin[4];
};
/*deposit should be a critical section*/
// static float deposit;
int checkValidity(float initial_amount);
int getBiodata(struct person *p);
int withdrawAmount(float bankBalance, float cashOut);

// this function checks weather the user
// is eligible for a discount or not
int checkValidity( float initial_amount)
{
    printf("Enter deposit: \n");
    scanf("%f", &initial_amount);

    if (initial_amount < 1000)
    {
        printf("Failed!\nMinimum amount is kes 1000!\n");
        return 1;
    }
    else
    {
        // deposit =  initial_amount;
        printf("Bank Balance: kes%.2f\n", initial_amount);
    }
}

//update biodata to a spreadsheet file
int getBiodata(struct person *p)
{
   printf("Enter name: \n");
   scanf("%s", p->name);
   printf("Enter national ID: \n");
   scanf("%s", p->id);
   printf("Enter KRA PIN: \n");
   scanf("%s", p->kra_pin);
}

int withdrawAmount(float bankBalance, float cashOut)
{
    printf("Withdraw amount: \n");
    scanf("%f", &cashOut);
    
    if(cashOut > bankBalance)
    {
        printf("No sufficient funds in your account!\n");
        return 1;
    }else{
        bankBalance = bankBalance - cashOut ;
    }
    printf("Bank Balance: %.2f\n", bankBalance);
}

int main(void)
{
    float cashOut;
    static float bankBalance;
    struct person p;
    getBiodata(&p);
    float initial_amount;
    checkValidity(initial_amount);
    bankBalance = initial_amount;
    
    withdrawAmount(bankBalance, cashOut);
    return 0;
}