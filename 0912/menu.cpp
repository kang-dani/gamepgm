#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
void hamburger(void);
void spaghetti(void);
void press_any_key(void);

int main(void) {
	int c;
	while((c=menu_display()) != 3) {
		switch(c) {
			case 1 :
				hamburger();
				break;
			case 2 :
				spaghetti();
				break;
			default :
				break;
		}
	}
	return 0;
}

int menu_display(void) 
{
	int select;
	system("cls");
	
	printf("make  a snack!\n\n");
	printf("1. Hamburger\n");
	printf("2. spaghetti\n");
	printf("3. exit\n\n");
	printf("Enter the menu number>");
	select=getch()-48;
	
	return select;
}

void hamburger(void) 
{
	system("cls");
	printf("how to make a hamburger\n");
	printf("...\n");
	press_any_key();
}

void spaghetti(void) 
{
	system("cls");
	printf("how to make a spaghetti\n");
	printf("...\n");
	press_any_key();
}

void press_any_key(void) 
{
	printf("\n\n");
	printf("if you want to go main, Press any key...");
	getch();
}
