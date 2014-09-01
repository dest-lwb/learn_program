
/*MFC如何获取字符串的后八位?

例如：
CString m_in ="567*12345678";
CString m_cc;
如何可以获取m_in中的后八位字符并赋给m_cc;
*/

CString m_in ="567*12345678";
CString m_cc = m_in.Right(8);