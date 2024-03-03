#ifndef _OVL26_H_
#define _OVL26_H_

#include <ssb_types.h>
#include <sys/obj_renderer.h>

// EXTERN
extern intptr_t D_NF_800A5240;      // 0x800A5240
extern intptr_t lOverlay26ArenaLo;  // 0x8013C4C0
extern intptr_t lOverlay26ArenaHi;  // 0x803903E0

// DATA
// TODO!

// Stuff - where does it go?!?

typedef struct mnCharPanelBattle
{
	GObj *cursor;
	GObj *token;
	GObj *player;
	GObj *type_button;
	GObj *name_logo;
	GObj *panel_doors;
	GObj *panel;
	GObj *team_color_button;
	GObj *handicap_cpu_level;
	GObj *arrows;
	GObj *handicap_cpu_level_value;
	GObj *white_square;
	GObj *type;
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
	alSoundEffect *p_sfx;
	u16 sfx_id;
	u16 unk_0xAE;
	sb32 is_b_held;
	u32 unk_0xB4;
	s32 b_held_frame_count;

} mnCharPanelBattle;

typedef enum mnSelectButton
{
	mnSelect_CU,                // C-Up
	mnSelect_CR,                // C-Right
	mnSelect_CD,                // C-Down
	mnSelect_CL,                // C-Left
	mnSelect_A                  // A

} mnSelectButton;

typedef enum mnPanelType
{
	mnPanelTypeHuman,           // HMN
	mnPanelTypeCPU,             // CPU
	mnPanelTypeNA               // NA

} mnPanelType;

typedef enum mnCursorState
{
	mnCursorStatePointer,         // Pointer
	mnCursorStateHoldingToken,    // Holding token
	mnCursorStateNotHoldingToken  // Not holding token
} mnCursorState;

#define GetAddressFromOffset(file_ptr, offset) \
((int*)((intptr_t)(file_ptr) + (intptr_t)(offset))) \

// ovl1 stuff
extern f32 menu_zoom[12]; // D_ovl1_80390D90

// ovl26 stuff
extern RldmFileId D_ovl26_8013B3A0[7];

extern f32 dMnBattlePortraitPositionsX[12]; // 0x8013B3F0
extern f32 dMnBattlePortraitVelocities[12]; // 0x8013B420
extern Vec2f dMnBattlePortraitPositionsXY[12]; // 0x8013B450[12];

