#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "blend_palette.h"
#include "decompress.h"
#include "palette.h"
#include "rng.h"
#include "rom_8077ABC.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"

struct __attribute__((packed)) Some3ByteStruct {
    u8 unkArr[3];
};

extern s16 gBattleAnimArgs[8];
extern u8 gBattleAnimPlayerMonIndex;
extern u8 gBattleAnimEnemyMonIndex;
extern struct SpriteTemplate gSpriteTemplate_83D631C;
extern struct SpriteTemplate gSpriteTemplate_83D6884;
extern struct SpriteTemplate gBattleAnimSpriteTemplate_83D6FC8;
extern struct SpriteTemplate gBattleAnimSpriteTemplate_83D6FF8;
extern s16 gUnknown_03000728[];
extern s8 gUnknown_083D680C[11][3];
extern u16 gUnknown_083D6984[];
extern s8 gUnknown_083D6DDC[4][2];
extern u8 gObjectBankIDs[];
extern u8 gNoOfAllBanks;
extern u8 gHealthboxIDs[];
extern u16 gUnknown_083D712C[4][6];

void sub_80CA768(struct Sprite* sprite);
void sub_80CA8B4(struct Sprite* sprite);
void sub_80CA9F8(struct Sprite* sprite);
void sub_80CAACC(struct Sprite* sprite);
void sub_80CAB88(struct Sprite* sprite);
void sub_80CABC0(struct Sprite* sprite);
void sub_80CAC44(struct Sprite* sprite);
void sub_80CADA8(struct Sprite* sprite);
void sub_80CAE74(struct Sprite* sprite);
void sub_80CAF20(struct Sprite* sprite);
void sub_80CAF6C(struct Sprite* sprite);
void sub_80CB09C(struct Sprite* sprite);
void sub_80CB1A4(struct Sprite* sprite);
void sub_80CB298(struct Sprite* sprite);
void sub_80CB2D4(struct Sprite* sprite);
void sub_80CB710(struct Sprite* sprite);
void sub_80CBB60(struct Sprite* sprite);
void sub_80CBC8C(struct Sprite* sprite);
void sub_80CBCF8(struct Sprite* sprite);
void sub_80CBDB0(struct Sprite* sprite);
void sub_80CC408(struct Sprite* sprite);
void sub_80CC580(struct Sprite* sprite);
void sub_80CC7D4(struct Sprite* sprite);
void sub_80CCB00(struct Sprite* sprite);
void sub_80CCCB4(struct Sprite* sprite);
void sub_80CCE0C(struct Sprite* sprite);
void sub_80CCF70(struct Sprite* sprite);
void sub_80CD0CC(struct Sprite* sprite, int unk1, int unk2);
void sub_80CD2D4(struct Sprite* sprite);
void sub_80CD394(struct Sprite* sprite);
void sub_80CD408(struct Sprite* sprite);
void sub_80CD4B8(struct Sprite* sprite);
void sub_80CD4EC(struct Sprite* sprite);
void sub_80CD5A8(struct Sprite* sprite);
void sub_80CD654(struct Sprite* sprite);
void sub_80CD67C(struct Sprite* sprite);
void sub_80CD7CC(struct Sprite* sprite);
void sub_80CD81C(struct Sprite* sprite);
void sub_80CD8A8(struct Sprite* sprite);
void sub_80CD8F8(struct Sprite* sprite);
void sub_80CD91C(struct Sprite* sprite);
void sub_80CD9B8(struct Sprite* sprite);
void sub_80CD9D4(struct Sprite* sprite);
void sub_80CDE78(struct Sprite* sprite);
void sub_80CDEB0(struct Sprite* sprite);
void sub_80CDEC0(struct Sprite* sprite);
void sub_80CDF70(struct Sprite* sprite);
void sub_80CE000(struct Sprite* sprite);
void sub_80CE1AC(struct Sprite* sprite);
void sub_80CE354(struct Sprite* sprite);
void sub_80CE3B0(struct Sprite* sprite);
void sub_80CE798(struct Sprite* sprite);
void sub_80CE974(struct Sprite* sprite);

s16 sub_80CC338(struct Sprite* sprite);

void sub_80787B0(struct Sprite *sprite, u8 a2);
void sub_8078764(struct Sprite *sprite, u8 a2);
void sub_8078B34(struct Sprite *sprite);
void sub_8078D60(struct Sprite *sprite);
void sub_80786EC(struct Sprite *sprite);
void sub_80782D8(struct Sprite *sprite);
void sub_8078CC0(struct Sprite *sprite);
void sub_8078600(struct Sprite *sprite);
void sub_8078504(struct Sprite *sprite);
void sub_807861C(struct Sprite *sprite);
void sub_8078650(struct Sprite *sprite);
void sub_8078394(struct Sprite *sprite);

extern void sub_8043DB0();
extern void sub_8043DFC();

void sub_807A3FC(u8 slot, u8 a2, s16 *a3, s16 *a4);
u8 sub_8079ED4(u8 slot);
s8 sub_8076F98(s8 a);
int sub_807A100(u8 slot, u8 a2);
u16 sub_80790F0(s16 a, s16 b);
void sub_8078FDC(struct Sprite *sprite, bool8 a2, s16 xScale, s16 yScale, u16 rotation);
void sub_807867C(struct Sprite *sprite, s16 a2);
u8 sub_8077EE4(u8 slot, u8 a2);
u32 sub_80791A8(u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7);
u32 sub_80792C0(u8 a1, u8 a2, u8 a3, u8 a4);
s16 duplicate_obj_of_side_rel2move_in_transparent_mode(u8 a1);
void obj_delete_but_dont_free_vram(struct Sprite *sprite);

void move_anim_8074EE0(struct Sprite *sprite);
bool8 sub_8078718(struct Sprite *sprite);
bool8 sub_8078CE8(struct Sprite *sprite);

void sub_80CB3A8(u8 taskId);
void sub_80CB438(u8 taskId);
void sub_80CBF5C(u8 taskId);
void sub_80CDB60(u8 taskId);
void sub_80CDD20(u8 taskId);
void sub_80CE4D4(u8 taskId);
void sub_80CE910(u8 taskId);

void sub_80CC358(struct Task* task, u8 taskId);

void sub_80CA710(struct Sprite* sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data1 = gBattleAnimArgs[3];
    if (GetBankSide(gBattleAnimPlayerMonIndex))
    {
        sprite->data3 = -gBattleAnimArgs[4];
    }
    else
    {
        sprite->data3 = gBattleAnimArgs[4];
    }
    sprite->data4 = gBattleAnimArgs[5];
    sprite->callback = sub_80CA768;
}

void sub_80CA768(struct Sprite* sprite)
{
    if (sprite->data0 > 0)
    {
        sprite->data0--;
        sprite->pos2.y = sprite->data2 >> 8;
        sprite->data2 += sprite->data1;
        sprite->pos2.x = Sin(sprite->data5, sprite->data3);
        sprite->data5 = (sprite->data5 + sprite->data4) & 0xFF;
    }
    else
    {
        move_anim_8072740(sprite);
    }
}

void sub_80CA7B0(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
    sprite->callback = sub_8078B34;
    oamt_set_x3A_32(sprite, move_anim_8074EE0);
}

void sub_80CA800(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    StartSpriteAnim(sprite, gBattleAnimArgs[3]);
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    sprite->callback = sub_8078B34;
    oamt_set_x3A_32(sprite, move_anim_8072740);
}

void sub_80CA858(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data1 = sprite->pos1.x;
    sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    sprite->data3 = sprite->pos1.y;
    sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    obj_translate_based_on_private_1_2_3_4(sprite);
    sprite->data5 = gBattleAnimArgs[3];
    sprite->callback = sub_80CA8B4;
    sub_80CA8B4(sprite);
}

void sub_80CA8B4(struct Sprite* sprite)
{
    if(sub_8078B5C(sprite))
    {
        DestroySprite(sprite);
    }
    else
    {
        if(sprite->data5 > 0x7F)
        {
            sprite->subpriority = sub_8079E90(gBattleAnimEnemyMonIndex) + 1;
        }
        else
        {
            sprite->subpriority = sub_8079E90(gBattleAnimEnemyMonIndex) + 6;
        }
        sprite->pos2.x += Sin(sprite->data5, 5);
        sprite->pos2.y += Cos(sprite->data5, 14);
        sprite->data5 = (sprite->data5 + 15) & 0xFF;
    }
}

void sub_80CA928(u8 taskId)
{
    gTasks[taskId].data[0]--;
    if (gTasks[taskId].data[0] == -1)
    {
        gTasks[taskId].data[1]++;
        gTasks[taskId].data[0] = 6;
        gBattleAnimArgs[0] = 15;
        gBattleAnimArgs[1] = 0;
        gBattleAnimArgs[2] = 80;
        gBattleAnimArgs[3] = 0;
        CreateSpriteAndAnimate(&gSpriteTemplate_83D631C, 0, 0, sub_8079E90(gBattleAnimEnemyMonIndex) + 1);
    }
    if (gTasks[taskId].data[1] == 15) DestroyAnimVisualTask(taskId);
}

void sub_80CA9A8(struct Sprite* sprite)
{
    sub_8078764(sprite, 1);
    sprite->data0 = gBattleAnimArgs[3];
    sprite->data2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
    sprite->data5 = gBattleAnimArgs[2];
    sub_80786EC(sprite);
    sprite->callback = sub_80CA9F8;
}

void sub_80CA9F8(struct Sprite* sprite)
{
    if (sub_8078718(sprite)) move_anim_8072740(sprite);
}

void sub_80CAA14(struct Sprite* sprite)
{
    u16 a = Random();
    u16 b;
    
    StartSpriteAnim(sprite, a & 7);
    sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
    if (GetBankSide(gBattleAnimPlayerMonIndex))
    {
        sprite->pos1.x -= 20;
    }
    else
    {
        sprite->pos1.x += 20;
    }
    b = Random();
    sprite->data0 = (b & 31) + 64;
    sprite->data1 = sprite->pos1.x;
    sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    sprite->data3 = sprite->pos1.y;
    sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    sub_8078D60(sprite);
    sprite->data5 = Random() & 0xFF;
    sprite->data6 = sprite->subpriority;
    sprite->callback = sub_80CAACC;
    sub_80CAACC(sprite);
}

void sub_80CAACC(struct Sprite* sprite)
{
    if (sub_8078CE8(sprite))
    {
        move_anim_8072740(sprite);
    }
    else
    {
        sprite->pos2.y += Cos(sprite->data5, 12);
        if (sprite->data5 <= 0x7E)
        {
            sprite->subpriority = sprite->data6;
        }
        else
        {
            sprite->subpriority = sprite->data6 + 1;
        }
        sprite->data5 = (sprite->data5 + 24) & 0xFF;
    }
}

void sub_80CAB18(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    if(GetBankSide(gBattleAnimPlayerMonIndex))
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    }
    sprite->data0 = gBattleAnimArgs[4];
    sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 0) + gBattleAnimArgs[2];
    sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 1) + gBattleAnimArgs[3];
    sprite->data5 = gBattleAnimArgs[5];
    sub_80786EC(sprite);
    sprite->callback = sub_80CAB88;
}

void sub_80CAB88(struct Sprite* sprite)
{
    if(sub_8078718(sprite))
    {
        sprite->invisible = 1;
        sprite->data0 = 10;
        sprite->callback = sub_80782D8;
        oamt_set_x3A_32(sprite, sub_80CABC0);
    }
}

void sub_80CABC0(struct Sprite* sprite)
{
    sprite->invisible = 0;
    StartSpriteAnim(sprite, 1);
    sprite->data0 = 60;
    sprite->callback = sub_80782D8;
    oamt_set_x3A_32(sprite, move_anim_8072740);
}

void sub_80CABF8(struct Sprite* sprite)
{
    sub_8078764(sprite, 1);
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    if (gBattleAnimArgs[4] == 1)
    {
        sprite->oam.objMode = 1;
    }
    sprite->data0 = gBattleAnimArgs[3];
    sprite->data1 = gBattleAnimArgs[2];
    sprite->callback = sub_80CAC44;
    sub_80CAC44(sprite);
}

void sub_80CAC44(struct Sprite* sprite)
{

    u8 b;
    
    sprite->pos2.x = Sin(sprite->data1, 32);
    sprite->pos2.y = Cos(sprite->data1, -3) + ((sprite->data2 += 24) >> 8);
    if ((u16)(sprite->data1 - 0x40) < 0x80)
    {
        sprite->oam.priority = (sub_8079ED4(gBattleAnimEnemyMonIndex) & 3);
    }
    else
    {
        b = sub_8079ED4(gBattleAnimEnemyMonIndex) + 1;
        if ( b > 3)
        {
            b = 3;
        }
        sprite->oam.priority = b;
    }
    sprite->data1 = (sprite->data1 + 2) & 0xFF;
    sprite->data0--;
    if (sprite->data0 == -1) move_anim_8072740(sprite);
}

