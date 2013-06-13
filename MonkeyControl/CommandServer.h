//==============================================================================
// Project  : Lab Monkey
// Module   : console
// File     : CommandServer.h
// Brief    : Serves commands from the remote console
//==============================================================================

#ifndef COMMAND_SERVER_H
#define COMMAND_SERVER_H

#include "mbed.h"
#include "EthernetInterface.h"
#include "../MonkeyMessages/MessageFramer.h"
#include "C12832_lcd.h"

/// \brief mbed based server for the remote console
/// \ingroup console
///
/// Instantiate this class in a separate thread and call run() to start processing
/// remote commands.
///
/// The server does the following
/// - Creates a TCP server on specified port
/// - Accepts commands from remote console
/// - Deframes the TCP packets
/// - Interprets the command and notifies the robot controller thread via
///   the common message queue
/// - Waits for robot controller thread to respond
/// - Replies to the remote console when a response becomes available
class CommandServer
{
public:
    CommandServer(C12832_LCD &lcd) : _lcd(lcd) {}
    ~CommandServer() {}

    /// Initialise server and bind to specified port
    bool init(int port);

    /// Start the server loop
    void run();

private:
    EthernetInterface   _eth;
    TCPSocketServer     _server;
    MessageFramer       _framer;
    C12832_LCD&         _lcd;
};


#endif // COMMAND_SERVER_H
