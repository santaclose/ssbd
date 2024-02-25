#define NULL ((void*)0)
#define DObjParentNULL ((void*)1)
#define FALSE 0
#define false FALSE

#define TRUE 1
#define true TRUE

#define SP_TRANSPARENT  0x00000001
#define SP_CUTOUT		0x00000002
#define SP_HIDDEN		0x00000004
#define SP_Z			0x00000008
#define SP_SCALE		0x00000010
#define SP_FASTCOPY		0x00000020
#define SP_OVERLAP		0x00000040
#define SP_TEXSHIFT		0x00000080
#define SP_FRACPOS		0x00000100
#define SP_TEXSHUF		0x00000200
#define SP_EXTERN		0x00000400

#define LR_Left -1
#define LR_Center 0
#define LR_Right 1
#define WALL_UP 2
#define WALL_DOWN 3

#define U8_MAX 0xFF
#define S8_MAX 0x7F
#define S8_MIN 0x80

#define U16_MAX 0xFFFF
#define S16_MAX 0x7FFF
#define S16_MIN 0x8000

#define U32_MAX 0xFFFFFFFF
#define S32_MAX 0x7FFFFFFF
#define S32_MIN 0x80000000

#define F_DEG_TO_RAD(x) ((f32)(((x) * PI32) / 180.0F))
#define F_RAD_TO_DEG(x) ((f32)(((x) / PI32) * 180.0F))
#define I_RAD_TO_DEG(x) ((int)(((x) / PI32) * 180.0F))

#define GEUPDATE_FRAMERATE_DEFAULT (60)

#define GETIME_SEC (GEUPDATE_FRAMERATE_DEFAULT * 1)
#define GETIME_MIN (GEUPDATE_FRAMERATE_DEFAULT * 60)
#define GETIME_HRS (GEUPDATE_FRAMERATE_DEFAULT * 600)

#define I_GETIME_TO_FRAMES(q, u) ((int) ((q) * (u)))

#define I_SEC_TO_FRAMES(q) ((int) ((q) * GETIME_SEC))
#define I_MIN_TO_FRAMES(q) ((int) ((q) * GETIME_MIN))
#define I_HRS_TO_FRAMES(q) ((int) ((q) * GETIME_HRS))
    
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#define ABS(x) \
((x < 0) ? -x : x) \

#define ABSF(x) \
((x < 0.0F) ? -x : x) \

#define SQUARE(x) ((x) * (x))

#define TERN_VEL_LR(x) \
((x < 0.0F) ? LEFT : RIGHT) \

#define MPCOLL_KIND_LWALL       (1 << 0)    // 0x1
#define MPCOLL_KIND_RWALL       (1 << 5)    // 0x20
#define MPCOLL_KIND_CEIL        (1 << 10)   // 0x400 
#define MPCOLL_KIND_GROUND      (1 << 11)   // 0x800
#define MPCOLL_KIND_LCLIFF      (1 << 12)   // 0x1000
#define MPCOLL_KIND_RCLIFF      (1 << 13)   // 0x2000
#define MPCOLL_KIND_CEILHEAVY   (1 << 14)   // 0x4000 - head bonk?
#define MPCOLL_KIND_UNK1        (1 << 15)   // 0x8000

#define MPCOLL_KIND_MAIN_MASK   (MPCOLL_KIND_GROUND | MPCOLL_KIND_CEIL | MPCOLL_KIND_RWALL | MPCOLL_KIND_LWALL) // Mask every main collision flag
#define MPCOLL_KIND_CLIFF_MASK  (MPCOLL_KIND_LCLIFF | MPCOLL_KIND_RCLIFF)                                       // Mask all ledge flags

#define MPCOLL_VERTEX_ATTR_BITS 8

#define MPCOLL_VERTEX_CLL_PASS (1 << 14) // Line ID can be passed through

#define MPCOLL_VERTEX_CLL_BITS (0xFF << (MPCOLL_VERTEX_ATTR_BITS * 1))
#define MPCOLL_VERTEX_MAT_BITS (0xFF << (MPCOLL_VERTEX_ATTR_BITS * 0))

#define MPCOLL_VERTEX_CLL_MASK (~MPCOLL_VERTEX_MAT_BITS) // This is what the game covers when checking flags & 0xFFFF00FF
#define MPCOLL_VERTEX_MAT_MASK (~MPCOLL_VERTEX_CLL_BITS) // This is what the game looks for when checking flags & 0xFFFF00FF

#define MPCOLL_VERTEX_ALL_BITS (MPCOLL_VERTEX_CLL_BITS | MPCOLL_VERTEX_MAT_BITS)

#define QUART_PI32 0.7853982F
#define HALF_PI32 1.5707964F
#define PI32 3.1415927F
#define DOUBLE_PI32 6.2831855F
    
#define FLOAT_MAX     3.4028235e38
#define FLOAT_NEG_MAX -FLOAT_MAX

#define GMCONTROLLER_RANGE_MAX_I 80                                 // Maximum control stick range in integer
#define GMCONTROLLER_RANGE_MAX_F ((float)GMCONTROLLER_RANGE_MAX_I)  // Maximum control stick range in float

#define GMHITCOLLISION_MASK_FIGHTER (1 << 0) // Can interact with fighters
#define GMHITCOLLISION_MASK_ITEM    (1 << 1) // Can interact with items
#define GMHITCOLLISION_MASK_ARTICLE (1 << 2) // Can interact with articles

#define GMHITCOLLISION_MASK_ALL     (GMHITCOLLISION_MASK_FIGHTER | GMHITCOLLISION_MASK_ITEM | GMHITCOLLISION_MASK_ARTICLE)
    
#define GMCOMPLAYER_LEVEL_MAX 9

#define GMMATCH_PLAYERS_MAX 4

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef volatile unsigned char vu8;
typedef volatile signed char vs8;
typedef volatile unsigned short vu16;
typedef volatile signed short vs16;
typedef volatile unsigned long vu32;
typedef volatile signed long vs32;
typedef volatile unsigned long long vu64;
typedef volatile signed long long vs64;

typedef float f32;
typedef double f64;

typedef volatile float vf32;
typedef volatile double vf64;

typedef  s8  sb8;
typedef s16 sb16;
typedef s32 sb32;

typedef u8   ub8;
typedef u16 ub16;
typedef u32 ub32;

typedef unsigned int uintptr_t;
typedef signed int intptr_t;
typedef unsigned int size_t;

typedef f32 mtx[3][4];
typedef f32 Mtx44f[4][4];

typedef struct Gfx Gfx;

typedef struct {

    s32 i[4][4];

} Mtx;

typedef struct {
	short	vscale[4];  /* scale, 2 bits fraction */
	short	vtrans[4];  /* translate, 2 bits fraction */
	/* both the above arrays are padded to 64-bit boundary */
} Vp_t;

typedef union {
    Vp_t		vp;
    long long int	force_structure_alignment;
} Vp;

struct bitmap {
	s16	width;		/* Size across to draw in texels */
				/* Done if width = 0		*/

	s16	width_img;	/* Size across of bitmap in texels */
				/* Done if width = 0		*/

	s16	s;		/* Horizontal offset into bitmap */
				/* if (s > width), then load only! */

	s16	t;		/* Vertical offset into base	*/

	void	*buf;		/* Pointer to bitmap data	*/
				/* Don't re-load if new buf	*/
				/* is the same as the old one   */
				/* Skip if NULL */

	s16	actualHeight;	/* True Height of this bitmap piece */

	s16	LUToffset;	/* LUT base index		*/
};

typedef struct bitmap Bitmap;

struct sprite {
	s16	x,y;		/* Target position		*/

	s16	width, height;	/* Target size			*/

	f32	scalex, scaley;	/* Texel to Pixel scale factor	*/

	s16	expx, expy;	/* Explosion spacing		*/

	u16 	attr;		/* Attribute Flags		*/
	s16	zdepth;		/* Z Depth 			*/

	u8	red;		/* Red component		*/
	u8	green;		/* Green component		*/
	u8	blue;		/* Blue component		*/
	u8	alpha;		/* Alpha component		*/

	s16	startTLUT;	/* Lookup Table Entry Starting index */
	s16	nTLUT;		/* Total number of Lookup Table Entries */

	int	*LUT;		/* Pointer to Lookup Table	*/

	s16	istart;		/* Starting bitmap index	*/
	s16	istep;		/* Bitmaps index step (see SP_INCY) */
				/* if 0, then variable width bitmaps */

	s16	nbitmaps;	/* Total number of bitmaps	*/
	s16	ndisplist;	/* Total number of display-list words */

	s16	bmheight;	/* Bitmap Texel height (Used)	*/
	s16	bmHreal;	/* Bitmap Texel height (Real)	*/
	u8	bmfmt;		/* Bitmap Format	 	*/
	u8	bmsiz;		/* Bitmap Texel Size		*/

	Bitmap	*bitmap;	/* Pointer to first bitmap	*/

	Gfx	*rsp_dl;	/* Pointer to RSP display list	*/

	Gfx	*rsp_dl_next;	/* Pointer to next RSP display entry	*/

	s16	frac_s,		/* Fractional Texture offsets */
		frac_t;		/* These have 5 fraction bits */
};

typedef struct sprite Sprite;

typedef struct _Vec2f
{
    f32 x;
    f32 y;

} Vec2f;

typedef struct _Vec2h
{

    s16 x;
    s16 y;

} Vec2h;

typedef struct _Vec2b
{
    s8 x;
    s8 y;

} Vec2b;

typedef struct _Vec2i
{
    s32 x;
    s32 y;

} Vec2i;

typedef struct _Vec3f
{

    f32 x;
    f32 y;
    f32 z;

} Vec3f;

typedef struct _Vec3d
{
    f64 x;
    f64 y;
    f64 z;

} Vec3d;

typedef struct _Vec3h
{
    s16 x;
    s16 y;
    s16 z;

} Vec3h;

typedef struct _Vec3i
{
    s32 x;
    s32 y;
    s32 z;

} Vec3i;

typedef struct _Vec4f
{
    f32 w;
    f32 x;
    f32 y;
    f32 z;

} Vec4f;

typedef struct gmController {
    /* 0x00 */ u16 button_press; // button
    /* 0x02 */ u16 button_new; // new button presses?
    /* 0x04 */ u16 button_update; // buttons to handle?
    /* 0x06 */ u16 button_release; // released buttons?
    Vec2b stick_range;

} gmController;

extern gmController gPlayerControllers[4];

typedef struct GfxColor
{
    u8 r, g, b;

} GfxColor;

typedef struct GfxColorAlpha
{
    u8 r, g, b, a;

} GfxColorAlpha;

extern GfxColorAlpha D_ovl2_801312F4;

typedef struct RldmFileNode 
{
    /* 0x00 */ u32 id;
    /* 0x04 */ void *addr;
} RldmFileNode; // size == 8

typedef struct RldmSetup
{
    /* 0x00 */ s32 tableRomAddr;
    /* 0x04 */ u32 tableFileCount;
    /* 0x08 */ u8 *fileHeap;
    /* 0x0C */ u32 fileHeapSize;
    /* 0x10 */ RldmFileNode *statusBuf;
    /* 0x14 */ s32 statusBufSize;
    /* 0x18 */ RldmFileNode *forceBuf;
    /* 0x1C */ s32 forceBufSize;
} RldmSetup; // size == 0x20    

extern intptr_t D_NF_00000854;
extern intptr_t D_NF_001AC870;
extern u32 D_ovl2_80116BD0[8];
    
typedef struct RldmFileSize
{
    u32 file_size;
    u32 largest_size1;
    u32 largest_size2;

} RldmFileSize;

RldmFileNode D_ovl2_80130DA0;
void rldm_initialize(RldmSetup*);
u32 rldm_bytes_need_to_load(u32*, u32);                 /* extern */
uintptr_t rldm_load_files_into(u32 *ids, u32 len, void **filePtrs, u8 *heapAddr);       /* extern */
extern RldmFileSize D_800A50F8[27];

typedef struct gmSoundEffect
{
    void *unk_0x0;
    void *unk_0x4;
    void *unk_0x8;
    void *unk_0xC;
    u16 unk_0x10;
    u16 unk_0x12;
    u16 unk_0x14;
    u16 unk_0x16;
    u16 unk_0x18;
    u16 unk_0x1A;
    u16 unk_0x1C;
    u16 unk_0x1E;
    u16 unk_0x20;
    u16 unk_0x22;
    u16 unk_0x24;
    u16 sfx_id;
    
} gmSoundEffect;

static s32 gmMusicIndexCurrent;
static s32 gmMusicIndexDefault;

typedef enum gmPauseStatus
{
    gmPauseStatus_Disable,        // Pausing not allowed
    gmPauseStatus_Enable,         // Pausing allowed
    gmPauseStatus_Paused,         // Player paused
    gmPauseStatus_Unpause         // Player unpaused

} gmPauseStatus;

typedef struct gmPlayerStale
{
    u16 unk_0x0;
    u16 unk_0x2;

} gmPlayerStale;

typedef enum gmHitCollisionStatus
{
    gmHitCollision_HitStatus_None, // User's hurtboxes are disabled
    gmHitCollision_HitStatus_Normal, // User can be hit
    gmHitCollision_HitStatus_Invincible, // User can be hit, but is immune to damage
    gmHitCollision_HitStatus_Intangible // User cannot be hit

} gmHitCollisionStatus;

typedef enum gmHitCollisionElement
{
    gmHitCollision_Element_Normal,
    gmHitCollision_Element_Fire,
    gmHitCollision_Element_Electric,
    gmHitCollision_Element_Slash,
    gmHitCollision_Element_Coin,
    gmHitCollision_Element_Unk1,
    gmHitCollision_Element_Sleep,
    gmHitCollision_Element_Unk2

} gmHitCollisionElement;

typedef enum gmHitCollisionType // Hitbox types, this is universal but I don't know where else to put it so both fighters and items can see it without redefining it for each
{
    gmHitCollision_Type_Hurt,
    gmHitCollision_Type_Shield,
    gmHitCollision_Type_Unk,
    gmHitCollision_Type_Hit,
    gmHitCollision_Type_ArticleHurt,             // Only used for specific articles? e.g. Pirahna Plants dealing damage
    gmHitCollision_Type_Absorb,
    gmHitCollision_Type_Reflect

} gmHitCollisionType;

typedef enum gmHitCollisionUpdateState
{
    gmHitCollision_UpdateState_Disable,          // No active hitbox or updates
    gmHitCollision_UpdateState_New,              // Initialize hitbox positions
    gmHitCollision_UpdateState_Transfer,         // Transitions to interpolation mode, that's it
    gmHitCollision_UpdateState_Interpolate       // Copies current position to previous

} gmHitCollisionUpdateState;

typedef struct t_mtx
{

    mtx *position_mtx; // ???
    u16 render_call_id; 
    s16 scale_x; // 0x8
    s32 unk_0xC;
    s16 unk_0x10;
    s16 scale_y;
    s32 unk_0x14;
    s32 unk_0x18;
    s16 scale_z;

    // Wildly unfinished, the offsets don't make much sense

} t_mtx;

typedef struct _Object
{
    void *class_info;
    u16 ref;
    u16 ref_count;

} Object;

typedef enum ftHitStatus
{
    ftHitStatus_Normal,
    ftHitStatus_Unk,
    ftHitStatus_Invincible,
    ftHitStatus_Intangible
        
} ftHitStatus;

typedef enum Ground_Air
{
    GA_Ground,
    GA_Air

} Ground_Air;

typedef enum omGObjKind
{
    omGObj_Kind_Fighter = 1000,     // 1000
    omGObj_Kind_MainCamera = 1002,  // 1002
    omGObj_Kind_WallpaperCamera,    // 1003 - Used to render stage backgrounds?
    omGObj_Kind_ScissorCamera,      // 1004 - Camera scissor?
    omGObj_Kind_UnkCamera1,         // 1005 - ???
    omGObj_Kind_UnkCamera2,         // 1006 - ???
    omGObj_Kind_GrWallpaper = 1008, // 1008 - Stage background?
    omGObj_Kind_GrRender,           // 1009 - Stage renderer?
    omGObj_Kind_Ground,             // 1010
    omGObj_Kind_Effect,             // 1011
    omGObj_Kind_Weapon,             // 1012
    omGObj_Kind_Item,               // 1013
    omGObj_Kind_Interface = 1016,   // 1016
    omGObj_Kind_Rumble,
    omGObj_Kind_PauseMenu = 1019    // 1019

} omGObjKind;

typedef enum omGObjLinkIndex
{
    omGObj_LinkIndex_Fighter = 3,     // 3
    omGObj_LinkIndex_Item,            // 4
    omGObj_LinkIndex_Weapon,          // 5
    omGObj_LinkIndex_Effect,          // 6
    omGObj_LinkIndex_Interface = 11,  // 11
    omGObj_LinkIndex_Rumble = 13,     // 13
    omGObj_LinkIndex_Background = 13, // 13 // Same index as rumble???
    omGObj_LinkIndex_PauseMenu        // 14

} omGObjLinkIndex;

typedef struct GObj GObj;

typedef struct _GObjProcess GObjProcess;

struct _GObjProcess
{
    GObjProcess *gobjproc_next; // This is more than likely not an array, doing this only to get the correct offsets
    GObjProcess *gobjproc_prev;
    GObjProcess *unk_gobjproc_0x8[2];
    s32 priority;
    u8 kind;
    u8 unk_gobjproc_0x15;
    GObj *parent_gobj;
    union // These are based on 0x14
    {
        void *thread; // GObjThread
        void(*proc)(GObj*);
    };
    void *unk_gobjproc_0x20;
};

typedef struct DObjMultiList
{
    Gfx *dl1, *dl2;

} DObjMultiList;

typedef struct DObj DObj;

struct GObj
{
    // Info here acquired from halofactory of the Smash Remix team
    omGObjKind gobj_id; // arbitrary ID signifying related objects? e.g. 0x000003F8
    GObj *group_gobj_next;
    GObj *group_gobj_prev;
    u8 group;
    u8 room;
    u8 asynchronous_timer; // For subaction events?
    u8 unk_0xF;
    s32 group_order; // Might be room?
    void *call_unk;
    GObjProcess *gobjproc;
    s32 unk_0x1C;
    GObj *room_gobj_next;
    GObj *room_gobj_prev;
    s32 room_order; // Might be group? Assuming room based on order here
    void (*renderer)(GObj *gobj);
    u64 unk_0x30;
    s32 unk_0x38; // 0xFFFFFFFF, textures or series of flags?
    u8 filler_0x3C[0x74 - 0x3C];
    void *obj;
    f32 anim_frame; // Current frame of animation?
    u32 obj_renderflags;
    void (*dobjproc)(DObj*, s32, f32);
    void *user_data;
};

typedef struct cmStruct
{
    s32 status_default;
    s32 status_curr;
    s32 status_prev;
    void (*proc_camera)(GObj*);
    f32 cam_target_dist;
    Vec3f unk_cmstruct_0x14;
    s32 scissor_ulx;
    s32 scissor_uly;
    s32 scissor_lrx;
    s32 scissor_lry;
    s32 unk_cmstruct_0x30;
    s32 unk_cmstruct_0x34;
    Vec2i unk_0x38;
    f32 unk_cmstruct_0x40;
    GObj *pl_pause_gobj;        // Guess: this is a struct from here...
    f32 unk_cmstruct_0x48;
    f32 unk_cmstruct_0x4C;
    f32 unk_cmstruct_0x50;
    f32 unk_cmstruct_0x54;
    f32 unk_cmstruct_0x58;
    Vec3f unk_cmstruct_0x5C;
    Vec3f unk_cmstruct_0x68;    // ...to here
    GObj *pl_bonus_gobj;        // ...and there is an array of it
    f32 unk_cmstruct_0x78;
    f32 unk_cmstruct_0x7C;
    f32 unk_cmstruct_0x80;
    f32 unk_cmstruct_0x84;
    f32 unk_cmstruct_0x88;
    Vec3f unk_cmstruct_0x8C;

} cmStruct;

typedef struct ifDamagePosition
{
    s32 hz_pos[4];

} ifDamagePosition;

typedef struct ifPlayerCommon
{
    u8 is_ifmagnify_display;
    u8 ifmagnify_mode;
    f32 ifmagnify_scale;
    s32 *ifplayers_pos_x;    // Pointer to each player's HUD X-position
    u16 ifplayers_pos_y;     // Player HUD's Y-positions - subtracted from center Y-position?
    u8 unk_80131580_0xE;
    u8 unk_80131580_0xF;
    u8 unk_80131580_0x10;

} ifPlayerCommon;

extern ifPlayerCommon gPlayerCommonInterface;

extern GObj *gCameraGObj;
extern Mtx44f D_ovl2_80131470, gCameraMatrix;
extern cmStruct D_ovl2_801314B0, gCameraStruct;

typedef union ACommand
{    
    struct
    {
        u16 opcode : 5;
        u16 flags : 10;
        u16 toggle : 1;

    } command;

    union
    {
        s16 shalf;
        u16 uhalf;
    }
    param;

} ACommand;

typedef union ATrack
{
    u32 w;
    f32 f;
    void *p;
    ACommand c;

} ATrack;

typedef struct AObj AObj;

struct AObj {
    /* 0x00 */ AObj *next;
    /* 0x04 */ u8 unk_aobj_0x4;
    /* 0x05 */ u8 unk_aobj_0x5;
    /* 0x08 */ f32 unk_aobj_0x8;
    /* 0x0C */ f32 unk_aobj_0xC;
    /* 0x10 */ f32 unk_aobj_0x10;
    /* 0x14 */ f32 unk_aobj_0x14;
    /* 0x18 */ f32 unk_aobj_0x18;
    /* 0x1C */ f32 unk_aobj_0x1C;
    // interpolation control struct?
    /* 0x20 */ ACommand *interpolate;
}; // size == 0x24

#define ACommandCast(acommand, type) \
((type*)(acommand)) \

#define ACommandAdvance(acommand) \
((acommand)++) \

#define ACommandGetAdvanceCast(acommand, type) \
(*((type*)(acommand)++)) \

#define ACommandTempAdvance(acommand) \
((acommand) + 1) \

// Cast to type pointer then dereference
#define ACommandGetParam(acommand, type) \
(*(type*)(acommand)) \

typedef struct MObj // Image footer struct
{
    void *mobj_next;
    u8 filler_0x4[0x34];
    u16 mobj_flags;
    u16 filler_0x3A;
    u8 filler_0x3C[0x60 - 0x3C];
    GfxColorAlpha mobj_color1;
    u8 filler_0x64[0x80 - 0x64];
    u16 index;
    f32 unk_0x84;
    f32 anim_frame;
    u8 filler_0x8C[0x94 - 0x8C];
    u32 unk_mobj_0x94;
    f32 unk_mobj_0x98;
    f32 unk_mobj_0x9C;
    f32 unk_mobj_0xA0;

} MObj;

typedef struct ftParts ftParts;

// PObj / Polygon object?
struct ftParts
{
    s32 unk_dobjtrans_0x0;
    u8 unk_dobjtrans_0x4;
    u8 unk_dobjtrans_0x5;
    u8 unk_dobjtrans_0x6;
    u8 unk_dobjtrans_0x7;
    ftParts *unk_dobjtrans_alloc_next;
    u8 unk_0xC;
    u8 unk_0xD; // Joint ID this is attached to?
    u8 unk_dobjtrans_0xE;
    u8 unk_dobjtrans_0xF;
    Mtx44f unk_dobjtrans_0x10;
    Mtx44f unk_dobjtrans_0x50;
    Vec3f unk_dobjtrans_0x90; // Scale?
    Mtx44f unk_dobjtrans_0x9C;
    GObj *unk_gobj;
};

ftParts* gMainFighterPartsCurrent;

struct OMMtx {
    /* 0x00 */ struct OMMtx *next;
    /* 0x04 */ u8 unk04; // kind
    /* 0x05 */ u8 unk05;
    /* 0x08 */ Mtx unk08;
    ///* 0x08 */ f32 unk08[4][4];
    ///* 0x08 */ f32 (*unk08)[4][4];
    ///* 0x0C */ u8 pad0C[0x48 - 0xc];
}; // size == 0x48

typedef struct HAL_Bitmap
{
    Vec3f unk_bitmap_0x0;
    void *unk_bitmap_0xC;
    Vec3f unk_bitmap_0x10;
    s32 unk_bitmap_0x1C;
    Vec3f unk_bitmap_0x20;
    void *unk_bitmap_0x2C;
    Vec3f unk_bitmap_0x30;
    f32 unk_bitmap_0x3C;

} HAL_Bitmap;

typedef struct OMMtxCamera
{
    struct OMMtx *mtx;
    Vec3f tilt;
    Vec3f pan;
    Vec3f unk;
    
} OMMtxCamera;

typedef struct _Mtx6f {
    /* 0x00 */ struct OMMtx *mtx;
    /* 0x04 */ f32 f[6];
} Mtx6f; // size == 0x1C

typedef struct _Mtx7f
{
    /* 0x00 */ struct OMMtx *mtx;
    /* 0x04 */ f32 f[7];
} Mtx7f; // size == 0x20

typedef struct OMCamera
{
    s32 unk_omcam_0x0;
    s32 unk_omcam_0x4;
    Vp viewport;
    union
    {    
        Mtx6f f6;
        Mtx7f f7;

    } mtx_types;
    OMMtxCamera view;
    u32 mtx_len;
    struct OMMtx *om_mtx[2];
    AObj *aobj;

    union
    {
        ATrack *atrack; // Unconfirmed
        ACommand *acommand;
    };

    f32 omcam_f0;
    f32 omcam_f1;
    f32 omcam_f2;
    u32 flags;

} OMCamera;

typedef struct DObjDesc
{
    s32 index;
    void *display_list;
    Vec3f translate;
    Vec3f rotate;
    Vec3f scale;

} DObjDesc;

typedef struct OMMtxVec3
{
    struct OMMtx *mtx;

    union
    {
        Vec3f f;
        Vec3i i;

    } vec;

} OMMtxVec3;

typedef struct OMMtxVec4
{
    struct OMMtx *mtx;
        
    f32 w; // W axis? Quaternion?

    union
    {
        Vec3f f;
    }
    vec;

} OMMtxVec4;

struct DObj
{
    u8 filler_0x0[0x4];
    GObj *parent_gobj;
    union
    {
        struct
        {
            DObj *sib_next; // Next sibling? 0x8
            DObj *sib_prev; // Previous sibling? 0xC
            DObj *child;    // Child? 0x10
            union
            {
                DObj *parent;   // Parent? 0x14
                s32 nullcheck;
            };
            
        };
        struct
        {
            DObj *unk_0x8;
            DObj *unk_0xC;
            DObj *next;
            DObj *prev;
        };
    };
    OMMtxVec3 translate;
    OMMtxVec4 rotate;
    OMMtxVec3 scale;
    s32 unk_0x4C;
    union
    {
        void *display_list;
        DObjMultiList *multi_list;
    };
    u8 unk_0x54;
    u8 unk_dobj_0x55;
    u8 unk_dobj_0x56;
    struct OMMtx *om_mtx[5];
    AObj *aobj;
    union
    {
        ATrack *atrack; // Unconfirmed
        ACommand *acommand;
    };
    f32 dobj_f0;
    f32 dobj_f1;
    f32 dobj_f2;
    MObj *mobj;
    union
    {
        DObj *attach_dobj;
        ftParts *unk_0x84;
        s32 yakumono_id; // Used in dynamic collision for moving platforms
    };
};

typedef struct _SObj SObj;

struct _SObj // Sprite object?
{
    SObj *next;
    GObj *parent_gobj;
    SObj *unk_sobj_0x8;
    SObj *unk_sobj_0xC;
    Sprite sprite;
    void *sobj_user_data;
    Vec2f pos; // Position / offset? Causes a ghosting effect if out of bounds
    GfxColor sobj_color;
};

typedef struct DObjRenderTypes
{
    u8 t1, t2, t3;

} DObjRenderTypes;

typedef struct efCreateDesc
{
    u8 unk_efcreate_0x0;
    u8 unk_efcreate_0x1;
    void *unk_efcreate_0x4;
    DObjRenderTypes unk_efcreate_0x8;
    DObjRenderTypes unk_efcreate_0xB;
    void (*proc_update)(GObj*);
    void (*unk_efcreate_0x14)(GObj*);
    intptr_t unk_efcreate_0x18;
    intptr_t unk_efcreate_0x1C;
    intptr_t unk_efcreate_0x20;
    intptr_t unk_efcreate_0x24;

} efCreateDesc;

typedef struct efTransform
{
    u8 filler_0x0[0x4];
    Vec3f translate;
    Vec3f rotate;
    Vec3f scale;
    u16 unk_effect_0x28;
    u16 unk_effect_0x2A;
    u8 filler_0x2C[0x4B - 0x2C];
    u8 unk_effect_0x4B;
    u8 filler_0x4C[0xB4 - 0x4C];
    void (*proc_dead)(GObj*);
    u16 unk_effect_0xB8;
    GObj *effect_gobj;

} efTransform;

typedef struct efGenerator
{
    u8 filler_0x0[0x14];
    Vec3f pos;

} efGenerator;

typedef struct efParticle
{
    u8 filler_0x0[0x8];
    u8 unk_efpart_0x8;
    u16 unk_efpart_0xA;
    u8 filler_0xC[0x20 - 0xC];
    Vec3f pos;
    u8 filler_0x2C[0x48 - 0x2C];
    GfxColorAlpha color1;
    s32 unk_efpart_0x4C;
    GfxColorAlpha color2;
    u8 filler_0x54[0x5C - 0x54];
    efTransform *effect_info;

} efParticle;

typedef struct efVars_Basic1
{
	s32 lifetime;
	s32 unk_ef_0x1C;

} efVars_Basic1;

typedef struct efVars_Basic2
{
    Vec3f vel;
    u8 player;
    s32 size;
    efTransform *eftrans;
    u8 filler_0x30[0x3C - 0x30];

} efVars_Basic2;

typedef struct efVars_DamageNHeavy
{
    Vec3f pos;
    u8 player;
    s32 size;

} efVars_DamageNHeavy;

typedef struct efVars_DamageEHit
{
    Vec3f vel;
    s32 size;
    efTransform *eftrans;

} efVars_DamageEHit;

typedef struct efVars_Common
{
    Vec3f vel;
    s32 size;
    efTransform *eftrans;

} efVars_Common;

typedef struct efVars_DustLight
{
    Vec3f vel1, vel2;
    s32 lifetime;
    efTransform *eftrans;

} efVars_DustLight;

typedef struct efVars_DustHeavy
{
    Vec3f pos;
    s32 lr;
    s32 anim_frame;
    efTransform *eftrans;

} efVars_DustHeavy;

typedef struct efVars_DamageFlyOrbs
{
    Vec3f vel;
    s32 lifetime;

} efVars_DamageFlyOrbs;

typedef struct efVars_DamageSpawnOrbs
{
    s32 lifetime;
    Vec3f pos;

} efVars_DamageSpawnOrbs;

typedef struct efVars_ImpactSW
{
    u8 index;
    f32 alpha;
    f32 decay;

} efVars_ImpactSW;

typedef struct efVars_StarRodSpark
{
    Vec3f vel, add;
    s32 add_timer;

} efVars_StarRodSpark;

typedef struct efVars_DamageFlySpark
{
    Vec3f vel, add;
    s32 add_timer;

} efVars_DamageFlySpark;

typedef struct efVars_DamageSpawnSpark
{
    s32 lifetime;
    Vec3f pos;
    s32 lr;

} efVars_DamageSpawnSpark;

typedef struct efVars_DamageFlyMDust
{
    Vec3f vel, add;
    s32 add_timer;

} efVars_DamageFlyMDust;

typedef struct efVars_DamageSpawnMDust
{
    s32 lifetime;
    Vec3f pos;
    s32 lr;

} efVars_DamageSpawnMDust;

typedef struct efVars_Quake
{
    u8 priority;

} efVars_Quake;

typedef struct efVars_Reflector
{
    s32 index;
    s32 status;

} efVars_Reflector;

typedef struct efVars_Shield
{
    s32 unk_efshield_0x0;
    sb32 unk_efshield_0x4;

} efVars_Shield;

typedef struct efVars_ThunderTrail
{
    s32 lifetime;

} efVars_ThunderTrail;

typedef struct efParticle_EffectVars_PKThunder
{
    s32 status;
    GObj *owner_gobj;

} efParticle_EffectVars_PKThunder;

typedef struct efParticle_EffectVars_YoshiEggLay
{
    s32 index;
    s32 force_index;

} efParticle_EffectVars_YoshiEggLay;

typedef struct efParticle_EffectVars_CaptureKirbyStar
{
    s32 effect_timer;

} efParticle_EffectVars_CaptureKirbyStar;

typedef struct efParticle_EffectVars_LoseKirbyStar
{
    Vec2f vel;
    s16 lifetime;
    s16 lr;

} efParticle_EffectVars_LoseKirbyStar;

