#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	char ch;
	printf("character  Enter> ");
	scanf("%c", &ch);
	system("cls");
	printf("Entered Character : %c\n", ch);
	
	return 0;
}