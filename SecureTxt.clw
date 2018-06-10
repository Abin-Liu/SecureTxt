; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSecureTxtView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SecureTxt.h"
LastPage=0

ClassCount=7
Class1=CSecureTxtApp
Class2=CSecureTxtDoc
Class3=CSecureTxtView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CPwdDlg
Resource3=IDD_PWDDLG
Class7=CNewPwdDlg
Resource4=IDD_NEWPWDDLG

[CLS:CSecureTxtApp]
Type=0
HeaderFile=SecureTxt.h
ImplementationFile=SecureTxt.cpp
Filter=N

[CLS:CSecureTxtDoc]
Type=0
HeaderFile=SecureTxtDoc.h
ImplementationFile=SecureTxtDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CSecureTxtDoc

[CLS:CSecureTxtView]
Type=0
HeaderFile=SecureTxtView.h
ImplementationFile=SecureTxtView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC
LastObject=ID_EDIT_MODREDO


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
LastObject=ID_EDIT_MODUNDO
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=SecureTxt.cpp
ImplementationFile=SecureTxt.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_MODUNDO
Command11=ID_EDIT_MODREDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CLEAR
Command16=ID_EDIT_FIND
Command17=ID_EDIT_REPEAT
Command18=ID_EDIT_REPLACE
Command19=ID_EDIT_SELECT_ALL
Command20=ID_EDIT_DATETIME
Command21=ID_VIEW_TOOLBAR
Command22=ID_VIEW_STATUS_BAR
Command23=ID_OPTIONS_FONT
Command24=ID_OPTIONS_PASSWORD
Command25=ID_APP_ABOUT
CommandCount=25

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_SELECT_ALL
Command2=ID_EDIT_COPY
Command3=ID_EDIT_FIND
Command4=ID_EDIT_REPLACE
Command5=ID_FILE_NEW
Command6=ID_FILE_OPEN
Command7=ID_FILE_PRINT
Command8=ID_FILE_SAVE
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_MODUNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_REPEAT
Command13=ID_EDIT_DATETIME
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_EDIT_CUT
Command19=ID_EDIT_MODREDO
Command20=ID_EDIT_MODUNDO
CommandCount=20

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT
Command6=ID_EDIT_MODUNDO
Command7=ID_EDIT_MODREDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_CLEAR
Command12=ID_EDIT_FIND
Command13=ID_APP_ABOUT
CommandCount=13

[DLG:IDD_PWDDLG]
Type=1
Class=CPwdDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PWD,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CPwdDlg]
Type=0
HeaderFile=PwdDlg.h
ImplementationFile=PwdDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPwdDlg

[DLG:IDD_NEWPWDDLG]
Type=1
Class=CNewPwdDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PWD1,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PWD2,edit,1350631584
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[CLS:CNewPwdDlg]
Type=0
HeaderFile=NewPwdDlg.h
ImplementationFile=NewPwdDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewPwdDlg
VirtualFilter=dWC

