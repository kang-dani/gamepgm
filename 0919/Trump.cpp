#include <stdio.h>
#include <string.h>

struct trump {
    int order; // 카드의 순서
    char shape[2]; // 카드의 모양 (ASCII 문자로 변경)
    char number; // 카드의 숫자 (문자형으로 변경)
};

void make_card(struct trump m_card[]);
void display_card(struct trump m_card[]);

int main(void) {
    struct trump card[52];
    make_card(card);
    display_card(card);
    return 0;
}

void make_card(struct trump m_card[]) {
    int i, j;
    char shape[4][2] = {"S", "H", "D", "C"}; // ASCII 문자로 변경
    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1; // 숫자 1~13

            // m_card[j].number에 A, J, Q, K를 문자로 저장
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
                default:
                    m_card[j].number += '0'; // 숫자를 문자로 변환
                    break;
            }
        }
    }
}

// 카드 정보를 출력하는 함수
void display_card(struct trump m_card[]) {
    int i;
    for (i = 0; i < 52; i++) {
        printf("%s", m_card[i].shape);
        // number가 10보다 크면 문자로 출력
        if (m_card[i].number >= 'A') {
            printf("%-2c  ", m_card[i].number);
        } else {
            printf("%-2d  ", m_card[i].number - '0'); // 문자로 변환된 숫자 출력
        }

        if (i % 13 == 12) {
            printf("\n");
        }
    }
}
