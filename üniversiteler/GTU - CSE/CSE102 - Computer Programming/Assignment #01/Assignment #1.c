//(for compiling this use -lm commend end of the your gcc commend)
#include <stdio.h>  //standard library
#include <math.h>   //math library (for compiling this use -lm commend end of the your gcc commend)

void find_root();   //part 1 function name
void find_newtonian_root(); //part 2 function name
int find_multiple_closest(int a, int b); //part 3 function name

int main(void){
    int first,second,value; //for part 3 taking variables
    printf("Part 1 starting\n");
   /* find_root();            //part 1 function
    printf("Part 2 starting\n"); */
    find_newtonian_root();  //part 2 function
    printf("Part 3 starting \n");

    printf("Enter the first integer:\n");
    scanf("%d",&first);
    printf("Enter the second integer:\n");
    scanf("%d",&second);
    value=find_multiple_closest(first,second);
    if (value == 0){
        printf("Closet number to %d that is multiple of %d is itself\n",first,second);
    }
    else {
        printf("Closet number to %d that is multiple of %d is %d\n",first,second,value);
    }

    return 0;
}

void find_root() {
    int first,second,third;
    double delta,first_root,second_root;
    printf("please enter the first coefficient\n");
    scanf("%d",&first);
    printf("please enter the second coefficient\n");
    scanf("%d",&second);
    printf("please enter the third coefficient\n");
    scanf("%d",&third);
    delta = (second*second)-4*first*third; //calculating delta
    first_root=(-second+sqrt(delta))/2*first; //calculating first root
    second_root=(-second-sqrt(delta))/2*first;//calculating second root
    printf("Your function is %dx^2+(%d)x+(%d). ",first,second,third);
    if (delta<0)
        printf("Does not have any real roots\n");
    else if (first_root==second_root)
        printf("Your roots is double and they are %0.1lf\n",first_root);
    else {
        printf("Your roots are %0.1lf and %0.1lf\n",first_root,second_root);
    }
}

void find_newtonian_root(){
    int first,second,third,initial;
    double x1,x2,x3,x4,x5,derivative,func,value_x,difference,delta,root;
    printf("please enter the first coefficient\n");
    scanf("%d",&first);
    printf("please enter the second coefficient\n");
    scanf("%d",&second);
    printf("please enter the third coefficient\n");
    scanf("%d",&third);
    printf("please enter the initial\n");
    scanf("%d",&initial);
    printf("Your function is %dx^2+(%d)x+(%d). \n",first,second,third);
    delta = (second*second)-4*first*third;//calculating delta
    root=(-second+sqrt(delta))/2*first;//calculating root

    //calculating root with newton method part 1
    value_x=initial;//this part for easier copy paste thing
    func=(first*value_x*value_x)+(second*value_x)+third; //calculating function
    derivative=(2*first*value_x)+second;
    x1=initial-(func/derivative); //newton method applying
    difference=x1-root; //calculating difference between known root and new root.
    value_x=x1; //this part for printing function value
    func=(first*value_x*value_x)+(second*value_x)+third; //same func part lile above but it should for printing right value
    printf("Step x1 is %0.5lf and f(x) is %0.5lf and difference is %0.5lf \n",x1,func,difference); //prints

    //other parts are same just copied from part 1.
    if (difference==0)
        printf("Secil\n");
    if (x1==root)
        printf("\neyupoglu");
    //calculating root with newton method part 2
    value_x=x1;
    func=(first*value_x*value_x)+(second*value_x)+third;
    derivative=(2*first*value_x)+second;
    x2=x1-(func/derivative);
    difference=x2-root;
    value_x=x2;
    func=(first*value_x*value_x)+(second*value_x)+third;
    printf("Step x2 is %0.5lf and f(x) is %0.5lf and difference is %0.5lf \n",x2,func,difference);
    if (difference==0)
        printf("Secil\n");
    if (x2==root)
        printf("\neyupoglu");
    //calculating root with newton method part 3
    value_x=x2;
    func=(first*value_x*value_x)+(second*value_x)+third;
    derivative=(2*first*value_x)+second;
    x3=x2-(func/derivative);
    difference=x3-root;
    value_x=x3;
    func=(first*value_x*value_x)+(second*value_x)+third;
    printf("Step x3 is %0.5lf and f(x) is %0.5lf and difference is %0.5lf \n",x3,func,difference);
    if (difference==0)
        printf("Secil\n");
    if (x3==root)
        printf("\neyupoglu");
    //calculating root with newton method part 4
    value_x=x3;
    func=(first*value_x*value_x)+(second*value_x)+third;
    derivative=(2*first*value_x)+second;
    x4=x3-(func/derivative);
    difference=x4-root;
    value_x=x4;
    func=(first*value_x*value_x)+(second*value_x)+third;
    printf("Step x4 is %0.5lf and f(x) is %0.5lf and difference is %0.5lf \n",x4,func,difference);
    if (difference==0)
        printf("Secil\n");
    if (x4==root)
        printf("\neyupoglu");
    //calculating root with newton method part 5
    value_x=x4;
    func=(first*value_x*value_x)+(second*value_x)+third;
    derivative=(2*first*value_x)+second;
    x5=x4-(func/derivative);
    difference=x5-root;
    value_x=x5;
    func=(first*value_x*value_x)+(second*value_x)+third;
    printf("Step x5 is %0.5lf and f(x) is %0.5lf and difference is %0.5lf \n",x5,func,difference);
    printf("dif %lf",difference);
    printf("root %lf",root);
    printf("x5 %lf\n",x5);
    if (difference==0)
        printf("Secil\n");
    if (x5==root)
        printf("\neyupoglu");
}

int find_multiple_closest(int a, int b) {
    int quotient= a/b; //for calculate quotient
    int value1=(quotient)*b,value2=(quotient+1)*b; //calculating near nums
    int distance1=a-value1,distance2=value2-a; //for comparison values
    if (a%b==0){ //calculating remainder
        return 0;
    }
    else {
        if (distance1<distance2) //finds near one
            return value1;
        else if (distance2<distance1)
            return value2;
       else {   //if both of them have same distance returns bigger one.
            return value2;
       }
    }
}
