package com.easyjava.bean;

import com.easyjava.utils.PropertiesUtils;

public class Constants {

    public static String AUTHER_COMMENT;

    public static boolean IGNORE_TABLE_PREFIX;

    public static String SUFFIX_BEAN_QUERY;

    public static String SUFFIX_BEAN_QUERY_FUZZY;

    public static String SUFFIX_BEAN_QUERY_TIME_START;
    public static String SUFFIX_BEAN_QUERY_TIME_END;

    public static String SUFFIX_MAPPERS;

    //需要忽略的属性
    public static String IGNORE_BEAN_TOJSON_FILED;
    public static String IGNORE_BEAN_TOJSON_EXPRESSION;
    public static String IGNORE_BEAN_TOJSON_CLASS;

    //日期序列化，反序列化
    public static String BEAN_DATE_FORMAT_EXPRESSION;
    public static String BEAN_DATE_FORMAT_CLASS;

    public static String BEAN_DATE_UNFORMAT_EXPRESSION;
    public static String BEAN_DATE_UNFORMAT_CLASS;

    public static String PATH_JAVA = "java";

    public static String PATH_RESOURCES = "resources";

    public static String PACKAGE_BASE;

    public static String PACKAGE_PO;

    public static String PACKAGE_QUERY;

    public static String PACKAGE_MAPPERS;

    public static String PACKAGE_UTILS;

    public static String PACKAGE_ENUMS;

    public static String PATH_ENUMS;

    public static String PATH_BASE;

    public static String PATH_PO;

    public static String PATH_QUERY;

    public static String PATH_UTILS;

    public static String PATH_MAPPERS;

    static {

        AUTHER_COMMENT = PropertiesUtils.getString("author.comment");

        IGNORE_BEAN_TOJSON_FILED = PropertiesUtils.getString("ignore.bean.tojson.filed");
        IGNORE_BEAN_TOJSON_EXPRESSION = PropertiesUtils.getString("ignore.bean.tojson.expression");
        IGNORE_BEAN_TOJSON_CLASS = PropertiesUtils.getString("ignore.bean.tojson.class");

        //日期序列化，反序列化
        BEAN_DATE_FORMAT_EXPRESSION = PropertiesUtils.getString("bean.date.format.expression");
        BEAN_DATE_FORMAT_CLASS = PropertiesUtils.getString("bean.date.format.class");

        BEAN_DATE_UNFORMAT_EXPRESSION = PropertiesUtils.getString("bean.date.unformat.expression");
        BEAN_DATE_UNFORMAT_CLASS = PropertiesUtils.getString("bean.date.unformat.class");

        IGNORE_TABLE_PREFIX = Boolean.valueOf(PropertiesUtils.getString("ignore.talble.prefix"));
        SUFFIX_BEAN_QUERY = PropertiesUtils.getString("suffix.bean.query");

        PATH_BASE = PropertiesUtils.getString("path.base");
        PATH_BASE = PATH_BASE + PATH_JAVA + "/" + PropertiesUtils.getString("package.base").replace(".", "/");

        PATH_PO = PATH_BASE + "/" + PropertiesUtils.getString("package.po").replace(".", "/");

        PACKAGE_BASE = PropertiesUtils.getString("package.base");
        PACKAGE_PO = PACKAGE_BASE + "." + PropertiesUtils.getString("package.po");

        PACKAGE_UTILS = PACKAGE_BASE + "." + PropertiesUtils.getString("package.utils");
        PATH_UTILS = PATH_BASE + "/" + PropertiesUtils.getString("package.utils").replace(".", "/");

        PACKAGE_ENUMS = PACKAGE_BASE + "." + PropertiesUtils.getString("package.enums");
        PATH_ENUMS = PATH_BASE + "/" + PropertiesUtils.getString("package.enums").replace(".", "/");

        PACKAGE_QUERY = PACKAGE_BASE + "." + PropertiesUtils.getString("package.query");
        PATH_QUERY = PATH_BASE + "/" + PropertiesUtils.getString("package.query").replace(".", "/");

        SUFFIX_BEAN_QUERY_FUZZY = PropertiesUtils.getString("suffix.bean.query.fuzzy");

        SUFFIX_BEAN_QUERY_TIME_START = PropertiesUtils.getString("suffix.bean.query.time.start");
        SUFFIX_BEAN_QUERY_TIME_END = PropertiesUtils.getString("suffix.bean.query.time.end");

        SUFFIX_MAPPERS = PropertiesUtils.getString("suffix.mappers");

        PACKAGE_MAPPERS = PACKAGE_BASE + "." + PropertiesUtils.getString("package.mappers");
        PATH_MAPPERS = PATH_BASE + "/" + PropertiesUtils.getString("package.mappers").replace(".", "/");
    }

    public final static String[] SQL_DATE_TIME_TYPES = new String[]{"timestamp", "datetime"};

    public final static String[] SQL_DATE_TYPES = new String[]{"date"};

    public static final String[] SQL_DECIMAL_TYPE = new String[]{"decimal", "double", "float"};

    public static final String[] SQL_STRING_TYPE = new String[]{"varchar", "char", "text", "mediumtext", "longtext"};

    //Integer
    public static final String[] SQL_INTEGER_TYPE = new String[]{"int", "tinyint"};

    //Long
    public static final String[] SQL_LONG_TYPE = new String[]{"bigint"};

    public static void main(String[] args) {
        System.out.println(PACKAGE_BASE);
    }

}
