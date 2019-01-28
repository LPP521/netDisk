#ifndef NETDISK_TYPE_H
#define NETDISK_TYPE_H
#include <string>
#include <cstring>
#include "mynet_def.h"
enum Mode{
    MAIL_LOGIN = 0,//���ŵ�¼
    LOGN_IN = 1,//��ͨ��¼
    LOGN_UP = 2 // ע��
};

enum Commit
{
    INIT_FILE = 0,//��ʼ��
    MKDIR_FILE = 1,//�½��ļ�
    DEL_FILE = 2, //ɾ���ļ�
    CHANGE_FILE = 3 //�޸��ļ�
};

enum File_mode
{
    DIR_FILE = 0, //�ļ���
    FILE_FILE = 1,//��ͨ�ļ�
    MUSIC_FILE = 2,//�����ļ�
    MOVIE_FILE = 3,//��Ƶ�ļ�
    PICTURE_FILE = 4//ͼƬ
};

enum ErrorCode
{
    NET_ERROR, //�����쳣
    FILEOPEN_FAIL, //�ļ���ʧ��
    BIND_ERROR, //��ʧ��
    GET_FILEINFO_FAIL, //��ȡ�ļ���Ϣʧ��
    SENDDATA_FAIL, //��������ʧ��
    RECVDATA_FAIL //��������ʧ��
};

#pragma pack(1)
typedef struct _usr_info //�û���Ϣ
{
    Mode e_mode;
 //   bool mode;
    char _usr[20];
    char Passwd[33];
    char AuthCode[5];
}usr_info;


typedef struct authcode_ //�û���֤��
{
    char _Usr[20];

}authcode;

typedef struct Data_Swap_ //�ļ�����
{
    char File_Name[30];
    char Finall_Time[20];
    File_mode FM;
    unsigned long File_Size;

    Data_Swap_(std::string name_, std::string time_, int fm_,unsigned long size_)
    {
        strcpy(File_Name,name_.c_str());
        strcpy(Finall_Time,time_.c_str());
        FM = (File_mode)fm_;
        File_Size = size_;
    }
    Data_Swap_(){}
}Data_Swap;

typedef struct Com_File_ //��������
{
    char Usr_name[20];
    Commit com;
    char Path[40];

    Com_File_(std::string name_, int fm_,std::string size_)
    {
        strcpy(Usr_name,name_.c_str());
        strcpy(Path,size_.c_str());
        com= (Commit)fm_;

    }
    Com_File_(){}
}Com_File;

typedef struct File_Num_ //�ļ�����
{
    int file_num;
}File_Num;

typedef struct Xml_Info_ //xml�ļ���Ϣ
{
    char name[51];
    long long size;
}Xml_Info;

#pragma pack()

#endif // NETDISK_TYPE_H
