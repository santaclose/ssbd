#include <gm/battle.h>
#include <gr/grdef.h>
#include <ft/ftdef.h>
#include <gr/ground.h>
#include <it/itdef.h>

typedef struct grBonusDesc
{
	intptr_t o_main;
	intptr_t o_dobjdesc;
	intptr_t o_anim;

} grBonusDesc;

void func_ovl6_8018D0C0(){}
void func_ovl6_8018D0C8(){}

void func_ovl6_8018D0D0(void) {
	func_ovl2_8011485C();
}

extern gmMatchInfo gDefaultBattleState;
extern gmMatchInfo gBonusBattleState;
void func_ovl6_8018D0F0(void) 
{
	s32 player;
	s32 ft_kind;

	gSceneData.is_reset = FALSE;
	
	gBonusBattleState = gDefaultBattleState;
	gBattleState = &gBonusBattleState;

	gBattleState->game_type = gmMatch_GameType_Bonus;
	gBattleState->match_rules = GMMATCH_GAMERULE_BONUS | GMMATCH_GAMERULE_TIME;
	gBattleState->is_display_score = FALSE;
	
	gBattleState->pl_count = 1;
	gBattleState->cp_count = 0;
	
	if (gSceneData.scene_previous == 0x34) 
	{
		ft_kind = gSceneData.ft_kind;
		
		gBattleState->time_limit = 100;
		
		if (gSceneData.spgame_stage == 3) 
		{
			if (gSceneData.spgame_time_limit != 0x64) 
			{
				gBattleState->time_limit = 2;
			}
			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus1Start;
		}
		else 
		{
			if (gSceneData.spgame_time_limit != 0x64) 
			{
				gBattleState->time_limit = 2;
			}
			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus2Start;
		}
	} 
	else 
	{
		ft_kind = gSceneData.unk39;
		
		gBattleState->time_limit = 0x64;
		
		if (gSceneData.scene_previous == 0x13) 
		{
			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus1Start;
		} 
		else gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus2Start;
	}
	for (player = 0; player < ARRAY_COUNT(gBattleState->player_block); player++)
	{
		if (player == gSceneData.player_port)
		{
			gBattleState->player_block[player].player_kind = Pl_Kind_Man;
			gBattleState->player_block[player].character_kind = ft_kind;
			
			if (gSceneData.scene_previous == 0x34) 
			{
				gBattleState->player_block[player].costume_index = gSceneData.costume_index;
			} 
			else gBattleState->player_block[player].costume_index = gSceneData.unk3A;
			
			gBattleState->player_block[player].player_color_index = player;
		}
		else gBattleState->player_block[player].player_kind = Pl_Kind_Not;
	}
}

extern intptr_t D_NF_000000FD;
extern void* D_ovl6_8018F1A0[];
void func_ovl6_8018D330(void) 
{
	D_ovl6_8018F1A0[0] = rldm_get_file_with_external_heap((u32)&D_NF_000000FD, hal_alloc(rldm_bytes_needed_to_load((u32)&D_NF_000000FD), 0x10));
}

extern grBonusDesc D_ovl6_8018EEC4[];
void func_ovl6_8018D374(void) 
{
	grBonusDesc *bonus_desc = &D_ovl6_8018EEC4[gBattleState->gr_kind - Gr_Kind_Bonus1Start];
	void **atrack;
	DObjDesc *dobj_desc;
	Vec3f sp48;

	sp48.x = sp48.y = sp48.z = 0.0F;
	
	dobj_desc = (DObjDesc*) ((uintptr_t) ((uintptr_t)gGroundInfo->gr_desc[1].dobj_desc - (intptr_t)bonus_desc->o_main) + (intptr_t)bonus_desc->o_dobjdesc);
	atrack = (void**) ((uintptr_t) ((uintptr_t)gGroundInfo->gr_desc[1].dobj_desc - (intptr_t)bonus_desc->o_main) + (intptr_t)bonus_desc->o_anim);
	
	gGroundStruct.bonus1.target_count = 0;
	
	dobj_desc++, atrack++;
	
	while (dobj_desc->index != 0x12)
	{
		GObj* item_gobj = itManager_MakeItemSetupCommon(NULL, It_Kind_Target, &dobj_desc->translate, &sp48, 1);

		if (*atrack != NULL) 
		{
			omAddDObjAnimAll(DObjGetStruct(item_gobj), *atrack, 0.0F);
			func_8000DF34(item_gobj);
		}
		dobj_desc++, atrack++, gGroundStruct.bonus1.target_count++;
	}
	if (gGroundStruct.bonus1.target_count != 10)
	{
		fatal_printf("Error : not %d targets!\n", 10);
		while(TRUE);
	}
}

// void func_800096EC(void*);                         /* extern */
// extern grStruct gGroundStruct;

// void func_ovl6_8018D4C4(void) 
// {
// 	s32 i;
// 	SObj *sobj = SObjGetStruct(gGroundStruct.bonus1.interface_gobj);
	
// 	for (i = 0; i < gGroundStruct.bonus1.target_count; i++) 
// 	{
// 		sobj = sobj->next;
// 	}
// 	func_800096EC(sobj);
// }
