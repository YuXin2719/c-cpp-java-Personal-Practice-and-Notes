package com.neuedu.tl.oop.solar.constant;

import javax.swing.undo.AbstractUndoableEdit;

public final class Constent {
    private Constent() {}
    //窗口名称
    public static final String WINDOW_TITLE = "2021006155-辛宏宇";
    // 窗口大小常数
    public static final int WINDOW_WIDTH = 2400;
    public static final int WINDOW_HEIGHT = 1400;
    //画板大小常数
    public static final int PANEL_WIDTH = 40000;

    // 太阳像素常数
    public static final int SUN_WIDTH = 2173;
    //太阳位置
    public static final int SUN_X = PANEL_WIDTH / 2;
    public static final int SUN_Y = PANEL_WIDTH / 2;

    // 水星像素常数
    public static final int MERCURY_WIDTH = 8;
    // 水星公转倍率
    public static final double MERCURY_PERIOD_RATE = 88.0/365;
    // 水星距离倍率（AU）
    public static final double MERCURY_CENTRIFUGAL_RATE = 0.387;
    //轨道离心率
    public static final double MERCURY_ECCENTRICITY = 0.2056;
    // 水星公转方向
    public static final boolean MERCURY_DIRECTION = true;

    // 金星像素常数
    public static final int VENUS_WIDTH = 19;
    // 金星公转倍率
    public static final double VENUS_PERIOD_RATE = 224.7/365;
    // 金星距离倍率（AU）
    public static final double VENUS_CENTRIFUGAL_RATE = 0.72;
    //轨道离心率
    public static final double VENUS_ECCENTRICITY = 0.0068;
    // 金星公转方向
    public static final boolean VENUS_DIRECTION = false;

    // 地球像素常数
    public static final int EARTH_WIDTH = 2000;
    // 地球公转倍率
    public static final double EARTH_PERIOD_RATE = 365.0/365;
    // 地球距离倍率（AU）
    public static final double EARTH_CENTRIFUGAL_RATE = 1;
    //轨道离心率
    public static final double EARTH_ECCENTRICITY = 0.0167;
    // 地球公转方向
    public static final boolean EARTH_DIRECTION = true;

    // 火星像素常数
    public static final int MARS_WIDTH = 11;
    // 火星公转倍率
    public static final double MARS_PERIOD_RATE = 687.0/365;
    // 火星距离倍率（AU）
    public static final double MARS_CENTRIFUGAL_RATE = 1.52;
    //轨道离心率
    public static final double MARS_ECCENTRICITY = 0.0934;
    // 火星公转方向
    public static final boolean MARS_DIRECTION = true;

    //木星像素常数
    public static final int JUPITER_WIDTH = 224;
    //木星公转倍率
    public static final double JUPITER_PERIOD_RATE = 4332.0/365;
    //木星距离倍率（AU）
    public static final double JUPITER_CENTRIFUGAL_RATE = 5.2;
    //轨道离心率
    public static final double JUPITER_ECCENTRICITY = 0.0489;
    //木星公转方向
    public static final boolean JUPITER_DIRECTION = true;

    //土星像素常数
    public static final int SATURN_WIDTH = 189;
    //土星公转倍率
    public static final double SATURN_PERIOD_RATE = 10759.0/365;
    //土星距离倍率（AU）
    public static final double SATURN_CENTRIFUGAL_RATE = 9.54;
    //轨道离心率
    public static final double SATURN_ECCENTRICITY = 0.0557;
    //土星公转方向
    public static final boolean SATURN_DIRECTION = true;

    //天王星像素常数
    public static final int URANUS_WIDTH = 80;
    //天王星公转倍率
    public static final double URANUS_PERIOD_RATE = 30685.0/365;
    //天王星距离倍率（AU）
    public static final double URANUS_CENTRIFUGAL_RATE = 19.218;
    //轨道离心率
    public static final double URANUS_ECCENTRICITY = 0.0444;
    //天王星公转方向
    public static final boolean URANUS_DIRECTION = true;

    //海王星像素常数
    public static final int NEPTUNE_WIDTH = 78;
    //海王星公转倍率
    public static final double NEPTUNE_PERIOD_RATE = 60189.0/365;
    //海王星距离倍率（AU）
    public static final double NEPTUNE_CENTRIFUGAL_RATE = 30.06;
    //轨道离心率
    public static final double NEPTUNE_ECCENTRICITY = 0.0112;
    //海王星公转方向
    public static final boolean NEPTUNE_DIRECTION = true;

    //月球像素常数
    public static final int MOON_WIDTH = 600;
    //地月距离倍率（AU）
    public static final double MOON_CENTRIFUGAL_RATE = 0.00257;
    //月球公转倍率
    public static final double MOON_PERIOD_RATE = 27.322/365;
    //月球公转方向
    public static final boolean MOON_DIRECTION = true;

    //真实比例的像素太大了，这里天体间距离我个人定义1AU为500px，天体大小的像素按照表格的设计了
    public static final int AU = 500;

    // 小行星带参数
//    public static final int ASTEROID_COUNT = 50;  // 小行星数量
//    public static final int ASTEROID_MIN_WIDTH = 2;  // 小行星最小宽度
//    public static final int ASTEROID_MAX_WIDTH = 5;  // 小行星最大宽度
//    public static final double ASTEROID_MIN_PERIOD_RATE = 0.5;  // 最小周期速率
//    public static final double ASTEROID_MAX_PERIOD_RATE = 2.0;  // 最大周期速率
//    public static final double ASTEROID_MIN_CENTRIFUGAL_RATE = MARS_CENTRIFUGAL_RATE + 1.0;  // 最小距离倍率
//    public static final double ASTEROID_MAX_CENTRIFUGAL_RATE = JUPITER_CENTRIFUGAL_RATE - 1.0;  // 最大距离倍率
//    public static final double ASTEROID_MIN_ECCENTRICITY = JUPITER_ECCENTRICITY;  // 最小离心率
//    public static final double ASTEROID_MAX_ECCENTRICITY = MARS_ECCENTRICITY;  // 最大离心率

    // 小行星带参数
    public static final int ASTEROID_COUNT = 1000;        // 小行星数量
    public static final int ASTEROID_SIZE = 5;            // 小行星大小
    public static final double ASTEROID_SPEED = 0.001;    // 基础速度

    // 火星和木星轨道之间的范围（根据您的配置调整）
    public static final double ASTEROID_MIN_RADIUS = SUN_WIDTH/2+AU*(MARS_CENTRIFUGAL_RATE + 1.0);
    public static final double ASTEROID_MAX_RADIUS = SUN_WIDTH/2+AU*(JUPITER_CENTRIFUGAL_RATE - 1.0);

    //轨道离心率对绘制出来的轨道影响太小，这里得暂时忽略不计了，近似为圆周运动
//    public static final int MERCURY_RECTANGLE_WIDTH = (int)(SUN_WIDTH + 2 * 0.387 * AU); //计算后得到3173
    //公转周期基础倍率
    public static final double MERCURY_PERIOD_BASE_RATE = 20;
    //星体名称字体大小
    public static final int NAME_FONT_SIZE = 100;
    //定时器间隔毫秒
    public static final int TIMER_INTERVAL = 10;
    // 缩放控制
    public static double zoomScale = 1.0;
    public static final double ZOOM_INCREMENT = 0.1;
    public static final double MIN_ZOOM = 0.3;
    public static final double MAX_ZOOM = 3.0;
}
