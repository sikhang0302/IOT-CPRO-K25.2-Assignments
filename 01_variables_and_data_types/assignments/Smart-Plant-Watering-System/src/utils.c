#include "../inc/config.h"
#include "../inc/utils.h"
#include <stdio.h>

void report_status()
{
    printf("[STATUS] Mode: %s | Moisture: %d%% | Pump: %s\n",
           g_system_state.config.mode == MODE_AUTO ? "AUTO" : "MANUAL",
           g_system_state.sensor_data.soil_moisture,
           g_system_state.pump_state == PUMP_ON ? "ON" : "OFF");
}

void init_system()
{
    g_system_state.config.moisture_min_threshold = 40;
    g_system_state.config.moisture_max_threshold = 70;
    g_system_state.config.max_watering_time_sec = 30;
    g_system_state.config.sensor_check_interval_sec = 10;
    g_system_state.config.mode = MODE_AUTO;

    g_system_state.pump_state = PUMP_OFF;
    g_system_state.led_state = LED_NORMAL;

    printf("[INIT] System initialized in AUTO mode.\n");
}
