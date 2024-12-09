package com.itheima.test;

import com.itheima.mapper.BrandMapper;
import com.itheima.mapper.UserMapper;
import com.itheima.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.InputStream;

public class UserMapperTest {
    @Test
    public void testDeleteByIds() throws Exception {
        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        //4.执行方法
        String username="zhangsan";
        String password="123";

        User user = userMapper.select(username, password);

        System.out.println(user);

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testSelectById() throws Exception {
        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        //4.执行方法
        User user = userMapper.selectById(1);

        System.out.println(user);

        //5.释放资源
        sqlSession.close();

    }
}
