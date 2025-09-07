#include "Test_Service.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_HIGH_BITS                     		(0x08)
#define HIGHEST_HIGH_BIT                		(0x07)
#define NUM_OF_BITS                     			(0x08)
#define DATA_BITS                       				(40)
#define NUM_OF_DATA                     			(DATA_BITS / NUM_OF_BITS)

// Variable to store error status
int g_last_error = 0;

/** 
 * @brief Rounds a floating-point number to a given number of decimal places
 *
 * @param number						Number to be rounded
 * @param decimal_places			Number of decimal places to round to
 *
 * @return Rounded number
 */
static double Round_To_Decimal_Places(double number, int decimal_places) {
    double factor = pow(10, decimal_places);
    return ((long long)(number * factor + 0.5)) / factor;
}

/** 
 * @brief Converts decimal integer to binary string
 *
 * @param num				Decimal number to be converted 
 * @param out_str			Pointer to a string buffer where binary string will be stored
 * @param num_bits		Number of bits to output
 *
 * @return None
 */
static void Decimal_To_Binary_String(int num, char *out_str, int num_bits) {
    int remainder;
    out_str[0] = '\0';
    
    int i;
    for (i = num_bits - 1; i >= 0; i--) {
        remainder = num % 2;
        num = num / 2;

        if (remainder == 1) {
        	out_str[i] = '1';
	    } else {
		    out_str[i] = '0';
	    }
    }

    out_str[num_bits] = '\0';

    return;
}

/** 
 * @brief Concatenate multiple integers into a binary string
 *
 * @details Each integer in the array is converted into a binary string (with length NUM_OF_BITS) before concatenation
 *
 * @param data						Pointer to an integer array of data
 * @param data_types			Number of data in the array
 * @param out_str					Pointer to a string buffer where the concatenated binary string will be stored 
 *
 * @return None
 */
static void Data_To_Write(const int * data, const int data_types, char * out_str) {
    char temp[NUM_OF_BITS + 1];
    out_str[0] = '\0';
    int i;
    for (i = 0; i < data_types; i++) {
        Decimal_To_Binary_String(data[i], temp, NUM_OF_BITS);
        strcat(out_str, temp);
    }

    return;
}

/** 
 * @brief Generates a data file for testing
 *
 * @details
 * Converts the provided temp and humidity values into a 40-bit data stream, 
 * writes each bit (1 or 0) to a new line in the specified filename
 * The conversion must follow the DHT22 datasheet protocol 
 * (8-bit humidity integer, 8-bit humidity decimal, 8-bit temperature integer, 
 * 8-bit temperature decimal, 8-bit checksum)
 *
 * @param filename		Name (including path) of the data file to be generated for testing 
 * @param temp			Float value of temperature provided by user
 * @param humidity		Float value of humidity provided by user
 *
 * @return None
 */
void Create_Data_Test(const char *filename, float temp, float humidity) {
    int tmp_temp;
    int tmp_humidity;
    int temp_high;
    int temp_low;
    int humidity_high;
    int humidity_low;
    int checksum;
    char data_to_write[DATA_BITS + 1];
    FILE *fp;

    // Open file in write mode
    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("fopen");
        g_last_error = 1;
        return;
    }

    // Handle humidity value
    tmp_humidity = (Round_To_Decimal_Places((double)humidity, 1)) * 10; // Round to 1 decimal place
    humidity_high = (tmp_humidity >> NUM_HIGH_BITS) & 0xFF;
    humidity_low = tmp_humidity & 0xFF;
    
    // Handle temperature value
    tmp_temp = (Round_To_Decimal_Places((double)(fabsf(temp)), 1)) * 10;
    // Check negative temperature value 
    if (temp < 0.0f) {
        temp_high = ((tmp_temp >> NUM_HIGH_BITS) & 0xFF) | (0x01 << HIGHEST_HIGH_BIT);
    } else {
        temp_high = (tmp_temp >> NUM_HIGH_BITS) & 0xFF;
    }
    temp_low = tmp_temp & 0xFF;
    
    // Calculate checksum
    checksum = humidity_high + humidity_low + temp_high + temp_low;

    int data[NUM_OF_DATA] = { temp_high, temp_low, humidity_high, humidity_low, checksum };

    Data_To_Write(data, NUM_OF_DATA, data_to_write);
    
    // Write data to file
    int i;
    for (i = 0; i < DATA_BITS; i++) {
        fputc(data_to_write[i], fp);
        fputc('\n', fp);
    }

    fclose(fp); 

    return;
}
