package ajiwo.xlfparser;

public class XlfParser {
    public native boolean parseFile(String file);
    public native XlfLayout getLayout();

    static {
        System.loadLibrary("xlfparser-jni");
    }

}
