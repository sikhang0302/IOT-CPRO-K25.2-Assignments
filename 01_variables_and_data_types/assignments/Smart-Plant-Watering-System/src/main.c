#include "../inc/config.h"
#include "../inc/sensors.h"
#include "../inc/actuators.h"
#include "../inc/watering_logic.h"
#include "../inc/utils.h"
#include "../inc/display_server.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

SystemState g_system_state;
volatile int g_running = 1;

// Function to sleep for 1 millisecond
void sleep_in_ms(int ms)
{
    struct timespec req = {
        .tv_sec = 0,
        .tv_nsec = ms * 1000000 // 1 millisecond in nanoseconds
    };
    nanosleep(&req, NULL);
}

int main()
{
    pthread_t server_tid;

    if (pthread_create(&server_tid, NULL, display_server_thread, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Small delay to ensure server thread starts first
    sleep_in_ms(2);

    init_system(); // Init the system

    while (g_running)
    {
        update_sensor_if_needed();

        if (g_system_state.config.mode == MODE_AUTO)
        {
            auto_watering_logic(); 
        }
        update_led_status();
        report_status();

        if (!g_running)
        {
            break;
        }
        else
        {
            sleep(1); // Simulate operating cycle (1 second)
        }
    }

    printf("[MAIN] Exitting the system.\n");

    pthread_join(server_tid, NULL);

    return 0;
}
