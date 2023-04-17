#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printTable(){
	#ifdef _WIN32
		system("cls");
	#endif
	#ifdef __linux__
		system("clear");
	#endif
	printf("   Binary number   |   Decimal number\n");	

}

void previousTable(int a, int c, long int bintable[10][3]){

	int auxcounter = a;
	int counter = c;
		
	while(auxcounter < counter){
		if(auxcounter == 0){
			printTable();
		}
		printf("%ld", bintable[auxcounter][0]);

		for(int l = 0; l < (19-bintable[auxcounter][2]); l++){
			printf(" ");
		}
		printf("|%ld\n", bintable[auxcounter][1]);
		auxcounter++;
	}

}

void main(){

	long int bin, dec;
	int i = -1;
	int j = 0;
	int k;
	int first = 1;
	int size;
	int aux;
	int counter = 0;
	int auxcounter = 0;
	long int bintable[10][3];
	char binT[20];	
	
	printTable();

	while(bin != -1){
		scanf("%ld", &bin);
		if(bin == -1){
			break;
		}	
	
		sprintf(binT, "%ld", bin);
	
		while(binT[i+1] != '\0'){
			i++;
		}

		dec = 0;
		size = i+1;
	
		while(i != -1){
		
			if(binT[i] == '1'){
				dec += pow(2, j);
			}

			j++;
			i--;
		}	
		if(first){
			printTable();	
			first = 0;
		}
		if(counter>=10){
			printTable();
			counter = 0;	
		}

		previousTable(auxcounter, counter, bintable);

		printf("%ld", bin);

		for(k = 0; k < (19-size); k++){
	
			printf(" ");

		}
		printf("|%ld\n", dec);

		bintable[counter][0] = bin;
	    	bintable[counter][1] = dec;
		bintable[counter][2] = size;

		dec = 0;
		i = -1;
		j = 0;
		counter++;
		auxcounter = 0;

	}
}
