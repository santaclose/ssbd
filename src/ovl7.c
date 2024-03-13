#include <ssb_types.h>
#include <ft/fighter.h>
#include <it/item.h>
#include <gr/ground.h>
#include <gm/battle.h>
#include <sc/scene.h>
#include <buttons.h>
#include <sys/om.h>
#include <sys/rldm.h>

#include "ovl7.h"


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

// 8018D0E8
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
			D_ovl7_80190B58.is_read_menu_inputs = TRUE;
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
	scTrainingMode_UpdateOptionArrows();
	scTrainingMode_UpdateCursorUnderline();
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
	else
		return FALSE;
}

// 8018D478
sb32 scTrainingMode_UpdateCPOption()
{
	if (scTrainingMode_CheckUpdateOptionID(&gTrainingModeStruct.cp_menu_option, 0, 5) != FALSE)
	{
		scTrainingMode_UpdateOpponentBehavior();
		scTrainingMode_InitCPDisplaySprite();
		scTrainingMode_InitCPOptionSprite();
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

	if (scTrainingMode_CheckUpdateOptionID(&gTrainingModeStruct.item_menu_option, 0, 0x11) != FALSE)
	{
		scTrainingMode_InitItemOptionSprite();
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
	if (scTrainingMode_CheckUpdateOptionID(&gTrainingModeStruct.speed_menu_option, 0, 4) != FALSE)
	{
		gTrainingModeStruct.lagframe_wait = gTrainingModeStruct.frameadvance_wait = 0;
		
		func_ovl7_8018E714();
		func_ovl7_8018F2C4();
		func_ovl7_8018D3DC();
	}
	return FALSE;
}

// 8018D6DC
sb32 scTrainingMode_UpdateViewOption()
{
	GObj *fighter_gobj;

	if (scTrainingMode_CheckUpdateOptionID(&gTrainingModeStruct.view_menu_option, 0, 2) != FALSE)
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
		scTrainingMode_InitViewOptionSprite();
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
				gTrainingModeStruct.main_menu_option = 5;
		}
		else if (++gTrainingModeStruct.main_menu_option >= 6)
			gTrainingModeStruct.main_menu_option = 0;

		func_ovl7_8018FBB0();
		func_ovl7_8018D3DC();
		func_800269C0(0xA4U);
	}
}

// 8018D91C
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
sb32 scTrainingMode_CheckSpeedFrameFreeze()
{
	if (gTrainingModeStruct.lagframe_wait == 0)
	{
		if (gTrainingModeStruct.frameadvance_wait == 0)
			gTrainingModeStruct.lagframe_wait = D_ovl7_8019081C[gTrainingModeStruct.speed_menu_option][0];
		else
		{
			gTrainingModeStruct.frameadvance_wait--;
			return TRUE;
		}
	}
	else
		gTrainingModeStruct.lagframe_wait--;

	if (gTrainingModeStruct.lagframe_wait == 0)
		gTrainingModeStruct.frameadvance_wait = D_ovl7_8019081C[gTrainingModeStruct.speed_menu_option][1];

	return FALSE;
}


// 8018D9F0
void scTrainingMode_ProcUpdate()
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
void scTrainingMode_RunProcUpdate()
{
	scTrainingMode_ProcUpdate();
}

// 8018DA98
void func_ovl7_8018DA98()
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
void scTrainingMode_LoadFiles()
{
	void *addr = rldm_get_file_with_external_heap((u32)&D_NF_000000FE, hal_alloc(rldm_bytes_needed_to_load((u32)&D_NF_000000FE), 0x10));
	gTrainingModeStruct.display_label_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_00000000);
	gTrainingModeStruct.display_option_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_00000020);
	gTrainingModeStruct.menu_label_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_000000BC);
	gTrainingModeStruct.menu_option_sprites = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_0000013C);
	gTrainingModeStruct.unk_trainmenu_0x34 = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_0000010C);
	gTrainingModeStruct.unk_trainmenu_0x38 = (void*) ((uintptr_t)addr + (intptr_t)&D_NF_000001B8);
}

void func_ovl7_8018DDB0()
{
	gGroundInfo->unk_0x48 = (void*) (rldm_get_file_external_force(
			scTrainingMode_Files_BackgroundImageInfo[scTrainingMode_Files_BackgroundImageIDs[gBattleState->gr_kind]].file_id,
			(void*) ((uintptr_t)gGroundInfo->unk_0x48 - (intptr_t)D_ovl7_801907B8[gBattleState->gr_kind])) +
			scTrainingMode_Files_BackgroundImageInfo[scTrainingMode_Files_BackgroundImageIDs[gBattleState->gr_kind]].addr
	);
}

// 8018DE60
void scTrainingMode_InitMiscVars()
{
	gGroundInfo->fog_color = scTrainingMode_Files_BackgroundImageInfo[scTrainingMode_Files_BackgroundImageIDs[gBattleState->gr_kind]].fog_color;
	ifPlayer_MagnifyGlass_SetInterface();
	gPlayerCommonInterface.is_ifmagnify_display = TRUE;
}

// 8018DEDC
SObj* scTrainingMode_MakeStatDisplaySObj(GObj *interface_gobj, scTrainingSprites *tms)
{
	SObj *sobj = func_ovl0_800CCFDC(interface_gobj, tms->sprite);
	sobj->pos.x = tms->pos.x;
	sobj->pos.y = tms->pos.y;
	return sobj;
}

