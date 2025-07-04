#include "../inc/panel_client.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SOCK_PATH "/tmp/sock_stream" // Socket file path

void send_command(const char *cmd)
{
    int server_sock;
    struct sockaddr_un server_addr; // Server address structure

    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_un));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCK_PATH, sizeof(server_addr.sun_path) - 1);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        close(server_sock);
        return;
    }

    write(server_sock, cmd, strlen(cmd) + 1);
    close(server_sock);
}

int main()
{
    int cmd;

    while (1)
    {
        printf("\n===== USER PANEL =====\n");
        printf("1 - Auto Mode\n");
        printf("2 - Manual Mode\n");
        printf("3 - Manual Watering (Only in Manual Mode)\n");
        printf("0 - Quit\n");
        printf(">> Select: ");

        scanf("%d", &cmd);

        if (cmd == 1)
        {
            send_command("AUTO_MODE");
        }
        else if (cmd == 2)
        {
            send_command("MANUAL_MODE");
        }
        else if (cmd == 3)
        {
            send_command("MANUAL_WATER");
        }
        else if (cmd == 0)
        {
            send_command("QUIT");
            break;
        }
        else
        {
            printf("Invalid command! Please try again.\n");
        }

        sleep(1);
    }

    return 0;
}