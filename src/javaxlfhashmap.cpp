#include "javaxlfhashmap.h"

JavaXlfHashMap::JavaXlfHashMap(JNIEnv *env)
    : JavaXlfObject(env, "java/util/HashMap")
{

}

jobject JavaXlfHashMap::put(const char *key, const char *value) {
    jmethodID hashMapPut = mEnv->GetMethodID(mCls, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    return mEnv->CallObjectMethod(mObj, hashMapPut, mEnv->NewStringUTF(key), mEnv->NewStringUTF(value));
}
