#ifndef XLFPARSER_JNI_H
#define XLFPARSER_JNI_H
#include <jni.h>
#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Class:     ajiwo_xlfparser_XlfParser
 * Method:    parseFile
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_ajiwo_xlfparser_XlfParser_parseFile
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ajiwo_xlfparser_XlfParser
 * Method:    getLayout
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_ajiwo_xlfparser_XlfParser_getLayout
  (JNIEnv *, jobject);


#ifdef	__cplusplus
}
#endif

#endif // XLFPARSER_JNI_H