// 8018DF30
void scTrainingMode_InitStatDisplayTextInterface()
{
	s32 i;
	GObj *interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xB, 0x80000000);
	
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	
	for(i = 0; i < 4; i++)
	{
		SObj *sobj = scTrainingMode_MakeStatDisplaySObj(interface_gobj, &gTrainingModeStruct.display_label_sprites[i]);
		
		sobj->sprite.red   = 0xAF;
		sobj->sprite.green = 0xAE;
		sobj->sprite.blue  = 0xDD;
		
		sobj->shadow_color.r = 0;
		sobj->shadow_color.g = 0;
		sobj->shadow_color.b = 0;
		
		sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
		
	}
}

// 8018E014
void scTrainingMode_UpdateDamageDisplay(GObj *interface_gobj, s32 index)
{
	SObj *sobj = SObjGetStruct(interface_gobj);
	s32 i;

	for (i = 0; i < (ARRAY_COUNT(D_ovl7_801907DC) + ARRAY_COUNT(D_ovl7_801907E4)) / 2; i++)
	{
		s32 modulo = index / D_ovl7_801907E4[i];
		index -= ((modulo) * D_ovl7_801907E4[i]);
		sobj->sprite = *gTrainingModeStruct.display_option_sprites[modulo];
		sobj->pos.x = (s32) (D_ovl7_801907DC[i] - (sobj->sprite.width * 0.5F));
		sobj = sobj->next;
	}
}

// 8018E138
void scTrainingMode_UpdateDamageInfo(GObj *interface_gobj)
{
	s32 damage = gBattleState->player_block[gTrainingModeStruct.opponent].combo_damage_foe;
	if (damage > 999)
		damage = 999;
	if (damage == 0)
	{
		if (gTrainingModeStruct.damage != 0)
		{
			gTrainingModeStruct.damage_reset_wait = 90;
			gTrainingModeStruct.damage = 0;
		}
		if (gTrainingModeStruct.damage_reset_wait == 0)
			gTrainingModeStruct.damage = 1;
	}
	if (damage != gTrainingModeStruct.damage)
	{
		scTrainingMode_UpdateDamageDisplay(interface_gobj, damage);
		gTrainingModeStruct.damage = damage;
	}
	func_ovl0_800CCF00(interface_gobj, damage);
}

// 8018E1F8
void scTrainingMode_UpdateDamageResetWait(GObj *interface_gobj)
{
	if (gTrainingModeStruct.damage_reset_wait != 0)
		gTrainingModeStruct.damage_reset_wait -= 1;
}

// 8018E21C
void scTrainingMode_InitStatDisplayCharacterVars()
{
	s32 i;
	for (i = 0; i < 39; i++)
	{
		Sprite *sprite = gTrainingModeStruct.display_option_sprites[i];
		sprite->red   = 0x6C;
		sprite->green = 0xFF;
		sprite->blue  = 0x6C;
		sprite->attr = SP_TEXSHUF | SP_TRANSPARENT;
	}
}

// 8018E300
void scTrainingMode_InitSObjColors(SObj *sobj)
{
	sobj->shadow_color.r = 0x00;
	sobj->shadow_color.g = 0x00;
	sobj->shadow_color.b = 0x00;
}

// 8018E310
void scTrainingMode_MakeDamageDisplayInterface()
{
	GObj* interface_gobj;
	SObj* sobj;
	s32 i;

	gTrainingModeStruct.damage_display_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xBU, 0x80000000);
	omAddGObjRenderProc(interface_gobj, scTrainingMode_UpdateDamageInfo, 0x17U, 0x80000000, -1);
	omAddGObjCommonProc(interface_gobj, scTrainingMode_UpdateDamageResetWait, 1, 4);

	for (i = 0; i < 3; i++)
	{
		sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[0]);
		scTrainingMode_InitSObjColors(sobj);
		sobj->pos.y = 20.0F;
	}
	scTrainingMode_UpdateDamageDisplay(interface_gobj, 0);
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[38]);
	scTrainingMode_InitSObjColors(sobj);
		
	sobj->pos.y = 20.0F;
	sobj->pos.x = 100.0F;
}

// 8018E424
void scTrainingMode_UpdateComboDisplay(GObj *interface_gobj, s32 index)
{
	SObj *sobj = SObjGetStruct(interface_gobj);
	s32 i;

	for (i = 0; i < (ARRAY_COUNT(D_ovl7_801907E8) + ARRAY_COUNT(D_ovl7_801907EC)) / 2; i++)
	{
		s32 modulo = index / D_ovl7_801907EC[i];
		index -= (modulo * D_ovl7_801907EC[i]);
		sobj->sprite = *gTrainingModeStruct.display_option_sprites[modulo];
		sobj->pos.x = (s32) (D_ovl7_801907E8[i] - (sobj->sprite.width * 0.5F));
		sobj = sobj->next;
	}
}

// 8018E548
void scTrainingMode_UpdateComboResetWait(GObj *interface_gobj)
{
	if (gTrainingModeStruct.combo_reset_wait != 0)
		gTrainingModeStruct.combo_reset_wait--;
}

// 8018E56C
void scTrainingMode_UpdateComboInfo(s32 interface_gobj)
{
	s32 combo = gBattleState->player_block[gTrainingModeStruct.opponent].combo_count_foe;
		
	if (combo > 99)
		combo = 99;
	if (combo == 0)
	{
		if (gTrainingModeStruct.combo != 0)
		{
			gTrainingModeStruct.combo_reset_wait = 90;
			gTrainingModeStruct.combo = 0;
		}
		if (gTrainingModeStruct.combo_reset_wait == 0)
			gTrainingModeStruct.combo = 1;
	}
	if (combo != gTrainingModeStruct.combo)
	{
		scTrainingMode_UpdateComboDisplay(interface_gobj, combo);
		gTrainingModeStruct.combo = combo;
	}
	func_ovl0_800CCF00(interface_gobj, combo);
}

