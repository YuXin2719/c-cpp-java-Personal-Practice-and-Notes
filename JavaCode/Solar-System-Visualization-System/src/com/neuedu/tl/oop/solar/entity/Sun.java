package com.neuedu.tl.oop.solar.entity;

import com.neuedu.tl.oop.solar.util.ImageUtil;

import java.awt.*;

import static com.neuedu.tl.oop.solar.constant.Constent.*;

public class Sun extends AbstractSolarObject{
    public Sun() {
        this("太阳","com/neuedu/tl/oop/solar/img/太阳.png",SUN_X,SUN_Y,SUN_WIDTH);
    }
    public Sun(String name,String img_path,int x,int y,int width){
        this.x = x;
        this.y = y;
        this.name = name;
        this.width=width;
        this.img = ImageUtil.getImage(img_path);
    }

    @Override
    public void draw(Graphics g) {
        g.drawImage(img,x,y,width,width,null);
        //在太阳下方用白字展示名称
        g.setColor(Color.WHITE);
        //设置字号
        g.setFont(new Font("宋体",Font.BOLD,NAME_FONT_SIZE));
        g.drawString(name,x+width/2-NAME_FONT_SIZE,y+width);
    }
}
