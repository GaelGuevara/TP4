#include "M_Pap.h"
#include "MKL25Z4.h"
#include <stdio.h>

#define IN1 1
#define IN2 2
#define IN3 3
#define IN4 4

int pines[4] = {IN1,IN2,IN3,IN4};
bool estadosC[4][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
};

bool estadosN[4][4] = {
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1}
};

bool estadosM[8][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,1},
    {0,0,0,1},
    {1,0,0,1}
};

void pasoC(int Pasos){
    while (Pasos){
        for (int i = 0; i < Pasos; i++){
            for (int j = 0; j < 4; j++){
                PTA -> PSOR|=(estadosC[j][i % 4]<<pines[j]);
            }
        }
        Pasos--;
    }
}

void pasoN(int Pasos){
    while (Pasos){
        for (int i = 0; i < Pasos; i++){
            for (int j = 0; j < 4; j++){
                PTA -> PSOR|=(estadosN[j][i % 4]<<pines[j]);
            }
        }
        Pasos--;
    }
}

void pasoM(int Pasos){
    while (Pasos){
        for (int i = 0; i < Pasos; i++){
            for (int j = 0; j < 4; j++){
                PTA -> PSOR|=(estadosM[j][i % 8]<<pines[j]);
            }
        }
        Pasos--;
    }
}