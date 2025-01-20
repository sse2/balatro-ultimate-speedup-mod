#include <windows.h>
#include <stdio.h>

HMODULE o_luasteam_handle = NULL;

#define LUASTEAM_EXPORT( ... )                                                                 \
 __declspec ( dllexport ) int __VA_ARGS__ ( void *L )                                          \
 {                                                                                             \
  static int ( __cdecl * o_fn ) ( void * ) = NULL;                                             \
  if ( !o_fn )                                                                                 \
   o_fn = ( int ( __cdecl * ) ( void * ) ) GetProcAddress ( o_luasteam_handle, #__VA_ARGS__ ); \
  if ( o_fn )                                                                                  \
  {                                                                                            \
   puts ( "calling " #__VA_ARGS__ "\n" );                                                      \
   return o_fn ( L );                                                                          \
  }                                                                                            \
  return 0;                                                                                    \
 }

LUASTEAM_EXPORT ( luaopen_luasteam );
LUASTEAM_EXPORT ( luasteam_activateActionSet );
LUASTEAM_EXPORT ( luasteam_activateActionSetLayer );
LUASTEAM_EXPORT ( luasteam_activateGameOverlay );
LUASTEAM_EXPORT ( luasteam_activateGameOverlayToWebPage );
LUASTEAM_EXPORT ( luasteam_createItem );
LUASTEAM_EXPORT ( luasteam_deactivateActionSetLayer );
LUASTEAM_EXPORT ( luasteam_deactivateAllActionSetLayers );
LUASTEAM_EXPORT ( luasteam_downloadLeaderboardEntries );
LUASTEAM_EXPORT ( luasteam_equint64 );
LUASTEAM_EXPORT ( luasteam_findLeaderboard );
LUASTEAM_EXPORT ( luasteam_findOrCreateLeaderboard );
LUASTEAM_EXPORT ( luasteam_getAchievement );
LUASTEAM_EXPORT ( luasteam_getActionOriginFromXboxOrigin );
LUASTEAM_EXPORT ( luasteam_getActionSetHandle );
LUASTEAM_EXPORT ( luasteam_getActiveActionSetLayers );
LUASTEAM_EXPORT ( luasteam_getAnalogActionData );
LUASTEAM_EXPORT ( luasteam_getAnalogActionHandle );
LUASTEAM_EXPORT ( luasteam_getAnalogActionOrigins );
LUASTEAM_EXPORT ( luasteam_getAppID );
LUASTEAM_EXPORT ( luasteam_getConnectedControllers );
LUASTEAM_EXPORT ( luasteam_getControllerForGamepadIndex );
LUASTEAM_EXPORT ( luasteam_getCurrentActionSet );
LUASTEAM_EXPORT ( luasteam_getCurrentGameLanguage );
LUASTEAM_EXPORT ( luasteam_getDeviceBindingRevision );
LUASTEAM_EXPORT ( luasteam_getDigitalActionData );
LUASTEAM_EXPORT ( luasteam_getDigitalActionHandle );
LUASTEAM_EXPORT ( luasteam_getDigitalActionOrigins );
LUASTEAM_EXPORT ( luasteam_getFriendPersonaName );
LUASTEAM_EXPORT ( luasteam_getGamepadIndexForController );
LUASTEAM_EXPORT ( luasteam_getGlyphForActionOrigin );
LUASTEAM_EXPORT ( luasteam_getInputTypeForHandle );
LUASTEAM_EXPORT ( luasteam_getItemInstallInfo );
LUASTEAM_EXPORT ( luasteam_getItemState );
LUASTEAM_EXPORT ( luasteam_getItemUpdateProgress );
LUASTEAM_EXPORT ( luasteam_getLeaderboardDisplayType );
LUASTEAM_EXPORT ( luasteam_getLeaderboardEntryCount );
LUASTEAM_EXPORT ( luasteam_getLeaderboardName );
LUASTEAM_EXPORT ( luasteam_getLeaderboardSortMethod );
LUASTEAM_EXPORT ( luasteam_getMotionData );
LUASTEAM_EXPORT ( luasteam_getNumSubscribedItems );
LUASTEAM_EXPORT ( luasteam_getPlayerSteamLevel );
LUASTEAM_EXPORT ( luasteam_getRemotePlaySessionID );
LUASTEAM_EXPORT ( luasteam_getStatFloat );
LUASTEAM_EXPORT ( luasteam_getStatInt );
LUASTEAM_EXPORT ( luasteam_getSteamID );
LUASTEAM_EXPORT ( luasteam_getStringForActionOrigin );
LUASTEAM_EXPORT ( luasteam_getSubscribedItems );
LUASTEAM_EXPORT ( luasteam_init );
LUASTEAM_EXPORT ( luasteam_input_init );
LUASTEAM_EXPORT ( luasteam_input_shutdown );
LUASTEAM_EXPORT ( luasteam_parseUint64 );
LUASTEAM_EXPORT ( luasteam_requestCurrentStats );
LUASTEAM_EXPORT ( luasteam_resetAllStats );
LUASTEAM_EXPORT ( luasteam_runCallbacks );
LUASTEAM_EXPORT ( luasteam_runFrame );
LUASTEAM_EXPORT ( luasteam_setAchievement );
LUASTEAM_EXPORT ( luasteam_setItemContent );
LUASTEAM_EXPORT ( luasteam_setItemDescription );
LUASTEAM_EXPORT ( luasteam_setItemPreview );
LUASTEAM_EXPORT ( luasteam_setItemTitle );
LUASTEAM_EXPORT ( luasteam_setLEDColor );
LUASTEAM_EXPORT ( luasteam_setRichPresence );
LUASTEAM_EXPORT ( luasteam_setStatFloat );
LUASTEAM_EXPORT ( luasteam_setStatInt );
LUASTEAM_EXPORT ( luasteam_showBindingPanel );
LUASTEAM_EXPORT ( luasteam_shutdown );
LUASTEAM_EXPORT ( luasteam_startItemUpdate );
LUASTEAM_EXPORT ( luasteam_startPlaytimeTracking );
LUASTEAM_EXPORT ( luasteam_stopAnalogActionMomentum );
LUASTEAM_EXPORT ( luasteam_stopPlaytimeTracking );
LUASTEAM_EXPORT ( luasteam_stopPlaytimeTrackingForAllItems );
LUASTEAM_EXPORT ( luasteam_storeStats );
LUASTEAM_EXPORT ( luasteam_submitItemUpdate );
LUASTEAM_EXPORT ( luasteam_translateActionOrigin );
LUASTEAM_EXPORT ( luasteam_triggerHapticPulse );
LUASTEAM_EXPORT ( luasteam_triggerRepeatedHapticPulse );
LUASTEAM_EXPORT ( luasteam_triggerVibration );
LUASTEAM_EXPORT ( luasteam_uint64ToString );
LUASTEAM_EXPORT ( luasteam_uploadLeaderboardScore );

float g_mult = 2.0f;

void get_multiplier_from_file ( )
{
 FILE *f = fopen ( "speedhax.cfg", "r" );
 if ( !f )
  return;

 fscanf_s ( f, "%f", &g_mult );
 fclose ( f );
}

typedef BOOL WINAPI queryperfcounter_kind ( LARGE_INTEGER *lpPerformanceCount );
queryperfcounter_kind *o_queryperfcounter = QueryPerformanceCounter;

BOOL WINAPI hk_queryperfcounter ( LARGE_INTEGER *lpPerformanceCount )
{
 static LARGE_INTEGER freq;
 if ( !freq.QuadPart )
  o_queryperfcounter ( &freq );

 BOOL res = o_queryperfcounter ( lpPerformanceCount );
 lpPerformanceCount->QuadPart = ( LONGLONG ) ( ( double ) ( lpPerformanceCount->QuadPart ) * g_mult );
 return res;
}

void init ( )
{
 o_luasteam_handle = LoadLibraryA ( "luasteam.original.dll" );
 if ( !o_luasteam_handle )
 {
  MessageBoxA ( NULL, "failed to load luasteam.original.dll, make sure you followed the install instructions correctly!", "", MB_ICONERROR );
  ExitProcess ( 0 );
  return;
 }

 get_multiplier_from_file ( );
 HANDLE kernel32 = GetModuleHandleA ( "kernel32.dll" );

 IMAGE_NT_HEADERS64 *p_nt = ( IMAGE_NT_HEADERS64 * ) ( ( BYTE * ) kernel32 + ( ( IMAGE_DOS_HEADER * ) kernel32 )->e_lfanew );
 IMAGE_IMPORT_DESCRIPTOR *p_import = ( IMAGE_IMPORT_DESCRIPTOR * ) ( ( BYTE * ) kernel32 + p_nt->OptionalHeader.DataDirectory[ IMAGE_DIRECTORY_ENTRY_IMPORT ].VirtualAddress );

 for ( ; p_import->Name; p_import++ )
 {
  IMAGE_THUNK_DATA64 *p_thunk = ( IMAGE_THUNK_DATA64 * ) ( ( BYTE * ) kernel32 + p_import->OriginalFirstThunk );
  IMAGE_THUNK_DATA64 *p_iat = ( IMAGE_THUNK_DATA64 * ) ( ( BYTE * ) kernel32 + p_import->FirstThunk );

  for ( ; p_thunk->u1.AddressOfData; p_thunk++, p_iat++ )
  {
   const char *func_name = ( const char * ) ( ( BYTE * ) kernel32 + p_thunk->u1.AddressOfData + 2 );
   if ( !strcmp ( func_name, "QueryPerformanceCounter" ) )
   {
    DWORD oldProtect;
    VirtualProtect ( &p_iat->u1.Function, sizeof ( p_iat->u1.Function ), PAGE_EXECUTE_READWRITE, &oldProtect );
    o_queryperfcounter = ( queryperfcounter_kind * ) p_iat->u1.Function;
    p_iat->u1.Function = ( ULONGLONG ) &hk_queryperfcounter;
    VirtualProtect ( &p_iat->u1.Function, sizeof ( p_iat->u1.Function ), oldProtect, &oldProtect );
    break;
   }
  }
 }
}

BOOL APIENTRY DllMain ( HMODULE mod, DWORD reason, LPVOID reserved )
{
 if ( reason == DLL_PROCESS_ATTACH )
  init ( );

 return TRUE;
}