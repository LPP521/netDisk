#ifndef MYSOCKET_H
#define MYSOCKET_H
#include <winsock2.h>
#include <stdio.h>
#include "NetDisk_Type.h"
//#pragma comment(lib, "ws2_32.lib") //vs������ʹ��
NAMESPACE_MYNET_SOCK

#define SERVER_ADDRESS "120.79.208.50" //��������IP��ַ
#define PORT           11112         //�������Ķ˿ں�
#define MSGSIZE        1024         //�շ��������Ĵ�С


class MySocket
{
public:
    MySocket();
    ~MySocket();

public:
    bool ConnecttoHost();
    int sendData(char* data,int size);
    int sendData(Xml_Info* data,int size);
    int recvData(char* data,int size);//ע��sizeҪ��data�Ĵ�СС1����һ��λ�ô��\0
    int recvData(Xml_Info* data,int size);
    bool InIt(); //����
    void clear(); //�ͷ�


public:
    //���������׽���
    SOCKET sClient;
    //����Զ�̷������ĵ�ַ��Ϣ
    SOCKADDR_IN* server;
    //�շ�������
    char szMessage[MSGSIZE];
    //�ɹ������ֽڵĸ���
    int ret;

};
NAMESAPCE_END
#endif // MYSOCKET_H
