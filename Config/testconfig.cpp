#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Config.h"

int main()
{
	// 打开一个写文件流指向 config.ini 文件
	std::string strConfigFileName("config.ini");
	std::ofstream out(strConfigFileName);
	// 初始化写入注释
	out << "# test for config read and write\n";
	// 写入一对配置记录： name = wangying
	out << "name = wangying\n";
	out.close();

	// 初始化 Config 类
	Config config(strConfigFileName);

	// 读取键值
	std::string strKey = "name";
	std::string strValue;
	strValue = config.Read<std::string>(strKey);
	std::cout << "Read Key " << strKey << "'s Value is " 
		 << strValue << std::endl;

	// 写入新键值对
	std::string strNewKey = "age";
	std::string strNewValue = "23";
	config.Add<std::string>(strNewKey, strNewValue);

	// 将 Config 类的修改写入文件
	out.open(strConfigFileName, std::ios::app);
	if (out.is_open()) {
		// 利用 Config 类的 << 重载运算符
		out << config;
		std::cout << "Write config content success!" << std::endl;
	}
	out.close();

	system("pause");
	return 0;
}