void sub_80CACEC(u8 taskId)
{
    if(IsContest() || !IsDoubleBattle())
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (GetBankIdentity_permutated(gBattleAnimEnemyMonIndex) == 1)
        {
            REG_BG2CNT_BITFIELD.priority = 3;
        }
        else
        {
            REG_BG1CNT_BITFIELD.priority = 1;
        }
        DestroyAnimVisualTask(taskId);
    }
}

void sub_80CAD54(struct Sprite* sprite)
{
    sub_80787B0(sprite, 0);
    sprite->data0 = gBattleAnimArgs[3];
    sprite->data1 = sprite->pos1.x;
    sprite->data2 = sprite->pos1.x;
    sprite->data3 = sprite->pos1.y;
    sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3) + gBattleAnimArgs[2];
    obj_translate_based_on_private_1_2_3_4(sprite);
    sprite->data5 = 0x40;
    sprite->callback = sub_80CADA8;
    sub_80CADA8(sprite);
}

void sub_80CADA8(struct Sprite* sprite)
{
    if(!sub_8078B5C(sprite))
    {
        sprite->pos2.x += Sin(sprite->data5, 32);
        sprite->pos2.y += Cos(sprite->data5, -5);
        if ((u16)(sprite->data5 - 0x40) < 0x80)
        {
            sprite->subpriority = sub_8079E90(gBattleAnimPlayerMonIndex) - 1;
        }
        else
        {
            sprite->subpriority = sub_8079E90(gBattleAnimPlayerMonIndex) + 1;
        }
        sprite->data5 = (sprite->data5 + 5) & 0xFF;
    }
    else
    {
        move_anim_8072740(sprite);
    }
}

void sub_80CAE20(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    sprite->data0 = gBattleAnimArgs[3];
    sprite->data1 = sprite->pos1.x;
    sprite->data2 = sprite->pos1.x;
    sprite->data3 = sprite->pos1.y;
    sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3) + gBattleAnimArgs[2];
    obj_translate_based_on_private_1_2_3_4(sprite);
    sprite->data5 = 0x40;
    sprite->callback = sub_80CAE74;
    sub_80CAE74(sprite);
}

void sub_80CAE74(struct Sprite* sprite)
{
    if(!sub_8078B5C(sprite))
    {
        sprite->pos2.x += Sin(sprite->data5, 8);
        if ((u16)(sprite->data5 - 0x3B) < 5 || (u16)(sprite->data5 - 0xBB) < 5)
        {
            sprite->oam.matrixNum ^= 8;
        }
        sprite->data5 = (sprite->data5 + 5) & 0xFF;
    }
    else
    {
       move_anim_8072740(sprite);
    }
}

void sub_80CAED8(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
    sprite->data0 = gBattleAnimArgs[0];
    sprite->data1 = gBattleAnimArgs[1];
    sprite->data2 = gBattleAnimArgs[2];
    sprite->callback = sub_80CAF20;
}

void sub_80CAF20(struct Sprite* sprite)
{
    if(!sprite->data2)
    {
        if(sprite->data1 & 1)
        {
            sprite->data0 = 0x80;
            sprite->data1 = 0;
            sprite->data2 = 0;
        }
        else
        {
            sprite->data0 = sprite->data1 & 1;
            sprite->data1 = sprite->data1 & 1;
            sprite->data2 = sprite->data1 & 1;
        }
        sprite->callback = sub_80CAF6C;
    }
    else
    {
        sprite->data2--;
        sprite->pos1.x += sprite->data0;
        sprite->pos1.y += sprite->data1;
    }
}

void sub_80CAF6C(struct Sprite* sprite)
{
    if(GetBankSide(gBattleAnimPlayerMonIndex))
    {
        sprite->pos2.x = -Sin(sprite->data0, 0x19);
    }
    else
    {
        sprite->pos2.x = Sin(sprite->data0, 0x19);
    }
    sprite->data0 = (sprite->data0 + 2) & 0xFF;
    sprite->data1++;
    if(!(sprite->data1 & 1))
    {
        sprite->pos2.y++;
    }
    if(sprite->data1 > 0x50)
    {
        move_anim_8072740(sprite);
    }
}

void sub_80CAFD0(struct Sprite* sprite)
{
    sub_80787B0(sprite, 1);
    if(GetBankSide(gBattleAnimPlayerMonIndex))
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    }
    sprite->data0 = gBattleAnimArgs[4];
    if(!(gBattleAnimArgs[6]))
    {
        sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + gBattleAnimArgs[2];
        sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + gBattleAnimArgs[3];
    }
    else
    {
        sub_807A3FC(gBattleAnimEnemyMonIndex, 1, &sprite->data2, &sprite->data4);
        sprite->data2 += gBattleAnimArgs[2];
        sprite->data4 += gBattleAnimArgs[3];
    }
    sprite->data5 = gBattleAnimArgs[5];
    sub_80786EC(sprite);
    if(GetBankSide(gBattleAnimPlayerMonIndex) == GetBankSide(gBattleAnimEnemyMonIndex))
    {
        sprite->data0 = 1;
    }
    else
    {
        sprite->data0 = 0;
    }
    sprite->callback = sub_80CB09C;
}

void sub_80CB09C(struct Sprite* sprite)
{
    bool8 c = FALSE;
    s16 a = sprite->data0;
    s16 b = sprite->data7;
    s16 r0;
    
    sprite->data0 = 1;
    sub_8078718(sprite);
    r0 = sprite->data7;
    sprite->data0 = a;
    if (b > 0xC8 && r0 <= 0x37 && sprite->oam.affineParam == 0)
        sprite->oam.affineParam++;
    if (sprite->oam.affineParam != 0 && sprite->data0 != 0)
    {
        sprite->invisible ^= 1;
        sprite->oam.affineParam++;
        if (sprite->oam.affineParam == 0x1E)
            c = TRUE;
    }
    
    if (sprite->pos1.x + sprite->pos2.x > 0x100
     || sprite->pos1.x + sprite->pos2.x < -16
     || sprite->pos1.y + sprite->pos2.y > 0xA0
     || sprite->pos1.y + sprite->pos2.y < -16)
        c = TRUE;

    if (c)
        move_anim_8072740(sprite);
}

void sub_80CB144(struct Sprite* sprite)
{
    if(!IsContest() && IsDoubleBattle() == TRUE)
    {
        sub_807A3FC(gBattleAnimEnemyMonIndex, 1, &sprite->pos1.x, &sprite->pos1.y);
    }
    sprite->pos1.y += 32;
    sprite->data0 = gBattleAnimArgs[0];
    sprite->data1 = gBattleAnimArgs[1];
    sprite->data2 = gBattleAnimArgs[2];
    sprite->data3 = gBattleAnimArgs[3];
    sprite->data4 = gBattleAnimArgs[4];
    sprite->callback = sub_80CB1A4;
}

void sub_80CB1A4(struct Sprite* sprite)
{
    if(sprite->data1 == 0xFF)
    {
        sprite->pos1.y -= 2;
    }
    else if(sprite->data1 > 0)
    {
        sprite->pos1.y -= 2;
        sprite->data1 -= 2;
    }
    sprite->data5 += sprite->data2;
    if(sprite->data0 < sprite->data4) sprite->data5 += sprite->data2;
    sprite->data5 &= 0xFF;
    sprite->pos2.x = Cos(sprite->data5, sprite->data3);
    sprite->pos2.y = Sin(sprite->data5, 5);
    if(sprite->data5 <= 0x7F)
    {
        sprite->oam.priority = sub_8079ED4(gBattleAnimEnemyMonIndex) - 1;
    }
    else
    {
        sprite->oam.priority = sub_8079ED4(gBattleAnimEnemyMonIndex) + 1;
    }
    sprite->data0--;
    if(!sprite->data0) move_anim_8072740(sprite);
}

void sub_80CB25C(struct Sprite* sprite)
{
    sub_8078764(sprite, 0);
    sprite->affineAnimPaused = 1;
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[2]);
    sprite->data6 = gBattleAnimArgs[2];
    sprite->data7 = gBattleAnimArgs[3];
    sprite->callback = sub_80CB298;
}

void sub_80CB298(struct Sprite* sprite)
{
    if((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->affineAnimPaused = 0;
        obj_id_for_side_relative_to_move(1);
        sprite->data0 = 0x100;
        sprite->callback = sub_80CB2D4;
    }
}

void sub_80CB2D4(struct Sprite* sprite)
{
    obj_id_for_side_relative_to_move(1);
    if(!sprite->data2)
    {
        sprite->data0 += 11;
    }
    else
    {
        sprite->data0 -= 11;
    }
    sprite->data1++;
    if(sprite->data1 == 6)
    {
        sprite->data1 = 0;
        sprite->data2 ^= 1;
    }
    if(sprite->affineAnimEnded)
    {
        sprite->data7--;
        if(sprite->data7 > 0)
        {
            StartSpriteAffineAnim(sprite, sprite->data6);
        }
        else
        {
            move_anim_8072740(sprite);
        }
    }
}

void sub_80CB340(u8 taskId)
{
    u8 spriteId = obj_id_for_side_relative_to_move(1);
    if(gSprites[spriteId].invisible)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        sub_8078E70(spriteId, 1);
        gTasks[taskId].data[0] = gBattleAnimArgs[0];
        gTasks[taskId].data[1] = gBattleAnimArgs[1];
        gTasks[taskId].data[11] = 256;
        gTasks[taskId].func = sub_80CB3A8;
    }
}

void sub_80CB3A8(u8 taskId)
{
    u8 spriteId = obj_id_for_side_relative_to_move(1);
    gTasks[taskId].data[10] += gTasks[taskId].data[0];
    gSprites[spriteId].pos2.x = gTasks[taskId].data[10] >> 8;
    if(GetBankSide(gBattleAnimEnemyMonIndex))
    {
        gSprites[spriteId].pos2.x = -gSprites[spriteId].pos2.x;
    }
    gTasks[taskId].data[11] += 16;
    obj_id_set_rotscale(spriteId, gTasks[taskId].data[11], gTasks[taskId].data[11], 0);
    sub_8079A64(spriteId);
    gTasks[taskId].data[1]--;
    if(!gTasks[taskId].data[1])
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80CB438;
    }
}

void sub_80CB438(u8 taskId)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            u8 spriteId = obj_id_for_side_relative_to_move(1);
            sub_8078F40(spriteId);
            gSprites[spriteId].pos2.x = 0;
            gSprites[spriteId].pos2.y = 0;
            gTasks[taskId].data[0]++;
            return;
        }
    }
    else
    {
        if (gTasks[taskId].data[0] == 0)
            return;
    }
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 3)
        DestroyAnimVisualTask(taskId);
}

void sub_80CB4CC(struct Sprite* sprite)
{
    switch(sprite->data0)
    {
        case 0:
        {
            if(GetBankSide(gBattleAnimEnemyMonIndex) == 0)
            {
                s16 a = gBattleAnimArgs[0];
                gBattleAnimArgs[0] = -a;
            }
            sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 0) + gBattleAnimArgs[0];
            sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 1) + gBattleAnimArgs[1];
            sprite->invisible = 1;
            sprite->data0++;
            break;
        }
        case 1:
        {
            sprite->invisible = 0;
            if(sprite->affineAnimEnded)
            {
                ChangeSpriteAffineAnim(sprite, 1);
                sprite->data0 = 25;
                sprite->data2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
                sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
                sprite->callback = sub_8078CC0;
                oamt_set_x3A_32(sprite, move_anim_8072740);
                break;
            }
        }
    }
}

void sub_80CB59C(struct Sprite* sprite)
{
    if(!sprite->data0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
        sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 1);
        sprite->pos2.x = gBattleAnimArgs[0];
        sprite->pos2.y = gBattleAnimArgs[1];
        sprite->subpriority = gBattleAnimArgs[2] + 30;
        StartSpriteAnim(sprite, gBattleAnimArgs[3]);
        sprite->data2 = gBattleAnimArgs[4];
        sprite->data0++;
        if((sprite->pos1.y + sprite->pos2.y) > 120)
        {
            sprite->pos1.y += -120 + (sprite->pos2.y + sprite->pos1.y);
        }
    }
    sprite->callback = sub_80CB710;
}

void sub_80CB620(struct Sprite *sprite)
{
    s16 p1 = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    s16 p2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
    s16 e1 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    s16 e2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);

    e1 -= p1;
    e2 -= p2;
    sprite->pos1.x = p1 + e1 * gBattleAnimArgs[0] / 100;
    sprite->pos1.y = p2 + e2 * gBattleAnimArgs[0] / 100;
    sprite->pos2.x = gBattleAnimArgs[1];
    sprite->pos2.y = gBattleAnimArgs[2];
    sprite->subpriority = gBattleAnimArgs[3] + 30;
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    sprite->data2 = gBattleAnimArgs[5];
    sprite->callback = sub_80CB710;
    gUnknown_03000728[0] = sprite->pos1.x;
    gUnknown_03000728[1] = sprite->pos1.y;
    gUnknown_03000728[2] = e1;
    gUnknown_03000728[3] = e2;
}

