package chapter08;

import java.io.*;

public class Java08_IO_Exception {
    public static void main(String[] args) {

        //TODO Java IO
        //FileNotFoundException
        FileInputStream in = null;
        //ClassNotFoundException, NotSerializableException
        ObjectInputStream objectIn = null;
        ObjectOutputStream objOut = null;

        try {
            in = new FileInputStream("xxx");

            in.read();
//            objOut.writeObject();
            objectIn.readObject();
        } catch (Exception e) {
        } finally {
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }


    }
}
