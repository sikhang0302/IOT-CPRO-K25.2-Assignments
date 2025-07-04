#include "../inc/config.h"
#include "../inc/sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void update_sensor_if_needed()
{
    static time_t last_check = 0;
    time_t now = time(NULL);

    if (now - last_check >= g_system_state.config.sensor_check_interval_sec)
    {
        read_sensor_data();
        last_check = now;
    }
}

void read_sensor_data()
{
    // Simulate data read from sensor using rand()
    g_system_state.sensor_data.soil_moisture = rand() % 101; 
    g_system_state.sensor_data.temperature = 20 + rand() % 15;
    printf("\n[SENSOR] Soil moisture: %d%% | Temp: %.1f°C\n\n",
           g_system_state.sensor_data.soil_moisture,
           g_system_state.sensor_data.temperature);
}
