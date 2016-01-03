#include "javaxlflayout.h"

JavaXlfLayout::JavaXlfLayout(JNIEnv *env)
    : JavaXlfObject(env, "ajiwo/xlfparser/XlfLayout")
{
}
void JavaXlfLayout::setLayoutNode(xlfNode *node) {
    jfieldID fid;

    Layout *layout = xlfparser_get_layout(node);

    fid = mEnv->GetFieldID(mCls, "width", "I");
    mEnv->SetIntField(mObj, fid, layout->width);

    fid = mEnv->GetFieldID(mCls, "height", "I");
    mEnv->SetIntField(mObj, fid, layout->height);

    fid = mEnv->GetFieldID(mCls, "bgcolor", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(layout->bgcolor));

    fid = mEnv->GetFieldID(mCls, "background", "Ljava/lang/String;");
    mEnv->SetObjectField(mObj, fid, mEnv->NewStringUTF(layout->background));

    mLayout = layout;
    mNode = node;
}

void JavaXlfLayout::attachRegions() {
    JavaXlfArrayList arrLst(mEnv);
    jfieldID regionsFid = mEnv->GetFieldID(mCls, "regions", "Ljava/util/List;");
    int length = xlfparser_region_length(mLayout);
    for(int i = 0; i < length; i++) {
        Region *region = xlfparser_get_region(mLayout, i);
        JavaXlfRegion jregion(mEnv);
        jregion.setRegion(region);
        jregion.attachMedia();
        jregion.attachOptions();
        arrLst.add(jregion.getObject());
    }
    mEnv->SetObjectField(mObj, regionsFid, arrLst.getObject());
}

void JavaXlfLayout::attachTags() {
    JavaXlfArrayList arrLst(mEnv);
    jfieldID tagsFid = mEnv->GetFieldID(mCls, "tags", "Ljava/util/List;");
    int length = xlfparser_tag_length(mLayout);
    for(int i = 0; i < length; i++) {
        arrLst.add(mEnv->NewStringUTF(xlfparser_get_tag(mLayout, i)));
    }
    mEnv->SetObjectField(mObj, tagsFid, arrLst.getObject());
}
