#ifndef _OVL26_H_
#define _OVL26_H_

#include <ssb_types.h>
#include <sys/obj_renderer.h>

typedef struct mnCharPanelBattle
{
	GObj* cursor;
	GObj* token;
	GObj* player;
	GObj* type_button;
	GObj* name_logo;
	GObj* panel_doors;
	GObj* panel;
	GObj* team_color_button;
	GObj* handicap_cpu_level;
	GObj* arrows;
	GObj* handicap_cpu_level_value;
	GObj* white_square;
	GObj* type;
	void* anim_heap;
	u32 cpu_level;
	u32 handicap;
	s32 team;
	u32 unk_0x44;
	s32 char_id;
	u32 costume_id;
	u32 shade;
	s32 cursor_state;
	sb32 is_selected;
	sb32 is_recalling;
	s32 min_frames_elapsed_until_recall;
	f32 recall_start_x;
	f32 recall_end_x;
	f32 recall_start_y;
	f32 recall_mid_y;
	f32 recall_end_y;
	s32 recall_frame_counter;
	s32 holder_port_id;
	s32 held_port_id;
	s32 player_type;
	sb32 unk_0x88;
	sb32 selected_animation_started;
	f32 token_x_velocity;
	f32 token_y_velocity;
	f32 cursor_pickup_x;
	f32 cursor_pickup_y;
	sb32 unk_0xA0;
	s32 door_offset;
	alSoundEffect* p_sfx;
	u16 sfx_id;
	u16 unk_0xAE;
	sb32 is_b_held;
	u32 unk_0xB4;
	s32 b_held_frame_count;

} mnCharPanelBattle;

typedef enum mnSelectButton
{
	mnSelect_CU, // C-Up
	mnSelect_CR, // C-Right
	mnSelect_CD, // C-Down
	mnSelect_CL, // C-Left
	mnSelect_A	 // A

} mnSelectButton;

typedef enum mnPanelType
{
	mnPanelTypeHuman, // HMN
	mnPanelTypeCPU,	  // CPU
	mnPanelTypeNA	  // NA

} mnPanelType;

typedef enum mnCursorState
{
	mnCursorStatePointer,		 // Pointer
	mnCursorStateHoldingToken,	 // Holding token
	mnCursorStateNotHoldingToken // Not holding token
} mnCursorState;

#define GetAddressFromOffset(file_ptr, offset) ((int*)((intptr_t)(file_ptr) + (intptr_t)(offset)))

extern intptr_t D_NF_800A5240;	   // 0x800A5240
extern intptr_t lOverlay26ArenaLo; // 0x8013C4C0
extern intptr_t lOverlay26ArenaHi; // 0x803903E0

extern f32 guSqrt(f32);
extern s32 lbRandom_GetIntRange(s32);
extern u8 lbRandom_GetTimeByteRange(s32);
extern void stop_current_process(s32);
extern void leoInitUnit_atten();
// ovl0
extern void func_ovl0_800CD2CC();
extern GObj* func_ovl0_800CD050(s32, void*, s32, s32, void*, s32, s32, s32, void*, s32, void*, s32);
extern void func_ovl0_800CD1F0(s32, s32, s32, s32);
extern void func_ovl0_800CCF74(GObj*);
extern SObj* gcAppendSObjWithSprite(GObj*, void*);
// ovl1
extern f32 menu_zoom[12]; // D_ovl1_80390D90
// ovl2
extern u32 D_ovl2_80130D9C;
extern u8 D_ovl2_8012EF40[4];
extern u32 D_ovl2_80130D9C;

extern uintptr_t D_NF_001AC870;
extern uintptr_t D_NF_00000854;

// ovl26 stuff
RldmFileId D_ovl26_8013B3A0[7];

f32 dMnBattlePortraitPositionsX[12];	   // 0x8013B3F0
f32 dMnBattlePortraitVelocities[12];	   // 0x8013B420
Vec2f dMnBattlePortraitPositionsXY[12]; // 0x8013B450[12];

