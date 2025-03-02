#pragma once
/******************************************************************************
*
*
* Notepad2
*
* Notepad2.h
*   Global definitions and declarations
*
* See Readme.txt for more information about this source code.
* Please send me your comments to this work.
*
* See License.txt for details about distribution and modification.
*
*                                              (c) Florian Balmer 1996-2011
*                                                  florian.balmer@gmail.com
*                                               http://www.flos-freeware.ch
*
*
******************************************************************************/



//==== Main Window ============================================================
// [2e]: application name fix
#define WC_NOTEPAD2 L"Notepad 2e"


//==== Data Type for WM_COPYDATA ==============================================
#define DATA_NOTEPAD2_PARAMS 0xFB10
typedef struct np2params {

  int   flagFileSpecified;
  int   flagChangeNotify;
  int   flagLexerSpecified;
  int   iInitialLexer;
  int   flagQuietCreate;
  int   flagJumpTo;
  int   iInitialLine;
  int   iInitialColumn;
  int   iInitialSelStart;
  int   iInitialSelEnd;
  int   iSrcEncoding;
  int   flagSetEncoding;
  int   flagSetEOLMode;
  int   flagTitleExcerpt;
  WCHAR wchData;

} NP2PARAMS, *LPNP2PARAMS;


//==== Toolbar Style ==========================================================
#define WS_TOOLBAR (WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | \
                    TBSTYLE_TOOLTIPS | TBSTYLE_FLAT | TBSTYLE_ALTDRAG | \
                    TBSTYLE_LIST | CCS_NODIVIDER | CCS_NOPARENTALIGN | \
                    CCS_ADJUSTABLE)


//==== ReBar Style ============================================================
#define WS_REBAR (WS_CHILD | WS_CLIPCHILDREN | WS_BORDER | RBS_VARHEIGHT | \
                  RBS_BANDBORDERS | CCS_NODIVIDER | CCS_NOPARENTALIGN)


//==== Ids ====================================================================
#define IDC_STATUSBAR    0xFB00
#define IDC_TOOLBAR      0xFB01
#define IDC_REBAR        0xFB02
#define IDC_EDIT         0xFB03
#define IDC_EDITFRAME    0xFB04
#define IDC_FILENAME     0xFB05
#define IDC_REUSELOCK    0xFB06


//==== Statusbar ==============================================================
#define STATUS_DOCPOS    0
#define STATUS_DOCSIZE   1
#define STATUS_CODEPAGE  2
#define STATUS_EOLMODE   3
#define STATUS_OVRMODE   4
#define STATUS_LEXER     5
#define STATUS_HELP    255


//==== Change Notifications ===================================================
#define ID_WATCHTIMER 0xA000
#define WM_CHANGENOTIFY WM_USER+1


//==== Callback Message from System Tray ======================================
#define WM_TRAYMESSAGE WM_USER


//==== Paste Board Timer ======================================================
#define ID_PASTEBOARDTIMER 0xA001


//==== Reuse Window Lock Timeout ==============================================
#define REUSEWINDOWLOCKTIMEOUT 250


//==== Function Declarations ==================================================
BOOL InitApplication(HINSTANCE);
HWND InitInstance(HINSTANCE, LPSTR, int);
// [2e]: separate exit-handler function
void ExitInstance(HINSTANCE);
BOOL ActivatePrevInst();
BOOL RelaunchMultiInst();
BOOL RelaunchElevated();
void SnapToDefaultPos(HWND);
void ShowNotifyIcon(HWND, BOOL);
void SetNotifyIconTitle(HWND);
void InstallFileWatching(LPCWSTR);
void CALLBACK WatchTimerProc(HWND, UINT, UINT_PTR, DWORD);
void CALLBACK PasteBoardTimer(HWND, UINT, UINT_PTR, DWORD);

void LoadSettings();
void SaveSettings(BOOL);
BOOL ParseCommandLine();
void LoadFlags();
int  CheckIniFile(LPWSTR, LPCWSTR);
int  CheckIniFileRedirect(LPWSTR, LPCWSTR);
int  FindIniFile();
int  TestIniFile();
int  CreateIniFile();
int  CreateIniFileEx(LPCWSTR);

void EditInit(HWND);
void UpdateStatusbar();
void UpdateToolbar();
void UpdateLineNumberWidth(HWND);
void SetWordWrap(HWND);
void SetSelectEx(HWND);
void SetLongLineMarker(HWND);
void SetMarginWidthN(HWND);
void ShowWhiteSpace(HWND);
void SetViewEOL(HWND);
void SetShowWordWrapSymbols(HWND);
void HideMatchBraces(HWND);

BOOL FileIO(BOOL, LPCWSTR, BOOL, int*, int*, BOOL*, BOOL*, BOOL*, BOOL);
BOOL FileLoad(BOOL, BOOL, BOOL, BOOL, LPCWSTR);
BOOL _FileLoad(BOOL, BOOL, BOOL, BOOL, LPCWSTR, BOOL);
BOOL FileSave(BOOL, BOOL, BOOL, BOOL, BOOL);
BOOL OpenFileDlg(HWND, LPWSTR, int, LPCWSTR);
BOOL SaveFileDlg(HWND, LPWSTR, int, LPCWSTR);


LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT MsgCreate(HWND, WPARAM, LPARAM);
void    CreateBars(HWND, HINSTANCE);
void    MsgThemeChanged(HWND, WPARAM, LPARAM);
void    MsgSize(HWND, WPARAM, LPARAM);
void    MsgInitMenu(HWND, WPARAM, LPARAM);
LRESULT MsgCommand(HWND, WPARAM, LPARAM);
LRESULT MsgNotify(HWND, WPARAM, LPARAM);
