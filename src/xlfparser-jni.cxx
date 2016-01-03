#include "xlfparser-jni.h"
#include "javaxlflayout.h"

namespace {
xlfNode *node;
bool parsed = false;
}


JNIEXPORT jboolean JNICALL Java_ajiwo_xlfparser_XlfParser_parseFile
  (JNIEnv *env, jobject, jstring fileName) {
    const char* cFileName = env->GetStringUTFChars(fileName, (jboolean*) false);
    node = xlfparser_parse_file(cFileName);
    parsed = node != NULL;
    return (jboolean) parsed;
}


JNIEXPORT jobject JNICALL Java_ajiwo_xlfparser_XlfParser_getLayout
  (JNIEnv *env, jobject) {
    JavaXlfLayout jlayout(env);
    if(parsed) {
        jlayout.setLayoutNode(node);
        jlayout.attachRegions();
        jlayout.attachTags();
        return jlayout.getObject();
    }
    return NULL;
}