typedef struct efParticle_EffectVars_MiscUnk1
{
    Vec3f pos;
    s32 unk_miscunk1_0xC;
    f32 scale_step;
    s32 lr;
    void *unk_miscunk1_0x18;
    void *unk_miscunk1_0x1C;
    u8 unk_miscunk1_0x20;

} efParticle_EffectVars_MiscUnk1;

typedef struct Unk_Ovl2Effect_Ptr
{
    u16 unk_ovl2efptr_0x0;
    u16 unk_ovl2efptr_0x2;
    s32 unk_ovl2efptr_0x4;
    u8 unk_ovl2efptr_0x8;

} Unk_Ovl2Effect_Ptr;

typedef struct Unk_Ovl2Effect_Container
{
    Unk_Ovl2Effect_Ptr p[1];

} Unk_Ovl2Effect_Container;

typedef struct Unk_Ovl2Effect_Vec
{
    Vec3f pos;
    f32 unk_ovl2efvec_scale;
    u16 unk_ovl2efvec_0x10;
    void (*unk_ovl2efvec_proc)(GObj*);
    efCreateDesc effect_desc;

} Unk_Ovl2Effect_Vec;

typedef struct Unk_Ovl2Effect_Sub
{
    u8 unk_ovl2efsub_0x0;
    Unk_Ovl2Effect_Ptr *unk_ovl2efsub_0x4;
    s32 unk_ovl2efsub_0x8;
    Unk_Ovl2Effect_Vec *unk_ovl2efsub_0xC;

} Unk_Ovl2Effect_Sub;

typedef struct Unk_Ovl2Effect_Main
{
    s32 unk_ovl2efmain_0x0;
    u16 unk_ovl2efmain_0x4;
    u16 unk_ovl2efmain_0x6;
    u8 unk_ovl2efmain_0x8;
    u8 *unk_ovl2efmain_0xC;
    s32 unk_ovl2efmain_0x10;
    s32 unk_ovl2efmain_0x14;
    Unk_Ovl2Effect_Sub *unk_ovl2efmain_0x18;

} Unk_Ovl2Effect_Main;

Unk_Ovl2Effect_Main D_ovl2_80131AD8;

typedef struct efStruct
{
    void *ep_alloc_next;
    GObj *fighter_gobj;
    u16 unk_effectstruct_0x8;
    efTransform *einfo;
    u32 is_pause_effect : 1;
    u32 effect_flags_b1 : 1;
    u32 effect_flags_b2 : 1;
    u32 effect_flags_b3 : 1;
    void (*proc_update)(GObj*);

    union effect_vars // Effect vars union?
    {
        efVars_Common common;
        efVars_Basic1 basic1;
        efVars_Basic2 basic2;
        efVars_DamageNHeavy damage_n_heavy;
        efVars_DustLight dust_light;
        efVars_DustHeavy dust_heavy;
        efVars_DamageFlyOrbs damage_fly_orbs;
        efVars_DamageSpawnOrbs damage_spawn_orbs;
        efVars_ImpactSW impact_sw;
        efVars_StarRodSpark star_rod_spark;
        efVars_DamageFlySpark damage_fly_spark;
        efVars_DamageSpawnSpark damage_spawn_spark;
        efVars_DamageFlyMDust damage_fly_mdust;
        efVars_DamageSpawnMDust damage_spawn_mdust;
        efVars_Quake quake;
        efVars_Reflector reflector;
        efVars_Shield shield;
        efVars_ThunderTrail thunder_trail;
        efParticle_EffectVars_PKThunder pkthunder;
        efParticle_EffectVars_YoshiEggLay yoshi_egg_lay;
        efParticle_EffectVars_CaptureKirbyStar capture_kirby_star;
        efParticle_EffectVars_LoseKirbyStar lose_kirby_star;
        efParticle_EffectVars_MiscUnk1 misc_unk1;
    } 
    effect_vars;

} efStruct;

typedef struct unsigned_bit
{
    u8 bit : 1; 

} unsigned_bit;

#define GMMATCH_PLAYERS_MAX 4

typedef enum gmMatchGameRules
{
    gmMatch_GameRule_Time,
    gmMatch_GameRule_Stock,
    gmMatch_GameRule_Bonus,
    gmMatch_GameRule_1PGame

} gmMatchGameRules;

#define GMMATCH_GAMERULE_TIME    (1 << gmMatch_GameRule_Time)   // 0x1
#define GMMATCH_GAMERULE_STOCK   (1 << gmMatch_GameRule_Stock)  // 0x2
#define GMMATCH_GAMERULE_BONUS   (1 << gmMatch_GameRule_Bonus)  // 0x4
#define GMMATCH_GAMERULE_1PGAME  (1 << gmMatch_GameRule_1PGame) // 0x8

typedef enum gmMatchGameType
{
    gmMatch_GameType_Demo,
    gmMatch_GameType_VSMode,
    gmMatch_GameType_Bonus,
    gmMatch_GameType_HowToPlay,
    gmMatch_GameType_1PGame = 5

} gmMatchGameType;

typedef struct gmPlayerBlock
{
    u8 level; // Actually begins at 1 instead of 0
    u8 handicap; // Master Hand's handicap value is 35!?
    u8 player_kind; // 0 = HMN, 1 = CPU, 5 = How to Play,
    u8 character_kind; // Same as ftKind
    u8 team_index;
    u8 player; // Identical to team index if team battle is on?
    u8 costume_index;
    u8 shade_index; // Color overlay applied when several players use the same costume
    u8 team_color_index;
    u8 is_permanent_stock;
    u8 tag_index;
    s8 stock_count; // -1 = player has no stocks
    u8 is_rebirth_multi; // Respawn flag of multi-man enemy teams (Yoshi, Kirby, Fighting Polygons) in 1P mode
    u8 placement; // ???
    s32 falls;
    s32 score; // Caps at positive 999, crashes if way too low
    s32 total_ko_player[4];
    s32 unk_pblock_0x28;
    s32 unk_pblock_0x2C;
    s32 total_self_destruct;
    s32 total_damage_dealt; // Total damage dealt to all players
    s32 total_damage_all; // Damage received from all hazards
    s32 total_damage_player[4]; // Total damage received from each player present
    s32 stock_damage_all;  // All damage received per current stock, from any hazard
    s32 combo_damage_foe; // Total damage from consecutive hits dealt by foes (Resets when hitstun ends)
    s32 combo_count_foe; // Number of consecutive hits received from foes (Resets when hitstun ends)
    GObj *fighter_gobj; // Pointer to player's fighter GObj
    u32 stale_index; // Current position in stale queue?
    u16 stale_flags[5][2];

} gmPlayerBlock;

typedef struct gmMatchInfo
{
    u8 game_type;
    u8 gr_kind;
    u8 is_team_battle;
    u8 match_rules;     // Series of flags; 0x1 = time, 0x2 = stock
    u8 pl_count;        // Number of human players registered
    u8 cp_count;        // Number of computer players registered
    u8 time_limit;
    u8 stock_setting;   // Number of stocks set in game rules
    u8 handicap_setting;// 0 = OFF, 1 = ON, 2 = AUTO
    u8 is_team_attack;  // 0 = OFF, 1 = ON
    u8 is_stage_select; // 0 = OFF, 1 = ON
    u8 damage_ratio;
    u32 item_toggles;   // Bits = item's on/off switch from match settings
    u8 unk_0x10;
    u8 game_status;
    u8 unk_0x12;
    u8 unk_0x13;
    u32 match_time_remain; // Frames remaining until timeout
    u32 match_time_current; // Current match frame, counts up from 0
    u8 item_switch; // Has various settings (0x0 on Master Hand and Giant DK (?), 0x1 on Metal Mario battle, 0x2 on Hyrule Castle, 0x3 on various stages, 0x4 on Polygon Team? 
    u32 is_display_score : 1;       // Displays score when a fighter falls
    u32 is_ignore_teamshadow : 1;   // If FALSE, shadows are colored based on players' team affiliation, otherwise use default shadow color
    gmPlayerBlock player_block[4]; // Holds data for each player

} gmMatchInfo;

extern gmMatchInfo *gBattleState, D_800A4EF8, D_800A4D08;

typedef struct gmBattleResults
{
    s32 tko;
    s32 kos;
    u8 player_or_team;
    u8 unk_battleres_0x9;
    u8 unk_battleres_0xA;

} gmBattleResults;

struct RecordCharCombo {
    /* 0x00 */ u16 gamesWith;
    /* 0x02 */ u16 playedAgainst;
}; // size == 4

struct VsRecordData {
    /* 0x00 */ u16 kos[12];
    /* 0x18 */ u32 timeUsed; //< in seconds
    /* 0x1C */ u32 damageDealt;
    /* 0x20 */ u32 damageReceived;
    /* 0x24 */ u16 totalSDs;
    /* 0x26 */ u16 gamesPlayed;
    /* 0x28 */ u16 gamesPlayedAgainst;
    /* 0x2C */ struct RecordCharCombo combinations[12];
}; // size == 0x5C

struct SinglePlayerData
{
    u32 spgame_hiscore;
    u32 spgame_continues;
    u32 spgame_bonuses;
    s8 spgame_best_difficulty;
    u32 tt_time;
    u8 tt_mato_count;
    u32 bp_time;
    u8 bp_platform_count;
    u8 unk_0x1D;
    u8 unk_0x1E;
    u8 unk_0x1F;
};

// is this the saved data structure?
struct gmSaveInfo {
    /* 0x000 */ struct VsRecordData vsRecords[12];
    u8 unk450;
    u8 unk451;
    u8 unk452;
    u8 unk453;
    u8 unk454;
    u8 unk455;
    u8 unk456;
    u8 unlock_mask;
    u16 unk458;
    u8 spgame_difficulty;
    u8 spgame_stock_count;
    struct SinglePlayerData spgame_records[12];
    u16 unlock_task_inishie;    // Records mask of unique stages played in VS mode
    u8 unlock_task_itemswitch;  // Records number of VS games played for Item Switch unlock
    u16 vsgame_total;           // Total amount of VS games played?
    u8 mprotect_fail;           // Some kind of anti-piracy measure??? 0x1 results in random knockback velocity, 0x2 halves stick range, 0x4 forces Mario in 1P game
    u8 unk5E3;  
    u8 unk5E4;
    u8 unk5E5;
    u8 unk5E6;
    u8 unk5E7;
    s32 mprotect_hash;
}; // size == 0x5EC

typedef struct gmSceneInfo
{
    u8 scene_current;
    u8 scene_previous;
    u8 unk02;
    u8 pad03[0x09 - 0x03];
    u8 unk09;
    u8 unk0A;
    u8 pad0B[0xF - 0xB];
    u8 gr_kind;
    u8 unk10;
    ub8 is_select_continue;
    ub8 is_reset;    // Player did A + B + R + Z button combination
    u8 player_port;
    u8 ft_kind;
    u8 costume_index;
    u8 unk16;
    u8 scene_queue; // Unconfirmed
    u8 cpu_port[3];
    u8 pad20[0x20 - 0x1B];
    u32 spgame_score;
    u32 continues_used;
    u32 bonuses; // Number of bonuses player acquired throughout the game
    u32 bonus_get_mask[2]; // Different bonuses the player has accumulated per match
    u32 bonus_tasks_complete;
    u8 unk38;
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;

} gmSceneInfo; // size == 0x48

typedef struct scUnkDataBounds
{
    uintptr_t unk_scdatabounds_0x0;
    uintptr_t unk_scdatabounds_0x4;
    uintptr_t unk_scdatabounds_0x8;
    uintptr_t unk_scdatabounds_0xC;
    u8 filler_0x10[0x1C - 0x10];

} scUnkDataBounds;

typedef struct scRuntimeInfo
{
    u8 filler_0x0[0xC];
    void *unk_scruntime_0xC;
    uintptr_t unk_scruntime_0x10;
    u8 filler_0x14[0x88 - 0x14];
    void (*proc_start)(); // 0x88
    
} scRuntimeInfo;

extern gmMatchInfo *Match_Info;
struct gmSaveInfo Save_Info, gSaveData;
extern struct gmSceneInfo Scene_Info, gSceneData;

typedef struct gmItemSpawn
{
    u8 max_items;
    u8 *item_toggles;
    u32 item_spawn_timer;
    void *unk_0xC;
    u32 unk_0x10;
    s8 unk_0x14;
    u8 *unk_0x18;
    u16 unk_0x1C;
    u16 *unk_0x20;

} gmItemSpawn;

static gmItemSpawn item_settings;

typedef struct Unk_8018D048
{
    u8 filler_0x0[0x8];
    u8 unk_0x8;
    u8 *unk_0xC;
    u16 unk_0x10;
    u16 *unk_0x14;

} Unk_8018D048;

static Unk_8018D048 D_ovl3_8018D048;

typedef struct Unk_8018D060
{
    u8 unk_0x0;
    u8 unk_0x1;
    u8 unk_0x2[0x2C];
    u8 unk_0x2E;

} Unk_8018D060;

static Unk_8018D060 D_ovl3_8018D060;

typedef struct gmGroundUnkBytes
{
    u8 byte[1];
    
} gmGroundUnkBytes;

typedef struct grMapCollisionRoom
{
    s32 room_id;
    u8 filler_0x4[0x2C - 0x4];

} grMapCollisionRoom;

typedef struct mpDirection
{
    f32 top, bottom, right, left;

} mpDirection;

typedef struct mpEdgeBounds
{
    mpDirection d0, d1, d2, d3;

} mpEdgeBounds;

extern mpEdgeBounds D_ovl2_80131308, gMapEdgeBounds;

typedef struct grMapObject
{
    GObj *ogobj;
    sb32 (*proc_update)(GObj*, GObj*, s32*);

} grMapObject;

typedef struct grMapEnvironment
{
    GObj *egobj;
    sb32 (*proc_update)(GObj*, GObj*, void*, s32*);

} grMapEnvironment;

static grMapObject D_ovl2_80131180[2];
static grMapEnvironment D_ovl2_80131190[1];
static s32 D_ovl2_80131198;
static s32 D_ovl2_8013119C;

typedef struct mpRoomInfo
{
    u8 filler_0x0[0x1C];
    Vec3f dynacoll_pos;
    u8 filler_0x28[0x70 - 0x28];
    void *p_dynacoll;
    u8 filler_0x74[0x84 - 0x74];
    s32 collision_kind;

} mpRoomInfo;

typedef struct mpVertexInfo
{
    u8 room_id;
    u8 line_type;
    s16 coll_pos_next;
    s16 coll_pos_prev;
    s16 edge_psign_id;
    s16 edge_nsign_id;

} mpVertexInfo;

typedef struct mpVertexLinks
{
    u16 vertex1, vertex2;

} mpVertexLinks;

typedef struct mpVertexArray
{
    u16 vertex_id[1];

} mpVertexArray;

typedef struct mpVertexPosition
{
    Vec2h pos;
    u16 vertex_flags;

} mpVertexPosition;

typedef struct mpVertexPosContainer
{
    mpVertexPosition vpos[1];

} mpVertexPosContainer;

typedef struct mpLineData
{
    u16 group_id;
    u16 line_count;    // Number of lines with collision type? e.g. there are 4 ground lines on Saffron City in the main group

} mpLineData;

typedef struct mpLineInfo
{
    u16 room_id; // Group that this line
    mpLineData line_data[4];
    
} mpLineInfo;

typedef struct mpLineGroup // This is all getting hard to wrap one's head around, but this is basically a group of line types (ground, ceil, rwall, lwall)
{
    u16 line_count, *line_id;

} mpLineGroup;

typedef struct mpGeometryInfo // 0x80131368
{
    u16 room_count;
    void *vertex_data;
    void *vertex_id;
    void *vertex_links;
    mpLineInfo *line_info;
    u16 unk_mpgeo_count;
    void *vectors;

} mpGeometryInfo;

typedef struct mpVertexInfoContainer
{
    mpVertexInfo vertex_info[1];

} mpVertexInfoContainer;

typedef struct mpVertexLinksContainer
{
    mpVertexLinks vertex_links[1];

} mpVertexLinksContainer;

typedef struct mpRoomDObj
{
    DObj *room_dobj[1];

} mpRoomDObj;

typedef struct mpUnkVectorData
{
    u16 mpvector_id;
    Vec2h pos;

} mpUnkVectorData;

typedef struct mpUnkVectorContainer
{
    mpUnkVectorData vector_data[1];

} mpUnkVectorContainer;

typedef struct mpRoomVectorContainer
{
    Vec3f vectors[1];

} mpRoomVectorContainer;

typedef struct grCollisionRoom
{
    s32 room_id;
    u8 filler_0x4[0x2C - 0x4];

} grCollisionRoom;  

typedef enum mpLineType
{
    mpCollision_LineType_Ground,
    mpCollision_LineType_Ceil,
    mpCollision_LineType_RWall,
    mpCollision_LineType_LWall,
    mpCollision_LineType_EnumMax

} mpLineType;

typedef enum mpYakumonoStatus
{
    mpCollision_Yakumono_None,
    mpCollision_Yakumono_On,
    mpCollision_Yakumono_Unk,
    mpCollision_Yakumono_Off

} mpYakumonoStatus;

mpEdgeBounds gMapEdgeBounds;
mpRoomDObj *gMapRooms;
mpLineGroup gMapLineTypeGroups[mpCollision_LineType_EnumMax];
mpGeometryInfo *gpMapGeometry;
mpVertexInfoContainer *gpMapVertexInfo;
mpVertexArray *gpMapVertexID;
mpVertexLinks *gpMapVertexLinks;   //
mpVertexPosContainer *gpMapVertexData; // Vertex positions
Vec3f *gpMapDynamicCollisions;
mpUnkVectorContainer *D_ovl2_80131380;
s32 gMapLineCount;
GfxColorAlpha gMapLightColor;
s32 gMapRoomCount;
f32 gMapLightAngleX;
f32 gMapLightAngleY;
u16 D_ovl2_80131398;

typedef struct grFileInfo
{
    intptr_t size, offset;

} grFileInfo;

typedef struct grCreateDesc
{
    DObjDesc *dobj_desc;
    void *anim_joint;
    void *aobj;
    void *matanim_joint;

} grCreateDesc;

typedef struct gmGroundInfo
{
    grCreateDesc gr_desc[4];
    mpGeometryInfo *map_geometry;
    u8 unk_0x44;
    void *unk_0x48;
    GfxColorAlpha fog_color;
    GfxColor emblem_colors[4];
    s32 unk_grinfo_0x5C;
    Vec3f light_angle;
    s16 cam_bound_top;
    s16 cam_bound_bottom;
    s16 cam_bound_right;
    s16 cam_bound_left;
    s16 blastzone_top;
    s16 blastzone_bottom;
    s16 blastzone_right;
    s16 blastzone_left;
    u32 music_id;
    void *map_nodes;
    gmGroundUnkBytes *unk_0x84;
    s16 unk_groundinfo_0x88;
    s16 unk_groundinfo_0x8A;
    s16 unk_groundinfo_0x8C;
    s16 unk_groundinfo_0x8E;
    s16 unk_groundinfo_0x90;
    s16 unk_bound_top;
    s16 unk_bound_bottom;
    s16 unk_bound_right;
    s16 unk_bound_left;
    Vec3h unk_groundinfo_0x9A;
    Vec3h unk_groundinfo_0xA0;

} gmGroundInfo;

static gmGroundInfo* Ground_Info, *gGroundInfo;

typedef struct _ObjectColl
{
    f32 top;
    f32 center;
    f32 bottom;
    f32 width;

} ObjectColl;

typedef enum mpMaterial
{
    mpCollision_Material_0,
    mpCollision_Material_1,
    mpCollision_Material_2,
    mpCollision_Material_3,
    mpCollision_Material_4,
    mpCollision_Material_5,
    mpCollision_Material_6,
    mpCollision_Material_FireWeakHz1,
    mpCollision_Material_FireStrongVt1,
    mpCollision_Material_FireWeakVt1,
    mpCollision_Material_SpikeStrongHz1,
    mpCollision_Material_FireWeakVt2,
    mpCollision_Material_DokanLeft,
    mpCollision_Material_DokanRight,
    mpCollision_Material_Detect, // Board the Platforms / Race to the Finish gate / Saffron City gate
    mpCollision_Material_FireWeakVt3,
    mpCollision_Material_Custom

} mpMaterial;

typedef struct _Coll_Data
{    
    Vec3f *p_translate;
    s32 *p_lr;
    Vec3f pos_curr;
    Vec3f pos_prev; // 0x8C
    Vec3f pos_correct; // 0x94 - 0xA0;
    Vec3f pos_push; // Wind speed
    ObjectColl object_coll;
    ObjectColl *p_object_coll; // Points back to collision box???
    Vec2f cliffcatch_coll;
    u16 coll_mask_prev;
    u16 coll_mask;
    u16 unk_0x58;
    u16 coll_type; // "Flag that relates to type of clipping?"
    u16 wall_flag; // "Flag is enabled if moving into a wall"
    u16 unk_0x5E;
    s32 unk_0x60;
    sb32 unk_0x64;
    Vec3f ground_to_air_pos_last;

    s32 ground_line_id;
    f32 ground_dist; // "Clipping / Platform ID directly under character"
    u32 ground_flags; // "Distance of platform directly under character"        u32 ground_flag; // "Clipping flag of platform directly under character"
    Vec3f ground_angle;

    s32 ceil_line_id; // Clipping ID of last ceiling interacted with
    u32 ceil_flags;
    Vec3f ceil_angle;

    s32 rwall_line_id; // Clipping ID of last right wall interacted with
    u32 rwall_flags;
    Vec3f rwall_angle;

    s32 lwall_line_id;
    u32 lwall_flags;
    Vec3f lwall_angle;

    // Most of this is unconfirmed

    s32 cliff_id;
    s32 ignore_line_id; // Might be the same as 0x19C from Melee?

} Coll_Data;

typedef struct caScript
{
    u32 *p_script; // Pointer to Color Animation script?
    u16 color_event_timer;
    u16 script_index;
    void *p_subroutine[1];
    s32 loop_count[1];
    void *p_goto[2];
    s32 unk_ca_timer;

} caScript;

typedef struct caColorInfo
{
    u8 r, g, b, a;
    s16 ir, ig, ib, ia; // Interpolation step

} caColorInfo;

typedef struct caStruct
{
    caScript cs[2];
    s32 duration;
    s32 colanim_id;
    caColorInfo maincolor;
    f32 light_angle1;
    f32 light_angle2;
    caColorInfo blendcolor;
    u8 is_use_maincolor : 1;
    u8 is_use_light : 1;
    u8 is_use_blendcolor : 1;
    u8 unk_ca_0x60_b34 : 2;

} caStruct;

typedef struct ColAnimDesc
{
    void *p_script;
    u8 unk_colanimdesc_0x4;
    u8 unk_colanimdesc_0x5;
    
} ColAnimDesc;

sb32 caCheckSetColAnimIndex(caStruct*, s32, s32);
s32 caMain_UpdateColAnim(caStruct*, GObj*, s32, s32);     /* extern */
void caResetColAnim(caStruct*);                        /* extern */
caStruct D_ovl2_80131A40;
u8 D_ovl2_80131AA4;

typedef struct ftSpecialHit
{
    s32 hit_type;
    s32 joint_index;
    Vec3f offset;
    Vec3f size;
    s32 damage_resist;

} ftSpecialHit;

typedef enum ftHitUpdateState
{
    ftHit_UpdateState_Disable,
    ftHit_UpdateState_New,
    ftHit_UpdateState_2,
    ftHit_UpdateState_3

} ftHitUpdateState;

typedef struct gmHitCollisionFlags
{
    u32 is_interact_hurt : 1;
    u32 is_interact_shield : 1;
    u32 is_interact_reflect : 1;
    u32 is_interact_absorb : 1;
    u32 interact_mask : 3;
    u32 timer_rehit : 6;

} gmHitCollisionFlags;

typedef struct ftHitboxArray
{
    GObj *victim_gobj;
    gmHitCollisionFlags victim_flags;

} ftHitboxArray;

typedef struct ftThrowHitDesc
{
    s32 status_id;
    s32 damage;
    s32 angle;
    s32 knockback_scale;
    s32 knockback_weight;
    s32 knockback_base;
    s32 element;

} ftThrowHitDesc;

typedef struct ftThrowReleaseDesc
{
    s32 angle;
    s32 knockback_scale;
    s32 knockback_weight;
    s32 knockback_base;

} ftThrowReleaseDesc;

typedef union gmStatFlags
{
    struct
    {
        u16 flags_0x8000 : 1;
        u16 flags_0x4000 : 1;
        u16 flags_0x2000 : 1;
        u16 is_smash_attack : 1;
        u16 is_ground_or_air : 1;
        u16 is_special_attack : 1;
        u16 attack_group_id : 10;
    };
    u16 halfword;

} gmStatFlags;

typedef struct gmDoubleFlags
{
    gmStatFlags hi;
    gmStatFlags lo;

} gmDoubleFlags;

typedef struct ftHitMatrix
{
    sb32 unk_fthitmtx_0x0;
    Mtx44f mtx;
    f32 unk_fthitmtx_0x44;

} ftHitMatrix;

typedef struct _ftHitbox
{
    gmHitCollisionUpdateState update_state;
    u32 interact_mask;
    s32 joint_index;
    s32 damage;
    gmHitCollisionElement element;
    DObj *joint;
    Vec3f offset;
    f32 size;
    s32 angle;
    s32 knockback_scale;
    s32 knockback_weight;
    s32 knockback_base;
    s32 shield_damage;
    u32 sfx_level : 3;
    u32 sfx_kind : 4;
    u32 is_hit_air : 1;
    u32 is_hit_ground : 1;
    u32 clang : 1;
    u32 is_itemswing : 1;
    u32 attack_id : 6;
    u16 motion_count;
    u16 stat_count;
    Vec3f pos;
    Vec3f pos_prev;
    ftHitboxArray hit_targets[4];
    ftHitMatrix hit_matrix;

} ftHitbox;

typedef struct WeirdBits
{
    u16 flags_0x4C_b012 : 3;
    u16 flags_0x4C_b3 : 1;
    u16 flags_0x4C_b4 : 1;
    u16 flags_0x4C_b5 : 1;
    u16 flags_0x4C_10bit : 10;

} WeirdBits;

typedef struct ItemFireballAttributes
{
    s32 lifetime;
    f32 fall_speed_max;
    f32 collide_damage; // Item loses this much health when colliding with an obstruction
    f32 gravity;
    f32 collide_vel;
    f32 rotate_speed;
    f32 vel_ground;
    f32 vel_air;
    f32 vel_mul;
    void *p_item;
    int offset_it_hit;
    f32 frame_begin;

} ItemFireballAttributes;

typedef struct ItemChargeShotAttributes
{
    f32 gfx_size;
    f32 vel_x;
    s32 damage;
    s32 hit_size;
    s32 coll_size;
    u32 shoot_sfx_id;
    u32 charge_sfx_id;
    u32 hit_sfx_id;
    s32 shield_damage;
 
} ItemChargeShotAttributes;

typedef struct wpCreateDesc
{
    u8 unk_0x0;
    s32 it_kind;
    void **p_item;
    int offset_it_hit;
    u8 unk_0x10;
    u8 unk_0x11;
    u8 unk_0x12;
    u8 unk_0x13;
    sb32 (*proc_update)(GObj*);
    sb32 (*proc_map)(GObj*);
    sb32 (*proc_hit)(GObj*);
    sb32 (*proc_shield)(GObj*);
    sb32 (*proc_hop)(GObj*);
    sb32 (*proc_setoff)(GObj*);
    sb32 (*proc_reflector)(GObj*);
    sb32 (*proc_absorb)(GObj*);
        
} wpCreateDesc;

typedef struct ItemHitDesc // Moreso hitbox stuff
{
    void *unk_0x0;
    void *unk_0x4;
    void *unk_0x8;
    void *unk_0xC;
    Vec3h offset[2];
    s16 objectcoll_top;
    s16 objectcoll_center;
    s16 objectcoll_bottom;
    s16 objectcoll_width;
    u16 size;
    s32 angle : 10;
    u32 knockback_scale : 10U;
    u32 damage : 8U;
    u32 element : 4U;
    u32 knockback_weight : 10U;
    s32 shield_damage : 8U;
    u32 hitbox_count : 2U;
    u32 clang : 1U;
    u32 sfx : 10U;
    u32 priority : 3U;
    u32 flags_0x2F_b0 : 1U;
    u32 flags_0x2F_b1 : 1U;
    u32 can_deflect : 1U;
    u32 can_reflect : 1U;
    u32 can_absorb : 1U;
    u32 can_shield : 1U;
    u32 flags_0x2F_b6 : 1U;
    u32 flags_0x2F_b7 : 1U;
    u32 knockback_base : 10U;

} ItemHitDesc;

typedef struct ItemHitUnk
{
    Vec3f pos;
    Vec3f pos_prev;
    s32 unk_0x18;
    u8 filler_0x1C[0x5C - 0x1C];
    f32 unk_0x5C;

} ItemHitUnk;

typedef struct AttackDescFlagsLw
{
    u16 flags_lw_filler : 6;
    u16 flags_0x3FF : 10;

} AttackDescFlagsLw;

typedef struct FighterAttackFlags
{
    gmStatFlags hi;
    gmStatFlags lw; 

} FighterAttackFlags; 

typedef struct _ItemHitArray
{
    GObj *victim_gobj;
    gmHitCollisionFlags victim_flags;

} ItemHitArray;

typedef struct ItemHitStatusFlags
{
    u8 flags_filler : 6;
    u8 flags_update : 2;

} ItemHitStatusFlags;

typedef struct wpHitPositions
{
    Vec3f pos;
    Vec3f pos_prev;
    sb32 unk_wphitpos_0x18;
    Mtx44f mtx;
    f32 unk_wphitpos_0x5C;

} wpHitPositions;

typedef struct _wpHitbox
{
    gmHitCollisionUpdateState update_state; // 0 = disabled, 1 = new hitbox, 2 and 3 = interpolate/copy current position to previous
    s32 damage; // 0x4
    f32 stale; // Multiplies damage
    gmHitCollisionElement element; // 0xC // Placed AFTER offset?
    Vec3f offset[2]; // 0x10 - 0x24   
    f32 size;
    s32 angle;
    u32 knockback_scale; // Unconfirmed
    u32 knockback_weight; // Weight-Dependent Set Knockback
    u32 knockback_base; // Base knockback
    s32 shield_damage;
    s32 priority; // Used to determine winner in item hitbox vs item hitbox interaction?
    u8 interact_mask; // Mask of object classes hitbox can interact with; 0x1 = fighters, 0x2 = items, 0x4 = articles
    u16 hit_sfx;

    u32 clang : 1;
    u32 flags_0x48_b1 : 1;
    u32 flags_0x48_b2 : 1;
    u32 flags_0x48_b3 : 1;
    u32 can_deflect : 1; // Actually determines whether item's shield deflect routine can run?
    u32 can_reflect : 1;
    u32 can_absorb : 1;
    u32 flags_0x48_b7 : 1;
    u32 can_shield : 1;
    u32 attack_id : 6;
    u32 flags_0x49_b7 : 1;
    u16 motion_count;
    gmStatFlags stat_flags;
    u16 stat_count;

    s32 hitbox_count;
    wpHitPositions hit_positions[2];
    ItemHitArray hit_targets[4];

} wpHitbox;

typedef struct itHitPositions
{
    Vec3f pos;
    Vec3f pos_prev;
    sb32 unk_ithitpos_0x18;
    Mtx44f mtx;
    f32 unk_ithitpos_0x5C;

} itHitPositions;

typedef struct _ArticleHitArray
{
    GObj *victim_gobj;
    gmHitCollisionFlags victim_flags;

} ArticleHitArray;

typedef struct _itHitbox
{
    gmHitCollisionUpdateState update_state; // 0x0 
    s32 damage; // 0x4
    f32 stale; // Might be damage in float? At least based on Melee?
    f32 throw_mul; // Multiplies damage on throw?
    gmHitCollisionElement element; // 0xC // Placed AFTER offset?
    Vec3f offset[2]; // 0x10 - 0x18    
    f32 size;
    s32 angle;
    u32 knockback_scale; // Unconfirmed
    u32 knockback_weight; // Weight-Dependent Set Knockback
    u32 knockback_base; // Base knockback
    s32 shield_damage; // Shield damage?
    s32 priority; // Priority?
    u8 interact_mask; // Mask of object classes hitbox can interact with; 0x1 = fighters, 0x2 = items, 0x4 = articles
    u16 hit_sfx;
    u32 rebound : 1;                    // Item's hitbox can collide with other hitboxes
    u32 can_rehit_item : 1;             // Item can rehit item after default rehit cooldown expires
    u32 can_rehit_fighter : 1;          // Item can rehit fighter after default rehit cooldown expires
    u32 can_rehit_shield : 1;           // Item can rehit shield after default rehit cooldown expires
    u32 can_hop : 1;                    // Item can bounce off shields
    u32 can_reflect : 1;                // Item can be reflected
    u32 can_shield : 1;                 // Item can be shielded
    u32 attack_id : 6;                  // Attack ID copied from object that spawned this item
    u16 motion_count;
    gmStatFlags stat_flags;
    u16 stat_count;
    s32 hitbox_count;
    itHitPositions hit_positions[2];
    ArticleHitArray hit_targets[4];

} itHitbox;

