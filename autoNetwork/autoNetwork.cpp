#include <iostream>
#include "sole.hpp"
#include "getIP.hpp"
#include <fstream>
#include <string>
#include<windows.h>
#include <codecvt>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
std::string line;
std::string line1;
std::string buf;
std::string buf2;

wstring relaPath;
wstring truePath;



string passw = "";
string account = "";
string piece1 = "";
string piece2 = "&uuid=";
string piece3 = "&portaltype=0&hostname=&bindCtrlId=' "
    "-WebSession $session "
    "-Headers @{ "
    "'Accept' = 'application/json, text/javascript, */*; q=0.01'; "
    "'Accept-Encoding' = 'gzip, deflate'; "
    "'Accept-Language' = 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6'; "
    "'Referer' = 'http://172.29.35.36:6060/portalReceiveAction.do?wlanuserip=10.36.147.64&wlanacname=HD-SuShe-ME60'; "
    "'X-Requested-With' = 'XMLHttpRequest' "
    "}\"";
int write() {

    
    auto now = std::chrono::system_clock::now();
    
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::string strtime = std::to_string(millis);
    std::cout << "��ǰ��ʱ��������룩: " <<strtime << std::endl;

    
    sole::uuid u4 = sole::uuid4();
    cout << "uuid v4 �ַ���: " << u4 << std::endl;
    string u4s = u4.str();
    cout << "uuid v4 �ַ���: " << u4s.length() << std::endl;
    std::string filePath = "./work.ps1";

    
    
    string printff = piece1 + strtime + piece2 + u4s +piece3;
    // ���ļ��Խ���д�����1
    std::ofstream ps1File(filePath);
    cout << printff<<endl;
    
    if (ps1File.is_open()) {
        // ���ַ���д���ļ�
        ps1File << printff;

        ps1File.close();

        std::cout << "�ַ����ѳɹ�д�� " << filePath << std::endl;
    }
    else { 
        std::cerr << "�޷����ļ� " << filePath << std::endl;
        
    }
    std::string command = "powershell -ExecutionPolicy Bypass -Command \"" + printff + "\"";
    //����std::string command = "powershell -ExecutionPolicy Bypass -File ./work.ps1";
    //ҲҪ�������д��work.ps1
    // ִ������
    int result = std::system(printff.c_str());
   if (result == 0) {
        std::cout << "PowerShell �ű�ִ�гɹ���" << std::endl;
    }
    else {
        std::cerr << "PowerShell �ű�ִ��ʧ�ܣ�������: " << result << std::endl;
   }
   return 0;
}







int main()
{

    

    truePath = getAddr( L"data\\state.txt");
    std::ifstream inFile1(truePath);
    if (inFile1.is_open()) {
        
        // ���ж�ȡ�ļ����ݲ����
        while (std::getline(inFile1, buf)) {
            //std::cout << buf << std::endl;

        }
        // �ر��ļ�
        inFile1.close();
    }
    else {
        std::cout << "�޷����ļ����ж�ȡ��\n";
    }

    string yysstate = "";
    truePath = getAddr( L"data\\YYS.txt");
    std::ifstream inFile7(truePath);
    if (inFile7.is_open()) {

        // ���ж�ȡ�ļ����ݲ����
        while (std::getline(inFile7, buf2)) {
            //std::cout << buf2 << std::endl;
            yysstate = buf2;
        }
        // �ر��ļ�
        inFile7.close();
    }
    else {
        std::cout << "�޷����ļ����ж�ȡ��\n";
    }

    //cout << yysstate << endl;
    truePath = getAddr( L"data\\account.txt");
    std::ifstream inFile3(truePath);
    if (inFile3.is_open()) {

        
        while (std::getline(inFile3, buf2)) {
            //std::cout << buf2 << std::endl;
            account = buf2;
        }
        
        inFile3.close();
    }
    else {
        std::cout << "�޷����ļ����ж�ȡ��\n";
    }

    truePath = getAddr( L"data\\passw.txt");
    std::ifstream inFile4(truePath);
    if (inFile4.is_open()) {

        // ���ж�ȡ�ļ����ݲ����
        while (std::getline(inFile4, buf2)) {
            //std::cout << buf2 << std::endl;
            passw = buf2;
        }
        // �ر��ļ�
        inFile4.close();
    }
    else {
        std::cout << "�޷����ļ����ж�ȡ��\n";
    }
    truePath = getAddr(L"data\\campusIP.txt");
    std::ifstream inFile5(truePath);
    if (inFile5.is_open()) {

        // ���ж�ȡ�ļ����ݲ����
        while (std::getline(inFile5, buf2)) {
            //std::cout << buf2 << std::endl;
            line1 = buf2;
        }
        // �ر��ļ�
        inFile5.close();
    }
    else {
        std::cout << "�޷����ļ����ж�ȡ��\n";
    }

    if (yysstate == "0")
    {
        piece1 = "powershell -Command \"$session = New-Object Microsoft.PowerShell.Commands.WebRequestSession; "
            "$session.UserAgent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36 Edg/134.0.0.0'; "
            "Invoke-WebRequest -UseBasicParsing -Uri 'http://172.29.35.36:6060/quickauth.do?userid=" + account + "%40henult&passwd=" + passw + "&wlanuserip=" + line1 + "&wlanacname=HD-SuShe-ME60&wlanacIp=172.22.254.253&ssid=&vlan=&mac=&version=0&portalpageid=4&timestamp=";
    }

    else if (yysstate == "1")
    {
        piece1 = "powershell -Command \"$session = New-Object Microsoft.PowerShell.Commands.WebRequestSession; "
            "$session.UserAgent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36 Edg/134.0.0.0'; "
            "Invoke-WebRequest -UseBasicParsing -Uri 'http://172.29.35.36:6060/quickauth.do?userid=" + account + "%40henuyd&passwd=" + passw + "&wlanuserip=" + line1 + "&wlanacname=HD-SuShe-ME60&wlanacIp=172.22.254.253&ssid=&vlan=&mac=&version=0&portalpageid=4&timestamp=";
    }
    

	int i = 0;
    if ( buf == "1")
    {
        pr();
    }
    else if (buf == "0")
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << write() << std::endl;
        return 0;
    }
    //cout << line1 << std::endl;
    
	//cin >> i;
    return 0;
}