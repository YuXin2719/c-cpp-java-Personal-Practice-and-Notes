//package com.neuedu.tl.oop.frame;
//
//import java.awt.*;
//import java.awt.event.WindowAdapter;
//import java.awt.event.WindowEvent;
//
//public class MyFrame extends Frame {
//    // 加载太阳
//    Image sun = ImageUtil.getImage("com/neuedu/tl/oop/img/太阳.png");
//    // 加载地球
//    Image earth = ImageUtil.getImage("com/neuedu/tl/oop/img/地球.png");
//
//    // 窗口大小常数
//    public static final int WINDOW_WIDTH = 2400;
//    public static final int WINDOW_HEIGHT = 1400;
//    //画板大小常数
//    public static final int PANEL_WIDTH = 8000;
//    // 太阳像素常数
//    public static final int SUN_WIDTH = 2173;
//    // 地球像素常数
//    public static final int EARTH_WIDTH = 20;
//    //地球矩形常数（真实比例的像素太大了，这里天体间距离我个人定义1AU为500px，天体大小的像素按照表格的设计了）
//    public static final int EARTH_RECTANGLE_WIDTH = 3173; //计算后得到3173
//
//    // 内容面板
//    private Panel contentPanel;
//
//    // 加载窗体的方法
//    public void loadFrame() {
//        this.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//        this.setVisible(true);
//        // 水平垂直居中
//        this.setLocationRelativeTo(null);
//        this.setTitle("2021006155-辛宏宇");
//
//        // 创建ScrollPane时指定滚动条策略
//        ScrollPane scrollPane = new ScrollPane(ScrollPane.SCROLLBARS_AS_NEEDED);
//
//        // 创建一个大尺寸面板
//        contentPanel = new Panel() {
//            @Override
//            public void paint(Graphics g) {
//                super.paint(g);
//                // 在内容面板上绘制图片
//                g.drawImage(sun, (PANEL_WIDTH - SUN_WIDTH) / 2,
//                        (PANEL_WIDTH - SUN_WIDTH) / 2,
//                        SUN_WIDTH, SUN_WIDTH, null);
//                //画地球轨道
//                g.drawOval((PANEL_WIDTH - EARTH_RECTANGLE_WIDTH) / 2, (PANEL_WIDTH - EARTH_RECTANGLE_WIDTH) / 2, EARTH_RECTANGLE_WIDTH, EARTH_RECTANGLE_WIDTH);
//                //画地球
//                g.drawImage(earth, (PANEL_WIDTH - EARTH_WIDTH) / 2, (PANEL_WIDTH - EARTH_RECTANGLE_WIDTH - EARTH_WIDTH) / 2, EARTH_WIDTH, EARTH_WIDTH, null);
//                //让地球沿着地球轨道运动
//            }
//        };
//
//        contentPanel.setPreferredSize(new Dimension(PANEL_WIDTH, PANEL_WIDTH));
//
//        // 添加面板到ScrollPane
//        scrollPane.add(contentPanel);
//        this.add(scrollPane);
//
//        // 添加关闭窗体的方法
//        this.addWindowListener(new WindowAdapter() {
//            @Override
//            public void windowClosing(WindowEvent e) {
//                System.exit(0);
//            }
//        });
//    }
//
//
//    public static void main(String[] args) {
//        new MyFrame().loadFrame();
//    }
//}