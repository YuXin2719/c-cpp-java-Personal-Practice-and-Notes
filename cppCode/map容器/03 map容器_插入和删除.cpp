//#include<iostream>
//using namespace std;
//#include<map>
//
////map容器的插入和删除
//
//void showMap(map<int, int>m) {
//	for (auto it = m.begin(); it != m.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}
//
//void test01() {
//	map<int, int>m1;
//	//插入数据
//	//方式1
//	m1.insert(pair<int, int>(1, 10));
//	//方式2,推荐,自动类型推导
//	m1.insert(make_pair(2, 20));
//	//方式3,不推荐,效率低
//	m1.insert(map<int, int>::value_type(3, 30));
//	//方式4,利用下标插入,不建议
//	// 因为如果key存在,会覆盖原来的value,而且如果key不存在,会创建一个新的key,value默认值为0
//	// 用途,可以利用key访问到value
//	m1[4] = 40;
//	//遍历map
//	showMap(m1);
//
//	//删除元素
//	m1.erase(m1.begin());
//	m1.erase(2); //根据key删除
//	cout << "删除元素后：" << endl;
//	showMap(m1);
//	m1.erase(m1.begin(), m1.end()); //删除区间
//	cout << "区间删除元素后：" << endl;
//	showMap(m1);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}