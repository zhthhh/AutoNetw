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
        // ����Ҫ������ַ�����ĸ�����֡��Լ�һЩ�����ַ�
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // �����ַ���Ҫ����
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
    // �ҵ����һ����б�ܵ�λ��
    size_t lastSlashPos = fullPath.find_last_of(L"\\");
    if (lastSlashPos != std::wstring::npos) {
        // ��ȡ��б��֮ǰ�Ĳ��֣���Ŀ¼·��
        std::wstring directoryPath = fullPath.substr(0, lastSlashPos + 1);

        std::wstring buff = c;
        std::wstring buff2 = directoryPath + buff;

        // ����������ı��ػ�����Ϊ����
        std::wcout.imbue(std::locale("chs"));
        std::wcout << buff2 << std::endl;
        b = buff2;
    }
    return b;
}

void pr()
{
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n____________________________autoNetwork_version_beta________________________________________\n________________________________________________________________________________________________\n";
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n____________________________By zht QQ3152430961 ����9_______________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n";
    //std::cout << "________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n________________________________________________________________________________________________\n";
    std::cout << "                  _             _   _          _   " << std::endl;
    std::cout << "   __ _   _   _  | |_    ___   | \\ | |   ___  | |_ " << std::endl;
    std::cout << "  / _` | | | | | | __|  / _ \\  |  \\| |  / _ \\ | __|" << std::endl;
    std::cout << " | (_| | | |_| | | |_  | (_) | | |\\  | |  __/ | |_ " << std::endl;
    std::cout << "  \\__,_|  \\__,_|  \\__|  \\___/  |_| \\_|  \\___|  \\__|" << std::endl;
    std::cout << "                                                   " << std::endl;

    char YoN='Y';

    std::cout << "�Ƿ���У԰���£������дY/N :";
    std::cin >> YoN;
    if (YoN == 'Y')
    {
        std::string command = "powershell -ExecutionPolicy Bypass -File ./getIP.ps1";
        // ִ������
        int result = std::system(command.c_str());
        if (result == 0) {
            std::cout << "PowerShell �ű�ִ�гɹ���" << std::endl;
        }
        else {
            std::cerr << "PowerShell �ű�ִ��ʧ�ܣ�������: " << result << std::endl;
        }

        char yys = '0';
        std::cout << "��ͨ����0���ƶ�����1 :";
        std::cin >> yys;

        tPath = getAddr(L"data\\YYS.txt");

        std::ofstream outFile6(tPath);
        if (outFile6.is_open()) {
            // ���ļ���д������
            outFile6 << yys;
            // �ر��ļ�
            outFile6.close();
            std::cout << "д��ɹ���\n";
        }
        else {
            std::cout << "�޷����ļ�����д�롣\n";
        }

        tPath = getAddr(L"data\\campusIP.txt");

        std::ifstream inFile(tPath);
        if (inFile.is_open()) {

            // ���ж�ȡ�ļ����ݲ����
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
                line1 = line;
            }
            // �ر��ļ�
            inFile.close();
        }
        else {
            std::cout << "�޷����ļ����ж�ȡ��\n";
        }
        std::cout << "�����˺� :";
        std::cin >> account;
        std::cout << "�������� :";
        std::cin >> passw;

        tPath = getAddr(L"data\\account.txt");
        std::ofstream outFile(tPath);
        if (outFile.is_open()) {
            // ���ļ���д������
            outFile << account;
            // �ر��ļ�
            outFile.close();
            std::cout << "д��ɹ���\n";
        }
        else {
            std::cout << "�޷����ļ�����д�롣\n";
        }

        tPath = getAddr(L"data\\passw.txt");
        std::ofstream outFile2(tPath);
        if (outFile2.is_open()) {
            // ���ļ���д������
            string newpass = urlEncode(passw);
            outFile2 << newpass;
            // �ر��ļ�
            outFile2.close();
            std::cout << "д��ɹ���\n";
        }
        else {
            std::cout << "�޷����ļ�����д�롣\n";
        }


        command = "powershell -ExecutionPolicy Bypass -File ./zqd.ps1";
        // ִ������
        result = std::system(command.c_str());
        if (result == 0) {
            std::cout << "PowerShell �ű�ִ�гɹ���" << std::endl;
        }
        else {
            std::cerr << "PowerShell �ű�ִ��ʧ�ܣ�������: " << result << std::endl;
        }


        tPath = getAddr(L"data\\state.txt");
        std::ofstream outFile3(tPath);
        if (outFile3.is_open()) {
            // ���ļ���д������
            outFile3 << '0';
            // �ر��ļ�
            outFile3.close();
            std::cout << "д��ɹ���\n";
        }
        else {
            std::cout << "�޷����ļ�����д�롣\n";
        }
    }
   
    


    
	std::cout << 1<<  "  ";
  }