void sub_80CB710(struct Sprite* sprite)
{
    if(++sprite->data0 > (sprite->data2 - 10))
    {
        sprite->invisible = sprite->data0 % 2;
    }
    if(sprite->data0 > sprite->data2) move_anim_8072740(sprite);
}

void sub_80CB768(struct Sprite* sprite)
{
    if(!sprite->data0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2) + gBattleAnimArgs[0];
        sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 1) + gBattleAnimArgs[1];
        sprite->data1 = gBattleAnimArgs[2];
        sprite->data2 = gBattleAnimArgs[3];
        sprite->data3 = gBattleAnimArgs[4];
    }
    sprite->data0++;
    sprite->pos2.x = sprite->data1 * sprite->data0;
    sprite->pos2.y = Sin((sprite->data0 * 20) & 0xFF, sprite->data2);
    if(sprite->data0 > sprite->data3) move_anim_8072740(sprite);
}

void sub_80CB7EC(struct Sprite* sprite, s16 c)
{
    s32 a = (sprite->pos1.x * 256) | sprite->pos1.y;
    s32 b = (sprite->data6 * 256) | sprite->data7;
    c *= 256;
    sprite->data5 = a;
    sprite->data6 = b;
    sprite->data7 = c;
}

#ifdef NONMATCHING
bool8 sub_80CB814(struct Sprite* sprite)
{
    s32 r10 = (u8)(sprite->data5 >> 8);
    s32 r9 = (u8)sprite->data5;
    s32 r2 = (u8)(sprite->data6 >> 8);
    s16 r4 = (u8)sprite->data6;
    u16 r6 = sprite->data7 >> 8;
    s16 r3 = sprite->data7 & 0xFF;
    s32 var1;
    s32 var2;
    
    if (r2 == 0)
        r2 = -32;
    else if (r2 == 255)
        r2 = 0x110;
    
    r4 -= r9;
    var1 = (r2 - r10) * r3 / r6;
    var2 = r4 * r3 / r6;
    sprite->pos1.x = var1 + r10;
    sprite->pos2.y = var2 + r9;
    r3++;
    if ((u16)r3 == r6)
        return TRUE;
    sprite->data7 = r3 | (r6 << 8);
    return FALSE;
}
#else
__attribute__((naked))
bool8 sub_80CB814(struct Sprite* sprite)
{
    asm(".syntax unified\n\
        push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    mov r8, r0\n\
    ldrh r0, [r0, 0x38]\n\
    lsrs r1, r0, 8\n\
    mov r10, r1\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r9, r0\n\
    mov r1, r8\n\
    ldrh r0, [r1, 0x3A]\n\
    lsrs r2, r0, 8\n\
    lsls r0, 24\n\
    lsrs r4, r0, 24\n\
    ldrh r1, [r1, 0x3C]\n\
    lsls r0, r1, 16\n\
    asrs r0, 24\n\
    lsls r0, 16\n\
    lsrs r6, r0, 16\n\
    movs r3, 0xFF\n\
    ands r3, r1\n\
    cmp r2, 0\n\
    bne _080CB84E\n\
    movs r2, 0x20\n\
    negs r2, r2\n\
    b _080CB856\n\
_080CB84E:\n\
    cmp r2, 0xFF\n\
    bne _080CB856\n\
    movs r2, 0x88\n\
    lsls r2, 1\n\
_080CB856:\n\
    mov r0, r9\n\
    subs r4, r0\n\
    lsls r4, 16\n\
    lsrs r4, 16\n\
    mov r1, r10\n\
    subs r0, r2, r1\n\
    lsls r5, r3, 16\n\
    asrs r5, 16\n\
    muls r0, r5\n\
    lsls r1, r6, 16\n\
    asrs r7, r1, 16\n\
    adds r1, r7, 0\n\
    bl __divsi3\n\
    adds r6, r0, 0\n\
    lsls r4, 16\n\
    asrs r4, 16\n\
    adds r0, r4, 0\n\
    muls r0, r5\n\
    adds r1, r7, 0\n\
    bl __divsi3\n\
    add r6, r10\n\
    mov r1, r8\n\
    strh r6, [r1, 0x20]\n\
    add r0, r9\n\
    strh r0, [r1, 0x22]\n\
    adds r5, 0x1\n\
    lsls r5, 16\n\
    lsrs r3, r5, 16\n\
    asrs r5, 16\n\
    cmp r5, r7\n\
    beq _080CB8A8\n\
    lsls r1, r7, 8\n\
    lsls r0, r3, 16\n\
    asrs r0, 16\n\
    orrs r0, r1\n\
    mov r1, r8\n\
    strh r0, [r1, 0x3C]\n\
    movs r0, 0\n\
    b _080CB8AA\n\
_080CB8A8:\n\
    movs r0, 0x1\n\
_080CB8AA:\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .syntax divided\n");
}
#endif

void sub_80CB8B8(struct Sprite* sprite)
{
    if(sprite->data0 == 10)
    {
        StartSpriteAffineAnim(sprite, 1);
    }
    sprite->data0++;
    if(sprite->data0 > 50) move_anim_8072740(sprite);
}

#ifdef NONMATCHING
void sub_80CB8E8(struct Sprite* sprite)
{
    int temp = ((sprite->data3 * 128) / sprite->data4) + sprite->data0;
    int zero = 0;
    sprite->data0 = temp;
    if(sprite->data0 > 0x7F)
    {
        sprite->data1++;
        sprite->data0 = zero;
    }
    sprite->pos2.y = Sin(sprite->data0 + 0x80, (sprite->data1 * 8) - 30);
    if(!sub_80CB814(sprite))
    {
        sprite->pos2.y = zero;
        sprite->data0 = zero;
        sprite->callback = sub_80CB8B8;
    }
}
#else
__attribute__((naked))
void sub_80CB8E8(struct Sprite* sprite)
{
    asm(".syntax unified\n\
        push {r4,r5,lr}\n\
    adds r4, r0, 0\n\
    movs r1, 0x34\n\
    ldrsh r0, [r4, r1]\n\
    lsls r0, 7\n\
    movs r2, 0x36\n\
    ldrsh r1, [r4, r2]\n\
    bl __divsi3\n\
    ldrh r1, [r4, 0x2E]\n\
    adds r1, r0\n\
    movs r5, 0\n\
    strh r1, [r4, 0x2E]\n\
    lsls r1, 16\n\
    asrs r1, 16\n\
    cmp r1, 0x7F\n\
    ble _080CB912\n\
    ldrh r0, [r4, 0x30]\n\
    adds r0, 0x1\n\
    strh r0, [r4, 0x30]\n\
    strh r5, [r4, 0x2E]\n\
_080CB912:\n\
    ldrh r0, [r4, 0x2E]\n\
    adds r0, 0x80\n\
    lsls r0, 16\n\
    asrs r0, 16\n\
    movs r1, 0x30\n\
    ldrsh r2, [r4, r1]\n\
    lsls r2, 3\n\
    movs r1, 0x1E\n\
    subs r1, r2\n\
    lsls r1, 16\n\
    asrs r1, 16\n\
    bl Sin\n\
    strh r0, [r4, 0x26]\n\
    adds r0, r4, 0\n\
    bl sub_80CB814\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _080CB942\n\
    strh r5, [r4, 0x26]\n\
    strh r5, [r4, 0x2E]\n\
    ldr r0, _080CB948 @ =sub_80CB8B8\n\
    str r0, [r4, 0x1C]\n\
_080CB942:\n\
    pop {r4,r5}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_080CB948: .4byte sub_80CB8B8\n\
    .syntax divided\n");
}
#endif

void sub_80CB94C(struct Sprite* sprite)
{
    s16 e1;
    s16 e2;
    sub_80787B0(sprite, 0);
    e1 = sub_8077ABC(gBattleAnimEnemyMonIndex, 0);
    e2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 1);
    if((gBattleAnimPlayerMonIndex ^ 2) == gBattleAnimEnemyMonIndex)
    {
        sprite->data6 = e1;
        sprite->data7 = e2 + 10;
        sub_80CB7EC(sprite, 0x3C);
        sprite->data3 = 1;
    }
    else
    {
        sprite->data6 = e1;
        sprite->data7 = e2 + 10;
        sub_80CB7EC(sprite, 0x3C);
        sprite->data3 = 3;
    }
    sprite->data4 = 0x3C;
    sprite->callback = sub_80CB8E8;
}

void sub_80CB9C4(struct Sprite* sprite)
{
    int zero;
    sprite->data0 += ((sprite->data3 * 128) / sprite->data4);
    zero = 0;
    if(sprite->data0 > 0x7F)
    {
        sprite->data1++;
        sprite->data0 = zero;
    }
    sprite->pos2.y = Sin(sprite->data0 + 0x80, 30 - sprite->data1 * 8);
    if(sub_80CB814(sprite))
    {
        sprite->pos2.y = zero;
        sprite->data0 = zero;
        move_anim_8072740(sprite);
    }
}

void sub_80CBA28(struct Sprite* sprite)
{
    s16 e = sub_8077ABC(gBattleAnimEnemyMonIndex, 1);
    if(GetBankSide(gBattleAnimEnemyMonIndex) == 0)
    {
        sprite->data6 = 0;
        sprite->data7 = e + 10;
        sub_80CB7EC(sprite, 0x28);
        sprite->data3 = 3;
        sprite->data4 = 0x3C;
        sprite->callback = sub_80CB8E8;
    }
    else
    {
        sprite->data6 = 255;
        sprite->data7 = e + 10;
        if(IsContest()) sprite->data6 = 0;
        sub_80CB7EC(sprite, 0x28);
        sprite->data3 = 3;
        sprite->data4 = 0x3C;
        sprite->callback = sub_80CB9C4;
    }
}

void sub_80CBAA4(struct Sprite* sprite)
{
    if(sprite->data0 == 0)
    {
        sub_8078764(sprite, 0);
        sprite->data1 = gBattleAnimArgs[2];
    }
    sprite->data0++;
    sprite->pos2.y = sprite->data1 * sprite->data0;
    if(sprite->animEnded) move_anim_8072740(sprite);
}

void sub_80CBAE8(struct Sprite* sprite)
{
    s16 p1;
    s16 p2;
    sub_8078764(sprite, 0);
    p1 = sub_8077ABC(gBattleAnimPlayerMonIndex, 0);
    p2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 1);
    if((gBattleAnimEnemyMonIndex ^ 2) == gBattleAnimPlayerMonIndex)
    {
        sprite->data6 = p1;
        sprite->data7 = p2 + 10;
        sub_80CB7EC(sprite, 0x3c);
        sprite->data3 = 1;
    }
    else
    {
        sprite->data6 = p1;
        sprite->data7 = p2 + 10;
        sub_80CB7EC(sprite, 0x3c);
        sprite->data3 = 3;
    }
    sprite->data4 = 0x3C;
    sprite->callback = sub_80CBB60;
}

void sub_80CBB60(struct Sprite* sprite)
{
    int zero;
    sprite->data0 += ((sprite->data3 * 128) / sprite->data4);
    zero = 0;
    if(sprite->data0 > 0x7F)
    {
        sprite->data1++;
        sprite->data0 = zero;
    }
    sprite->pos2.y = Sin(sprite->data0 + 0x80, 30 - sprite->data1 * 8);
    if(sprite->pos2.y == 0)
    {
        PlaySE12WithPanning(0x7D, sub_8076F98(0x3F));
    }
    if(sub_80CB814(sprite))
    {
        sprite->pos2.y = 0;
        sprite->data0 = 0;
        sprite->callback = sub_80CB8B8;
        PlaySE12WithPanning(0x7D, sub_8076F98(-0x40));
    }
}

void sub_80CBBF0(struct Sprite* sprite)
{
    int a;
    int b;

    if (sprite->data0 == 0)
    {
        if (!IsContest())
        {
            sprite->data1 = gBattleAnimArgs[1];
            sprite->pos1.x = 0x78;
        }
        else
        {
            a = gBattleAnimArgs[1] - 32;
            if (a < 0)
                b = gBattleAnimArgs[1] + 0xDF;
            else
                b = a;
            sprite->data1 = a - ((b >> 8) << 8);
            sprite->pos1.x = 0x46;

        }
        sprite->pos1.y = gBattleAnimArgs[0];
        sprite->data2 = gBattleAnimArgs[0];
        sprite->data4 = 20;
        sprite->pos2.x = Cos(sprite->data1, 0x3C);
        sprite->pos2.y = Sin(sprite->data1, 20);
        sprite->callback = sub_80CBC8C;
        if (sprite->data1 > 0 && sprite->data1 < 0xC0)
            sprite->subpriority = 31;
        else
            sprite->subpriority = 29;
    }
}

void sub_80CBC8C(struct Sprite* sprite)
{
    switch(sprite->data3)
    {
        case 0:
        {
            if(sprite->data2 > 0x4E)
            {
                sprite->data3 = 1;
                StartSpriteAffineAnim(sprite, 1);
                break;
            }
            else
            {
                sprite->data2 += sprite->data4 / 10;
                sprite->data4 += 3;
                sprite->pos1.y = sprite->data2;
                break;
            }
        }
        case 1:
        {
            if(sprite->data3 && sprite->affineAnimEnded)
            {
                sprite->data0 = 0;
                sprite->data2 = 0;
                sprite->callback = sub_80CBCF8;
            }
            break;
        }
    }
}



