#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE * flujo = fopen("texto.txt", "r+");
	int c, bl=0,bn=0,bln=0,psn=0,n=0;
	
	

	while((c = getc(flujo)) != EOF){
		if((c>=65 && c<=90) || (c>=97 && c<=122)){
			bl=1;
		}else if(c>=48 && c<=57){
			bn=1;
		}
		
		if(c==32 && bl==1){
			psn++;
		}
		
		if(c==32 && bn==1){
			n++;
		}
	}
	
	fclose(flujo);
	printf("\nSe a leido el archivo correctamente..");
	printf("\n\nEl total de psn son: %i",psn);
	printf("\n\nEl total de numeros son: %i",n);
	//printf("\n\nEl total letras y numeros son: %i",letrasNumeros);
	return 0;
}
