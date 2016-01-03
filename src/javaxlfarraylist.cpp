#include "javaxlfarraylist.h"


JavaXlfArrayList::JavaXlfArrayList(JNIEnv *env)
    : JavaXlfObject(env, "java/util/ArrayList")
{

}

jboolean JavaXlfArrayList::add(jobject element) {
    jmethodID arrayListAdd = mEnv->GetMethodID(mCls, "add", "(Ljava/lang/Object;)Z");
    return mEnv->CallBooleanMethod(mObj, arrayListAdd, element);
}