extern s32 dMnBattleFtKindOrder[12]; // 0x8013B4D4[12];
extern s32 dMnBattlePortraitOrder[12]; // 0x8013B504[12];
extern s32 dMnBattleLockedPortraitOffsets[12]; // 0x8013B534[12];
extern s32 dMnBattlePortraitOffsets[12]; // 0x8013B564[12];
extern s32 dMnBattleTeamButtonOffsets[3]; // 0x8013B594[3];
extern s32 dMnBattleTypeButtonOffsets[3]; // 0x8013B5A0[3];
extern Vec2f dMnBattleUnusedPositions[12]; // 0x8013B5AC[12];
extern s32 dMnBattleLogoOffsets[12]; // 0x8013B60C[12];
extern s32 dMnBattleNameOffsets[12]; // 0x8013B63C[12];
extern intptr_t dMnBattlePanelOffsets[4]; // 0x8013B66C[4];
extern intptr_t dMnBattlePanelCPUOffsets[4]; // 0x8013B67C[4];
extern GfxColor dMnBattleUnusedColors[4]; // 0x8013B68C[4]
extern intptr_t dMnBattleTypeButtonOffsetsDuplicate[3]; // 0x8013B698[3];
extern intptr_t dMnBattleTypeOffsets[4]; // 0x8013B6A4[4];
extern f32 dMnBattleTypeOffsetsX[4]; // 0x8013B6B4[4];
extern intptr_t dMnBattleTypeOffsetsDuplicate[4]; // 0x8013B6C4[4];
extern f32 dMnBattleTypeOffsetsXDuplicate[4]; // 0x8013B6D4[4];
extern intptr_t dMnBattlePanelProcRenderList[4]; // 0x8013B6E4[4];
extern s32 dMnBattlePaletteIndexes[4]; // 0x8013B6F4[4];
extern intptr_t dMnBattleNumberOffsets[10]; // 0x8013B704[10];
extern s32 dMnBattleNumberColorsTime[6]; // 0x8013B72C[6];
extern s32 dMnBattleNumberColorsStock[6]; // 0x8013B744[6];
extern intptr_t dMnBattleTitleOffsets[2]; // 0x8013B75C[2]; // title offsets
extern GfxColor dMnBattleTitleColors[2]; // 0x8013B764[2]; // title colors
extern GfxColorPair dMnBattleCursorTypeColors[4]; // 0x8013B76C[4]; // cursor type texture colors
extern intptr_t dMnBattleCursorTypeOffsets[4]; // 0x8013B784[4]; // cursor type texture offsets
extern intptr_t dMnBattleCursorOffsets[3]; // 0x8013B794[3]; // cursor offsets
extern Vec2i dMnBattleCursorTypePositions[3]; // 0x8013B7A0[3]; // x,y offset pairs for cursor type texture
extern s32 dMnBattlePanelColorIndexes[4]; // 0x8013B7B8[4]; // panel color indexes
extern intptr_t dMnBattleTitleOffsetsDuplicate[2]; // 0x8013B7C8[2]; // ffa/team battle offsets
extern GfxColor dMnBattleTitleColorsDuplicate[2]; // 0x8013B7D0[2]; // ffa/team battle colors
extern s32 dMnBattleTeamPaletteIndexes[3]; // 0x8013B7D8[3]; // team panel color indexes
extern s32 D_ovl26_8013B7E4[3]; // ??
extern s32 dMnBattleTokenIndexes[4]; // 0x8013B7F0[4]; // token_ids
extern u16 dMnBattleAnnouncerNames[12]; // 0x8013B800[12]; // announcer names
extern intptr_t dMnBattleHandicapCPULevelNumberOffsets[10]; // 0x8013B818[10];
extern s32 dMnBattleTokenPickupDisplayOrders[4]; // 0x8013B840[4]; // display orders for cursors on token pickup
extern s32 dMnBattleTokenPlaceHeldDisplayOrders[4]; // 0x8013B850[4]; // display orders for cursors holding tokens on token placement
extern s32 dMnBattleTokenPlaceUnheldDisplayOrders[4]; // 0x8013B860[4]; // display orders for cursors not holding tokens on token placement
extern Vec2i dMnBattleCursorTypePositions2[3]; // 0x8013B870[3]; // x,y offset pairs for cursor type texture
extern intptr_t dMnBattleTokenOffsets[5]; // 0x8013B888[5]; // token offsets
extern intptr_t dMnBattleCursorTypeOffsetsUnused[4]; // 0x8013B89C[4]; // cursor type texture offsets
extern Vec2f dMnBattleCursorStartingPositions[4]; // 0x8013B8AC[4]; // starting coords for cursors
extern s32 dMnBattleCursorStartingDisplayOrders[4]; // 0x8013B8CC[4]; // display orders for cursors on initial load
extern intptr_t dMnBattleTokenOffsetsNoCPU[4]; // 0x8013B8DC; // token offsets not including cpu
extern s32 dMnBattleTokenStartingDisplayOrders[4]; // 0x8013B8EC; // display orders for tokens on initial load
extern s32 dMnBattleTokenHoldingDisplayOrders[4]; // 0x8013B8FC; // display orders for tokens while being held initially?
extern f32 dMnBattleWhiteCircleSizes[12]; // 0x8013B90C[12]; // white circle size
extern s32 dMnBattleTimerValues[8]; // 0x8013B93C[8];
extern s32 dMnBattleTimerValuesDuplicate[8]; // 0x8013B95C[8];
extern u8 dMnBattleDefaultTeam[4]; // 0x8013B97C[4]; // default team
extern scUnkDataBounds D_ovl26_8013B980;
extern scRuntimeInfo D_ovl26_8013B99C;

extern mnCharPanelBattle gMnBattlePanels[GMMATCH_PLAYERS_MAX]; // 0x8013BA88[GMMATCH_PLAYERS_MAX];
extern GObj* gMnBattlePickerGObj; // 0x8013BD78; // stock/time picker
extern s32 gMnBattleTimerValue; // 0x8013BD7C;
extern s32 gMnBattleStockValue; // 0x8013BD80;
extern s32 gMnBattleControllerOrderArray[4]; // 0x8013BD90; // -1 if no controller plugged in; due to a bug, random positive value if plugged in

extern s32 gMnBattleStartDelayTimer; // 0x8013BDA0; // when start is pressed when ready to fight, timer counts down to delay leaving CSS
extern sb32 gMnBattleIsStartTriggered; // 0x8013BDA4;
extern sb32 gMnBattleIsTeamBattle; // 0x8013BDA8
extern sb32 gMnBattleRule; // 0x8013BDAC
extern GObj* gMnBattleTitleGObj; // 0x8013BDB0; // title gobj
extern s32 gMnBattleTokenShinePulseColor; // 0x8013BDB4;
extern sb32 gMnBattleIsTokenShineIncreasing; // 0x8013BDB8;
extern u16 gMnBattleCharacterUnlockedMask; // 0x8013BDBC; // flag indicating which bonus chars are available

extern s32 gMnBattlePressStartFlashTimer; // 0x8013BDC4; looping timer that helps determine blink rate of Press Start (and Ready to Fight?)
extern s32 D_ovl26_8013BDC8;
extern s32 gMnBattleFramesElapsed; // 0x8013BDCC; // frames elapsed on CSS
extern s32 gMnBattleMaxFramesElapsed; // 0x8013BDD0; // frames to wait until exiting the CSS