typedef struct ArticleFileData
{
    f32 spawn_vel_y[20];

} ArticleFileData;

typedef struct ArticleHitEvent // Hitbox subaction event?
{
    u8 timer;
    s32 angle : 10;
    u32 damage : 8;
    u16 size;

} ArticleHitEvent;

typedef struct ArticleHitDesc
{
    u8 timer;
    s32 angle : 10;
    u32 damage : 8;
    u16 size;
    u32 knockback_scale;
    u32 knockback_weight;
    u32 knockback_base;
    s32 element;
    u32 clang : 1;
    s32 shield_damage;
    u16 hit_sfx;

} ArticleHitDesc;

typedef struct ArticleSpawnData
{
    s32 at_kind;
    ArticleFileData **p_file;
    intptr_t offset;
    u8 unk_aspd_0xC;
    u8 unk_aspd_0xD;
    u8 unk_aspd_0xE;
    s32 update_state;
    sb32 (*proc_update)(GObj*);
    sb32 (*proc_map)(GObj*);
    sb32 (*proc_hit)(GObj*);
    sb32 (*proc_shield)(GObj*);
    sb32 (*proc_hop)(GObj*);
    sb32 (*proc_setoff)(GObj*);
    sb32 (*proc_reflector)(GObj*);
    sb32 (*proc_damage)(GObj*);

} ArticleSpawnData;

typedef struct Fireball_ItemVars
{
    s32 index;

} Fireball_ItemVars;

typedef struct SamusBomb_ItemVars
{
    s32 bomb_blink_timer;

} SamusBomb_ItemVars;

typedef struct ThunderJolt_ItemVars
{
    s32 coll_type;
    Vec3f rotate;
    
} ThunderJolt_ItemVars;

typedef struct Thunder_ItemVars
{
    s32 thunder_state;

} Thunder_ItemVars;

typedef struct _pkthunder_ItemVars
{
    s32 status;
    f32 angle;
    GObj *spawn_gobj; // Original owner?
    GObj *trail_gobj[5];

} pkthunder_ItemVars;

typedef struct _pkthunder_Trail_ItemVars
{
    s32 status;
    s32 trail_index;
    GObj *spawn_gobj; // Original owner?
    GObj *head_gobj;

} pkthunder_Trail_ItemVars;

typedef struct Charge_Shot_ItemVars
{
    sb32 is_release;
    sb32 is_full_charge;
    s32 charge_size;
    GObj *owner_gobj;
    
} Charge_Shot_ItemVars;

typedef struct Spin_Attack_ItemVars
{    
    s16 pos_x[4];
    s16 pos_y[4];
    Vec2f vel;
    s8 is_destroy;
    s8 pos_index;

} Spin_Attack_ItemVars;

typedef struct Boomerang_ItemVars
{
    GObj *spawn_gobj;
    u8 unk_0x4;
    u8 homing_delay;
    u8 flags;
    u8 adjust_angle_delay;
    f32 unk_0x8;
    f32 homing_angle;

} Boomerang_ItemVars;

typedef struct Egg_Throw_ItemVars
{
    s8 is_spin;
    s8 is_throw;
    s8 stick_range;
    s8 lr;
    s16 throw_force;
    f32 angle;

} Egg_Throw_ItemVars;

typedef struct Star_ItemVars // Star Rod projectile
{
    s32 lifetime;

} Star_ItemVars;

typedef struct ftNess_FighterVars
{
    sb32 is_thunder_exist;        // Bool to check if PK Thunder exists
    s32 pkthunder_trail_id;
    s16 pkthunder_trail_x[12];
    s16 pkthunder_trail_y[12];

} ftNess_FighterVars;

typedef struct ftNess_SpecialHi_StatusVars
{
    s32 pk_jibaku_delay;            // Frames before PK Thunder Blast can be initiated (PK Thunder will go through Ness while this timer is greater than 0)
    s32 pkthunder_end_delay;       // Frames before PK Thunder transitions to its ending animation after the projectile despawns 
    s32 pkthunder_gravity_delay;   // Frames before Ness is affected by gravity while performing PK Thunder
    GObj *pkthunder_gobj;          // Pointer to the PK Thunder object
    s32 pk_jibaku_anim_length;      // Number of frames PK Thunder Blast will loop
    f32 pk_jibaku_vel;              // Velocity of PK Thunder Blast (converted to 2D vector with sin(vel) and cos(vel))
    Vec3f pkthunder_vel;           // Might be PK Thunder's collision detection when checking if Ness is hitting himself with it?

} ftNess_SpecialHi_StatusVars;

typedef struct ftNess_SpecialLw_StatusVars
{
    s32 release_lag;                // Frames PSI Magnet automatically stays in the hold animation after initiating the move
    sb32 is_release;              // Bool to check if PSI Magnet should be dropped (alas the B button is no longer being held)
    s32 gravity_delay;              // Frames before Ness is affected by gravity after initiating PSI Magnet

} ftNess_SpecialLw_StatusVars;

typedef union ftNess_StatusVars
{
    ftNess_SpecialHi_StatusVars specialhi;
    ftNess_SpecialLw_StatusVars speciallw;

} ftNess_StatusVars;

typedef struct ftMario_FighterVars
{

    sb32 is_tornado_charge;

} ftMario_FighterVars;

typedef struct ftMario_SpecialHi_StatusVars
{
    sb32 x0;

} ftMario_SpecialHi_StatusVars;

typedef struct ftMario_SpecialLw_StatusVars
{

    f32 x0;
    s32 x4;

} ftMario_SpecialLw_StatusVars;

typedef union ftMario_StatusVars
{

    ftMario_SpecialHi_StatusVars specialhi;
    ftMario_SpecialLw_StatusVars speciallw;

} ftMario_StatusVars;

typedef struct ftDonkey_FighterVars
{
    s32 charge_level;

} ftDonkey_FighterVars;

typedef struct ftDonkey_SpecialN_StatusVars
{
    sb32 is_release;
    s32 charge_level;
    sb32 is_charging;
    sb32 is_cancel;

} ftDonkey_SpecialN_StatusVars;

typedef struct ftDonkey_SpecialLw_StatusVars
{
    sb32 is_loop;

} ftDonkey_SpecialLw_StatusVars;

typedef union ftDonkey_StatusVars
{
    ftDonkey_SpecialN_StatusVars specialn;
    ftDonkey_SpecialLw_StatusVars speciallw;

} ftDonkey_StatusVars;

typedef struct ftFox_SpecialHi_StatusVars
{
    s32 launch_delay;
    s32 x4;
    f32 x8;
    s32 travel_time;
    s32 x10;
    s32 x14;

} ftFox_SpecialHi_StatusVars;

typedef struct ftFox_SpecialLw_StartusVars
{
    s32 x0;
    s32 x4;
    s32 x8;

} ftFox_SpecialLw_StatusVars;

typedef union ftFox_StatusVars
{
    ftFox_SpecialHi_StatusVars specialhi;
    ftFox_SpecialLw_StatusVars speciallw;

} ftFox_StatusVars;

typedef struct ftSamus_FighterVars
{
    s32 charge_level;
    s32 charge_recoil;

} ftSamus_FighterVars;

typedef struct ftSamus_SpecialN_StatusVars
{
    sb32 is_release;
    s32 charge_int;
    GObj *charge_gobj;
    
} ftSamus_SpecialN_StatusVars;

typedef union ftSamus_StatusVars
{
    ftSamus_SpecialN_StatusVars specialn;

} ftSamus_StatusVars;

typedef struct ftYoshi_SpecialN_StatusVars
{
    u32 unk_0x0;
    u16 unk_0x4;

} ftYoshi_SpecialN_StatusVars;

typedef struct ftYoshi_SpecialHi_StatusVars
{
    GObj *egg_gobj;
    s16 throw_force;

} ftYoshi_SpecialHi_StatusVars;

typedef union ftYoshi_StatusVars
{
    ftYoshi_SpecialN_StatusVars specialn;
    ftYoshi_SpecialHi_StatusVars specialhi;

} ftYoshi_StatusVars;

typedef struct ftCaptain_FighterVars
{
    s32 falcon_punch_unk;

} ftCaptain_FighterVars;

typedef struct ftCaptain_SpecialHi_StatusVars
{
    u16 unk_0x0;
    Vec3f vel;

} ftCaptain_SpecialHi_StatusVars;

typedef struct ftCaptain_SpecialLw_StatusVars
{
    u16 scale_apply_timer;
    f32 vel_scale;

} ftCaptain_SpecialLw_StatusVars;

typedef union ftCaptain_StatusVars
{
    ftCaptain_SpecialHi_StatusVars specialhi;
    ftCaptain_SpecialLw_StatusVars speciallw;

} ftCaptain_StatusVars;

typedef struct ftKirby_FighterVars
{
    s32 copy_id;
    s32 copysamus_charge_level;
    s32 copysamus_charge_recoil;
    s32 copydonkey_charge_level;
    s32 copycaptain_falcon_punch_unk;
    s32 copypurin_unk;
    sb32 copy_bool_unk;
    GObj *copylink_boomerang_gobj;

} ftKirby_FighterVars;

typedef struct ftKirby_SpecialN_StatusVars
{    
    s16 copy_id;
    s16 release_lag;
    Vec3f dist;

} ftKirby_SpecialN_StatusVars;

typedef struct ftKirby_SpecialLw_StatusVars
{
    s16 duration;
    s16 unk_0x2;
    s16 colanim_id;

} ftKirby_SpecialLw_StatusVars;

typedef struct ftKirby_CopyDonkey_SpecialN_StatusVars
{
    sb32 is_release;
    s32 charge_level;
    sb32 is_charging;
    sb32 is_cancel;

} ftKirby_CopyDonkey_SpecialN_StatusVars;

typedef struct ftKirby_CopySamus_SpecialN_StatusVars
{
    sb32 is_release;
    s32 charge_int;
    GObj *charge_gobj;

} ftKirby_CopySamus_SpecialN_StatusVars;

typedef struct ftKirby_CopyLink_SpecialN_StatusVars
{
    sb32 is_smash;

} ftKirby_CopyLink_SpecialN_StatusVars;

typedef union ftKirby_StatusVars
{
    ftKirby_SpecialN_StatusVars specialn;
    ftKirby_SpecialLw_StatusVars speciallw;
    ftKirby_CopyDonkey_SpecialN_StatusVars copydonkey_specialn;
    ftKirby_CopySamus_SpecialN_StatusVars copysamus_specialn;
    ftKirby_CopyLink_SpecialN_StatusVars copylink_specialn;
    
} ftKirby_StatusVars;

typedef struct ftKirbyCopyData
{
    u16 copy_id;
    s16 copy_hat_rs;
    f32 effect_scatter; // Random position offset used for blue sparkle effect?
    s32 star_damage;

} ftKirbyCopyData;

typedef struct ftLink_FighterVars
{
    GObj *boomerang_gobj;

} ftLink_FighterVars;

typedef struct ftLink_SpecialN_StatusVars
{
    sb32 is_smash;

} ftLink_SpecialN_StatusVars;

typedef struct ftLink_SpecialHi_StatusVars
{
    GObj *spin_attack_gobj;

} ftLink_SpecialHi_StatusVars;

typedef union ftLink_StatusVars
{
    ftLink_SpecialN_StatusVars specialn;
    ftLink_SpecialHi_StatusVars specialhi;

} ftLink_StatusVars;

typedef struct ftPurin_FighterVars
{    
    u32 unk_0x0;

} ftPurin_FighterVars;

typedef struct ftPikachu_FighterVars
{
    sb32 is_thunder_destroy;

} ftPikachu_FighterVars;

typedef struct ftPikachu_SpecialHi_StatusVars
{
    s32 anim_frames;
    sb32 is_subsequent_zip;
    u32 unk_0x8;
    Vec2i stick_range;
    s32 coll_timer_unk;
    f32 vel_x_bak;
    f32 vel_y_bak;
    f32 vel_ground_bak;

} ftPikachu_SpecialHi_StatusVars;

typedef struct ftPikachu_SpecialLw_StatusVars
{
    GObj *thunder_gobj;

} ftPikachu_SpecialLw_StatusVars;

typedef union ftPikachu_StatusVars
{
    ftPikachu_SpecialHi_StatusVars specialhi;
    ftPikachu_SpecialLw_StatusVars speciallw;
    
} ftPikachu_StatusVars;

typedef struct ftCommon_Dead_StatusVars
{
    s32 rebirth_wait;
    Vec3f pos;

} ftCommon_Dead_StatusVars;

typedef struct ftCommon_Rebirth_StatusVars
{
    Vec3f halo_offset;
    Vec3f pos;
    s32 halo_despawn_wait;
    s32 halo_number;
    s32 halo_lower_wait;

} ftCommon_Rebirth_StatusVars;

typedef struct ftCommon_Sleep_StatusVars
{
    s32 stock_steal_wait;

} ftCommon_Sleep_StatusVars;

typedef struct ftCommon_Entry_StatusVars
{
    s32 entry_timer;
    s32 lr_entry;
    s32 ground_line_id;
    sb32 is_rotate;

} ftCommon_Entry_StatusVars;

typedef struct ftCommon_Turn_StatusVars
{
    sb32 is_allow_turn_direction; // Cannot turn around at all if disabled + horizontal controls are inverted?
    sb32 is_disable_interrupts;
    u16 button_mask;
    s32 lr_dash;
    s32 lr_turn;
    s32 unk_0x14;

} ftCommon_Turn_StatusVars;

typedef struct ftCommon_KneeBend_StatusVars
{
    f32 jump_force;
    f32 anim_frame;
    u32 input_source;
    sb32 is_short_hop;

} ftCommon_KneeBend_StatusVars;

typedef struct ftCommon_JumpAerial_StatusVars
{
    f32 drift;
    f32 vel_x;
    s32 turn_frames;

} ftCommon_JumpAerial_StatusVars;

typedef struct ftCommon_Damage_StatusVars
{
    s32 hitstun_timer;
    s32 dust_gfx_int;
    f32 publicity_knockback;
    u16 coll_mask_curr;
    u16 coll_mask_prev;
    u16 coll_mask_unk;
    Vec3f wall_collide_angle;
    s32 unk_0xB38;
    s32 unk_0xB3C;
    s32 unk_index;
    s32 status_id;
    sb32 is_limit_knockback;

} ftCommon_Damage_StatusVars;

typedef struct ftCommon_Squat_StatusVars
{
    sb32 is_allow_pass;
    s32 pass_wait;
    s32 unk_0x8;

} ftCommon_Squat_StatusVars;

typedef struct ftCommon_Dokan_StatusVars
{
    s32 ground_line_id;
    s32 wall_line_id;
    Vec3f pos_current;
    Vec3f pos_target;
    s32 pos_adjust_wait;
    s32 set_unk_wait;
    s32 turn_stop_wait;

} ftCommon_Dokan_StatusVars;

typedef struct ftCommon_Landing_StatusVars
{
    sb32 is_allow_interrupt;

} ftCommon_Landing_StatusVars;

typedef struct ftCommon_FallSpecial_StatusVars
{
    f32 drift;
    sb32 is_allow_pass;
    sb32 is_goto_landing;
    f32 landing_lag;
    sb32 is_allow_interrupt;
    sb32 is_fall_accelerate;

} ftCommon_FallSpecial_StatusVars;

typedef struct ftCommon_Tornado_StatusVars
{
    s32 release_wait;
    GObj *tornado_gobj;

} ftCommon_Tornado_StatusVars;

typedef struct ftCommon_TaruCann_StatusVars
{
    s32 release_wait;
    s32 shoot_wait;
    GObj *tarucann_gobj;

} ftCommon_TaruCann_StatusVars;

typedef struct ftCommon_DownWait_StatusVars
{
    s32 stand_wait;

} ftCommon_DownWait_StatusVars;

typedef struct ftCommon_DownBounce_StatusVars
{
    s32 attack_buffer;

} ftCommon_DownBounce_StatusVars;

typedef struct ftCommon_Rebound_StatusVars
{
    f32 anim_speed;
    f32 rebound_timer;

} ftCommon_Rebound_StatusVars;

typedef struct ftCommon_CliffWait_StatusVars
{
    s32 status_id;
    s32 fall_wait;

} ftCommon_CliffWait_StatusVars;

typedef struct ftCommon_CliffMotion_StatusVars
{
    s32 status_id;
    s32 cliff_id;

} ftCommon_CliffMotion_StatusVars;

typedef struct ftCommon_Lift_StatusVars
{
    s32 turn_frames;

} ftCommon_Lift_StatusVars;

typedef struct ftCommon_ItemThrow_StatusVars
{
    s32 turn_rotate_step;
    s32 turn_frames;
    s32 turn_invert_lr_wait;
    f32 throw_vel;
    s32 throw_angle;
    f32 throw_damage;
    Vec2f unk;
    s32 get_heavy_wait;

} ftCommon_ItemThrow_StatusVars;

typedef struct ftCommon_ItemSwing_StatusVars
{
    s32 harisen_scale_reset_wait;

} ftCommon_ItemSwing_StatusVars;

typedef struct ftCommon_FireFlower_StatusVars
{
    s32 flame_vel_index;
    s32 ammo_sub;
    s32 gfx_spawn_int;
    s32 ammo_fire_count;
    sb32 is_release;
    s32 release_lag;

} ftCommon_FireFlower_StatusVars;

typedef struct ftCommon_Hammer_StatusVars
{
    union
    {
        f32 landing_lag;
        f32 jump_force;
    };

    f32 kneebend_anim_frame;
    s32 input_source;
    sb32 is_short_hop;

} ftCommon_Hammer_StatusVars;

typedef struct ftCommon_Guard_StatusVars
{
    s32 release_lag;
    s32 shield_decay_wait;
    GObj *effect_gobj;
    sb32 is_release;
    s32 angle_i;
    f32 angle_f;
    f32 shield_rotate_range;
    f32 setoff_frames;
    s32 slide_frames;
    sb32 is_setoff;

} ftCommon_Guard_StatusVars;

typedef struct ftCommon_Escape_StatusVars
{
    s32 unk_0x0;

} ftCommon_Escape_StatusVars;

typedef struct ftCommon_Catch_StatusVars
{
    f32 catch_pull_frame_begin; // ???
    f32 catch_pull_anim_frames; // Time it takes to retract grabbed fighter
    u8 filler_0x8[0xB3C - 0xB20];
    u32 unk_0x24;

} ftCommon_Catch_StatusVars;

typedef struct ftCommon_Capture_StatusVars
{
    sb32 is_goto_pulled_wait;

} ftCommon_Capture_StatusVars;

typedef struct ftCommon_CatchWait_StatusVars
{
    s32 throw_wait;

} ftCommon_CatchWait_StatusVars;

typedef struct ftCommon_CaptureKirby_StatusVars
{
    s16 is_goto_capturewait;
    s16 lr;
    s16 is_kirby;

} ftCommon_CaptureKirby_StatusVars;

typedef struct ftCommon_CaptureYoshi_StatusVars
{
    GObj *effect_gobj;
    s16 stage;
    s16 breakout_wait;
    s8 lr;
    s8 unk_0x9;

} ftCommon_CaptureYoshi_StatusVars;

typedef struct ftCommon_CaptureCaptain_StatusVars
{
    u16 capture_flag;

} ftCommon_CaptureCaptain_StatusVars;

typedef struct ftCommon_ThrowF_StatusVars // Cargo Throw
{
    union
    {
        f32 landing_anim_frame;
        f32 jump_force;
    };
    f32 kneebend_anim_frame;
    s32 input_source;
    sb32 is_short_hop;

} ftCommon_ThrowF_StatusVars;

typedef struct ftCommon_ThrowFF_StatusVars
{
    sb32 is_turn; // Used to tell if Donkey Kong is doing "Cargo Back Throw" (this is still just Forward Throw but he turns around first)
    s32 turn_frames;

} ftCommon_ThrowFF_StatusVars;

typedef struct ftCommon_ThrowFDamage_StatusVars
{
    s32 hitstun_timer;
    s32 dust_gfx_int;
    f32 publicity_knockback;
    u16 coll_flags;
    u8 filler_0xC[0x28 - 0xE];
    s32 unk_index;
    s32 status_id;
    sb32 is_limit_knockback;

} ftCommon_ThrowFDamage_StatusVars;

typedef struct ftCommon_Attack1_StatusVars
{
    sb32 is_goto_followup;
    s32 interrupt_catch_timer;

} ftCommon_Attack1_StatusVars;

typedef struct ftCommon_Attack100_StatusVars
{
    sb32 is_anim_end;
    sb32 is_goto_loop;

} ftCommon_Attack100_StatusVars;

typedef struct ftCommon_AttackLw3_StatusVars
{
    sb32 is_goto_attacklw3;

} ftCommon_AttackLw3_StatusVars;

typedef struct ftCommon_Attack4_StatusVars
{
    s32 gfx_id;
    s32 filler_0x4;
    sb32 is_goto_attacklw4;
    s32 unk_0xC;
    s32 lr;

} ftCommon_Attack4_StatusVars;

typedef struct ftCommon_AttackAir_StatusVars
{
    s32 rehit_timer;

} ftCommon_AttackAir_StatusVars;

typedef union ftCommon_StatusVars
{
    ftCommon_Dead_StatusVars dead;    
    ftCommon_Rebirth_StatusVars rebirth;
    ftCommon_Sleep_StatusVars sleep;
    ftCommon_Entry_StatusVars entry;
    ftCommon_Turn_StatusVars turn;
    ftCommon_KneeBend_StatusVars kneebend;
    ftCommon_JumpAerial_StatusVars jumpaerial;
    ftCommon_Damage_StatusVars damage;
    ftCommon_Squat_StatusVars squat;
    ftCommon_Dokan_StatusVars dokan;
    ftCommon_Landing_StatusVars landing;
    ftCommon_FallSpecial_StatusVars fallspecial;
    ftCommon_Tornado_StatusVars tornado;
    ftCommon_TaruCann_StatusVars tarucann;
    ftCommon_DownWait_StatusVars downwait;
    ftCommon_DownBounce_StatusVars downbounce;
    ftCommon_Rebound_StatusVars rebound;
    ftCommon_CliffWait_StatusVars cliffwait;
    ftCommon_CliffMotion_StatusVars cliffmotion;
    ftCommon_Lift_StatusVars lift;
    ftCommon_ItemThrow_StatusVars itemthrow;
    ftCommon_ItemSwing_StatusVars itemswing;
    ftCommon_FireFlower_StatusVars fireflower;
    ftCommon_Hammer_StatusVars hammer;
    ftCommon_Guard_StatusVars guard;
    ftCommon_Escape_StatusVars escape;
    ftCommon_Catch_StatusVars catchmain;
    ftCommon_CatchWait_StatusVars catchwait;
    ftCommon_Capture_StatusVars capture;
    ftCommon_CaptureKirby_StatusVars capturekirby;
    ftCommon_CaptureYoshi_StatusVars captureyoshi;
    ftCommon_CaptureCaptain_StatusVars capturecaptain;
    ftCommon_ThrowF_StatusVars throwf;
    ftCommon_ThrowFF_StatusVars throwff;
    ftCommon_ThrowFDamage_StatusVars throwfdamage;
    ftCommon_Attack1_StatusVars attack1;
    ftCommon_Attack100_StatusVars attack100;
    ftCommon_AttackLw3_StatusVars attacklw3;
    ftCommon_Attack4_StatusVars attack4;
    ftCommon_AttackAir_StatusVars attackair;

} ftCommon_StatusVars;

typedef struct MasterHand_Struct
{
    GObj *target_gobj; // GObj pointer?
    s32 unk_0x4;
    s32 unk_0x8;
    f32 unk_0xC;
    u32 wait_timer; // Wait this many frames until next attack
    s8 unk_0x14;
    s8 unk_0x15;
    u8 unk_0x16;
    u8 unk_0x17;

} MasterHand_Struct;

typedef struct ftMasterHand_FighterVars
{
    MasterHand_Struct *p_masterhand;
    MasterHand_Struct s;

} ftMasterHand_FighterVars;

typedef struct ftMasterHand_Wait_StatusVars
{
    Vec3f pos;

} ftMasterHand_Wait_StatusVars;

typedef struct ftMasterHand_Move_StatusVars
{
    void (*cb)(GObj*);
    Vec3f vel;
    f32 magnitude;

} ftMasterHand_Move_StatusVars;

typedef struct ftMasterHand_Okhuikouki_StatusVars
{
    Vec3f pos;

} ftMasterHand_Okuhikouki_StatusVars;

typedef struct ftMasterHand_Gootsubu_StatusVars
{
    s16 wait_timer;
    f32 pos_x1;
    f32 pos_x2;

} ftMasterHand_Gootsubu_StatusVars;

typedef struct ftMasterHand_Drill_StatusVars
{
    s16 follow_timer; // Follow player for this many frames?
    f32 pos_x1;
    f32 pos_x2;

} ftMasterHand_Drill_StatusVars;

typedef struct ftMasterHand_Yubideppou_StatusVars
{
    s16 wait_timer;
    s16 bullet_count;
    u8 shoot_timer;

} ftMasterHand_Yubideppou_StatusVars;

typedef struct ftMasterHand_Okupunch_StatusVars
{
    Vec3f pos;

} ftMasterHand_Okupunch_StatusVars;

typedef struct ftMasterHand_Okutsubushi_StatusVars
{
    Vec3f pos;
    u16 wait_timer;

} ftMasterHand_Okutsubushi_StatusVars;

typedef struct ftMasterHand_Dead_StatusVars
{
    s16 dead_timer;

} ftMasterHand_Dead_StatusVars;

typedef union ftMasterHand_StatusVars
{
    ftMasterHand_Wait_StatusVars wait;
    ftMasterHand_Move_StatusVars move;
    ftMasterHand_Okuhikouki_StatusVars okuhikouki;
    ftMasterHand_Gootsubu_StatusVars gootsubu;
    ftMasterHand_Drill_StatusVars drill;
    ftMasterHand_Yubideppou_StatusVars yubideppou;
    ftMasterHand_Okupunch_StatusVars okupunch;
    ftMasterHand_Okutsubushi_StatusVars okutsubushi;
    ftMasterHand_Dead_StatusVars dead;

} ftMasterHand_StatusVars;

typedef struct ftUnkFlag_0x28E_Bit
{
    u16 x28C_halfword;
    u16 x28E_flag_4bit : 4;
    u16 x28E_flag_0x8 : 1;

} ftUnkFlag_0x28E_Bit;

typedef struct ftUnkFlag_0x28E_Byte
{
    u8 x28C_byte;
    u8 x28E_flag_4bit : 4;
    u8 x28E_byte;

} ftUnkFlag_0x28E_Byte;

typedef struct ftUnkFlag_0x28E_Halfword
{
    u16 x28C_halfword;
    u16 x28E_halfword;

} ftUnkFlag_0x28E_Halfword;

typedef union ftUnkFlagUnion
{
    ftUnkFlag_0x28E_Bit bit;
    ftUnkFlag_0x28E_Byte byte;
    ftUnkFlag_0x28E_Halfword halfword;

} ftUnkFlagUnion;

typedef struct UnkDObjDesc
{
    u32 filler[3];
    u8 something;

} UnkDObjDesc;

typedef struct DObjDescArray
{
    DObjDesc *dobj_desc;
    DObjDesc **d2;
    DObjDesc **d3;
    u8 unk_dobjcontain_0xC;

} DObjDescArray;

typedef struct DObjDescContainer
{
    DObjDescArray dobj_desc_array[2];

} DObjDescContainer;

typedef struct ftItemPickup
{
    Vec2f pickup_offset_light;
    Vec2f pickup_range_light;
    Vec2f pickup_offset_heavy;
    Vec2f pickup_range_heavy;

} ftItemPickup;

typedef struct ftThrownStatus
{
    s32 status1, status2;

} ftThrownStatus;

typedef struct ftThrownStatusArray
{
    ftThrownStatus ft_thrown[2];

} ftThrownStatusArray;

typedef struct UnkFighterDObjData
{
    s32 joint_index;
    void *unk_ftdobj_0x4;
    s32 unk_ftdobj_0x8;
    s32 unk_ftdobj_0xC;

} UnkFighterDObjData;

typedef struct ftHurtbox
{
    s32 hitstatus;
    s32 joint_index;
    DObj *joint;
    s32 placement;              // 0 = low, 1 = middle, 2 = high
    sb32 is_grabbable;
    Vec3f offset;
    Vec3f size;

} ftHurtbox;

typedef struct FighterHurtDesc
{
    s32 joint_index;
    s32 unk_fthdesc_0x4;
    s32 unk_fthdesc_0x8;
    Vec3f offset;
    Vec3f size;

} FighterHurtDesc;

typedef struct ftHitCollisionLog
{
    s32 hit_source;
    void *attacker_hit;
    s32 unk_hitlog_0x8;
    GObj *attacker_gobj;
    ftHurtbox *victim_hurt;
    u8 attacker_player;
    s32 attacker_player_number;

} ftHitCollisionLog;

typedef struct ftPartIndex
{
    s32 partindex_0x0;
    s32 partindex_0x4;
    s32 partindex_0x8;
    s32 partindex_0xC;

} ftPartIndex;

typedef struct ftCostumeIndex
{
    u8 ffa[4];
    u8 team[3];
    u8 unk_ftcostume_0x7;

} ftCostumeIndex;

typedef struct ftModelPartRenderState
{
    s8 render_state_b0;
    s8 render_state_b1;

} ftModelPartRenderState;

typedef struct ftTexturePartInfo
{
    u8 joint_index;
    u8 lod[2];

} ftTexturePartInfo;

typedef struct ftTexturePartContainer
{
    ftTexturePartInfo texture_part_info[2];

} ftTexturePartContainer;

typedef struct ftTexturePartRenderState
{
    s8 frame_index_default;
    s8 frame_index_current;

} ftTexturePartRenderState;

typedef struct ftModelPart
{
    void *display_list;
    void *unk_modelpart_0x4;
    void *unk_modelpart_0x8;
    void *unk_modelpart_0xC;
    u8 unk_modelpart_0x10;

} ftModelPart;

typedef struct ftModelPartDesc
{
    ftModelPart model_part[4][2];

} ftModelPartDesc;

typedef struct ftModelPartContainer
{
    ftModelPartDesc *model_part_desc[37];

} ftModelPartContainer;

static s32 ftHitCollisionLogIndex;
static ftHitCollisionLog ftHitCollisionLogTable[10];

typedef struct ftPartsUnkIndexTable
{
    s32 unk_ftpartunkindex_0x0;
    s32 unk_ftpartunkindex_0x4;

} ftPartsUnkIndexTable;

typedef enum ftPartsLevelDetail
{
    ftParts_LOD_None,       // Unused?
    ftParts_LOD_HighPoly,   // Hi-poly
    ftParts_LOD_LowPoly     // Lo-poly
        
} ftPartsLevelDetail;

typedef struct ftSprites
{
    Sprite *stock_spr;
    void **stock_lut;
    void *emblem;

} ftSprites;

typedef struct ftSkeleton
{
    union
    {
        void *display_list;
        DObjMultiList *multi_list;
    };
    
    s32 unk_ftskel_0x4;

} ftSkeleton;

typedef struct ftSkeletonContainer
{
    ftSkeleton skeleton[33][2];

} ftSkeletonContainer;

