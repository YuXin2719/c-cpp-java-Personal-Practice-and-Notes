package chapter08;

import java.io.File;

public class Java02_IO_File {
    public static void main(String[] args) throws Exception {

        //TODO Java IO - 文件流

        //TODO File : 文件类型(文件,文件夹),属于java.io包
        //创建文件对象,使用文件路径关联系统文件
        String filePath = "E:\\c.---c.---java-exercise\\JavaCode\\java-top-speed\\data";
        File file = new File(filePath);
        System.out.println(file);
        //文件对象的操作
        //TODO 判断当前的文件对象是否为文件(确认不是文件夹)
        System.out.println(file.isFile());
        //TODO 判断当前的文件对象是否为文件夹(确认不是文件)
        System.out.println(file.isDirectory());
        //TODO 判断文件对象是否存在关联(指向的文件是否存在)
        System.out.println(file.exists());

        if (file.exists()) {
            //TODO 文件对象存在的情况
            System.out.println("文件对象存在");
            if (file.isFile()) {
                System.out.println("文件对象关联的是一个文件");
                System.out.println(file.getName()); //文件名称
                System.out.println(file.length()); //文件大小
                System.out.println(file.lastModified()); //最后修改时间
                System.out.println(file.getAbsolutePath()); //当前文件的绝对路径
            } else if (file.isDirectory()) {
                System.out.println("文件对象关联的是一个文件夹");
                System.out.println(file.getName()); //文件夹名称
                System.out.println(file.lastModified()); //最后修改时间
                System.out.println(file.getAbsolutePath()); //当前文件夹的绝对路径

                String[] list = file.list(); //当前目录下的每一个文件的名称
                System.out.println("文件夹中的文件:");
                for (String s : list) {
                    System.out.println(s);
                }

                System.out.println("文件夹中的文件对象:");
                File[] files = file.listFiles();
                for (File file1 : files) {
                    System.out.println(file1);
                }

            }
        } else {
            //TODO 文件对象不存在的情况
            System.out.println("文件对象不存在,没有关联成功");
            //TODO 创建多级文件目录
//            file.mkdirs(); //mk表示创建,dir表示目录,s代表可以创建多级目录
            //TODO 创建新文件
//            file.createNewFile();
        }

    }
}
