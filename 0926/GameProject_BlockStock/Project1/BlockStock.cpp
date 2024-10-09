#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define box_length 15 
#define box_height 15 
#define MAX_MODES 4

void intro_game(void);
void game_control(int mode);
void outro_game(int total_score);
void gotoxy(int x, int y);
int left_right_move(void);
void move_down(int x);
void draw_rectangle(int c, int r);
int max_block(void);

int block_stack[box_length * 2 + 1] = { 0 };
char map[box_height + 2][box_length * 2 + 3];
int move_speed = 0;

int main(void)
{
    intro_game();
    return 0;
}

void set_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void intro_game(void)
{
    int selected_mode = 0;
    const char* modes[MAX_MODES] = { "���� ���", "���� ���", "����� ���", "������" };

    while (1) {
        system("cls");
        printf("��� �ױ� ���� \n\n");
        printf("��带 �����ϼ���:\n\n");

        for (int i = 0; i < MAX_MODES; i++) {
            if (i == selected_mode) {
                set_color(10);  // �ؽ�Ʈ �� ����
                printf("-> %s\n", modes[i]); // ���� ���� ��� ǥ��
                set_color(7);   // �⺻ ������ ���ƿ���
            }
            else {
                printf("   %s\n", modes[i]);
            }
        }

        printf("\nȭ��ǥ Ű�� �����ϰ� Enter Ű�� �����ϼ���.\n");

        switch (_getch()) {
        case 72: // �� ȭ��ǥ
            selected_mode = (selected_mode - 1 + MAX_MODES) % MAX_MODES;
            break;
        case 80: // �Ʒ� ȭ��ǥ
            selected_mode = (selected_mode + 1) % MAX_MODES;
            break;
        case 13: // Enter Ű
            printf("������ ���: %s\n", modes[selected_mode]);
            Sleep(1000); // ��� ���
            if (selected_mode == 3) return;   // ������ �������� �� ����
            game_control(selected_mode); // ���õ� ���� ���� ����
            return;
        }
    }
}

void game_control(int mode)
{
    int x, count = 0;
    int total_score = 0; // �� ����

    // ��忡 ���� ����
    switch (mode) {
    case 0: // ���� ���
        move_speed = 200;
        break;
    case 1: // ���� ���
        move_speed = 100;
        break;
    case 2: // ����� ���
        move_speed = 20;
        break;
    }

    system("cls");
    draw_rectangle(box_length, box_height);
    gotoxy(box_length * 2 + 5, 3);
    printf("�ִ� ����: %2d", box_height);
    gotoxy(1, box_height + 3);
    printf("��� �ױ� ������ �����մϴ�.\n");
    printf("�����̽� �ٸ� ������ ����� ���Դϴ�.\n");

    while (count < box_height)
    {
        gotoxy(box_length * 2 + 5, 4);
        printf("���� ����: %2d", total_score);
        gotoxy(box_length * 2 + 5, 5);
        printf("���� ���� ���: %2d", max_block());
        x = left_right_move();
        move_down(x);
        count++;

        // ���� ����� ���̿� ����Ͽ� ���� ����
        total_score += block_stack[x]; // ���� ���� ����� ���̸�ŭ ���� ����
    }
    gotoxy(1, box_height + 3);
    printf("������ ����Ǿ����ϴ�.\n");
    Sleep(1000); // ��� ���
    outro_game(total_score); // ���� ���� �� outro �Լ� ȣ��
}

void outro_game(int total_score)
{
    int selected_option = 0;
    const char* options[2] = { "�ٽ��ϱ�", "������" };

    while (1) 
    {
        system("cls");
        printf("������ ����Ǿ����ϴ�.\n");
        printf("�� ����: %d\n\n", total_score);
        printf("���� �� �����ϼ���:\n\n");

        for (int i = 0; i < 2; i++) 
        {
            if (i == selected_option) 
            {
                set_color(10);  // �ؽ�Ʈ �� ����
                printf("-> %s\n", options[i]); // ���� ���� �ɼ� ǥ��
                set_color(7);   // �⺻ ������ ���ƿ���
            }
            else {
                printf("   %s\n", options[i]);
            }
        }

        printf("\nȭ��ǥ Ű�� �����ϰ� Enter Ű�� �����ϼ���.\n");

        switch (_getch()) {
        case 72: // �� ȭ��ǥ
            selected_option = (selected_option - 1 + 2) % 2;
            break;
        case 80: // �Ʒ� ȭ��ǥ
            selected_option = (selected_option + 1) % 2;
            break;
        case 13: // Enter Ű
            if (selected_option == 0) {
                // �ٽ��ϱ� ����
                for (int i = 0; i < box_length * 2 + 1; i++) 
                {
                    block_stack[i] = 0; // ��� ���� �ʱ�ȭ
                }
                intro_game(); // ���� �ٽ� ����
            }
            else 
            {
                return; // ������ ����
            }
            break;
        }
    }
}

void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int left_right_move(void)
{
    int x = 3, y = 2, temp = 2;
    bool space_pressed = false;

    do
    {
        gotoxy(x, y);
        printf("��");
        Sleep(move_speed); // ��忡 ���� ������ �¿� �̵� �ӵ�
        gotoxy(x, y);
        printf("  ");

        x += temp;

        // ���� ��踦 Ȯ���Ͽ� �̵� ����   
        if (x > (box_length * 2)) // x�� ������ �ʰ��ϸ�
        {
            x = box_length * 2;
            temp = -2;
        }
        if (x < 3)
        {
            x = 3;
            temp = 2;
        }

        // �����̽��ٰ� ���ȴ��� Ȯ��
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') // �����̽��ٰ� ������ ��
            {
                if (block_stack[x] < box_height) // ����� ���� �� �ִ� ���
                {
                    block_stack[x] += 1; // ��� �ױ�
                }
                space_pressed = true; // �����̽� �ٰ� ���� ���·� ����
                break; // ��� �ױ� �� ���� ����
            }
        }

    } while (!space_pressed); // �����̽��ٰ� ���� ������ ��� �̵�

    while (_kbhit()) 
    {
        _getch(); // �Է� ���۸� ����
    }

    return x;
}

void move_down(int x)
{
    int y;
    for (y = 2; y < box_height + 2 - block_stack[x]; y += 1)
    {
        gotoxy(x, y);
        printf("��");
        Sleep(50);
        gotoxy(x, y);
        printf("  ");
        Sleep(10);
    }
    gotoxy(x, box_height + 2 - block_stack[x]);
    printf("��");
}

void draw_rectangle(int c, int r)
{
    int i, j;

    // �� �ʱ�ȭ
    for (i = 0; i < r + 2; i++)
    {
        for (j = 0; j < c * 2 + 3; j++)
        {
            if (i == 0 || i == r + 1 || j == 0 || j == c * 2 + 2)
                map[i][j] = '*'; // ���
            else
                map[i][j] = ' '; // ����
        }
    }
    for (i = 0; i < r + 2; i++)
    {
        for (j = 0; j < c * 2 + 3; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int max_block(void)
{
    int i, max = 0;
    for (i = 1; i < box_height * 2 + 1; i++)
    {
        if (max <= block_stack[i])
            max = block_stack[i];
    }
    return max;
}
