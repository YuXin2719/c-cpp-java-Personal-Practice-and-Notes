package com.neuedu.tl.oop.solar.client;

import com.neuedu.tl.oop.solar.entity.*;
import com.neuedu.tl.oop.solar.util.ImageUtil;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.List;
import java.util.ArrayList;

import static com.neuedu.tl.oop.solar.constant.Constent.*;

public class SolarSystemClient extends JFrame {
    // 内容面板，用于绘制太阳系的天体
    private JPanel contentPanel;
    // 在类成员变量中添加
    private List<Asteroid> asteroids = new ArrayList<>();

    //暂停变量
    private boolean isPaused = false;

    // 预创建对象
    private Background background = new Background();
    private Sun sun = new Sun();
    private Planet mercury = new Planet("水星", "com/neuedu/tl/oop/solar/img/水星.png", MERCURY_WIDTH, MERCURY_CENTRIFUGAL_RATE, MERCURY_PERIOD_RATE, MERCURY_ECCENTRICITY, MERCURY_DIRECTION);
    private Planet venus = new Planet("金星", "com/neuedu/tl/oop/solar/img/金星.png", VENUS_WIDTH, VENUS_CENTRIFUGAL_RATE, VENUS_PERIOD_RATE, VENUS_ECCENTRICITY, VENUS_DIRECTION);
    //同时创建地球和月球对象
    private Planet earth = new Planet("地球", "com/neuedu/tl/oop/solar/img/地球.png", EARTH_WIDTH, EARTH_CENTRIFUGAL_RATE, EARTH_PERIOD_RATE, EARTH_ECCENTRICITY, EARTH_DIRECTION,
            "月球", "com/neuedu/tl/oop/solar/img/月亮.png",MOON_WIDTH, MOON_CENTRIFUGAL_RATE, MOON_PERIOD_RATE, MOON_DIRECTION);
    private Planet mars = new Planet("火星", "com/neuedu/tl/oop/solar/img/火星.png", MARS_WIDTH, MARS_CENTRIFUGAL_RATE, MARS_PERIOD_RATE, MARS_ECCENTRICITY, MARS_DIRECTION);
    private Planet jupiter = new Planet("木星", "com/neuedu/tl/oop/solar/img/木星.png", JUPITER_WIDTH, JUPITER_CENTRIFUGAL_RATE, JUPITER_PERIOD_RATE, JUPITER_ECCENTRICITY, JUPITER_DIRECTION);
    private Planet saturn = new Planet("土星", "com/neuedu/tl/oop/solar/img/土星.png", SATURN_WIDTH, SATURN_CENTRIFUGAL_RATE, SATURN_PERIOD_RATE, SATURN_ECCENTRICITY, SATURN_DIRECTION);
    private Planet uranus = new Planet("天王星", "com/neuedu/tl/oop/solar/img/天王星.png", URANUS_WIDTH, URANUS_CENTRIFUGAL_RATE, URANUS_PERIOD_RATE, URANUS_ECCENTRICITY, URANUS_DIRECTION);
    private Planet neptune = new Planet("海王星", "com/neuedu/tl/oop/solar/img/海王星.png", NEPTUNE_WIDTH, NEPTUNE_CENTRIFUGAL_RATE, NEPTUNE_PERIOD_RATE, NEPTUNE_ECCENTRICITY, NEPTUNE_DIRECTION);

