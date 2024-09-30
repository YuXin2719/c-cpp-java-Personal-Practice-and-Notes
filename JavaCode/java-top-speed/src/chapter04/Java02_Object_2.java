package chapter04;

public class Java02_Object_2 {
    public static void main(String[] args) {

        //TODO 面向对象

        Teacher teacher1 = new Teacher();
        teacher1.name = "zhangsan";
        teacher1.teach();

        Sdudent sdudent1 = new Sdudent();
        sdudent1.name = "lisi";
        sdudent1.sdudy();
    }
}

class Teacher {
    String name;

    void teach() {
        System.out.println(name + "老师在讲课");
    }
}

class Sdudent {
    String name;

    void sdudy() {
        System.out.println("学生" + name + "在听课");
    }
}