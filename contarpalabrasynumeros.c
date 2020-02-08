#include<stdio.h>

/*	ENUNCIADO DEL EJERCICIO
Leer un archivo de texto caracter por caracter e identificar:
	1- Cuantas palabras sin numeros hay, ejemplo: hola, Hoy, AYER, ahora
	2- Cuantos numeros hay, ejemplo: 4, 589, 1213465, 0001
	3- Cuantas palabras con numeros hay, ejemplo: c0mo, 2apato, tre5, 9ueso
*/

int main(){

	FILE * flujo = fopen("texto.txt", "r+");
	int c;
	int palabrassinnumeros=0;
	int numeros=0;
	int palabrasconnumeros=0;
	int encontreletra=0;
	int encontrenumero=0;
	int finpalabra = 0;
	

	while((c = getc(flujo)) != EOF){
		if(isalpha(c)){//isalpha es una funcion que devuelve true si el caracter evaluando es una letra
			encontreletra=1;
			//printf("%c es letra \n",c);
		}else if(isdigit(c)){//	isdigit es una funcion que devuelve true si el caracter evaluando es un digito		
			 encontrenumero=1;			
			//printf("%c es numero \n",c);
		}else{
			finpalabra=1;
		}
		
		if(finpalabra==1){	
			if(encontreletra==0 && encontrenumero==1){
				numeros++;// aumento de 1 en 1 el contador de numeros
				//printf("sume numeros \n");
			}else if(encontreletra==1 && encontrenumero==0){
				palabrassinnumeros++;// aumento de 1 en 1 el contador de palabras sin numeros
				//printf("sume palabras sin numeros \n");
			}else if(encontreletra==1 && encontrenumero==1){
				palabrasconnumeros++;// aumento de 1 en 1 el contador de palabras con numeros
				//printf("sume palabras con numeros \n");
			}
			
		finpalabra=0;	
		encontreletra=0;
		encontrenumero=0;
		}
	}

			
	fclose(flujo);
	printf("\nSe a leido el archivo correctamente..\n");
	printf("\n\Se encontraron %i palabras sin numeros",palabrassinnumeros);
	printf("\nSe encontraron %i numeros",numeros);
	printf("\nSe encontraron %i palabras con numeros",palabrasconnumeros);
	return 0;
}
