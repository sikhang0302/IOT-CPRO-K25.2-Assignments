#include "../inc/config.h"
#include "../inc/sensors.h"
#include "../inc/actuators.h"
#include "../inc/watering_logic.h"
#include <stdio.h>
#include <time.h>

static time_t pump_start_time = 0;

void auto_watering_logic()
{
    time_t now = time(NULL);

    if (g_system_state.sensor_data.soil_moisture < g_system_state.config.moisture_min_threshold)
    {
        turn_pump_on();
        pump_start_time = now;
    }

    if (g_system_state.pump_state == PUMP_ON)
    {
        if (g_system_state.sensor_data.soil_moisture >= g_system_state.config.moisture_max_threshold ||
            (now - pump_start_time) >= g_system_state.config.max_watering_time_sec)
        {
            turn_pump_off();
        }
    }
}
