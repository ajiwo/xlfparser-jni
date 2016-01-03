package ajiwo.xlfparser.jni.test;

import ajiwo.xlfparser.XlfLayout;

public class LayoutTest extends CommonClass {
    public static void main(String[] args) {
        XlfLayout layout = getLayout();

        if(layout == null) {
            return;
        }
        int argc = args.length;
        if(argc < 1) {
            System.exit(1);
        }

        String cmd = args[0];
        switch (cmd) {
            case "dummy":
                System.out.println(cmd);
                break;
            case "width":
                System.out.println(layout.width);
                break;
            case "height":
                System.out.println(layout.height);
                break;
            case "bgcolor":
                System.out.println(layout.bgcolor);
                break;
            case "background":
                System.out.println(layout.background);
                break;
            case "numregion":
                System.out.println(layout.regions.size());
                break;
            case "numtag":
                System.out.println(layout.tags.size());
                break;
            default:
                System.exit(2);
        }
    }
}
