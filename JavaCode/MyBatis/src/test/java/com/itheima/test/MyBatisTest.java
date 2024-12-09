package com.itheima.test;

import com.itheima.mapper.BrandMapper;
import com.itheima.pojo.Brand;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MyBatisTest {

    @Test
    public void testSelectAll() throws Exception {
        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        List<Brand> brands = brandMapper.selectAll();
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testSelectById() throws Exception {
        //接收参数
        int id = 1;

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        Brand brand = brandMapper.selectByIdBrand(id);
        System.out.println(brand);

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testSelectByCondition() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //封装对象
//        Brand brand=new Brand();
//        brand.setStatus(status);
//        brand.setCompanyName(companyName);
//        brand.setBrandName(brandName);

        Map map = new HashMap();
        map.put("status", status);
        map.put("companyName", companyName);
        map.put("brandName", brandName);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
//        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
//        List<Brand> brands = brandMapper.selectByCondition(brand);
        List<Brand> brands = brandMapper.selectByCondition(map);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testSelectByConditionSingle() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //封装对象
        Brand brand = new Brand();
//        brand.setStatus(status);
//        brand.setCompanyName(companyName);
//        brand.setBrandName(brandName);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
//        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
//        List<Brand> brands = brandMapper.selectByCondition(brand);

        List<Brand> brands = brandMapper.selectByConditionSingle(brand);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testAdd() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "波导手机";
        String brandName = "波导";
        String description = "手机中的战斗机";
        int ordered = 100;

        //封装对象
        Brand brand = new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);
        brand.setDescription(description);
        brand.setOrdered(ordered);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.add(brand);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testAdd2() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "波导手机";
        String brandName = "波导";
        String description = "手机中的战斗机";
        int ordered = 100;

        //封装对象
        Brand brand = new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);
        brand.setDescription(description);
        brand.setOrdered(ordered);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.add(brand);
        Integer id = brand.getId();
        System.out.println(id);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testUpdate() throws Exception {
        //接收参数
        int status = 0;
        String companyName = "波导手机";
        String brandName = "波导";
        String description = "波导手机,手机中的战斗机";
        int ordered = 200;
        int id = 11;

        //封装对象
        Brand brand = new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);
        brand.setDescription(description);
        brand.setOrdered(ordered);
        brand.setId(id);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        int count = brandMapper.update(brand);
        System.out.println(count);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testDeleteById() throws Exception {
        //接收参数
        int id = 11;

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.deleteById(id);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }

    @Test
    public void testDeleteByIds() throws Exception {
        //接收参数
        int[] ids = {12, 13};

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.deleteByIds(ids);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }
}
