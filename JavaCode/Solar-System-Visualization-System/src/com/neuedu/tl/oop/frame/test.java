//package com.neuedu.tl.oop.frame;
//import java.awt.*;
//
//public class test {
//    public static void main(String[] args) {
//        Frame frame = new Frame("AWT ScrollPane示例");
//        frame.setSize(400, 300);
//
//        // 创建ScrollPane时指定滚动条策略
//        ScrollPane scrollPane = new ScrollPane(ScrollPane.SCROLLBARS_AS_NEEDED);
//
//        // 创建一个大尺寸面板
//        Panel contentPanel = new Panel();
//        contentPanel.setPreferredSize(new Dimension(8000, 6000));
//        contentPanel.setBackground(Color.LIGHT_GRAY);
//
//        // 添加面板到ScrollPane
//        scrollPane.add(contentPanel);
//
//        frame.add(scrollPane);
//        frame.setVisible(true);
//
//        // 添加窗口关闭事件
//        frame.addWindowListener(new java.awt.event.WindowAdapter() {
//            public void windowClosing(java.awt.event.WindowEvent e) {
//                System.exit(0);
//            }
//        });
//    }
//}
