#include "../Test/Test_Service.h"
#include "../DHT22/DHT22.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILE_NAME_MAX_LENGTH            256

int main(void) {
    float temp;
    float humidity;
    float read_temp;
    float read_humidity;
    int choice;
    char file_name[FILE_NAME_MAX_LENGTH];

    while(1) {
        printf("===== DHT22 SENSOR SIMULATION =====\n");
        printf("1 - Reading Data\n");
        printf("0 - Quit\n");
        printf(">> Select: ");

        scanf("%d", &choice);
        fgetc(stdin);

        if (choice == 1) {
            printf("Create data for testing:\n");
            printf("Enter data file name: ");
            fgets(file_name, sizeof(file_name), stdin);
            int len = strlen(file_name);
            if (len > 0 && file_name[len - 1] == '\n') {
                file_name[len - 1] = '\0';
            }

            while(1) {
                printf("Enter temperature (Range from -40 to 80Celsius): ");
                scanf("%f", &temp);
                fgetc(stdin);
                if (temp < -40.0f || temp > 80.0f) {
                    printf("Temperature is out of range! Please try again.\n");
                } else {
                    break;
                }
            }

            while (1) {
                printf("Enter humidity (Rage from 0 to 100%%RH): ");
                scanf("%f", &humidity);
                fgetc(stdin);
                if (humidity < 0.0f || humidity > 100.0f) {
                    printf("Humidity is out of range! Please try again.\n");
                } else {
                    break;
                }
            }

            printf("\nStart generating data file...\n");
			Create_Data_Test(file_name, temp, humidity);
			if (g_last_error == 1) {
				printf("Failed to create data file! Please try again.\n");	
				g_last_error = 0;
				continue;
			} else {
				printf("Successfully created data file!\n");
			}

            if (DHT_Init(file_name) == true) {
                printf("Start reading from file...\n\n");
            } else {
                printf("Failed to read from data file!\n");
                return 1;
            }

            if (DHT_Read_Temperature(&read_temp) == false) {
                printf("Failed to read temperature!\n");
            }

            if (DHT_Read_Humidity(&read_humidity) == false) {
                printf("Failed to read humidity!\n");
            }

            printf("Original Temperature: %0.1f\n", temp);
            printf("Original Humidity: %0.1f\n", humidity);
            printf("Temperature Read from Test File: %0.1f\n", read_temp);
            printf("Humidity Read from Test File: %0.1f\n\n", read_humidity);
        } else if (choice == 0) {
            printf("Exiting the program...\n\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
    
    return 0;
}