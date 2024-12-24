package cn.tlrj.util;

import com.ghgande.j2mod.modbus.ModbusException;
import com.ghgande.j2mod.modbus.facade.ModbusSerialMaster;
import com.ghgande.j2mod.modbus.procimg.Register;
import com.ghgande.j2mod.modbus.util.SerialParameters;

public class QuShu {
    public static void main(String[] args) {
        SerialParameters params = new SerialParameters();
        params.setPortName("COM11"); // 设置串口名称，根据实际情况修改
        params.setBaudRate(9600); // 设置波特率
        params.setDatabits(8); // 设置数据位
        params.setParity("None"); // 设置校验位
        params.setStopbits(1); // 设置停止位
        params.setEncoding("rtu"); // 设置编码方式为RTU
        params.setEcho(false); // 设置是否回显

        // 创建ModbusRTU传输对象
        ModbusSerialMaster master = null;
        try {
            master = new ModbusSerialMaster(params);
            master.connect(); // 连接串口

            int unitId = 1; // Modbus设备地址
            int ref = 0; // 寄存器起始地址
            int count = 2; // 读取的寄存器数量

            while (true) {
                // 读取保持寄存器
                Register[] registerValues = master.readMultipleRegisters(unitId, ref, count);
                //0   气体值
                //1   状态     1(<20  5   20~49  6 >=50
                Thread.sleep(1000);

                System.out.println("状态码" + registerValues[0]+"========"+"设备阈值:"+registerValues[1]);
                JdbcUtil.update("insert into test values(null,'设备1',?,?)",registerValues[0].getValue(),registerValues[1].getValue());
            }
        } catch (ModbusException e) {
            e.printStackTrace();

        } catch (Exception exception) {
            exception.printStackTrace();
        } finally {
            if (master != null) {
                master.disconnect(); // 断开连接
            }
        }
    }
}

