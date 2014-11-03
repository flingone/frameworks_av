#ifndef FAKE_EXTRACTOR_H_
#define FAKE_EXTRACTOR_H_

#include <media/stagefright/DataSource.h>
#include <utils/String8.h>

namespace android {

    bool SniffFake(
            const sp<DataSource> &source, String8 *mimeType, float *confidence,
            sp<AMessage> *);

}  // namespace android

#endif  //FAKE_EXTRACTOR_H_
