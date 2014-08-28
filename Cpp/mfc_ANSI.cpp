// 今天写了一段输出文本到文件的代码，一开始用CFile输出中文,总是出现乱码，又是百度（Google被墙了）一番，网上的教程基本是只知其一不知其二，大多只讲了输出文件字节序标记和计算宽字符长度这两个注意点，却没有提到字符转换这个最关键的一步。下面的代码分别输出UTF-8和ANSI（简体中文Windows上是GBK编码)两种编码的文本文件。
//
// 写UTF-8文本
// 下列文件类操作中可能抛出一个CFileException异常
    try {
        CStdioFile hfile( strFilePath, CFile::modeReadWrite);
                           
        if(hfile.m_hFile)
        {
			DWORD dwFileLen = hfile.GetLength();
		   
			if (0 == dwFileLen) // 文件为空时写入UTF字节序标记
			{
					 const unsigned char LeadBytes[]  = {0xEF, 0xBB, 0xBF};
					 hfile.Write(LeadBytes, sizeof(LeadBytes));
			}
 
            int nSrcLen = (int)wcslen(lpstrWord);
 
            CStringA utf8String(lpstrWord);
            int nBufLen = (nSrcLen+1) * 6;
            LPSTR buffer = utf8String.GetBufferSetLength(nBufLen);
 
            // 将UNICODE 转换成UTF8
            // 需要函数AtlUnicodeToUTF8 头文件: <atlenc.h>
            int nLen = AtlUnicodeToUTF8(lpstrWord, nSrcLen, buffer, nBufLen);             // int nLen = utf8String.GetLength();
 
            buffer[nLen] = 0;
            utf8String.ReleaseBuffer();
 
            //写文件
                            hfile.SeekToEnd();
            hfile.Write((LPCSTR)utf8String, nLen);
            hfile.Write("/r/n", 2);
 
            hfile.Close();
        }
    }
    catch(CFileException* pException)
    {
        CString strMsg;
                  
        TCHAR  szErrorMessage[512];
        if (pException->GetErrorMessage(szErrorMessage,
                            sizeof(szErrorMessage)/sizeof(*szErrorMessage), 0))
                strMsg.Format(_T("(%s:%d)/n%s"), _T(__FILE__), __LINE__, szErrorMessage);
            else
                strMsg.Format(_T("(%s:%d)"),  _T(__FILE__), __LINE__);
 
        AfxMessageBox(strMsg);
    }

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// 写ANSI文本:
    try {
        CStdioFile hfile( strHeiMaiUsrLibPath, CFile::modeReadWrite);
                           
        if(hfile.m_hFile)
        {
            // 将Unicode字符串赋给Ansi格式的CStringA,实现Unicode=>Ansi转换
            CStringA utf8String(lpstrWord);
            int nLen = utf8String.GetLength();
 
            // 写文件
            hfile.SeekToEnd();
            hfile.Write((LPCSTR)utf8String, nLen);
            hfile.Write("/r/n", 2);
 
            hfile.Close();
        }
    }
    catch(CFileException* pException)
    {
        CString strMsg;
                  
        TCHAR  szErrorMessage[512];
        if (pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage)/sizeof(*szErrorMessage), 0))
                strMsg.Format(_T("(%s:%d)/n%s"), _T(__FILE__), __LINE__, szErrorMessage);
            else
                strMsg.Format(_T("(%s:%d)"),  _T(__FILE__), __LINE__);
 
        AfxMessageBox(strMsg);
    }