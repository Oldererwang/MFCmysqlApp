
// MFCmysqlAppDlg.h: 头文件
//
#pragma once
#include <winsock2.h> //定义socket 
#include <winsock.h>
#include "mysql.h" //连接mysql的接口
#include "AdminDlg.h"
#include "UserDlg.h"
#include "LoginDlg.h"

// CMFCmysqlAppDlg 对话框
class CMFCmysqlAppDlg : public CDialogEx
{
// 构造
public:
	CMFCmysqlAppDlg(CWnd* pParent = nullptr);	// 标准构造函数

	afx_msg LRESULT OnIsAdminMessage(WPARAM wParam, LPARAM lParam);	 //接收子窗口发送的信息
	DECLARE_MESSAGE_MAP()

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMYSQLAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	MYSQL local_mysql;

	AdminDlg admDlg;
	UserDlg usrDlg;
	LoginDlg loginDlg;


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
public:

	CListCtrl m_ctrList;
};
