// -*- coding:utf-8-unix -*-
/**
 * @file   AQM0802.hpp
 * @author alnasl
 * @date   Thu Jun 16 14:45:57 2022
 *
 * @brief  Act driver for AQM0802 LCD modules built with the Sitronix ST7032 LCD controller
 *
 * Copyright (C) 2022 Mono Wireless Inc. All Rights Reserved.
 * Released under MW-OSSLA-*J,*E (MONO WIRELESS OPEN SOURCE SOFTWARE LICENSE AGREEMENT).
 */

#pragma once

// Include Files //////////////////////////////////////////////////////////////

#include <stdarg.h>             // For printf
#include <stdint.h>             // For uint8_t


// Macro Definitions //////////////////////////////////////////////////////////

/// Display width
#define AQM0802_COLUMNS 8
/// Display height
#define AQM0802_ROWS 2
/// Maximum length of printf() strings
#define AQM0802_PRINTF_MAX 64


// Type Definitions ///////////////////////////////////////////////////////////

/// ST7032 control bytes
enum st7032_ctrl_byte_e {
    ST7032_INSTRUCTION = 0x00,
    ST7032_DATA = 0x40
};

/// Cursor structure
struct st7032_cursor_s {
    int row;
    int col;
};


// Class Definition ///////////////////////////////////////////////////////////

class AQM0802 {
private:
    /**
     * @brief   I2C slave address
     */
    uint8_t i2c_address;
    /**
     * @brief   Virtual VRAM
     */
    char vvram[AQM0802_ROWS][AQM0802_COLUMNS];
    /**
     * @brief   Current cursor positions (row/col)
     */
    st7032_cursor_s cursor;

public:
    /**
     * @fn      AQM0802
     * @brief   Constructor
     */
    AQM0802();

    /**
     * @fn      ~AQM0802
     * @brief   Destructor
     */
    ~AQM0802() {}

public:
    /**
     * @fn      begin
     * @brief   Setup the display
     *
     * @param   none
     * @return  none
     */
    void begin();

    /**
     * @fn      clear
     * @brief   Clear the display
     *
     * @param   none
     * @return  none
     */
    void clear();

    /**
     * @fn      printf
     * @brief   Print formatted text to the display
     *
     * @param   format  Formatted string
     * @param   ...     Parameters
     * @return  Number of printed characters
     */
    int printf(const char* format, ...);

    /**
     * @fn      putc
     * @brief   Print a character to the display
     *
     * @param   c       Character
     * @return  none
     */
    void putc(const char c);

    /**
     * @fn      move
     * @brief   Move the cursor position (affects printf/putc)
     *
     * @param   y   Cursor position y (row)
     * @param   x   Cursor position x (column)
     * @retval  1   Success
     * @retval  -1  Error (out of range)
     */
    int move(const int y, const int x);

private:
    /**
     * @fn      clearVVRAM
     * @brief   clear the VVRAM
     *
     * @param   none
     * @return  none
     */
    void clearVVRAM();

    /**
     * @fn      moveVVRAMCursorTo
     * @brief   Move the cursor on the VVRAM to the specified position
     *
     * @param   row     Row (y)
     * @param   col     Column (x)
     * @return  none
     */
    void moveVVRAMCursorTo(const uint8_t row, const uint8_t col);

    /**
     * @fn      moveVVRAMCursorForward
     * @brief   Move the cursor on the VVRAM forward
     *
     * @param   none
     * @return  none
     */
    void moveVVRAMCursorForward();

    /**
     * @fn      putVVRAM
     * @brief   Put a character at current cursor position of the VVRAM
     *
     * @param   c       Character to put
     * @return  none
     */
    void putVVRAM(const char c);

private:
    /**
     * @fn      initializeDisplay
     * @brief   Initialize the display
     *
     * @param   none
     * @return  none
     */
    void initializeDisplay();

    /**
     * @fn      updateDisplayWithVVRAM
     * @brief   Update display contents with data in the VVRAM
     *
     * @param   none
     * @return  none
     */
    void updateDisplayWithVVRAM();

    /**
     * @fn      writeDisplay
     * @brief   Write commands to the display
     *
     * @param   ctrl_byte   ST7032 control byte
     * @param   data        ST7032 data
     * @return  none
     */
    void writeDisplay(const st7032_ctrl_byte_e ctrl_byte, const uint8_t data);

    /**
     * @fn      moveDisplayCursorTo
     * @brief   Move the cursor on the display
     *
     * @param   row     Row (y)
     * @param   col     Column (x)
     * @return  none
     */
    void moveDisplayCursorTo(const uint8_t row, const uint8_t col);
};
