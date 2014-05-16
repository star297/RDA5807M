/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.22                          *
*        Compiled Jul  4 2013, 15:16:01                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include <math.h>
#include "RDA5807M.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x17)
#define ID_BUTTON_0 (GUI_ID_USER + 0x18)
#define ID_BUTTON_1 (GUI_ID_USER + 0x19)
#define ID_BUTTON_2 (GUI_ID_USER + 0x1C)
#define ID_BUTTON_3 (GUI_ID_USER + 0x1D)
#define ID_CHECKBOX_0 (GUI_ID_USER + 0x1F)
#define ID_TEXT_0 (GUI_ID_USER + 0x20)
#define ID_TEXT_1 (GUI_ID_USER + 0x21)
#define ID_TEXT_2 (GUI_ID_USER + 0x22)
#define ID_SPINBOX_0 (GUI_ID_USER + 0x24)
#define ID_SPINBOX_1 (GUI_ID_USER + 0x25)
#define ID_CHECKBOX_1 (GUI_ID_USER + 0x26)
#define ID_CHECKBOX_2 (GUI_ID_USER + 0x27)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 240, 320, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "power", ID_BUTTON_0, 155, 5, 80, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "reset", ID_BUTTON_1, 183, 35, 50, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "seekdown", ID_BUTTON_2, 5, 240, 80, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "seekup", ID_BUTTON_3, 90, 240, 80, 30, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "mute", ID_CHECKBOX_0, 175, 290, 65, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "tittle", ID_TEXT_0, 5, 5, 125, 20, 0, 0x64, 0 },
	{ TEXT_CreateIndirect, "text1", ID_TEXT_1, 5, 35, 80, 20, 0, 0x64, 0 },
	{ TEXT_CreateIndirect, "text2", ID_TEXT_2, 85, 35, 90, 20, 0, 0x64, 0 },
	{ SPINBOX_CreateIndirect, "channel", ID_SPINBOX_0, 5, 280, 80, 30, 0, 0x0, 0 },
	{ SPINBOX_CreateIndirect, "volume", ID_SPINBOX_1, 90, 280, 80, 30, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "bass", ID_CHECKBOX_1, 175, 265, 65, 20, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "rds", ID_CHECKBOX_2, 175, 240, 80, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  float   frq;
  char bufem[30];
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, 0x00000000);
	//
	// Initialization of channel spinbox
	//
	hItem = WM_GetDialogItem(pMsg->hWin,  ID_SPINBOX_0);
	SPINBOX_SetRange(hItem, 875, 1080);
	SPINBOX_SetFont(hItem, GUI_FONT_COMIC18B_1);
	//
	// Initialization of volume spinbox
	//
	hItem = WM_GetDialogItem(pMsg->hWin,  ID_SPINBOX_1);
	SPINBOX_SetRange(hItem, 0, 15);
	SPINBOX_SetFont(hItem, GUI_FONT_COMIC18B_1);
    //
    // Initialization of 'power'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "Power On");
    BUTTON_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'reset'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, "Reset");
    BUTTON_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'seekdown'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetText(hItem, "Seek Down");
    BUTTON_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'seekup'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetText(hItem, "Seek Up");
    BUTTON_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'mute'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "Mute");
    CHECKBOX_SetTextColor(hItem, 0x00FFFFFF);
    CHECKBOX_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'tittle'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, GUI_FONT_COMIC18B_1);
    TEXT_SetTextColor(hItem, 0x00FFFFFF);
    TEXT_SetText(hItem, "RDA5807M FM");
    //
    // Initialization of 'text1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetFont(hItem, GUI_FONT_COMIC18B_1);
    TEXT_SetTextColor(hItem, 0x00FFFFFF);
    TEXT_SetText(hItem, "Frequency:");
    //
    // Initialization of 'text2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetFont(hItem, GUI_FONT_COMIC18B_1);
    TEXT_SetTextColor(hItem, 0x00FFFFFF);
    TEXT_SetText(hItem, "");
    //
    // Initialization of 'bass'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
    CHECKBOX_SetText(hItem, "Bass");
    CHECKBOX_SetTextColor(hItem, 0x00FFFFFF);
    CHECKBOX_SetFont(hItem, GUI_FONT_8X16);
    //
    // Initialization of 'rds'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
    CHECKBOX_SetText(hItem, "RDS");
    CHECKBOX_SetTextColor(hItem, 0x00FFFFFF);
    CHECKBOX_SetFont(hItem, GUI_FONT_8X16);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'power'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
      	if((RDA5807M_WriteReg[0] & 1) == 0){
      		RDA5807_PowerOn();
      		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
      		BUTTON_SetText(hItem, "Power Off");
      	}
      	else{
  			RDA5807_PowerOff();
      		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
      		BUTTON_SetText(hItem, "Power On");
      	}
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'reset'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	RDA5807_Reset();
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'seekdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	RDA5807_SeekDown();
    	GUI_Delay(200);
    	RDA5807_Read();
    	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    	frq = (float)freq / 1000;
    	int d1 = frq;
    	int d2= (frq - d1)*100;
    	sprintf (bufem, "%d.%dMHz", d1, d2);
    	TEXT_SetText(hItem,bufem);
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by 'seekup'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	RDA5807_SeekUp();
		GUI_Delay(200);
    	RDA5807_Read();
    	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    	frq = (float)freq / 1000;
    	int d1 = frq;
    	int d2= (frq - d1)*100;
    	sprintf (bufem, "%d.%dMHz", d1, d2);
        TEXT_SetText(hItem,bufem);
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'mute'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	RDA5807_Mute();
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_0: // Notifications sent by 'Spinbox' channel
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	frq = SPINBOX_GetValue(pMsg->hWinSrc);
    	RDA5807_Frequency(((float)frq/(float)100));
    	RDA5807_Read();
    	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    	frq = (float)freq / 1000;
    	int d1 = frq;
    	int d2= (frq - d1)*100;
    	sprintf (bufem, "%d.%dMHz", d1, d2);
    	TEXT_SetText(hItem,bufem);
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_1: // Notifications sent by 'Spinbox' volume
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        RDA5807_Volume(SPINBOX_GetValue(pMsg->hWinSrc));
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_1: // Notifications sent by 'bass'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
    	RDA5807_BassBoost();
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_2: // Notifications sent by 'rds'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
/*
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}
*/
// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
