package 配置文件;

//TODO 目标:掌握使用Don4j框架解析XML文件

import org.dom4j.Attribute;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

import java.util.List;

public class Dom4jTest1 {
    public static void main(String[] args) throws Exception {
        //1.创建一个Dom4j框架提供的解析起对象
        SAXReader saxReader = new SAXReader();

        //2.使用saxReader对象需要解析的XML文件读成一个Document对象
        Document document = saxReader.read("src/特殊文件/helloworld.xml");

        //3.从文件对象中解析XML文件的全部数据了
        Element root = document.getRootElement();
        System.out.println(root.getName());

        //4.获取根元素下的全部一级子元素
//        List<Element> elements = root.elements();
        //获取指定名字的子元素
        List<Element> elements = root.elements("user");
        for (Element element : elements) {
            System.out.println(element.getName());
        }

        //5.获取当前元素下的某个子元素
        Element people = root.element("people");
        System.out.println(people.getText());

        //如果下面有很多子元素user,默认获取第一个
        Element user = root.element("user");
        System.out.println(user.elementText("name"));

        //6.获取元素的属性信息
        System.out.println(user.attributeValue("id"));
        Attribute id = user.attribute("id");
        System.out.println(id.getName());
        System.out.println(id.getValue());

        List<Attribute> attributes = user.attributes();
        for (Attribute attribute : attributes) {
            System.out.println(attribute.getName() + "=" + attribute.getValue());
        }

        //7.如何获取全部的文本内容:获取当前元素下的子元素文本值
        System.out.println(user.elementText("name"));
        System.out.println(user.elementText("地址"));
        System.out.println(user.elementText("password"));

        Element data = user.element("data");
        System.out.println(data.getText());
        System.out.println(data.getTextTrim()); //取出文本并且取去除前后空格
    }
}