// 8018E62C
void scTrainingMode_MakeComboDisplayInterface()
{
	GObj *interface_gobj;
	s32 i;

	gTrainingModeStruct.combo_display_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xBU, 0x80000000);
	
	omAddGObjRenderProc(interface_gobj, scTrainingMode_UpdateComboInfo, 0x17U, 0x80000000, -1);
	omAddGObjCommonProc(interface_gobj, scTrainingMode_UpdateComboResetWait, 1, 4);

	for(i = 0; i < 2; i++)
	{
		SObj *sobj = func_ovl0_800CCFDC(interface_gobj, *gTrainingModeStruct.display_option_sprites);
		scTrainingMode_InitSObjColors(sobj);
		sobj->pos.y = 36.0F;
	}
	scTrainingMode_UpdateComboDisplay(interface_gobj, 0);
}

// 8018E714
void scTrainingMode_InitSpeedDisplaySprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.speed_display_gobj);
	sobj->sprite = *gTrainingModeStruct.display_option_sprites[gTrainingModeStruct.speed_menu_option + 27];
}

// 8018E774
void scTrainingMode_MakeSpeedDisplayInterface()
{
	GObj* interface_gobj;
	SObj* sobj;

	gTrainingModeStruct.speed_display_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xB, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000U, -1);
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[gTrainingModeStruct.speed_menu_option + 27]);
	
	sobj->pos.x = 276.0F;
	sobj->pos.y = 20.0F;
	
	scTrainingMode_InitSObjColors(sobj);
}

// 8018E810
void scTrainingMode_InitCPDisplaySprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.cp_display_gobj);
	sobj->sprite = *gTrainingModeStruct.display_option_sprites[gTrainingModeStruct.cp_menu_option + 31];
}

// 8018E870
void scTrainingMode_MakeCPDisplayInterface()
{
	GObj *interface_gobj;
	SObj *sobj;

	gTrainingModeStruct.cp_display_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xB, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[gTrainingModeStruct.cp_menu_option + 31]);

	sobj->pos.x = 191.0F;
	sobj->pos.y = 20.0F;

	scTrainingMode_InitSObjColors(sobj);
}

// 8018E90C
void scTrainingMode_InitItemDisplaySprite()
{
	SObj *root_sobj, *next_sobj;
	root_sobj = SObjGetStruct(gTrainingModeStruct.item_display_gobj)->next;
	next_sobj = root_sobj->next;
	root_sobj->sprite = *gTrainingModeStruct.display_option_sprites[gTrainingModeStruct.item_hold + 10];
	root_sobj->pos.x = (f32)(292 - root_sobj->sprite.width);
	next_sobj->pos.x = (f32)(292 - root_sobj->sprite.width) - next_sobj->sprite.width;
}

// 8018E9AC
void scTrainingMode_UpdateItemDisplay(s32 interface_gobj)
{
	ftStruct *fp = ftGetStruct(gBattleState->player_block[gSceneData.player_port].fighter_gobj);
	GObj *item_gobj = fp->item_hold;
	s32 item_id;

	if (item_gobj != NULL)
	{
		itStruct *ip = itGetStruct(item_gobj);
		
		if (ip->it_kind <= It_Kind_ContainerEnd)
		{
			while(TRUE)
			{
				fatal_printf("Error : wrong item! %d\n", ip->it_kind);
				scnmgr_crash_print_gobj_state();
			}
		}
		item_id = (ip->it_kind <= It_Kind_CommonEnd) ? scGetTrainingModeItemKind(ip->it_kind) : 0;
	}
	else
		item_id = 0;
	
	if (gTrainingModeStruct.item_hold != item_id)
	{
		gTrainingModeStruct.item_hold = item_id;
		scTrainingMode_InitItemDisplaySprite();
	}
	func_ovl0_800CCF00_overload(interface_gobj);
}

// 8018EA88
void scTrainingMode_MakeItemDisplayInterface()
{
	GObj* interface_gobj;
	SObj* sobj;
	
	gTrainingModeStruct.item_display_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xB, 0x80000000);
	omAddGObjRenderProc(interface_gobj, scTrainingMode_UpdateItemDisplay, 0x17, 0x80000000, -1);
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[37]);
	
	sobj->pos.x = 292.0F;
	sobj->pos.y = 36.0F;
	scTrainingMode_InitSObjColors(sobj);
	
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[0]);
	sobj->pos.y = 36.0F;
	scTrainingMode_InitSObjColors(sobj);
	
	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.display_option_sprites[36]);
	sobj->pos.y = 36.0F;
	scTrainingMode_InitSObjColors(sobj);
}

// 8018EB64
void scTrainingMode_InitStatDisplayAll()
{
	scTrainingMode_InitStatDisplayTextInterface();
	scTrainingMode_InitStatDisplayCharacterVars();
	scTrainingMode_MakeDamageDisplayInterface();
	scTrainingMode_MakeComboDisplayInterface();
	scTrainingMode_MakeSpeedDisplayInterface();
	scTrainingMode_MakeCPDisplayInterface();
	scTrainingMode_MakeItemDisplayInterface();
}

