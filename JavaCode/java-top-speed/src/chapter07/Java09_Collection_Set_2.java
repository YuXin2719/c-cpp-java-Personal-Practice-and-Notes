package chapter07;

import javax.jws.soap.SOAPBinding;
import java.util.HashSet;

public class Java09_Collection_Set_2 {
    public static void main(String[] args) {

        //TODO 集合 - Collection - set
        //HashSet 底层数据结构为 数组 + 链表

        HashSet set = new HashSet();

        User9 user1 = new User9();
        user1.id = 1001;
        user1.name = "zhangsan";
        System.out.println(user1.hashCode()); //hashCode值可以类比为内存地址,user1和user2内存地址不一样,所以这里hash算法认为是两个不同的对象

        User9 user2 = new User9();
        user2.id = 1001;
        user2.name = "wangwu";
        System.out.println(user2.hashCode());

        User9 user3 = new User9();
        user3.id = 1002;
        user3.name = "lisi";
        System.out.println(user3.hashCode());

        set.add(user1);
        set.add(user2);
        set.add(user3);

        System.out.println(set);

    }
}

class User9 {
    public int id;
    public String name;

    @Override
    //类似于内存地址
    public int hashCode() {
        return id;
    }

    @Override
    //判断两个对象的属性是否完全相同
    public boolean equals(Object obj) {
        if (obj instanceof User9) {
            User9 otherUser = (User9) obj;
            if (otherUser.id == this.id) {
                if (otherUser.name.equals(this.name)) {
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        return "User[" + id + "," + name + "]";
    }
}