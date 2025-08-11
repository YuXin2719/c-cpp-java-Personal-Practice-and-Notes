package com.easyjava.bean;

import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class TableInfo {
    //表名
    private String tableName;

    //bean名称
    private String beanName;

    //参数名称
    private String BeanParamName;

    //表注释
    private String comment;

    //字段信息
    private List<FieldInfo> fieldList;

    //唯一索引集合
    private Map<String, List<FieldInfo>> keyIndexMap=new LinkedHashMap<>();

    //是否有date类型
    private boolean haveDate;

    //是否有时间类型
    private boolean haveDateTime;

    //是否有bigdecimal类型
    private boolean haveBigDecimal;

    public Map<String, List<FieldInfo>> getKeyIndexMap() {
        return keyIndexMap;
    }

    public void setKeyIndexMap(Map<String, List<FieldInfo>> keyIndexMap) {
        this.keyIndexMap = keyIndexMap;
    }

    public String getTableName() {
        return tableName;
    }

    public void setTableName(String tableName) {
        this.tableName = tableName;
    }

    public String getBeanName() {
        return beanName;
    }

    public void setBeanName(String beanName) {
        this.beanName = beanName;
    }

    public String getBeanParamName() {
        return BeanParamName;
    }

    public void setBeanParamName(String beanParamName) {
        BeanParamName = beanParamName;
    }

    public String getComment() {
        return comment;
    }

    public void setComment(String comment) {
        this.comment = comment;
    }

    public List<FieldInfo> getFieldList() {
        return fieldList;
    }

    public void setFieldList(List<FieldInfo> fieldList) {
        this.fieldList = fieldList;
    }

    public boolean getHaveDate() {
        return haveDate;
    }

    public void setHaveDate(boolean haveDate) {
        this.haveDate = haveDate;
    }

    public boolean getHaveDateTime() {
        return haveDateTime;
    }

    public void setHaveDateTime(boolean haveDateTime) {
        this.haveDateTime = haveDateTime;
    }

    public boolean getHaveBigDecimal() {
        return haveBigDecimal;
    }

    public void setHaveBigDecimal(boolean haveBigDecimal) {
        this.haveBigDecimal = haveBigDecimal;
    }
}