// 8018EBB4
void scTrainingMode_MakeMenuLabelsInterface()
{
	GObj* interface_gobj;
	s32 i;
	
	gTrainingModeStruct.menu_label_gobj = interface_gobj = omMakeGObjCommon(0x3F8U, NULL, 0xE, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);

	for (i = 0; i < 10; i++)
	{
		SObj *sobj = scTrainingMode_MakeStatDisplaySObj(interface_gobj, &gTrainingModeStruct.menu_label_sprites[i]);
		
		if (i < 6)
		{
			sobj->sprite.red   = 0xF3;
			sobj->sprite.green = 0xA7;
			sobj->sprite.blue  = 0x6A;
			
			sobj->shadow_color.r = 0x00;
			sobj->shadow_color.g = 0x00;
			sobj->shadow_color.b = 0x00;
		}
		sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
	}
}

// 8018ECA4
void scTrainingMode_InitMenuOptionSpriteAttrs()
{
	s32 i;
	for (i = 0; i < 31; i++)
		gTrainingModeStruct.menu_option_sprites[i]->attr = SP_TEXSHUF | SP_TRANSPARENT;
}

// 8018ED2C
void scTrainingMode_RenderMainMenu(GObj *interface_gobj)
{
	gDPPipeSync(gDisplayListHead[0]++);
	gDPSetCycleType(gDisplayListHead[0]++, G_CYC_1CYCLE);
	gDPSetCombineMode(gDisplayListHead[0]++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetRenderMode(gDisplayListHead[0]++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
	gDPSetPrimColor(gDisplayListHead[0]++, 0, 0, 0x00, 0x64, 0xFF, 0x64);
	gDPFillRectangle(gDisplayListHead[0]++, 68, 47, 253, 198);
	gDPPipeSync(gDisplayListHead[0]++);
}


// 8018EE10
void scTrainingMode_MakeMainMenuInterface()
{
	omAddGObjRenderProc(omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000), scTrainingMode_RenderMainMenu, 0x16, 0x80000000, -1);
}

// 8018EE5C
void scTrainingMode_InitCPOptionTextColors()
{
	s32 i;
	for (i = scTrainingMenu_OptionSprite_CPStart; i <= scTrainingMenu_OptionSprite_CPEnd; i++)
	{
		Sprite *sprite = gTrainingModeStruct.menu_option_sprites[i];
		sprite->red   = 0xFF;
		sprite->green = 0xFF;
		sprite->blue  = 0xFF;
	}
}

// 8018EEE8
void scTrainingMode_InitCPOptionSprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.cp_option_gobj);
	sobj->sprite = *gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.cp_menu_option + scTrainingMenu_OptionSprite_CPStart];
	sobj->pos.x = 191 - (sobj->sprite.width / 2);
}

// 8018EF78
void scTrainingMode_MakeCPOptionInterface()
{
	GObj *interface_gobj;
	SObj *sobj;

	gTrainingModeStruct.cp_option_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);

	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);

	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.cp_menu_option + scTrainingMenu_OptionSprite_CPStart]);

	sobj->pos.x = 191 - (sobj->sprite.width / 2);
	sobj->pos.y = 65.0F;

	sobj->shadow_color.r = 0x4A;
	sobj->shadow_color.g = 0x2E;
	sobj->shadow_color.b = 0x60;
}

// 8018F040
void scTrainingMode_InitItemOptionSprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.item_option_gobj);

	sobj->sprite = *gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.item_menu_option + scTrainingMenu_OptionSprite_ItemStart];

	sobj->pos.x = 191 - (sobj->sprite.width / 2);
	sobj->pos.y = (gTrainingModeStruct.item_menu_option == scTrainingMenu_Item_MotionSensorBomb) ? 83.0F : 85.0F;
}

// 8018F0FC
void scTrainingMode_InitItemOptionTextColors()
{
	s32 i;
	for (i = scTrainingMenu_OptionSprite_ItemStart; i <= scTrainingMenu_OptionSprite_ItemEnd; i++)
	{
		Sprite *sprite = gTrainingModeStruct.menu_option_sprites[i];
		sprite->red   = 0xFF;
		sprite->green = 0xFF;
		sprite->blue  = 0xFF;
	}
}

// 8018F194
void scTrainingMode_MakeItemOptionInterface()
{
	GObj *interface_gobj;
	SObj *sobj;

	gTrainingModeStruct.item_option_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);

	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);

	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.item_menu_option + scTrainingMenu_OptionSprite_ItemStart]);
	sobj->pos.x = 191 - (sobj->sprite.width / 2);

	scTrainingMode_InitItemOptionSprite();

	sobj->shadow_color.r = 0x4A;
	sobj->shadow_color.g = 0x2E;
	sobj->shadow_color.b = 0x60;
}

// 8018F264
void scTrainingMode_InitSpeedOptionTextColors()
{
	s32 i;
	for (i = scTrainingMenu_OptionSprite_SpeedStart; i <= scTrainingMenu_OptionSprite_SpeedEnd; i++)
	{
		Sprite *sprite = gTrainingModeStruct.menu_option_sprites[i];
		sprite->red   = 0xFF;
		sprite->green = 0xFF;
		sprite->blue  = 0xFF;
	}
}

// 8018F2C4
void scTrainingMode_InitSpeedOptionSprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.speed_option_gobj);

	sobj->sprite = *gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.speed_menu_option + scTrainingMenu_OptionSprite_SpeedStart];

	sobj->pos.x = 191 - (sobj->sprite.width / 2);
}

