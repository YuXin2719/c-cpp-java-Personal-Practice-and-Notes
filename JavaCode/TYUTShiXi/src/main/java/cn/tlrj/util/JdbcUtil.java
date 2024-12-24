package cn.tlrj.util;

import java.sql.*;

public class JdbcUtil {
    //释放资源;
    public static void close(Statement stmt, Connection conn) {
        if (stmt != null) {
            try {
                stmt.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }
    /**
     * //封装:
     * @param sql sql语句;
     * @param args Object... 表示的是可变数组;
     *
     */
    public static void update(String sql, Object... args) {
        Connection conn=null;
        PreparedStatement pstmt=null;
        try {
            //加载驱动:
            Class.forName("com.mysql.cj.jdbc.Driver");
            //获取连接对象:
            //.var或者是ctrl+alt+v 可以快速返回当前方法的返回值；
            //url:  什么与数据库连接:什么数据库://服务器地址:数据库服务端口号/数据库名字
             conn = DriverManager.getConnection(
                    "jdbc:mysql://127.0.0.1:3306/tlrj?useSSL=false",
                    "root",
                    "admin");
//             sql="insert into t_dev values (5,'设备1',?)";
            //获取执行sql的对象:pstmt
            pstmt = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                pstmt.setObject(i+1, args[i]);
            }
            //i表示的是影响行数: 假如sql没问题正常执行  影响几行;1
            pstmt.executeUpdate();
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            close(pstmt,conn);
        }
    }
}
