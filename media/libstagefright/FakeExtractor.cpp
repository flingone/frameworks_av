#define LOG_NDEBUG 0
#define LOG_TAG "mm-debug"
#include <utils/Log.h>

#include <media/stagefright/foundation/AMessage.h>
#include <cutils/properties.h> // for property_get
#include <utils/String8.h>

#include "FakeExtractor.h"
namespace android {

    bool SniffFake(
            const sp<DataSource> &source, String8 *mimeType, float *confidence,
            sp<AMessage> *meta) {
        ssize_t rn = 0;
        uint8_t header[1024];

        char prop[PROPERTY_VALUE_MAX];
        if (property_get("media.stagefright.debug", prop, NULL)
                && (!strcmp(prop, "1") || !strcasecmp(prop, "true"))) {

            if ((rn = source->readAt(0, header, 1024)) != 1024){
                if (rn <= 0) {
                    ALOGE("IO Error.");
                    return false;
                }
            }

            for (int i = 0; i < rn; i ++) {
                ALOGE("%d - 0x%x - %c", header[i], header[i], header[i]);
            }
        }

        return false;
    }
}


