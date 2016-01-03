#ifndef JAVA_XLF_OBJECT_H
#define JAVA_XLF_OBJECT_H

#include <jni.h>

class JavaXlfObject
{
public:
    JavaXlfObject(JNIEnv *env, const char* fullClassName);
    jobject getObject();

protected:
    JNIEnv *mEnv;
    jclass mCls;
    jobject mObj;
};

#endif // JAVA_XLF_OBJECT_H