typedef struct ftAttributes
{
    f32 size_mul;
    f32 walkslow_anim_speed;
    f32 walkmiddle_anim_speed;
    f32 walkfast_anim_speed;
    f32 throw_walkslow_anim_speed;
    f32 throw_walkmiddle_anim_speed;
    f32 throw_walkfast_anim_speed; // Cargo Throw
    f32 rebound_anim_length;
    f32 walk_speed_mul;
    f32 traction;
    f32 dash_speed;
    f32 dash_decelerate;
    f32 run_speed;
    f32 kneebend_frames; // Jump squat frames
    f32 jump_vel_x;
    f32 jump_height_mul;
    f32 jump_height_base;
    f32 aerial_jump_vel_x;
    f32 aerial_jump_height;
    f32 aerial_acceleration;
    f32 aerial_speed_max_x;
    f32 aerial_friction;
    f32 gravity;
    f32 fall_speed_max;
    f32 fast_fall_speed;
    s32 jumps_max; // Number of jumps
    f32 weight;
    f32 attack1_followup_frames; // Jab combo connection frames
    f32 dash_to_run; // Frames before dash transitions to run?
    f32 shield_size;
    f32 shield_break_vel_y;
    f32 shadow_size;
    f32 jostle_width; // ???
    f32 jostle_x;
    sb32 is_metallic; // So far only seen this used to determine whether the character makes blue sparks or gray metal dust particles when hit; used by Metal Mario and Samus
    f32 cam_offset_y;    
    f32 vs_pause_zoom;
    f32 cam_zoom;
    f32 cam_zoom_default;
    ObjectColl object_coll;
    Vec2f cliffcatch_coll; // Ledge grab box
    u16 dead_sfx[2]; // KO voices
    u16 deadup_sfx;  // Star-KO voice
    u16 damage_sfx;
    u16 smash_sfx[3]; // Random Smash SFX
    s16 unk_0xC2;
    ftItemPickup item_pickup;
    u16 item_throw_vel;
    u16 item_throw_mul;
    u16 throw_heavy_sfx;
    f32 halo_size;
    GfxColorAlpha shade_color[4];
    u32 is_have_attack11 : 1;
    u32 is_have_attack12 : 1;
    u32 is_have_attackdash : 1;
    u32 is_have_attacks3 : 1;
    u32 is_have_attackhi3 : 1;
    u32 is_have_attacklw3 : 1;
    u32 is_have_attacks4 : 1;
    u32 is_have_attackhi4 : 1;
    u32 is_have_attacklw4 : 1;
    u32 is_have_attackairn : 1;
    u32 is_have_attackairf : 1;
    u32 is_have_attackairb : 1;
    u32 is_have_attackairhi : 1;
    u32 is_have_attackairlw : 1;
    u32 is_have_specialn : 1;
    u32 is_have_specialairn : 1;
    u32 is_have_specialhi : 1;
    u32 is_have_specialairhi : 1;
    u32 is_have_speciallw : 1;
    u32 is_have_specialairlw : 1;
    u32 is_have_catch : 1;
    u32 is_have_voice : 1;
    /*
    u32 catch_flags_b22 : 1;
    u32 catch_flags_b23 : 1;
    u32 catch_flags_b24 : 1;
    u32 catch_flags_b25 : 1;
    u32 catch_flags_b26 : 1;
    u32 catch_flags_b27 : 1;
    u32 catch_flags_b28 : 1;
    u32 catch_flags_b29 : 1;
    u32 catch_flags_b30 : 1;
    u32 catch_flags_b31 : 1;
    */
    FighterHurtDesc ftHurtbox_desc[11];
    Vec3f unk_ftca_0x290;
    s32 unk_ftca_0x29C;
    ftPartsUnkIndexTable *unk_ftca_0x2A0;
    s32 gfx_joint_cycle_index[5];
    sb32 cliff_status_ground_air_id[5];
    u8 filler_0x2CC[0x2D0 - 0x2CC];
    ftPartIndex *p_ftpart_lookup;
    DObjDescContainer *dobj_desc_container;
    DObjDesc *dobj_lookup;
    s32 *unk_joint[8];
    s32 joint_index1; // What does this do?
    f32 joint_float1;
    s32 joint_index2;
    f32 joint_float2;
    u8 filler_0x304[0x31C - 0x30C];
    f32 unk_0x31C;
    f32 unk_0x320;
    Vec3f *unk_0x324; // Fighter joint scales???
    ftModelPartContainer *model_parts;
    UnkFighterDObjData *unk_0x32C;
    ftTexturePartContainer *texture_parts;
    s32 joint_itemhold_heavy;
    ftThrownStatusArray *thrown_status;
    s32 joint_itemhold_light;
    ftSprites *sprites;
    ftSkeleton **skeleton;

} ftAttributes;

typedef struct ftStatus_EventScript
{
    u32 unk_0x0;

} ftStatus_EventScript;

typedef struct ftStatusDescFlags
{
    s16 anim_id : 10;
    u16 flags_hi_0x3F : 6;

} ftStatusDescFlags;

typedef struct ftStatusDesc
{
    ftStatusDescFlags flags_h;
    gmStatFlags flags_l;

    void (*proc_update)(GObj*);
    void (*proc_interrupt)(GObj*);
    void (*proc_physics)(GObj*);
    void (*proc_map)(GObj*);

} ftStatusDesc;

typedef struct ftIntroStatusDesc
{
    s32 anim_id;
    void (*proc_update)(GObj*);

} ftIntroStatusDesc;


typedef struct ftDataUnkContainer3
{
    ftStatus_EventScript *x0;

} ftDataUnkContainer3;

typedef struct ftAnimFlags
{
    union
    {
        struct
        {
            u32 is_use_xrotn_joint : 1;
            u32 is_use_transn_joint : 1;
            u32 is_use_yrotn_joint : 1;
            u32 x198_flag_b3 : 1;
            u32 x198_flag_b4 : 1;
            u32 x198_flag_b5 : 1;
            u32 x198_flag_b6 : 1;
            u32 x198_flag_b7 : 1;
            u32 x199_flag_b0 : 1;
            u32 x199_flag_b1 : 1;
            u32 x199_flag_b2 : 1;
            u32 x199_flag_b3 : 1;
            u32 x199_flag_b4 : 1;
            u32 x199_flag_b5 : 1;
            u32 x199_flag_b6 : 1;
            u32 x199_flag_b7 : 1;
            u32 x19A_flag_b0 : 1;
            u32 x19A_flag_b1 : 1;
            u32 x19A_flag_b2 : 1;
            u32 x19A_flag_b3 : 1;
            u32 x19A_flag_b4 : 1;
            u32 x19A_flag_b5 : 1;
            u32 x19A_flag_b6 : 1;
            u32 x19A_flag_b7 : 1;
            u32 x19B_flag_b0 : 1;
            u32 x19B_flag_b1 : 1;
            u32 x19B_flag_b2 : 1;
            u32 x19B_flag_b3 : 1;
            u32 x19B_flag_b4 : 1;
            u32 x19B_flag_b5 : 1;
            u32 x19B_flag_b6 : 1;
            u32 x19B_flag_b7 : 1;

        } flags;

        u32 word;
    };
    
} ftAnimFlags;

typedef struct ftAnimUnknown
{
    f32 floats[8];

} ftAnimUnknown;

typedef struct ftScriptInfo
{
    u32 anim_id;
    uintptr_t offset;
    ftAnimFlags anim_flags;

} ftScriptInfo;

typedef struct ftScriptInfoArray
{
    ftScriptInfo script_info[220];

} ftScriptInfoArray;

typedef struct ftScript2Data
{
    s32 unk_ftscript2_0x0;

} ftScript2Data;

typedef struct ftData
{
    intptr_t file_main_id; // File size in bytes?
    intptr_t file_battlescript_id;
    intptr_t file_demoscript_id;
    intptr_t file_model_id;
    intptr_t file_shieldpose_id;
    intptr_t file_extra1_id;
    intptr_t file_extra2_id;
    intptr_t file_extra3_id;
    intptr_t file_extra4_id;
    s32 file_size_total;
    void **p_file_main; // Pointer to character's file?
    s32 **p_file_battlescript;
    s32 **p_file_demoscript;
    s32 **p_file_model;
    s32 **p_file_shieldpose;
    s32 **p_file_extra1;
    s32 **p_file_extra2;
    s32 **p_file_extra3;
    s32 **p_file_extra4;
    void **p_particle;
    intptr_t o_particles1;
    intptr_t o_particles2;
    intptr_t o_particles3;
    intptr_t o_particles4;
    intptr_t o_attributes; // Offset to fighter's attributes
    ftScriptInfoArray *battlescript;
    ftScriptInfoArray *demoscript;
    s32 battlescript_array_count;
    s32 *demoscript_array_count;
    s32 anim_file_size;

} ftData;

typedef enum ftStatusUpdateFlags
{
    ftStatusUpdate_Hit_Preserve,
    ftStatusUpdate_ColAnim_Preserve,
    ftStatusUpdate_GFX_Preserve,
    ftStatusUpdate_FastFall_Preserve,
    ftStatusUpdate_HitStatus_Preserve,
    ftStatusUpdate_ModelPart_Preserve,
    ftStatusUpdate_SlopeContour_Preserve,
    ftStatusUpdate_TexturePart_Preserve,
    ftStatusUpdate_Unk3_Preserve,
    ftStatusUpdate_ThrowGObj_Preserve,
    ftStatusUpdate_ShuffleTime_Preserve, // Don't reset hitlag vibration frames?
    ftStatusUpdate_Unk4_Preserve,
    ftStatusUpdate_DamagePort_Preserve,
    ftStatusUpdate_AfterImage_Preserve,
    ftStatusUpdate_Unk5_Preserve

} ftStatusUpdateFlags;

#define FTSTATUPDATE_HIT_PRESERVE           (1 << ftStatusUpdate_Hit_Preserve)          // 0x1
#define FTSTATUPDATE_COLANIM_PRESERVE       (1 << ftStatusUpdate_ColAnim_Preserve)      // 0x2
#define FTSTATUPDATE_GFX_PRESERVE           (1 << ftStatusUpdate_GFX_Preserve)          // 0x4
#define FTSTATUPDATE_FASTFALL_PRESERVE      (1 << ftStatusUpdate_FastFall_Preserve)     // 0x8
#define FTSTATUPDATE_HITSTATUS_PRESERVE     (1 << ftStatusUpdate_HitStatus_Preserve)    // 0x10
#define FTSTATUPDATE_MODELPART_PRESERVE     (1 << ftStatusUpdate_ModelPart_Preserve)    // 0x20
#define FTSTATUPDATE_SLOPECONTOUR_PRESERVE  (1 << ftStatusUpdate_SlopeContour_Preserve) // 0x40
#define FTSTATUPDATE_TEXTUREPART_PRESERVE   (1 << ftStatusUpdate_TexturePart_Preserve)  // 0x80
#define FTSTATUPDATE_UNK3_PRESERVE          (1 << ftStatusUpdate_Unk3_Preserve)         // 0x100
#define FTSTATUPDATE_THROWPOINTER_PRESERVE  (1 << ftStatusUpdate_ThrowGObj_Preserve)    // 0x200
#define FTSTATUPDATE_SHUFFLETIME_PRESERVE   (1 << ftStatusUpdate_ShuffleTime_Preserve)  // 0x400
#define FTSTATUPDATE_UNK4_PRESERVE          (1 << ftStatusUpdate_Unk4_Preserve)         // 0x800
#define FTSTATUPDATE_DAMAGEPORT_PRESERVE    (1 << ftStatusUpdate_DamagePort_Preserve)   // 0x1000
#define FTSTATUPDATE_AFTERIMAGE_PRESERVE    (1 << ftStatusUpdate_AfterImage_Preserve)   // 0x2000
#define FTSTATUPDATE_UNK5_PRESERVE          (1 << ftStatusUpdate_Unk5_Preserve)         // 0x4000

typedef enum ftCommonAction
{
    ftStatus_Common_DeadDown,
    ftStatus_Common_DeadLeftRight,
    ftStatus_Common_DeadUpStar,
    ftStatus_Common_DeadUpFall,
    ftStatus_Common_Sleep,
    ftStatus_Common_Entry,
    ftStatus_Common_EntryNull,
    ftStatus_Common_RebirthDown,
    ftStatus_Common_RebirthStand,
    ftStatus_Common_RebirthWait,
    ftStatus_Common_Wait,
    ftStatus_Common_WalkSlow,
    ftStatus_Common_WalkMiddle,
    ftStatus_Common_WalkFast,
    ftStatus_Common_WalkEnd,
    ftStatus_Common_Dash,
    ftStatus_Common_Run,
    ftStatus_Common_RunBrake,
    ftStatus_Common_Turn,
    ftStatus_Common_TurnRun,
    ftStatus_Common_KneeBend,
    ftStatus_Common_GuardKneeBend,
    ftStatus_Common_JumpF,
    ftStatus_Common_JumpB,
    ftStatus_Common_JumpAerialF,
    ftStatus_Common_JumpAerialB,
    ftStatus_Common_Fall,
    ftStatus_Common_FallAerial,
    ftStatus_Common_Squat,
    ftStatus_Common_SquatWait,
    ftStatus_Common_SquatRv,
    ftStatus_Common_LandingLight,
    ftStatus_Common_LandingHeavy,
    ftStatus_Common_Pass,
    ftStatus_Common_GuardPass,
    ftStatus_Common_OttottoWait,
    ftStatus_Common_Ottotto,
    ftStatus_Common_DamageHi1,
    ftStatus_Common_DamageHi2,
    ftStatus_Common_DamageHi3,
    ftStatus_Common_DamageN1,
    ftStatus_Common_DamageN2,
    ftStatus_Common_DamageN3,
    ftStatus_Common_DamageLw1,
    ftStatus_Common_DamageLw2,
    ftStatus_Common_DamageLw3,
    ftStatus_Common_DamageAir1,
    ftStatus_Common_DamageAir2,
    ftStatus_Common_DamageAir3,
    ftStatus_Common_DamageElec1,
    ftStatus_Common_DamageElec2,
    ftStatus_Common_DamageFlyHi,
    ftStatus_Common_DamageFlyN,
    ftStatus_Common_DamageFlyLw,
    ftStatus_Common_DamageFlyTop,
    ftStatus_Common_DamageFlyRoll,
    ftStatus_Common_WallDamage,
    ftStatus_Common_DamageFall,
    ftStatus_Common_FallSpecial,
    ftStatus_Common_LandingFallSpecial,
    ftStatus_Common_Tornado,
    ftStatus_Common_TaruCann, // DK Barrel
    ftStatus_Common_DokanStart, // Enter pipe
    ftStatus_Common_DokanWait, // In pipe
    ftStatus_Common_DokanEnd, // Exit pipe
    ftStatus_Common_DokanWalk, // Exit horizontal pipe
    ftStatus_Common_StopCeil, // Bump head into ceiling
    ftStatus_Common_DownBounceD,
    ftStatus_Common_DownBounceU,
    ftStatus_Common_DownWaitD,
    ftStatus_Common_DownWaitU,
    ftStatus_Common_DownStandD,
    ftStatus_Common_DownStandU,
    ftStatus_Common_PassiveStandF,
    ftStatus_Common_PassiveStandB,
    ftStatus_Common_DownForwardD,
    ftStatus_Common_DownForwardU,
    ftStatus_Common_DownBackD,
    ftStatus_Common_DownBackU,
    ftStatus_Common_DownAttackD,
    ftStatus_Common_DownAttackU,
    ftStatus_Common_Passive,
    ftStatus_Common_ReboundWait,
    ftStatus_Common_Rebound,
    ftStatus_Common_CliffCatch,
    ftStatus_Common_CliffWait,
    ftStatus_Common_CliffQuick,
    ftStatus_Common_CliffClimbQuick1,
    ftStatus_Common_CliffClimbQuick2,
    ftStatus_Common_CliffSlow,
    ftStatus_Common_CliffClimbSlow1,
    ftStatus_Common_CliffClimbSlow2,
    ftStatus_Common_CliffAttackQuick1,
    ftStatus_Common_CliffAttackQuick2,
    ftStatus_Common_CliffAttackSlow1,
    ftStatus_Common_CliffAttackSlow2,
    ftStatus_Common_CliffEscapeQuick1,
    ftStatus_Common_CliffEscapeQuick2,
    ftStatus_Common_CliffEscapeSlow1,
    ftStatus_Common_CliffEscapeSlow2,
    ftStatus_Common_LightGet,
    ftStatus_Common_HeavyGet,
    ftStatus_Common_LiftWait,
    ftStatus_Common_LiftTurn,
    ftStatus_Common_LightThrowDrop,
    ftStatus_Common_LightThrowDash,
    ftStatus_Common_LightThrowF,
    ftStatus_Common_LightThrowB,
    ftStatus_Common_LightThrowHi,
    ftStatus_Common_LightThrowLw,
    ftStatus_Common_LightThrowF4,
    ftStatus_Common_LightThrowB4,
    ftStatus_Common_LightThrowHi4,
    ftStatus_Common_LightThrowLw4,
    ftStatus_Common_LightThrowAirF,
    ftStatus_Common_LightThrowAirB,
    ftStatus_Common_LightThrowAirHi,
    ftStatus_Common_LightThrowAirLw,
    ftStatus_Common_LightThrowAirF4,
    ftStatus_Common_LightThrowAirB4,
    ftStatus_Common_LightThrowAirHi4,
    ftStatus_Common_LightThrowAirLw4,
    ftStatus_Common_HeavyThrowF,
    ftStatus_Common_HeavyThrowB,
    ftStatus_Common_HeavyThrowF4,
    ftStatus_Common_HeavyThrowB4,
    ftStatus_Common_SwordSwing1,
    ftStatus_Common_SwordSwing3,
    ftStatus_Common_SwordSwing4,
    ftStatus_Common_SwordSwingDash,
    ftStatus_Common_BatSwing1,
    ftStatus_Common_BatSwing3,
    ftStatus_Common_BatSwing4,
    ftStatus_Common_BatSwingDash,
    ftStatus_Common_HarisenSwing1,
    ftStatus_Common_HarisenSwing3,
    ftStatus_Common_HarisenSwing4,
    ftStatus_Common_HarisenSwingDash,
    ftStatus_Common_StarRodSwing1,
    ftStatus_Common_StarRodSwing3,
    ftStatus_Common_StarRodSwing4,
    ftStatus_Common_StarRodSwingDash,
    ftStatus_Common_LGunShoot,
    ftStatus_Common_LGunShootAir,
    ftStatus_Common_FireFlowerShoot,
    ftStatus_Common_FireFlowerShootAir,
    ftStatus_Common_HammerWait,
    ftStatus_Common_HammerWalk,
    ftStatus_Common_HammerTurn,
    ftStatus_Common_HammerKneeBend,
    ftStatus_Common_HammerFall, // Pretty much any aerial Hammer state
    ftStatus_Common_HammerLanding,
    ftStatus_Common_GuardOn,
    ftStatus_Common_Guard,
    ftStatus_Common_GuardOff,
    ftStatus_Common_GuardSetOff,
    ftStatus_Common_EscapeF,
    ftStatus_Common_EscapeB,
    ftStatus_Common_ShieldBreakFly,
    ftStatus_Common_ShieldBreakFall,
    ftStatus_Common_ShieldBreakDownD,
    ftStatus_Common_ShieldBreakDownU,
    ftStatus_Common_ShieldBreakStandD,
    ftStatus_Common_ShieldBreakStandU,
    ftStatus_Common_FuraFura,
    ftStatus_Common_FuraSleep,
    ftStatus_Common_Catch,
    ftStatus_Common_CatchPull,
    ftStatus_Common_CatchWait,
    ftStatus_Common_ThrowF,
    ftStatus_Common_ThrowB,
    ftStatus_Common_CapturePulled,
    ftStatus_Common_CaptureWait,
    ftStatus_Common_CaptureKirby,
    ftStatus_Common_CaptureWaitKirby,
    ftStatus_Common_ThrownKirbyStar,
    ftStatus_Common_ThrownCopyStar,
    ftStatus_Common_CaptureYoshi,
    ftStatus_Common_YoshiEgg,
    ftStatus_Common_CaptureCaptain,
    ftStatus_Common_ThrownDonkeyUnk, // Related to DK throws?
    ftStatus_Common_ThrownDonkeyF,
    ftStatus_Common_ThrownMarioB,
    ftStatus_Common_ThrownFoxF,
    ftStatus_Common_Shouldered,
    ftStatus_Common_ThrownF,
    ftStatus_Common_ThrownB,
    ftStatus_Common_ThrownUnk,
    ftStatus_Common_ThrownFoxB,
    ftStatus_Common_Appeal,
    ftStatus_Common_Attack11,
    ftStatus_Common_Attack12,
    ftStatus_Common_AttackDash,
    ftStatus_Common_AttackS3Hi,
    ftStatus_Common_AttackS3HiS,
    ftStatus_Common_AttackS3,
    ftStatus_Common_AttackS3LwS,
    ftStatus_Common_AttackS3Lw,
    ftStatus_Common_AttackHi3F, // Forward-angled up tilt???
    ftStatus_Common_AttackHi3,
    ftStatus_Common_AttackHi3B, // Unknown
    ftStatus_Common_AttackLw3,
    ftStatus_Common_AttackS4Hi,
    ftStatus_Common_AttackS4HiS,
    ftStatus_Common_AttackS4,
    ftStatus_Common_AttackS4LwS,
    ftStatus_Common_AttackS4Lw,
    ftStatus_Common_AttackHi4,
    ftStatus_Common_AttackLw4,
    ftStatus_Common_AttackAirN,
    ftStatus_Common_AttackAirF,
    ftStatus_Common_AttackAirB,
    ftStatus_Common_AttackAirHi,
    ftStatus_Common_AttackAirLw,
    ftStatus_Common_LandingAirN,
    ftStatus_Common_LandingAirF,
    ftStatus_Common_LandingAirB,
    ftStatus_Common_LandingAirHi,
    ftStatus_Common_LandingAirLw,
    ftStatus_Common_LandingAirX,
    ftStatus_Common_SpecialStart // Start of special move table

} ftCommonAction;

typedef enum ftKind
{

    Ft_Kind_Mario,
    Ft_Kind_Fox,
    Ft_Kind_Donkey,
    Ft_Kind_Samus,
    Ft_Kind_Luigi,
    Ft_Kind_Link,
    Ft_Kind_Yoshi,
    Ft_Kind_Captain,
    Ft_Kind_Kirby,
    Ft_Kind_Pikachu,
    Ft_Kind_Purin,
    Ft_Kind_Ness,
    Ft_Kind_MasterHand,
    Ft_Kind_MetalMario,
    Ft_Kind_PolyMario,
    Ft_Kind_PolyFox,
    Ft_Kind_PolyDonkey,
    Ft_Kind_PolySamus,
    Ft_Kind_PolyLuigi,
    Ft_Kind_PolyLink,
    Ft_Kind_PolyYoshi,
    Ft_Kind_PolyCaptain,
    Ft_Kind_PolyKirby,
    Ft_Kind_PolyPikachu,
    Ft_Kind_PolyPurin,
    Ft_Kind_PolyNess,
    Ft_Kind_GiantDonkey

} ftKind;

typedef enum plKind
{
    Pl_Kind_Human,
    Pl_Kind_CPU,
    Pl_Kind_None,
    Pl_Kind_Result,
    Pl_Kind_Intro,
    Pl_Kind_Explain

} plKind;

typedef enum ftSpecialStatus
{
    ftSpecialStatus_Invincible, // Fighter cannot take damage?
    ftSpecialStatus_Normal, // Fighter can take damage
    ftSpecialStatus_Star, // CPUs run away from fighter; cannot take damage
    ftSpecialStatus_Intangible // Fighter cannot be hit at all

} ftSpecialStatus;

#define gmScriptEventUpdatePtr(event, type)                                   \
((event)->p_script = (void*) ((uintptr_t)event->p_script + (sizeof(type))))   \

#define gmScriptEventCast(event, type)                                        \
((type*) event->p_script)                                                     \

// WARNING: Only advances 4 bytes at a time
#define gmScriptEventCastUpdate(event, type)                                  \
((type*) event->p_script++)                                                   \

#define gmColorEventUpdatePtr(event, type)                                    \
(event = (void*) ((uintptr_t)event + sizeof(type)))                           \

#define gmColorEventCast(event, type)                                         \
((type*) event)                                                               \

// WARNING: Only advances 4 bytes at a time
#define gmColorEventCastUpdate(event, type)                                   \
((type*) event++)                                                             \

typedef enum gmScriptEventKind
{
    gmScriptEvent_Kind_End,
    gmScriptEvent_Kind_SyncWait,
    gmScriptEvent_Kind_AsyncWait,
    gmScriptEvent_Kind_ftHitbox,
    gmScriptEvent_Kind_ItemSwingHit,
    gmScriptEvent_Kind_ClearHitIndex,
    gmScriptEvent_Kind_ClearHitAll,
    gmScriptEvent_Kind_SetHitOffset,
    gmScriptEvent_Kind_SetHitDamage,
    gmScriptEvent_Kind_SetHitSize,
    gmScriptEvent_Kind_SetHitSoundLevel,
    gmScriptEvent_Kind_ResetHit, // ???
    gmScriptEvent_Kind_SetFighterThrow,
    gmScriptEvent_Kind_SubroutineUnk, // ???
    gmScriptEvent_Kind_PlaySFX,
    gmScriptEvent_Kind_UnkPlaySFX1,
    gmScriptEvent_Kind_UnkPlaySFX2,
    gmScriptEvent_Kind_PlayVoice,
    gmScriptEvent_Kind_UnkPlayVoice,
    gmScriptEvent_Kind_StorePlaySFX,
    gmScriptEvent_Kind_PlaySmashVoice,
    gmScriptEvent_Kind_SetFlag0,
    gmScriptEvent_Kind_SetFlag1,
    gmScriptEvent_Kind_SetFlag2,
    gmScriptEvent_Kind_SetFlag3,
    gmScriptEvent_Kind_SetAirJumpAdd,
    gmScriptEvent_Kind_SetAirJumpMax,
    gmScriptEvent_Kind_ResetHitStatusAll,
    gmScriptEvent_Kind_SetHitStatusPart,
    gmScriptEvent_Kind_SetHitStatusAll,
    gmScriptEvent_Kind_ResetHurtAll,
    gmScriptEvent_Kind_SetHurtPart,
    gmScriptEvent_Kind_LoopBegin,
    gmScriptEvent_Kind_LoopEnd,
    gmScriptEvent_Kind_Subroutine,
    gmScriptEvent_Kind_Return,
    gmScriptEvent_Kind_Goto,
    gmScriptEvent_Kind_ScriptPause,
    gmScriptEvent_Kind_GFX,
    gmScriptEvent_Kind_GFXPersist, // ???
    gmScriptEvent_Kind_SetModelPart,
    gmScriptEvent_Kind_Unk10,
    gmScriptEvent_Kind_Unk11,
    gmScriptEvent_Kind_SetTexturePart,
    gmScriptEvent_Kind_Unk12,
    gmScriptEvent_Kind_Unk13,
    gmScriptEvent_Kind_SetParallelScript, // What
    gmScriptEvent_Kind_SlopeContour,
    gmScriptEvent_Kind_Unk14,
    gmScriptEvent_Kind_Unk15,
    gmScriptEvent_Kind_Unk16,
    gmScriptEvent_Kind_AfterImage // Sword Trail

} gmScriptEventKind;

typedef enum gmColorEventKind
{
    gmColorEvent_Kind_End,
    gmColorEvent_Kind_Wait,
    gmColorEvent_Kind_Goto,
    gmColorEvent_Kind_LoopBegin,
    gmColorEvent_Kind_LoopEnd,
    gmColorEvent_Kind_Subroutine,
    gmColorEvent_Kind_Return,
    gmColorEvent_Kind_SetParallelScript,
    gmColorEvent_Kind_ToggleColorOff,
    gmColorEvent_Kind_SetColor1,
    gmColorEvent_Kind_BlendColor1,
    gmColorEvent_Kind_SetColor2,
    gmColorEvent_Kind_BlendColor2,
    gmColorEvent_Kind_GFX,
    gmColorEvent_Kind_GFXPersist,
    gmColorEvent_Kind_SetLight,
    gmColorEvent_Kind_ToggleLightOff,
    gmColorEvent_Kind_PlaySFX,
    gmColorEvent_Kind_SetUnk

} gmColorEventKind;

typedef struct gmScriptPointer
{
    void *p_goto[1];
    s32 script_index[4];

} gmScriptPointer;

typedef struct gmScriptEvent
{
    f32 frame_timer;
    u32 *p_script;
    s32 script_index;
    void *p_goto[1];
    s32 loop_count[4];

} gmScriptEvent;

typedef struct gmScriptEventDefault // Event with no arguments
{
    u32 opcode : 6;

} gmScriptEventDefault;

typedef struct gmScriptEventWait
{
    u32 opcode : 6;
    u32 frames : 26;

} gmScriptEventWait;

typedef struct gmScriptEventCreateHit1
{
    u32 opcode : 6;
    u32 hit_id : 3;
    u32 group_id : 3;
    s32 joint_index : 7;
    u32 damage : 8;
    u32 clang : 1;
    u32 element : 4;

} gmScriptEventCreateHit1;

typedef struct gmScriptEventCreateHit2
{
    u32 size : 16;
    s32 off_x : 16;

} gmScriptEventCreateHit2;

typedef struct gmScriptEventCreateHit3
{
    s32 off_y : 16;
    s32 off_z : 16;

} gmScriptEventCreateHit3;

typedef struct gmScriptEventCreateHit4
{
    s32 angle : 10;
    u32 knockback_scale : 10;
    u32 knockback_weight : 10;
    u32 is_hit_ground_air : 2;

} gmScriptEventCreateHit4;

typedef struct gmScriptEventCreateHit5
{
    s32 shield_damage : 8;
    u32 sfx_level : 3;
    u32 sfx_kind : 4;
    u32 knockback_base : 10;

} gmScriptEventCreateHit5;

typedef struct gmScriptEventCreateHit
{
    gmScriptEventCreateHit1 s1;
    gmScriptEventCreateHit2 s2;
    gmScriptEventCreateHit3 s3;
    gmScriptEventCreateHit4 s4;
    gmScriptEventCreateHit5 s5;

} gmScriptEventCreateHit;

typedef struct gmScriptEventSetHitOff1
{
    u32 opcode : 6;
    u32 hit_id : 3;
    s32 off_x : 16;

} gmScriptEventSetHitOff1;

typedef struct gmScriptEventSetHitOff2
{
    s32 off_y : 16;
    s32 off_z : 16;

} gmScriptEventSetHitOff2;

typedef struct gmScriptEventSetHitOff
{
    gmScriptEventSetHitOff1 s1;
    gmScriptEventSetHitOff2 s2;

} gmScriptEventSetHitOff;

typedef struct gmScriptEventSetHitDamage
{
    u32 opcode : 6;
    u32 hit_id : 3;
    u32 damage : 8;

} gmScriptEventSetHitDamage;

typedef struct gmScriptEventSetHitSize
{
    u32 opcode : 6;
    u32 hit_id : 3;
    u32 size : 16;

} gmScriptEventSetHitSize;

typedef struct gmScriptEventSetHitSound
{
    u32 opcode : 6;
    u32 hit_id : 3;
    u32 sfx_level : 3;

} gmScriptEventSetHitSound;

typedef struct gmScriptEventResetHit
{
    u32 opcode : 6;
    u32 hit_id : 26;
    
} gmScriptEventResetHit;

typedef struct gmScriptEventClearHitIndex
{
    u32 opcode : 6;
    u32 hit_id : 26;

} gmScriptEventClearHitIndex;

typedef struct gmScriptEventClearHitAll
{
    u32 opcode : 6;

} gmScriptEventClearHitAll;

typedef struct gmScriptEventSetFighterThrow1
{
    u32 opcode : 6;

} gmScriptEventSetFighterThrow1;

typedef struct gmScriptEventSetFighterThrow2
{
    ftThrowHitDesc *fighter_throw;

} gmScriptEventSetFighterThrow2;

typedef struct gmScriptEventSetFighterThrow
{
    gmScriptEventSetFighterThrow1 s1;
    gmScriptEventSetFighterThrow2 s2;

} gmScriptEventSetFighterThrow;

typedef struct gmScriptEventPlaySFX
{
    u32 opcode : 6;
    u32 sfx_id : 26;

} gmScriptEventPlaySFX;

typedef struct gmScriptEventCreateGFX1
{
    u32 opcode : 6;
    s32 joint_index : 7;
    u32 gfx_id : 9;
    u32 flag : 10;

} gmScriptEventCreateGFX1;

typedef struct gmScriptEventCreateGFX2
{
    s32 off_x : 16;
    s32 off_y : 16;

} gmScriptEventCreateGFX2;

typedef struct gmScriptEventCreateGFX3
{
    s32 off_z : 16;
    s32 rng_x : 16;

} gmScriptEventCreateGFX3;

typedef struct gmScriptEventCreateGFX4
{
    s32 rng_y : 16;
    s32 rng_z : 16;

} gmScriptEventCreateGFX4;

typedef struct gmScriptEventCreateGFX
{
    gmScriptEventCreateGFX1 s1;
    gmScriptEventCreateGFX2 s2;
    gmScriptEventCreateGFX3 s3;
    gmScriptEventCreateGFX4 s4;

} gmScriptEventCreateGFX;

typedef struct gmScriptEventSetHitStatusAll
{
    u32 opcode : 6;
    u32 hitstatus : 26;

} gmScriptEventSetHitStatusAll;

typedef struct gmScriptEventSetHitStatusPart
{
    u32 opcode : 6;
    s32 joint_index : 7;
    u32 hitstatus : 19;

} gmScriptEventSetHitStatusPart;

typedef struct gmScriptEventSetHurtPart1
{
    u32 opcode : 6;
    s32 joint_index : 7;

} gmScriptEventSetHurtPart1;

typedef struct gmScriptEventSetHurtPart2
{
    s32 off_x : 16;
    s32 off_y : 16;

} gmScriptEventSetHurtPart2; 

