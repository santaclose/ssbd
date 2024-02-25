#include <ft/fighter.h>
#include <it/item.h>
#include <gr/ground.h>
// #include <if/interface.h>
#include <gm/battle.h>
#include <sc/scene.h>
#include <buttons.h>
#include <sys/om.h>

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


// 8018D0C0
void scTrainingMode_SetPauseGObjRenderFlags(u32 flags)
{
	GObj *pause_gobj = gOMObjCommonLinks[omGObj_LinkIndex_PauseMenu];

	while (pause_gobj != NULL)
	{
		pause_gobj->obj_renderflags = flags;

		pause_gobj = pause_gobj->group_gobj_next;
	}
}

scTrainingMenu D_ovl7_80190B58;
void scTrainingMode_CheckEnterTrainingMenu()
{
	s32 player = gSceneData.player_port;

	if (gPlayerControllers[player].button_new & HAL_BUTTON_START)
	{
		GObj *fighter_gobj = gBattleState->player_block[player].fighter_gobj;
		ftStruct *fp = ftGetStruct(fighter_gobj);
		
		if (!(fp->is_ignore_startbutton))
		{
			ifCommon_SetRenderFlagsAll(1);
			scTrainingMode_SetPauseGObjRenderFlags(0);
			func_ovl2_801157EC();
			ftCommon_ResetControllerInputs(gBattleState->player_block[player].fighter_gobj);
			ftCommon_ResetControllerInputs(gBattleState->player_block[D_ovl7_80190B58.opponent].fighter_gobj);
			
			gBattleState->game_status = 2;
			
			func_800269C0(0x116U);
			func_80020B38(0, 0x3C00);
			
			D_ovl7_80190B58.is_read_menu_inputs = 0;
		}
	}
}

// 8018D1F0
void scTrainingMode_CheckLeaveTrainingMenu()
{
	s32 player = gSceneData.player_port;
	GObj* fighter_gobj;
	
	if (gPlayerControllers[player].button_new & (HAL_BUTTON_B | HAL_BUTTON_START))
	{
		ifCommon_SetRenderFlagsAll(0);
		scTrainingMode_SetPauseGObjRenderFlags(1);
		
		gBattleState->game_status = 1;
		
		func_ovl2_800E7F68(gBattleState->player_block[D_ovl7_80190B58.opponent].fighter_gobj);
		
		fighter_gobj = gBattleState->player_block[player].fighter_gobj;
		
		func_ovl2_800E7F68(fighter_gobj);
		
		if (gPlayerControllers[player].button_new & HAL_BUTTON_B)
		{
			ftStruct *fp = ftGetStruct(fighter_gobj);
			
			fp->input.pl.button_hold |= HAL_BUTTON_B;
		}
		func_80020B38(0, 0x7800);
	}
}


// 8018D2F0
void scTrainingMode_UpdateMenuInputs()
{
	u16 inputs = 0;
	s32 player = gSceneData.player_port;
	
	if (gPlayerControllers[player].stick_range.x > 40)
		inputs |= 0x100;
	if (gPlayerControllers[player].stick_range.x < -40)
		inputs |= 0x200;
	if (gPlayerControllers[player].stick_range.y > 40)
		inputs |= 0x800;
	if (gPlayerControllers[player].stick_range.y < -40)
		inputs |= 0x400;
	if (D_ovl7_80190B58.is_read_menu_inputs == FALSE)
	{
		if (!(inputs))
		{
			D_ovl7_80190B58.is_read_menu_inputs = TRUE;
		}
	} 
	else 
	{
		D_ovl7_80190B58.button_tap = (inputs ^ D_ovl7_80190B58.button_hold) & inputs;
		
		if (inputs ^ D_ovl7_80190B58.button_hold)
		{
			D_ovl7_80190B58.button_queue = D_ovl7_80190B58.button_tap;
			D_ovl7_80190B58.rapid_scroll_wait = 30;
		}
		else 
		{
			D_ovl7_80190B58.rapid_scroll_wait--;
			
			if (D_ovl7_80190B58.rapid_scroll_wait > 0)
				D_ovl7_80190B58.button_queue = 0;
			else
			{
				D_ovl7_80190B58.button_queue = inputs;
				D_ovl7_80190B58.rapid_scroll_wait = 5;
			}
		}
		D_ovl7_80190B58.button_hold = inputs;
	}
}

