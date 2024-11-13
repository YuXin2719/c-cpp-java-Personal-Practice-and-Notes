package 配置文件;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.Properties;

public class PropertiesTest3 {
    public static void main(String[] args) throws Exception {
        //TODO 目标:读取属性文件,判断是否存在李方,存在年龄改成18
        // users.txt里面就是一个一个的键值对,那他就是属性文件,无所谓什么后缀的

        //1.加载属性文件的键值对到程序中来
        Properties properties = new Properties(); // { }

        //2.开始加载
        properties.load(new FileReader("src/特殊文件/users.txt"));

        //3.判断是否包含李方这个键
        if (properties.containsKey("李方")) {
            properties.setProperty("李方", "18");
        }

        //4.把Properties对象的键值对数据重新写入到属性文件中去
        properties.store(new FileWriter("src/users.txt"), "success!");
    }
}
