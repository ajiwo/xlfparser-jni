#ifndef JAVA_XLF_ARRAYLIST_H
#define JAVA_XLF_ARRAYLIST_H

#include "javaxlfobject.h"

class JavaXlfArrayList: public JavaXlfObject
{
public:
    JavaXlfArrayList(JNIEnv *env);
    jboolean add(jobject element);

};


#endif // JAVA_XLF_ARRAYLIST_H