void sub_80CBCF8(struct Sprite* sprite)
{
    if(sprite->data2 == gUnknown_083D680C[sprite->data0][1])
	{
	    if(gUnknown_083D680C[sprite->data0][2] == 0x7F)
		{
		    sprite->data0 = 0;
			sprite->callback = sub_80CBDB0;
		}
		sprite->data2 = 0;
		sprite->data0++;
	}
	else
	{
	    sprite->data2++;
		sprite->data1 = (gUnknown_083D680C[sprite->data0][0] * gUnknown_083D680C[sprite->data0][2] + sprite->data1) & 0xFF;
		if (!IsContest())
		{
		    if((u16)(sprite->data1 - 1) <= 0xBE)
            {
			    sprite->subpriority = 31;
			}
			else
			{
			    sprite->subpriority = 29;
		    }
		}
		sprite->pos2.x = Cos(sprite->data1, 0x3C);
		sprite->pos2.y = Sin(sprite->data1, 20);
	}
}

void sub_80CBDB0(struct Sprite* sprite)
{
    if(sprite->data0 > 20) move_anim_8072740(sprite);
	sprite->invisible = sprite->data0 % 2;
	sprite->data0++;
}

void sub_80CBDF4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[4] = sub_8079E90(gBattleAnimEnemyMonIndex) - 1;
    task->data[6] = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    task->data[7] = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    task->data[10] = sub_807A100(gBattleAnimEnemyMonIndex, 1);
    task->data[11] = sub_807A100(gBattleAnimEnemyMonIndex, 0);
    task->data[5] = (GetBankSide(gBattleAnimEnemyMonIndex) == 1) ? 1 : -1;
    task->data[9] = 0x38 - (task->data[5] * 64);
    task->data[8] = task->data[7] - task->data[9] + task->data[6];
    task->data[2] = CreateSprite(&gSpriteTemplate_83D6884, task->data[8], task->data[9], task->data[4]);
    if (task->data[2] == 0x40)
        DestroyAnimVisualTask(taskId);
    gSprites[task->data[2]].data0 = 10;
    gSprites[task->data[2]].data1 = task->data[8];
    gSprites[task->data[2]].data2 = task->data[6] - (task->data[10] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data3 = task->data[9];
    gSprites[task->data[2]].data4 = task->data[7] + (task->data[11] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data5 = sub_80CC338(&gSprites[task->data[2]]);
    sub_80786EC(&gSprites[task->data[2]]);
    task->func = sub_80CBF5C;
}

void sub_80CBF5C(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    struct Sprite* sprite = &gSprites[task->data[2]];
    int a = task->data[0];
    switch(a)
    {
        case 4:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            else
            {
                task->data[15] = 5;
                task->data[0] = 0xFF;
                break;
            }
        }
        case 8:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            else
            {
            task->data[15] = 9;
            task->data[0] = 0xFF;
            break;
            }
        }
        case 0:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            task->data[15] = 1;
            task->data[0] = 0xFF;
            break;
        }
        case 1:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[6];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[7];
            sprite->data5 = sub_80CC338(sprite);
            task->data[4] += 2;
            task->data[3] = a;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 2:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            task->data[15] = 3;
            task->data[0] = 0xFF;
            break;
        }
        case 3:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[7] - ((task->data[11] / 2) + 10) * task->data[5];
            sprite->data5 = sub_80CC338(sprite);
            task->data[3] = 2;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 5:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[6] + ((task->data[10] / 2) + 10) * task->data[5];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
            sprite->data5 = sub_80CC338(sprite);
            task->data[4] -= 2;
            task->data[3] = 3;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 6:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            task->data[15] = 7;
            task->data[0] = 0xFF;
            break;
        }
        case 7:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[6];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[7];
            sprite->data5 = sub_80CC338(sprite);
            task->data[4] += 2;
            task->data[3] = 4;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 9:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
            sprite->data5 = sub_80CC338(sprite);
            task->data[3] = 5;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 10:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) == 0)
            {
                break;
            }
            else
            {
                task->data[15] = 11;
                task->data[0] = 0xFF;
                break;
            }
        }
        case 11:
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;
            sprite->data0 = 10;
            sprite->data1 = sprite->pos1.x;
            sprite->data2 = task->data[8];
            sprite->data3 = sprite->pos1.y;
            sprite->data4 = task->data[9];
            sprite->data5 = sub_80CC338(sprite);
            task->data[4] -= 2;
            task->data[3] = 6;
            sprite->subpriority = task->data[4];
            StartSpriteAnim(sprite, task->data[3]);
            sub_80786EC(sprite);
            task->data[0]++;
            break;
        }
        case 12:
        {
            sub_80CC358(task, taskId);
            if(sub_8078718(sprite) != 0)
            {
                DestroySprite(sprite);
                task->data[0]++;
            }
            break;
        }
        case 13:
        {
            if(task->data[12] == 0)
            {
                DestroyAnimVisualTask(taskId);
                break;
            }
            break;
        }
        case 255:
        {
            task->data[1]++;
            if(task->data[1] > 5)
            {
                task->data[1] = 0;
                task->data[0] = task->data[15];
            }
        }
    }
}

s16 sub_80CC338(struct Sprite* sprite)
{
    s16 var = 8;
    if(sprite->data4 < sprite->pos1.y) var = -var;
    return var;
}

void sub_80CC358(struct Task* task, u8 taskId)
{
    task->data[14]++;
    if(task->data[14] > 0)
    {
        u8 spriteId;
        s16 spriteX;
        s16 spriteY;
        task->data[14] = 0;
        spriteX = gSprites[task->data[2]].pos1.x + gSprites[task->data[2]].pos2.x;
        spriteY = gSprites[task->data[2]].pos1.y + gSprites[task->data[2]].pos2.y;
        spriteId = CreateSprite(&gSpriteTemplate_83D6884, spriteX, spriteY, task->data[4]);
        if (spriteId != 0x40)
        {
            gSprites[spriteId].data6 = taskId;
            gSprites[spriteId].data7 = 12;
            gTasks[taskId].data[12]++;
            gSprites[spriteId].data0 = task->data[13] & 1;
            gTasks[taskId].data[13]++;
            StartSpriteAnim(&gSprites[spriteId], task->data[3]);
            gSprites[spriteId].subpriority = task->data[4];
            gSprites[spriteId].callback = sub_80CC408;
        }
    }
}

void sub_80CC408(struct Sprite* sprite)
{
    sprite->data0++;
    if (sprite->data0 > 1)
    {
        sprite->data0 = 0;
        sprite->invisible ^= 1;
        sprite->data1++;
        if(sprite->data1 > 8)
        {
            gTasks[sprite->data6].data[sprite->data7]--;
            DestroySprite(sprite);
        }
    }
}

void sub_80CC474(struct Sprite* sprite)
{
    u8 bank;
    if (!gBattleAnimArgs[6])
        bank = gBattleAnimPlayerMonIndex;
    else
        bank = gBattleAnimEnemyMonIndex;
    if (GetBankSide(bank) != 0)
    {
        sprite->data4 = 0;
        sprite->data2 = gBattleAnimArgs[3];
        sprite->pos1.x = 0xFFF0;
    }
    else
    {
        sprite->data4 = 1;
        sprite->data2 = -gBattleAnimArgs[3];
        sprite->pos1.x = 0x100;
    }
    sprite->data1 = gBattleAnimArgs[1];
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data3 = gBattleAnimArgs[4];
    switch(gBattleAnimArgs[5])
    {
        case 0:
        {
            sprite->pos1.y = gBattleAnimArgs[0];
            sprite->oam.priority = sub_8079ED4(bank);
            break;
        }
        case 1:
        {
            sprite->pos1.y = gBattleAnimArgs[0];
            sprite->oam.priority = sub_8079ED4(bank) + 1;
            break;
        }
        case 2:
        {
            sprite->pos1.y = sub_8077ABC(bank, 3) + gBattleAnimArgs[0];
            sprite->oam.priority = sub_8079ED4(bank);
            break;
        }
        case 3:
        {
            sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + gBattleAnimArgs[0];
            obj_id_for_side_relative_to_move(1);
            sprite->oam.priority = sub_8079ED4(bank) + 1;
            break;
        }
    }
    sprite->callback = sub_80CC580;
}

void sub_80CC580(struct Sprite* sprite)
{
    int a = sprite->data7;
    sprite->data7++;
    sprite->pos2.y = (sprite->data1 * gSineTable[sprite->data0]) >> 8;
    sprite->pos2.x = sprite->data2 * a;
    sprite->data0 = (sprite->data3 * a) & 0xFF;
    if (sprite->data4 == 0)
    {
        if (sprite->pos2.x + sprite->pos1.x <= 0xF7)
            return;
    }
    else
    {
        if (sprite->pos2.x + sprite->pos1.x > -16)
            return;
    }
    move_anim_8074EE0(sprite);
}

void sub_80CC5F8(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    switch(task->data[0])
    {
        case 0:
        {
            task->data[8] = IndexOfSpritePaletteTag(0x274f) * 16 + 256;
            task->data[12] = IndexOfSpritePaletteTag(0x27b0) * 16 + 256;
            task->data[0]++;
            break;
        }
        case 1:
        {
            task->data[9]++;
            if(task->data[9] >= 0)
            {
                task->data[9] = 0;
                BlendPalette(task->data[8], 0x10, task->data[10], gUnknown_083D6984[task->data[11]]);
                BlendPalette(task->data[12], 0x10, task->data[10], gUnknown_083D6984[task->data[11]]);
                task->data[10]++;
                if(task->data[10] == 17)
                {
                    task->data[10] = 0;
                    task->data[11]++;
                    if(task->data[11] == 7) task->data[11] = 0;
                }
            }
            break;
        }
    }
    if(gBattleAnimArgs[7] == -1) DestroyAnimVisualTask(taskId);
}

#ifdef NONMATCHING
void sub_80CC6CC(struct Sprite* sprite)
{
    u8 a;
    u8 b;
    u8 bank;
    int c;
    u16 x;
    u16 y;
    if (gBattleAnimArgs[4] == 0)
    {
        move_anim_8072740(sprite);
    }
    else
    {
        
        if (gBattleAnimArgs[0] == 0) bank = gBattleAnimPlayerMonIndex;
        else
            bank = gBattleAnimEnemyMonIndex;
        a = sub_8077ABC(bank, 2);
        b = sub_8077ABC(bank, 3);
        sprite->data0 = gBattleAnimArgs[4];
        if (gBattleAnimArgs[1] == 0)
        {
            sprite->pos1.x = gBattleAnimArgs[2] + a;
            sprite->pos1.y = gBattleAnimArgs[3] + b;
            sprite->data5 = a;
            sprite->data6 = b;
        }
        else
        {
            sprite->pos1.x = a;
            sprite->pos1.y = b;
            sprite->data5 = gBattleAnimArgs[2] + a;
            sprite->data6 = gBattleAnimArgs[3] + b;
        }
        x = sprite->pos1.x;
        sprite->data1 = x * 16;
        y = sprite->pos1.y;
        sprite->data2 = y * 16;
        sprite->data3 = ((sprite->data5 - sprite->pos1.x) * 16) / gBattleAnimArgs[4];
        sprite->data4 = ((sprite->data6 - sprite->pos1.y) * 16) / gBattleAnimArgs[4];
        c = sub_80790F0(sprite->data5 - x, sprite->data6 - y);
        if(IsContest() != 0) c = c + -0x8000;
        sub_8078FDC(sprite, 0, 0x100, 0x100, c);
        sprite->callback = sub_80CC7D4;
    }
}
#else
__attribute__((naked))
void sub_80CC6CC(struct Sprite* sprite)
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	sub sp, 0x4\n\
	adds r6, r0, 0\n\
	ldr r1, _080CC6E4 @ =gBattleAnimArgs\n\
	movs r2, 0x8\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, 0\n\
	bne _080CC6E8\n\
	adds r0, r6, 0\n\
	bl move_anim_8072740\n\
	b _080CC7C2\n\
	.align 2, 0\n\
_080CC6E4: .4byte gBattleAnimArgs\n\
_080CC6E8:\n\
	movs r3, 0\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, 0\n\
	bne _080CC6F8\n\
	ldr r4, _080CC6F4 @ =gBattleAnimPlayerMonIndex\n\
	b _080CC6FA\n\
	.align 2, 0\n\
_080CC6F4: .4byte gBattleAnimPlayerMonIndex\n\
_080CC6F8:\n\
	ldr r4, _080CC734 @ =gBattleAnimEnemyMonIndex\n\
