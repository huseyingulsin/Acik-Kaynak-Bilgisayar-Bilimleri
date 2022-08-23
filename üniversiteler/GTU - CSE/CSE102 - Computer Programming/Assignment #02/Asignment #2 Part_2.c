#include <stdio.h>
#include <math.h>

int main(void){
	char s[20];
	FILE *fp;
	for (int i=0; i<200; i++){
		sprintf(s,"essek_meryem%d.txt",i);
		fp=fopen(s,"w");
	}
	
	fclose(fp);
}
