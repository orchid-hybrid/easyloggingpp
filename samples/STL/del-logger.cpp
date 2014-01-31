 //
 // This file is part of Easylogging++ samples
 // Sample to remove logger
 //
 // Revision 1.0
 // @author mkhan3189
 //

#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(void) {
    
    LOG(INFO) << "My first ultimate log message";
    CLOG(INFO, "test") << "Send me error";
    el::Loggers::getLogger("test");
    CLOG(INFO, "test") << "Write";
    el::Loggers::unregisterLogger("test");
    CLOG(INFO, "test") << "Send me error";
    return 0;
}
