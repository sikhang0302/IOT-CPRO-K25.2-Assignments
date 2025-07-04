#include "../inc/display_server.h"
#include "../inc/config.h"
#include "../inc/actuators.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>      // For perror()
#include <sys/socket.h> // For socket(), bind(), listen(), accept()
#include <sys/un.h>     // For UNIX domain sockets
#include <unistd.h>     // For close(), write()

#define SOCK_PATH "/tmp/sock_stream" // Socket file path

void *display_server_thread(void *arg)
{
    int server_sock;
    int client_sock;
    struct sockaddr_un server_addr;
    char read_buff[100] = {0};
    int watering_second = 5;
    int bytes_read;

    unlink(SOCK_PATH);

    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("socket");
        pthread_exit(NULL);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_un));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCK_PATH, sizeof(server_addr.sun_path) - 1);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        close(server_sock);
        pthread_exit(NULL);
    }

    if (listen(server_sock, 1) == -1)
    {
        perror("listen");
        close(server_sock);
        pthread_exit(NULL);
    }

    while (1)
    {
        client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1)
        {
            perror("accept");
            continue;
        }

        bytes_read = read(client_sock, read_buff, sizeof(read_buff));
        if (bytes_read > 0)
        {
            read_buff[bytes_read] = '\0';
        }
        printf("[DISP] Received command: %s\n", read_buff);

        if (strcmp(read_buff, "AUTO_MODE") == 0)
        {
            g_system_state.config.mode = MODE_AUTO;
        }
        else if (strcmp(read_buff, "MANUAL_MODE") == 0)
        {
            g_system_state.config.mode = MODE_MANUAL;
            turn_pump_off();
        }
        else if (strcmp(read_buff, "MANUAL_WATER") == 0)
        {
            if (g_system_state.config.mode == MODE_MANUAL)
            {
                printf("[CMD] Manual watering for %d seconds.\n", watering_second);
                turn_pump_on();
                sleep(watering_second);
                turn_pump_off();
            }
            else
            {
                printf("[CMD] Cannot use this command on Auto Mode.\n");
            }
        }
        else if (strcmp(read_buff, "QUIT") == 0)
        {
            printf("[SERVER] Received Quit command.\n");
            g_running = 0; // Send quit signal to main() via flag
            break;         // Quit the loop
        }
        else
        {
            // Currently do nothing
        }

        close(client_sock);
    }

    close(server_sock);
    unlink(SOCK_PATH);

    return NULL;
}