    // 加载窗体的方法
    public void loadFrame() {
        // 使用JScrollPane
        JScrollPane scrollPane = new JScrollPane(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        // 初始化小行星带 (使用静态优化的Asteroid类)
        for (int i = 0; i < ASTEROID_COUNT; i++) {
            asteroids.add(new Asteroid(
                    ASTEROID_MIN_RADIUS,
                    ASTEROID_MAX_RADIUS,
                    ASTEROID_SPEED,
                    ASTEROID_SIZE
            ));
        }

        // 创建自定义面板
        contentPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                // 使用 Graphics2D 进行缩放
                Graphics2D g2d = (Graphics2D) g;
                g2d.scale(zoomScale, zoomScale);

                // 绘制背景（纯黑背景）
                background.drawBlack(g2d);

                // 绘制太阳
                sun.draw(g2d);

                // 绘制行星
                mercury.draw(g2d);
                venus.draw(g2d);
                earth.draw(g2d);
                mars.draw(g2d);
                jupiter.draw(g2d);
                saturn.draw(g2d);
                uranus.draw(g2d);
                neptune.draw(g2d);
                //绘制月球
                earth.MoonDraw(g2d);
                //绘制小行星带
                for (Asteroid asteroid : asteroids) {
                    asteroid.draw(g2d);
                }
                contentPanel.repaint();
            }
        };

        contentPanel.setPreferredSize(new Dimension(PANEL_WIDTH, PANEL_WIDTH));

        // 键盘控制缩放
        contentPanel.setFocusable(true);
        contentPanel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_PLUS:  // "+" 键放大
                        zoomIn();
                        break;
                    case KeyEvent.VK_MINUS: // "-" 键缩小
                        zoomOut();
                        break;
                    case KeyEvent.VK_0:     // "0" 键重置缩放
                        resetZoom();
                        break;
                }
            }
        });

        // 鼠标滚轮控制缩放
        contentPanel.addMouseWheelListener(e -> {
            if (e.getWheelRotation() < 0) { // 滚轮向上（放大）
                zoomIn();
            } else { // 滚轮向下（缩小）
                zoomOut();
            }
        });

        //空格控制暂停播放
        contentPanel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_PLUS:
                        zoomIn();
                        break;
                    case KeyEvent.VK_MINUS:
                        zoomOut();
                        break;
                    case KeyEvent.VK_0:
                        resetZoom();
                        break;
                    case KeyEvent.VK_SPACE:  // 添加空格键处理
                        isPaused = !isPaused;
                        break;
                }
            }
        });


        // 添加定时器，控制行星运动
        Timer timer = new Timer(TIMER_INTERVAL, e -> {
            if (!isPaused) {  // 只在非暂停状态下更新
                mercury.move();
                venus.move();
                earth.move();
                mars.move();
                jupiter.move();
                saturn.move();
                uranus.move();
                neptune.move();
                earth.MoonMove();
                for (Asteroid asteroid : asteroids) {
                    asteroid.move();
                }
            }
            contentPanel.repaint();
        });

        timer.start();

        // 添加面板到ScrollPane
        scrollPane.setViewportView(contentPanel);
        this.add(scrollPane);
        // 图标
        this.setIconImage(ImageUtil.getImage("com/neuedu/tl/oop/solar/img/太阳.png"));
        this.setVisible(true);
        this.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
        this.setLocationRelativeTo(null); // 居中显示
        this.setTitle(WINDOW_TITLE);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    // 放大
    private void zoomIn() {
        if (zoomScale < MAX_ZOOM) {
            zoomScale += ZOOM_INCREMENT;
            applyZoom();
        }
    }

    // 缩小
    private void zoomOut() {
        if (zoomScale > MIN_ZOOM) {
            zoomScale -= ZOOM_INCREMENT;
            applyZoom();
        }
    }

    // 重置缩放
    private void resetZoom() {
        zoomScale = 1.0;
        applyZoom();
    }

    // 应用缩放（调整面板大小并重绘）
    private void applyZoom() {
        int newWidth = (int)(PANEL_WIDTH * zoomScale);
        int newHeight = (int)(PANEL_WIDTH * zoomScale);
        contentPanel.setPreferredSize(new Dimension(newWidth, newHeight));
        contentPanel.revalidate(); // 重新计算布局
        contentPanel.repaint();    // 重绘
    }

    public static void main(String[] args) {
        // 在EDT线程中运行Swing组件
        SwingUtilities.invokeLater(() -> {
            new SolarSystemClient().loadFrame();
        });
    }
}