// 8018D3DC
void func_ovl7_8018D3DC()
{
	func_ovl7_8018F630();
	func_ovl7_8018FE40();
	func_800269C0(0xA4U);
}

// 8018D40C
sb32 scTrainingMode_CheckUpdateOptionID(s32 *arg0, s32 arg1, s32 arg2)
{
	if (gTrainingModeStruct.button_queue & 0x300)
	{
		if (gTrainingModeStruct.button_queue & 0x200)
		{     
			if (--(*arg0) < arg1)
			{
				*arg0 = arg2 - 1;
				return TRUE;
			}
		}
		else if (++(*arg0) >= arg2)
			*arg0 = arg1;
		return TRUE;
	}
	else return FALSE;
}

// 8018D478
sb32 scTrainingMode_UpdateCPOption()
{
	if (func_ovl7_8018D40C(&gTrainingModeStruct.cp_menu_option, 0, 5) != FALSE)
	{
		func_ovl7_801901F4();
		func_ovl7_8018E810();
		func_ovl7_8018EEE8();
		func_ovl7_8018D3DC();
	}
	return FALSE;
}

// 8018D4D0
s32 scTrainingMode_GetSpawnableItemCount()
{
	GObj *item_gobj = gOMObjCommonLinks[omGObj_LinkIndex_Item];
	s32 item_count;

	for (item_count = 0; item_gobj != NULL; item_gobj = item_gobj->group_gobj_next)
	{
		if ((itGetStruct(item_gobj)->it_kind <= It_Kind_CommonEnd) || (itGetStruct(item_gobj)->it_kind >= It_Kind_MbMonsterStart))
			item_count++;
	}
	return item_count;
}

// 8018D518
sb32 scTrainingMode_UpdateItemOption()
{
	Vec3f pos;
	Vec3f vel;

	if (func_ovl7_8018D40C(&gTrainingModeStruct.item_menu_option, 0, 0x11) != FALSE)
	{
		func_ovl7_8018F040();
		func_ovl7_8018D3DC();
	}
	if (gTrainingModeStruct.item_spawn_wait == 0)
	{
		if ((gPlayerControllers[gSceneData.player_port].button_new & HAL_BUTTON_A) && (gTrainingModeStruct.item_menu_option != 0))
		{
			if (scTrainingMode_GetSpawnableItemCount() <= 3)
			{
				vel.x = vel.z = 0.0F;
				vel.y = 30.0F;

				pos = DObjGetStruct(gBattleState->player_block[gSceneData.player_port].fighter_gobj)->translate.vec.f;
				
				pos.y += 200.0F;
				pos.z = 0.0F;
				
				itManager_MakeItemSetupCommon(NULL, gTrainingModeStruct.item_menu_option + 3, &pos, &vel, 4);
				func_800269C0(0x9EU);
				gTrainingModeStruct.item_spawn_wait = 8;
			} 
			else
				func_800269C0(0xA5U);
		}
	}
	else
		gTrainingModeStruct.item_spawn_wait--;
	
	return FALSE;
}

// 8018D684
sb32 scTrainingMode_UpdateSpeedOption()
{
	if (func_ovl7_8018D40C(&gTrainingModeStruct.speed_menu_option, 0, 4) != FALSE)
	{
		gTrainingModeStruct.lagframe_wait = gTrainingModeStruct.frameadvance_wait = 0;
		
		func_ovl7_8018E714();
		func_ovl7_8018F2C4();
		func_ovl7_8018D3DC();
	}
	return FALSE;
}

// 8018D6DC
void func_ovl2_8010CF44(void*, f32, f32, f32, f32, f32);   /* extern */
void func_ovl7_8018F424();                             /* extern */
sb32 scTrainingMode_UpdateViewOption()
{
	GObj *fighter_gobj;

	if (func_ovl7_8018D40C(&gTrainingModeStruct.view_menu_option, 0, 2) != FALSE)
	{
		if (gTrainingModeStruct.view_menu_option == 1)
		{
			func_ovl2_8010CF20();
			gTrainingModeStruct.magnify_wait = 180;
		} 
		else 
		{
			fighter_gobj = gBattleState->player_block[gSceneData.player_port].fighter_gobj;
			func_ovl2_8010CF44(fighter_gobj, 0.0F, 0.0F, ftGetStruct(fighter_gobj)->attributes->closeup_cam_zoom, 0.1F, 28.0F);
			gPlayerCommonInterface.is_ifmagnify_display = FALSE;
			gTrainingModeStruct.magnify_wait = 0;
		}
		func_ovl7_8018F424();
		func_ovl7_8018D3DC();
	}
	return FALSE;
}