s32 dMnBattleFtKindOrder[12];						// 0x8013B4D4[12];
s32 dMnBattlePortraitOrder[12];						// 0x8013B504[12];
s32 dMnBattleLockedPortraitOffsets[12];				// 0x8013B534[12];
s32 dMnBattlePortraitOffsets[12];					// 0x8013B564[12];
s32 dMnBattleTeamButtonOffsets[3];					// 0x8013B594[3];
s32 dMnBattleTypeButtonOffsets[3];					// 0x8013B5A0[3];
Vec2f dMnBattleUnusedPositions[12];					// 0x8013B5AC[12];
s32 dMnBattleLogoOffsets[12];						// 0x8013B60C[12];
s32 dMnBattleNameOffsets[12];						// 0x8013B63C[12];
intptr_t dMnBattlePanelOffsets[4];					// 0x8013B66C[4];
intptr_t dMnBattlePanelCPUOffsets[4];				// 0x8013B67C[4];
GfxColor dMnBattleUnusedColors[4];					// 0x8013B68C[4]
intptr_t dMnBattleTypeButtonOffsetsDuplicate[3];		// 0x8013B698[3];
intptr_t dMnBattleTypeOffsets[4];					// 0x8013B6A4[4];
f32 dMnBattleTypeOffsetsX[4];						// 0x8013B6B4[4];
intptr_t dMnBattleTypeOffsetsDuplicate[4];			// 0x8013B6C4[4];
f32 dMnBattleTypeOffsetsXDuplicate[4];				// 0x8013B6D4[4];
intptr_t dMnBattlePanelProcRenderList[4];			// 0x8013B6E4[4];
s32 dMnBattlePaletteIndexes[4];						// 0x8013B6F4[4];
intptr_t dMnBattleNumberOffsets[10];					// 0x8013B704[10];
s32 dMnBattleNumberColorsTime[6];					// 0x8013B72C[6];
s32 dMnBattleNumberColorsStock[6];					// 0x8013B744[6];
intptr_t dMnBattleTitleOffsets[2];					// 0x8013B75C[2]; // title offsets
GfxColor dMnBattleTitleColors[2];					// 0x8013B764[2]; // title colors
GfxColorPair dMnBattleCursorTypeColors[4];			// 0x8013B76C[4]; // cursor
															// type texture colors
intptr_t dMnBattleCursorTypeOffsets[4];				// 0x8013B784[4]; // cursor type
															// texture offsets
intptr_t dMnBattleCursorOffsets[3];					// 0x8013B794[3]; // cursor offsets
Vec2i dMnBattleCursorTypePositions[3];				// 0x8013B7A0[3]; // x,y offset
															// pairs for cursor type texture
s32 dMnBattlePanelColorIndexes[4];					// 0x8013B7B8[4]; // panel color indexes
intptr_t dMnBattleTitleOffsetsDuplicate[2];			// 0x8013B7C8[2]; //
															// ffa/team battle offsets
GfxColor dMnBattleTitleColorsDuplicate[2];			// 0x8013B7D0[2]; // ffa/team
															// battle colors
s32 dMnBattleTeamPaletteIndexes[3];					// 0x8013B7D8[3]; // team panel
															// color indexes
s32 D_ovl26_8013B7E4[3];								// ??
s32 dMnBattleTokenIndexes[4];						// 0x8013B7F0[4]; // token_ids
u16 dMnBattleAnnouncerNames[12];						// 0x8013B800[12]; // announcer names
intptr_t dMnBattleHandicapCPULevelNumberOffsets[10]; // 0x8013B818[10];
s32 dMnBattleTokenPickupDisplayOrders[4];			// 0x8013B840[4]; // display orders
															// for cursors on token pickup
s32 dMnBattleTokenPlaceHeldDisplayOrders[4];			// 0x8013B850[4]; // display
															// orders for cursors holding
															// tokens on token placement
s32 dMnBattleTokenPlaceUnheldDisplayOrders[4]; // 0x8013B860[4]; // display orders for cursors not holding tokens
													  // on token placement
Vec2i dMnBattleCursorTypePositions2[3];		  // 0x8013B870[3]; // x,y offset
													  // pairs for cursor type texture
intptr_t dMnBattleTokenOffsets[5];			  // 0x8013B888[5]; // token offsets
intptr_t dMnBattleCursorTypeOffsetsUnused[4];  // 0x8013B89C[4]; // cursor
													  // type texture offsets
Vec2f dMnBattleCursorStartingPositions[4];	  // 0x8013B8AC[4]; // starting
													  // coords for cursors
s32 dMnBattleCursorStartingDisplayOrders[4];	  // 0x8013B8CC[4]; // display orders for cursors on initial load
intptr_t dMnBattleTokenOffsetsNoCPU[4];		  // 0x8013B8DC; // token offsets
													  // not including cpu
s32 dMnBattleTokenStartingDisplayOrders[4];	  // 0x8013B8EC; // display orders
													  // for tokens on initial load