typedef struct gmScriptEventSetHurtPart3
{
    s32 off_z : 16;
    s32 size_x : 16;

} gmScriptEventSetHurtPart3; 

typedef struct gmScriptEventSetHurtPart4
{
    s32 size_y : 16;
    s32 size_z : 16;

} gmScriptEventSetHurtPart4;

typedef struct gmScriptEventSetHurtPart
{
    gmScriptEventSetHurtPart1 s1;
    gmScriptEventSetHurtPart2 s2;
    gmScriptEventSetHurtPart3 s3;
    gmScriptEventSetHurtPart4 s4;

} gmScriptEventSetHurtPart;

typedef struct gmScriptEventLoopBegin
{
    u32 opcode : 6;
    u32 loop_count : 26;

} gmScriptEventLoopBegin;

typedef struct gmScriptEventSubroutine1
{
    u32 opcode : 6;    

} gmScriptEventSubroutine1;

typedef struct gmScriptEventSubroutine2
{
    void *p_goto;

} gmScriptEventSubroutine2;

typedef struct gmScriptEventSubroutine
{
    gmScriptEventSubroutine1 s1;
    gmScriptEventSubroutine2 s2;

} gmScriptEventSubroutine;

typedef struct gmScriptEventDamageUnk1
{
    u32 opcode : 6;

} gmScriptEventDamageUnk1;

typedef struct gmScriptEventDamageUnk2
{
    void *p_subroutine;

} gmScriptEventDamageUnk2;

typedef struct gmScriptEventDamage
{
    void *p_script[2][27];

} gmScriptEventDamage;

typedef struct gmScriptEventDamageUnk
{
    gmScriptEventDamageUnk1 s1;
    gmScriptEventDamageUnk2 s2;

} gmScriptEventDamageUnk;

typedef struct gmScriptEventReturn
{
    u32 opcode : 6;

} gmScriptEventReturn;

typedef struct gmScriptEventGoto1
{
    u32 opcode : 6;    

} gmScriptEventGoto1;

typedef struct gmScriptEventGoto2
{
    void *p_goto;

} gmScriptEventGoto2;

typedef struct gmScriptEventGoto
{
    gmScriptEventGoto1 s1;
    gmScriptEventGoto2 s2;

} gmScriptEventGoto;

typedef struct gmScriptEventParallel1
{
    u32 opcode : 6;    

} gmScriptEventParallel1;

typedef struct gmScriptEventParallel2
{
    void *p_goto;

} gmScriptEventParallel2;

typedef struct gmScriptEventParallel
{
    gmScriptEventParallel1 s1;
    gmScriptEventParallel2 s2;

} gmScriptEventParallel;

typedef struct gmScriptEventSetModelPart
{
    u32 opcode : 6;
    s32 joint_index : 7;
    s32 mode : 19;

} gmScriptEventSetModelPart;

typedef struct gmScriptEventSetTexturePart
{
    u32 opcode : 6;
    u32 obj_index : 6;
    u32 frame : 20; 

} gmScriptEventSetTexturePart;

typedef struct gmScriptEventSetColAnim
{
    u32 opcode : 6;
    u32 colanim_id : 8;
    u32 length : 18;

} gmScriptEventSetColAnim;

typedef struct gmScriptEventSetFlag
{
    u32 opcode : 6;
    u32 flag : 26;

} gmScriptEventSetFlag;

typedef struct gmScriptEventSlopeContour
{
    u32 opcode : 6;
    u32 filler : 23;
    u32 mode : 3;

} gmScriptEventSlopeContour;

typedef struct gmScriptEventUnkFlag
{
    u32 opcode : 6;
    u32 flag : 26;

} gmScriptEventUnkFlag;

typedef struct gmScriptEventAfterImage
{
    u32 opcode : 6;
    u32 is_itemswing : 8;
    s32 render_state : 18;

} gmScriptEventAfterImage;

typedef struct gmScriptEventUnk31
{
    u32 opcode : 6;
    u32 value1 : 13;
    u32 value2 : 13;

} gmScriptEventUnk31;

typedef struct gmScriptEventUnk32
{
    u32 opcode : 6;
    u32 value1 : 26;

} gmScriptEventUnk32;

typedef struct gmColorEventDefault
{
    u32 opcode : 6;
    u32 value1 : 26;

} gmColorEventDefault;

typedef struct gmColorEventGoto1
{
    u32 opocode : 6;

} gmColorEventGoto1;

typedef struct gmColorEventGoto2
{
    void *p_goto;

} gmColorEventGoto2;

typedef struct gmColorEventGoto
{
    gmColorEventGoto1 s1;
    gmColorEventGoto2 s2;
    
} gmColorEventGoto;

typedef struct gmColorEventLoopBegin
{
    u32 opcode : 6;
    u32 loop_count : 26;

} gmColorEventLoopBegin;

typedef struct gmColorEventSubroutine1
{
    u32 opcode : 6;

} gmColorEventSubroutine1;

typedef struct gmColorEventSubroutine2
{
    void *p_subroutine;

} gmColorEventSubroutine2;

typedef struct gmColorEventSubroutine
{
    gmColorEventSubroutine1 s1;
    gmColorEventSubroutine2 s2;

} gmColorEventSubroutine;

typedef struct gmColorEventParallel1
{
    u32 opcode : 6;

} gmColorEventParallel1;

typedef struct gmColorEventParallel2
{
    void *p_script;

} gmColorEventParallel2;

typedef struct gmColorEventParallel
{
    gmColorEventParallel1 s1;
    gmColorEventParallel2 s2;

} gmColorEventParallel;

typedef struct gmColorEventSetRGBA1
{
    u32 opcode : 6;

} gmColorEventSetRGBA1;

typedef struct gmColorEventSetRGBA2
{
    u32 r : 8;
    u32 g : 8;
    u32 b : 8;
    u32 a : 8;

} gmColorEventSetRGBA2;

typedef struct gmColorEventBlendRGBA1
{
    u32 opcode : 6;
    u32 blend_frames : 26;

} gmColorEventBlendRGBA1;

typedef struct gmColorEventBlendRGBA2
{
    u32 r : 8;
    u32 g : 8;
    u32 b : 8;
    u32 a : 8;

} gmColorEventBlendRGBA2;

typedef struct gmColorEventBlendRGBA
{
    gmColorEventBlendRGBA1 s1;
    gmColorEventBlendRGBA2 s2;

} gmColorEventBlendRGBA;

typedef struct gmColorEventCreateGFX1
{
    u32 opcode : 6;
    s32 joint_index : 7;
    u32 gfx_id : 9;
    u32 flag : 10;

} gmColorEventCreateGFX1;

typedef struct gmColorEventCreateGFX2
{
    s32 off_x : 16;
    s32 off_y : 16;

} gmColorEventCreateGFX2;

typedef struct gmColorEventCreateGFX3
{
    s32 off_z : 16;
    s32 rng_x : 16;

} gmColorEventCreateGFX3;

typedef struct gmColorEventCreateGFX4
{
    s32 rng_y : 16;
    s32 rng_z : 16;

} gmColorEventCreateGFX4;

typedef struct gmColorEventCreateGFX
{
    gmColorEventCreateGFX1 s1;
    gmColorEventCreateGFX2 s2;
    gmColorEventCreateGFX3 s3;
    gmColorEventCreateGFX4 s4;

} gmColorEventCreateGFX;

typedef struct gmColorEventSetLight
{
    u32 opcode : 6;
    s32 light1 : 13;
    s32 light2 : 13;

} gmColorEventSetLight;

typedef struct gmColorEventPlaySFX
{
    u32 opcode : 6;
    u32 sfx_id : 26;

} gmColorEventPlaySFX;

typedef struct ftUnkFrameStruct
{
    f32 unk_0x0;
    s32 unk_0x4;
    void *unk_0x8;
    void *unk_0xC;
    f32 unk_0x10;
    void *unk_0x14;
    void *unk_0x18;
    void *unk_0x1C;

} ftUnkFrameStruct;

typedef struct AfterImageDesc
{
    s16 unk_afid_0x0;
    s16 unk_afid_0x2;
    s16 unk_afid_0x4;
    Vec3f vec;

} AfterImageDesc;

typedef struct ftStruct ftStruct;

ftStruct *gMainFighterStructCurrent;

typedef struct Fighter_Com
{
    u8 behave_current;
    u8 behave_default;
    u8 attack_id;
    u8 behavior_set;
    u8 unk_ftcom_0x4;
    u8 behavior_write; // Override behavior
    u8 unk_ftcom_0x6;
    u8 input_wait; // "Controller command wait timer"
    u8 *p_command;
    void (*proc_com)(GObj*); // "Main behavior routine"
    s32 unk_ftcom_0x10;
    s32 unk_ftcom_0x14;
    s16 unk_ftcom_0x18;
    s16 unk_timer_0x1A;
    s32 unk_timer_0x1C;
    s32 unk_ftcom_0x20;
    u16 target_find_wait; 
    u16 target_damage_percent;
    s32 unk_ftcom_0x28;
    s32 unk_ftcom_0x2C;
    GObj *target_gobj;
    u8 unk_ftcom_0x34;
    u8 unk_ftcom_0x35;
    u8 unk_ftcom_0x36;
    u8 unk_ftcom_0x37;
    u8 unk_ftcom_0x38;
    u8 attack11;
    u8 attacks3;
    u8 attacks4;
    u8 attackhi3;
    u8 attackhi4;
    u8 attacklw3;
    u8 attacklw4;
    u8 specialn;
    u8 specialhi;
    u8 speciallw;
    u8 unk_ftcom_0x43; // Also neutral special?
    u8 filler_0x44[0x48 - 0x44];
    u8 ftcom_flags_0x48_b0 : 1;
    u8 ftcom_flags_0x48_b1 : 1;
    u8 ftcom_flags_0x48__0x48_b2 : 1;
    u8 ftcom_flags_0x48_b3 : 1;
    u8 ftcom_flags_0x48_b4 : 1;
    u8 ftcom_flags_0x48_b5 : 1;
    u8 ftcom_flags_0x48_b6 : 1;
    u8 ftcom_flags_0x48_b7 : 1;
    u8 ftcom_flags_0x49_b0 : 1;
    u8 ftcom_flags_0x49_b1 : 1;
    u8 ftcom_flags_0x49_b2 : 1;
    u8 ftcom_flags_0x49_b3 : 1;
    u8 ftcom_flags_0x49_b4 : 1;
    u8 ftcom_flags_0x49_b5 : 1;
    u8 ftcom_flags_0x49_b6 : 1;
    u8 ftcom_flags_0x49_b7 : 1;
    u8 ftcom_flags_0x4A_b0 : 1;
    u8 ftcom_flags_0x4A_b1 : 1;
    u8 ftcom_flags_0x4A_b2 : 1;
    u8 ftcom_flags_0x4A_b3 : 1;
    u8 ftcom_flags_0x4A_b4 : 1;
    u8 ftcom_flags_0x4A_b5 : 1;
    u8 ftcom_flags_0x4A_b6 : 1;
    u8 ftcom_flags_0x4A_b7 : 1;
    u8 ftcom_flags_0x4B_b0 : 1;
    u8 ftcom_flags_0x4B_b1 : 1;
    u8 ftcom_flags_0x4B_b2 : 1;
    u8 ftcom_flags_0x4B_b3 : 1;
    u8 ftcom_flags_0x4B_b4 : 1;
    u8 ftcom_flags_0x4B_b5 : 1;
    u8 ftcom_flags_0x4B_b6 : 1;
    u8 ftcom_flags_0x4B_b7 : 1;
    Vec2f cliff_left_pos; // Ledge position
    Vec2f cliff_right_pos;
    s32 target_line_id; // Line ID target is standing on
    Vec2f target_pos;
    f32 target_dist; // FLOAT_MAX when offstage
    ftStruct *target_fp; // I assume this is what the documentation means?
    u8 filler_0x70[0x8C - 0x70];
    f32 unk_ftcom_0x8C;

} Fighter_Com;

typedef struct ftPlayerInput
{
    u16 button_hold;
    u16 button_tap;
    u16 button_tap_prev;
    Vec2b stick_range;
    Vec2b stick_prev; // Previous stick range?

} ftPlayerInput;

typedef struct ftComputerInput
{
    u16 button_inputs;
    Vec2b stick_range; // CPU stick input?

} ftComputerInput;

typedef struct ftExplainCommand
{
    u16 opcode : 4;
    u16 param : 12;

} ftExplainCommand;

typedef struct ftExplainInput
{
    s32 input_wait;
    ftExplainCommand *input_seq;

} ftExplainInput;

#define ftExplainCommandCast(input_seq, type) \
((type*)(input_seq)) \

#define ftExplainGetCpButtons(input_seq)    \
(*(ftExplainCommandCast((input_seq), u16))) \

#define ftExplainGetCpStickRange(input_seq)\
(ftExplainCommandCast((input_seq), Vec2b)) \

typedef struct ftCamera
{
    ftStruct *target_fp;
    Vec3f target_pos;
    f32 unk_ftcam_0x10;

} ftCamera;

ftData *ftManager_FighterData_FilePointers[27];

typedef struct ftSpawnInfo
{
    s32 ft_kind;
    Vec3f pos;
    s32 lr_spawn;
    u8 team;
    u8 player;
    u8 model_lod;
    u8 costume;
    u8 shade;
    u8 handicap;
    u8 cp_level;
    u8 stock_count;
    u32 unk_rebirth_0x1C : 8;
    u32 unk_rebirth_0x1D : 8;
    u32 unk_rebirth_0x1E : 8;
    u32 unk_rebirth_0x1F_b0 : 1;
    u32 unk_rebirth_0x1F_b1 : 1;
    u32 unk_rebirth_0x1F_b2 : 1;
    u32 unk_rebirth_0x1F_b3 : 1;
    s32 copy_kind;    // Might be used exclusively for Kirby's copy ID
    s32 damage;
    s32 pl_kind;
    void *p_controller; // Pointer to player's controller inputs
    u16 button_mask_a;
    u16 button_mask_b;
    u16 button_mask_z;
    u16 button_mask_l;
    void *unk_rebirth_0x38; // Pointer to animation bank?
    void *unk_rebirth_0x3C;

} ftSpawnInfo;

ftStruct *D_ovl2_80130D80;
ftStruct *D_ovl2_80130D84;
ftParts *D_ovl2_80130D88;
ftParts *D_ovl2_80130D8C;
void *D_ovl2_80130D98;
u32 D_ovl2_80130D9C;
u32 gBattlePlayerCount;
u16 gEntityMotionCount;
u16 gEntityStatUpdateCount;

struct ftStruct
{
    ftStruct *fp_alloc_next;
    GObj *fighter_gobj;
    ftKind ft_kind;
    u8 team;
    u8 player;    
    u8 lod_current;  // Hi-Poly = 1, Low-Poly = 2
    u8 lod_match; // Hi-Poly = 1, Low-Poly = 2
    u8 costume;
    u8 shade; // i.e. When multiple instances of the same character costume are in-game
    u8 handicap; // Original note: offset to attack hitbox type in 5x (???)
    u8 cp_level; // CPU level
    s8 stock_count;
    u8 unk_0x15;
    u8 unk_0x16;
    s32 player_number; // Based on port

    struct // Status = Action State
    {
        u32 status_time_spent; // 0x1C
        plKind pl_kind;
        s32 status_id;
        s32 script_id;

    } status_info;

    s32 percent_damage;
    s32 damage_resist; // Used as HP in Kirby's Stone
    s32 shield_health;
    f32 unk_ft_0x38;
    s32 x3C_unk;
    u32 hitlag_timer; // Freeze if TRUE
    s32 lr; // Facing direction; -1 = LEFT, 1 = RIGHT

    struct phys_info
    {
        Vec3f vel_air; // Knockback / external velocity?
        Vec3f vel_damage_air;
        Vec3f vel_ground; // Might be one float?
        f32 vel_damage_ground;
        f32 vel_jostle_x;
        f32 vel_jostle_z;

    } phys_info;

    Coll_Data coll_data;
    u8 jumps_used;
    u8 unk_ft_0x149;

    Ground_Air ground_or_air;

    f32 attack1_followup_frames;
    s32 attack1_status_id;
    s32 attack1_input_count;
    s32 cliffcatch_wait;
    s32 time_since_last_z;  // Frames since last Z-press, resets to 65536 on action state change
    s32 acid_wait;          // Wait this many frames before fighter can be hurt by Planet Zebes acid again?
    s32 twister_wait;       // Wait this many frames before fighter can be picked up by the Hyrule Tornado again
    s32 tarucann_wait;      // Wait this many frames before fighter can enter Barrel Cannon again
    s32 damagefloor_wait;   // Wait this many frames before fighter can be hurt by damaging floors again (e.g. Mario's Board the Platforms stage)
    s32 playertag_wait;     // Wait this many frames before fighter's player indicator is shown again; tag is shown when this reaches 1 or is overridden by position on stage
    s32 unk_0x178;

    union command_vars
    {
        struct flags
        {
            u32 flag0;
            u32 flag1;    
            u32 flag2;
            u32 flag3;

        } flags;

        struct item_throw
        {
            sb32 is_throw_item;
            u8 unk1;
            u32 damage : 24;
            u8 unk2;
            u32 vel : 12;
            s32 angle : 12;

        } item_throw;
        
        // Equivalent to ftcmd flags from Melee?

    } command_vars;

    u32 is_hitbox_active : 1;
    u32 is_hitstatus_nodamage : 1;
    u32 is_hurtbox_modify : 1;
    u32 is_modelpart_modify : 1;
    u32 is_texturepart_modify : 1;
    u32 is_reflect : 1; // Fighter's reflect box is active
    s32 lr_reflect : 2;
    u32 is_absorb : 1; // Fighter's absorb box is active
    s32 lr_absorb : 2;
    u32 is_goto_attack100 : 1;
    u32 is_fast_fall : 1;
    u32 x18D_flag_b5 : 1;
    u32 is_check_blastzone : 1;
    u32 is_invisible : 1;

    u32 x18E_flag_b0 : 1;
    u32 x18E_flag_b1 : 1;
    u32 x18E_flag_b2 : 1;
    u32 is_playertag_hide : 1;
    u32 x18E_flag_b4 : 1;
    u32 is_playing_gfx : 1;
    u32 joint_cycle_array_index : 4; // Goes up to 5 by default; index of the array from gfx_joint_cycle_index from ftAttributes which houses the actual joint ID
    u32 is_shield : 1; // Fighter's shield bubble is active
    u32 is_persist_effect : 1; // Destroy GFX on action state change if TRUE, not sure why this and is_playing_gfx are different
    u32 x18F_flag_b4 : 1;
    u32 x18F_flag_b5 : 1;
    u32 is_disable_control : 1;   // Fighter cannot be controlled if TRUE; enabled when training mode menu is up
    u32 is_hitstun : 1;

    u32 slope_contour : 3;
    u32 x190_flag_b3 : 1;
    u32 is_playing_sfx : 1;
    u32 x190_flag_b5 : 1;
    u32 is_show_item : 1;
    u32 x190_flag_b7 : 1;
    u32 x191_flag_b0 : 1;
    u32 is_nullstatus : 1; // Dead / Entry / Appear / Rebirth, ignore hit collisions + blastzones?
    u32 is_damage_resist : 1;
    u32 is_ignore_startbutton : 1;
    u32 camera_mode : 4;
    u32 is_special_interrupt : 1;
    u32 x192_flag_b1 : 1;
    u32 is_catchstatus : 1;
    u32 x192_flag_b3 : 1;
    u32 x192_flag_b4 : 1;
    u32 x192_flag_b5 : 1;
    u32 x192_flag_b6 : 1;
    u32 x192_flag_b7 : 1;
    u8 capture_ignore_mask; // Fighter is immune to these grab types
    u8 catch_mask;          // Fighter's current grab type

    ftAnimFlags anim_flags;

    Vec3f anim_vel;
    f32 ifpos_x;
    f32 ifpos_y;

    struct _input
    {
        void *p_controller; // Controller inputs?
        u16 button_mask_a;
        u16 button_mask_b;
        u16 button_mask_z;
        u16 button_mask_l;
        ftPlayerInput pl;
        ftComputerInput cp;

    } input;

    Fighter_Com fighter_com; // CPU behavior struct

    f32 unk_fighter_0x25C;
    f32 unk_fighter_0x260;
    f32 unk_fighter_0x264;

    u8 tap_stick_x;
    u8 tap_stick_y;
    u8 hold_stick_x;
    u8 hold_stick_y;

    s32 breakout_wait;
    s8 breakout_lr;
    s8 breakout_ud;

    u8 shuffle_frame_index;
    u8 shuffle_index_max;
    u8 is_shuffle_electric;
    u16 shuffle_timer;
    GObj *throw_gobj;
    ftKind throw_ft_kind;
    u8 throw_team;
    u8 throw_player;
    s32 throw_player_number;
    s32 attack_id;
    u16 motion_count;
    gmStatFlags stat_flags;
    u16 stat_count;

    ftHitbox fighter_hit[4];

    s32 invincible_timer;
    s32 intangible_timer;
    s32 special_hitstatus;
    s32 star_invincible_timer;
    s32 star_hitstatus;
    s32 hitstatus;

    ftHurtbox fighter_hurt[11];

    f32 unk_ft_0x7A0;
    f32 hitlag_mul;
    f32 shield_lifeup_wait;
    s32 unk_ft_0x7AC;
    
    s32 attack_damage;
    f32 attack_knockback; 
    u16 attack_hit_count; // Number of times this fighter successfully dealt damage 
    s32 shield_attack_damage;
    f32 attack_rebound;
    s32 lr_attack;
    s32 shield_damage;
    s32 shield_damage_total;
    s32 lr_shield;
    s32 shield_player;
    s32 reflect_damage;
    s32 damage_queue;
    f32 damage_knockback;
    f32 knockback_resist_passive;// Passive armor, always active (?)
    f32 knockback_resist_status; // Resist this many units of knockback, effectively knockback-based armor
    f32 damage_knockback_again;
    s32 damage_taken_recent;
    s32 damage_angle;
    s32 damage_element;
    s32 lr_damage;
    s32 damage_index;
    s32 damage_joint_index;
    s32 damage_player_number;
    s32 damage_player;
    s16 unk_0x810;
    s32 unk_ft_0x814;
    s32 damage_heal;
    f32 damage_mul;

    s32 unk_ft_0x820;
    s32 unk_ft_0x824;
    gmStatFlags damage_stat_flags;
    u16 damage_stat_count;

    f32 publicity_knockback; // Knockback value used for crowd reactions

    GObj *search_gobj;  // GObj this fighter found when searching for grabbable fighters?
    f32 search_gobj_dist;
    void (*proc_catch)(GObj*); // Run this callback on grabbing attacker
    void (*proc_capture)(GObj*, GObj*); // Run this callback on grabbed victim
    GObj *catch_gobj;   // GObj this fighter has caught
    GObj *capture_gobj; // GObj this fighter is captured by
    ftThrowHitDesc *fighter_throw;
    GObj *item_hold;
    ftSpecialHit *special_hit;
    Vec3f entry_pos;

    f32 fighter_cam_zoom_frame;
    f32 fighter_cam_zoom_range;

    gmScriptEvent script_event[2][2];

    DObj *joint[37];

    ftModelPartRenderState joint_render_state[33];
    ftTexturePartRenderState texture_render_state[2];

    ftData *ft_data;
    ftAttributes *attributes;

    void *x9CC;
    void *x9D0;

    void (*proc_update)(GObj*);
    void (*proc_accessory)(GObj*);
    void (*proc_interrupt)(GObj*);
    void (*proc_physics)(GObj*);
    void (*proc_map)(GObj*);
    void (*proc_slope)(GObj*);
    void (*proc_damage)(GObj*);
    void (*proc_trap)(GObj*);
    void (*proc_shield)(GObj*);
    void (*proc_hit)(GObj*);
    void (*proc_gfx)(GObj*);
    void (*proc_lagupdate)(GObj*);
    void (*proc_lagstart)(GObj*);
    void (*proc_lagend)(GObj*);
    void (*proc_status)(GObj*);

    gmSoundEffect *p_sfx;
    u16 sfx_id;
    gmSoundEffect *p_voice;
    u16 voice_id;
    gmSoundEffect *p_loop_sfx;
    u16 loop_sfx_id;

    caStruct colanim;

    u8 unk_0xA8C;
    u8 unk_0xA8D;
    u8 unk_0xA8E;
    u8 unk_0xA8F;

    GfxColorAlpha shade_color;
    ftExplainInput explain_input;

    struct
    {
        u8 is_itemswing;
        s8 render_state;
        u8 desc_index;
        AfterImageDesc desc[3];

    } afterimage;

    union fighter_vars
    {
        ftMario_FighterVars mario;
        ftDonkey_FighterVars donkey;
        ftSamus_FighterVars samus;
        ftLink_FighterVars link;
        ftCaptain_FighterVars captain;
        ftKirby_FighterVars kirby;
        ftPikachu_FighterVars pikachu;
        ftPurin_FighterVars purin;
        ftNess_FighterVars ness;
        ftMasterHand_FighterVars masterhand;

    } fighter_vars;

    s32 hammer_timer;

    union status_vars
    {    
        ftCommon_StatusVars common;
        ftMario_StatusVars mario;
        ftFox_StatusVars fox;
        ftDonkey_StatusVars donkey;
        ftSamus_StatusVars samus;
        ftLink_StatusVars link;
        ftYoshi_StatusVars yoshi;
        ftCaptain_StatusVars captain;
        ftKirby_StatusVars kirby;
        ftPikachu_StatusVars pikachu;
        ftNess_StatusVars ness;
        ftMasterHand_StatusVars masterhand;
        
    } status_vars;

    s32 display_mode;
};

typedef struct Rock_ItemVars
{
    s32 unk_0x0;
    s32 ground_line_id;
    s32 unk_0x8;
    s32 unk_0xC;
    GObj *owner_gobj;

} Rock_ItemVars;

typedef struct Coin_ItemVars
{
    s32 lifetime;

} Coin_ItemVars;

typedef struct Hydro_ItemVars
{
    s32 unk_0x0; // Set to 0 but never used
    s32 unk_0x4; // Set to 0 but never used

} Hydro_ItemVars;

typedef struct Smog_ItemVars
{
    ItemHitDesc *hit_desc;

} Smog_ItemVars;

typedef struct _wpStruct
{
    u32 unk_x0;
    GObj *item_gobj;
    GObj *owner_gobj;
    s32 it_kind;
    u8 team;
    u8 player;
    u8 handicap;
    s32 player_number;
    s32 lr; // lr is unconfirmed; thought to be port owner,
                // but I've seen this compared against "facing direction" at 0x18 which would be silly

    struct wpPhysics
    {
        f32 vel_ground; 
        Vec3f vel_air;

    } phys_info;

    Coll_Data coll_data;
    Ground_Air ground_or_air;
    wpHitbox weapon_hit;

    s32 hit_victim_damage;      // Set to item hitbox's final damage output when hitting a target
    s32 hit_reflect_damage;              // Might be self-damage?
    s32 hit_attack_damage;      // Set to item hitbox's final damage output when hitting another attack
    s32 hit_shield_damage;      // Set to item hitbox's final damage output when hitting a shield
    f32 shield_collide_angle;   // If this is less than 135 degrees, the item gets deflected
    Vec3f shield_collide_vec;   //
    GObj *reflect_gobj;         // GObj that reflected this item
    gmStatFlags reflect_stat_flags;              // Attack flags
    u16 reflect_stat_count;              // Attack flags
    GObj *absorb_gobj;          // GObj that absorbed this item

    u32 is_hitlag_victim : 1;
    u32 is_hitlag_item : 1;

    u32 group_id;
    s32 lifetime; // Frames

    u32 is_camera_follow : 1;
    u32 is_static_damage : 1;

    gmSoundEffect *p_sfx;
    u16 sfx_id;

    sb32 (*proc_update)(GObj*);
    sb32 (*proc_map)(GObj*);
    sb32 (*proc_hit)(GObj*);
    sb32 (*proc_shield)(GObj*);
    sb32 (*proc_hop)(GObj*);
    sb32 (*proc_setoff)(GObj*);
    sb32 (*proc_reflector)(GObj*);
    sb32 (*proc_absorb)(GObj*);
    sb32 (*proc_dead)(GObj*);
    union
    {
        Fireball_ItemVars fireball;
        Charge_Shot_ItemVars charge_shot;
        SamusBomb_ItemVars samus_bomb;
        ThunderJolt_ItemVars thunder_jolt;
        Spin_Attack_ItemVars spin_attack; // Link's Up Special
        Egg_Throw_ItemVars egg_throw;
        Thunder_ItemVars thunder;
        Boomerang_ItemVars boomerang;
        pkthunder_ItemVars pkthunder;
        pkthunder_Trail_ItemVars pkthunder_trail;
        Star_ItemVars star;    
        Rock_ItemVars rock;
        Coin_ItemVars coin;
        Hydro_ItemVars hydro;
        Smog_ItemVars smog;

    } weapon_vars;

    s32 display_state;

} wpStruct;

typedef struct BombHei_ArticleVars
{
    u16 unk_0x0;

} BombHei_ArticleVars;

typedef struct Shell_ArticleVars
{
    u8 damage_all_delay; // Shell can hit owner and teammates once this frame timer reaches -1
    u8 dust_gfx_int; // Delay between dust GFX
    u8 health; // Appears to deterime whether Shell will despawn after hittin a target, shell can have up to 4 HP
    u8 is_damage; // Shell can damage players
    u8 is_setup_vars;
    u8 interact;
    f32 vel_x;

} Shell_ArticleVars;

typedef struct Bumper_ArticleVars
{
    u16 hit_anim_length;
    u16 unk_0x2;
    u16 damage_all_delay;

} Bumper_ArticleVars;

typedef struct Common_ArticleVars
{
    u8 filler[0x24]; // fill 0x24 bytes until all vars are mapped

} Common_ArticleVars;

typedef struct Taru_ArticleVars
{
    f32 roll_rotate_speed;

} Taru_ArticleVars;

typedef struct Gr_Lucky_ArticleVars
{
    Vec3f pos;
    u16 spawn_egg_wait;

} Gr_Lucky_ArticleVars;

typedef struct M_Ball_ArticleVars
{
    u16 is_rebound;
    GObj *owner_gobj;
    GObj *effect_gobj;

} M_Ball_ArticleVars;

typedef struct Pakkun_ArticleVars
{
    Vec3f pos;
    u8 is_wait_fighter;

} Pakkun_ArticleVars;

typedef struct Iwark_ArticleVars
{
    u16 rock_timer1;
    s32 spawn_rock_wait;
    u16 rock_timer2;
    u16 is_rumble;
    u16 rumble_wait;
    u16 spawn_rock_count; 

} Iwark_ArticleVars;

typedef struct Kabigon_ArticleVars
{
    s32 unk_0x0;
    s32 rumble_wait;

} Kabigon_ArticleVars;

typedef struct Tosakinto_ArticleVars
{
    Vec3f pos;

} Tosakinto_ArticleVars;

typedef struct Mew_ArticleVars
{
    s32 esper_gfx_int;

} Mew_ArticleVars;

typedef struct Nyars_ArticleVars
{
    u16 coin_spawn_wait;
    u16 coin_rotate_step;
    u16 model_rotate_wait;

} Nyars_ArticleVars;

typedef struct Lizardon_ArticleVars
{
    s32 unk_0x0;
    s32 unk_0x4;
    s32 unk_0x8;
    u16 turn_wait;
    u16 flame_spawn_wait;

} Lizardon_ArticleVars;

typedef struct Spear_ArticleVars
{
    u16 spear_spawn_count;
    s32 spear_spawn_wait;
    f32 spear_spawn_pos_y;

} Spear_ArticleVars;

typedef struct Kamex_ArticleVars
{
    s32 hydro_spawn_wait;
    f32 hydro_push_vel_x;
    sb32 is_apply_push;

} Kamex_ArticleVars;

typedef struct Mb_Lucky_ArticleVars
{
    u16 egg_spawn_wait;
    u16 lifetime;

} Mb_Lucky_ArticleVars;

typedef struct Starmie_ArticleVars
{
    s32 unk_0x0;
    s32 swift_spawn_wait;
    Vec3f target_pos;
    Vec3f victim_pos;
    f32 add_vel_x;

} Starmie_ArticleVars;

typedef struct Dogas_ArticleVars
{
    Vec3f pos;
    s32 smog_spawn_wait;

} Dogas_ArticleVars;

typedef struct Marumine_ArticleVars
{
    Vec3f offset;

} Marumine_ArticleVars;

typedef struct Porygon_ArticleVars
{
    Vec3f offset;

} Porygon_ArticleVars;

typedef struct Hitokage_ArticleVars
{
    Vec3f offset;
    u16 flags;
    u16 flame_spawn_wait;

} Hitokage_ArticleVars;