// 8018D7B8
sb32 scTrainingMode_UpdateResetOption()
{
	if (gPlayerControllers[gSceneData.player_port].button_new & A_BUTTON)
	{
		gTrainingModeStruct.exit_or_reset = 1;
		func_800266A0();
		func_800269C0(0xA2U);
		func_80020B38(0, 0x7800);
		func_80005C74();
		return TRUE;
	}
	else
		return FALSE;
}

// 8018D830
sb32 scTrainingMode_UpdateExitOption()
{
	if (gPlayerControllers[gSceneData.player_port].button_new & A_BUTTON)
	{
		func_800266A0();
		func_800269C0(0xA2U);
		func_80005C74();
		return TRUE;
	}
	else
		return FALSE;
}

// 8018D898
void scTrainingMode_UpdateMainOption()
{
	if (gTrainingModeStruct.button_queue & 0xC00) 
	{
		if (gTrainingModeStruct.button_queue & 0x800) 
		{
			if (--gTrainingModeStruct.main_menu_option < 0)
			{
				gTrainingModeStruct.main_menu_option = 5;
			}
		}
		else if (++gTrainingModeStruct.main_menu_option >= 6)
		{
			gTrainingModeStruct.main_menu_option = 0;
		}
		func_ovl7_8018FBB0();
		func_ovl7_8018D3DC();
		func_800269C0(0xA4U);
	}
}

// 8018D91C
extern sb32 (*jtbl_ovl7_801907F0[/* */])(void);
void scTrainingMode_UpdateTrainingMenu()
{
	scTrainingMode_UpdateMenuInputs();
	
	if (jtbl_ovl7_801907F0[gTrainingModeStruct.main_menu_option]() == FALSE) 
	{
		scTrainingMode_UpdateMainOption();
		scTrainingMode_CheckLeaveTrainingMenu();
	}
}

// 8018D974
extern u8 D_ovl7_8019081C[/* */][2];
sb32 scTrainingMode_CheckSpeedFrameFreeze()
{
	if (gTrainingModeStruct.lagframe_wait == 0)
	{
		if (gTrainingModeStruct.frameadvance_wait == 0) 
		{
			gTrainingModeStruct.lagframe_wait = D_ovl7_8019081C[gTrainingModeStruct.speed_menu_option][0];
		}
		else
		{
			gTrainingModeStruct.frameadvance_wait--;
			
			return TRUE;
		}
	}
	else gTrainingModeStruct.lagframe_wait--;

	if (gTrainingModeStruct.lagframe_wait == 0) 
	{
		gTrainingModeStruct.frameadvance_wait = D_ovl7_8019081C[gTrainingModeStruct.speed_menu_option][1];
	}
	return FALSE;
}


// 8018D9F0
void scTrainingMode_ProcUpdate(void) 
{
	switch (gBattleState->game_status) 
	{
	case 1:
		scTrainingMode_CheckEnterTrainingMenu();
		break;
		
	case 2:
		scTrainingMode_ProcUpdate();
		break;
	}
	if (scTrainingMode_CheckSpeedFrameFreeze() == FALSE) 
		func_8000A5E4();
	else
		cmManager_RunProcCamera(gCameraGObj);
	
	func_ovl2_80114800();
}

// 8018DA78
void scTrainingMode_RunProcUpdate(void) 
{
	scTrainingMode_ProcUpdate();
}

