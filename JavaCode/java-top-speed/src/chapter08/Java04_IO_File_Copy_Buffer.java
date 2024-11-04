package chapter08;

import java.io.*;

public class Java04_IO_File_Copy_Buffer {
    public static void main(String[] args) {

        //TODO Java IO - 文件复制 - 缓冲

        //TODO 数据源文件对象
        File srcfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt");
        //TODO 数据目的地文件对象(自动生成文件)
        File destfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt.copy");

        //TODO 文件输入流(管道对象)
        //TODO 文件输出流(管道对象)
        FileInputStream in = null;
        FileOutputStream out = null;

        //TODO 缓冲输入流(管道对象)
        //TODO 缓冲输出流(管道对象)
        BufferedInputStream buffin = null;
        BufferedOutputStream buffout = null;

        //TODO 缓冲区(水桶)
        byte[] cache = new byte[1024];

        try {
            in = new FileInputStream(srcfile);
            out = new FileOutputStream(destfile);

            buffin = new BufferedInputStream(in);
            buffout = new BufferedOutputStream(out);

            //TODO 打开阀门,流转数据(输入)
            int data = -1;

            while ((data = buffin.read(cache)) != -1) {
                buffout.write(cache, 0, data); //从缓冲区的0开始写,然后把data全部写完(意味着缓冲区没满也可以将装进去的一部分数据写出去)
                //最后只循环1次,Java03中的循环写入需要循环5次
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if (buffin != null) {
                try {
                    buffin.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if (buffout != null) {
                try {
                    buffout.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }


    }
}
