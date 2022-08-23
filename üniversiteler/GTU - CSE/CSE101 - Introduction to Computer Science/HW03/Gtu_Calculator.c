#include <stdio.h>

float add_num(float a,float b)
{
    printf("Welcome To add numbers. Enter Two Number:");
    scanf("%f",&a);
    scanf("%f",&b);
    return a+b;
}
float sub_num(float a,float b)
{
    printf("Welcome To subtract numbers. Enter Two Number:");
    scanf("%f",&a);
    scanf("%f",&b);
    return a-b;
}
float multi_num(float a,float b)
{
    printf("Welcome To multiply numbers. Enter Two Number:");
    scanf("%f",&a);
    scanf("%f",&b);
    return a*b;
}
float divide_num(float a,float b)
{
    printf("Welcome To num divider. Enter first the numerator after denominator:");
    scanf("%f",&a);
    scanf("%f",&b);
    if (b==0)
    {
        printf("Denominator can not be zero, Please enter different number:");
        do
        {
        scanf("%f",&b);
        }
        while (b==0);
    }

        return a/b;
}
float exponent_num(float a,float b)
{
    printf("Welcome To NTh Power Calculator. Enter first ground after exponent:");
    scanf("%f",&a);
    scanf("%f",&b);
    float temp=a;
    if (a==0)
    {
        return 0;
    }
    else if (b==0)
    {
        return 1;
    }
    else
    {
        for (int i=1; i<b; i++)
    {
        a = a*temp;
    }
    return a;
    }
}
float avarage_num(char a)
{
    printf("Welcome To average calculator\nPlease Enter 'zero' for finish entering number and calculate the average.\n");
    printf("Enter Numbers:");
    int holder=0;
    float temp=0;
    while (1)
    {

        scanf("%c",&a);
        if (a=='q')
        {
            return temp/holder;
        }
        else
        {
            int a;
            scanf("%d",&a);
            temp=temp+a;
            holder++;
        }
    }
}
float max_num(float a)
{
    printf("Welcome To max number calculator\nPlease Enter 'zero' for finish entering number and calculate the max number.\n");
    printf("Enter Numbers:");
    float max=0;
    while (1)
    {
        scanf("%f",&a);
        if (a==0)
        {
            return max;
        }
        else if (a<0)
        {
            if (max==0 || max <a)
                max=a;
        }
        else if (a>0)
        {
            if (max < a)
                max =a;
        }
    }
}
int main (void)
{
    float a,b,x;
    float calc=0;
    printf("%% WELCOME TO GTU CALCULATOR MACHINE %%\n"
            "%% STUDENT NAME:Muhammed Oguz        %%\n"
            "%% PLEASE SELECT FROM THE FOLLOWING  %%\n"
            "%% MENU :                            %%\n"
            "(1) ADD TWO NUMBERS\n"
            "(2) SUBTRACT TWO NUMBERS\n"
            "(3) MULTIPLY TWO NUMBERS\n"
            "(4) DIVIDE TWO NUMBERS\n"
            "(5) TAKE THE NTH POWER OF A NUMBER\n"
            "(6) FIND AVERAGE OF NUMBERS INPUTTED\n"
            "(7) FIND THE MAXIMUM OF NUMBERS INPUTTED\n"
            "(0) EXIT\n"
            );

    while (1)
    {

        printf("PLEASE SELECT:");
        scanf("%f",&x);
        if(x==1)
        {
            calc=add_num(a,b);
            printf("Result: %f\n",calc);
        }
        else if (x==2)
        {
            calc=sub_num(a,b);
            printf("Result: %f\n",calc);
        }
        else if (x==3)
        {
            calc=multi_num(a,b);
            printf("Result: %f\n",calc);
        }
        else if (x==4)
        {
            calc=divide_num(a,b);
            printf("Result: %f\n",calc);
        }
        else if (x==5)
        {
            calc=exponent_num(a,b);
            printf("Result: %f\n",calc);
        }
        else if (x==6)
        {
            calc=avarage_num(a);
            printf("Result: %f\n",calc);
        }
        else if (x==7)
        {
            calc=max_num(a);
            printf("Result: %f\n",calc);
        }
        else if (x==0)
        {
            printf("Exiting...");
            break;
        }
        else
        {
            printf("Invalid Request. Please Look At the Menu.\n");
            continue;

        }
    }
    return 0;
}
