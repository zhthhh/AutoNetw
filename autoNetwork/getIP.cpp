#include <iostream>
#include "sole.hpp"
#include "getIP.hpp"
#include <fstream>
#include <string>
#include<windows.h>
#include <codecvt>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;


extern std::string line;
extern std::string line1;
extern std::string passw;
extern std::string account;


wstring tPath;

std::string urlEncode(const std::string& value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (char c : value) {
        // 不需要编码的字符：字母、数字、以及一些特殊字符
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // 其他字符需要编码
        escaped << '%' << std::setw(2) << int((unsigned char)c);
    }

    return escaped.str();
}



wstring getAddr(wstring c)
{
    wchar_t buffer[MAX_PATH];


    GetModuleFileName(NULL, buffer, MAX_PATH);


    std::wstring fullPath(buffer);
    wstring b;
    // 找到最后一个反斜杠的位置
    size_t lastSlashPos = fullPath.find_last_of(L"\\");
    if (lastSlashPos != std::wstring::npos) {
        // 截取反斜杠之前的部分，即目录路径
        std::wstring directoryPath = fullPath.substr(0, lastSlashPos + 1);

        std::wstring buff = c;
        std::wstring buff2 = directoryPath + buff;

        // 设置输出流的本地化环境为中文
        std::wcout.imbue(std::locale("chs"));
        std::wcout << buff2 << std::endl;
        b = buff2;
    }
    return b;
}

void pr()
{
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n____________________________autoNetwork_version_beta________________________________________\n________________________________________________________________________________________________\n";
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n____________________________By zht QQ3152430961 网工9_______________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n";
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n";
    std::cout << "                  _             _   _          _   " << std::endl;
    std::cout << "   __ _   _   _  | |_    ___   | \\ | |   ___  | |_ " << std::endl;
    std::cout << "  / _` | | | | | | __|  / _ \\  |  \\| |  / _ \\ | __|" << std::endl;
    std::cout << " | (_| | | |_| | | |_  | (_) | | |\\  | |  __/ | |_ " << std::endl;
    std::cout << "  \\__,_|  \\__,_|  \\__|  \\___/  |_| \\_|  \\___|  \\__|" << std::endl;
    std::cout << "                                                   " << std::endl;

    char YoN='Y';

    std::cout << "是否在校园网下，输入大写Y/N :";
    std::cin >> YoN;
    if (YoN == 'Y')
    {
        std::string command = "powershell -ExecutionPolicy Bypass -File ./getIP.ps1";
        // 执行命令
        int result = std::system(command.c_str());
        if (result == 0) {
            std::cout << "PowerShell 脚本执行成功。" << std::endl;
        }
        else {
            std::cerr << "PowerShell 脚本执行失败，返回码: " << result << std::endl;
        }

        char yys = '0';
        std::cout << "联通输入0，移动输入1 :";
        std::cin >> yys;

        tPath = getAddr(L"data\\YYS.txt");

        std::ofstream outFile6(tPath);
        if (outFile6.is_open()) {
            // 向文件中写入内容
            outFile6 << yys;
            // 关闭文件
            outFile6.close();
            std::cout << "写入成功。\n";
        }
        else {
            std::cout << "无法打开文件进行写入。\n";
        }

        tPath = getAddr(L"data\\campusIP.txt");

        std::ifstream inFile(tPath);
        if (inFile.is_open()) {

            // 逐行读取文件内容并输出
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
                line1 = line;
            }
            // 关闭文件
            inFile.close();
        }
        else {
            std::cout << "无法打开文件进行读取。\n";
        }
        std::cout << "输入账号 :";
        std::cin >> account;
        std::cout << "输入密码 :";
        std::cin >> passw;

        tPath = getAddr(L"data\\account.txt");
        std::ofstream outFile(tPath);
        if (outFile.is_open()) {
            // 向文件中写入内容
            outFile << account;
            // 关闭文件
            outFile.close();
            std::cout << "写入成功。\n";
        }
        else {
            std::cout << "无法打开文件进行写入。\n";
        }

        tPath = getAddr(L"data\\passw.txt");
        std::ofstream outFile2(tPath);
        if (outFile2.is_open()) {
            // 向文件中写入内容
            string newpass = urlEncode(passw);
            outFile2 << newpass;
            // 关闭文件
            outFile2.close();
            std::cout << "写入成功。\n";
        }
        else {
            std::cout << "无法打开文件进行写入。\n";
        }


        command = "powershell -ExecutionPolicy Bypass -File ./zqd.ps1";
        // 执行命令
        result = std::system(command.c_str());
        if (result == 0) {
            std::cout << "PowerShell 脚本执行成功。" << std::endl;
        }
        else {
            std::cerr << "PowerShell 脚本执行失败，返回码: " << result << std::endl;
        }


        tPath = getAddr(L"data\\state.txt");
        std::ofstream outFile3(tPath);
        if (outFile3.is_open()) {
            // 向文件中写入内容
            outFile3 << '0';
            // 关闭文件
            outFile3.close();
            std::cout << "写入成功。\n";
        }
        else {
            std::cout << "无法打开文件进行写入。\n";
        }
    }
   
    


    
	std::cout << 1<<  "  ";
  }