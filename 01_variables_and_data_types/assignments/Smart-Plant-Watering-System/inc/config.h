#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

// System status
typedef enum
{
    MODE_AUTO,
    MODE_MANUAL
} SystemMode;

typedef enum
{
    PUMP_OFF,
    PUMP_ON
} PumpState;

typedef enum
{
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LEDState;

// System cofiguration
typedef struct
{
    uint8_t moisture_min_threshold;
    uint8_t moisture_max_threshold;
    uint16_t max_watering_time_sec;
    uint16_t sensor_check_interval_sec;
    SystemMode mode;
} SystemConfig;

// Sensor data
typedef struct
{
    uint8_t soil_moisture;
    float temperature;
} SensorData;

// System global status
typedef struct
{
    SystemConfig config;
    SensorData sensor_data;
    PumpState pump_state;
    LEDState led_state;
} SystemState;

extern SystemState g_system_state;

extern volatile int g_running; // Flag to check if system is running

#endif