s32 dMnBattleTokenHoldingDisplayOrders[4];	  // 0x8013B8FC; // display
													  // orders for tokens while
													  // being held initially?
f32 dMnBattleWhiteCircleSizes[12];			  // 0x8013B90C[12]; // white circle size
s32 dMnBattleTimerValues[8];					  // 0x8013B93C[8];
s32 dMnBattleTimerValuesDuplicate[8];		  // 0x8013B95C[8];
u8 dMnBattleDefaultTeam[4];					  // 0x8013B97C[4]; // default team
scUnkDataBounds D_ovl26_8013B980;
scRuntimeInfo D_ovl26_8013B99C;

mnCharPanelBattle gMnBattlePanels[GMMATCH_PLAYERS_MAX]; // 0x8013BA88[GMMATCH_PLAYERS_MAX];
GObj* gMnBattlePickerGObj;							   // 0x8013BD78; // stock/time picker
s32 gMnBattleTimerValue;								   // 0x8013BD7C;
s32 gMnBattleStockValue;								   // 0x8013BD80;
s32 gMnBattleControllerOrderArray[4];				   // 0x8013BD90; // -1 if no controller
															   // plugged in; due to a bug, random
															   // positive value if plugged in

s32 gMnBattleStartDelayTimer;		 // 0x8013BDA0; // when start is pressed
											 // when ready to fight, timer counts down
											 // to delay leaving CSS
sb32 gMnBattleIsStartTriggered;		 // 0x8013BDA4;
sb32 gMnBattleIsTeamBattle;			 // 0x8013BDA8
sb32 gMnBattleRule;					 // 0x8013BDAC
GObj* gMnBattleTitleGObj;			 // 0x8013BDB0; // title gobj
s32 gMnBattleTokenShinePulseColor;	 // 0x8013BDB4;
sb32 gMnBattleIsTokenShineIncreasing; // 0x8013BDB8;
u16 gMnBattleCharacterUnlockedMask;	 // 0x8013BDBC; // flag indicating
											 // which bonus chars are available

s32 gMnBattlePressStartFlashTimer; // 0x8013BDC4; looping timer that
										  // helps determine blink rate of
										  // Press Start (and Ready to Fight?)
s32 D_ovl26_8013BDC8;
s32 gMnBattleFramesElapsed;	  // 0x8013BDCC; // frames elapsed on CSS
s32 gMnBattleMaxFramesElapsed; // 0x8013BDD0; // frames to wait until
									  // exiting the CSS
RldmFileNode D_ovl26_8013C0A8;
u32 D_ovl26_8013C0E0[240];

s32 gMnBattleFilesArray[7]; // 0x8013C4A0[7]
s32 gFile011;			   // 0x8013C4A0; // file 0x011 pointer
s32 gFile000;			   // 0x8013C4A4; // file 0x000 pointer
s32 gFile014;			   // 0x8013C4A8; // file 0x014 pointer
s32 gFile015;			   // 0x8013C4AC; // file 0x015 pointer
s32 gFile012;			   // 0x8013C4B0; // file 0x012 pointer
s32 gFile013;			   // 0x8013C4B4; // file 0x013 pointer
s32 gFile016;			   // 0x8013C4B8; // file 0x016 pointer

// Offsets
extern intptr_t FILE_000_COLON_IMAGE_OFFSET = 0xDCF0; // file 0x000 image offset for colon

