#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE * flujo = fopen("texto.txt", "r+");
	int c,texto[1000],i=0,letras=0,numeros=0,letrasNumeros=0,f;
	

	while((c = getc(flujo)) != EOF){
		texto[i]=c;
	i++;		
	}
	
	for(f=0;f<i;f++){
		if((texto[f]>=48 && texto[f]<=57)){
			numeros++;
		}		
	}
	
	for(f=0;f<i;f++){
		if(((texto[f]>=65 && texto[f]<=90) || (texto[f]>=97 && texto[f]<=122))){
			letras++;
		}
	}
	
	for(f=0;f<i;f++){
		printf("\n%c",texto[f]);
		if(((texto[f]>=65 && texto[f]<=90) || (texto[f]>=97 && texto[f]<=122)) || (texto[f]>=48 && texto[f]<=57)){
			letrasNumeros++;
		}
		
	}
	fclose(flujo);
	printf("\nSe a leido el archivo correctamente..");
	printf("\n\nEl total de letras son: %i",letras);
	printf("\n\nEl total de numeros son: %i",numeros);
	printf("\n\nEl total letras y numeros son: %i",letrasNumeros);
	return 0;
}