_080CC6FA:\n\
	ldrb r0, [r4]\n\
	movs r1, 0x2\n\
	bl sub_8077ABC\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	ldrb r0, [r4]\n\
	movs r1, 0x3\n\
	bl sub_8077ABC\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	ldr r0, _080CC738 @ =gBattleAnimArgs\n\
	ldrh r1, [r0, 0x8]\n\
	strh r1, [r6, 0x2E]\n\
	movs r3, 0x2\n\
	ldrsh r1, [r0, r3]\n\
	adds r7, r0, 0\n\
	cmp r1, 0\n\
	bne _080CC73C\n\
	ldrh r0, [r7, 0x4]\n\
	adds r0, r5\n\
	strh r0, [r6, 0x20]\n\
	ldrh r0, [r7, 0x6]\n\
	adds r0, r2\n\
	strh r0, [r6, 0x22]\n\
	strh r5, [r6, 0x38]\n\
	strh r2, [r6, 0x3A]\n\
	b _080CC74C\n\
	.align 2, 0\n\
_080CC734: .4byte gBattleAnimEnemyMonIndex\n\
_080CC738: .4byte gBattleAnimArgs\n\
_080CC73C:\n\
	strh r5, [r6, 0x20]\n\
	strh r2, [r6, 0x22]\n\
	ldrh r0, [r7, 0x4]\n\
	adds r0, r5\n\
	strh r0, [r6, 0x38]\n\
	ldrh r0, [r7, 0x6]\n\
	adds r0, r2\n\
	strh r0, [r6, 0x3A]\n\
_080CC74C:\n\
	ldrh r4, [r6, 0x20]\n\
	lsls r0, r4, 4\n\
	strh r0, [r6, 0x30]\n\
	ldrh r5, [r6, 0x22]\n\
	lsls r0, r5, 4\n\
	strh r0, [r6, 0x32]\n\
	movs r1, 0x38\n\
	ldrsh r0, [r6, r1]\n\
	movs r2, 0x20\n\
	ldrsh r1, [r6, r2]\n\
	subs r0, r1\n\
	lsls r0, 4\n\
	movs r3, 0x8\n\
	ldrsh r1, [r7, r3]\n\
	bl __divsi3\n\
	strh r0, [r6, 0x34]\n\
	movs r1, 0x3A\n\
	ldrsh r0, [r6, r1]\n\
	movs r2, 0x22\n\
	ldrsh r1, [r6, r2]\n\
	subs r0, r1\n\
	lsls r0, 4\n\
	movs r3, 0x8\n\
	ldrsh r1, [r7, r3]\n\
	bl __divsi3\n\
	strh r0, [r6, 0x36]\n\
	ldrh r0, [r6, 0x38]\n\
	subs r0, r4\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	ldrh r1, [r6, 0x3A]\n\
	subs r1, r5\n\
	lsls r1, 16\n\
	asrs r1, 16\n\
	bl sub_80790F0\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
	bl IsContest\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080CC7AE\n\
	ldr r1, _080CC7CC @ =0xffff8000\n\
	adds r0, r4, r1\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
_080CC7AE:\n\
	movs r3, 0x80\n\
	lsls r3, 1\n\
	str r4, [sp]\n\
	adds r0, r6, 0\n\
	movs r1, 0\n\
	adds r2, r3, 0\n\
	bl sub_8078FDC\n\
	ldr r0, _080CC7D0 @ =sub_80CC7D4\n\
	str r0, [r6, 0x1C]\n\
_080CC7C2:\n\
	add sp, 0x4\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CC7CC: .4byte 0xffff8000\n\
_080CC7D0: .4byte sub_80CC7D4\n\
    .syntax divided\n");
}
#endif

void sub_80CC7D4(struct Sprite* sprite)
{
    if(sprite->data0)
    {
        sprite->data1 += sprite->data3;
        sprite->data2 += sprite->data4;
        sprite->pos1.x = sprite->data1 >> 4 ;
        sprite->pos1.y = sprite->data2 >> 4 ;
        sprite->data0--;
    }
    else
        move_anim_8074EE0(sprite);
}

void sub_80CC810(struct Sprite* sprite)
{
    if(sprite->animEnded)
        move_anim_8072740(sprite);
}

void sub_80CC82C(struct Sprite* sprite)
{
    if(GetBankSide(gBattleAnimPlayerMonIndex) != 0)
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }
    sprite->callback = sub_8078600;
    oamt_set_x3A_32(sprite, move_anim_8072740);
}

void sub_80CC884(struct Sprite* sprite)
{
    if(GetBankSide(gBattleAnimPlayerMonIndex) == 0)
        StartSpriteAnim(sprite, 1);
    sprite->callback = sub_80CC810;
    sub_807867C(sprite, gBattleAnimArgs[0]);
    sprite->pos1.y += gBattleAnimArgs[1];
}

void sub_80CC8C8(struct Sprite* sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data1 = gBattleAnimArgs[3];
    sprite->data3 = gBattleAnimArgs[4];
    sprite->data5 = gBattleAnimArgs[5];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[6]);
    oamt_set_x3A_32(sprite, move_anim_8074EE0);
    sprite->callback = sub_8078504;
}

void sub_80CC914(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 0);
    sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 1);
    if(GetBankSide(gBattleAnimEnemyMonIndex) == 0)
        sprite->pos1.y += 8;
    sprite->callback = sub_80CCB00;
    if(gBattleAnimArgs[2] == 0)
        sprite->pos1.x += gBattleAnimArgs[0];
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data1 -= 0x400;
    sprite->data2 += 0x400;
    sprite->data5 = gBattleAnimArgs[2];
    if(sprite->data5 == 1)
        sprite->data1 = -sprite->data1;
}

void sub_80CC9BC(struct Sprite* sprite)
{
    u8 a;
    u8 b;
    switch(gBattleAnimArgs[3])
    {
        case 1:
        {
            a = sub_8077ABC(gBattleAnimEnemyMonIndex ^ 2, 0);
            b = sub_8077ABC(gBattleAnimEnemyMonIndex ^ 2, 1);
            break;
        }
        case 2:
        {
            a = sub_8077ABC(gBattleAnimEnemyMonIndex, 0);
            b = sub_8077ABC(gBattleAnimEnemyMonIndex, 1);
            if(b_side_obj__get_some_boolean(gBattleAnimEnemyMonIndex ^ 2))
            {
                a = (sub_8077ABC(gBattleAnimEnemyMonIndex ^ 2, 0) + a) / 2;
                b = (sub_8077ABC(gBattleAnimEnemyMonIndex ^ 2, 1) + b) / 2;
            }
            break;
        }
        case 0:
        default:
        {
            a = sub_8077ABC(gBattleAnimEnemyMonIndex, 0);
            b = sub_8077ABC(gBattleAnimEnemyMonIndex, 1);
            break;
        }
    }
    sprite->pos1.x = a;
    sprite->pos1.y = b;
    if(GetBankSide(gBattleAnimEnemyMonIndex) == 0)
        sprite->pos1.y += 8;
    sprite->callback = sub_80CCB00;
    if(gBattleAnimArgs[2] == 0)
        sprite->pos1.x += gBattleAnimArgs[0];
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data1 -= 0x400;
    sprite->data2 += 0x400;
    sprite->data5 = gBattleAnimArgs[2];
    if(sprite->data5 == 1)
        sprite->data1 = -sprite->data1;
}

void sub_80CCB00(struct Sprite* sprite)
{
    sprite->data3 += sprite->data1;
    sprite->data4 += sprite->data2;
    if(sprite->data5 == 0)
        sprite->data1 += 0x18;
    else
        sprite->data1 -= 0x18;
    sprite->data2 -= 0x18;
    sprite->pos2.x = sprite->data3 >> 8;
    sprite->pos2.y = sprite->data4 >> 8;
    sprite->data0++;
    if(sprite->data0 == 20)
    {
        oamt_set_x3A_32(sprite, move_anim_8072740);
        sprite->data0 = 3;
        sprite->callback = sub_80782D8;
    }
}

void unref_sub_80CCB6C(struct Sprite* sprite)
{
    if(sprite->data2 > 1)
    {
        if(sprite->data3 & 1)
        {
            sprite->invisible = 0;
            gSprites[sprite->data0].invisible = 0;
            gSprites[sprite->data1].invisible = 0;
        }
        else
        {
            sprite->invisible = 1;
            gSprites[sprite->data0].invisible = 1;
            gSprites[sprite->data1].invisible = 1;
        }
        sprite->data2 = 0;
        sprite->data3++;
    }
    else
    {
        sprite->data2++;
    }
    if(sprite->data3 == 10)
    {
        DestroySprite(&gSprites[sprite->data0]);
        DestroySprite(&gSprites[sprite->data1]);
        move_anim_8072740(sprite);
    }
}

void sub_80CCC50(struct Sprite* sprite)
{
    sprite->data0 = gBattleAnimArgs[2];
    if(GetBankSide(gBattleAnimPlayerMonIndex) != 0)
        sprite->pos1.x -= gBattleAnimArgs[0];
    else
        sprite->pos1.x += gBattleAnimArgs[0];
    StartSpriteAnim(sprite, gBattleAnimArgs[5]);
    sprite->data1 = -gBattleAnimArgs[3];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data3 = gBattleAnimArgs[4];
    sprite->callback = sub_80CCCB4;
    sub_80CCCB4(sprite);
}

void sub_80CCCB4(struct Sprite* sprite)
{
    sprite->pos2.x = Cos(sprite->data0, 100);
    sprite->pos2.y = Sin(sprite->data0, 20);
    if(sprite->data0 <= 0x7F)
        sprite->subpriority = 0;
    else
        sprite->subpriority = 14;
    sprite->data0 = (sprite->data0 + sprite->data1) & 0xFF;
    sprite->data5 += 0x82;
    sprite->pos2.y += sprite->data5 >> 8;
    sprite->data2++;
    if(sprite->data2 == sprite->data3)
        move_anim_8072740(sprite);
}

void sub_80CCD24(struct Sprite* sprite)
{
    if(IsContest() != 0)
    {
        gBattleAnimArgs[1] += 8;
    }
    sprite->pos1.x = sub_8077EE4(gBattleAnimPlayerMonIndex, 0) + gBattleAnimArgs[0];
    sprite->pos1.y = sub_8077EE4(gBattleAnimPlayerMonIndex, 1) + gBattleAnimArgs[1];
    if (GetBankSide(gBattleAnimPlayerMonIndex) == 0 || IsContest())
        sprite->oam.priority = sub_8079ED4(gBattleAnimPlayerMonIndex) + 1;
    else
        sprite->oam.priority = sub_8079ED4(gBattleAnimPlayerMonIndex);
    sprite->data0 = gBattleAnimArgs[2];
    sprite->data2 = (IndexOfSpritePaletteTag(0x2828) << 4) + 0x100;
    sprite->data7 = 16;
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = (sprite->data7 << 8) | (16 - sprite->data7);
    sprite->callback = sub_80CCE0C;
}

void sub_80CCE0C(struct Sprite* sprite)
{
    int a;
    int i;
    sprite->data5 += 0x60;
    sprite->pos2.x = -(sprite->data5 >> 8);
    sprite->data1++;
    if(sprite->data1 > 1)
    {
        sprite->data1 = 0;
        a = gPlttBufferFaded[sprite->data2 + 1];
        i = 0;
        do
    {
      gPlttBufferFaded[sprite->data2 + ++i] = gPlttBufferFaded[sprite->data2 + i + 1];
    }
    while ( i <= 5 );
        gPlttBufferFaded[sprite->data2 + 7] = a;
    }
    if (sprite->data7 > 6 && sprite->data0 >0 && ++sprite->data6 > 1)
    {
        sprite->data6 = 0;
        sprite->data7 -= 1;
        REG_BLDALPHA = (sprite->data7 << 8) | (16 - sprite->data7);;
    }
    if (sprite->data0 >0)
    {
        sprite->data0 -= 1;
    }
    else if (++sprite->data6 > 1)
    {
        sprite->data6 = 0;
        sprite->data7++;
        REG_BLDALPHA = (sprite->data7 << 8) | (16 - sprite->data7);
        if(sprite->data7 == 16)
        {
            sprite->invisible = 1;
            sprite->callback = sub_807861C;
        }
    }
}

void sub_80CCF04(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 2);
    sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + 0xFFE8;
    sprite->data0 = 0;
    sprite->data1 = 0;
    sprite->data2 = 0;
    sprite->data3 = 0;
    sprite->data4 = 0;
    sprite->data6 = 0;
    sprite->data7 = 16;
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = (sprite->data7 << 8) | sprite->data6;
    sprite->callback = sub_80CCF70;
}

