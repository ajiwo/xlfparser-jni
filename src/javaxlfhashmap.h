#ifndef JAVA_XLF_HASHMAP_H
#define JAVA_XLF_HASHMAP_H
#include "javaxlfobject.h"

class JavaXlfHashMap : public JavaXlfObject
{
public:
    JavaXlfHashMap(JNIEnv *env);
    jobject put(const char *key, const char *value);
};

#endif // JAVA_XLF_HASHMAP_H
