#include "javaxlfregion.h"

JavaXlfRegion::JavaXlfRegion(JNIEnv *env)
    : JavaXlfObject(env, "ajiwo/xlfparser/XlfRegion")
{
}

void JavaXlfRegion::setRegion(Region *region) {
    jfieldID fid;

    fid = mEnv->GetFieldID(mCls, "id", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(region->id));

    fid = mEnv->GetFieldID(mCls, "width", "I");
    mEnv->SetIntField(mObj, fid, region->width);

    fid = mEnv->GetFieldID(mCls, "height", "I");
    mEnv->SetIntField(mObj, fid, region->height);

    fid = mEnv->GetFieldID(mCls, "left", "I");
    mEnv->SetIntField(mObj, fid, region->left);

    fid = mEnv->GetFieldID(mCls, "top", "I");
    mEnv->SetIntField(mObj, fid, region->top);

    mRegion = region;
}

void JavaXlfRegion::attachMedia() {
    JavaXlfArrayList arrLst(mEnv);
    jfieldID regionsFid = mEnv->GetFieldID(mCls, "media", "Ljava/util/List;");
    int length = xlfparser_media_length(mRegion);
    for(int i = 0; i < length; i++) {
        Media *media = xlfparser_get_media(mRegion, i);
        JavaXlfMedia jmedia(mEnv);
        jmedia.setMedia(media);
        jmedia.attachOptions();
        jmedia.attachRaws();
        arrLst.add(jmedia.getObject());
    }
    mEnv->SetObjectField(mObj, regionsFid, arrLst.getObject());

}

void JavaXlfRegion::attachOptions() {
    JavaXlfHashMap joption(mEnv);
    jfieldID optionsFid = mEnv->GetFieldID(mCls, "options", "Ljava/util/Map;");
    int length = xlfparser_region_option_length(mRegion);

    for(int i = 0; i < length; i++) {
        RegionOption *option = xlfparser_get_region_option(mRegion, i);
        joption.put(option->key, option->value);
    }
    mEnv->SetObjectField(mObj, optionsFid, joption.getObject());
}
