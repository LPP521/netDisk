#include "recvthread.h"
#include <QMessageBox>
#include <QFile>

USING_NAMESPACE_MYNET_RECVTHREAD
RecvThread::RecvThread()
{
    Recv_Socket = new MySocket;
}

RecvThread::~RecvThread()
{
    delete Recv_Socket;
}

void RecvThread::run()
{
    recv_Xml();
}


bool RecvThread::recv_Xml()
{
    delete Recv_Socket;
    Recv_Socket = new MySocket;
    if(!Recv_Socket->InIt())//bind �󶨵�ַ
    {
        emit SIG_bind_error();
        return false;
    }

    if(!Recv_Socket->ConnecttoHost())//���������������
    {
        emit SIG_LinkErr();//��������ʧ���ź�
        return false;
    }
    else // ���ӳɹ�
    {
        Xml_Info info;
        char buff[MSGSIZE];
        int ret;
        ret = Recv_Socket->recvData(&info,sizeof(info));
        if(ret == sizeof(info))
        {
            QFile file("./log/xml/recv.xml");
            if( !file.open(QIODevice::Append | QIODevice::Text) )
            {
                return false;
            }
            while(ret>0)
            {
                ret = Recv_Socket->recvData(buff,MSGSIZE);
                file.write(buff,ret);
            }
            file.close();
        }
        else
        {
            emit recv_xml_info_error();//�ļ���Ϣ����ʧ��
            return false;
        }
    }
    Recv_Socket->clear();
    return true;
}
