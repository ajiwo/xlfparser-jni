package ajiwo.xlfparser.jni.test;

import ajiwo.xlfparser.XlfLayout;
import ajiwo.xlfparser.XlfRegion;

public class RegionTest extends CommonClass {
    public static void main(String[] args) {
        XlfLayout layout = getLayout();
        XlfRegion region;
        if(layout == null) {
            return;
        }
        int argc = args.length;
        if(argc < 1) {
            System.exit(1);
        }

        String cmd = args[0];
        int index = Integer.parseInt(args[1]);
        region = layout.regions.get(index);
        switch (cmd) {
            case "dummy":
                System.out.println(cmd);
                break;
            case "id":
                System.out.println(region.id);
                break;
            case "width":
                System.out.println(region.width);
                break;
            case "height":
                System.out.println(region.height);
                break;
            case "left":
                System.out.println(region.left);
                break;
            case "top":
                System.out.println(region.top);
                break;
            case "nummedia":
                System.out.println(region.media.size());
                break;
            case "numoption":
                System.out.println(region.options.size());
                break;
            default:
                System.exit(2);
        }
    }
}
