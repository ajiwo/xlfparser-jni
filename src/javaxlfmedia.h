#ifndef JAVA_XLF_MEDIA_H
#define JAVA_XLF_MEDIA_H

#include <xlfparser/xlfparser.h>
#include "javaxlfarraylist.h"
#include "javaxlfhashmap.h"


class JavaXlfMedia : public JavaXlfObject
{
public:
    JavaXlfMedia(JNIEnv *env);
    void setMedia(Media *media);
    void attachOptions();
    void attachRaws();

private:
    Media *mMedia;
};

#endif // JAVA_XLF_MEDIA_H