void sub_80CCF70(struct Sprite* sprite)
{
    switch(sprite->data0)
    {
        case 0:
        {
            if(++sprite->data2 > 0)
            {
                sprite->data2 = 0;
                if(((++sprite->data1) & 1) != 0)
                {
                    if(sprite->data6 <= 15)
                        sprite->data6++;
                }
                else if (sprite->data7 > 0)
                    sprite->data7--;
                REG_BLDALPHA = (sprite->data7 << 8) | sprite->data6;
                if(sprite->data6 == 16 && sprite->data7 == 0)
                {
                    sprite->data1 = 0;
                    sprite->data0++;
                    break;
                }
            }
            break;
        }
        case 1:
        {
            if(++sprite->data1 > 8)
            {
                sprite->data1 = 0;
                StartSpriteAffineAnim(sprite, 1);
                sprite->data0++;
                break;
            }
            break;
        }
        case 2:
        {
            sub_80CD0CC(sprite, 16, 4);
            if(++sprite->data1 > 2)
            {
                sprite->data1 = 0;
                sprite->pos1.y++;
            }
            if(++sprite->data2 <= 29)
                break;
            if(sprite->data2 & 1)
            {
                if(sprite->data6 > 0)
                    sprite->data6--;
            }
            else if(sprite->data7 <= 15)
                sprite->data7++;
            REG_BLDALPHA = (sprite->data7 << 8) | sprite->data6;
            if(sprite->data6 == 0 && sprite->data7 == 16)
            {
                sprite->data1 = 0;
                sprite->data2 = 0;
                sprite->data0++;
                break;
            }
            else
                break;
        }
        case 3:
        {
            sprite->invisible = 1;
            sprite->data0++;
            break;
        }
        case 4:
        {
            REG_BLDCNT = 0;
            REG_BLDALPHA = 0;
            move_anim_8072740(sprite);
        }
    }
}

void sub_80CD0CC(struct Sprite* sprite, int unk1, int unk2)
{
    if(sprite->data3 <= 11)
        sprite->data4 += 2;
    if((u16)(sprite->data3 - 0x12) <= 0x17)
        sprite->data4 -= 2;
    if((sprite->data3) > 0x2F)
        sprite->data4 += 2;
    sprite->pos2.x = sprite->data4 / 9;
    sprite->pos2.y = sprite->data4 / 14;
    if(sprite->pos2.y < 0)
        sprite->pos2.y *= -1;
    sprite->data3++;
    if(sprite->data3 > 0x3B)
        sprite->data3 = 0;
}

void sub_80CD140(struct Sprite* sprite)
{
    if (!gBattleAnimArgs[2])
        sub_8078650(sprite);
    sub_807867C(sprite, gBattleAnimArgs[0]);
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data0 = gBattleAnimArgs[5];
    sprite->data1 = gBattleAnimArgs[3];
    sprite->data2 = gBattleAnimArgs[4];
    oamt_set_x3A_32(sprite, move_anim_8072740);
    sprite->callback = sub_8078394;
}

void sub_80CD190(struct Sprite* sprite)
{
    u8 bank;
    if (!gBattleAnimArgs[2])
        bank = gBattleAnimPlayerMonIndex;
    else
        bank = gBattleAnimEnemyMonIndex;
    if (IsDoubleBattle() && b_side_obj__get_some_boolean(bank ^ 2))
    {
        sub_807A3FC(bank, gBattleAnimArgs[6], &sprite->pos1.x, &sprite->pos1.y);
        sub_807867C(sprite, gBattleAnimArgs[0]);
        sprite->pos1.y += gBattleAnimArgs[1];
    }
    else
    {
        if (!gBattleAnimArgs[6])
        {
            sprite->pos1.x = sub_8077ABC(bank, 0);
            sprite->pos1.y = sub_8077ABC(bank, 1) + gBattleAnimArgs[1];
        }
        else
        {
            sprite->pos1.x = sub_8077ABC(bank, 2);
            sprite->pos1.y = sub_8077ABC(bank, 3) + gBattleAnimArgs[1];
        }
        sub_807867C(sprite, gBattleAnimArgs[0]);
    }
    sprite->data0 = gBattleAnimArgs[5];
    sprite->data1 = gBattleAnimArgs[3];
    sprite->data2 = gBattleAnimArgs[4];
    oamt_set_x3A_32(sprite, move_anim_8072740);
    sprite->callback = sub_8078394;
}

void sub_80CD274(struct Sprite* sprite)
{
    sub_8078650(sprite);
    if (GetBankSide(gBattleAnimPlayerMonIndex) == 0)
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        StartSpriteAnim(sprite, 1);
    }
    sprite->callback = sub_80CD2D4;
}

void sub_80CD2D4(struct Sprite* sprite)
{
    if (++sprite->data0 > 30)
    {
        sprite->pos2.y = (30 - sprite->data0) / 3;
        sprite->pos2.x = Sin(sprite->data1 * 4, 3);
        sprite->data1++;
    }
    if(sprite->animEnded)
        move_anim_8072740(sprite);
}

void sub_80CD328(struct Sprite* sprite)
{
    sub_8078650(sprite);
    if (GetBankSide(gBattleAnimPlayerMonIndex) == 0)
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data3 = 1;
    }
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data3 = 0xFFFF;
        StartSpriteAffineAnim(sprite, 1);
    }
    sprite->callback = sub_80CD394;
}

void sub_80CD394(struct Sprite* sprite)
{
    sprite->pos2.y = -(sprite->data0 / 0x28);
    sprite->pos2.x = sprite->data4 / 10;
    sprite->data4 += sprite->data3 * 2;
    sprite->data0 += sprite->data1;
    if (++sprite->data1 > 0x3C)
        move_anim_8074EE0(sprite);
}

void sub_80CD3E0(struct Sprite* sprite)
{
    sprite->pos1.x -= 32;
    sprite->pos1.y -= 32;
    sprite->data0 = 20;
    sprite->callback = sub_80782D8;
    oamt_set_x3A_32(sprite, sub_80CD408);
}

void sub_80CD408(struct Sprite* sprite)
{
    switch(sprite->data5 & 1)
    {
        case 0:
            sprite->data0 = 1;
            sprite->callback = sub_80782D8;
            oamt_set_x3A_32(sprite, sub_80CD408);
            break;
        case 1:
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.y = 0;
            sprite->pos2.x = 0;
            sprite->data0 = 8;
            sprite->data2 = sprite->pos1.x + gUnknown_083D6DDC[sprite->data5 >> 8][0];
            sprite->data4 = sprite->pos1.y + gUnknown_083D6DDC[sprite->data5 >> 8][1];
            sprite->callback = sub_8078B34;
            oamt_set_x3A_32(sprite, sub_80CD4B8);
            sprite->data5 += 0x100;
            PlaySE12WithPanning(0xD2, sub_8076F98(0x3F));
            break;
    }
    sprite->data5 ^= 1;
}

void sub_80CD4B8(struct Sprite* sprite)
{
    if ((sprite->data5 >> 8) == 4)
    {
        sprite->data0 = 10;
        sprite->callback = sub_80782D8;
        oamt_set_x3A_32(sprite, sub_80CD4EC);
    }
    else
        sprite->callback = sub_80CD408;
}

void sub_80CD4EC(struct Sprite* sprite)
{
    s16 a;
    s16 b;
    if(sprite->oam.affineParam == 0)
    {
        sprite->data0 = 3;
        sprite->data1 = 0;
        sprite->data2 = 0;
        sprite->callback = sub_80782D8;
        oamt_set_x3A_32(sprite, sub_80CD5A8);
    }
    else
    {
        switch(sprite->oam.affineParam)
        {
            case 1:
                a = -8;
                b = -8;
                break;
            case 2:
                a = -8;
                b = 8;
                break;
            case 3:
                a = 8;
                b = -8;
                break;
            default:
                a = 8;
                b = 8;
                break;
        }
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;
        sprite->data0 = 6;
        sprite->data2 = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + a;
        sprite->data4 = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + b;
        sprite->callback = sub_8078B34;
        oamt_set_x3A_32(sprite, sub_80CD654);
    }
}

void sub_80CD5A8(struct Sprite* sprite)
{
    if (sprite->data2 == 0)
    {
        if ((sprite->data1 += 3) > 16)
            sprite->data1 = 16;
    }
    else if ((sprite->data1 -= 3) < 0)
            sprite->data1 = 0;
    BlendPalettes(sub_80791A8(1, 1, 1, 1, 1, 0, 0), sprite->data1, 0x7FFF);
    if (sprite->data1 == 16)
    {
        int pal;
        sprite->data2++;
        pal = sprite->oam.paletteNum;
        LoadPalette(&gPlttBufferUnfaded[0x108 + pal * 16], pal * 16 | 0x101, 4);
        PlaySE12WithPanning(0xC0, sub_8076F98(0x3F));
    }
    else if (sprite->data1 == 0)
        sprite->callback = sub_80CD654;
}

void sub_80CD654(struct Sprite* sprite)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->data1 = 0;
        sprite->data0 = 0;
        sprite->callback = sub_80CD67C;
    }
}

void sub_80CD67C(struct Sprite* sprite)
{
    if (sprite->data0 % 3 == 0)
    {
        sprite->data1++;
        sprite->invisible ^= 1;
    }
    sprite->data0++;
    if (sprite->data1 == 8)
        move_anim_8072740(sprite);
}

void sub_80CD6CC(struct Sprite* sprite)
{
    sprite->oam.affineParam = gBattleAnimArgs[0];
    if ((s16)sprite->oam.affineParam == 1)
    {
        sprite->pos1.x -= 0x18;
        sprite->pos1.y -= 0x18;
    }
    else if((s16)sprite->oam.affineParam == 2)
    {
        sprite->pos1.x -= 0x18;
        sprite->pos1.y += 0x18;
        sprite->oam.matrixNum = 16;
    }
    else if((s16)sprite->oam.affineParam == 3)
    {
        sprite->pos1.x += 0x18;
        sprite->pos1.y -= 0x18;
        sprite->oam.matrixNum = 8;
    }
    else
    {
        sprite->pos1.x += 0x18;
        sprite->pos1.y += 0x18;
        sprite->oam.matrixNum = 24;
    }
    sprite->oam.tileNum = (sprite->oam.tileNum + 16);
    sprite->callback = sub_80CD3E0;
    sub_80CD3E0(sprite);
}

void sub_80CD774(struct Sprite* sprite)
{
    sprite->invisible = 1;
    sprite->data0 = 0;
    switch(gBattleAnimArgs[0])
    {
        case 0:
            sprite->callback = sub_80CD7CC;
            break;
        case 1:
            sprite->callback = sub_80CD8A8;
            break;
        case 2:
            sprite->callback = sub_80CD8F8;
            break;
        default:
            sprite->callback = sub_80CD9B8;
            break;
    }
}

void sub_80CD7CC(struct Sprite* sprite)
{
    sprite->data0 = 6;
    sprite->data1 = (GetBankSide(gBattleAnimPlayerMonIndex)) ? 2 : -2;
    sprite->data2 = 0;
    sprite->data3 = gObjectBankIDs[gBattleAnimPlayerMonIndex];
    oamt_set_x3A_32(sprite, sub_80CD81C);
    sprite->callback = sub_8078458;
}

void sub_80CD81C(struct Sprite* sprite)
{
    if (sprite->data0 == 0)
    {
        sprite->data3 = gObjectBankIDs[gBattleAnimPlayerMonIndex];
        sub_8078E70(sprite->data3, 0);
        sprite->data4 = (sprite->data6 = GetBankSide(gBattleAnimPlayerMonIndex)) ? 0x300 : 0xFFFFFD00;
        sprite->data5 = 0;
    }
    sprite->data5 += sprite->data4;
    obj_id_set_rotscale(sprite->data3, 0x100, 0x100, sprite->data5);
    sub_8078F9C(sprite->data3);
    if (++sprite->data0 > 3)
    {
        sprite->data0 = 0;
        sprite->callback = sub_80CD9B8;
    }
}

void sub_80CD8A8(struct Sprite* sprite)
{
    sprite->data0 = 4;
    sprite->data1 = (GetBankSide(gBattleAnimPlayerMonIndex)) ? -3 : 3;
    sprite->data2 = 0;
    sprite->data3 = gObjectBankIDs[gBattleAnimPlayerMonIndex];
    oamt_set_x3A_32(sprite, sub_80CD9B8);
    sprite->callback = sub_8078458;
}

void sub_80CD8F8(struct Sprite* sprite)
{
    if(++sprite->data0 > 8)
    {
        sprite->data0 = 0;
        sprite->callback = sub_80CD91C;
    }
}

void sub_80CD91C(struct Sprite* sprite)
{
    if (sprite->data0 == 0)
    {
        sprite->data3 = gObjectBankIDs[gBattleAnimPlayerMonIndex];
        sprite->data6 = GetBankSide(gBattleAnimPlayerMonIndex);
        if (GetBankSide(gBattleAnimPlayerMonIndex))
        {
            sprite->data4 = 0xFC00;
            sprite->data5 = 0xC00;
        }
        else
        {
            sprite->data4 = 0x400;
            sprite->data5 = 0xF400;
        }
    }
    sprite->data5 += sprite->data4;
    obj_id_set_rotscale(sprite->data3, 0x100, 0x100, sprite->data5);
    sub_8078F9C(sprite->data3);
    if (++sprite->data0 > 2)
    {
        sub_8078F40(sprite->data3);
        sprite->callback = sub_80CD9B8;
    }
}

void sub_80CD9B8(struct Sprite* sprite)
{
    move_anim_8072740(sprite);
}

