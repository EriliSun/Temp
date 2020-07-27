#ifndef __BSP_CAN_H__
#define __BSP_CAN_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal_can.h"
//#include "stm32f4xx_hal_can_legacy.h"
/* 类型定义 ------------------------------------------------------------------*/
// typedef struct{
// 	CanRxMsgTypeDef m;
// }CANOpen_Message;

typedef struct {
  uint16_t cob_id;	/**< message's ID */
  uint8_t  rtr;		/**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
  uint8_t  len;		/**< message's length (0 to 8) */
  uint8_t  data[8]; /**< message's datas */
} Message;
/* 宏定义 --------------------------------------------------------------------*/
#define CANx                            CAN1
#define CANx_CLK_ENABLE()               __HAL_RCC_CAN1_CLK_ENABLE()
#define CANx_FORCE_RESET()              __HAL_RCC_CAN1_FORCE_RESET()
#define CANx_RELEASE_RESET()            __HAL_RCC_CAN1_RELEASE_RESET()

#define CANx_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()
#define CANx_TX_GPIO_PORT               GPIOB
#define CANx_TX_PIN                     GPIO_PIN_9

#define CANx_RX_GPIO_PORT               GPIOB
#define CANx_RX_PIN                     GPIO_PIN_8

#define CANx_RX_IRQn                   CAN1_RX0_IRQn

/* 扩展变量 ------------------------------------------------------------------*/
extern CAN_HandleTypeDef hCAN;

/* 函数声明 ------------------------------------------------------------------*/
void MX_CAN_Init(void);
uint8_t canSend(Message *m);
void Task_Laser_Init(void);
#endif /* __BSP_CAN_H__ */

/********** (C) COPYRIGHT 2019-2030 硬石嵌入式开发团队 *******END OF FILE******/