extern intptr_t FILE_011_TYPE_CP_IMAGE_OFFSET = 0xFF8;		   // file 0x011 image offset for CP type image
extern intptr_t FILE_011_HANDICAP_IMAGE_OFFSET = 0x1108;	   // file 0x011 image offset for Handicap image
extern intptr_t FILE_011_CPU_LEVEL_IMAGE_OFFSET = 0x1218;	   // file 0x011 image offset for CPU Level image
extern intptr_t FILE_011_START_IMAGE_OFFSET = 0x1378;		   // Press Start's "Start" texture
extern intptr_t FILE_011_PRESS_IMAGE_OFFSET = 0x14D8;		   // Press Start's "Press" texture
extern intptr_t FILE_011_INFINITY_IMAGE_OFFSET = 0x3EF0;	   // file 0x011 image offset for infinity symbol
extern intptr_t FILE_011_PICKER_TIME_IMAGE_OFFSET = 0x48B0;	   // file 0x011 image offset for Time picker texture
extern intptr_t FILE_011_PICKER_STOCK_IMAGE_OFFSET = 0x5270;   // file 0x011 image offset for Stock picker texture
extern intptr_t FILE_011_CURSOR_POINTER_IMAGE_OFFSET = 0x76E8; // file 0x011 image offset for pointer cursor
extern intptr_t FILE_011_PANEL_DOOR_L_IMAGE_OFFSET = 0xCDB0;
extern intptr_t FILE_011_PANEL_DOOR_R_IMAGE_OFFSET = 0xDFA0;
extern intptr_t FILE_011_ARROW_L_IMAGE_OFFSET = 0xECE8;			  // file 0x011 image offset for left arrow
extern intptr_t FILE_011_ARROW_R_IMAGE_OFFSET = 0xEDC8;			  // file 0x011 image offset for right arrow
extern intptr_t FILE_011_READY_TO_FIGHT_IMAGE_OFFSET = 0xF448;	  // Ready to Fight banner text
extern intptr_t FILE_011_READY_TO_FIGHT_BG_IMAGE_OFFSET = 0xF530; // Ready to Fight banner bg
extern intptr_t FILE_011_PANEL_IMAGE_OFFSET = 0x104B0;
extern intptr_t FILE_011_BACK_IMAGE_OFFSET = 0x115C8; // file 0x011 image offset for

extern s32 FILE_013_XBOX_IMAGE_OFFSET = 0x2B8; // file 0x013 image offset
extern intptr_t FILE_013_WHITE_SQUARE = 0x6F0; // white square
extern s32 FILE_013_PORTRAIT_QUESTION_MARK_IMAGE_OFFSET
	= 0xF68;												// file 0x013 image offset for portrait question mark image
extern s32 FILE_013_PORTRAIT_FIRE_BG_IMAGE_OFFSET = 0x24D0; // file 0x013 image offset for portrait bg (fire) image

extern intptr_t FILE_015_BACKGROUND_IMAGE_OFFSET = 0x440; // file 0x015 image offset for background tile

extern intptr_t FILE_016_WHITE_CIRCLE_OFFSET_1 = 0x408; // AObj? for white circle
extern intptr_t FILE_016_WHITE_CIRCLE_OFFSET_2 = 0x568; // DObjDesc for white circle

void ftRender_Lights_DisplayLightReflect(Gfx**, f32, f32);	  /* extern */
extern f32 func_ovl1_8039051C();							  /* extern */
extern f32 func_ovl1_80390528();							  /* extern */
extern void func_ovl0_800CCF00(GObj*);						  /* extern */
extern void func_ovl1_803904E0(f32, f32, s32, s32, s32, s32); /* extern */
extern void func_ovl0_800CD2CC();
extern GObj* func_8000B93C(u32, void*, s32, u32, void*, s32, s64, s32, s32, s32, s32, s32, s32); /* extern */
extern void func_80007080(void*, f32, f32, f32, f32);											 /* extern */
sb32 mnBattleIsCostumeInUse(s32 ft_kind, s32 port_id, s32 costume_id);
void mnBattleRedrawCursor(GObj* cursor_gobj, s32 port_id, s32 cursor_state);
s32 mnCheckCPUHandicapRightArrowPress(GObj* cursor_gobj, s32 port_id);
s32 mnCheckCPUHandicapLeftArrowPress(GObj* cursor_gobj, s32 port_id);
void mnBattleSyncNameAndLogo(s32 port_id);
void mnBattleCreateWhiteSquare(s32 port_id);
void mnBattleAnnounceFighter(s32 port_id, s32 panel_id);
void mnBattleDrawHandicapCPULevel(s32 port_id);
void mnDrawHandicapCPULevelValue(s32 port_id);
void mnReplaceFighterNameWithHandicapCPULevel(s32 port_id);
sb32 mnIsHandicapOn();
sb32 mnIsHandicapAuto();
sb32 mnIsHandicap();
void mnBattleReorderCursorsOnPickup(s32 port_id, s32 token_id);
s32 mnBattleReorderCursorsOnPlacement(s32 port_id, s32 held_token_id); // doesn't actually return anything but
																	   // required to match
void mnBattleRedrawToken(GObj* token_gobj, s32 token_index);
s32 mnSelectRandomFighter(GObj* token_gobj);
sb32 mnBattleIsReadyToFight();
void mnBattleDestroyCursorAndTokenProcesses();
void mnBattleSaveMatchInfo();
s32 mnBattleGetNextTimerValue(s32 current_value);
s32 mnBattleGetPrevTimerValue(s32 current_value);

#endif