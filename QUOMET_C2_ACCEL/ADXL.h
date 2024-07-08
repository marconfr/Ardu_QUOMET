#ifndef ADXL_H
#define ADXL_H

#include <stdint.h>

// Constants for device I2C addresses and multipliers
#define ADXL375_DEFAULT_ADDRESS 0x53
#define ADXL345_ALTERNA_ADDRESS 0x1D
#define ADXL375_MULTIPLIER 0.049
#define ADXL345_MULTIPLIER 0.0039
#define STANDARD_GRAVITY 9.80665

// Constants for ADXL register addresses and default values
typedef struct {
    const uint8_t REG_DEVID;
    const uint8_t REG_THRESH_TAP;
    const uint8_t REG_OFSX;
    const uint8_t REG_OFSY;
    const uint8_t REG_OFSZ;
    const uint8_t REG_DUR;
    const uint8_t REG_LATENT;
    const uint8_t REG_WINDOW;
    const uint8_t REG_THRESH_ACT;
    const uint8_t REG_THRESH_INACT;
    const uint8_t REG_TIME_INACT;
    const uint8_t REG_ACT_INACT_CTL;
    const uint8_t REG_THRESH_FF;
    const uint8_t REG_TIME_FF;
    const uint8_t REG_TAP_AXES;
    const uint8_t REG_ACT_TAP_STATUS;
    const uint8_t REG_BW_RATE;
    const uint8_t REG_POWER_CTL;
    const uint8_t REG_INT_ENABLE;
    const uint8_t REG_INT_MAP;
    const uint8_t REG_INT_SOURCE;
    const uint8_t REG_DATA_FORMAT;
    const uint8_t REG_DATAX0;
    const uint8_t REG_DATAX1;
    const uint8_t REG_DATAY0;
    const uint8_t REG_DATAY1;
    const uint8_t REG_DATAZ0;
    const uint8_t REG_DATAZ1;
    const uint8_t REG_FIFO_CTL;
    const uint8_t REG_FIFO_STATUS;
} ADXL_REG_ADDRESSES;

static const ADXL_REG_ADDRESSES ADXL_REG = {
    .REG_DEVID          = 0x00, // Device ID
    .REG_THRESH_TAP     = 0x1D, // Shock threshold
    .REG_OFSX           = 0x1E, // X-axis offset
    .REG_OFSY           = 0x1F, // Y-axis offset
    .REG_OFSZ           = 0x20, // Z-axis offset
    .REG_DUR            = 0x21, // Shock duration
    .REG_LATENT         = 0x22, // Shock latency
    .REG_WINDOW         = 0x23, // Shock window
    .REG_THRESH_ACT     = 0x24, // Activity threshold
    .REG_THRESH_INACT   = 0x25, // Inactivity threshold
    .REG_TIME_INACT     = 0x26, // Inactivity time
    .REG_ACT_INACT_CTL  = 0x27, // Axis enable control for activity/inactivity detection
    .REG_THRESH_FF      = 0x28, // Free-fall threshold (not described in ADXL375)
    .REG_TIME_FF        = 0x29, // Free-fall time (not described in ADXL375)
    .REG_TAP_AXES       = 0x2A, // Axis control for single shock/double shock
    .REG_ACT_TAP_STATUS = 0x2B, // Source of single shock/double shock
    .REG_BW_RATE        = 0x2C, // Data rate and power mode control (default normal power mode / 100Hz)
    .REG_POWER_CTL      = 0x2D, // Power-saving features control
    .REG_INT_ENABLE     = 0x2E, // Interrupt enable control
    .REG_INT_MAP        = 0x2F, // Interrupt mapping control
    .REG_INT_SOURCE     = 0x30, // Interrupt source
    .REG_DATA_FORMAT    = 0x31, // Data format control
    .REG_DATAX0         = 0x32, // X-axis data 0 (low)
    .REG_DATAX1         = 0x33, // X-axis data 1 (high)
    .REG_DATAY0         = 0x34, // Y-axis data 0 (low)
    .REG_DATAY1         = 0x35, // Y-axis data 1 (high)
    .REG_DATAZ0         = 0x36, // Z-axis data 0 (low)
    .REG_DATAZ1         = 0x37, // Z-axis data 1 (high)
    .REG_FIFO_CTL       = 0x38, // FIFO control default: bypassed
    .REG_FIFO_STATUS    = 0x39  // FIFO status
};

