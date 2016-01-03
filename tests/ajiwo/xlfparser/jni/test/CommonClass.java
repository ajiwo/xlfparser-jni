package ajiwo.xlfparser.jni.test;

import ajiwo.xlfparser.XlfLayout;
import ajiwo.xlfparser.XlfParser;

public class CommonClass {
    protected static XlfLayout getLayout() {
        XlfParser parser = new XlfParser();
        XlfLayout layout = null;
        boolean parsed;

        parsed = parser.parseFile("/tmp/file.xml");
        if(parsed) {
            layout = parser.getLayout();
        }

        return layout;
    }
}
