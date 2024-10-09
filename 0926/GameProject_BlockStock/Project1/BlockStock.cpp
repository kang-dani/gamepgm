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
    const char* modes[MAX_MODES] = { "쉬운 모드", "보통 모드", "어려운 모드", "나가기" };

    while (1) {
        system("cls");
        printf("블록 쌓기 게임 \n\n");
        printf("모드를 선택하세요:\n\n");

        for (int i = 0; i < MAX_MODES; i++) {
            if (i == selected_mode) {
                set_color(10);  // 텍스트 색 변경
                printf("-> %s\n", modes[i]); // 선택 중인 모드 표시
                set_color(7);   // 기본 색으로 돌아오기
            }
            else {
                printf("   %s\n", modes[i]);
            }
        }

        printf("\n화살표 키로 선택하고 Enter 키로 진행하세요.\n");

        switch (_getch()) {
        case 72: // 위 화살표
            selected_mode = (selected_mode - 1 + MAX_MODES) % MAX_MODES;
            break;
        case 80: // 아래 화살표
            selected_mode = (selected_mode + 1) % MAX_MODES;
            break;
        case 13: // Enter 키
            printf("선택한 모드: %s\n", modes[selected_mode]);
            Sleep(1000); // 잠시 대기
            if (selected_mode == 3) return;   // 나가기 선택했을 때 종료
            game_control(selected_mode); // 선택된 모드로 게임 시작
            return;
        }
    }
}

void game_control(int mode)
{
    int x, count = 0;
    int total_score = 0; // 총 점수

    // 모드에 따른 설정
    switch (mode) {
    case 0: // 쉬운 모드
        move_speed = 200;
        break;
    case 1: // 보통 모드
        move_speed = 100;
        break;
    case 2: // 어려운 모드
        move_speed = 20;
        break;
    }

    system("cls");
    draw_rectangle(box_length, box_height);
    gotoxy(box_length * 2 + 5, 3);
    printf("최대 높이: %2d", box_height);
    gotoxy(1, box_height + 3);
    printf("블록 쌓기 게임을 시작합니다.\n");
    printf("스페이스 바를 누르면 블록이 쌓입니다.\n");

    while (count < box_height)
    {
        gotoxy(box_length * 2 + 5, 4);
        printf("현재 점수: %2d", total_score);
        gotoxy(box_length * 2 + 5, 5);
        printf("현재 쌓인 블록: %2d", max_block());
        x = left_right_move();
        move_down(x);
        count++;

        // 쌓인 블록의 높이에 비례하여 점수 증가
        total_score += block_stack[x]; // 현재 쌓인 블록의 높이만큼 점수 증가
    }
    gotoxy(1, box_height + 3);
    printf("게임이 종료되었습니다.\n");
    Sleep(1000); // 잠시 대기
    outro_game(total_score); // 게임 종료 후 outro 함수 호출
}

void outro_game(int total_score)
{
    int selected_option = 0;
    const char* options[2] = { "다시하기", "나가기" };

    while (1) 
    {
        system("cls");
        printf("게임이 종료되었습니다.\n");
        printf("총 점수: %d\n\n", total_score);
        printf("다음 중 선택하세요:\n\n");

        for (int i = 0; i < 2; i++) 
        {
            if (i == selected_option) 
            {
                set_color(10);  // 텍스트 색 변경
                printf("-> %s\n", options[i]); // 선택 중인 옵션 표시
                set_color(7);   // 기본 색으로 돌아오기
            }
            else {
                printf("   %s\n", options[i]);
            }
        }

        printf("\n화살표 키로 선택하고 Enter 키로 진행하세요.\n");

        switch (_getch()) {
        case 72: // 위 화살표
            selected_option = (selected_option - 1 + 2) % 2;
            break;
        case 80: // 아래 화살표
            selected_option = (selected_option + 1) % 2;
            break;
        case 13: // Enter 키
            if (selected_option == 0) {
                // 다시하기 선택
                for (int i = 0; i < box_length * 2 + 1; i++) 
                {
                    block_stack[i] = 0; // 블록 스택 초기화
                }
                intro_game(); // 게임 다시 시작
            }
            else 
            {
                return; // 나가기 선택
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
        printf("■");
        Sleep(move_speed); // 모드에 따라 설정된 좌우 이동 속도
        gotoxy(x, y);
        printf("  ");

        x += temp;

        // 맵의 경계를 확인하여 이동 제한   
        if (x > (box_length * 2)) // x가 범위를 초과하면
        {
            x = box_length * 2;
            temp = -2;
        }
        if (x < 3)
        {
            x = 3;
            temp = 2;
        }

        // 스페이스바가 눌렸는지 확인
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') // 스페이스바가 눌렸을 때
            {
                if (block_stack[x] < box_height) // 블록이 쌓일 수 있는 경우
                {
                    block_stack[x] += 1; // 블록 쌓기
                }
                space_pressed = true; // 스페이스 바가 눌린 상태로 설정
                break; // 블록 쌓기 후 루프 종료
            }
        }

    } while (!space_pressed); // 스페이스바가 눌릴 때까지 계속 이동

    while (_kbhit()) 
    {
        _getch(); // 입력 버퍼를 비우기
    }

    return x;
}

void move_down(int x)
{
    int y;
    for (y = 2; y < box_height + 2 - block_stack[x]; y += 1)
    {
        gotoxy(x, y);
        printf("■");
        Sleep(50);
        gotoxy(x, y);
        printf("  ");
        Sleep(10);
    }
    gotoxy(x, box_height + 2 - block_stack[x]);
    printf("■");
}

void draw_rectangle(int c, int r)
{
    int i, j;

    // 맵 초기화
    for (i = 0; i < r + 2; i++)
    {
        for (j = 0; j < c * 2 + 3; j++)
        {
            if (i == 0 || i == r + 1 || j == 0 || j == c * 2 + 2)
                map[i][j] = '*'; // 경계
            else
                map[i][j] = ' '; // 내부
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
