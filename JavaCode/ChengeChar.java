//转义字符演示
public class ChengeChar {

	public static void main(String[] args) {

		System.out.println("北京\t天津\t山西");

		System.out.println("北京\n天津\n山西");

		System.out.println("北京\\天津");

		System.out.println("北京\"天津");

		System.out.println("北京\'天津");

		System.out.println("韩顺平教育\r天津");
		//解读
		//1.输出韩顺平教育
		//2.\r表示回车，不是换行，此时光标回到“输”的位置
		//3.然后“天津”替代掉“韩顺”输出：天津平教育
		//注：ctrl+z上一步  ctrl+shift+z下一步

	}
	
}