typedef struct Fushigibana_ArticleVars
{
    Vec3f offset;
    u16 flags;
    u16 razor_spawn_wait;

} Fushigibana_ArticleVars;

typedef struct Gr_Bomb_ArticleVars
{
    f32 roll_rotate_speed;

} Gr_Bomb_ArticleVars;

typedef struct PK_Fire_ArticleVars
{
    efTransform *effect;

} PK_Fire_ArticleVars;

typedef struct Link_Bomb_ArticleVars
{
    u16 unk_0x0;
    u16 unk_0x2;
    u16 scale_index;
    u16 scale_int;

} Link_Bomb_ArticleVars;

typedef struct itHurtbox
{
    u8 interact_mask;
    gmHitCollisionStatus hitstatus;
    Vec3f offset;
    Vec3f size;

} itHurtbox; // Article Hurtbox, might be larger

typedef struct atCommonAttributes
{
    void *unk_0x0;
    void *unk_0x4;
    void *unk_atca_0x8;
    void *unk_atca_0xC;
    u32 unk_0x10_b0 : 1;
    u32 unk_0x10_b1 : 1;
    u32 unk_0x10_b2 : 1;
    u32 is_give_hitlag : 1;
    u32 is_light : 1;
    s32 hit_offset1_x : 16;
    s16 hit_offset1_y;
    s16 hit_offset1_z;
    s16 hit_offset2_x;
    s16 hit_offset2_y;
    s16 hit_offset2_z;
    Vec3h hurt_offset;
    Vec3h hurt_size;
    s16 objectcoll_top;
    s16 objectcoll_center; 
    s16 objectcoll_bottom;
    s16 objectcoll_width;
    u16 size;
    s32 angle : 10;
    u32 knockback_scale : 10;
    u32 damage: 8;
    u32 element : 4;
    u32 knockback_weight : 10;
    s32 shield_damage : 8;
    u32 hitbox_count : 2;
    u32 clang : 1;
    u32 hit_sfx : 10;
    u32 priority : 3;
    u32 unk_atca_0x3C_b4 : 1;
    u32 unk_atca_0x3C_b5 : 1;
    u32 can_deflect : 1;
    u32 can_reflect : 1;
    u32 can_shield : 1;
    u32 knockback_base : 10;
    u32 unk_atca_0x3C_b3 : 4;
    u32 hitstatus : 4;
    u32 unk_atca_0x3C_b6 : 1;
    u32 unk_atca_0x3C_b7 : 1;
    u32 unk_atca_sfx : 10;
    u32 drop_sfx : 10;
    u32 throw_sfx : 10;
    u32 vel_scale : 9;
    u16 spin_speed;

} atCommonAttributes;

typedef struct ArticleStatusDesc
{
    sb32 (*proc_update)(GObj*);
    sb32 (*proc_map)(GObj*);
    sb32 (*proc_hit)(GObj*);
    sb32 (*proc_shield)(GObj*);
    sb32 (*proc_hop)(GObj*);
    sb32 (*proc_setoff)(GObj*);
    sb32 (*proc_reflector)(GObj*);
    sb32 (*proc_damage)(GObj*);

} ArticleStatusDesc;

// Enums
typedef enum itKind
{
    // Common items
    It_Kind_CommonStart,                        // Start of common item IDs
    It_Kind_Box = It_Kind_CommonStart,          // Crate
    It_Kind_Taru,                               // Barrel
    It_Kind_Capsule,                            // Capsule
    It_Kind_Egg,                                // Egg
    It_Kind_Tomato,                             // Maxim Tomato
    It_Kind_Heart,                              // Heart
    It_Kind_Star,                               // Star Man
    It_Kind_Sword,                              // Beam Sword
    It_Kind_Bat,                                // Home-Run Bat
    It_Kind_Harisen,                            // Fan
    It_Kind_StarRod,                            // Star Rod
    It_Kind_LGun,                               // Ray Gun
    It_Kind_FFlower,                            // Fire Flower
    It_Kind_Hammer,                             // Hammer
    It_Kind_MSBomb,                             // Motion-Sensor Bomb
    It_Kind_BombHei,                            // Bob-Omb
    It_Kind_NBumper,                            // Bumper (Item)
    It_Kind_GShell,                             // Green Shell
    It_Kind_RShell,                             // Red Shell
    It_Kind_MBall,                              // Poké Ball
    It_Kind_CommonMax,                          // End of common item IDs

    // Fighter items
    It_Kind_FighterStart = It_Kind_CommonMax,   // Start of fighter item IDs
    It_Kind_PKFire = It_Kind_FighterStart,      // PK Fire pillar
    It_Kind_LinkBomb,                           // Link's Bomb
    It_Kind_FighterMax,                         // End of fighter item IDs

    // Stage items
    It_Kind_GroundStart = It_Kind_FighterMax,   // Start of stage hazard IDs
    It_Kind_PowerBlock = It_Kind_GroundStart,   // POW block
    It_Kind_GBumper,                            // Bumper (Stage Hazard)
    It_Kind_Pakkun,                             // Pirahna Plant
    It_Kind_Mato,                               // Target
    It_Kind_RBomb,                              // Race to the Finish bomb

    It_Kind_GrMonsterStart,                     // Start of stage Pokémon
    It_Kind_GLucky = It_Kind_GrMonsterStart,    // Chansey (Saffron City)
    It_Kind_Marumine,                           // Electrode
    It_Kind_Hitokage,                           // Charmander
    It_Kind_Fushigibana,                        // Venusaur
    It_Kind_Porygon,                            // Porygon
    It_Kind_GrMonsterMax = It_Kind_Porygon,     // End of stage Pokémon IDs

    It_Kind_GroundMax,                          // End of stage hazard IDs

    // Pokémon
    It_Kind_MbMonsterStart = It_Kind_GroundMax, // Start of Pokémon item IDs
    It_Kind_Iwark = It_Kind_MbMonsterStart,     // Onix
    It_Kind_Kabigon,                            // Snorlax
    It_Kind_Tosakinto,                          // Goldeen
    It_Kind_Nyars,                              // Meowth
    It_Kind_Lizardon,                           // Charizard
    It_Kind_Spear,                              // Beedrill
    It_Kind_Kamex,                              // Blastoise
    It_Kind_MLucky,                             // Chansey (Poké Ball)
    It_Kind_Starmie,                            // Starmie
    It_Kind_Sawamura,                           // Hitmonlee
    It_Kind_Dogas,                              // Koffing
    It_Kind_Pippi,                              // Clefairy
    It_Kind_Mew,                                // Mew
    It_Kind_MbMonsterMax = It_Kind_Mew,         // End of Pokémon item IDs

    It_Kind_EnumMax                             // End of all item IDs

} itKind;

typedef struct itStruct // Common items, stage hazards and Pokémon
{
    void *ip_alloc_next;
    GObj *item_gobj;
    GObj *owner_gobj;
    s32 it_kind;
    s32 type;
    u8 team;
    u8 player;
    u8 handicap;
    s32 player_number;
    s32 percent_damage;
    u32 hitlag_timer;
    s32 lr;

    struct
    {
        f32 vel_ground;
        Vec3f vel;

    } phys_info;

    Coll_Data coll_data;

    Ground_Air ground_or_air;

    itHitbox item_hit;
    itHurtbox item_hurt;

    s32 hit_normal_damage;              // Damage applied to entity this item has hit
    s32 lr_attack;                      // Direction of outgoing attack?
    s32 hit_refresh_damage;             // Damage applied to entity this item has hit, if rehit is possible?
    s32 hit_attack_damage;              // Damage item dealt to other attack

    s32 hit_shield_damage;              // Damage item dealt to shield
    f32 shield_collide_angle;           // Angle at which item collided with shield?
    Vec3f shield_collide_vec;           // Position of shield item collided with? (Update: only Z axis appears to be used, can be 0, -1 or 1 depending on attack direction

    GObj *reflect_gobj;                 // GObj that reflected this item
    gmStatFlags reflect_stat_flags;     // Status flags of GObj reflecting this item (e.g. is_smash_attack, is_ground_or_air, is_special_attack, etc.)
    u16 reflect_stat_count;             // Status update count at the time the item is reflected?

    s32 damage_highest;                 // I don't know why there are at least two of these
    f32 damage_knockback;               // Item's calculated knockback
    s32 damage_queue;                   // Used to calculate knockback?
    s32 damage_angle;                   // Angle of attack that hit the item
    s32 damage_element;                 // Element of attack that hit the item
    s32 lr_damage;                      // Direction of incoming attack
    GObj *damage_gobj;                  // GObj that last dealt damage to this item?
    u8 damage_team;                     // Team of attacker
    u8 damage_port;                     // Controller port of attacker
    s32 damage_player_number;           // Player number of attacker
    u8 damage_handicap;                 // Handicap of attacker
    s32 damage_display_mode;            // Display mode of attacker which the item takes on
    s32 damage_lag;                     // Used to calculate hitlag?

    s32 lifetime;                       // Item's duration in frames

    f32 vel_scale;                      // Scale item's velocity

    u16 unk_sfx;                        // Unused?
    u16 drop_sfx;                       // SFX to play when item is dropped?
    u16 throw_sfx;                      // SFX to play when item is thrown?

    u32 is_allow_pickup : 1;            // Bool to check whether item can be picked up or not
    u32 is_hold : 1;                    // I think this is used to tell if a fighter is holding this article?
    u32 times_landed : 2;               // Number of times item has touched the ground when landing, used to tell how many times item should bounce up
    u32 times_thrown : 3;               // Number of times item has been dropped or thrown by player; overflows after 7
    u32 weight : 1;                     // 0 = item is heavy, 1 = item is light
    u32 is_damage_all : 1;              // Item ignores ownership and can damage anything?
    u32 is_attach_surface : 1;          // Item is "sticking" to a collision line specified by attach_line_id
    u32 is_thrown : 1;                  // Apply magnitude and stale multiplier to damage output
    u16 attach_line_id;                 // Line ID that item is attached to
    u32 pickup_wait : 12;               // Number of frames item can last without being picked up (if applicable)
    u32 is_allow_knockback : 1;         // Item can receive knockback velocity?
    u32 is_unused_item_bool : 1;        // Unused? Set various times, but no item process makes use of it
    u32 is_static_damage : 1;           // Ignore reflect multiplier if TRUE

    atCommonAttributes *attributes;

    caStruct colanim;

    u32 is_hitlag_victim : 1;           // Item can deal hitlag to target

    u16 it_multi;                       // Some sort of universal multi-purpose variable, e.g. it is used as intangibility delay for Star Man and ammo count for Ray Gun
    u32 item_event_index : 4;           // Item hitbox script index? When in doubt, make this u8 : 4

    f32 rotate_speed;

    GObj *indicator_gobj;
    u8 indicator_timer;

    union
    {    
        BombHei_ArticleVars bombhei;
        Shell_ArticleVars shell;
        Taru_ArticleVars taru;
        Bumper_ArticleVars bumper;
        Gr_Lucky_ArticleVars gr_lucky;
        M_Ball_ArticleVars m_ball;
        Pakkun_ArticleVars pakkun;
        Iwark_ArticleVars iwark;
        Kabigon_ArticleVars kabigon;    
        Tosakinto_ArticleVars tosakinto;
        Mew_ArticleVars mew;
        Nyars_ArticleVars nyars;
        Lizardon_ArticleVars lizardon;
        Spear_ArticleVars spear;
        Kamex_ArticleVars kamex;
        Mb_Lucky_ArticleVars mb_lucky;
        Starmie_ArticleVars starmie;
        Dogas_ArticleVars dogas;
        Marumine_ArticleVars marumine;
        Porygon_ArticleVars porgyon;
        Hitokage_ArticleVars hitokage;
        Fushigibana_ArticleVars fushigibana;
        Gr_Bomb_ArticleVars gr_bomb;
        PK_Fire_ArticleVars pk_fire;
        Link_Bomb_ArticleVars link_bomb;

    } article_vars;

    s32 display_state;

    sb32(*proc_update)(GObj *);
    sb32(*proc_map)(GObj *);
    sb32(*proc_hit)(GObj *);
    sb32(*proc_shield)(GObj *);
    sb32(*proc_hop)(GObj *);
    sb32(*proc_setoff)(GObj *);
    sb32(*proc_reflector)(GObj *);
    sb32(*proc_damage)(GObj *);
    sb32(*proc_dead)(GObj *);

} itStruct;

typedef struct grDObjIndex
{
    u8 grdobj_id1, grdobj_id2, grdobj_id3;

} grDObjIndex;

typedef struct _grHitbox
{
    s32 env_kind;
    s32 damage;
    s32 angle;
    s32 knockback_scale;
    s32 knockback_weight;
    s32 knockback_base;
    s32 element;

} grHitbox;

typedef enum grKind
{
    Gr_Kind_CommonStart,
    Gr_Kind_VSStart = Gr_Kind_CommonStart,
    Gr_Kind_Castle = Gr_Kind_VSStart, // Peach's Castle
    Gr_Kind_Sector,
    Gr_Kind_Jungle,
    Gr_Kind_Zebes,
    Gr_Kind_Hyrule,
    Gr_Kind_Yoster, // Yoshi's Island
    Gr_Kind_Pupupu, // Dream Land
    Gr_Kind_Yamabuki, // Saffron City
    Gr_Kind_Inishie, // Mushroom Kingdom
    Gr_Kind_VSEnd = Gr_Kind_Inishie,
    Gr_Kind_PPPTest1,
    Gr_Kind_PPPTest2,
    Gr_Kind_Explain, // How to Play
    Gr_Kind_Yoster1P, // Small Yoshi's Island
    Gr_Kind_Crystal, // Meta Crystal
    Gr_Kind_Duel, // Duel Zone
    Gr_Kind_Bonus3, // Race to the Finish
    Gr_Kind_Last, // Final Destination
    Gr_Kind_CommonEnd = Gr_Kind_Last,

    Gr_Kind_BonusGameStart,
    Gr_Kind_Bonus1Start = Gr_Kind_BonusGameStart, // Start of Target Test stages
    Gr_Kind_Bonus1Mario = Gr_Kind_Bonus1Start,
    Gr_Kind_Bonus1Fox,
    Gr_Kind_Bonus1Donkey,
    Gr_Kind_Bonus1Samus,
    Gr_Kind_Bonus1Luigi,
    Gr_Kind_Bonus1Link,
    Gr_Kind_Bonus1Yoshi,
    Gr_Kind_Bonus1Captain,
    Gr_Kind_Bonus1Kirby,
    Gr_Kind_Bonus1Pikachu,
    Gr_Kind_Bonus1Purin,
    Gr_Kind_Bonus1Ness,
    Gr_Kind_Bonus1End = Gr_Kind_Bonus1Ness,

    Gr_Kind_Bonus2Start, // Start of Board the Platforms stages
    Gr_Kind_Bonus2Mario = Gr_Kind_Bonus2Start,
    Gr_Kind_Bonus2Fox,
    Gr_Kind_Bonus2Donkey,
    Gr_Kind_Bonus2Samus,
    Gr_Kind_Bonus2Luigi,
    Gr_Kind_Bonus2Link,
    Gr_Kind_Bonus2Yoshi,
    Gr_Kind_Bonus2Captain,
    Gr_kind_Bonus2Kirby,
    Gr_Kind_Bonus2Pikachu,
    Gr_Kind_Bonus2Purin,
    Gr_Kind_Bonus2Ness,
    Gr_Kind_Bonus2End = Gr_Kind_Bonus2Ness,
    Gr_Kind_BonusGameEnd = Gr_Kind_Bonus2End

} grKind;

typedef struct grPupupuEffect
{
    Vec3f pos;
    f32 rotate;

} grPupupuEffect;

typedef struct grPupupuDustEffect
{
    Vec3f pos;

} grPupupuDustEffect;

typedef enum grPupupuWhispyWindStatus
{
    grPupupu_WhispyWind_Default,
    grPupupu_WhispyWind_Wait,
    grPupupu_WhispyWind_Turn,
    grPupupu_WhispyWind_Open,
    grPupupu_WhispyWind_Blow,
    grPupupu_WhispyWind_Stop

} grPupupuWhispyWindStatus;

typedef enum grPupupuWhispyEyesStatus
{
    grPupupu_WhispyEyes_Turn

} grPupupuWhispyEyesStatus;

typedef enum grPupupuWhispyMouthStatus
{
    grPupupu_WhispyMouth_Stretch,
    grPupupu_WhispyMouth_Turn,
    grPupupu_WhispyMouth_Open

} grPupupuWhispyMouthStatus;

typedef enum grPupupuFlowerStatus
{
    grPupupu_Flower_Default,
    grPupupu_Flower_WindStart,
    grPupupu_Flower_WindLoopStart,
    grPupupu_Flower_WindLoop,
    grPupupu_Flower_WindLoopEnd,
    grPupupu_Flower_WindStop

} grPupupuFlowerStatus;

typedef struct grCommon_GroundVars_Pupupu
{
    void *map_head;
    GObj *map_gobj[4];
    s32 effect_bank_index;
    efTransform *leaves_eftrans;
    efTransform *dust_eftrans;
    u16 whispy_wind_wait;
    u16 whispy_wind_duration;
    s16 whispy_blink_wait;
    u8 whispy_status;
    u8 flowers_back_wait;
    u8 flowers_front_wait;
    u8 rumble_wait;
    s8 lr_players;
    u8 flowers_back_status;
    u8 flowers_front_status;
    s8 whispy_eyes_status;
    s8 whispy_mouth_status;
    s8 unk_pupupu_0xF;
    s8 unk_pupupu_0x10;

} grCommon_GroundVars_Pupupu;

typedef struct grCommon_GroundVars_Sector
{
    void *map_head;
    GObj *map_gobj;
    DObj *unk_sector_0x8;
    DObj *unk_sector_0xC;
    DObj *unk_sector_0x10;
    DObj *unk_sector_0x14;
    DObj *unk_sector_0x18;
    DObj *unk_sector_0x1C;
    u8 filler_0x18[0x24 - 0x20];
    DObj *unk_sector_0x24;
    DObj *unk_sector_0x28;
    DObj *unk_sector_0x2C;
    DObj *unk_sector_0x30;
    DObj *unk_sector_dobj;
    void *unk_sector_0x38;
    void *unk_sector_0x3C;
    f32 arwing_target_x;
    u16 arwing_appear_timer;
    u16 arwing_state_timer;
    u8 arwing_status;
    s8 unk_sector_0x49;
    u8 arwing_type_cycle;
    u8 arwing_laser_ammo;
    s8 unk_sector_0x4C;
    s8 unk_sector_0x4D;
    u16 unk_sector_0x4E;
    u16 arwing_laser_timer;
    u8 unk_sector_0x52;
    s8 arwing_pilot_current; // Line IDs?
    s8 arwing_pilot_prev;
    u8 arwing_laser_count; // Laser shot count? e.g. if set to 2, the arwing will fire 2 lasers at once (though this is hardcoded to fire two shots in the weapon make function)
    u8 unk_sector_0x56;
    u8 unk_sector_0x57;
    u8 is_arwing_line_active;
    u8 unk_sector_0x59;

} grCommon_GroundVars_Sector;

typedef struct grZebesAcid
{
    u16 acid_random_add;
    u16 acid_random1, acid_random2;
    f32 acid_level;

} grZebesAcid;

typedef struct grCommon_GroundVars_Zebes
{
    void *map_head;
    GObj *map_gobj;
    void *hitbox_head;
    f32 acid_level_current;
    f32 acid_level_step;
    u16 acid_level_wait;
    u8 acid_status;
    u8 acid_level_index;
    u8 rumble_wait;

} grCommon_GroundVars_Zebes;

typedef struct grYosterCloud
{
    GObj *gobj;
    DObj *dobj[3];
    f32 altitude;
    f32 pressure; // 0x18
    u8 status;
    s8 anim_id;
    u8 is_cloud_line_active;
    s8 pressure_timer;
    u8 evaporate_wait; // 0x20

} grYosterCloud;

typedef struct grCommon_GroundVars_Yoster
{
    void *map_head;
    grYosterCloud clouds[3];
    s32 cloud_gfx_id;

} grCommon_GroundVars_Yoster;

typedef struct grInishieScale
{
    DObj *platform_dobj;
    DObj *string_dobj;
    f32 string_length;
    f32 platform_base_y;

} grInishieScale;

typedef struct grCommon_GroundVars_Inishie
{
    void *map_head;
    void *item_head;
    grInishieScale scale[2];
    f32 splat_altitude;         // Scale platform uh... thing I don't know how to explain, splat_accelerate gets added to this
    f32 splat_accelerate;       // Scale platform fall acceleration
    u16 splat_wait;             // Wait this many frames before retracting if the platforms have falle
    u8 splat_status;            // Current state of the platforms
    u8 players_tt[4];           // Players timer, something to do with being grounded/airborne
    u8 players_ga[4];           // Players ground or air
    GObj *pblock_gobj;
    grHitbox *gr_hit;
    u16 pblock_appear_wait;
    u8 pblock_pos_count;
    u8 *pblock_pos_ids;
    u8 pblock_status;
    GObj *pakkun_gobj[2];

} grCommon_GroundVars_Inishie;

typedef struct grCommon_GroundVars_Jungle
{
    void *map_head;
    GObj *tarucann_gobj;
    u8 tarucann_status;
    u16 tarucann_wait;
    f32 tarucann_rotate_step;

} grCommon_GroundVars_Jungle;

typedef struct grCommon_GroundVars_Hyrule
{
    void *map_head;
    GObj *twister_gobj;
    efTransform *twister_eftrans;
    f32 twister_leftedge_x;
    f32 twister_rightedge_x;
    f32 twister_vel;
    u8 *twister_pos_ids;
    s32 effect_bank_index;
    u16 twister_wait;
    u16 twister_speed_wait;
    u16 twister_turn_wait;
    u16 twister_line_id;
    u8 twister_status;
    u8 twister_pos_count;

} grCommon_GroundVars_Hyrule;

typedef struct grCommon_GroundVars_Yamabuki
{
    void *map_head;
    void *item_head;
    GObj *monster_gobj;
    GObj *gate_gobj;
    Vec3f gate_pos;
    u8 gate_status;
    u8 is_gate_deny_entry;
    u16 monster_wait;
    u16 gate_wait;
    u8 monster_id_prev;

} grCommon_GroundVars_Yamabuki;

typedef struct grCommon_GroundVars_Castle
{
    void *map_head;
    void *item_head;
    GObj *bumper_gobj;
    Vec3f bumper_pos;

} grCommon_GroundVars_Castle;

typedef struct grBonus_GroundVars_Bonus1
{
    u8 filler_0xC[0xC];
    u8 target_count;
    u8 unk_bonus1_0xD;
    u8 unk_bonus1_0xE;
    u8 unk_bonus1_0xF;
    u8 unk_bonus1_0x10;

} grBonus_GroundVars_Bonus1;

typedef struct grBonus_GroundVars_Bonus2
{
    void *unk_bonus2_0x0;
    void *unk_bonus2_0x4;
    void *unk_bonus2_0x8;
    GObj *unk_bonus2_gobj;
    u8 platform_count;

} grBonus_GroundVars_Bonus2;

typedef struct grBonus_GroundVars_Bonus3
{
    void *map_head;
    void *item_head;
    Vec3f rbomb_make_pos;
    s32 rbomb_make_wait;

} grBonus_GroundVars_Bonus3;

typedef union grStruct
{   
    grBonus_GroundVars_Bonus1 bonus1;
    grBonus_GroundVars_Bonus2 bonus2;
    grBonus_GroundVars_Bonus3 bonus3;
    grCommon_GroundVars_Castle castle;
    grCommon_GroundVars_Yamabuki yamabuki;
    grCommon_GroundVars_Hyrule hyrule;
    grCommon_GroundVars_Jungle jungle;
    grCommon_GroundVars_Inishie inishie;
    grCommon_GroundVars_Yoster yoster;
    grCommon_GroundVars_Zebes zebes;
    grCommon_GroundVars_Sector sector;
    grCommon_GroundVars_Pupupu pupupu;

} grStruct;

extern grStruct gGroundStruct;

typedef struct grRenderDesc
{
    void *unk_grrender_0x0;
    void *unk_grrender_0x4;
    u8 unk_grrender_0x8;
    void *gobjproc;

} grRenderDesc;

typedef struct ifCharacter
{
    Vec2f pos;
    Vec2f vel;
    u8 image_id; // e.g. the % display is set to 0x0A
    u8 is_lock_movement;

} ifCharacter;

typedef struct ifPlayerDamage
{
    s32 damage;
    s32 pos_adjust_wait; // Wait this many frames before snapping numbers back to original position?
    s32 flash_reset_wait; // Frames until damage display's white flash is reset; tied to pos_adjust_wait?
    f32 scale;
    ifCharacter chars[4];
    GObj *interface_gobj;   // Fighter whom this HUD is assigned to
    u8 color_id;    // ??? This changes the damage HUD's color to white if set to 4
    u8 is_update_anim;
    u8 char_display_count;
    u8 break_anim_frame;
    u8 dead_stopupdate_wait;
    u8 is_display_interface;

} ifPlayerDamage;

ifPlayerDamage gPlayerDamageInterface[4];

typedef struct ifPlayerMagnify
{
    Vec2f pos;
    Vp viewport;
    GObj *interface_gobj;
    u8 color_id;

} ifPlayerMagnify;

ifPlayerMagnify D_ovl2_80131748[4];

ifPlayerMagnify gPlayerMagnifyInterface[4];

typedef struct ifACharacter
{
    Vec2h pos;
    intptr_t offset;

} ifACharacter;

extern void *D_ovl2_80130D40[], *gCommonSpriteFiles[];

typedef struct ifStartLamp // This is exclusively for the color of the countdown lamps, the black main body is not included
{
    Vec2h pos;
    u8 color_id;

} ifStartLamp;

extern ifStartLamp ifStart_TrafficLamp_SpriteData[];

extern u8 D_ovl2_8012ECCC[2];
extern u8 D_ovl2_8012ECD0[2];
extern u8 D_ovl2_8012ECD4[2];
extern u8 D_ovl2_8012ECD8[2];
extern u8 D_ovl2_8012ECDC[2];
extern u8 D_ovl2_8012ECE0[2];

typedef struct ifPauseIcon
{
    intptr_t offset;
    Vec2h pos;
    GfxColor sprite_color;
    GfxColor sobj_color;

} ifPauseIcon;

#define gmRumbleEventAdvance(event, type)                                       \
((event) = (void*) ((uintptr_t)(event) + (sizeof(type))))   \

#define gmRumbleEventCast(event, type)                                          \
((type*) (event))                                                               \

// WARNING: Only advances 2 bytes at a time
#define gmRumbleEventCastAdvance(event, type)                                   \
((type*) (event)++)                                                             \

typedef enum gmRumbleEventKind
{
    gmRumbleEvent_Kind_SetScript,
    gmRumbleEvent_Kind_StartRumble,
    gmRumbleEvent_Kind_StopRumble,
    gmRumbleEvent_Kind_LoopBegin,
    gmRumbleEvent_Kind_LoopEnd

} gmRumbleEventKind;

typedef struct gmRumbleEventDefault
{
    u16 opcode : 3;
    u16 param : 13;

} gmRumbleEventDefault;

typedef struct gmRumbleEvent
{
    u8 index;
    u8 is_rumble_active;
    u16 rumble_status;
    u16 loop_count;
    s32 unk_rumble_0x8;
    void *p_goto;
    gmRumbleEventDefault *p_script;

} gmRumbleEvent;

typedef struct gmRumbleLink gmRumbleLink;

struct gmRumbleLink
{
    gmRumbleEvent *p_event;
    gmRumbleLink *rnext;
    gmRumbleLink *rprev;
};

typedef struct gmRumblePlayer
{
    u8 is_active;
    gmRumbleLink *rlink;

} gmRumblePlayer;

typedef struct gmRumbleLinkArray
{
    gmRumbleLink grumble[3];

} gmRumbleLinkArray;

typedef struct gmRumbleEventArray
{
    gmRumbleEvent r_event[3];

} gmRumbleEventArray;

void func_ovl0_800CE040(s32, s32);                         /* extern */
GObj* func_ovl0_800CE418(s32);                          /* extern */
GObj* func_ovl0_800D2758(s32);                          /* extern */
GObj* D_ovl2_80131A10;
GObj* D_ovl2_80131A14;
s32 D_ovl2_80131A18;
s32 D_ovl2_80131A20[7];

typedef struct Unk800D4060
{
    u32 unk_b0 : 1;

} Unk800D4060;

extern ftSpawnInfo D_ovl2_80116DD0;
extern Unk800D4060 D_ovl4_8018E3D0;
extern void func_ovl2_80114D98();

#define grGetStruct(ground_gobj) \
((grStruct*)(ground_gobj)->user_data) \

#define itGetStruct(article_gobj) \
((itStruct*)article_gobj->user_data) \

#define ArticleGetPData(ap, off1, off2) \
( (void*) ( ((uintptr_t)ap->attributes->unk_0x0 - (intptr_t)&off1 ) + (intptr_t)&off2) ) \

#define ftGetStruct(fighter_gobj) \
((ftStruct*)fighter_gobj->user_data) \

#define ifGetPlayer(interface_gobj) \
((s32)(interface_gobj)->user_data)  \

#define ifSetPlayer(interface_gobj, player)     \
((interface_gobj)->user_data = (void*)(player)) \

#define ifGetSObj(interface_gobj)    \
((SObj*)(interface_gobj)->user_data) \

#define ifSetSObj(interface_gobj, sobj)       \
((interface_gobj)->user_data = (SObj*)(sobj)) \

#define ifGetProc(interface_gobj)			   \
((void (*)(void)) (interface_gobj)->user_data) \

#define ifSetProc(interface_gobj, proc)					\
((interface_gobj)->user_data = (void (*)(void)) (proc)) \

#define wpGetStruct(item_gobj) \
((wpStruct*)item_gobj->user_data) \

#define efGetStruct(effect_gobj) \
((efStruct*)effect_gobj->user_data) \

#define DObjGetStruct(gobj) \
((DObj*)gobj->obj) \

#define SObjGetStruct(gobj) \
((SObj*)(gobj)->obj) \

#define OMCameraGetStruct(gobj) \
((OMCamera*)(gobj)->obj) \

#define AttributesGetStruct(fp) \
((ftAttributes*)fp->attributes)

#define FighterGetJoint(fp, id) \
((DObj*)fp->joint[id]) \

#define FighterCalcLandingLag(anim_length, target_length) \
((f32)anim_length / target_length) \


void func_ovl0_800C8CB8(void*, void*, void*, void*, f32);      /* extern */
void func_ovl0_800C8DB4(void*, void*, u8, void*, s32, s32, s32, s32, f32, s32); /* extern */
void func_ovl1_80390584(GObj*);                     /* extern */
void func_ovl1_803905CC(GObj*, s32);                     /* extern */
ftStruct* func_ovl2_800D7594();                         /* extern */
ftParts* func_ovl2_800D7604();                         /* extern */
void func_ovl2_800D79F0(GObj*, void*);                 /* extern */
void func_ovl2_800E1260(GObj*);                     /* extern */
void func_ovl2_800E2604(GObj*);                     /* extern */
void func_ovl2_800E2660(GObj*);                     /* extern */
void func_ovl2_800E6100(GObj*);                     /* extern */
void func_ovl2_800E6178(GObj*);                     /* extern */
void func_ovl2_800E61EC(GObj*);                     /* extern */
void ftCommon_ResetControllerInputs(GObj*);                        /* extern */
// void func_ovl2_800EB6EC(void*);                        /* extern */
void func_ovl3_8013D930(GObj*);                        /* extern */
void func_unkmulti_8013A8A8(GObj*);                    /* extern */
void func_unkmulti_8013AC00(GObj*);                    /* extern */
void func_unkmulti_8013BB88(GObj*);                    /* extern */

// Interface
void ifPlayer_Damage_InitInterface(void);
s32 ifPlayer_Damage_GetSpecialArrayID(s32 damage, u8 *digits);

// Fighter functions

