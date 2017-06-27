#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define NEWLINE '\n'
#define EASY 10
#define NORMAL 50
#define HARD 100

char platform[20][50];
int pX = 0;
int pY= 1;
int iBombX[20];
int iBombY[50];

int iInitial = 0;
const int _iLevel; // const get user input - level
int _iDirection, _iSteps; // Movement: direction, steps
int iLife = 3; // Player's Lifes

void vGenerateBomb(int level){
//	printf("vGenerateBomb(%d) \n", level);
	if(level == 1){ // Easy
		int i;
		for(i=0; i<EASY; i++){
			iBombX[i] = vRand(1,20);
			iBombY[i] = vRand(1,50);
		}
//		printf("Generated %d bomb! %c", EASY, NEWLINE);
	}else if(level == 2){ // Normal
		int i;
		for(i=0; i<NORMAL; i++){
			iBombX[i] = vRand(1,20);
			iBombY[i] = vRand(1,50);
		}
//		printf("Generated %d bomb! %c", NORMAL, NEWLINE);
	}else if(level == 3){ // Hard
		int i;
		for(i=0; i<HARD; i++){
			iBombX[i] = vRand(1,20);
			iBombY[i] = vRand(1,50);
		}
//		printf("Generated %d bomb! %c", HARD, NEWLINE);
	}
}

void vGetBomb(int level){
	printf("vGetBomb(%d) \n", level);
	if(level == 1){
		int i;
		for(i=0; i<EASY; i++){
			printf("Bomb-E %d: %d %d \n", i, iBombX[i], iBombY[i]);
		}
	}else if(level == 2){
		int i;
		for(i=0; i<NORMAL; i++){
			printf("Bomb-N %d: %d %d \n", i, iBombX[i], iBombY[i]);
		}
	}else if(level == 3){
		int i;
		for(i=0; i<HARD; i++){
			printf("Bomb-H %d: %d %d \n", i, iBombX[i], iBombY[i]);	
		}
	}
}

void vGetPlatform(){
	int i, j;
	for(i=0; i<20; i++){
		for(j=0; j<50; j++){
			if(i == 0 && j == 0){
				printf("%c", 'S');
				continue;
			}
			if(i == 19 && j == 49){
				printf("%c", 'E');
				continue;
			}
			if(i == pX && j == pY){
				printf("%c", 'P');
				continue;
			}
			printf("%c", platform[i][j]);
		}
		printf("%c", NEWLINE);
	}
	printf("%c", NEWLINE);
}

void vBuildPlatform(){
	int i, j;
	for(i=0; i<20; i++){
		for(j=0; j<50; j++){
			platform[i][j] = '*';
		}
	}
}

int vMove(int direction, int steps){
	if(direction == 1){ // Left
		// Boundary check
		int boundary = pY - steps;
		if(boundary < 0){
			vGetPlatform();
			printf("Invalid move, out of boundary! \n");
			return 0;
		}else{
			// Unmask the map
			int i, j;
			for(i = pX; i <= pX; i++){
				for(j = pY; j > pY-steps; j--){
					platform[i][j] = ' ';
				}
			}
			pY -= steps; // Update player position
		}
		return 1;
		
	}else if(direction == 2){ // Right
		// Boundary check
		int boundary = pY + steps;
		if(boundary > 49){
			vGetPlatform();
			printf("Invalid move, out of boundary! \n");
			return 0;
		}else{
			// Unmask the map
			int i, j;
			for(i = pX; i <= pX; i++){
				for(j = pY; j < pY+steps; j++){
					platform[i][j] = ' ';
				}
			}
			pY += steps; // Update player position
		}
		return 1;
		
	}else if(direction == 3){ // Up
		// Boundary check
		int boundary = pX - steps;
		if(boundary < 0){
			vGetPlatform();
			printf("Invalid move, out of boundary! \n");
			return 0;
		}else{
			// Unmask the map
			int i, j;
			for(j=pY; j<=pY; j++){
				for(i=pX; i>pX-steps; i--){
					platform[i][j] = ' ';
				}
			}
			pX -= steps; // Update player position
		}
		return 1;
		
	}else if(direction == 4){ // Down
		// Boundary check
		int boundary = pX + steps;
		if(boundary > 19){
			vGetPlatform();
			printf("Invalid move, out of boundary! \n");
			return 0;
		}else{
			// Unmask the map
			int i, j;
			for(j = pY; j <= pY; j++){
				for(i = pX; i < pX+steps; i++){
					platform[i][j] = ' ';
				}
			}
			pX += steps; // Update player position
		}
		return 1;
		
	}else{
		printf("Invalid move! \n");
		return 0;
	}
}

void vStartGame(int level){
	// Generate Bomb
	if(level != 1 && level != 2 && level != 3){
		printf("Invalid Level Input! %c", NEWLINE);
	}else{
		vGenerateBomb(level);
	}

	// Platform
	if(iInitial == 0){
		vBuildPlatform();
		vGetPlatform();
		iInitial = 1;
	}
	
	// Movement - Direction, Steps
	while(1){
		printf("Enter command (1-left, 2-right, 3-up, 4-down, 9-end): ");
		scanf("%d", &_iDirection);
		
		if(_iDirection == 9){
			exit(0);
		}else if(_iDirection != 1 && _iDirection != 2 && _iDirection != 3 && _iDirection != 4 && _iDirection != 9){
			printf("Invalid movement-direction Input! %c", NEWLINE);
		}else{
			// ok do nothing
		}
		
		printf("Enter steps to move: ");
		scanf("%d", &_iSteps);
		
		if(vMove(_iDirection, _iSteps) == 0){
			// movement invalid
		}else{
			break; // valid movement
		}
	}
	
	vGetPlatform(); // print valid movement platform

	
}

int vRand(int Min,int Max){
	return(rand() % (Max-Min)+Min);
}


int main(int argc, char *argv[]) {
	srand(time(NULL)); // Random seed
//	const int _iLevel; // const get user input - level
//	int _iDirection, _iSteps; // Movement: direction, steps
//	int iLife = 3; // Player's Lifes

	// Get user input - difficulties level
	do{
		printf("Difficulties: 1 - Beginner, 2 - Intermediate, 3 - Advance : "); // 1-10 | 2-50 | 3-100
		scanf("%d", &_iLevel);
		
		if(_iLevel != 1 && _iLevel != 2 && _iLevel != 3){
			printf("Invalid Level Input: %d \n", _iLevel);
		}else{
			break;
		}
	}while(1);
	
	// Start Game
	do{
		vStartGame(_iLevel);
	}while(iLife != 0);
	
	return 0;
} 


