package 特殊文件;

//TODO 目标:如何使用程序把数据写出到XML文件中去
/*
<?xml version="1.0" encoding="UTF-8" ?>
<book>
    <name>从入门到跑路</name>
    <author>dlei</author>
    <price>999.9</price>
</book>
 */

import netscape.security.UserTarget;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Dom4jTest2 {
    public static void main(String[] args) {
        //1.使用一个Stringbuilder对象来拼接XML格式的数据
        StringBuilder sb = new StringBuilder();
        sb.append("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\r\n");
        sb.append("<book>\r\n");
        sb.append("\t<name>").append("从入门到跑路").append("</name>\r\n");
        sb.append("\t<author>").append("dlei").append("</author>\r\n");
        sb.append("\t<price>").append("999.9").append("</price>\r\n");
        sb.append("</book>\r\n");

        //放在小括号内自动关闭
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("src/特殊文件/book.xml"))) {
            bw.write(sb.toString());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}