void ftStatus_Update(GObj *fighter_gobj, s32 status_id, f32 frame_begin, f32 anim_rate, u32 flags); // Action State Change
void func_ovl3_801438F0(GObj *fighter_gobj, f32 aerial_drift, sb32 unk1, sb32 is_custom_gravity, sb32 unk2, f32 landing_lag, sb32 can_interrupt); // FallSpecial Action State
sb32 func_ovl2_800DDE84(GObj*, void(*proc_map)(GObj*)); // Grounded Collision check (stop at ledge?)
sb32 func_ovl2_800DE80C(GObj*, void(*proc_map)(GObj*)); // Aerial Collision check (ledge grab?)
sb32 func_ovl2_800D9480(GObj*, void(*proc_map)(GObj*));
sb32 func_ovl2_800DDDDC(GObj*, void(*proc_map)(GObj*));                           
sb32 func_ovl2_800DE6E4(GObj*, void(*proc_map)(GObj*));                           
sb32 func_ovl2_800DE87C(GObj*);
sb32 func_ovl2_800DE8B0(GObj*);
sb32 func_ovl2_80101ED8(GObj *fighter_gobj);
void ftMapCollide_SetGround(ftStruct*); // ???
void func_ovl2_800D8EB8(ftStruct*); // ???
void ftMapCollide_SetAir(ftStruct*); // ???
void ftCommon_StickInputSetLR(ftStruct*);
void func_ovl2_800E853C(ftStruct*, s32);
void func_ovl2_800D8BB4(GObj*);                             
void func_ovl2_800D8FC8(ftStruct*, s32, f32, f32);    
sb32 ftCommon_CheckSetColAnimIndex(GObj*, s32, s32);
void func_ovl2_800DDF44(GObj*);                             
void func_ovl2_800DE724(GObj*);                       
void func_ovl2_800D8938(ftStruct*, f32);
void func_ovl2_800D8E78(ftStruct*, f32); 
sb32 func_ovl2_800DE798(GObj*, void (*proc_map)(GObj*));         
void ftCommon_SetCatchVars(ftStruct*, u8, void(*proc_catch)(GObj*), void(*proc_capture)(GObj*, GObj*));
void func_ovl2_800E9C3C(GObj*);
sb32 func_ovl2_80102418(GObj*);
sb32 func_ovl2_80102490(GObj*);
sb32 func_ovl2_80102508(GObj*);
sb32 func_ovl2_80102560(GObj*);
void* func_ovl2_801008F4(s32);
GObj* func_ovl2_801020F4(GObj*);
sb32 func_ovl2_80101F84(GObj*);
efParticle* func_ovl2_801042B4(GObj*);
void func_ovl3_80142E3C(GObj*, s32, f32);  
void func_ovl3_8014B968(GObj*, GObj*);
void func_ovl3_80144C24(GObj*);                  
void jtgt_ovl2_800D9414(GObj*);
void func_ovl2_800D8C14(GObj*);
void func_ovl2_800D93E4(GObj*);
void func_ovl2_800D94C4(GObj*);
void func_ovl2_800D94E8(GObj*);
void ftAnim_Update(GObj*); // ???
void func_ovl2_800DE324(GObj*);
void func_ovl2_800D87D0(GObj*); 
void func_ovl2_800DE348(GObj*);
sb32 func_ovl2_800E9814(GObj*, s32, s32);
s32 func_ovl2_800E9AF4(GObj*, s32);
void func_ovl2_800D91EC(GObj*);
void func_ovl2_800DE958(GObj*);
void func_ovl2_800DE978(GObj*);
void func_ovl2_800E9C8C(GObj*); // GFX_PauseAll
void func_ovl2_800E9CC4(GObj*); // GFX_ResumeAll
void func_ovl3_8013E1C8(GObj*);
void func_ovl3_8013F9E0(GObj*);
void func_ovl2_800DEE54(GObj*);                        /* extern */
sb32 func_ovl2_800FC8EC(s32);                          /* extern */
void func_ovl2_800FC900(s32, s32, s32*);
void func_ovl2_800DF09C(GObj*, Vec3f*, Coll_Data*);            /* extern */
void ftCommon_StopLoopSFX(ftStruct*);                    /* extern */
void func_ovl2_800EA5E8(ftStruct*, s32);                     /* extern */
// void func_ovl2_800EA778(ftStruct*, u16);                   /* extern */
void func_ovl2_800EA7B0(ftStruct*, u16);                     /* extern */
void func_ovl3_8014D0F0(GObj*, GObj*, Vec3f*);
void func_ovl3_8014ADB0(GObj*);
void jtgt_ovl2_800D9160(GObj*);
sb32 func_ovl2_800F3DD8(s32, Vec3f*, f32*, void*, Vec3f*);
void func_ovl2_800F4408(s32, Vec3f*);                    /* extern */
void func_ovl2_800F4428(s32, Vec3f*);                    /* extern */
f32 func_ovl2_800EBB3C(Vec3f*, Vec3f*, Vec3f*);         /* extern */
void func_ovl2_800EE018(void*, Vec3f*);                  /* extern */
void func_ovl2_800E8A24(GObj*, s32);
void* func_800269C0(u16);                                 /* extern */
void func_ovl2_800E8EAC(GObj*, s32, s16);                /* extern */
void func_ovl2_800E8ECC(GObj*);                        /* extern */
sb32 func_ovl2_800DDDA8(GObj*);
sb32 func_ovl2_800DE6B0(GObj*);
void ftCommon_ThrownUpdateEnemyInfo(ftStruct*, GObj*);
void func_ovl3_8014C508(GObj*);
f32 func_ovl2_800E9D78(s32, s32, s32, s32, s32, s32, f32, s32, s32);
void func_ovl2_800EA248(ftStruct*, s32);
s32 func_ovl2_800EA54C(u32, s32, s32, u16);
void func_ovl2_800EA614(s32, s32, s32, u16);
void func_ovl2_800EA98C(s32, s32, s32);
void func_ovl3_801415F8(GObj*, f32, s32);
sb32 func_ovl3_8014935C(GObj*);                           /* extern */
void func_ovl3_8014C6AC(GObj*);
void func_ovl2_800D8978(ftStruct*, f32);
void func_ovl2_800D8D68(ftStruct*, f32, f32);         
void func_ovl2_800D8ADC(ftStruct*, f32, f32);
void ftCommon_SetCaptureFlags(ftStruct*, u8);
void func_ovl2_800D8DA0(ftStruct*, ftAttributes*);
sb32 func_ovl2_800D8FA8(ftStruct*, ftAttributes*);               
void func_ovl2_800D9074(ftStruct*, ftAttributes*);                 
void func_ovl2_800D8E50(ftStruct*, ftAttributes*); 
sb32 func_ovl2_800D8EDC(ftStruct*, f32);
void func_ovl2_800EB528(DObj*);
void func_ovl2_800EDF24(DObj*, Vec3f*); 
void* func_ovl2_800FF648(Vec3f*, f32);                       /* extern */
void ftCommon_PlayLoopSFXStoreInfo(ftStruct*, u16);            /* extern */
Vec3f* func_ovl3_80131B44(ftStruct*, s32);
void func_ovl2_800D7994(GObj*);                        /* extern */
void ftCommon_ProcDamageStopVoice(GObj*);                             /* extern */
void func_ovl3_8014AF2C(GObj*);                        /* extern */
void func_ovl2_800D9444(GObj*);                             /* extern */
void func_ovl3_8013BC60(u16);                          /* extern */
void func_ovl3_8013BC8C(ftStruct*);                        /* extern */
void func_ovl3_8013BD64(ftStruct*);                        /* extern */
void func_ovl3_8013C050(GObj*);                        /* extern */
void func_ovl3_8013C0B0(GObj*);                        /* extern */
void func_ovl3_8013C120(GObj*);                        /* extern */
void func_ovl3_8013BF94(GObj*);                          /* extern */
void func_ovl2_800E7F7C(GObj*, s32);                     /* extern */
void func_ovl2_800E827C(GObj*, u8);                     /* extern */
void func_ovl2_800E98B0(GObj*);                        /* extern */
void func_ovl2_800D79F0(GObj*, void*);                    /* extern */
sb32 func_ovl2_80104068(GObj*, s32);                 /* extern */
void func_ovl2_8010F840(ftStruct*);
void func_ovl2_800EA8EC(ftStruct*, s32);                       /* extern */
void func_ovl2_801102B0(s32, s32);
sb32 func_ovl2_800F3794(GObj*);                           /* extern */
void func_ovl2_800F3938(GObj*);                        /* extern */
void func_ovl2_800D8A70(ftStruct*, f32, f32);
void func_ovl2_800D9044(ftStruct*, ftAttributes*);
void func_ovl2_800D9260(ftStruct*, f32*, f32*, f32*);
// void func_ovl2_800EABDC(GObj*, s32, s32, Vec3f*, Vec3f*, s32, s32, s32);
void func_ovl3_80140EE4(GObj*, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
void func_ovl3_801499A4(GObj*);
s32 func_ovl2_800EA1C0(s32, s32, f32);       /* extern */
s32 func_ovl3_80140D30(void*);               /* extern */
void func_ovl3_80140E2C(GObj*);                        /* extern */
s32 func_ovl3_80140EC0(void*);               /* extern */
void func_ovl3_80141560(GObj*);                        /* extern */
void func_ovl3_80141648(GObj*);                 /* extern */
void func_ovl3_8014AECC(GObj*, GObj*);                 /* extern */
void func_ovl3_8014B2AC(void*);                        /* extern */
void func_ovl3_8014B330(GObj*);                        /* extern */
void func_ovl3_8014B5B4(GObj*);                        /* extern */
void func_ovl3_80142D44(GObj*, s32, sb32, f32);
void func_ovl3_80141DA0(GObj*, s32, f32, s32);
s32 func_ovl2_800E8AAC(GObj*);                      /* extern */
void func_ovl2_800EAA2C(ftStruct*, s32, s32, s32, s32, s32); /* extern */
void func_ovl2_800E9CE8(ftStruct*);
f32 ftCommon_GetStickAngleRadians(ftStruct*);
void ftSpecialItem_BGMSetPlay(s32);
void func_ovl2_800EA3D4(ftStruct*, s32);
GObj* func_ovl3_80145990(GObj*, u8);          /* extern */
void func_ovl3_80145BE4(GObj*);                        /* extern */
void func_ovl3_801460E8(GObj*);                        /* extern */
void func_ovl3_8014D49C(GObj*);                        /* extern */
void jtgt_ovl2_800D90E0(GObj*);
f32 func_ovl2_800F3828(GObj*);                           /* extern */
u32 func_ovl2_800F385C(GObj*);                      /* extern */
void func_ovl2_800F388C(GObj*);                        /* extern */
void func_ovl2_800E8884(GObj*, s32, s32);
void func_ovl2_800E90F8(GObj*);                        /* extern */
GObj* func_ovl2_80101374(GObj*);                      /* extern */
void func_ovl3_80148120(ftStruct*);                        /* extern */
void func_ovl3_80148214(GObj*);                        /* extern */
void func_ovl3_801482E4(GObj*);                        /* extern */
void func_ovl3_80148304(GObj*);                        /* extern */
void func_ovl3_80148714(GObj*);                        /* extern */
void func_ovl3_80148DDC(GObj*);                        /* extern */
void func_ovl3_80148FF0(GObj*);                        /* extern */
void func_ovl3_80149510(GObj*);                        /* extern */
GObj* func_ovl2_80101108(GObj*);                      /* extern */
void func_ovl3_8014A5F0(GObj*, Vec3f*, Vec3f*);                    /* extern */
void func_ovl3_8014AA58(GObj*);                        /* extern */
void func_ovl2_800E11C8(GObj*);                        /* extern */
void ftSpecialItem_BGMCheckFighters();                             /* extern */
void func_ovl2_800E98D4(GObj*);                        /* extern */
void func_ovl2_800F36E0(GObj*);                        /* extern */
void func_ovl2_80115B10(GObj*);                        /* extern */
void func_unkmulti_8013A834(GObj*);                    /* extern */
void func_ovl2_800E26BC(ftStruct*, u32, GObj*, s32, u32, sb32); /* extern */
void func_ovl2_800E287C(GObj*, ftStruct*, ftHitbox*, GObj*);       /* extern */
void func_ovl2_800F0BC4(Vec3f*, ftHitbox*, ftHitbox*);         /* extern */
void func_ovl2_800E2B88(ftStruct *attacker_fp, ftHitbox *attacker_hit, ftStruct *victim_fp, GObj *attacker_gobj, GObj *victim_gobj);
s32 func_ovl2_800E2CC0(ftStruct*, s32*);           /* extern */
s32 func_ovl2_800EA40C(ftStruct*, s32);                 /* extern */
void func_ovl2_800F0A90(Vec3f*, ftHitbox*, ftHurtbox*);   /* extern */
void func_ovl2_800F0C08(Vec3f*, wpHitbox*, s32, ftHitbox*);
void func_ovl2_800F0EB4(Vec3f*, itHitbox*, s32, GObj*, DObj*); 
void func_ovl2_800E3DD0(GObj*, GObj*);                 /* extern */
void func_ovl2_800F0D24(Vec3f*, wpHitbox*, s32, ftHurtbox*); /* extern */
void func_ovl2_800F0E08(Vec3f*, itHitbox*, s32, ftHurtbox*); /* extern */
efParticle* func_ovl2_800FDEAC(Vec3f*, s32, s32); /* extern */
GObj* func_ovl2_800FFB38(Vec3f*);                       /* extern */
void* func_ovl2_80100218(Vec3f*, s32);                  /* extern */
void* func_ovl2_80100440(Vec3f*, s32);                  /* extern */
void ftCommon_SetModelPartRenderState(GObj*, s32, s32);
sb32 func_ovl3_8013E648(GObj*);                      /* extern */
sb32 func_ovl3_8013EA04(GObj*);                      /* extern */
sb32 func_ovl3_8013ED64(GObj*);                      /* extern */
sb32 func_ovl3_8013F4D0(GObj*);                      /* extern */
sb32 func_ovl3_80141EA4(GObj*);                      /* extern */
sb32 func_ovl3_80142258(GObj*);                      /* extern */
sb32 func_ovl3_8014310C(GObj*);                      /* extern */
sb32 func_ovl3_80148D0C(GObj*);                      /* extern */
sb32 func_ovl3_80149CE0(GObj*);                      /* extern */
sb32 func_ovl3_8014E764(GObj*);                      /* extern */
sb32 func_ovl3_8014EC78(GObj*);                      /* extern */
sb32 func_ovl3_8014F8C0(GObj*);                      /* extern */
sb32 func_ovl3_8014FB1C(GObj*);                      /* extern */
sb32 func_ovl3_8014FD70(GObj*);                      /* extern */
sb32 func_ovl3_80150470(GObj*);                      /* extern */
sb32 func_ovl3_8015070C(GObj*);                      /* extern */
sb32 func_ovl3_80150884(GObj*);                      /* extern */
sb32 func_ovl3_80151098(GObj*);                      /* extern */
sb32 func_ovl3_80151160(GObj*);                      /* extern */
sb32 func_ovl3_801511E0(GObj*);                      /* extern */

#define ftStatus_CheckInterruptAll(fighter_gobj)   \
(                                                  \
    (func_ovl3_80151098(fighter_gobj) != FALSE) || \
    (func_ovl3_80151160(fighter_gobj) != FALSE) || \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) || \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) || \
    (func_ovl3_80150470(fighter_gobj) != FALSE) || \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) || \
    (func_ovl3_80150884(fighter_gobj) != FALSE) || \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) || \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) || \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) || \
    (func_ovl3_8013ED64(fighter_gobj) != FALSE) || \
    (func_ovl3_80141EA4(fighter_gobj) != FALSE) || \
    (func_ovl3_80142258(fighter_gobj) != FALSE) || \
    (func_ovl3_8014310C(fighter_gobj) != FALSE) || \
    (func_ovl3_8013EA04(fighter_gobj) != FALSE) || \
    (func_ovl3_8013E648(fighter_gobj) != FALSE)    \
)                                                  \

#define ftStatus_CheckInterruptGround(fighter_gobj)\
(                                                  \
    (func_ovl3_80151098(fighter_gobj) != FALSE) || \
    (func_ovl3_80151160(fighter_gobj) != FALSE) || \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) || \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) || \
    (func_ovl3_80150470(fighter_gobj) != FALSE) || \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) || \
    (func_ovl3_80150884(fighter_gobj) != FALSE) || \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) || \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) || \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) || \
    (func_ovl3_8013ED64(fighter_gobj) != FALSE) || \
    (func_ovl3_8014310C(fighter_gobj) != FALSE) || \
    (func_ovl3_8013E2A0(fighter_gobj) != FALSE)    \
)                                                  \

#define ftStatus_CheckInterruptOttotto(fighter_gobj)\
(                                                  \
    (func_ovl3_80151098(fighter_gobj) != FALSE) || \
    (func_ovl3_80151160(fighter_gobj) != FALSE) || \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) || \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) || \
    (func_ovl3_80150470(fighter_gobj) != FALSE) || \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) || \
    (func_ovl3_80150884(fighter_gobj) != FALSE) || \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) || \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) || \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) || \
    (func_ovl3_8013ED64(fighter_gobj) != FALSE) || \
    (func_ovl3_80141EA4(fighter_gobj) != FALSE) || \
    (func_ovl3_80142258(fighter_gobj) != FALSE) || \
    (func_ovl3_8014310C(fighter_gobj) != FALSE) || \
    (func_ovl3_8013EA04(fighter_gobj) != FALSE)    \
)                                                  \

#define ftStatus_CheckInterruptLanding(fighter_gobj)   \
(                                                      \
    (func_ovl3_80151098(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80151160(fighter_gobj) != FALSE) ||     \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80150470(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80150884(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) ||     \
    (func_ovl3_8013ED64(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80141EA4(fighter_gobj) != FALSE) ||     \
    (func_ovl3_80142258(fighter_gobj) != FALSE)        \
)                                                      \

#define ftStatus_CheckInterruptSquat(fighter_gobj) \
(                                                  \
    (func_ovl3_80151098(fighter_gobj) != FALSE) || \
    (func_ovl3_80151160(fighter_gobj) != FALSE) || \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) || \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) || \
    (func_ovl3_80150470(fighter_gobj) != FALSE) || \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) || \
    (func_ovl3_80150838(fighter_gobj) != FALSE) || \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) || \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) || \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) || \
    (func_ovl3_80141F0C(fighter_gobj) != FALSE) || \
    (func_ovl3_80142258(fighter_gobj) != FALSE)    \
)                                                  \

