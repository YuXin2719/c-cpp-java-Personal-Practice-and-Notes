package com.neuedu.tl.oop.solar.entity;

import com.neuedu.tl.oop.solar.util.ImageUtil;

import java.awt.*;
import java.util.Random;

import static com.neuedu.tl.oop.solar.constant.Constent.*;

public class Asteroid {
    // 静态变量：所有小行星共享的图片，这里用太阳的照片方便观察
    private static final Image ASTEROID_IMG = ImageUtil.getImage("com/neuedu/tl/oop/solar/img/太阳.png");
    private static final int CENTER_X = SUN_X + SUN_WIDTH / 2;
    private static final int CENTER_Y = SUN_Y + SUN_WIDTH / 2;

    // 轨道参数（静态计算）
    private final double orbitRadius;  // 轨道半径
    private double angle;              // 当前角度
    private final double angularSpeed; // 角速度（弧度/帧）
    private final int size;            // 小行星大小
    private final int x;               // 计算后的位置
    private final int y;

    // 构造方法
    public Asteroid(double minRadius, double maxRadius, double speed, int size) {
        // 随机生成轨道半径（在火星和木星轨道之间）
        this.orbitRadius = minRadius + (maxRadius - minRadius) * Math.random(); // 随机生成轨道半径

        // 随机初始角度
        this.angle = Math.random() * 2 * Math.PI;

        // 角速度 = 基础速度 * 随机系数（0.8-1.2）
        this.angularSpeed = speed * (0.8 + Math.random() * 0.4);

        this.size = size;

        // 预计算初始位置
        int[] pos = calculatePosition(orbitRadius, angle);
        this.x = pos[0];
        this.y = pos[1];
    }

    // 静态方法：位置计算（避免每次move都重复计算）
    private int[] calculatePosition(double radius, double angle) {
        int posX = (int)(CENTER_X + radius * Math.cos(angle)) - size/2;
        int posY = (int)(CENTER_Y + radius * Math.sin(angle)) - size/2;
        return new int[]{posX, posY};
    }

    // 移动方法
    public void move() {
        angle += angularSpeed;
        if (angle > 2 * Math.PI) angle -= 2 * Math.PI;
    }

    // 绘制方法（极简）
    public void draw(Graphics g) {
        int[] pos = calculatePosition(orbitRadius, angle);
        g.drawImage(ASTEROID_IMG, pos[0], pos[1], size, size, null);
    }
}