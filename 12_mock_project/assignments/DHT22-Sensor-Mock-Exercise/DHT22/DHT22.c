#include "DHT22.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_OF_BITS                     		(0x08)
#define DATA_BITS                       			(40)
#define NUM_OF_DATA                     		(DATA_BITS / NUM_OF_BITS)
#define HIGH                            				(0x01)
#define LOW                             				(0x00)
#define HIGHEST_HIGH_BIT               	(0x07)
#define MASK_HIGHEST_BIT             		(0x80)
#define MASK_HIGHEST_BIT_LOW    	(0x7F)

// Array to store temperature,humidity, and checksum data bytes
int data[NUM_OF_DATA] = { 0 };

/** 
 * @brief Verifies checksum from data file versus calculated checksum from received temperature and humidity values
 * 
 * @param sensor_checksum	Checksum from data file
 * @param checksum 				Calculated checksum from temperature and humidity values
 *
 * @return True if the checksums match, false otherwise
 */
static bool Data_Verify(int sensor_checksum, int checksum) {
    return (sensor_checksum == checksum);
}

/** 
 * @brief Converts binary string to decimal integer
 *
 * @param out_num		Pointer to store converted decimal value
 * @param in_str			String containing binary digits ('0' or '1') to be converted
 * @param num_bits		Number of bits to process from binary string
 *
 * @return None
 */
static void Binary_String_To_Decimal(int *out_num, const char * in_str, const int num_bits) {
    int i;
    int base = 0; // 2^0
    *out_num = 0;
    for (i = num_bits - 1; i >= 0; i--) {
        int digit = in_str[i] - '0'; // converts digit character to its numeric value
        *out_num += digit * pow(2, base);
        base++;
    }

    return;
}

/** 
 * @brief Calculates checksum from temperature and humidity data bytes
 *
 * @param temp_high			High byte of temperature value
 * @param temp_low			Low byte of temperature value
 * @param humidity_high		High byte of humidity value
 * @param humidity_low		Low byte of humidity value
 *
 * @return Calculated checksum (last 8 bits of sum)
 */
static int Calculate_Checksum(int temp_high, int temp_low, int humidity_high, int humidity_low) {
    // AND 0xFF to get the last 8 bits of Sum
    return (temp_high + temp_low + humidity_high + humidity_low) & 0xFF;
}

/** 
 * @brief Simulates the initialization of a GPIO pin and prepares the data file for reading
 *
 * @param filename	Name (including path) of the data file to be read 
 *
 * @return True if the file is successfully opened for reading, false otherwise
 */
bool DHT_Init(const char *filename) {
    FILE *fp;

	// Array to store data from data file
    char data_to_read[DATA_BITS + 1];

	// Open file in read-only mode
    fp = fopen(filename, "r");

    if (fp == NULL) { // Fail to open data file
        return false;
    }

	// Simulates the communication process between MCU and DHT22 sensor
    printf("Host sends start signal\n");
    printf("Host pulls up and wait for sensor's response\n");
    printf("Sensor sends out response\n");
    printf("Sensor pulls up get ready to output signal\n");
    printf("Start data transmission...\n");

	// Read each character in data file and store in the array
    int i = 0;
    int c;
    while((c = fgetc(fp)) != EOF) {
        if (c == '\n') continue; // Ignore new line character
        data_to_read[i] = (char)c;
        i++;
    }

    // Close data file after finishing reading
    fclose(fp);

	// Array to store each binary string of temperature and humidity data bytes read from data file
    char temps[NUM_OF_DATA][NUM_OF_BITS + 1];
    for (i = 0; i < NUM_OF_DATA; i++) {
		// Copy each binary string (8 bits per each) and store in the array 
        strncpy(temps[i], data_to_read + i * NUM_OF_BITS, NUM_OF_BITS);
        // Add null terminator character
		temps[i][NUM_OF_BITS] = '\0';
        // Convert each binary string to its decimal integer 
		Binary_String_To_Decimal(&data[i], temps[i], NUM_OF_BITS);
    }
    
    return true;
}

/** 
 * @brief Reads temperature data
 * @param temp Pointer to a float variable that stores read temperature value
 * @return Returns true on successful read and data validation, false otherwise
 */
bool DHT_Read_Temperature(float *temp) {
    float tmp_temp = NAN;
	
    int temp_high = data[0];
    int temp_low = data[1];
    int humidity_high = data[2];
    int humidity_low = data[3];
    int sensor_checksum = data[4];
    int checksum = Calculate_Checksum(temp_high, temp_low, humidity_high, humidity_low);
    int temp_total;

    printf("SENSOR CHECKSUM: %d\n", sensor_checksum);
    printf("CHECKSUM: %d\n\n", checksum);

    // Check negative temperature (If highest bit of temperature is 1, then temperature is below 0 degree Celsius)
    if (((temp_high & MASK_HIGHEST_BIT) >> HIGHEST_HIGH_BIT) == HIGH) {
        temp_high &= MASK_HIGHEST_BIT_LOW;
        temp_total = -(temp_high << NUM_OF_BITS | temp_low);
    } else {
        temp_total = temp_high << NUM_OF_BITS | temp_low;
    }

    tmp_temp = temp_total / 10.0f;

    if (isnan(tmp_temp) || !(Data_Verify(sensor_checksum, checksum))) {
        return false;
    } else {
        *temp = tmp_temp;
        return true;
    }
}

/** 
 * @brief Reads humidity data
 * @param humidity Pointer to a float variable that stores read humidity value
 * @return True on successful read and data validation, false otherwise
 */
bool DHT_Read_Humidity(float *humidity) {
    float tmp_humidity = NAN;
	
    int temp_high = data[0];
    int temp_low = data[1];
    int humidity_high = data[2];
    int humidity_low = data[3];
    int sensor_checksum = data[4];
    int checksum = Calculate_Checksum(temp_high, temp_low, humidity_high, humidity_low);
    int humidity_total = humidity_high << 8 | humidity_low;

    tmp_humidity = humidity_total / 10.0f;

    if (isnan(tmp_humidity) || !(Data_Verify(sensor_checksum, checksum))) {
        return false;
    } else {
        *humidity = tmp_humidity;
        return true;
    }
}
