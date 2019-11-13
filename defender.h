#ifndef DEFENDER_H_
#define DEFENDER_H_
#include "system.h"
#include "screen.h"
#include "keypad.h"


//variables globales claves
uint8_t win=0;
uint8_t vidas=3;

//posicion inicial jugador
uint8_t player_posv=15;
uint8_t player_posh=15;
//posicion disparo jugador -->solo uno a la vez
uint8_t disparo_posh=0;
uint8_t disparo_posv=0;
uint8_t isdisparo=0;
//posicion inicial nave avanzada:se mueve en zigzag
int enemigo2[5]={1,1,1,1,1};
uint8_t enemy2_posv[5]={25,25,25,25,25};
uint8_t enemy2_posh[5]={79,79,79,79,79};
uint8_t sub=0;
uint8_t loopenemigo2=0;
//posicion inicial nave basica: se mueve en una sola direccion
int enemigo1[5]={1,1,1,1,1};
uint8_t enemigo1_posv[5]={2,3,4,5,6};
uint8_t enemigo1_posh[5]={78,78,78,78,78};
uint8_t loopenemigo1=0;
//variables globales: Posicion de disparos de aliens
uint8_t disparoenemigo1_posh=0;
uint8_t disparoenemigo1_posv=0;
uint8_t disparoenemigo2_posh=0;
uint8_t disparoenemigo2_posv=0;
uint8_t isalien1disparo=0;
uint8_t isalien2disparo=0;


void resetgame();
void moveplayer(uint8_t key);
void playershoot();
void alienshoot();
void enemy1();
void enemy2();
void draw();
bool islive(int n);
void colision();
void colisionnaves();
void colisionDisparoAlien();
void * myitoa(uint32_t n);

#endif