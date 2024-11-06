package chapter10;

public class Java02_Reflect_ClassLoader {
    public static void main(String[] args) throws Exception {

        //TODO 反射 - 类加载器
        //加载类
        //Java中的类主要分为3种:
        //1.Java核心类库中的类:String,Object
        //2.JVM软件开发商
        //3.自己写的类,User,Child
        //类加载器也有3种
        //1.BootClassLoader : 启动类加载器(加载类时,采用操作系统平台语言实现)
        //2.PlatformClassLoader : 平台类加载器
        //3.AppClassLoader : 应用类加载器

        //TODO 获取类的信息
        Class<Student> studentClass = Student.class;
        //获取类的加载器对象
        //应用类加载器
        ClassLoader classLoader = studentClass.getClassLoader();
        System.out.println(classLoader);
        System.out.println(classLoader.getParent()); //当前类加载器的上一级 : 平台类加载器
        System.out.println(classLoader.getParent().getParent()); //当前类加载器的上一级 : 核心类加载器

        Class<String> StringClass = String.class;
        //获取类的加载器对象
        //启动类加载器
        ClassLoader classLoader1 = StringClass.getClassLoader();
        System.out.println(classLoader1);

        //加载Java核心类库 > 平台类库 > 自己的类
    }
}

class Student {

}