void sub_80CD9C4(struct Sprite* sprite)
{
    sprite->data0 = 0;
    sprite->callback = sub_80CD9D4;
}

void sub_80CD9D4(struct Sprite* sprite)
{
    switch(sprite->data0)
    {
        case 0:
            sprite->data1 = 0;
            sprite->data2 = gObjectBankIDs[gBattleAnimPlayerMonIndex];
            sprite->data3 = GetBankSide(gBattleAnimPlayerMonIndex);
            sprite->data4 = (sprite->data3 != 0) ? 0x200 : -0x200;
            sprite->data5 = 0;
            sub_8078E70(sprite->data2, 0);
            sprite->data0++;
        case 1:
            sprite->data5 += sprite->data4;
            obj_id_set_rotscale(sprite->data2, 0x100, 0x100, sprite->data5);
            sub_8078F9C(sprite->data2);
            if (++sprite->data1 > 3)
            {
                sprite->data1 = 0;
                sprite->data4 *= -1;
                sprite->data0++;
            }
            break;
        case 2:
            sprite->data5 += sprite->data4;
            obj_id_set_rotscale(sprite->data2, 0x100, 0x100, sprite->data5);
            sub_8078F9C(sprite->data2);
            if (++sprite->data1 > 3)
            {
                sub_8078F40(sprite->data2);
                move_anim_8072740(sprite);
            }
            break;
    }
}

void sub_80CDAC8(u8 taskId)
{   u8 a;
    gTasks[taskId].data[0] = gObjectBankIDs[gBattleAnimPlayerMonIndex];
    a = GetBankSide(gBattleAnimPlayerMonIndex);
    gTasks[taskId].data[1] = a;
    gTasks[taskId].data[2] = 0;
    switch(gBattleAnimArgs[0])
    {
        default:
            DestroyAnimVisualTask(taskId);
            break;
        case 0:
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[3] = 8;
            gTasks[taskId].data[4] = 0;
            gTasks[taskId].data[5] = 3;
            if (a == 0)
                gTasks[taskId].data[5] *= -1;
            gTasks[taskId].func = sub_80CDB60;
            break;
        case 1:
            gTasks[taskId].data[3] = 8;
            gTasks[taskId].data[4] = 0x600;
            gTasks[taskId].data[5] = 0xC0;
            if (a == 0)
            {
                gTasks[taskId].data[4] = -gTasks[taskId].data[4];
                gTasks[taskId].data[5] = -gTasks[taskId].data[5];
            }
            gTasks[taskId].func = sub_80CDD20;
            break;
    }
}

void sub_80CDB60(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch(task->data[2])
    {
    case 0:
        if(task->data[3])
        {
            task->data[4] += task->data[5];
            gSprites[task->data[0]].pos2.x = task->data[4];
            task->data[3]--;
        }
        else
        {
            task->data[3] = 8;
            task->data[4] = 0;
            task->data[5] = (task->data[1] == 0) ? -0xC0 : 0xC0;
            sub_8078E70(task->data[0], 0);
            task->data[2]++;
        }
        break;
    case 1:
        if (task->data[3])
        {
            task->data[4] += task->data[5];
            obj_id_set_rotscale(task->data[0], 0x100, 0x100, task->data[4]);
            sub_8078F9C(task->data[0]);
            task->data[3]--;
        }
        else
        {
            task->data[3] = 8;
            task->data[4] = gSprites[task->data[0]].pos2.x;
            task->data[5] = (task->data[1] == 0) ? 0x2 : -0x2;
            task->data[6] = 1;
            task->data[2]++;
        }
        break;
    case 2:
        if (task->data[3])
        {
            if (task->data[6])
            {
                task->data[6]--;
            }
            else
            {
                if (task->data[3] & 1)
                    gSprites[task->data[0]].pos2.x = task->data[4] + task->data[5];
                else
                    gSprites[task->data[0]].pos2.x = task->data[4] - task->data[5];
                task->data[6] = 1;
                task->data[3]--;
            }
        }
        else
        {
            gSprites[task->data[0]].pos2.x = task->data[4];
            task->data[3] = 12;
            task->data[2]++;
        }
        break;
    case 3:
        if (task->data[3])
        {
            task->data[3]--;
        }
        else
        {
            task->data[3] = 3;
            task->data[4] = gSprites[task->data[0]].pos2.x;
            task->data[5] = (task->data[1] == 0) ? 8 : -8;
            task->data[2]++;
        }
        break;
    case 4:
        if (task->data[3])
        {
            task->data[4] += task->data[5];
            gSprites[task->data[0]].pos2.x = task->data[4];
            task->data[3]--;
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
        break;
    }
}

void sub_80CDD20(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    if (task->data[3])
    {
        task->data[4] -= task->data[5];
        obj_id_set_rotscale(task->data[0], 0x100, 0x100, task->data[4]);
        sub_8078F9C(task->data[0]);
        task->data[3]--;
    }
    else
    {
        sub_8078F40(task->data[0]);
        DestroyAnimVisualTask(taskId);
    }
}

void sub_80CDD74(struct Sprite* sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 3) + gBattleAnimArgs[2];
    }
    else
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + gBattleAnimArgs[2];
    }
    sprite->data0 = 0;
    sprite->data1 = 0;
    oamt_set_x3A_32(sprite, sub_80CDEC0);
    sprite->callback = sub_8078600;
}

void sub_80CDDDC(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + 0xFFD0;
    sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    oamt_set_x3A_32(sprite, sub_80CDE78);
    sprite->callback = sub_8078600;
}

void sub_80CDE24(struct Sprite* sprite)
{
    sprite->pos1.x = sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + 0xFFD0 + gBattleAnimArgs[0];
    sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3);
    StartSpriteAnim(sprite, 1);
    sprite->data0 = 0;
    sprite->data1 = 0;
    sprite->callback = sub_80CDEC0;
}

void sub_80CDE78(struct Sprite* sprite)
{
    if (++sprite->data0 > 8)
    {
        sprite->data0 = 12;
        sprite->data1 = 8;
        sprite->data2 = 0;
        oamt_set_x3A_32(sprite, sub_80CDEB0);
        sprite->callback = sub_8078364;
    }
}

void sub_80CDEB0(struct Sprite* sprite)
{
    sprite->data0 = 0;
    sprite->data1 = 0;
    sprite->callback = sub_80CDEC0;
}

void sub_80CDEC0(struct Sprite* sprite)
{
    if(++sprite->data0 > 1)
    {
        sprite->data0 = 0;
        sprite->invisible = !sprite->invisible;
        if(++sprite->data1 > 8)
            move_anim_8072740(sprite);
    }
}

void sub_80CDF0C(struct Sprite* sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 0) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 1) + gBattleAnimArgs[2];
    }
    else
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 0) + gBattleAnimArgs[1];
        sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 1) + gBattleAnimArgs[2];
    }
    sprite->data0 = 0;
    sprite->data1 = gBattleAnimArgs[3];
    sprite->callback = sub_80CDF70;
}

void sub_80CDF70(struct Sprite* sprite)
{
    if (++sprite->data0 > sprite->data1)
    {
        sprite->data0 = 0;
        sprite->pos1.y--;
    }
    sprite->pos1.y -= sprite->data0;
    if (sprite->animEnded)
        move_anim_8072740(sprite);
}

void sub_80CDFB0(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
    sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 3) - 12;
    sprite->data0 = 0;
    sprite->data1 = 2;
    sprite->data2 = 0;
    sprite->data3 = 0;
    sprite->data4 = 0;
    sprite->data5 = sub_8076F98(-0x40);
    sprite->callback = sub_80CE000;
}

#ifdef NONMATCHING
void sub_80CE000(struct Sprite* sprite)
{
    if (++sprite->data0 >= sprite->data1)
    {
        sprite->invisible = !sprite->invisible;
        if (!sprite->invisible && !(++sprite->data4 & 1))
            PlaySE12WithPanning(0xC2, sprite->data5);
        sprite->data0 = 0;
        if (++sprite->data2 > 1)
        {
            sprite->data2 = 0;
            sprite->data1++;
        }
    }
    if (sprite->animEnded && sprite->data1 > 16 && sprite->invisible)
        move_anim_8072740(sprite);
}
#else
__attribute__((naked))
void sub_80CE000(struct Sprite* sprite)
{
    asm(".syntax unified\n\
    push {r4,lr}\n\
	adds r4, r0, 0\n\
	ldrh r0, [r4, 0x2E]\n\
	adds r0, 0x1\n\
	strh r0, [r4, 0x2E]\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	movs r2, 0x30\n\
	ldrsh r1, [r4, r2]\n\
	cmp r0, r1\n\
	blt _080CE06C\n\
	adds r3, r4, 0\n\
	adds r3, 0x3E\n\
	ldrb r2, [r3]\n\
	lsrs r1, r2, 2\n\
	movs r0, 0x1\n\
	eors r1, r0\n\
	ands r1, r0\n\
	lsls r1, 2\n\
	movs r0, 0x5\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r1, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _080CE052\n\
	ldrh r0, [r4, 0x36]\n\
	adds r0, 0x1\n\
	strh r0, [r4, 0x36]\n\
	movs r1, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _080CE052\n\
	ldrh r1, [r4, 0x38]\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	movs r0, 0xC2\n\
	bl PlaySE12WithPanning\n\
_080CE052:\n\
	movs r1, 0\n\
	strh r1, [r4, 0x2E]\n\
	ldrh r0, [r4, 0x32]\n\
	adds r0, 0x1\n\
	strh r0, [r4, 0x32]\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	cmp r0, 0x1\n\
	ble _080CE06C\n\
	strh r1, [r4, 0x32]\n\
	ldrh r0, [r4, 0x30]\n\
	adds r0, 0x1\n\
	strh r0, [r4, 0x30]\n\
_080CE06C:\n\
	adds r0, r4, 0\n\
	adds r0, 0x3F\n\
	ldrb r1, [r0]\n\
	movs r0, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CE096\n\
	movs r1, 0x30\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, 0x10\n\
	ble _080CE096\n\
	adds r0, r4, 0\n\
	adds r0, 0x3E\n\
	ldrb r1, [r0]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CE096\n\
	adds r0, r4, 0\n\
	bl move_anim_8072740\n\
_080CE096:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}
#endif

void sub_80CE09C(struct Sprite* sprite)
{
    if (sprite->data0 == 0)
    {
        sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 0) + gBattleAnimArgs[0];
        sprite->pos1.y = sub_8077ABC(gBattleAnimPlayerMonIndex, 1) + gBattleAnimArgs[1];
        if (IsContest())
            sprite->pos1.y += 10;
        sprite->data0++;
    }
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        move_anim_8072740(sprite);
}

void sub_80CE108(u8 taskId)
{
    if (gTasks[taskId].data[2] == 1)
    {
        gBattleAnimArgs[7] = 0xFFFF;
        gTasks[taskId].data[2]++;
    }
    else if (gTasks[taskId].data[2] == 2)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (++gTasks[taskId].data[0] == 4)
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1]++;
            REG_BLDALPHA = (gTasks[taskId].data[1] << 8) | (16 - gTasks[taskId].data[1]);
            if (gTasks[taskId].data[1] == 16)
                gTasks[taskId].data[2]++;
        }
    }
}

void sub_80CE17C(struct Sprite* sprite)
{
    sub_8078764(sprite, 0);
    sprite->animPaused = 1;
    sprite->data0 = gBattleAnimArgs[2];
    sprite->callback = sub_80CE1AC;
}

void sub_80CE1AC(struct Sprite* sprite)
{
    if (sprite->data0)
        sprite->data0--;
    else
    {
        sprite->animPaused = 0;
        sprite->data0 = 30;
        sprite->data2 = sub_8077ABC(gBattleAnimPlayerMonIndex, 2);
        sprite->data4 = sub_8077ABC(gBattleAnimPlayerMonIndex, 3);
        sprite->callback = sub_8078B34;
        oamt_set_x3A_32(sprite, move_anim_8072740);
    }
}

void sub_80CE210(u8 taskId)
{
    if (++gTasks[taskId].data[0] == 4)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1]++;
        REG_BLDALPHA = gTasks[taskId].data[1] | ((16 - gTasks[taskId].data[1]) << 8);
        if (gTasks[taskId].data[1] == 16)
            DestroyAnimVisualTask(taskId);
    }
}

void unref_sub_80CE260(u8 taskId)
{
    u8 i;
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gBattleAnimArgs[0] == 1 && GetBankSide(i) == 0)
            sub_8043DB0(gHealthboxIDs[i]);
        if (gBattleAnimArgs[1] == 1 && GetBankSide(i) == 1)
            sub_8043DB0(gHealthboxIDs[i]);
    }
    DestroyAnimVisualTask(taskId);
}

void unref_sub_80CE2D4(u8 taskId)
{
    u8 i;
    for (i = 0; i < gNoOfAllBanks; i++)
        sub_8043DFC(gHealthboxIDs[i]);
    DestroyAnimVisualTask(taskId);
}

