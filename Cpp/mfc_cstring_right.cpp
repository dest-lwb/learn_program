
/*MFC如何获取字符串的后八位?

例如：
CString m_in ="567*12345678";
CString m_cc;
如何可以获取m_in中的后八位字符并赋给m_cc;
*/

CString m_in ="567*12345678";
CString m_cc = m_in.Right(8);

// MFC CString 字符串截取

    CString str=_T("aaa;vvv");
    int index=str.Find(_T(";"));
    str=str.Left(str.GetLength()-index-1);
    AfxMessageBox((LPCTSTR)str);