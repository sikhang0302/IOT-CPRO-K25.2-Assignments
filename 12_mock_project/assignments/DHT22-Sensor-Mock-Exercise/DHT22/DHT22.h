#ifndef DHT22_H
#define DHT22_H

#include <stdbool.h>

/*
** Function prototypes
*/ 
bool DHT_Init(const char *filename);
bool DHT_Read_Temperature(float *temp);
bool DHT_Read_Humidity(float *humidity);

#endif
