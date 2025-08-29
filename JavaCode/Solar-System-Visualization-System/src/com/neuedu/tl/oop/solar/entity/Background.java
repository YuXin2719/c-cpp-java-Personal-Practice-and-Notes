package com.neuedu.tl.oop.solar.entity;

import com.neuedu.tl.oop.solar.util.ImageUtil;

import java.awt.*;

import static com.neuedu.tl.oop.solar.constant.Constent.PANEL_WIDTH;

public class Background extends AbstractSolarObject{
    public Background() {
        this.x = 0;
        this.y = 0;
        this.img = ImageUtil.getImage("com/neuedu/tl/oop/solar/img/星空背景.png");
    }
    public Background(int x, int y) {
        this.x = x;
        this.y = y;
        this.img = ImageUtil.getImage("com/neuedu/tl/oop/solar/img/星空背景.png");
    }

    @Override
    public void draw(Graphics g) {
            g.drawImage(img,x,y,PANEL_WIDTH,PANEL_WIDTH,null);
    }

    public void drawBlack(Graphics g){
        g.setColor(Color.BLACK);
        g.fillRect(0,0,PANEL_WIDTH,PANEL_WIDTH);
    }
}