extern RldmFileNode D_ovl26_8013C0A8;
extern u32 D_ovl26_8013C0E0[240];
extern uintptr_t D_NF_001AC870;
extern uintptr_t D_NF_00000854;

extern s32 gMnBattleFilesArray[7]; // 0x8013C4A0[7]
extern s32 gFile011; // 0x8013C4A0; // file 0x011 pointer
extern s32 gFile000; // 0x8013C4A4; // file 0x000 pointer
extern s32 gFile014; // 0x8013C4A8; // file 0x014 pointer
extern s32 gFile015; // 0x8013C4AC; // file 0x015 pointer
extern s32 gFile012; // 0x8013C4B0; // file 0x012 pointer
extern s32 gFile013; // 0x8013C4B4; // file 0x013 pointer
extern s32 gFile016; // 0x8013C4B8; // file 0x016 pointer

// Offsets
extern intptr_t FILE_000_COLON_IMAGE_OFFSET = 0xDCF0; // file 0x000 image offset for colon

extern intptr_t FILE_011_TYPE_CP_IMAGE_OFFSET = 0xFF8; // file 0x011 image offset for CP type image
extern intptr_t FILE_011_HANDICAP_IMAGE_OFFSET = 0x1108; // file 0x011 image offset for Handicap image
extern intptr_t FILE_011_CPU_LEVEL_IMAGE_OFFSET = 0x1218; // file 0x011 image offset for CPU Level image
extern intptr_t FILE_011_START_IMAGE_OFFSET = 0x1378; // Press Start's "Start" texture
extern intptr_t FILE_011_PRESS_IMAGE_OFFSET = 0x14D8; // Press Start's "Press" texture
extern intptr_t FILE_011_INFINITY_IMAGE_OFFSET = 0x3EF0; // file 0x011 image offset for infinity symbol
extern intptr_t FILE_011_PICKER_TIME_IMAGE_OFFSET = 0x48B0; // file 0x011 image offset for Time picker texture
extern intptr_t FILE_011_PICKER_STOCK_IMAGE_OFFSET = 0x5270; // file 0x011 image offset for Stock picker texture
extern intptr_t FILE_011_CURSOR_POINTER_IMAGE_OFFSET = 0x76E8; // file 0x011 image offset for pointer cursor
extern intptr_t FILE_011_PANEL_DOOR_L_IMAGE_OFFSET = 0xCDB0;
extern intptr_t FILE_011_PANEL_DOOR_R_IMAGE_OFFSET = 0xDFA0;
extern intptr_t FILE_011_ARROW_L_IMAGE_OFFSET = 0xECE8; // file 0x011 image offset for left arrow
extern intptr_t FILE_011_ARROW_R_IMAGE_OFFSET = 0xEDC8; // file 0x011 image offset for right arrow
extern intptr_t FILE_011_READY_TO_FIGHT_IMAGE_OFFSET = 0xF448; // Ready to Fight banner text
extern intptr_t FILE_011_READY_TO_FIGHT_BG_IMAGE_OFFSET = 0xF530; // Ready to Fight banner bg
extern intptr_t FILE_011_PANEL_IMAGE_OFFSET = 0x104B0;
extern intptr_t FILE_011_BACK_IMAGE_OFFSET = 0x115C8; // file 0x011 image offset for

extern s32 FILE_013_XBOX_IMAGE_OFFSET = 0x2B8; // file 0x013 image offset
extern intptr_t FILE_013_WHITE_SQUARE = 0x6F0; // white square
extern s32 FILE_013_PORTRAIT_QUESTION_MARK_IMAGE_OFFSET = 0xF68; // file 0x013 image offset for portrait question mark image
extern s32 FILE_013_PORTRAIT_FIRE_BG_IMAGE_OFFSET = 0x24D0; // file 0x013 image offset for portrait bg (fire) image

extern intptr_t FILE_015_BACKGROUND_IMAGE_OFFSET = 0x440; // file 0x015 image offset for background tile

extern intptr_t FILE_016_WHITE_CIRCLE_OFFSET_1 = 0x408; // AObj? for white circle
extern intptr_t FILE_016_WHITE_CIRCLE_OFFSET_2 = 0x568; // DObjDesc for white circle

void ftRender_Lights_DisplayLightReflect(Gfx**, f32, f32); /* extern */
f32 func_ovl1_8039051C();                           /* extern */
f32 func_ovl1_80390528();                           /* extern */
void func_ovl0_800CCF00(GObj*);                     /* extern */
extern void func_ovl0_800CD2CC();
GObj* func_8000B93C(u32, void*, s32, u32, void*, s32, s64, s32, s32, s32, s32, s32, s32); /* extern */
void func_80007080(void*, f32, f32, f32, f32);         /* extern */
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
s32 mnBattleReorderCursorsOnPlacement(s32 port_id, s32 held_token_id); // doesn't actually return anything but required to match
void mnRedrawToken(GObj* token_gobj, s32 token_index);
s32 mnSelectRandomFighter(GObj* token_gobj);

#endif