#include "../inc/config.h"
#include "../inc/actuators.h"
#include <stdio.h>

void turn_pump_on()
{
    if (g_system_state.pump_state == PUMP_OFF)
    {
        g_system_state.pump_state = PUMP_ON;
        printf("\n[ACTUATOR] Pump ON\n\n");
    }
}

void turn_pump_off()
{
    if (g_system_state.pump_state == PUMP_ON)
    {
        g_system_state.pump_state = PUMP_OFF;
        printf("\n[ACTUATOR] Pump OFF\n\n");
    }
}

void update_led_status()
{
    if (g_system_state.pump_state == PUMP_ON)
    {
        g_system_state.led_state = LED_WATERING;
    }
    else if (g_system_state.sensor_data.soil_moisture < g_system_state.config.moisture_min_threshold)
    {
        g_system_state.led_state = LED_LOW_MOISTURE_ALERT;
    }
    else
    {
        g_system_state.led_state = LED_NORMAL;
    }

    // Print LED status
    const char *led_color = "";
    switch (g_system_state.led_state)
    {
    case LED_NORMAL:
        led_color = "Green";
        break;
    case LED_WATERING:
        led_color = "Yellow";
        break;
    case LED_LOW_MOISTURE_ALERT:
        led_color = "Orange";
        break;
    case LED_ERROR:
        led_color = "Red";
        break;
    }
    printf("[LED] Status LED: %s\n", led_color);
}
