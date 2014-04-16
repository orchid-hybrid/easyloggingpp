 //
 // This file is part of Easylogging++ samples
 // PerformanceTrackingCallback sample
 //
 // Revision 1.0
 // @author mkhan3189
 //

#define _ELPP_HANDLE_POST_PERFORMANCE_TRACKING // we need this!
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP
class Handler : public el::PerformanceTrackingCallback {
protected:
void handle(const el::PerformanceTrackingData* data) {
    TIMED_SCOPE(handBlock, "handerBlock");
    // ELPP_COUT is cout when not using unicode otherwise wcout
    ELPP_COUT << "I am from handler: " << data->blockName()->c_str() << " in " << *data->formattedTimeTaken();
    if (data->dataType() == el::PerformanceTrackingData::DataType::Checkpoint) {
        ELPP_COUT << " [CHECKPOINT ONLY] ";
    }
    ELPP_COUT << std::endl;
    LOG(INFO) << "You can even log from here!";
}
};

int main(void) {

    TIMED_SCOPE(mainBlock, "main");

    el::Helpers::installPerformanceTrackingCallback<Handler>("handler");

    {
        TIMED_SCOPE(timer, "my-block");
        for (int i = 0; i <= 500; ++i) {
            // Spend time
            for (int j = 0; j < 10000; ++j) { std::string tmp; }
            if (i % 100 == 0) {
                timer.checkpoint(std::string(std::string("checkpoint at ") + std::to_string(static_cast<unsigned long long>(i))).c_str());
            }
        }
    } 
    LOG(INFO) << "By now, you should get performance result of above scope";

    return 0;
}
