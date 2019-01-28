#include "mysocket.h"
#include <QMessageBox>

USING_NAMESPACE_MYNET_SOCK
USING_NAMESPACE_STD

MySocket::MySocket()
{
}

MySocket::~MySocket()
{
}

void MySocket::clear()
{
    delete server;
    // �ͷ����Ӻͽ��н�������
    closesocket(sClient);
    WSACleanup();
}

bool MySocket::InIt()
{
    WSADATA wsaData;
    server = new SOCKADDR_IN;
    //WSAStartup(0x0202, &wsaData); // Initialize Windows socket library
    if(WSAStartup(0x0202, &wsaData) != 0)
        return false;

    // �����ͻ����׽���
    sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INETָ��ʹ��TCP/IPЭ���壻
                                                         //SOCK_STREAM, IPPROTO_TCP����ָ��ʹ��TCPЭ��
    if(sClient == INVALID_SOCKET)
        return false;

    // ָ��Զ�̷������ĵ�ַ��Ϣ(�˿ںš�IP��ַ��)
    memset(server, 0, sizeof(SOCKADDR_IN)); //�Ƚ������ַ��server��Ϊȫ0
    server->sin_family = PF_INET;  //������ַ��ʽ��TCP/IP��ַ��ʽ
    server->sin_port = htons(PORT); //ָ�����ӷ������Ķ˿ں�
    server->sin_addr.s_addr = inet_addr(SERVER_ADDRESS); //ָ�����ӷ�������IP��ַ
    return true;
}

bool MySocket::ConnecttoHost()
{
    if(connect(sClient,(struct sockaddr*)server,sizeof(SOCKADDR_IN)))
        return false;
    else
        return true;
}


int MySocket::sendData(char* data,int size)
{
    ret = send(sClient,data,size,0);
    return ret;
}

int MySocket::sendData(Xml_Info* data,int size)
{
    ret = send(sClient,(char*)data,size,0);
    return ret;
}

int MySocket::recvData(char* data,int size)
{
    ret = recv(sClient,data,size*sizeof(char),0);
    return ret;
}

int MySocket::recvData(Xml_Info* data,int size)
{
    ret = recv(sClient,(char*)data,size,0);
    return ret;
}

