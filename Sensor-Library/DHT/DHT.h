/*
 * DHT.h
 *
 *  Created on: Sep 24, 2024
 *      Author: otaku
 */

#ifndef DHT_H_
#define DHT_H_

#include "stm32f1xx_hal.h"

// Thời gian khởi động cho các loại cảm biến
#define DHT11_STARTTIME 18000
#define DHT22_STARTTIME 12000

// Định nghĩa loại cảm biến
#define DHT11_TYPE 0x11
#define DHT22_TYPE 0x02

// Cấu trúc lưu trữ thông tin cảm biến DHT
typedef struct {
    uint16_t Type;                // Loại cảm biến (DHT11 hoặc DHT22)
    TIM_HandleTypeDef* Timer;     // Con trỏ đến timer sử dụng
    uint16_t Pin;                 // Số pin của cảm biến
    GPIO_TypeDef* PORT;           // Cổng GPIO mà cảm biến kết nối
    float Temp;                   // Giá trị nhiệt độ
    float Humi;                   // Giá trị độ ẩm
} DHT_Name;

// Hàm khởi tạo cảm biến DHT
void DHT_Init(DHT_Name* DHT, uint8_t DHT_Type, TIM_HandleTypeDef* Timer, GPIO_TypeDef* DH_PORT, uint16_t DH_Pin);

// Hàm đọc giá trị nhiệt độ và độ ẩm từ cảm biến DHT
uint8_t DHT_ReadTempHum(DHT_Name* DHT);

#endif /* DHT_H_ */
