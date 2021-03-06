//==============================================================================
// Project  : Lab Monkey
// Module   : mbed board
// File     : AppBoard.h
// Brief    : Facilities from the application board
//==============================================================================

#ifndef APPBOARD_H
#define APPBOARD_H

#include "mbed.h"
#include "Display.h"
#include "EthernetInterface.h"

/// \brief singleton accessor for hardware io on the mbed application board
class AppBoard
{
public:

    /// the one and only me
    static inline AppBoard& singleton();

    /// logging intensity
    /// - 0: critical info,
    /// - 1: 0 + motor log,
    /// - 2: 1 + function calls
    static const int VERBOSITY = 0;

    /// log port configuration
    static const PinName LOG_SERIAL_TX = USBTX;
    static const PinName LOG_SERIAL_RX = USBRX;

    /// robot serial port configuration
    static const PinName ROBOT_SERIAL_TX = p9;
    static const PinName ROBOT_SERIAL_RX = p10;
    static const int ROBOT_SERIAL_BAUD = 9600;

    /// command server configuration
    static const int SERVER_PORT = 1234;

    /// control button mapping
    static const PinName BTN_MODE = p14; // mode
    static const PinName BTN_FUNC = p13; // rec, play/stop
    static const PinName BTN_CLEAR = p16; //clear waypoints, speed down
    static const PinName BTN_HOME = p17; // home, speed up

    /// peripherals
    static Display& lcd() { return singleton()._lcd; }
    static Serial& logStream() { return singleton()._logStream; }
    static EthernetInterface& eth() { return singleton()._eth; }
    static Serial& robotPort() { return singleton()._robotPort; }

    static bool initPorts();

private:
    AppBoard();
    ~AppBoard();

public:

    Serial              _robotPort;
    Serial              _logStream;
    Display             _lcd;
    EthernetInterface   _eth;
};

//------------------------------------------------------------------------------
AppBoard& AppBoard::singleton()
//------------------------------------------------------------------------------
{
    static AppBoard s_singleton;
    return s_singleton;
 }

#endif // APPBOARD_H
