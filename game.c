/*
 * game.c
 *
 *  Created on: Jul 5, 2017
 *      Author: i_anu
 */

#include <stdint.h>
#include "ST7735.h"
#include "game.h"
#include "graphics.h"
#include "supportFunctions.h"

const  unsigned short slotOne [] =  { bar,bell,brinjal,pear,seven,watermelon,orange,cheery,grapes};

const  unsigned short slotTwo [] =  { bar,bell,brinjal,pear,seven,watermelon,orange,cheery,grapes};

const unsigned short slotThree [] = { bar,bell,brinjal,pear,seven,watermelon,orange,cheery,grapes};


void initLCD()
{
    ST7735_InitR(INITR_REDTAB);
}

void initState()
{
    ST7735_FillScreen(ST7735_YELLOW);

    ST7735_DrawBitmap(2, 160, bgnd, 120, 160);

    displaySlotThree(0);
    displaySlotTwo(0);
    displaySlotOne(0);

    ST7735_DrawBitmap(33, 143, start, 70, 15);
}


void displaySlotOne(int i)
{
    ST7735_DrawBitmap(slotXValues[0], slotYValues[0] , slotOne[(i+2)%8],         slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[0], slotYValues[1],  slotOne[(i+1)%8],         slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[0], slotYValues[2],  slotOne[i],           slot_pic_width, slot_pic_height);

}

void displaySlotTwo(int i)
{
    ST7735_DrawBitmap(slotXValues[1], slotYValues[0],  slotTwo[(i+2)%8],        slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[1], slotYValues[1],  slotTwo[(i+1)%8],        slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[1], slotYValues[2],  slotTwo[i],          slot_pic_width, slot_pic_height);



}

void displaySlotThree(int i)
{
    ST7735_DrawBitmap(slotXValues[2], slotYValues[0],  slotThree[(i+2)%8],      slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[2], slotYValues[1],  slotThree[(i+1)%8],      slot_pic_width, slot_pic_height);
    ST7735_DrawBitmap(slotXValues[2], slotYValues[2],  slotThree[i],        slot_pic_width, slot_pic_height);

}

void roll()
{

    displaySlotOne(PositionOne);
    displaySlotTwo(PositionTwo);
    displaySlotThree(PositionThree);

    PositionOne++;
    PositionTwo++;
    PositionThree++;
    if(PositionOne == 9)
        PositionOne = 0;
    if(PositionTwo == 9)
        PositionTwo = 0;
    if(PositionThree == 9)
        PositionThree = 0;

    delayNms(50);

}



//void stopOne()
//{
//    int k = 0;
//
//
//    displaySlotOne(PositionOne);
//    displaySlotTwo(PositionTwo);
//    displaySlotThree(PositionThree);
//
//    PositionTwo++;
//    PositionThree++;
//
//    if (OneRoller <= 50)
//    {
//        if (k == OneRoller)
//        {
//                PositionOne++;
//                k = 0;
//                OneRoller++;
//        }
//        else
//            k++;
//    }
//
//
//    if(PositionOne >= 9)
//        PositionOne = 0;
//    if(PositionTwo == 9)
//        PositionTwo = 0;
//    if(PositionThree == 9)
//        PositionThree = 0;
//
//    delayNms(50);
//
//
//
//}


void stopOne()
{
    displaySlotOne(PositionOne);
    displaySlotTwo(PositionTwo);
    displaySlotThree(PositionThree);

    //PositionOne++;
    PositionTwo++;
    PositionThree++;
    //if(PositionOne == 9)
    //    PositionOne = 0;
    if(PositionTwo == 9)
        PositionTwo = 0;
    if(PositionThree == 9)
        PositionThree = 0;

    delayNms(50);

}

void stopTwo()
{
    displaySlotOne(PositionOne);
    displaySlotTwo(PositionTwo);
    displaySlotThree(PositionThree);

    //PositionOne++;
    //PositionTwo++;
    PositionThree++;
    //if(PositionOne == 9)
    //    PositionOne = 0;
    //if(PositionTwo == 9)
    //    PositionTwo = 0;
    if(PositionThree == 9)
        PositionThree = 0;

    delayNms(50);

}

void stopThree()
{
    displaySlotOne(PositionOne);
    displaySlotTwo(PositionTwo);
    displaySlotThree(PositionThree);
}


void game()
{
    switch(CurrentState){
    case Start:
        if (!gameStart)
        {
            initState();
            gameStart = 1;
        }
        break;

    case Roll:
        roll();
        break;
    case StopOne:
        stopOne();
        break;

    case StopTwo:
        stopTwo();
        break;
    case StopThree:
        stopThree();
        checkWin();
        break;
    default:
        break;
    }
}

void checkWin()
{
    if (PositionOne == PositionTwo)
        if(PositionOne == PositionThree)
            ST7735_DrawBitmap(33, 143, win, 70, 15);
        else
            ST7735_DrawBitmap(33, 143, lose, 70, 15);
    else
        ST7735_DrawBitmap(33, 143, lose, 70, 15);

    gameStart = 0;

}