// 8018DA98
gmMatchInfo D_ovl7_80190968;
void func_ovl7_8018DA98(void)
{
	s32 opponent;
	s32 player;
	D_ovl7_80190968 = gDefaultBattleState;
	gBattleState = &D_ovl7_80190968;

	gBattleState->game_type = 7;
	gBattleState->gr_kind = gSceneData.gr_kind;
	gBattleState->time_limit = 100;
	gBattleState->is_display_score = FALSE;
	gBattleState->item_toggles = 0;

	for (player = 0; player < ARRAY_COUNT(gBattleState->player_block); player++)
	{
		if (player == gSceneData.player_port) 
		{
			gBattleState->player_block[player].player_kind = Pl_Kind_Man;
			gBattleState->player_block[player].character_kind = gSceneData.unk3B;
			gBattleState->player_block[player].costume_index = gSceneData.unk3C;
			gBattleState->player_block[player].team_index = 0;
			gBattleState->player_block[player].player_color_index = player;
		} 
		else
			gBattleState->player_block[player].player_kind = Pl_Kind_Not;
	}
	
	opponent = (gSceneData.player_port == 0) ? 1 : 0;

	gBattleState->player_block[opponent].player_kind = 1;
	gBattleState->player_block[opponent].tag_index = 4;
	gBattleState->player_block[opponent].character_kind = gSceneData.unk3D;
	gBattleState->player_block[opponent].costume_index = gSceneData.unk3E;
	gBattleState->player_block[opponent].level = 3;
	gBattleState->player_block[opponent].team_index = 1;
	gBattleState->player_block[opponent].player_color_index = 4;
	gBattleState->pl_count = 1;
	gBattleState->cp_count = 1;
	
	gTrainingModeStruct.main_menu_option = 0;
	gTrainingModeStruct.damage = 0;
	gTrainingModeStruct.combo = 0;
	gTrainingModeStruct.item_hold = -1;
	gTrainingModeStruct.cp_menu_option = 0;
	gTrainingModeStruct.speed_menu_option = 0;
	gTrainingModeStruct.view_menu_option = 1;
	gTrainingModeStruct.lagframe_wait = 0;
	gTrainingModeStruct.frameadvance_wait = 0;
	gTrainingModeStruct.item_spawn_wait = 0;
	gTrainingModeStruct.item_menu_option = 0;
	gTrainingModeStruct.opponent = opponent;
	gTrainingModeStruct.button_hold = gTrainingModeStruct.button_tap = gTrainingModeStruct.button_queue = 0;
	gTrainingModeStruct.rapid_scroll_wait = 30;
	gTrainingModeStruct.damage_reset_wait = 0;
	gTrainingModeStruct.combo_reset_wait = 0;
	gTrainingModeStruct.exit_or_reset = 0;
	gTrainingModeStruct.magnify_wait = 0;
	gTrainingModeStruct.is_read_menu_inputs = 0;
}

// 8018DD0C
extern intptr_t D_NF_00000000;
extern intptr_t D_NF_00000020;
extern intptr_t D_NF_000000BC;
extern intptr_t D_NF_000000FE;
extern intptr_t D_NF_0000010C;
extern intptr_t D_NF_0000013C;
extern intptr_t D_NF_000001B8;
void scTrainingMode_LoadFiles(void) 
{
	void *addr = rldm_get_file_with_external_heap((u32)&D_NF_000000FE, hal_alloc(rldm_bytes_needed_to_load((u32)&D_NF_000000FE), 0x10));
	gTrainingModeStruct.display_label_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_00000000);
	gTrainingModeStruct.display_option_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_00000020);
	gTrainingModeStruct.menu_label_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_000000BC);
	gTrainingModeStruct.menu_option_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_0000013C);
	gTrainingModeStruct.unk_trainmenu_0x34 = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_0000010C);
	gTrainingModeStruct.unk_trainmenu_0x38 = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_000001B8);
}

// 8018DE60
#pragma GLOBAL_ASM("src/func_ovl7_8018DE60.s")
// scTrainingFiles scTrainingMode_Files_BackgroundImageInfo[/* */] =
// {
// 	{ 0x1A, 0x20718, { 0x00, 0x00, 0x00 } },
// 	{ 0x1B, 0x20718, { 0xEE, 0x9E, 0x06 } },
// 	{ 0x1C, 0x20718, { 0xAF, 0xF5, 0xFF } }
// };
// extern intptr_t scTrainingMode_Files_BackgroundImageIDs[/* */];
// void scTrainingMode_InitMiscVars(void)
// {
// 	gGroundInfo->fog_color = scTrainingMode_Files_BackgroundImageInfo[scTrainingMode_Files_BackgroundImageIDs[gBattleState->gr_kind]].fog_color;
// 	ifPlayer_MagnifyGlass_SetInterface();
// 	gPlayerCommonInterface.is_ifmagnify_display = TRUE;
// }

// 8018DEDC
// scTrainingMode_MakeStatDisplaySObj

// 8018DF30
// scTrainingMode_InitStatDisplayTextInterface

