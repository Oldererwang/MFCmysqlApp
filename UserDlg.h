#pragma once


// UserDlg 对话框

class UserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserDlg)

public:
	UserDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UserDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = USERDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
