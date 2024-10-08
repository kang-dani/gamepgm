#include <stdio.h>
#include <locale>

void draw_square(int size);

int main(void) {
	setlocale(LC_ALL, "");
	int n;
	
	printf("Draw SQUARE\n\n");
	printf("Enter the Square Length (MAX 37)\n");
	printf("Enter>");
	scanf("%d", &n);
	
	draw_square(n);
	return 0;
}
void draw_square(int size) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	
	for(i = 0; i < 7; i++)
		b[i] = 0xa0 + i;
		
	// 정사각형의 상단
	printf("%c%c", a, b[3]);
	
	for(i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
		
	printf("%c%c", a, b[4]);
	printf("\n");
	
	
	//정사각형의 중간 부분
	for(i = 0; i < size; i++) 
	{
		printf("%c%c", a, b[2]);
		
		for(j = 0; j < size; j++)
			printf(" ");
			
		printf("%c%c", a, b[2]);
		printf("\n");
	}
	
	//정사각형의 하단
	printf("%c%c", a, b[6]);
	
	for(i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
		
	printf("%c%c", a, b[5]);
	printf("\n");
}