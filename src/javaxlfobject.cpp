#include "javaxlfobject.h"

JavaXlfObject::JavaXlfObject(JNIEnv *env, const char* fullClassName)
    : mEnv(env), mCls(mEnv->FindClass(fullClassName))
{
    jmethodID arrayListCtor = mEnv->GetMethodID(mCls, "<init>", "()V");
    mObj = mEnv->NewObject(mCls, arrayListCtor);

}

jobject JavaXlfObject::getObject() {
    return mObj;
}

