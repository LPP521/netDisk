#ifndef XMB_H
#define XMB_H

#include <QDialog>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidgetItem>
#include <QToolButton>
#include <iostream>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAxWidget>
#include <QLineEdit>
#include <vector>
#include "qnavigationwidget.h"
#include "NetDisk_Type.h"

#define MAXNUM 20 //�ļ�����
namespace Ui {

    class XMB;
}

class XMB : public QDialog
{
    Q_OBJECT

public:
    explicit XMB(QWidget *parent = 0);
    ~XMB();

private:
    void Init();//��ʼ��
    void mMenu();//��ʼ���˵���
    QMenu* CreateMenu(QString); //�����˵�
    void CreateWeb(); //�������������

    bool getUsr(std::string&);//��ȡ�û���

private slots:

    void OnLast();//����
    void OnBscGroupRightAction();//ˢ��
    void onCreateFile();//�½��ļ�
    void onCreateDir();//�½��ļ���
    void onUpLoad();//�ϴ�
    void onDownLoad();//����
    void loadNavigate();

    void on_listWidget_itemActivated(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::XMB *ui;
    Data_Swap file_tmp; //�ļ���Ϣ�ṹ��
    Com_File com_tmp; //������Ϣ�ṹ��
    QToolButton* ButtonArry[MAXNUM];
    QMenuBar* MyMenuBar;//�˵���
    QMenu* menu;//�˵�
    QLineEdit *lineUrl; //url��Ŀ
    QAxWidget* webWidget; //���������
    std::vector<Data_Swap> File_All; //�����ļ���Ϣ


protected:
     void mousePressEvent(QMouseEvent*);
     //����һ���麯�����̳���QEvent.ֻҪ��д������麯�������㰴�´������Ͻǵ�"��"ʱ���ͻ����������д�Ĵ˺���.
     void closeEvent(QCloseEvent*event);

};
//��ȫ·���л�ȡ�ļ���
inline std::string pathName(std::string name)
{
    size_t index;
    for(index = name.size() - 1;index >= 0; --index)
    {
        if(name[index] == '/')
            break;
    }
    if(index < 0)
        return name;
    else
        return name.substr(index + 1,name.size() - index);
}

#endif // XMB_H
