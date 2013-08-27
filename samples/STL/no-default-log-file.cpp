 //
 // This file is part of Easylogging++ samples
 // Very basic sample to configure using configuration and not default log file
 //
 // @since v9.13
 // Revision 1.0
 // @author mkhan3189
 //

#define _ELPP_NO_DEFAULT_LOG_FILE

#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(void) {

    // If we log before configuration, we will end up with heaps of internal errors because _ELPP_NO_DEFAULT_LOG_FILE is defined before include
    el::Configurations confFromFile("../default-logger.conf");

    el::Loggers::reconfigureAllLoggers(confFromFile); 
     
    LOG(INFO) << "Logging after configured!";
    return 0;
}