// 8018F354
void scTrainingMode_MakeSpeedOptionInterface()
{
	GObj *interface_gobj;
	SObj *sobj;

	gTrainingModeStruct.speed_option_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);

	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);

	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.speed_menu_option + scTrainingMenu_OptionSprite_SpeedStart]);

	sobj->pos.x = 191 - (sobj->sprite.width / 2);
	sobj->pos.y = 105.0F;

	sobj->shadow_color.r = 0x4A;
	sobj->shadow_color.g = 0x2E;
	sobj->shadow_color.b = 0x60;
}

// 8018F41C
void func_ovl7_8018F41C() {}

// 8018F424
void scTrainingMode_InitViewOptionSprite()
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.view_option_gobj);
	sobj->sprite = *gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.view_menu_option + scTrainingMenu_OptionSprite_ViewStart];
	sobj->pos.x = 191 - (sobj->sprite.width / 2);
}

// 8018F4B4
void scTrainingMode_UpdateMagnifyWait(GObj *interface_gobj)
{
	if (gTrainingModeStruct.magnify_wait != 0)
	{
		gTrainingModeStruct.magnify_wait--;
		if (gTrainingModeStruct.magnify_wait == 0)
			gPlayerCommonInterface.is_ifmagnify_display = TRUE;
	}
}

// 8018F4EC
void scTrainingMode_MakeViewOptionInterface()
{
	GObj *interface_gobj;
	SObj *sobj;

	gTrainingModeStruct.view_option_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);

	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);

	sobj = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[gTrainingModeStruct.view_menu_option + scTrainingMenu_OptionSprite_ViewStart]);

	sobj->pos.x = 191 - (sobj->sprite.width / 2);
	sobj->pos.y = 125.0F;

	sobj->shadow_color.r = 0x4A;
	sobj->shadow_color.g = 0x2E;
	sobj->shadow_color.b = 0x60;

	omAddGObjCommonProc(interface_gobj, scTrainingMode_UpdateMagnifyWait, 1, 4);
}

// 8018F5CC
void scTrainingMode_CopyHScrollOptionSObjs()
{
	gTrainingModeStruct.hscroll_option_sobj[0] = SObjGetStruct(gTrainingModeStruct.cp_option_gobj);
	gTrainingModeStruct.hscroll_option_sobj[1] = SObjGetStruct(gTrainingModeStruct.item_option_gobj);
	gTrainingModeStruct.hscroll_option_sobj[2] = SObjGetStruct(gTrainingModeStruct.speed_option_gobj);
	gTrainingModeStruct.hscroll_option_sobj[3] = SObjGetStruct(gTrainingModeStruct.view_option_gobj);
}

// 8018F608
void scTrainingMode_InitOptionArrowColors(SObj *sobj)
{
	sobj->sprite.red   = 0xF3;
	sobj->sprite.green = 0x10;
	sobj->sprite.blue  = 0xE;

	sobj->shadow_color.r = 0x00;
	sobj->shadow_color.g = 0x00;
	sobj->shadow_color.b = 0x00;
}

// 8018F630
void scTrainingMode_UpdateOptionArrows()
{
	SObj *root_sobj = SObjGetStruct(gTrainingModeStruct.arrow_option_gobj); // Left arrow
	SObj *next_sobj = root_sobj->next; // Right arrow

	if (gTrainingModeStruct.main_menu_option <= scTrainingMenu_Main_ScrollEnd)
	{
		SObj *option_sobj = gTrainingModeStruct.hscroll_option_sobj[gTrainingModeStruct.main_menu_option];

		root_sobj->pos.x = 137.0F;
		next_sobj->pos.x = 237.0F;

		if ((gTrainingModeStruct.main_menu_option == scTrainingMenu_Main_Item) &&
			(gTrainingModeStruct.item_menu_option == scTrainingMenu_Item_MotionSensorBomb))
			root_sobj->pos.y = next_sobj->pos.y = (s32)(option_sobj->pos.y + 5.0F);
		else
			root_sobj->pos.y = next_sobj->pos.y = (s32)(option_sobj->pos.y + 3.0F);

		root_sobj->sprite.attr &= ~SP_HIDDEN;
		next_sobj->sprite.attr &= ~SP_HIDDEN;
	}
	else
	{
		root_sobj->sprite.attr |= SP_HIDDEN;
		next_sobj->sprite.attr |= SP_HIDDEN;
	}
}

// 8018F730
void scTrainingMode_MakeOptionArrowInterface()
{
	GObj *interface_gobj;

	gTrainingModeStruct.arrow_option_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	scTrainingMode_InitOptionArrowColors(func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[scTrainingMenu_OptionSprite_LeftArrow]));
	scTrainingMode_InitOptionArrowColors(func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[scTrainingMenu_OptionSprite_RightArrow]));

	scTrainingMode_UpdateOptionArrows();
}

// 8018F7C8
SObj* func_ovl7_8018F7C8(GObj *interface_gobj, scTrainingSprites *tms)
{
	SObj *sobj = func_ovl0_800CCFDC(interface_gobj, tms->sprite);
	sobj->pos.x = tms->pos.x;
	return sobj;
}

// 8018F804
void func_ovl7_8018F804() // Unused?
{
	s32 i;
	for (i = 0; i < 6; i++)
		gTrainingModeStruct.unk_trainmenu_0x34[i].sprite->attr = SP_TEXSHUF | SP_TRANSPARENT;
}

// 8018F874
void func_ovl7_8018F874() // Unused?
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.unk_trainmenu_0x7C);
	sobj->sprite = *gTrainingModeStruct.unk_trainmenu_0x34[gTrainingModeStruct.main_menu_option].sprite;
	sobj->pos.x = gTrainingModeStruct.unk_trainmenu_0x34[gTrainingModeStruct.main_menu_option].pos.x;
}