#define ftStatus_CheckInterruptSquatWait(fighter_gobj) \
(                                                  \
    (func_ovl3_80151098(fighter_gobj) != FALSE) || \
    (func_ovl3_80151160(fighter_gobj) != FALSE) || \
    (func_ovl3_801511E0(fighter_gobj) != FALSE) || \
    (func_ovl3_80149CE0(fighter_gobj) != FALSE) || \
    (func_ovl3_80150470(fighter_gobj) != FALSE) || \
    (func_ovl3_8015070C(fighter_gobj) != FALSE) || \
    (func_ovl3_80150884(fighter_gobj) != FALSE) || \
    (func_ovl3_8014F8C0(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FB1C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014FD70(fighter_gobj) != FALSE) || \
    (func_ovl3_8014EC78(fighter_gobj) != FALSE) || \
    (func_ovl3_80148D0C(fighter_gobj) != FALSE) || \
    (func_ovl3_8014E764(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F4D0(fighter_gobj) != FALSE) || \
    (func_ovl3_8013ED64(fighter_gobj) != FALSE) || \
    (func_ovl3_80141EA4(fighter_gobj) != FALSE) || \
    (func_ovl3_80142258(fighter_gobj) != FALSE)    \
)                                                  \

#define ftStatus_CheckInterruptGuard(fighter_gobj) \
(                                                  \
    (func_ovl3_80146AE8(fighter_gobj) != FALSE) || \
    (func_ovl3_801493EC(fighter_gobj) != FALSE) || \
    (func_ovl3_80149C60(fighter_gobj) != FALSE) || \
    (func_ovl3_8013F604(fighter_gobj) != FALSE) || \
    (func_ovl3_80141F8C(fighter_gobj) != FALSE)    \
)                                                  \

// Crowd sound effects

void func_ovl3_80164F2C(GObj*, f32, sb32);

// Items and stuff

GObj* wpManager_MakeWeapon(GObj*, wpCreateDesc*, Vec3f*, u32);         /* extern */
sb32 wpMain_DecLifeCheckExpire(wpStruct*);
GObj* func_ovl3_801655C8(GObj*, wpCreateDesc*, Vec3f*, u32);            /* extern */
void* func_800092D0(GObj*, void*);                      /* extern */
void func_80009DF4(GObj*, void*, s32, u32, s32);              /* extern */
void func_8000BED8(GObj*, void*, void*, f32);              /* extern */
void func_8000F590(GObj*, void*, void*, u32, s32, s32);       /* extern */
void func_8000F8F4(GObj*, void*);                        /* extern */
void func_ovl0_800C89BC(void*, u32, u32, u32);              /* extern */
u16 func_ovl2_800EA5BC();                           /* extern */
u16 func_ovl2_800EA74C();                        /* extern */
void* func_ovl3_80165558(GObj*);                         /* extern */
void* func_ovl3_80165588(void*); // Eject item's user_data?
void func_ovl3_80165F60(GObj*);                        /* extern */
void func_ovl3_801662BC(GObj*);                     /* extern */
void func_ovl3_80166954(GObj*);                     /* extern */
void func_ovl3_80166BE4(GObj*);                     /* extern */
void func_ovl3_80168158(void*);                        /* extern */
void func_ovl3_801675D0(GObj*);
void func_ovl3_801675F4(GObj*);
void func_ovl3_80167618(GObj*);
void func_ovl3_8016763C(GObj*);
void func_8000DF34(GObj*);                                  /* extern */
void func_ovl2_800FA7B8(s32, Vec3f*);            /* extern */
sb32 func_ovl2_800FC67C(s32);                        /* extern */
void func_ovl3_801661E0(GObj*);                        /* extern */
void func_ovl3_8016800C(GObj*);                        /* extern */
void func_ovl3_80166594(wpHitbox*, GObj*, s32, s32);
void func_ovl2_800F0C94(Vec3f*, void*, s32, void*, s32);   /* extern */
void* func_ovl2_80100BF0(Vec3f*, s32);                      /* extern */
void func_ovl3_8016679C(wpStruct*, wpHitbox*, GObj*, s32, u32);    /* extern */
s32 func_ovl3_80168128(wpStruct*);                      /* extern */
void func_ovl3_80167520(GObj *item_gobj, void(*render)(GObj*)); // Render item
void func_ovl3_80167EB0(wpStruct*);
sb32 func_ovl3_80167FE8(wpStruct*);                      /* extern */
void func_ovl3_80168088(wpStruct*, f32, f32);              /* extern */
sb32 func_ovl3_80167A58(GObj*);                             /* extern */
sb32 func_ovl3_80167C38(GObj*, u32, f32, Vec3f*);          /* extern */
void func_ovl3_80167FA0(GObj*);                        /* extern */
void func_ovl3_801680EC(wpStruct*, ftStruct*);                   /* extern */
sb32 func_ovl3_80167C04(GObj*);                           /* extern */
void func_ovl3_80167F68(GObj*); 
void func_ovl3_80168044(GObj*);                   /* extern */
sb32 func_ovl3_8016796C(GObj*);                      /* extern */
sb32 func_ovl3_80167B58(GObj*);                           /* extern */
void func_ovl3_80167E78(wpStruct*);                        /* extern */
void func_ovl3_80167E9C(wpStruct*);                        /* extern */
void func_ovl3_80167F08(wpStruct*, u16);                     /* extern */
u32 func_ovl3_801655A0();

// Articles

GObj* itManager_MakeItemSetupCommon(GObj*, s32, Vec3f*, Vec3f*, u32); /* extern */
void func_ovl2_800F0E70(Vec3f*, itHitbox*, s32, ftHitbox*); /* extern */
s32 func_ovl3_801727F4(itStruct*);                           /* extern */
GObj* func_ovl3_8016EA78(GObj*, s32, Vec3f*, Vec3f*, u32);        /* extern */
void* func_ovl3_8016EB00();                           /* extern */
void func_ovl3_8016EB0C();                             /* extern */
void* func_ovl3_80173090(void*);                         /* extern */
void func_ovl3_8016F280(GObj*);                        /* extern */
void func_ovl3_8016F3D4(GObj*);                        /* extern */
void func_ovl3_801713B0(GObj*);                        /* extern */
void func_ovl3_801728D4(GObj*); // Destroy article
void func_ovl3_8016F930(itHitbox *at_hit, GObj *victim_gobj, s32 hitbox_type, s32 arg3);
void func_ovl3_8016FB18(ftStruct*, ftHitbox*, itStruct*, itHurtbox*, GObj*, GObj*); /* extern */
void func_ovl3_8016FD4C(itStruct*, itHitbox*, s32, itStruct*, itHitbox*, s32, GObj*, GObj*); /* extern */
void func_ovl3_8016FF4C(itStruct*, itHitbox*, s32, itStruct*, itHurtbox*, GObj*, GObj*); /* extern */
void func_ovl3_8016FE4C(wpStruct*, wpHitbox*, s32, itStruct*, itHitbox*, s32, GObj*, GObj*); /* extern */
void func_ovl3_801702C8(wpStruct*, wpHitbox*, s32, itStruct*, itHurtbox*, GObj*, GObj*); /* extern */
void func_ovl3_80172FBC(GObj*);
void func_ovl3_8016DFDC(itStruct*);                 /* extern */
void func_ovl3_8017275C(GObj*);                        /* extern */
void func_ovl3_80172984(GObj *article_gobj, Vec3f *vel, f32 stale, ...);
void func_ovl3_8017245C(GObj*, Vec3f*, s32);           /* extern */
void func_ovl3_80173F78(itStruct*);                        /* extern */
void func_ovl3_801725BC(GObj*);                        /* extern */
void func_ovl3_80173F54(itStruct*);                        /* extern */
void func_ovl3_80172508(GObj*);                        /* extern */
sb32 func_ovl3_801737B8(GObj*, u32);                          /* extern */
sb32 func_ovl3_801737EC(GObj*, u32, f32, Vec3f*);           /* extern */
void func_ovl3_80173A48(Vec3f*, Vec3f*, f32);                /* extern */
void func_ovl3_801713F4(void*);                        /* extern */
void func_ovl3_80172558(itStruct*, f32, f32);                    /* extern */
sb32 func_ovl3_801735A0(GObj*, void (*cb)(GObj*));
sb32 func_ovl3_801730D4(GObj*);
sb32 func_ovl3_80173B24(GObj*, f32, f32, void(*cb)(GObj*));
void func_ovl3_80172E74(GObj*);                             /* extern */
void func_ovl3_80172EC8(GObj*, ArticleStatusDesc*, s32);                   /* extern */
void func_ovl3_80173180(GObj*, ArticleHitEvent*);
GObj* func_ovl3_8016E174(GObj*, ArticleSpawnData*, Vec3f*, Vec3f*, u32); 
void func_ovl3_8017279C(GObj*);
sb32 func_ovl3_80173DF4(GObj*, f32);
sb32 func_ovl3_80172F98(GObj*, s32, s32); 
sb32 func_ovl3_80173E58(GObj*, void(*cb)(GObj*));
sb32 func_ovl3_80173C68(GObj*, f32, f32, void(*cb)(GObj*));                     /* extern */
sb32 func_ovl3_80173EE8(GObj*, f32, void(*cb)(GObj*));
void func_ovl3_80172FE0(GObj*);
GObj* func_ovl3_8016F238(GObj*, s32, Vec3f*, Vec3f*, u32);      /* extern */
void func_ovl3_80173228(GObj*);   
void func_ovl3_80173680(GObj*);
sb32 func_ovl3_80173D24(GObj*, f32, f32, void(*cb)(GObj*));
void func_ovl3_80172AEC(GObj*, Vec3f*, f32);        /* extern */
void func_ovl3_80172CA4(GObj*, GObj*);            /* extern */

// Collision
void mpCollision_GetGPointIDsKind(s32, s32*);
s32 mpCollision_GetGPointCountKind(s32);
void mpCollision_GetGPointPositionsID(s32, Vec3f*);         /* extern */
s32 mpCollision_SetDObjNoID(s32);
void mpCollision_SetYakumonoOnID(s32);                  /* extern */
void mpCollision_SetYakumonoOffID(s32);
void mpCollision_SetYakumonoPosID(s32, Vec3f*);          /* extern */
sb32 mpCollision_CheckCeilSurfaceTilt(s32 v1x, s32 v1y, s32 v2x, s32 v2y, f32 d1x, f32 d1y, f32 d2x, f32 d2y, f32 *dfx, f32 *dfy); /* extern */
sb32 mpCollision_CheckLineSurfaceFlat(s32, s32, s32, f32, f32, f32, f32, f32*, f32*); /* extern */
sb32 mpCollision_CheckGroundSurfaceTilt(s32 v1x, s32 v1y, s32 v2x, s32 v2y, f32 d1x, f32 d1y, f32 d2x, f32 d2y, f32 *dfx, f32 *dfy); 
sb32 mpCollision_CheckLWallSurfaceTilt(s32, s32, s32, s32, f32, f32, f32, f32, f32*, f32*); /* extern */
sb32 mpCollision_CheckRWallSurfaceTilt(s32, s32, s32, s32, f32, f32, f32, f32, f32*, f32*);
sb32 mpCollision_CheckLRSurfaceFlat(s32, s32, s32, f32, f32, f32, f32, f32*, f32*); /* extern */
void mpCollision_GetLRAngle(Vec3f*, s32, s32, s32, s32, s32);
sb32 func_ovl2_800F47AC(s32, s32, s32, s32, f32, f32, f32, f32, f32*, f32*); /* extern */
sb32 func_ovl2_800F58A0(s32, s32, s32, f32, f32, f32, f32, f32*, f32*); /* extern */
void mpCollision_GetUDAngle(Vec3f*, s32, s32, s32, s32, s32); /* extern */
void mp_GetUDEdge(s32, Vec3f*, s32);
void mp_GetLREdge(s32, Vec3f*, s32);
sb32 mp_GetUUCommon(s32 line_id, Vec3f *object_pos, f32 *arg2, u32 *arg3, Vec3f *arg4, s32 lr);
sb32 mp_GetLRCommon(s32 line_id, Vec3f *object_pos, f32 *arg2, u32 *arg3, Vec3f *arg4, s32 lr);
f32 func_ovl2_800F3A34(f32, s32, s32, s32, s32); /* extern */
f32 func_ovl2_800F39F0(f32, s32, s32, s32, s32); /* extern */
void func_ovl2_800F46D0(s32, s32, s32, s32, s32, s32); /* extern */
sb32 func_ovl2_800DD820(GObj*, s32);                     /* extern */
sb32 func_ovl2_800DDA6C(GObj*, s32);                   /* extern */
sb32 func_ovl2_800DDC50(Coll_Data *coll_data, GObj *fighter_gobj, s32 arg2);
sb32 func_ovl2_800DD2C8(Coll_Data*, sb32(*)(GObj*), GObj*);
void func_ovl2_800D9510();                             /* extern */
void func_ovl2_800D951C(s32);                          /* extern */
sb32 func_ovl2_800F5E90(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
void func_ovl2_800D9FCC(Coll_Data*);
void func_ovl2_800D9590(void);                             /* extern */
void func_ovl2_800D95A4(f32, s32, f32, Vec3f*);        /* extern */
void func_ovl2_800D95E0(f32*, s32*, s32*, Vec3f*);     /* extern */
s32 func_ovl2_800FA518(s32);                        /* extern */
void func_ovl2_800FA5E8(s32, s32, Vec3f*);               /* extern */
// sb32 func_ovl2_800F9348(Vec3f*, s32*, f32*, u32*, f32*); /* extern */
s32 func_ovl2_800D9A00(Coll_Data*);                           /* extern */
void func_ovl2_800D9AB0(Coll_Data*);                        /* extern */
s32 func_ovl2_800D9CC0(Coll_Data*);                      /* extern */
void func_ovl2_800D9D70(Coll_Data*);                        /* extern */
// s32 func_ovl2_800F4BD8(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, void*); /* extern */
s32 func_ovl2_800D9628(Coll_Data*);                           /* extern */
void func_ovl2_800D96D8(Coll_Data*);                   /* extern */
s32 func_ovl2_800D97F0(Coll_Data*);                 /* extern */
void func_ovl2_800D98A0(Coll_Data*);                   /* extern */
sb32 func_ovl2_800F6B58(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
s32 func_ovl2_800FABA4(s32);                 /* extern */
s32 func_ovl2_800F3E04(s32, Vec3f*, f32*, u32*, Vec3f*);
sb32 func_ovl2_800F7F00(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
s32 func_ovl2_800FAAE4(s32);                 /* extern */
void func_ovl2_800D9F84(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DA294(Coll_Data*);                           /* extern */
void func_ovl2_800DA658(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DAAA8(Coll_Data*);                      /* extern */
void func_ovl2_800DAE6C(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DB2BC(Coll_Data*);                      /* extern */
sb32 func_ovl2_800DB474(Coll_Data*, s32);                 /* extern */
void func_ovl2_800DD59C(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DA034(Coll_Data*, sb32 (*proc_map)(Coll_Data*, GObj*, s32), GObj*, sb32);
void func_ovl2_800D99B8(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DB838(Coll_Data*);                           /* extern */
void func_ovl2_800DBF58(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DC3C8(Coll_Data*);                      /* extern */
void func_ovl2_800DCAE8(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DCF58(Coll_Data*);                      /* extern */
void func_ovl2_800DD160(Coll_Data*);                        /* extern */
sb32 func_ovl2_800DD578(Coll_Data*);                      /* extern */
void func_ovl2_800DD6A8(Coll_Data*);                        /* extern */
void func_ovl0_800C7AE0(Vec3f*, f32);                   /* extern */
void* func_ovl0_800C7B08(Vec3f*, Vec3f*);                 /* extern */
f32 func_ovl0_800C7C0C(Vec3f*, Vec3f*);               /* extern */
void func_ovl2_800DF014(GObj*, Vec3f*, Coll_Data*); 

// Camera
void cmManager_SetCameraStatus(s32);
void func_ovl2_8010C55C(OMCamera*, Vec3f*, f32);                 /* extern */
void func_ovl2_8010C5C0(OMCamera*, Vec3f*);                    /* extern */
void func_ovl2_8010C6B8(OMCamera*);                          /* extern */
void func_ovl2_8010C6FC(OMCamera*);                          /* extern */
void func_ovl2_8010C70C(f32);                   /* extern */

// Animation

void GObjSetAnimSpeed(GObj*, f32); // Apply animation speed to fighter?
void func_8000BB4C(GObj*, f32); // Apply animation speed to item?
void func_8000BD8C(GObj*, void*, f32); // ??? From unused Fan function
void func_8000BD54(MObj*, void*, f32); // Apply texture animation?
void func_8000BFE8(DObj*);                             /* extern */
void func_8000CCBC(DObj*);                        /* extern */
void func_ovl0_800C9488(DObj*, Vec3f*);                   /* extern */
void func_ovl0_800C8758(DObj*, void*, f32);                /* extern */
void func_ovl2_800EB648(DObj*);                          /* extern */

// Color Animation

sb32 func_ovl2_800E0880(caStruct*, GObj*, sb32, sb32);
sb32 func_ovl2_800E974C(caStruct*, s32, s32);
void func_ovl2_800E9838(caStruct*);

// Sound?

void func_80020AB4(s32, s32);                            /* extern */
s32 ftSpecialItem_BGMGetDuration(s32);                        /* extern */
void func_80026738(gmSoundEffect*); // Destroy sound effect?
sb32 func_ovl3_80164AB0(s32, f32, s32);              /* extern */
void func_ovl3_80164C18();                          /* extern */
void func_ovl3_80164C44(s32);                  /* extern */
void func_ovl3_80164CBC(f32);                          /* extern */

// Math functions
f32 acosf(f32);                                     /* extern */
f32 asinf(f32);                                /* extern */
f32 atan2f(f32, f32);
f32 vec3f_angle_diff(Vec3f*, Vec3f*);
void vec3f_scale(Vec3f*, f32);
f32 vec3f_mag(Vec3f*);
void vec3f_sub(Vec3f*, Vec3f*, Vec3f*);             /* extern */
void vec3f_add_to(Vec3f*, Vec3f*);
f32 vec3f_normalize(Vec3f*);
void vec3f_sub_from(Vec3f*, Vec3f*);
f32 bitmap_sinf(f32);
f32 bitmap_cosf(f32);                               /* extern */
f32 __sinf(f32);                                    /* extern */
f32 cosf(f32);                                      /* extern */
f32 sqrtf(f32);
void vec3f_normalized_cross_product(Vec3f*, Vec3f*, Vec3f*); /* extern */
void func_80019438(Vec3f*, Vec3f*, f32);
f32 vec3_get_euler_rotation(Vec3f*, s32, f32);

// Misc functions
void cmManager_MakeWallpaperCamera();                  /* extern */
void cmManager_SetViewportCoordinates(s32, s32, s32, s32);     /* extern */
void ftManager_AllocFighterData(u32, s32);                 /* extern */
GObj* ftManager_MakeFighter(void*);                /* extern */
void ftManager_SetFileDataKind(s32);             /* extern */
void ftManager_SetFileDataPlayables();                 /* extern */
void ftPublicity_SetPlayerPublicReact();               /* extern */
void func_ovl2_80112B74();                             /* extern */
void gmRumble_SetPlayerRumble();                       /* extern */
void grNodeInit_SetGroundFiles();                      /* extern */
void grWallpaper_SetGroundWallpaper();                 /* extern */
void ifMain_SetGameStatusWait();                       /* extern */
void ifPlayer_MagnifyArrows_SetInterface();            /* extern */
void ifPlayer_MagnifyGlass_SetInterface();             /* extern */
void ifPlayer_Stocks_SetInterface();                   /* extern */
void ifPlayer_Tag_SetInterface();                      /* extern */
void ifScreen_SetScreenFlash(u8);                       /* extern */
void ifTimer_BattleTime_SetInterface(void (*)());      /* extern */
void ifTimer_BattleTime_SetTimerDigits();              /* extern */
void mpData_SetGroundMusicID();                        /* extern */
void mpData_SetMapCollisionData();                     /* extern */
s32 scBattle_GetPlayerStartLR(s32);                 /* extern */
void efManager_AllocUserData();                        /* extern */
void ftCommon_ClearPlayerMatchStats(s32, GObj*);          /* extern */
GObj* ftManager_CreateFighter(ftSpawnInfo*);                  /* extern */ 
GObj* func_8000B9FC(s32 link, u32 arg1, s32 arg2, s32 arg3, s32 arg4);                   /* extern */
void func_ovl0_800D4060(void*, void*, void*, void*, s32, s32, s32); /* extern */
// void func_ovl2_800D7194(void*, void*);                         /* extern */
void func_ovl2_800D782C();                             /* extern */
void func_ovl2_800D786C(s32);                           /* extern */
void* func_ovl2_800D78B4(s32);           /* extern */
void func_ovl2_800EC130();                             /* extern */
void func_ovl2_800FAF64(s32, Vec3f*);                       /* extern */
void func_ovl2_800FC284();                             /* extern */
void func_ovl2_800FC3E8();                             /* extern */
void func_ovl2_80104BDC();                             /* extern */
void func_ovl2_80105600();                             /* extern */
void func_ovl2_8010DB00();                             /* extern */
void func_ovl2_8010DB54();                             /* extern */
void func_ovl2_8010DDC4();                             /* extern */
void func_ovl2_8010E1A4();                             /* extern */
void func_ovl2_8010E2D4();                             /* extern */
void func_ovl2_8010E374();                             /* extern */
void func_ovl2_8010E498();                             /* extern */
void func_ovl2_8010E598(s32, s32, s32, s32);                   /* extern */
void func_ovl2_8010F3A0();                             /* extern */
void func_ovl2_8010F3C0();                             /* extern */
void func_ovl2_80110514();                             /* extern */
void func_ovl2_80111440();                             /* extern */
void func_ovl2_801118E4();                             /* extern */
void func_ovl2_80111BE4();                             /* extern */
void func_ovl2_80112A80();                             /* extern */
void func_ovl2_80112F68();                             /* extern */
void func_ovl2_80113398(void(*)());                           /* extern */
void func_ovl2_80114958();                             /* extern */
void func_ovl2_801156E4();                             /* extern */
void func_ovl2_80115890();                             /* extern */
void func_ovl2_80115DE8(u8);                            /* extern */
void func_ovl3_801653E0();                             /* extern */
s32 func_ovl4_8018D0E0(s32);                         /* extern */
void func_ovl4_8018E330();                             /* extern */
void itManager_AllocUserData();                        /* extern */
void osInvalICache(void*, s32);                    /* extern */
void osWritebackDCache(void*, s32);                /* extern */
u32 rldm_bytes_needed_to_load(u32);                  /* extern */
void* rldm_get_file_with_external_heap(u32, u8*);    /* extern */
void wpManager_AllocUserData();                        /* extern */
void func_ovl0_800C88AC(DObj*, void*, void*, f32);           /* extern */
void func_ovl0_800C9228(DObj*, void*);                   /* extern */
void func_ovl2_8011633C(GObj*, void*, void*, u8, u8, u8, s32); /* extern */
void func_ovl2_800FD714(GObj*);
void func_ovl0_800C8B28(DObj*, s32, void*, u8, s32, s32);  /* extern */
void hal_scale(Mtx*, f32, f32, f32);                    /* extern */
void hal_translate(Mtx*, f32, f32, f32);                /* extern */
void func_ovl2_800F1D44(ftStruct *fp, DObj *dobj, ftParts *unk_dobjtrans);
void func_ovl2_800F1C08(u8 flags, ftStruct *fp);
void itCollision_GetHitPosition(Vec3f*, itHitbox*, s32);     /* extern */
void wpCollision_GetHitPosition(Vec3f*, wpHitbox*, s32); 
void func_ovl2_800F09F0(Vec3f*, GObj*, DObj*);                 /* extern */
void gmCollision_GetImpactPosition(Vec3f*, Vec3f*, Vec3f*);     /* extern */
void ftCollision_GetHitPosition(Vec3f*, ftHitbox*);                   /* extern */
void func_ovl2_800F0A48(Vec3f*, Vec3f*, Vec3f*);           /* extern */
sb32 gcColSphere(Vec3f *sphere1, Vec3f *sphere2, f32 radius, s32 opkind, Mtx44f mtx, Vec3f *arg5, Vec3f *arg6, Vec3f *arg7, s32 arg8, f32 *p_angle, Vec3f *argA);
void func_ovl2_800EDE00(DObj*);                        /* extern */
void func_ovl2_800EDE5C(DObj*);                        /* extern */
sb32 func_ovl2_800EE300(Vec3f*, Vec3f*, f32, s32, Mtx44f, Vec3f*, Vec3f*, Vec3f*); /* extern */
void func_ovl2_800EE050(s32, Vec3f*, Vec3f*, sb32*, Mtx44f, f32*); /* extern */
sb32 func_ovl2_800EEEAC(Vec3f*, Vec3f*, f32, s32, Mtx44f, s32, Vec3f*, f32, s32, f32); /* extern */
sb32 func_ovl2_800EF5D4(Vec3f*, Vec3f*, f32, s32, s32, s32, f32, s32); /* extern */
void func_ovl2_800ECDE4(DObj *dobj, void *arg1, Mtx44f mtx);
void func_8000CF6C(MObj*);                             /* extern */
void func_8000DA40(MObj*);                             /* extern */
void func_ovl2_800EC238(DObj*);                        /* extern */
efParticle* func_ovl2_80102DEC(Vec3f*);                          /* extern */
GObj* ftCommon_GetPlayerNumGObj(s32);                      /* extern */
void func_ovl2_8010CF20();        
void func_ovl2_8010D0A4(Vec3f*, Vec3f*);                   /* extern */
void func_ovl0_800C7A00(Vec3f*);                       /* extern */
f32 func_ovl0_800C7A84(Vec3f*);                /* extern */
void* func_ovl2_80100480(Vec3f*);                          /* extern */
void* func_ovl2_80103320(Vec3f*);                          /* extern */
efParticle* func_ovl2_801005C8(Vec3f*);                          /* extern */
void func_ovl2_800F4650(s32, Vec3f*);                      /* extern */
void func_ovl2_800F4670(s32, Vec3f*);                      /* extern */
void func_ovl2_800F4690(s32, Vec3f*);                      /* extern */
void func_ovl2_800F46B0(s32, Vec3f*);                      /* extern */
// void func_ovl2_800FE068(Vec3f*, s32);
void func_ovl2_80101C34(Vec3f*, f32);                     /* extern */
sb32 func_ovl2_800F4194(s32, Vec3f*, f32*, u32*, Vec3f*);    /* extern */
sb32 func_ovl2_800F41C0(s32, Vec3f*, f32*, u32*, Vec3f*);    /* extern */
sb32 func_ovl2_800F521C(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
s32 func_ovl2_800F64D4(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
sb32 func_ovl2_800F769C(Vec3f*, Vec3f*, Vec3f*, s32*, u32*, Vec3f*); /* extern */
s32 func_ovl2_800F8974(Vec3f*, Vec3f*, Vec3f*, s32*, Vec3f*, Vec3f*); /* extern */
s32 func_ovl2_800FA964(s32);                        /* extern */ 
s32 func_ovl2_800FAA24(s32);                        /* extern */
s32 func_ovl2_800FAC64(s32);                        /* extern */
s32 func_ovl2_800FADE4(s32);                        /* extern */
s32 func_ovl2_800FA8A4(s32);                        /* extern */
s32 func_ovl2_800FAD24(s32);                        /* extern */
s32 func_ovl2_800FAEA4(s32);                        /* extern */
void func_ovl2_80101B88(Vec3f*, s32, s32);                   /* extern */
void func_ovl2_80103A88(Vec3f*);                          /* extern */
void func_ovl2_801041A0(Vec3f*);                          /* extern */
void func_ovl2_800EB924(OMCamera*, Mtx44f, Vec3f*, f32*, f32*);     /* extern */
void func_ovl2_800FECBC(Vec3f*);              /* extern */
void func_ovl2_800FC894(s32, void*);                       /* extern */
s32 func_ovl2_800FC7A4(s32);            /* extern */
void func_ovl2_800FC814(s32, s32*);                 /* extern */
f32 func_ovl2_800EA470(u32, s32, u16);
void* func_ovl2_8010066C(Vec3f*, f32);              /* extern */
void func_ovl2_800E26BC(ftStruct*, u32, GObj*, s32, u32, sb32);      /* extern */
void func_ovl2_800E2C24(ftStruct*, ftHitbox*);                 /* extern */
void func_ovl2_800F0AF8(void*, void*, void*, void*);      /* extern */
f32 func_ovl2_800F0FC0(void*, void*);               /* extern */
// void* func_ovl2_800FDC04(void*, u8, s32, void*);               /* extern */
efParticle* func_ovl2_800FE2F4(Vec3f*, s32);                      /* extern */
efParticle* func_ovl2_800FE4EC(Vec3f*, s32);                      /* extern */
GObj* func_ovl2_800FE6E4(Vec3f*, s32, f32);                 /* extern */
void func_ovl2_80100ACC(void*);                           /* extern */
void func_ovl2_800F0EFC(Vec3f*, void*, s32, void*, s32); /* extern */
void func_ovl2_800F0F44(Vec3f*, itHitbox*, s32, itHurtbox*, GObj*); /* extern */
void func_ovl2_800F0D8C(Vec3f*, wpHitbox*, s32, itHurtbox*, GObj*);   /* extern */
sb32 func_ovl2_800EFC20(ftHitbox*, itHurtbox*, GObj*);
sb32 func_ovl2_800F05C8(itHitbox*, s32, itHitbox*, s32);     /* extern */
sb32 func_ovl2_800F06E8(itHitbox*, s32, itHurtbox*, GObj*);   /* extern */
sb32 func_ovl2_800F019C(wpHitbox*, s32, itHitbox*, s32);     /* extern */
sb32 func_ovl2_800F079C(wpHitbox*, s32, itHurtbox*, GObj*);   /* extern */
void func_80009A84(GObj*);                      /* extern */
void func_ovl2_800E8744(GObj*);                 /* extern */
efParticle* func_ovl2_800FF590(Vec3f*);                 /* extern */
void func_ovl0_800C9424(DObj*);                        /* extern */
void func_ovl2_800DF058(GObj*, Vec3f*, Coll_Data*);            /* extern */
void func_ovl2_800E806C(ftStruct*, s32, s32);                  /* extern */
void* func_80008CC0(DObj*, u8, u8);                       /* extern */
void func_8000F988(GObj*, s32);                        /* extern */
void func_ovl2_800E86F0(GObj*);                        /* extern */
void func_ovl2_80104458(Vec3f*);                         /* extern */
GObj* func_ovl2_80111EC0(void*); 
efParticle* func_ovl2_800FF3F4(Vec3f*, s32, f32);
void* func_ovl2_800FFEA4(Vec3f*, s32);
void func_ovl2_80102070(Vec3f*, s32);
void func_8000BD1C(DObj*, void*, f32);
efParticle* func_ovl2_800FF048(Vec3f*, s32, f32);
void func_800090DC(DObj*, void*);                      /* extern */
void func_800091F4(DObj*);               /* extern */
void func_ovl2_8010B0AC();                             /* extern */
f32 func_ovl3_801409BC(s32, s32, f32);
void* func_ovl2_80102E90(Vec3f*);
efGenerator* func_ovl2_801014A8(Vec3f*); 
void* func_ovl2_800FF278(Vec3f*, s32);                    /* extern */
void* func_ovl0_800CE8C0(s32, s32, f32, f32, f32, f32, f32, f32); /* extern */
sb32 func_ovl2_800F8FFC(Vec3f*);
void func_ovl2_80113804(u16);
void func_ovl2_8010F76C(ftStruct*);                             /* extern */
void func_ovl2_8011388C(ftStruct*);                        /* extern */
void func_ovl2_80114968(ftStruct*);                        /* extern */
void func_ovl2_801149CC(ftStruct*, s32); /* extern */
void func_ovl2_80114C80();                             /* extern */
// GObj* func_ovl2_801021C0(Vec3f*, s32, s32);                  /* extern */
void func_ovl2_80115BF0(s32, s32);                         /* extern */
void* func_ovl2_80100720(Vec3f*, f32);                       /* extern */
void func_ovl0_800C7AB8(Vec3f*, Vec3f*);                /* extern */
f32 func_ovl2_800EA1B0(f32);                        /* extern */
void func_ovl2_800EA948(ftStruct*, s32);           /* extern */
void* func_ovl2_800FFD58(void*, s32, f32);                    /* extern */
f32 func_ovl0_800C78B8(f32);
void func_ovl2_80109D20(GObj*);
f32 func_ovl2_800E9FC0(s32, s32, s32, s32, s32, s32, f32, s32, s32); /* extern */
f32 func_ovl2_8010A12C();                           /* extern */
void func_ovl0_800C9A38(Mtx44f, DObj*);               /* extern */
void func_ovl2_800ED3C0(Mtx44f, Vec3f*);                    /* extern */
void func_ovl2_800EDA0C(Vec3f*, Vec3f*);                      /* extern */
void func_ovl0_800C87F4(DObj*, void*, f32);
void func_80014038(GObj*);
void func_80014768(GObj*);

// Effect?

extern s32 gEffectBankIndex;

GObj* func_ovl2_800FD778(efCreateDesc*, sb32);
void func_ovl2_80116204(GObj*, s32);         /* extern */
GObj* func_ovl2_8011652C(efCreateDesc*, s32);            /* extern */
// s32 func_ovl2_801159F8(s32, s32, s32, s32);             /* extern */
efParticle* func_ovl0_800CE870(s32, s32);
GObj* func_ovl2_800FDB1C(efCreateDesc*);
GObj* func_ovl2_800FDAFC(efCreateDesc*);
efGenerator* func_ovl0_800D35DC(s32, s32);
void efTransform_Default_ProcDead(GObj*);               /* extern */
efParticle* efManager_DestroyParticleGObj(efParticle*, GObj*); /* extern */
efStruct* efManager_GetStructNoForceReturn();       /* extern */
void efParticle_Default_ProcUpdate(GObj*);          /* extern */
efParticle* func_ovl0_800CE9E8(s32, s32);             /* extern */
void efManager_SetPrevAlloc(efStruct*);
void* func_ovl2_800FE7B4(Vec3f*, s32);                    /* extern */
void* func_ovl2_800FE9B4(Vec3f*);                         /* extern */
void* func_ovl2_800FEB58(Vec3f*);                         /* extern */
void* func_ovl2_800FEEB0(Vec3f*);                         /* extern */
void* func_ovl2_800FF7D8(Vec3f*, s32, f32);               /* extern */
void* func_ovl2_800FFAB8(Vec3f*);                         /* extern */
void* func_ovl2_800FFDE8(Vec3f*, s32);                      /* extern */
void* func_ovl2_801001A8(Vec3f*, s32);                    /* extern */
GObj *func_ovl2_801003D0(Vec3f*, s32);                    /* extern */
void* func_ovl2_80100524(Vec3f*);                         /* extern */
GObj* func_ovl2_80100DEC(GObj*);                        /* extern */
void* func_ovl2_80101408(Vec3f*);                         /* extern */
efParticle* func_ovl2_801015D4(Vec3f*);                         /* extern */
void* func_ovl2_80101630(Vec3f*);                         /* extern */
void* func_ovl2_80101688(Vec3f*);                         /* extern */
void* func_ovl2_801016E0(Vec3f*);                         /* extern */
void* func_ovl2_80101738(Vec3f*);                         /* extern */
void* func_ovl2_8010183C(Vec3f*, s32);                    /* extern */
void* func_ovl2_80102018(Vec3f*);                         /* extern */
void* func_ovl2_80103150(GObj*);                        /* extern */
void* func_ovl2_801031E0(Vec3f*);                         /* extern */
void* func_ovl2_80103280(Vec3f*);                         /* extern */
void* func_ovl2_801039D4(Vec3f*);                         /* extern */
void efRunProc(GObj*, void(*proc)(GObj*, efStruct*));
efTransform* func_ovl0_800CE1DC(efParticle*, u8);                   /* extern */
// efParticle* func_ovl0_800CE9E8(s32, void*);                     /* extern */
void func_ovl0_800CEA14(efParticle*);                          /* extern */
void func_ovl0_800CEA40(efParticle*);                          /* extern */
void func_ovl2_800FD4F8(efStruct*);
efStruct* func_ovl2_800FD4B8();                     /* extern */
efParticle* func_ovl2_800FDB3C(efParticle*, GObj*);     /* extern */
void func_ovl2_800FDBCC(GObj*);                     /* extern */

// Ground
GObj* func_ovl0_800CD050(s32, void*, s32, s32, void*, s32, s32, s32, void*, s32, void*, s32); /* extern */
void func_ovl2_80108550(Vec3f*);                         /* extern */
s32 func_ovl2_801085A8(s32);                        /* extern */
extern GObj *D_ovl2_801313D8;

// Randomizer

u16 lbRandom_GetShort();
f32 lbRandom_GetFloat();
s32 lbRandom_GetIntRange(s32);

f32 rand_f32();
u16 rand_u16();
u32 rand_u16_range(s32);

// Misc
f32 func_ovl0_800C7B58(Vec3f*, Vec3f*);             /* extern */
f32 func_ovl2_800EBA6C(Vec3f*, Vec3f*);             /* extern */
void func_80007080(void*, f32, f32, f32, f32);         /* extern */
struct OMMtx* func_80008CF0(void*, u8, u8);                      /* extern */
GObj* func_8000B93C(u32, void*, s32, u32, void*, s32, s64, s32, s32, s32, s32, s32, s32); /* extern */

// HAL Sprite
void func_ovl0_800D39D4(u16, s32);

// Math

void lbVector_Vec3fNormalizedCross(Vec3f*, Vec3f*, Vec3f*); /* extern */
f32 lbVector_Vec3fAngleDiff(Vec3f*, Vec3f*);        /* extern */
f32 lbVector_Vec3fMagnitude(Vec3f*);                  /* extern */
void lbVector_Vec3fSubtract(Vec3f*, Vec3f*, Vec3f*);       /* extern */
void lbVector_Vec3fGetEulerRotation(Vec3f*, s32, f32); /* extern */
void lbVector_Vec3fAddTo(Vec3f*, Vec3f*);              /* extern */
void lbVector_Vec3fScale(Vec3f*, f32);                 /* extern */
f32 func_8000CB94(AObj*);                           /* extern */
void func_ovl0_800CD5AC(Vec3f*, Vec3f*, Vec3f*);                /* extern */
void hal_interpolation_cubic(Vec3f*, void*, f32);           /* extern */
void hal_interpolation_quadratic(Vec3f*, void*, f32);       /* extern */
void lbVector_Vec3fNormalize(Vec3f*);                     /* extern */
void guMtxF2L(Mtx44f, Mtx*);                    /* extern */
void guMtxCatF(Mtx44f, Mtx44f, Mtx44f);                            /* extern */
void hal_look_at_f(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
void hal_mtx_f2l(void*, s32);                             /* extern */
void hal_ortho_f(void*, f32, f32, f32, f32, f32, f32, f32);   /* extern */

// GObj
GObj* omMakeGObjCommon(u32, void*, u8, u32);                 /* extern */
void omAddDObjAnimAll(DObj*, ATrack*, f32);
GObj* omAddGObjCommonProc(GObj*, void(*)(GObj*), s32, s32);
void* func_80008188(GObj*, void(*cb)(GObj*), u8, u32);                     /* static */
GObj* func_80009968(u32, void (*cb)(void), u8, u32);    
void om_g_move_obj_dl_head(GObj*, u8, u32);
void om_g_move_obj_dl(GObj*, u8, u32);
void omEjectGObjCommon(GObj*);

// SObj
SObj* func_80009614(GObj*, void*);                      /* extern */
SObj* func_ovl0_800CCFDC(GObj*, void*);             /* extern */

// Log

void fatal_printf(char*, ...);
void scnmgr_crash_print_gobj_state();

// HAL

void* hal_alloc(u32, u32);                      /* extern */

// Misc
u32 func_ovl2_800EE24C(Vec3f*, Vec3f*);               /* extern */
u32 func_ovl2_800EE2C0(Vec3f*, Vec3f*);               /* extern */
DObj* func_800093F4(DObj*, void*);                      /* extern */
void func_8000F2FC(DObj*, u8, u8, u8);               /* extern */
void cmManager_RestoreCameraStatus(); /* extern */
void cmManager_RunProcCamera(GObj*); /* extern */
void func_80005C74();                                  /* extern */
void func_8000AF58();               /* extern */
void func_800266A0();          /* extern */
void func_ovl2_80104CD0();                             /* extern */
void func_ovl2_801142B4();                             /* extern */
void func_ovl2_801157EC();                             /* extern */
void ifPauseMenu_SetRenderFlagsAll(u32);                 /* extern */

typedef union MtxStore
{
    Mtx *gbi;
    Mtx44f *f;
    s32 i;

} MtxStore;

// mlBumpAllocRegion?
typedef struct mlBumpAllocRegion {
    /* 0x00 */ u32 id;
    /* 0x04 */ void *start;
    /* 0x08 */ void *end;
    /* 0x0C */ void *ptr;
} mlBumpAllocRegion; // size == 0x10

extern GObj *gOMObjCommonLinks[];
extern Gfx *gDisplayListHead[4];

f32 padding;

// extern gmMatchInfo* gBattleState;
extern gmMatchInfo gDefaultBattleState;
// extern gmSceneInfo gSceneData;

extern gmMatchInfo D_ovl6_8018F1B0;

void func_ovl6_8018D0F0(void) 
{
    s32 player;
    s32 ft_kind;

    gSceneData.is_reset = FALSE;
    
    D_ovl6_8018F1B0 = gDefaultBattleState;
    gBattleState = &D_ovl6_8018F1B0;

    gBattleState->game_type = gmMatch_GameType_Bonus;
    gBattleState->match_rules = GMMATCH_GAMERULE_BONUS | GMMATCH_GAMERULE_TIME;
    gBattleState->is_display_score = FALSE;
    
    gBattleState->pl_count = 1;
    gBattleState->cp_count = 0;
    
    if (gSceneData.scene_previous == 0x34) 
    {
        ft_kind = gSceneData.ft_kind;
        
        gBattleState->time_limit = 100;
        
        if (gSceneData.scene_queue == 3) 
        {
            if (gSceneData.unk16 != 0x64) 
            {
                gBattleState->time_limit = 2;
            }
            gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus1Start;
        }
        else 
        {
            if (gSceneData.unk16 != 0x64) 
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
    for(player = 0; player < ARRAY_COUNT(gBattleState->player_block); player++)
    {
        if (player == gSceneData.player_port)
        {
            gBattleState->player_block[player].player_kind = Pl_Kind_Human;
            gBattleState->player_block[player].character_kind = ft_kind;
            
            if (gSceneData.scene_previous == 0x34) 
            {
                gBattleState->player_block[player].costume_index = gSceneData.costume_index;
            } 
            else gBattleState->player_block[player].costume_index = gSceneData.unk3A;
            
            gBattleState->player_block[player].team_color_index = player;
        }
        else gBattleState->player_block[player].player_kind = Pl_Kind_None;
    }
}











// #include <gm/battle.h>
// #include <gr/grdef.h>
// #include <ft/ftdef.h>
// #include <gr/ground.h>
// #include <it/itdef.h>

// typedef struct grBonusDesc
// {
// 	intptr_t o_main;
// 	intptr_t o_dobjdesc;
// 	intptr_t o_anim;

// } grBonusDesc;

// void func_ovl6_8018D0C0(){}
// void func_ovl6_8018D0C8(){}

// void func_ovl6_8018D0D0(void) {
// 	func_ovl2_8011485C();
// }

// extern gmMatchInfo gDefaultBattleState;
// extern gmMatchInfo gBonusBattleState;
// void func_ovl6_8018D0F0(void) 
// {
// 	s32 player;
// 	s32 ft_kind;

// 	gSceneData.is_reset = FALSE;
	
// 	gBonusBattleState = gDefaultBattleState;
// 	gBattleState = &gBonusBattleState;

// 	gBattleState->game_type = gmMatch_GameType_Bonus;
// 	gBattleState->match_rules = GMMATCH_GAMERULE_BONUS | GMMATCH_GAMERULE_TIME;
// 	gBattleState->is_display_score = FALSE;
	
// 	gBattleState->pl_count = 1;
// 	gBattleState->cp_count = 0;
	
// 	if (gSceneData.scene_previous == 0x34) 
// 	{
// 		ft_kind = gSceneData.ft_kind;
		
// 		gBattleState->time_limit = 100;
		
// 		if (gSceneData.spgame_stage == 3) 
// 		{
// 			if (gSceneData.spgame_time_limit != 0x64) 
// 			{
// 				gBattleState->time_limit = 2;
// 			}
// 			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus1Start;
// 		}
// 		else 
// 		{
// 			if (gSceneData.spgame_time_limit != 0x64) 
// 			{
// 				gBattleState->time_limit = 2;
// 			}
// 			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus2Start;
// 		}
// 	} 
// 	else 
// 	{
// 		ft_kind = gSceneData.unk39;
		
// 		gBattleState->time_limit = 0x64;
		
// 		if (gSceneData.scene_previous == 0x13) 
// 		{
// 			gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus1Start;
// 		} 
// 		else gBattleState->gr_kind = ft_kind + Gr_Kind_Bonus2Start;
// 	}
// 	for (player = 0; player < ARRAY_COUNT(gBattleState->player_block); player++)
// 	{
// 		if (player == gSceneData.player_port)
// 		{
// 			gBattleState->player_block[player].player_kind = Pl_Kind_Man;
// 			gBattleState->player_block[player].character_kind = ft_kind;
			
// 			if (gSceneData.scene_previous == 0x34) 
// 			{
// 				gBattleState->player_block[player].costume_index = gSceneData.costume_index;
// 			} 
// 			else gBattleState->player_block[player].costume_index = gSceneData.unk3A;
			
// 			gBattleState->player_block[player].player_color_index = player;
// 		}
// 		else gBattleState->player_block[player].player_kind = Pl_Kind_Not;
// 	}
// }

// // extern intptr_t D_NF_000000FD;
// // extern void* D_ovl6_8018F1A0[];
// // void func_ovl6_8018D330(void) 
// // {
// //     D_ovl6_8018F1A0[0] = rldm_get_file_with_external_heap((u32)&D_NF_000000FD, hal_alloc(rldm_bytes_needed_to_load((u32)&D_NF_000000FD), 0x10));
// // }

// // extern grBonusDesc D_ovl6_8018EEC4[];
// // void func_ovl6_8018D374(void) 
// // {
// // 	grBonusDesc *bonus_desc = &D_ovl6_8018EEC4[gBattleState->gr_kind - Gr_Kind_Bonus1Start];
// // 	void **atrack;
// // 	DObjDesc *dobj_desc;
// // 	Vec3f sp48;

// // 	sp48.x = sp48.y = sp48.z = 0.0F;
	
// // 	dobj_desc = (DObjDesc*) ((uintptr_t) ((uintptr_t)gGroundInfo->gr_desc[1].dobj_desc - (intptr_t)bonus_desc->o_main) + (intptr_t)bonus_desc->o_dobjdesc);
// // 	atrack = (void**) ((uintptr_t) ((uintptr_t)gGroundInfo->gr_desc[1].dobj_desc - (intptr_t)bonus_desc->o_main) + (intptr_t)bonus_desc->o_anim);
	
// // 	gGroundStruct.bonus1.target_count = 0;
	
// // 	dobj_desc++, atrack++;
	
// // 	while (dobj_desc->index != 0x12)
// // 	{
// // 		GObj* item_gobj = itManager_MakeItemSetupCommon(NULL, It_Kind_Target, &dobj_desc->translate, &sp48, 1);

// // 		if (*atrack != NULL) 
// // 		{
// // 			omAddDObjAnimAll(DObjGetStruct(item_gobj), *atrack, 0.0F);
// // 			func_8000DF34(item_gobj);
// // 		}
// // 		dobj_desc++, atrack++, gGroundStruct.bonus1.target_count++;
// // 	}
// // 	if (gGroundStruct.bonus1.target_count != 10)
// // 	{
// // 		fatal_printf("Error : not %d targets!\n", 10);
// // 		while(TRUE);
// // 	}
// // }