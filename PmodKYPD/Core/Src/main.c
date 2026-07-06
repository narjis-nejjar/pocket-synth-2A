#include "main.h"
#include <stdio.h>
#include <string.h>

/* UART */
UART_HandleTypeDef huart2;

/* KEYBOARD */
char keypad[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'0','F','E','D'}
};

/* ROWS : PA0 PA1 PA6 PA7 */
GPIO_TypeDef* rowPorts[4] = {GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t rowPins[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_6, GPIO_PIN_7};

/* COLS : PB0 PA4 PA5 PB3 */
GPIO_TypeDef* colPorts[4] = {GPIOB, GPIOA, GPIOA, GPIOB};
uint16_t colPins[4] = {GPIO_PIN_0, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_3};

/* PROTOTYPES */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

char Keypad_Scan(void);

/* ---------------- KEYPAD SCAN ---------------- */
char Keypad_Scan(void)
{
    for(int row = 0; row < 4; row++)
    {
        HAL_GPIO_WritePin(GPIOA,
                          GPIO_PIN_0 | GPIO_PIN_1 |
                          GPIO_PIN_6 | GPIO_PIN_7,
                          GPIO_PIN_SET);

        HAL_GPIO_WritePin(rowPorts[row],
                          rowPins[row],
                          GPIO_PIN_RESET);

        HAL_Delay(1);

        for(int col = 0; col < 4; col++)
        {
            if(HAL_GPIO_ReadPin(colPorts[col],
                                colPins[col]) == GPIO_PIN_RESET)
            {
                HAL_Delay(20);

                while(HAL_GPIO_ReadPin(colPorts[col],
                                       colPins[col]) == GPIO_PIN_RESET);

                return keypad[row][col];
            }
        }
    }
    return 0;
}

/* ---------------- MAIN ---------------- */
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();

    char key;
    char msg[30];

    while (1)
    {
        key = Keypad_Scan();

        if(key != 0)
        {
            sprintf(msg, "Touche : %c\r\n", key);
            HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

            /* LED LD2 = PA5 */

            if(key == '1')
            {
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            }
            else if(key == '2')
            {
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            }
            else if(key == '3')
            {
                for(int i = 0; i < 10; i++)
                {
                    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
                    HAL_Delay(300);
                }
            }
        }
    }
}
