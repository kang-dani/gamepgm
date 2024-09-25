#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct trump {
    int order; // 카드의 순서
    char shape[2]; // 카드의 모양 (ASCII 문자)
    char number; // 카드의 숫자 (문자형)
};

void make_card(struct trump m_card[]);
void display_card(struct trump m_card[]);
void shuffle_cards(struct trump m_card[]);

int main(void) {
    struct trump card[52];
    make_card(card);
    shuffle_cards(card); // 카드 셔플
    display_card(card);
    return 0;
}

void make_card(struct trump m_card[]) {
	
    int i, j;
    char shape[4][2] = {"S", "H", "D", "C"}; 
    
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
        // number가 A, J, Q, K인지 확인하여 출력
        if (m_card[i].number >= 'A') {
            printf("%-2c  ", m_card[i].number);
        } else {
            printf("%-2c  ", m_card[i].number); // 문자로 변환된 숫자 출력
        }

        if (i % 13 == 12) {
            printf("\n");
        }
    }
}

// 카드 셔플 함수
void shuffle_cards(struct trump m_card[]) {
    srand(time(NULL)); // 랜덤 시드 초기화
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52; // 0부터 51까지의 랜덤 인덱스
        // 카드 교환
        struct trump temp = m_card[i];
        m_card[i] = m_card[j];
        m_card[j] = temp;
    }
}
