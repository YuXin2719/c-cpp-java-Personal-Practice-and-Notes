package com.neuedu.tl.oop.solar.entity;

import java.awt.*;

//太阳系中所有星体
public abstract class AbstractSolarObject implements IMoveable,IDrawable{
    public int x;
    public int y;
    public Image img;
    //天体名称
    public String name;
    //天体大小
    public int width;
    //天体轨道矩形长度
    public int rectangleWidth;
    //天体轨道矩形宽度
    public int rectangleHeight;
    //公转周期倍率
    public double periodRate;
    //轨道离心率
    public double eccentricity;
    //公转方向
    public boolean direction = true;

    //卫星大小
    public int satelliteSize;
    //卫星轨道矩形长度
    public int satelliteRectangleWidth;
    //卫星坐标
    public int satelliteX;
    public int satelliteY;
    //卫星名称
    public String satelliteName;
    //卫星图片
    public Image satelliteImg;
    //卫星公转周期倍率
    public double satellitePeriodRate;
    //卫星公转方向
    public boolean satelliteDirection = true;

    @Override
    public void move() {

    }

//    @Override
//    public void draw(Graphics g) {
//
//    }
}
