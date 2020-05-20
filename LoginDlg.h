#pragma once

#include <winsock2.h> //定义socket 
#include <winsock.h>
#include "mysql.h" //连接mysql的接口
// LoginDlg 对话框


class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LoginDlg();

	bool isAdmin;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = LOGINDIALOG };
#endif

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();

	MYSQL local_mysql;
	afx_msg void OnBnClickedButton1();
};