// 8018F8FC
void func_ovl7_8018F8FC() // Unused?
{
	GObj *interface_gobj;

	gTrainingModeStruct.unk_trainmenu_0x7C = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	func_ovl7_8018F7C8(interface_gobj, &gTrainingModeStruct.unk_trainmenu_0x34[gTrainingModeStruct.main_menu_option])->pos.y = 182.0F;
}

// 8018F984
void func_ovl7_8018F984() // Unused?
{
	s32 i;
	for (i = 0; i < 28; i++)
		gTrainingModeStruct.unk_trainmenu_0x38[i].sprite->attr = SP_TEXSHUF | SP_TRANSPARENT;
}

// 8018F9E8
s32 scTrainingMode_GetMenuOptionSpriteID()
{
	switch (gTrainingModeStruct.main_menu_option)
	{
	case scTrainingMenu_Main_CP:
		return gTrainingModeStruct.cp_menu_option + scTrainingMenu_OptionSprite_CPStart;

	case scTrainingMenu_Main_Item:
		return gTrainingModeStruct.item_menu_option + scTrainingMenu_OptionSprite_ItemStart;

	case scTrainingMenu_Main_Speed:
		return gTrainingModeStruct.speed_menu_option + scTrainingMenu_OptionSprite_SpeedStart;

	case scTrainingMenu_Main_View:
		return gTrainingModeStruct.view_menu_option + scTrainingMenu_OptionSprite_ViewStart;

	case scTrainingMenu_Main_Reset:
		return scTrainingMenu_OptionSprite_EnumMax;

	case scTrainingMenu_Main_Exit:
		return scTrainingMenu_OptionSprite_EnumMax;
	}
}


// 8018FA54
void func_ovl7_8018FA54() // Unused but referenced?
{
	SObj *sobj = SObjGetStruct(gTrainingModeStruct.combo0);
	s32 sprite_id = scTrainingMode_GetMenuOptionSpriteID();

	if (sprite_id == scTrainingMenu_OptionSprite_EnumMax)
		sobj->sprite.attr |= SP_HIDDEN;
	else
	{
		sobj->sprite = *gTrainingModeStruct.unk_trainmenu_0x38[sprite_id].sprite;
		sobj->pos.x = gTrainingModeStruct.unk_trainmenu_0x38[sprite_id].pos.x;
		sobj->pos.y = (sprite_id == scTrainingMenu_OptionSprite_ItemMotionSensorBomb) ? 178.0F : 182.0F;
		sobj->sprite.attr &= ~SP_HIDDEN;
	}
}

// 8018FB40
void func_ovl7_8018FB40() // Unused?
{
	GObj *interface_gobj;

	gTrainingModeStruct.combo0 = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	func_ovl7_8018F7C8(interface_gobj, gTrainingModeStruct.unk_trainmenu_0x38);
	func_ovl7_8018FA54();
}

// 8018FBB0
void scTrainingMode_UpdateCursorPosition()
{
	SObj *cursor_sobj = SObjGetStruct(gTrainingModeStruct.cursor_gobj);
	SObj *text_sobj = gTrainingModeStruct.vscroll_option_sobj[gTrainingModeStruct.main_menu_option][0];
	cursor_sobj->pos.y = (s32)(text_sobj->pos.y - 1.0F);
}

// 8018FC00
void scTrainingMode_MakeMenuCursorInterface()
{
	GObj *interface_gobj;
	SObj *target_sprite;

	gTrainingModeStruct.cursor_gobj = interface_gobj = omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000);
	omAddGObjRenderProc(interface_gobj, func_ovl0_800CCF00, 0x17, 0x80000000, -1);
	target_sprite = func_ovl0_800CCFDC(interface_gobj, gTrainingModeStruct.menu_option_sprites[scTrainingMenu_OptionSprite_Cursor]);
	target_sprite->pos.x = 71.0F;

	scTrainingMode_UpdateCursorPosition();
}

// 8018FC7C
void scTrainingMode_CopyVScrollOptionSObjs()
{
	SObj *arrow_sobj = SObjGetStruct(gTrainingModeStruct.arrow_option_gobj)->next;

	gTrainingModeStruct.vscroll_option_sobj[0][0] = SObjGetStruct(gTrainingModeStruct.menu_label_gobj);
	gTrainingModeStruct.vscroll_option_sobj[0][1] = arrow_sobj;

	gTrainingModeStruct.vscroll_option_sobj[1][0] = gTrainingModeStruct.vscroll_option_sobj[0][0]->next;
	gTrainingModeStruct.vscroll_option_sobj[1][1] = arrow_sobj;

	gTrainingModeStruct.vscroll_option_sobj[2][0] = gTrainingModeStruct.vscroll_option_sobj[1][0]->next;
	gTrainingModeStruct.vscroll_option_sobj[2][1] = arrow_sobj;

	gTrainingModeStruct.vscroll_option_sobj[3][0] = gTrainingModeStruct.vscroll_option_sobj[2][0]->next;
	gTrainingModeStruct.vscroll_option_sobj[3][1] = arrow_sobj;

	gTrainingModeStruct.vscroll_option_sobj[4][0] = gTrainingModeStruct.vscroll_option_sobj[4][1] = gTrainingModeStruct.vscroll_option_sobj[3][0]->next;
	gTrainingModeStruct.vscroll_option_sobj[5][0] = gTrainingModeStruct.vscroll_option_sobj[5][1] = gTrainingModeStruct.vscroll_option_sobj[4][0]->next;
}