void sub_80CE30C(struct Sprite* sprite)
{
    if (IsContest())
    {
        sprite->pos1.x = 0x30;
        sprite->pos1.y = 0x28;
    }
    else
    {
        sprite->pos1.x = gBattleAnimArgs[0];
        sprite->pos1.y = gBattleAnimArgs[1];
    }
    sprite->oam.shape = 0;
    sprite->oam.size = 3;
    sprite->data0 = 0;
    sprite->callback = sub_80CE354;
}

void sub_80CE354(struct Sprite* sprite)
{
    if (sprite->data0)
        move_anim_8072740(sprite);
}

void sub_80CE36C(struct Sprite* sprite)
{
    sprite->pos1.x = sub_8077ABC(gBattleAnimPlayerMonIndex, 2) + gBattleAnimArgs[0];
    sprite->pos1.y = gBattleAnimArgs[1];
    sprite->data0 = 0;
    sprite->data1 = 0;
    sprite->data2 = 0;
    sprite->data3 = 0;
    sprite->data4 = 1;
    sprite->callback = sub_80CE3B0;
}

void sub_80CE3B0(struct Sprite* sprite)
{
    if (++sprite->data1 > 1)
    {
        sprite->data1 = 0;
        if (sprite->data2 <= 0x77)
        {
            sprite->pos1.y++;
            sprite->data2++;
        }
    }
    if (sprite->data0)
        move_anim_8072740(sprite);
}

void sub_80CE3EC(u8 taskId)
{
    int a = sub_80791A8(1, 0, 0, 0, 0, 0, 0) & 0xFFFF;
    int b;
    int c;
    int d;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = a;
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
    gTasks[taskId].data[7] = 13;
    gTasks[taskId].data[8] = 14;
    gTasks[taskId].data[9] = 15;
    b = sub_80792C0(1, 1, 1, 1);
    c = a | b;
    sub_8079BF4(&gTasks[taskId].data[14], &gTasks[taskId].data[15], (void*)c);
    b = b | (0x10000 << IndexOfSpritePaletteTag(0x27D2));
    d = IndexOfSpritePaletteTag(0x27D3);
    BeginNormalPaletteFade((0x10000 << d) | b, 0, 0, 0x10, 32699);
    gTasks[taskId].func = sub_80CE4D4;
    sub_80CE4D4(taskId);
}

void sub_80CE4D4(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    switch (task->data[0])
    {
        case 0:
            if (++task->data[1] > 0)
            {
                u16 color;
                u16 bitmask;
                u16 r3;
                u16 i;
                u16 j;
                task->data[1] = 0;
                if (++task->data[2] <= 15)
                {
                    u16 red;
                    u16 green;
                    u16 blue;
                    task->data[4] += task->data[7];
                    task->data[5] += task->data[8];
                    task->data[6] += task->data[9];
                    red = task->data[4] >> 3;
                    green = task->data[5] >> 3;
                    blue = task->data[6] >> 3;
                    color = RGB(red, green, blue);
                }
                else
                {
                    color = RGB(27, 29, 31);
                    task->data[0]++;
                }
                bitmask = 1;
                r3 = 0;
                for (i = 0; i <= 15; i++)
                {
                    if (task->data[3] & bitmask)
                    {
                            for (j = 1; j <= 15; j++)
                                gPlttBufferFaded[r3 + j] = color;
                    }
                    bitmask <<= 1;
                    r3 += 16;
                }
            }
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                u8 spriteId;
                for (spriteId = 0; spriteId < MAX_SPRITES; spriteId++)
                {
                    if (gSprites[spriteId].template == &gBattleAnimSpriteTemplate_83D6FC8 || gSprites[spriteId].template == &gBattleAnimSpriteTemplate_83D6FF8)
                        gSprites[spriteId].data0 = 1;
                }
                task->data[1] = 0;
                task->data[0]++;
            }
            break;
        case 2:
            if (++task->data[1] > 30)
            {
                BeginNormalPaletteFade((u32)sub_8079BFC(task->data[14], task->data[15]), 0, 16, 0, RGB(27, 29, 31));
                task->data[0]++;
            }
            break;
        case 3:
            if (!gPaletteFade.active)
                DestroyAnimVisualTask(taskId);
            break;
    }
}

void sub_80CE670(struct Sprite* sprite)
{
    if (gBattleAnimArgs[2] <= 1)
        gBattleAnimArgs[2] = 2;
    if (gBattleAnimArgs[2] > 0x7F)
        gBattleAnimArgs[2] = 0x7F;
    sprite->data0 = 0;
    sprite->data1 = gBattleAnimArgs[2];
    sprite->pos1.x = sub_8077ABC(gBattleAnimEnemyMonIndex, 2) + gBattleAnimArgs[0];
    sprite->pos1.y = sub_8077ABC(gBattleAnimEnemyMonIndex, 3) + gBattleAnimArgs[1];
    sprite->data6 = sprite->pos1.x;
    sprite->data7 = sprite->pos1.y;
    if (IsContest() != 0)
    {
        sprite->oam.matrixNum = 8;
        sprite->pos1.x += 40;
        sprite->pos1.y += 20;
        sprite->data2 = sprite->pos1.x << 7;
        sprite->data3 = -0x1400 / sprite->data1;
        sprite->data4 = sprite->pos1.y << 7;
        sprite->data5 = -0xA00 / sprite->data1;
    }
    else if (GetBankSide(gBattleAnimPlayerMonIndex) == 0)
    {
        sprite->pos1.x -= 40;
        sprite->pos1.y += 20;
        sprite->data2 = sprite->pos1.x << 7;
        sprite->data3 = 0x1400 / sprite->data1;
        sprite->data4 = sprite->pos1.y << 7;
        sprite->data5 = -0xA00 / sprite->data1;
    }
    else
    {
        sprite->pos1.x += 40;
        sprite->pos1.y -= 20;
        sprite->data2 = sprite->pos1.x << 7;
        sprite->data3 = -0x1400 / sprite->data1;
        sprite->data4 = sprite->pos1.y << 7;
        sprite->data5 = 0xA00 / sprite->data1;
        sprite->oam.matrixNum = 24;
    }
    sprite->callback = sub_80CE798;
}

void sub_80CE798(struct Sprite* sprite)
{
    sprite->data2 += sprite->data3;
    sprite->data4 += sprite->data5;
    sprite->pos1.x = sprite->data2 >> 7;
    sprite->pos1.y = sprite->data4 >> 7;
    if (--sprite->data1 == 1)
    {
        sprite->pos1.x = sprite->data6;
        sprite->pos1.y = sprite->data7;
    }
    if (sprite->data1 == 0)
        move_anim_8072740(sprite);
}

// double team
void sub_80CE7E0(u8 taskId)
{
    u16 i;
    int obj;
    u16 r3;
    u16 r4;
    struct Task* task = &gTasks[taskId];
    task->data[0] = obj_id_for_side_relative_to_move(0);
    task->data[1] = AllocSpritePalette(0x2771);
    r3 = (task->data[1] * 16) + 0x100;
    r4 = (gSprites[task->data[0]].oam.paletteNum + 16) << 4;
    for (i = 1; i < 16; i++)
    {
        gPlttBufferUnfaded[r3 + i] = gPlttBufferUnfaded[r4 + i];
    }
    BlendPalette(r3, 16, 11, 0);
    task->data[3] = 0;
    i = 0;
    while (i <= 1 && (obj = duplicate_obj_of_side_rel2move_in_transparent_mode(0)) >= 0)
    {
        gSprites[obj].oam.paletteNum = task->data[1];
        gSprites[obj].data0 = 0;
        gSprites[obj].data1 = i << 7;
        gSprites[obj].data2 = taskId;
        gSprites[obj].callback = sub_80CE974;
        task->data[3]++;
        i++;
    }
    task->func = sub_80CE910;
    if (GetBankIdentity_permutated(gBattleAnimPlayerMonIndex) == 1)
    {
        REG_DISPCNT &= 0xFDFF;
    }
    else
        REG_DISPCNT &= 0xFBFF;
}

void sub_80CE910(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    if (!task->data[3])
    {
        if (GetBankIdentity_permutated(gBattleAnimPlayerMonIndex) == 1)
            REG_DISPCNT |= 0x200;
        else
            REG_DISPCNT |= 0x400;
        FreeSpritePaletteByTag(0x2771);
        DestroyAnimVisualTask(taskId);
    }
}

void sub_80CE974(struct Sprite* sprite)
{
    if (++sprite->data3 > 1)
    {
        sprite->data3 = 0;
        sprite->data0++;
    }
    if (sprite->data0 > 0x40)
    {
        gTasks[sprite->data2].data[3]--;
        obj_delete_but_dont_free_vram(sprite);
    }
    else
    {
        sprite->data4 = gSineTable[sprite->data0] / 6;
        sprite->data5 = gSineTable[sprite->data0] / 13;
        sprite->data1 = (sprite->data1 + sprite->data5) & 0xFF;
        sprite->pos2.x = Sin(sprite->data1, sprite->data4);
    }
}

void sub_80CEA04(struct Sprite* sprite)
{
    oamt_set_x3A_32(sprite, move_anim_8072740);
    sprite->callback = sub_8078600;
}

// grasswhistle
#ifdef NONMATCHING
void sub_80CEA20(u8 taskId)
{
    u16 i;
    u16 j;
    u16 a;
    u16 index;
    if ((index = IndexOfSpritePaletteTag(gUnknown_083D712C[0][0])) != 0xFF)
    {
        index = (index << 4) + 0x100;
        for (i = 1; i < 6; i++)
            gPlttBufferFaded[index + i] = gUnknown_083D712C[0][i];
    }
    for (i = 1; i < 4; i++)
    {
        a = AllocSpritePalette(gUnknown_083D712C[i][0]);
        if (a != 0xFF)
        {
            a = (a << 4) + 0x100;
            for (j = 1; j < 6; j++)
                gPlttBufferFaded[a + j] = gUnknown_083D712C[i][j];
        }
    }
    DestroyAnimVisualTask(taskId);
}
#else
__attribute__((naked))
void sub_80CEA20(u8 taskId)
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r9\n\
	mov r6, r8\n\
	push {r6,r7}\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	ldr r4, _080CEAD0 @ =gUnknown_083D712C\n\
	ldrh r0, [r4]\n\
	bl IndexOfSpritePaletteTag\n\
	lsls r0, 24\n\
	lsrs r3, r0, 24\n\
	cmp r3, 0xFF\n\
	beq _080CEA64\n\
	lsls r0, r3, 20\n\
	movs r1, 0x80\n\
	lsls r1, 17\n\
	adds r0, r1\n\
	lsrs r3, r0, 16\n\
	movs r2, 0x1\n\
	ldr r5, _080CEAD4 @ =gPlttBufferFaded\n\
_080CEA4C:\n\
	adds r1, r3, r2\n\
	lsls r1, 1\n\
	adds r1, r5\n\
	lsls r0, r2, 1\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, 0x5\n\
	bls _080CEA4C\n\
_080CEA64:\n\
	movs r4, 0x1\n\
	ldr r0, _080CEAD0 @ =gUnknown_083D712C\n\
	mov r8, r0\n\
_080CEA6A:\n\
	lsls r0, r4, 1\n\
	adds r0, r4\n\
	lsls r5, r0, 2\n\
	mov r1, r8\n\
	adds r0, r5, r1\n\
	ldrh r0, [r0]\n\
	bl AllocSpritePalette\n\
	lsls r0, 24\n\
	lsrs r3, r0, 24\n\
	adds r4, 0x1\n\
	mov r12, r4\n\
	cmp r3, 0xFF\n\
	beq _080CEAB2\n\
	lsls r0, r3, 20\n\
	movs r1, 0x80\n\
	lsls r1, 17\n\
	adds r0, r1\n\
	lsrs r3, r0, 16\n\
	movs r2, 0x1\n\
	ldr r7, _080CEAD4 @ =gPlttBufferFaded\n\
	ldr r6, _080CEAD0 @ =gUnknown_083D712C\n\
	adds r4, r5, 0\n\
_080CEA98:\n\
	adds r1, r3, r2\n\
	lsls r1, 1\n\
	adds r1, r7\n\
	lsls r0, r2, 1\n\
	adds r0, r4\n\
	adds r0, r6\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, 0x5\n\
	bls _080CEA98\n\
_080CEAB2:\n\
	mov r1, r12\n\
	lsls r0, r1, 16\n\
	lsrs r4, r0, 16\n\
	cmp r4, 0x3\n\
	bls _080CEA6A\n\
	mov r0, r9\n\
	bl DestroyAnimVisualTask\n\
	pop {r3,r4}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CEAD0: .4byte gUnknown_083D712C\n\
_080CEAD4: .4byte gPlttBufferFaded\n\
.syntax divided\n");
}
#endif

void sub_80CEAD8(u8 taskId)
{
    u16 i;
    for (i = 1; i < 4; i++)
        FreeSpritePaletteByTag(gUnknown_083D712C[i][0]);
    DestroyAnimVisualTask(taskId);
}