// 8018E014
// scTrainingMode_UpdateDamageDisplay

// 8018E138
// scTrainingMode_UpdateDamageInfo

// 8018E1F8
// scTrainingMode_UpdateDamageResetWait

// 8018E21C
// scTrainingMode_InitStatDisplayCharacterVars

// 8018E300
// scTrainingMode_InitSObjColors

// 8018E310
// scTrainingMode_MakeDamageDisplayInterface

// 8018E424
// scTrainingMode_UpdateComboDisplay

// 8018E548
// scTrainingMode_UpdateComboResetWait

// 8018E56C
// scTrainingMode_UpdateComboInfo

// 8018E62C
// scTrainingMode_MakeComboDisplayInterface

// 8018E714
// scTrainingMode_InitSpeedDisplaySprite

// 8018E774
// scTrainingMode_MakeSpeedDisplayInterface

// 8018E810
// scTrainingMode_InitCPDisplaySprite

// 8018E870
// scTrainingMode_MakeCPDisplayInterface

// 8018E90C
// scTrainingMode_InitItemDisplaySprite

// 8018E9AC
// scTrainingMode_UpdateItemDisplay

// 8018EA88
// scTrainingMode_MakeItemDisplayInterface

// 8018EB64
// scTrainingMode_InitStatDisplayAll

// 8018EBB4
// scTrainingMode_MakeMenuLabelsInterface

// 8018ECA4
// scTrainingMode_InitMenuOptionSpriteAttrs

// 8018ED2C
// scTrainingMode_RenderMainMenu

// 8018EE10
// scTrainingMode_MakeMainMenuInterface

// 8018EE5C
// scTrainingMode_InitCPOptionTextColors

// 8018EEE8
// scTrainingMode_InitCPOptionSprite

// 8018EF78
// scTrainingMode_MakeCPOptionInterface

// 8018F040
// scTrainingMode_InitItemOptionSprite

// 8018F0FC
// scTrainingMode_InitItemOptionTextColors

// 8018F194
// scTrainingMode_MakeItemOptionInterface

// 8018F264
// scTrainingMode_InitSpeedOptionTextColors

// 8018F2C4
// scTrainingMode_InitSpeedOptionSprite

// 8018F354
// scTrainingMode_MakeSpeedOptionInterface

// 8018F41C
// func_ovl7_8018F41C

// 8018F424
// scTrainingMode_InitSpeedOptionSprite

// 8018F4B4
// scTrainingMode_UpdateMagnifyWait

// 8018F4EC
// scTrainingMode_MakeViewOptionInterface

// 8018F5CC
// scTrainingMode_CopyHScrollOptionSObjs

// 8018F608
// scTrainingMode_InitOptionArrowColors

// 8018F630
// scTrainingMode_UpdateOptionArrows

// 8018F730
// scTrainingMode_MakeOptionArrowInterface

// 8018F7C8
// func_ovl7_8018F7C8

// 8018F9E8
// scTrainingMode_GetMenuOptionSpriteID

// 8018FA14
// jtgt_ovl7_8018FA14

// 8018FA20
// jtgt_ovl7_8018FA20

// 8018FA28
// jtgt_ovl7_8018FA28

// 8018FA34
// jtgt_ovl7_8018FA34

// 8018FA40
// jtgt_ovl7_8018FA40

// 8018FA48
// jtgt_ovl7_8018FA48

// 8018FA54
// func_ovl7_8018FA54

// 8018FBB0
// scTrainingMode_UpdateCursorPosition

// 8018FC00
// scTrainingMode_MakeMenuCursorInterface

// 8018FC7C
// scTrainingMode_CopyVScrollOptionSObjs

// 8018FCE0
// scTrainingMode_RenderCursorUnderline

// 8018FE40
// scTrainingMode_UpdateCursorUnderline

// 80190070
// scTrainingMode_MakeCursorUnderlineInterface

// 801900C4
// scTrainingMode_InitTrainingMenuAll

// 80190164
// scTrainingMode_SetPlayDefaultMusicID

// 801901A0
// scTrainingMode_SetGameStatusGo

// 801901F4
// scTrainingMode_UpdateOpponentBehavior

// 80190260
// scTrainingMode_InitTrainingMode

// 801905A8
// scTrainingMode_SetGeometryRenderLights

// 801905F4
// scManager_TrainingMode_InitScene

// 801906D0
// func_ovl7_801906D0