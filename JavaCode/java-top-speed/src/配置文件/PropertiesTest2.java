package 配置文件;

//TODO 目标:掌握把键值对数据存入到属性文件中去

import java.io.FileWriter;
import java.util.Properties;

public class PropertiesTest2 {
    public static void main(String[] args) throws Exception {
        //1.创建Properties对象出来,先用它存储一些键值对数据
        Properties properties = new Properties();
        properties.setProperty("张无忌", "minmin");
        properties.setProperty("殷素素", "cuishan");
        properties.setProperty("张翠山", "susu");

        //2.把Properties对象中的键值对数据存入到属性文件中去
        //  方法执行完成后会自动关闭管道,不需要手动关闭
        properties.store(new FileWriter("src/users2.properties"), "i saved many users!"); //相对路径/绝对路径，注释
    }
}
