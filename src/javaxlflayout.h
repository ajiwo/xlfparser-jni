#ifndef JAVA_XLF_LAYOUT_H
#define JAVA_XLF_LAYOUT_H
#include "javaxlfregion.h"

class JavaXlfLayout : public JavaXlfObject
{
public:
    JavaXlfLayout(JNIEnv *env);
    void setLayoutNode(xlfNode *node);
    void attachRegions();
    void attachTags();

private:
    Layout *mLayout;
    LayoutTag *mTags;
    xlfNode *mNode;
};

#endif // JAVA_XLF_LAYOUT_H
