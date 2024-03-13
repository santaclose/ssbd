#ifndef _OVL7_H_
#define _OVL7_H_

#define scGetTrainingModeItemKind(kind) \
((kind) - (It_Kind_UtilityStart - 1))

void func_80020B38(s32, s32);
void func_ovl2_8010CF44(void*, f32, f32, f32, f32, f32);   /* extern */
void scTrainingMode_InitViewOptionSprite();                             /* extern */
void func_ovl0_800CCF00(GObj*, s32);                     /* extern */
void func_ovl0_800CCF00_overload(GObj*);                     /* extern */
void func_ovl7_801906D0();
void ftRender_Lights_DisplayLightReflect(Gfx**, f32, f32);    /* extern */
void scTrainingMode_InitCPDisplaySprite();
void scTrainingMode_InitCPOptionSprite();
void scTrainingMode_UpdateOptionArrows();
void scTrainingMode_UpdateCursorUnderline();
void scTrainingMode_UpdateOpponentBehavior();
void scTrainingMode_InitItemOptionSprite();

typedef struct scTrainingMenu
{
	s32 main_menu_option;                       // Option selected in the main training mode menu (vertically)
	s32 damage;                                 // Total combo damage accumulated
	s32 combo;                                  // Combo count
	s32 item_hold;                              // Training Mode Item ID of item currently held by player
	s32 item_menu_option;                       // Option selected in "Item" settings
	s32 cp_menu_option;                         // Option selected in "CP" settings
	s32 speed_menu_option;                      // Option selected in "Speed" settings
	s32 view_menu_option;                       // Option selected in "View" settings
	s32 opponent;                               // Dummy fighter's port ID
	scTrainingSprites *display_label_sprites;   // "DAMAGE", "COMBO", "ENEMY", "SPEED" text
	Sprite **display_option_sprites;
	scTrainingSprites *menu_label_sprites;      // Orange text describing what each option is?
	Sprite **menu_option_sprites;
	scTrainingSprites *unk_trainmenu_0x34;
	scTrainingSprites *unk_trainmenu_0x38;
	GObj *damage_display_gobj;                  // Interface GObj of damage stat display
	GObj *combo_display_gobj;                   // Interface GObj of combo stat display
	GObj *cp_display_gobj;                      // Interface GObj of CP behavior display
	GObj *speed_display_gobj;                   // Interface GObj of speed display
	GObj *item_display_gobj;                    // Interface GObj of item display
	GObj *menu_label_gobj;                      // Interface GObj of main menu options descriptions (orange text)
	GObj *cursor_gobj;
	GObj *cp_option_gobj;                       // Interface GObj of main menu CP options
	GObj *item_option_gobj;                     // Interface GObj of main menu Item options
	GObj *speed_option_gobj;
	GObj *view_option_gobj;
	GObj *arrow_option_gobj;
	SObj *hscroll_option_sobj[4];
	GObj *unk_trainmenu_0x7C;
	GObj *combo0;
	SObj *vscroll_option_sobj[6][2];
	u32 cursor_ulx, cursor_uly;
	u32 cursor_lrx, cursor_lry;
	u16 button_hold;
	u16 button_tap;
	u16 button_queue;
	s32 rapid_scroll_wait;
	u8 damage_reset_wait;                       // Wait this many frames before resetting combo damage
	u8 combo_reset_wait;                        // Wait this many frames before resetting combo count
	ub8 exit_or_reset;                          // 0 = exit, 1 = reset
	u8 lagframe_wait;                           // Wait this many frames before duplicate/lag frame is applied? Used for 2/3 speed with a setting of 1
	u8 frameadvance_wait;                       // Wait this many frames before advancing to the next frame
	u8 item_spawn_wait;                         // Cooldown before new item can be summoned
	u16 magnify_wait;                           // Cooldown before magnifying glass is shown again after switching back from Close-Up view
	ub8 is_read_menu_inputs;                    // Menu navigation inputs are ignored if FALSE
} scTrainingMenu;
scTrainingMenu gTrainingModeStruct;

// 80190808
s32 scTrainingMode_CPOpponent_BehaviorKind[/* */] = { 0x0F, 0x10, 0x11, 0x12, 0x00 };

// 8018DDB0
intptr_t D_ovl7_801907B8[] =
{
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88,
	0x26C88
};

// 80190824
scTrainingFiles scTrainingMode_Files_BackgroundImageInfo[/* */] =
{
	{ 0x1A, 0x20718, { 0x00, 0x00, 0x00 } },
	{ 0x1B, 0x20718, { 0xEE, 0x9E, 0x06 } },
	{ 0x1C, 0x20718, { 0xAF, 0xF5, 0xFF } }
};

// 0x80190848
s32 scTrainingMode_Files_BackgroundImageIDs[/* */] =
{
	2, // Peach's Castle
	0, // Sector Z
	0, // Kongo Jungle
	0, // Planet Zebes
	2, // Hyrule Castle
	1, // Yoshi's Story
	2, // Dream Land
	2, // Saffron City
	2  // Mushroom Kingdom
};

extern intptr_t D_NF_00000000;
extern intptr_t D_NF_00000020;
extern intptr_t D_NF_000000BC;
extern intptr_t D_NF_000000FE;
extern intptr_t D_NF_0000010C;
extern intptr_t D_NF_0000013C;
extern intptr_t D_NF_000001B8;
extern uintptr_t D_NF_800A5240;
scUnkDataBounds D_ovl7_80190870;
scRuntimeInfo D_ovl7_8019088C;
gmMatchInfo D_ovl7_80190968;
scTrainingMenu D_ovl7_80190B58;
extern uintptr_t lOverlay7ArenaHi;  // 80392A00
extern uintptr_t lOverlay7ArenaLo;  // 80190FA0
extern intptr_t D_NF_00000854;
extern intptr_t D_NF_001AC870;

extern u16 D_ovl7_801907DC[3];
extern u8 D_ovl7_801907E4[3];
extern u16 D_ovl7_801907E8[2];
extern u8 D_ovl7_801907EC[2];
extern sb32 (*jtbl_ovl7_801907F0[/* */])();
extern u8 D_ovl7_8019081C[/* */][2];
Unk800D4060 D_ovl7_8019086C = { 0 };
extern void *gCommonSpriteFiles[/* */];
extern u32 D_ovl2_80116BD0[8];
// 80190C40
RldmFileNode gOverlay7StatusBuf[100];
// 80190F60
RldmFileNode gOverlay7ForceBuf[7];

#endif 