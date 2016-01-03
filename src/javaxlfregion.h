#ifndef JAVA_XLF_REGION_H
#define JAVA_XLF_REGION_H
#include "javaxlfmedia.h"

class JavaXlfRegion : public JavaXlfObject
{
public:
    JavaXlfRegion(JNIEnv *env);
    void setRegion(Region *region);
    void attachMedia();
    void attachOptions();
private:
    Region *mRegion;
    RegionOption *mOptions;
};

#endif // JAVA_XLF_REGION_H
