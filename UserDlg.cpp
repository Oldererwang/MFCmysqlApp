// UserDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCmysqlApp.h"
#include "UserDlg.h"
#include "afxdialogex.h"


// UserDlg 对话框

IMPLEMENT_DYNAMIC(UserDlg, CDialogEx)

UserDlg::UserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(USERDLG, pParent)
{

}

UserDlg::~UserDlg()
{
}

void UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserDlg, CDialogEx)
END_MESSAGE_MAP()


// UserDlg 消息处理程序
