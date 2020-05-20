// AdminDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCmysqlApp.h"
#include "AdminDlg.h"
#include "afxdialogex.h"


// AdminDlg 对话框

IMPLEMENT_DYNAMIC(AdminDlg, CDialogEx)

AdminDlg::AdminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ADMINDIALOG, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
END_MESSAGE_MAP()


// AdminDlg 消息处理程序


BOOL AdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
