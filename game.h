/*
 * game.h
 *
 *  Created on: Jul 5, 2017
 *      Author: i_anu
 */

#ifndef GAME_H_
#define GAME_H_



typedef enum {Start,Roll,StopOne,StopTwo,StopThree} gameState;

gameState CurrentState;

static int PositionOne = 0;
static int PositionTwo = 0;
static int PositionThree = 0;


static int gameStart = 0;


void initState();

void initLCD();

void displaySlotOne(int i);
void displaySlotTwo(int i);
void displaySlotThree(int i);

void roll();

void stopOne();
void stopTwo();
void stopThree();

void game();



#endif /* GAME_H_ */
