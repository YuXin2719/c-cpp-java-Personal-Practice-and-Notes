package chapter08;

import java.io.*;

public class Java06_IO_File_Copy_String_1 {
    public static void main(String[] args) {

        //TODO Java IO - 文件复制 - 字符串

        //TODO 数据源文件对象
        File srcfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt");
        //TODO 数据目的地文件对象(自动生成文件)
        File destfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt.copy");

        //TODO 字符输入流(管道对象)
        BufferedReader reader = null;
        //TODO 字符输出流(管道对象)
        PrintWriter writer = null; //打印输出流
        try {
            reader = new BufferedReader(new FileReader(srcfile)); //通过字符的方式读取文件
            writer = new PrintWriter(destfile);

            //TODO 打开阀门,流转数据(输入)
            //读取文件中的一行数据(字符串)
            String line = null;

            StringBuilder ss = new StringBuilder();

            while ((line = reader.readLine()) != null) {
                System.out.println(line);
                writer.println(line);
            }
            //刷写数据
            writer.flush(); //把内部缓冲区的数据全部强制输出到目的地

            //Unicode编码
            //byte => -128 ~ 127
            //ascii码 => 0 ~ 127

        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if (writer != null) {
                writer.close();
            }
        }


    }
}