// 8018FCE0
void scTrainingMode_RenderCursorUnderline(GObj *interface_gobj)
{
	gDPPipeSync(gDisplayListHead[0]++);
	gDPSetCycleType(gDisplayListHead[0]++, G_CYC_FILL);
	gDPSetRenderMode(gDisplayListHead[0]++, G_RM_NOOP, G_RM_NOOP2);
	gDPSetFillColor(gDisplayListHead[0]++, rgba32_to_fill_color(GPACK_RGBA8888(0xFF, 0x00, 0x00, 0xFF), gDisplayListHead));
	gDPFillRectangle(gDisplayListHead[0]++, gTrainingModeStruct.cursor_ulx, gTrainingModeStruct.cursor_uly, gTrainingModeStruct.cursor_lrx, gTrainingModeStruct.cursor_lry);
	gDPPipeSync(gDisplayListHead[0]++);
	gDPSetCycleType(gDisplayListHead[0]++, G_CYC_1CYCLE);
	gDPSetRenderMode(gDisplayListHead[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
}

// 8018FE40
void scTrainingMode_UpdateCursorUnderline()
{
	SObj *text_sobj = gTrainingModeStruct.vscroll_option_sobj[gTrainingModeStruct.main_menu_option][0];
	SObj *arrow_sobj = gTrainingModeStruct.vscroll_option_sobj[gTrainingModeStruct.main_menu_option][1];
	s32 offset;

	gTrainingModeStruct.cursor_ulx = text_sobj->pos.x - 13.0F;

	offset = ((gTrainingModeStruct.main_menu_option == scTrainingMenu_Main_Reset) || (gTrainingModeStruct.main_menu_option == scTrainingMenu_Main_Exit)) ? 2 : -2;

	gTrainingModeStruct.cursor_lrx = offset + (arrow_sobj->pos.x + arrow_sobj->sprite.width);
	gTrainingModeStruct.cursor_uly = text_sobj->pos.y + text_sobj->sprite.height + (-1.0F);
	gTrainingModeStruct.cursor_lry = gTrainingModeStruct.cursor_uly + 1;
}

// 80190070
void scTrainingMode_MakeCursorUnderlineInterface()
{
	omAddGObjRenderProc(omMakeGObjCommon(omGObj_Kind_Interface, NULL, 0xE, 0x80000000), scTrainingMode_RenderCursorUnderline, 0x16, 0x80000000, -1);
	scTrainingMode_UpdateCursorUnderline();
}

// 801900C4
void scTrainingMode_InitTrainingMenuAll()
{
	scTrainingMode_MakeMenuLabelsInterface();
	scTrainingMode_InitMenuOptionSpriteAttrs();
	scTrainingMode_MakeMainMenuInterface();
	scTrainingMode_InitCPOptionTextColors();
	scTrainingMode_MakeCPOptionInterface();
	scTrainingMode_InitItemOptionTextColors();
	scTrainingMode_MakeItemOptionInterface();
	scTrainingMode_InitSpeedOptionTextColors();
	scTrainingMode_MakeSpeedOptionInterface();
	func_ovl7_8018F41C();
	scTrainingMode_MakeViewOptionInterface();
	scTrainingMode_CopyHScrollOptionSObjs();
	scTrainingMode_MakeOptionArrowInterface();
	scTrainingMode_CopyVScrollOptionSObjs();
	scTrainingMode_MakeMenuCursorInterface();
	scTrainingMode_MakeCursorUnderlineInterface();
	scTrainingMode_SetPauseGObjRenderFlags(GOBJ_RENDERFLAG_HIDDEN);
}

// 80190164
void scTrainingMode_SetPlayDefaultMusicID()
{
	gMusicIndexDefault = 0x2A;
	func_80020AB4(0, gMusicIndexDefault);
	gMusicIndexCurrent = gMusicIndexDefault;
}

// 801901A0
void scTrainingMode_SetGameStatusGo()
{
	GObj *fighter_gobj = gOMObjCommonLinks[omGObj_LinkIndex_Fighter];

	while (fighter_gobj != NULL)
	{
		ftCommon_SetAllowPlayerControl(fighter_gobj);
		fighter_gobj = fighter_gobj->group_gobj_next;
	}
	gBattleState->game_status = gmMatch_GameStatus_Go;
}

// 801901F4
void scTrainingMode_UpdateOpponentBehavior()
{
	ftStruct *fp = ftGetStruct(gBattleState->player_block[gTrainingModeStruct.opponent].fighter_gobj);

	if (fp->status_info.pl_kind == Pl_Kind_Com)
	{
		fp->fighter_com.behavior_set = scTrainingMode_CPOpponent_BehaviorKind[gTrainingModeStruct.cp_menu_option];
		fp->fighter_com.behavior_write = 0xA;
	}
}

// 80190260
void scTrainingMode_InitTrainingMode()
{
	GObj *fighter_gobj;
	ftSpawnInfo player_spawn;
	s32 player;
	Unk800D4060 sp54;

	func_ovl7_8018DA98();
	func_ovl7_801906D0();
	scTrainingMode_LoadFiles();
	func_8000B9FC(9, 0x80000000, 0x64, 1, 0xFF);
	func_ovl2_80115890();
	func_ovl2_800EC130();
	mpCollision_InitMapCollisionData();
	cmManager_SetViewportCoordinates(10, 10, 310, 230);
	cmManager_MakeWallpaperCamera();
	grWallpaper_SetGroundWallpaper();
	func_ovl2_8010DB00();
	itManager_AllocUserData();
	grNodeInit_SetGroundFiles();
	ftManager_AllocFighterData(2, GMMATCH_PLAYERS_MAX);
	wpManager_AllocUserData();
	efManager_AllocUserData();
	ifScreenFlash_InitInterfaceVars(0xFF);
	gmRumble_SetPlayerRumble();
	ftPublicity_SetPlayerPublicReact();

	for (player = 0; player < ARRAY_COUNT(gBattleState->player_block); player++)
	{
		player_spawn = ftGlobal_SpawnInfo_MainData;

		if (gBattleState->player_block[player].player_kind == Pl_Kind_Not)
			continue;

		ftManager_SetFileDataKind(gBattleState->player_block[player].character_kind);
		player_spawn.ft_kind = gBattleState->player_block[player].character_kind;
		mpCollision_GetPlayerMPointPosition(player, &player_spawn.pos);
		player_spawn.lr_spawn = (player_spawn.pos.x >= 0.0F) ? LR_Left : LR_Right;
		player_spawn.team = gBattleState->player_block[player].team_index;
		player_spawn.player = player;
		player_spawn.model_lod = ((gBattleState->pl_count + gBattleState->cp_count) < 3) ? ftParts_LOD_HighPoly : ftParts_LOD_LowPoly;
		player_spawn.costume = gBattleState->player_block[player].costume_index;
		player_spawn.shade = gBattleState->player_block[player].shade_index;
		player_spawn.handicap = gBattleState->player_block[player].handicap;
		player_spawn.cp_level = gBattleState->player_block[player].level;
		player_spawn.stock_count = gBattleState->stock_setting;
		player_spawn.damage = 0;
		player_spawn.pl_kind = gBattleState->player_block[player].player_kind;
		player_spawn.p_controller = &gPlayerControllers[player];
		player_spawn.anim_heap = ftManager_AllocAnimHeapKind(gBattleState->player_block[player].character_kind);
		player_spawn.is_skip_entry = TRUE;
		fighter_gobj = ftManager_MakeFighter(&player_spawn);
		ftCommon_ClearPlayerMatchStats(player, fighter_gobj);
	}
	scTrainingMode_UpdateOpponentBehavior();
	ftManager_SetFileDataPlayables();
	scTrainingMode_SetGameStatusGo();
	func_ovl2_8010E2D4();
	ifPlayer_MagnifyArrows_SetInterface();
	func_ovl2_8010E1A4();
	scTrainingMode_InitMiscVars();
	func_ovl2_8010DDC4();
	func_ovl2_8010E374();
	func_ovl2_8010E498();
	ifPlayer_Tag_SetInterface();
	func_ovl2_8010F3A0();
	func_ovl2_8010F3C0();
	ifPlayer_Damage_InitInterface();
	ifPlayer_Stocks_SetInterface();
	scTrainingMode_InitStatDisplayAll();
	scTrainingMode_InitTrainingMenuAll();
	scTrainingMode_SetPlayDefaultMusicID();
	func_800266A0();
	func_800269C0(0x272);

	sp54 = D_ovl7_8019086C;

	func_ovl0_800D4060(0x3FD, 0xD, 0xA, &sp54, 0xC, 1, 0);
}

// 801905A8
void scTrainingMode_SetGeometryRenderLights(Gfx **display_list)
{
	gSPSetGeometryMode(display_list[0]++, G_LIGHTING);
	ftRender_Lights_DisplayLightReflect(display_list, gMapLightAngleX, gMapLightAngleY);
}

// 801905F4
void scManager_TrainingMode_InitScene()
{
	D_ovl7_80190870.unk_scdatabounds_0xC = (uintptr_t)&D_NF_800A5240 - 6400;

	func_80007024(&D_ovl7_80190870);

	D_ovl7_8019088C.arena_size = ((uintptr_t)&lOverlay7ArenaHi - (uintptr_t)&lOverlay7ArenaLo);
	D_ovl7_8019088C.proc_start = scTrainingMode_InitTrainingMode;

	do
	{
		func_800A2698(&D_ovl7_8019088C);
		func_ovl2_801157EC();
	}
	while (gTrainingModeStruct.exit_or_reset != 0);

	func_80020A74();

	while (func_80020D58(0) != FALSE)
		continue;
	func_80020B38(0, 0x7800);

	gSceneData.scene_previous = gSceneData.scene_current;
	gSceneData.scene_current = 0x12;
}

// 801906D0
void func_ovl7_801906D0()
{
	RldmSetup rldm_setup;

	rldm_setup.tableRomAddr = &D_NF_001AC870;
	rldm_setup.tableFileCount = &D_NF_00000854;
	rldm_setup.fileHeap = NULL;
	rldm_setup.fileHeapSize = 0;
	rldm_setup.statusBuf = gOverlay7StatusBuf;
	rldm_setup.statusBufSize = ARRAY_COUNT(gOverlay7StatusBuf);
	rldm_setup.forceBuf = gOverlay7ForceBuf;
	rldm_setup.forceBufSize = ARRAY_COUNT(gOverlay7ForceBuf);

	rldm_initialize(&rldm_setup);
	rldm_load_files_into(
		D_ovl2_80116BD0,
		ARRAY_COUNT(D_ovl2_80116BD0),
		gCommonSpriteFiles,
		hal_alloc(rldm_bytes_need_to_load(D_ovl2_80116BD0, ARRAY_COUNT(D_ovl2_80116BD0)), 0x10));
}