package com.itheima.mapper;

import com.itheima.pojo.Brand;
import com.itheima.pojo.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface BrandMapper {

    //TODO 查询所有
    List<Brand> selectAll();

    //TODO 查看详情:根据ID查看详情
    Brand selectByIdBrand(int id);

    //TODO 条件查询
    //  参数接收
    //      1.散装参数 : 如果这个方法中有多个参数,需要使用@Param("SQL参数占位符名称")
    //      2.对象参数 : 对象的属性名称要和参数占位符名称一致
    //      3.map集合参数
//    List<Brand> selectByCondition(@Param("status") int status, @Param("companyName")String companyName, @Param("brandName")String brandName);

//    List<Brand> selectByCondition(Brand brand);

    List<Brand> selectByCondition(Map map);

    //TODO 单条件动态查询
    List<Brand> selectByConditionSingle(Brand brand);

    //TODO 添加
    void add(Brand brand);

}
