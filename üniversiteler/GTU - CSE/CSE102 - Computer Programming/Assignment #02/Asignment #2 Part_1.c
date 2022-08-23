#include <stdio.h>
#include <math.h>

int draw_triangle(int side1,int side2, int side3);
void type_triangle(int side1,int side2, int side3);
int perimeter_triangle(int side1,int side2, int side3);
double area_triangle(int side1,int side2, int side3,int perimeter);


int main(void){
    int side1,side2,side3,control,perimeter;
    double area;
    printf("Enter the first side:\n");
    scanf("%d",&side1);
    printf("Enter the second side:\n");
    scanf("%d",&side2);
    printf("Enter the third side\n");
    scanf("%d",&side3);
    control=draw_triangle(side1,side2,side3);
    if (control ==1){
        printf("According to the triangle inequality theorem, this triangle can be drawn.\n");
        type_triangle(side1,side2,side3);

        perimeter=perimeter_triangle(side1,side2,side3);
        printf("The perimeter is %d\n",perimeter);

        area=area_triangle(side1,side2,side3,perimeter);
        printf("The area is %lf\n",area); }
    else
        printf("According to the triangle inequality theorem, this triangle cannot be drawn. \n");

}


int draw_triangle(int side1,int side2, int side3){
    int r=0;
    if(side1+side2<=side3 || side1+side3<=side2 || side3+side2<=side1){
        return r; }
    else {
        r=1;
        return r; }
}


void type_triangle(int side1,int side2, int side3){
    if (side1==side2 && side1==side3 && side2==side3)
        printf("This triangle is equilateral\n");
    else if((side1==side2 && side1!=side3 && side2!=side3)|| (side2==side3 && side2!=side1 && side3!=side1)||(side1==side3 && side1!=side2 && side3!=side2))
        printf("This triangle is isosceles\n");
    else
        printf("This triangle is scalene");
}

int perimeter_triangle(int side1,int side2, int side3){
    return side1+side2+side3;
}

double area_triangle(int side1,int side2, int side3,int perimeter){
    int p = perimeter/2;
    return sqrt(p*(p-side1)*(p-side2)*(p-side3));
}
