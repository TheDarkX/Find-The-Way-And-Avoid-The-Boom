#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int row = 20;
	int col = 50;
	
	char platform[row][col];
	
	
	
	
	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			platform[i][j] = '*';
		}
	}
	
	platform[0][0] = 'S';
	platform[19][49] = 'E';
	
	//print
//	char a[10][50] = { '*', 'b' };
//	printf("check %c", platform[0][1]);
	
	int a,b;
	for(a=0; a<row; a++){
		for(b=0; b<col; b++){
			printf("%c", platform[a][b]);
		}
		printf("\n");
	}
	
	return 0;
}
