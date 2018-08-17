//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "driverlib.h"
//#include "ST7735.h"
//#include "graphics.h"
#include "game.h"
#include "supportFunctions.h"

int game_start = 0;
int button5_7_pressed = 0;
int button3_7_pressed = 0;


void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    clockInit48MHzXTL();

    P6->DIR |= BIT6;
    P6->OUT |= BIT6;

    P4->DIR |= BIT5;

    initLCD();


    /* Configuring SysTick to trigger at 48000 (MCLK is 48 MHz so this will trigger every 1 ms) */
        MAP_SysTick_enableModule();
        MAP_SysTick_setPeriod(48 * 1000 * 1);
        MAP_SysTick_enableInterrupt();  // use a simple interrupt service routine to keep track of time intervals

    // BTN1 p5.7 BTN2 p3.7

     MAP_GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN7);
     MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);
     MAP_GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN7);
     MAP_Interrupt_enableInterrupt(INT_PORT5);


     MAP_GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN7);
     MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN7);
     MAP_GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN7);
     MAP_Interrupt_enableInterrupt(INT_PORT3);


     //ST7735_SetRotation(3);

     initState();
     CurrentState = Start;




     /* Enabling MASTER interrupts */
      MAP_Interrupt_enableMaster();


    while(1)
    {
//        if(button5_7_pressed)
//        {
//
//          delayNms(100);      // Software delay for debouncing button
//          button5_7_pressed = 0;                                     // Reset flag
//          P5IFG &= ~BIT7;                                      // Clear pending interrupt flag for S1 (P5.7)
//          P5IE |= BIT7;
//
//          if (CurrentState == Start)
//              CurrentState = Roll;
//          if (CurrentState == StopThree)
//              CurrentState = Start;
//
//
//
//        }
//
//        if(button3_7_pressed)
//        {
//            delayNms(100);      // Software delay for debouncing button
//            button5_7_pressed = 0;                                     // Reset flag
//            P3IFG &= ~BIT7;                                      // Clear pending interrupt flag for S2 (P3.7)
//            P3IE |= BIT7;
//
//            if (CurrentState == StopTwo)
//                CurrentState = StopThree;
//            if (CurrentState == StopOne)
//                CurrentState = StopTwo;
//            if (CurrentState == Roll)
//                CurrentState = StopOne;
//
//
//        }
        game();
    }


}


void PORT5_IRQHandler(void)
{
    uint32_t status;
    status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, status);
        if (status & GPIO_PIN7){
            if (CurrentState == Start)
                CurrentState = Roll;
            if (CurrentState == StopThree)
            {
                CurrentState = Start;
            }
        }
//      P5IE &= ~BIT7;                                           // Disable interrupt for S1 (5.7) for debouncing
//      button5_7_pressed = 1;
}

void PORT3_IRQHandler(void)
{
//    P3IE &= ~BIT7;                                           // Disable interrupt for S2 (3.7) for debouncing
//    button3_7_pressed = 1;
    uint32_t status;
    status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, status);
        if (status & GPIO_PIN7){
            if (CurrentState == StopTwo)
                CurrentState = StopThree;
            if (CurrentState == StopOne)
                CurrentState = StopTwo;
            if (CurrentState == Roll)
                CurrentState = StopOne;
        }


}

