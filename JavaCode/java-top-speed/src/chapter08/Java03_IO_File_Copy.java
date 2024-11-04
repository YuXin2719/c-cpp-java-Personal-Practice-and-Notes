package chapter08;

import java.io.*;

public class Java03_IO_File_Copy {
    public static void main(String[] args) {

        //TODO Java IO - 文件复制

        //TODO 数据源文件对象
        File srcfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt");
        //TODO 数据目的地文件对象(自动生成文件)
        File destfile = new File("E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data\\word.txt.copy");

        //TODO 文件输入流(管道对象)
        //TODO 文件输出流(管道对象)
        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            in = new FileInputStream(srcfile);
            out = new FileOutputStream(destfile);

            //TODO 打开阀门,流转数据(输入)
            int data = -1;
            //TODO 打开阀门,流转数据(输出)
            out.write(data);

            //TODO 问题1 : 代码重复性比较强
            //TODO 问题2 : 多读数据
//            data = in.read();
//            out.write(data);
//
//            data = in.read();
//            out.write(data);
//
//            data = in.read();
//            out.write(data);
//
//            data = in.read();
//            out.write(data);
//
//            //TODO 如果文件数据已经全部读取完毕后,那么再去读取数据,读取的结果就是-1,表示无效(结尾)
//            data = in.read();
//            if (data != -1) {
//                out.write(data);
//            }
////            System.out.println(data); //这里data是-1
            while ((data = in.read()) != -1) {
                out.write(data);
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if (out != null) {
                try {
                    out.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }


    }
}
