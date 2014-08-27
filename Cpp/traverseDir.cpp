// TraverseDir.cpp : 定义控制台应用程序的入口点。
//遍历目录下文件和文件夹

#include "stdafx.h"
#include <afx.h>
#include <iostream>
#include <WinBase.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD ret;
	if(SetCurrentDirectory("D:/Software") == TRUE)
	{
		CFileFind  finder;
		BOOL bWorking = finder.FindFile("*.*");
		while(bWorking)
		{
			bWorking = finder.FindNextFile();
			if(finder.IsDirectory())
				cout<<"Directory: \t";
			else
				cout<<"File: \t\t";
			cout<<finder.GetFileName()<<endl;
		}
	}
	else
	{
		ret = GetLastError();
		cout<<"GetLastError() = "<<ret<<endl;
	}
	
	return 0;
}
