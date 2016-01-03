package ajiwo.xlfparser.jni.test;

import ajiwo.xlfparser.XlfLayout;
import ajiwo.xlfparser.XlfMedia;
import ajiwo.xlfparser.XlfRegion;

public class MediaTest extends CommonClass {
    public static void main(String[] args) {
        XlfLayout layout = getLayout();
        XlfRegion region;
        XlfMedia media;
        if(layout == null) {
            return;
        }
        int argc = args.length;
        if(argc < 1) {
            System.exit(1);
        }

        String cmd = args[0];
        int regionIndex = Integer.parseInt(args[1]);
        int mediaIndex = Integer.parseInt(args[2]);

        region = layout.regions.get(regionIndex);
        media = region.media.get(mediaIndex);
        switch (cmd) {
            case "dummy":
                System.out.println(cmd);
                break;
            case "id":
                System.out.println(media.id);
                break;
            case "type":
                System.out.println(media.type);
                break;
            case "render":
                System.out.println(media.render);
                break;
            case "duration":
                System.out.println(media.duration);
                break;
            case "numraw":
                System.out.println(media.raws.size());
                break;
            case "numoption":
                System.out.println(media.options.size());
                break;
            default:
                System.exit(2);
        }
    }
}
