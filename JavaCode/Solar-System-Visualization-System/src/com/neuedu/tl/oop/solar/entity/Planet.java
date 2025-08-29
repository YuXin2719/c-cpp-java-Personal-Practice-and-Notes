package com.neuedu.tl.oop.solar.entity;

import com.neuedu.tl.oop.solar.util.ImageUtil;

import java.awt.*;

import static com.neuedu.tl.oop.solar.constant.Constent.*;

public class Planet extends AbstractSolarObject {
    // 在Planet类中添加角度变量
    private double angle = 0; // 初始角度为0

    public Planet(String name, String img_path, int width, Double DistenceRate, Double periodRate, Double eccentricity, boolean direction) { //介绍参数： 轨道距离比例，公转周期比例，离心率，公转方向
        //rectangleWidth是轨道矩形长度
        this.width = width;
        this.rectangleWidth = (int) (SUN_WIDTH + 2 * DistenceRate * AU);
        this.rectangleHeight = (int) (rectangleWidth * Math.sqrt(1 - eccentricity * eccentricity)); // 计算轨道矩形宽度
        this.x = SUN_X + (SUN_WIDTH + rectangleWidth - width)/2;
        this.y = SUN_Y + (SUN_WIDTH - width)/2;
        this.name = name;
        this.img = ImageUtil.getImage(img_path);
        this.periodRate = periodRate; // 设置公转周期倍率
        this.eccentricity = eccentricity; // 设置轨道离心率
        this.direction = direction; // 设置公转方向
    }

    public Planet(String name, String img_path, int width, Double DistenceRate, Double periodRate, Double eccentricity, boolean direction,
                  String m_name, String m_img_path, int m_width, Double m_DistenceRate, Double m_periodRate, boolean m_direction) { //介绍参数： 轨道距离比例，公转周期比例，离心率，公转方向
        //rectangleWidth是轨道矩形长度
        this.width = width;
        this.rectangleWidth = (int) (SUN_WIDTH + 2 * DistenceRate * AU);
        this.rectangleHeight = (int) (rectangleWidth * Math.sqrt(1 - eccentricity * eccentricity)); // 计算轨道矩形宽度
        this.x = SUN_X + (SUN_WIDTH + rectangleWidth - width)/2;
        this.y = SUN_Y + (SUN_WIDTH - width)/2;
        this.name = name;
        this.img = ImageUtil.getImage(img_path);
        this.periodRate = periodRate; // 设置公转周期倍率
        this.eccentricity = eccentricity; // 设置轨道离心率
        this.direction = direction; // 设置公转方向

        //rectangleWidth是轨道矩形长度
        this.satelliteSize = m_width;
        this.satelliteRectangleWidth = (int) (this.width + 2 * m_DistenceRate * AU);
        this.satelliteX = x + (this.width - satelliteRectangleWidth - satelliteSize)/2;
        this.satelliteY = y + (this.width - satelliteRectangleWidth - satelliteSize)/2;
        this.satelliteName = m_name;
        this.satelliteImg = ImageUtil.getImage(m_img_path);
        this.satellitePeriodRate = m_periodRate; // 设置公转周期倍率
        this.satelliteDirection = m_direction; // 设置公转方向
    }

    public void setAngle(double angle){
        this.angle = angle;
    }

    @Override
    public void draw(Graphics g) {
        // 设置黄色
        g.setColor(Color.YELLOW);
        //绘制星体的轨道
        g.drawOval(SUN_X + (SUN_WIDTH - rectangleWidth)/2, SUN_Y + (SUN_WIDTH - rectangleHeight)/2, rectangleWidth, rectangleHeight);
        //在星球上绘制星体名称
        g.setColor(Color.WHITE);
        g.setFont(new Font("宋体", Font.BOLD, NAME_FONT_SIZE));
        g.drawString(name, x + (width  - NAME_FONT_SIZE * name.length()) / 2, y - 50);
        //绘制星体
        g.drawImage(img, x, y, width, width, null);
    }

    @Override
    public void move() {
        // 计算角度增量，速度由periodRate控制
        double angleIncrement = (direction ? 1 : -1) * (2 * Math.PI) / (periodRate * MERCURY_PERIOD_BASE_RATE * 365);
        angle += angleIncrement;

        // 计算椭圆轨道上的位置
        double semiMajorAxis = rectangleWidth / 2.0;  // 半长轴
        double semiMinorAxis = rectangleHeight / 2.0; // 半短轴

        // 椭圆参数方程计算坐标
        double orbitX = semiMajorAxis * Math.cos(angle);
        double orbitY = semiMinorAxis * Math.sin(angle);

        // 计算相对于太阳中心的位置
        int centerX = SUN_X + SUN_WIDTH / 2;
        int centerY = SUN_Y + SUN_WIDTH / 2;

        // 更新行星位置
        this.x = (int) (centerX + orbitX - width / 2);
        this.y = (int) (centerY + orbitY - width / 2);
    }

    public void MoonDraw(Graphics g) {
        // 设置黄色
        g.setColor(Color.GREEN);
        //绘制星体的轨道
        g.drawOval(x + (width - satelliteRectangleWidth)/2, y + (width - satelliteRectangleWidth)/2, satelliteRectangleWidth, satelliteRectangleWidth);
        //在星球上绘制星体名称
        g.setColor(Color.WHITE);
        g.setFont(new Font("宋体", Font.BOLD, NAME_FONT_SIZE-30));
        g.drawString(satelliteName, satelliteX + (satelliteSize  - (NAME_FONT_SIZE-30) * satelliteName.length()) / 2, satelliteY - 50);
        //绘制星体
        g.drawImage(satelliteImg, satelliteX, satelliteY, satelliteSize, satelliteSize, null);
    }

    //卫星初始角度
    private double moonAngle = 0;

    public void MoonMove() {
        double angleIncrement = (satelliteDirection ? 1 : -1) * (2 * Math.PI) / (satellitePeriodRate * MERCURY_PERIOD_BASE_RATE * 365);
        moonAngle += angleIncrement;

            // 计算轨道半径（矩形宽度的一半减去月球大小的一半）
            double orbitRadius = (satelliteRectangleWidth - satelliteSize) / 2.0;

            // 计算月球在轨道上的新位置
            int centerX = x + width / 2;
            int centerY = y + width / 2;

            satelliteX = (int) (centerX + orbitRadius * Math.cos(angle));
            satelliteY = (int) (centerY + orbitRadius * Math.sin(angle));
    }
}
