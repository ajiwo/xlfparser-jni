#include "javaxlfmedia.h"

JavaXlfMedia::JavaXlfMedia(JNIEnv *env)
    : JavaXlfObject(env, "ajiwo/xlfparser/XlfMedia")
{
}

void JavaXlfMedia::setMedia(Media *media) {
    jfieldID fid;

    fid = mEnv->GetFieldID(mCls, "id", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(media->id));

    fid = mEnv->GetFieldID(mCls, "type", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(media->type));

    fid = mEnv->GetFieldID(mCls, "duration", "I");
    mEnv->SetIntField(mObj, fid, media->duration);

    fid = mEnv->GetFieldID(mCls, "render", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(media->render));

    mMedia = media;
}

void JavaXlfMedia::attachOptions() {
    JavaXlfHashMap joption(mEnv);
    jfieldID optionsFid = mEnv->GetFieldID(mCls, "options", "Ljava/util/Map;");
    int length = xlfparser_media_option_length(mMedia);

    for(int i = 0; i < length; i++) {
        MediaOption *option = xlfparser_get_media_option(mMedia, i);
        joption.put(option->key, option->value);
    }
    mEnv->SetObjectField(mObj, optionsFid, joption.getObject());
}


void JavaXlfMedia::attachRaws() {
    JavaXlfHashMap jraw(mEnv);
    jfieldID optionsFid = mEnv->GetFieldID(mCls, "raws", "Ljava/util/Map;");
    int length = xlfparser_media_raw_length(mMedia);

    for(int i = 0; i < length; i++) {
        MediaOption *option = xlfparser_get_media_raw(mMedia, i);
        jraw.put(option->key, option->value);
    }
    mEnv->SetObjectField(mObj, optionsFid, jraw.getObject());
}


