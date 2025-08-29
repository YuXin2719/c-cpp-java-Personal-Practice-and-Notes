//package com.neuedu.tl.oop.frame;
//
//import javax.imageio.ImageIO;
//import java.awt.*;
//import java.io.IOException;
//import java.net.URL;
//
//public final class ImageUtil {
//    private ImageUtil() {}
//    public static Image getImage(String path) {
//        //根据硬盘的路径返回该路径对应的图片对象
//        //path表示相对路径或者绝对路径
//        Image img = null;
//        URL url = ImageUtil.class.getClassLoader().getResource(path);
//        try {
//            img = ImageIO.read(url);
//        } catch (IOException e) {
//            e.printStackTrace();
//            System.out.println("图片加载失败");
//        }
//        return img;
//    }
//}
