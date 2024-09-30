package chapter04;

public class Java17_Object_Access_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 访问权限
        Person17 person = new Person17();

        //private:同类
        //default:同类,同包(路径)
        //protected:同类,同包(路径),子类(优先保护和自己直接相关的子类)
        //public:公共的
        //所谓的访问权限,其实就是访问属性,方法的权力和限制
        //谁访问? Java17_Object_Access_1 -> super -> java.long.Object
        //访问谁的? Person17 -> super -> java.long.Object(clone)
//        Person.clone(); //所有类的父类都有Object类,clone是Object的一个protected方法,按理说子类可以访问,这里为什么不能用呢
    }
}

class Person17 {
    void test() throws Exception {
        clone();
    }
}