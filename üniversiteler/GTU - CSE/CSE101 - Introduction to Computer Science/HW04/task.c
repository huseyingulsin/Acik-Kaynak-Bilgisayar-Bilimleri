
#include <stdio.h> //standart kütüphane

int Arduino_Operations(int a); //kullanılacak fonksiyon.

int main()
{
	printf("## WELCOME TO GTU ARDUINO LAB ##\n"
"## STUDENT NAME: MUHAMMED OGUZ ##\n"
"## PLEASE SELECT FROM THE FOLLOWING ##\n"
"## MENU :##\n"
"(1) TURN ON LED ON ARDUINO\n"
"(2) TURN OFF LED ON ARDUINO\n"
"(3) FLASH ARDUINO LED 3 TIMES\n"
"(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n"
"(5) Button press counter (bonus item)\n"
"(0) EXIT\n");
printf("operator 5i kullanırsanız, arduinoyu tekrar başlatınız. iki operator beraber çalışmamaktadır.");


int a,b;
while (1) {				//sonsuz döngüye alır.
printf("PLEASE SELECT:");

scanf("%d", &a);
if (a==1)			//led açar
	Arduino_Operations(1);
else if(a==2)			//led kapar
	Arduino_Operations(0);
else if(a==3) {			//led 3 kere blink eder
	printf("blink");
	Arduino_Operations(a);

}
else if(a==4) {			//bunu yapamadım.
	printf("square fonksiyonu bunu yapamadım hocam :)");
	Arduino_Operations(a);
}
else if(a==5){			//buton sayma işlemi
	printf("Her butona basıldığında tekrar 5'e basınız.\n");
	printf("sayı:");
	Arduino_Operations(a);
	printf("\n");

}
else if(a==0)
	break;
else
	printf("geçersiz operasyon");
	printf("\n");
}
return 0;
}


int Arduino_Operations(int a)
{

    	FILE *file;
	file = fopen("COM6","w+");  //cihazi açar
	fprintf(file,"%d",a); //cihaza yazar
	int b;
	fscanf(file,"%d",&b); 	//cihazdan okur
	printf("%d",b);		//sonucu yazar


	fclose(file);
return 0;
}