// Interrupt bits
#define INT_SINGLE_TAP  0b01000000 // SINGLE_TAP bit
#define INT_DOUBLE_TAP  0b00100000 // DOUBLE_TAP bit
#define INT_ACT         0b00010000 // ACT bit
#define INT_INACT       0b00001000 // INACT bit
#define INT_FREE_FALL   0b00000100 // FREE_FALL bit

// Constants for ADXL data rates
typedef struct {
    const uint8_t RATE_3200_HZ;
    const uint8_t RATE_1600_HZ;
    const uint8_t RATE_800_HZ;
    const uint8_t RATE_400_HZ;
    const uint8_t RATE_200_HZ;
    const uint8_t RATE_100_HZ;
    const uint8_t RATE_50_HZ;
    const uint8_t RATE_25_HZ;
    const uint8_t RATE_12_5_HZ;
    const uint8_t RATE_6_25_HZ;
    const uint8_t RATE_3_13_HZ;
    const uint8_t RATE_1_56_HZ;
    const uint8_t RATE_0_78_HZ;
    const uint8_t RATE_0_39_HZ;
    const uint8_t RATE_0_20_HZ;
    const uint8_t RATE_0_10_HZ;
} ADXL_DATARATE_VALUES;

static const ADXL_DATARATE_VALUES ADXL_DATARATE = {
    .RATE_3200_HZ = 0b1111, // 1600Hz Bandwidth, 140mA IDD (Only in SPI)
    .RATE_1600_HZ = 0b1110, // 800Hz Bandwidth, 90mA IDD (Only in SPI)
    .RATE_800_HZ  = 0b1101, // 400Hz Bandwidth, 140mA IDD (Max. I2C)
    .RATE_400_HZ  = 0b1100, // 200Hz Bandwidth, 140mA IDD
    .RATE_200_HZ  = 0b1011, // 100Hz Bandwidth, 140mA IDD
    .RATE_100_HZ  = 0b1010, // 50Hz Bandwidth, 140mA IDD
    .RATE_50_HZ   = 0b1001, // 25Hz Bandwidth, 90mA IDD
    .RATE_25_HZ   = 0b1000, // 12.5Hz Bandwidth, 60mA IDD
    .RATE_12_5_HZ = 0b0111, // 6.25Hz Bandwidth, 50mA IDD
    .RATE_6_25_HZ = 0b0110, // 3.13Hz Bandwidth, 45mA IDD
    .RATE_3_13_HZ = 0b0101, // 1.56Hz Bandwidth, 40mA IDD
    .RATE_1_56_HZ = 0b0100, // 0.78Hz Bandwidth, 34mA IDD
    .RATE_0_78_HZ = 0b0011, // 0.39Hz Bandwidth, 23mA IDD
    .RATE_0_39_HZ = 0b0010, // 0.20Hz Bandwidth, 23mA IDD
    .RATE_0_20_HZ = 0b0001, // 0.10Hz Bandwidth, 23mA IDD
    .RATE_0_10_HZ = 0b0000  // 0.05Hz Bandwidth, 23mA IDD (default value)
};

// Constants for ADXL345 ranges
typedef struct {
    const uint8_t RANGE_16_G;
    const uint8_t RANGE_8_G;
    const uint8_t RANGE_4_G;
    const uint8_t RANGE_2_G;
} ADXL345_RANGE_VALUES;

static const ADXL345_RANGE_VALUES ADXL345_RANGE = {
    .RANGE_16_G = 0b11, // +/- 16g
    .RANGE_8_G  = 0b10, // +/- 8g
    .RANGE_4_G  = 0b01, // +/- 4g
    .RANGE_2_G  = 0b00  // +/- 2g (default value)
};

#endif // ADXL_REGISTERS_H
