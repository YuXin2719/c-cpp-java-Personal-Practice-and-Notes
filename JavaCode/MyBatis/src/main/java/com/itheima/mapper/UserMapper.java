package com.itheima.mapper;

import com.itheima.pojo.User;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import javax.jws.soap.SOAPBinding;
import java.util.Collection;
import java.util.List;

public interface UserMapper {

    List<User> selectAll();

    @Select("select * from tb_user where id = #{id}")
    User selectById(int id);

    //TODO 多个参数查询 : 封装为Map集合,可以使用@Param注解,替换Map集合中默认的arg键名(param不会被修改)
    //   map.put("arg0",参数值1)
    //   map.put("param1",参数值1)
    //   map.put("arg1",参数值2)
    //   map.put("param2",参数值2)
    User select(@Param("username")String username, @Param("password")String password);
    User select(Collection collection);

}
