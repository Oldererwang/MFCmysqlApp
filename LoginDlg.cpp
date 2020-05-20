// LoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCmysqlApp.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(LOGINDIALOG, pParent)
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &LoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &LoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


void LoginDlg::OnBnClickedButton2()
{

	// TODO: 在此添加控件通知处理程序代码
	mysql_init(&local_mysql);

	if (!mysql_real_connect(&local_mysql, "localhost", "root",
		"19961221why0", "MyAut", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败!"));
	}
	else
	{
		CString strName, strPwd;
		GetDlgItemText(IDC_EDIT1, strName);
		GetDlgItemText(IDC_EDIT2, strPwd);

		CString cStr;
		cStr.Format(_T("select * from admin where user = \"%s\""), strName);
		USES_CONVERSION;

		int ress = mysql_query(&local_mysql, W2A(cStr));

		if (ress == 0)
		{
			MYSQL_RES* res = mysql_store_result(&local_mysql);
			if (mysql_num_rows(res) == 0)
			{
				cStr.Format(_T("select user,password from user where user = \"%s\""), strName);
				USES_CONVERSION;

				int ress = mysql_query(&local_mysql, W2A(cStr));

				if (ress == 0)
				{
					MYSQL_RES* res2 = mysql_store_result(&local_mysql);
					if (mysql_num_rows(res2) == 0)
					{
						AfxMessageBox(_T("用户不存在!"));
					}
					else
					{
						MYSQL_ROW row2 = mysql_fetch_row(res2);
						if (strPwd == row2[1])
						{
							CDialog::OnOK();
							mysql_free_result(res2);
							MessageBox(_T("登录成功!"));
						}
					}
				}
				else
				{
					AfxMessageBox(_T("用户不存在!"));
				}
			}
			else
			{
				MYSQL_ROW row = mysql_fetch_row(res);
				if (strPwd == row[1])
				{
					CDialog::OnOK();
					mysql_free_result(res);
					MessageBox(_T("登录成功!"));
					CString wodeshenfne;
					GetDlgItemText(IDC_EDIT1, wodeshenfne);

					if (wodeshenfne == _T("admin"))
					{
						isAdmin = 1;
					}	
				}
				else
				{
					AfxMessageBox(_T("密码错误!"));
				}

			}

		}
		else
		{
			AfxMessageBox(_T("用户不存在"));

		}
	}
	mysql_close(&local_mysql);
}


void LoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
