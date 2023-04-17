#ifdef _WIN32
	#include <windows.h>
	#define OS "cls"
#endif
#ifdef __linux__
	#include <unistd.h>
	#define OS "clear"
#endif
#include <stdio.h>
#include <stdlib.h>


void progressBar(int progress, int max){

	int counter = progress;
	int counter2 = max - progress;
	
	system(OS);
	
	printf("\n\n");
	while(counter != 0 ){
		printf("█");
		counter--;
	
	}
	while(counter2 != 0){
		
		printf("░");
		counter2--;

	}

	printf("\n\n");

}

void main(){
	
	int max = 10;

	for(int i = 0; i < max+1; i++){
		progressBar(i, max);
		sleep(i/2+(i%2));
	}

	system(OS);
	printf("\n\n     ඞ     \n");
	printf("   amogus\n\n\n");

}
