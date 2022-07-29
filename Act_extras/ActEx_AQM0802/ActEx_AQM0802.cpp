// -*- coding:utf-8-unix -*-
/**
 * @file   ActEx_AQM0802.cpp
 * @author alnasl
 * @date   Thu Jun 16 14:45:57 2022
 *
 * @brief  Act sample for using AQM0802 LCD modules built with the Sitronix ST7032 LCD controller
 *
 * Copyright (C) 2022 Mono Wireless Inc. All Rights Reserved.
 * Released under MW-OSSLA-*J,*E (MONO WIRELESS OPEN SOURCE SOFTWARE LICENSE AGREEMENT).
 */

// Include Files //////////////////////////////////////////////////////////////

#include <TWELITE>
#include "AQM0802/AQM0802.hpp"    // AQM0802 local library for TWELITE


// Macro Definitions //////////////////////////////////////////////////////////


// Function Prototypes ////////////////////////////////////////////////////////


// Global Objects /////////////////////////////////////////////////////////////

AQM0802 display;                // AQM0802 Display object
uint16_t count;                 // Count number (Maximum: 5 digits)


// Setup and Loop Procedure ///////////////////////////////////////////////////

/**
 * @fn      setup
 * @brief   the setup procedure (called on boot)
 *
 * @param   none
 * @return  none
 */
void setup() {
    // Setup the display
    display.begin();
    // Print initial messages
    display.printf("ActExtra AQM0802\n");
    delay(2000);
    display.printf("-Start!-\n");
    // Initialize the count number
    count = 0;
    // 1Hz Timer
    Timer0.begin(1);
}

/**
 * @fn      loop
 * @brief   the loop procedure (called every event)
 *
 * @param   none
 * @return  none
 */
void loop() {
    if (Timer0.available()) {
        // Increment the count number and print it
        display.printf("%05d[s]\n", ++count);
    }
}
