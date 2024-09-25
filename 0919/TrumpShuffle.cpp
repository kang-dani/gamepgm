#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct trump {
    int order; // 카드의 종류
    char shape[3]; // 카드의 모양
    int number; // 카드의 숫자
};

void make_card(struct trump m_card[]);
void display_card(struct trump m_card[]);
void shuffle_card(struct trump m_card[]);

int main(void) {
    struct trump card[52];
    make_card(card);
    shuffle_card(card);
    display_card(card);
    return 0;
}

void make_card(struct trump m_card[]) {
    int i, j;
    char shape[4][3] = {"♥", "♦", "♣", "♠"}; // 카드 모양을 ASCII 문자로 변경
    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;
            switch (m_card[j].number) {
                case 1:
                    m_card[j].number = 'A'; 
                    break;
                case 11:
                    m_card[j].number = 'J'; 
                    break;
                case 12:
                    m_card[j].number = 'Q'; 
                    break;
                case 13:
                    m_card[j].number = 'K'; 
                    break;
            }
        }
    }
}

void display_card(struct trump m_card[]) {
    int i, count = 0;
    for (i = 0; i < 52; i++) {
        printf("%s", m_card[i].shape);
        // 숫자가 10보다 크면 문자로 출력
        if (m_card[i].number == 'A' || m_card[i].number == 'J' || m_card[i].number == 'Q' || m_card[i].number == 'K') {
            printf("%-2c  ", m_card[i].number);
        } else {
            printf("%-2d  ", m_card[i].number);
        }
        count++;
        if (i % 13 + 1 == 13) {
            printf("\n");
            count = 0;
        }
    }
}

void shuffle_card(struct trump m_card[]) {
    int i, rnd;
    struct trump temp;
    srand(time(NULL)); // 랜덤 시드 설정
    for (i = 0; i < 52; i++) {
        rnd = rand() % 52;
        temp = m_card[rnd];
        m_card[rnd] = m_card[i];
        m_card[i] = temp;
    }
}
