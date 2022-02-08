#include "photon.h"


const uint8_t RC[12][D] = {
{0x1, 0x0, 0x2, 0x6, 0xe, 0xf, 0xd, 0x9}, 
{0x3, 0x2, 0x0, 0x4, 0xc, 0xd, 0xf, 0xb}, 
{0x7, 0x6, 0x4, 0x0, 0x8, 0x9, 0xb, 0xf}, 
{0xe, 0xf, 0xd, 0x9, 0x1, 0x0, 0x2, 0x6}, 
{0xd, 0xc, 0xe, 0xa, 0x2, 0x3, 0x1, 0x5}, 
{0xb, 0xa, 0x8, 0xc, 0x4, 0x5, 0x7, 0x3}, 
{0x6, 0x7, 0x5, 0x1, 0x9, 0x8, 0xa, 0xe}, 
{0xc, 0xd, 0xf, 0xb, 0x3, 0x2, 0x0, 0x4}, 
{0x9, 0x8, 0xa, 0xe, 0x6, 0x7, 0x5, 0x1}, 
{0x2, 0x3, 0x1, 0x5, 0xd, 0xc, 0xe, 0xa}, 
{0x5, 0x4, 0x6, 0x2, 0xa, 0xb, 0x9, 0xd}, 
{0xa, 0xb, 0x9, 0xd, 0x5, 0x4, 0x6, 0x2}
};

const uint64_t SCShRMCS_Table2[D/2][1<<(2*S)] = {
{
0x040402070200090eULL, 0x0a020f090b020f0fULL, 0x0805070b080e0809ULL, 0x0f06080c050f0b00ULL, 0x020d090107070004ULL, 0x0c0b040f0e050605ULL, 0x000a0103040b0702ULL, 0x0b080b080304050cULL, 0x0e0c0c0d0d090103ULL, 0x090f030a0008020aULL, 0x06030a05010c0e08ULL, 0x0d01000e06030c06ULL, 0x050e06060a06030dULL, 0x07090e04090a040bULL, 0x03070d000f010a07ULL, 0x010005020c0d0d01ULL, 
0x0d0505010102040cULL, 0x0303080f0800020dULL, 0x0104000d0b0c050bULL, 0x06070f0a060d0602ULL, 0x0b0c0e0704050d06ULL, 0x050a03090d070b07ULL, 0x090b060507090a00ULL, 0x02090c0e0006080eULL, 0x070d0b0b0e0b0c01ULL, 0x000e040c030a0f08ULL, 0x0f020d03020e030aULL, 0x0400070805010104ULL, 0x0c0f010009040e0fULL, 0x0e0809020a080909ULL, 0x0a060a060c030705ULL, 0x080102040f0f0003ULL, 
0x0e0304060b0e0c00ULL, 0x00050908020c0a01ULL, 0x0202010a01000d07ULL, 0x05010e0d0c010e0eULL, 0x080a0f000e09050aULL, 0x060c020e070b030bULL, 0x0a0d07020d05020cULL, 0x010f0d090a0a0002ULL, 0x040b0a0c0407040dULL, 0x0308050b09060704ULL, 0x0c040c0408020b06ULL, 0x0706060f0f0d0908ULL, 0x0f09000703080603ULL, 0x0d0e080500040105ULL, 0x09000b01060f0f09ULL, 0x0b0703030503080fULL, 
0x030a0e05030f0301ULL, 0x0d0c030b0a0d0500ULL, 0x0f0b0b0909010206ULL, 0x0808040e0400010fULL, 0x0503050306080a0bULL, 0x0b05080d0f0a0c0aULL, 0x07040d0105040d0dULL, 0x0c06070a020b0f03ULL, 0x0902000f0c060b0cULL, 0x0e010f0801070805ULL, 0x010d060700030407ULL, 0x0a0f0c0c070c0609ULL, 0x02000a040b090902ULL, 0x0007020608050e04ULL, 0x040901020e0e0008ULL, 0x060e09000d02070eULL, 
0x010e010e0f070209ULL, 0x0f080c0006050408ULL, 0x0d0f04020509030eULL, 0x0a0c0b0508080007ULL, 0x07070a080a000b03ULL, 0x0901070603020d02ULL, 0x0500020a090c0c05ULL, 0x0e0208010e030e0bULL, 0x0b060f04000e0a04ULL, 0x0c0500030d0f090dULL, 0x0309090c0c0b050fULL, 0x080b03070b040701ULL, 0x0004050f0701080aULL, 0x02030d0d040d0f0cULL, 0x060d0e0902060100ULL, 0x040a060b010a0606ULL, 
0x080f06080c050f0bULL, 0x06090b060507090aULL, 0x040e0304060b0e0cULL, 0x030d0c030b0a0d05ULL, 0x0e060d0e09020601ULL, 0x0000000000000000ULL, 0x0c01050c0a0e0107ULL, 0x07030f070d010309ULL, 0x02070802030c0706ULL, 0x050407050e0d040fULL, 0x0a080e0a0f09080dULL, 0x010a040108060a03ULL, 0x0905020904030508ULL, 0x0b020a0b070f020eULL, 0x0f0c090f01040c02ULL, 0x0d0b010d02080b04ULL, 
0x02080009050b0a05ULL, 0x0c0e0d070c090c04ULL, 0x0e0905050f050b02ULL, 0x090a0a020204080bULL, 0x04010b0f000c030fULL, 0x0a070601090e050eULL, 0x0606030d03000409ULL, 0x0d040906040f0607ULL, 0x08000e030a020208ULL, 0x0f03010407030101ULL, 0x000f080b06070d03ULL, 0x0b0d020001080f0dULL, 0x030204080d0d0006ULL, 0x01050c0a0e010700ULL, 0x050b0f0e080a090cULL, 0x070c070c0b060e0aULL, 
0x05060c0b0404000aULL, 0x0b0001050d06060bULL, 0x090709070e0a010dULL, 0x0e040600030b0204ULL, 0x030f070d01030900ULL, 0x0d090a0308010f01ULL, 0x01080f0f020f0e06ULL, 0x0a0a050405000c08ULL, 0x0f0e02010b0d0807ULL, 0x080d0d06060c0b0eULL, 0x070104090708070cULL, 0x0c030e0200070502ULL, 0x040c080a0c020a09ULL, 0x060b00080f0e0d0fULL, 0x0205030c09050303ULL, 0x00020b0e0a090405ULL, 
0x0b09070f06090707ULL, 0x050f0a010f0b0106ULL, 0x070802030c070600ULL, 0x000b0d0401060509ULL, 0x0d000c09030e0e0dULL, 0x030601070a0c080cULL, 0x0f07040b0002090bULL, 0x04050e00070d0b05ULL, 0x0101090509000f0aULL, 0x0602060204010c03ULL, 0x090e0f0d05050001ULL, 0x020c0506020a020fULL, 0x0a03030e0e0f0d04ULL, 0x08040b0c0d030a02ULL, 0x0c0a08080b08040eULL, 0x0e0d000a08040308ULL, 
0x06000d0c0e080806ULL, 0x08060002070a0e07ULL, 0x0a01080004060901ULL, 0x0d02070709070a08ULL, 0x0009060a0b0f010cULL, 0x0e0f0b04020d070dULL, 0x020e0e080803060aULL, 0x090c04030f0c0404ULL, 0x0c0803060101000bULL, 0x0b0b0c010c000302ULL, 0x0407050e0d040f00ULL, 0x0f050f050a0b0d0eULL, 0x070a090d060e0205ULL, 0x050d010f05020503ULL, 0x0103020b03090b0fULL, 0x03040a0900050c09ULL, 
0x07020300080c0102ULL, 0x09040e0e010e0703ULL, 0x0b03060c02020005ULL, 0x0c00090b0f03030cULL, 0x010b08060d0b0808ULL, 0x0f0d050804090e09ULL, 0x030c00040e070f0eULL, 0x080e0a0f09080d00ULL, 0x0d0a0d0a0705090fULL, 0x0a09020d0a040a06ULL, 0x05050b020b000604ULL, 0x0e0701090c0f040aULL, 0x06080701000a0b01ULL, 0x040f0f0303060c07ULL, 0x00010c07050d020bULL, 0x020604050601050dULL, 
0x000c0f0209030b0dULL, 0x0e0a020c00010d0cULL, 0x0c0d0a0e030d0a0aULL, 0x0b0e05090e0c0903ULL, 0x060504040c040207ULL, 0x0803090a05060406ULL, 0x04020c060f080501ULL, 0x0f00060d0807070fULL, 0x0a040108060a0300ULL, 0x0d070e0f0b0b0009ULL, 0x020b07000a0f0c0bULL, 0x09090d0b0d000e05ULL, 0x01060b030105010eULL, 0x0301030102090608ULL, 0x070f000504020804ULL, 0x05080807070e0f02ULL, 
0x0c070b0d07060d08ULL, 0x020106030e040b09ULL, 0x00060e010d080c0fULL, 0x0705010600090f06ULL, 0x0a0e000b02010402ULL, 0x04080d050b030203ULL, 0x08090809010d0304ULL, 0x030b02020602010aULL, 0x060f0507080f0505ULL, 0x010c0a00050e060cULL, 0x0e00030f040a0a0eULL, 0x0502090403050800ULL, 0x0d0d0f0c0f00070bULL, 0x0f0a070e0c0c000dULL, 0x0b04040a0a070e01ULL, 0x09030c08090b0907ULL, 
0x0f010a0a0d0a0504ULL, 0x0107070404080305ULL, 0x03000f0607040403ULL, 0x040300010a05070aULL, 0x0908010c080d0c0eULL, 0x070e0c02010f0a0fULL, 0x0b0f090e0b010b08ULL, 0x000d03050c0e0906ULL, 0x0509040002030d09ULL, 0x020a0b070f020e00ULL, 0x0d0602080e060202ULL, 0x060408030909000cULL, 0x0e0b0e0b050c0f07ULL, 0x0c0c060906000801ULL, 0x0802050d000b060dULL, 0x0a050d0f0307010bULL, 
0x090d08040a01060fULL, 0x070b050a0303000eULL, 0x050c0d08000f0708ULL, 0x020f020f0d0e0401ULL, 0x0f0403020f060f05ULL, 0x01020e0c06040904ULL, 0x0d030b000c0a0803ULL, 0x0601010b0b050a0dULL, 0x0305060e05080e02ULL, 0x0406090908090d0bULL, 0x0b0a0006090d0109ULL, 0x00080a0d0e020307ULL, 0x08070c0502070c0cULL, 0x0a000407010b0b0aULL, 0x0e0e070307000506ULL, 0x0c090f01040c0200ULL, 
0x0a0b0903000d0e03ULL, 0x040d040d090f0802ULL, 0x060a0c0f0a030f04ULL, 0x0109030807020c0dULL, 0x0c020205050a0709ULL, 0x02040f0b0c080108ULL, 0x0e050a070606000fULL, 0x0507000c01090201ULL, 0x000307090f04060eULL, 0x0700080e02050507ULL, 0x080c010103010905ULL, 0x030e0b0a040e0b0bULL, 0x0b010d02080b0400ULL, 0x090605000b070306ULL, 0x0d0806040d0c0d0aULL, 0x0f0f0e060e000a0cULL, 
},
{
0x020a010505000906ULL, 0x0d0b0a080e0f0d07ULL, 0x090d0500010b0601ULL, 0x0704090f0d050408ULL, 0x0e00030e070c070cULL, 0x010108030c03030dULL, 0x0a060c0608080c0aULL, 0x0f08040c000d0104ULL, 0x0507070b0307080bULL, 0x0b0e0b040f090a02ULL, 0x060c0e0d0a040200ULL, 0x0302060702010f0eULL, 0x00090f010b020505ULL, 0x040f000904060e03ULL, 0x0c030d0a090e0b0fULL, 0x08050202060a0009ULL, 
0x070f0f0a0c0f060aULL, 0x080e04070700020bULL, 0x0c080b0f0804090dULL, 0x02010700040a0b04ULL, 0x0b050d010e030800ULL, 0x0404060c050c0c01ULL, 0x0f03020901070306ULL, 0x0a0d0a0309020e08ULL, 0x000209040a080707ULL, 0x0e0b050b0606050eULL, 0x03090002030b0d0cULL, 0x060708080b0e0002ULL, 0x050c010e020d0a09ULL, 0x010a0e060d09010fULL, 0x0906030500010403ULL, 0x0d000c0d0f050f05ULL, 
0x0a020d0e0f0b0204ULL, 0x0503060304040605ULL, 0x0105090b0b000d03ULL, 0x0f0c0504070e0f0aULL, 0x06080f050d070c0eULL, 0x090904080608080fULL, 0x020e000d02030708ULL, 0x070008070a060a06ULL, 0x0d0f0b00090c0309ULL, 0x0306070f05020100ULL, 0x0e040206000f0902ULL, 0x0b0a0a0c080a040cULL, 0x0801030a01090e07ULL, 0x0c070c020e0d0501ULL, 0x040b01010305000dULL, 0x000d0e090c010b0bULL, 
0x01090a0002050c02ULL, 0x0e08010d090a0803ULL, 0x0a0e0e05060e0305ULL, 0x0407020a0a00010cULL, 0x0d03080b00090208ULL, 0x020203060b060609ULL, 0x090507030f0d090eULL, 0x0c0b0f0907080400ULL, 0x06040c0e04020d0fULL, 0x080d0001080c0f06ULL, 0x050f05080d010704ULL, 0x00010d0205040a0aULL, 0x030a04040c070001ULL, 0x070c0b0c03030b07ULL, 0x0f00060f0e0b0e0bULL, 0x0b060907010f050dULL, 
0x060e0709000c0507ULL, 0x090f0c040b030106ULL, 0x0d09030c04070a00ULL, 0x03000f0308090809ULL, 0x0a04050202000b0dULL, 0x05050e0f090f0f0cULL, 0x0e020a0a0d04000bULL, 0x0b0c020005010d05ULL, 0x01030107060b040aULL, 0x0f0a0d080a050603ULL, 0x020808010f080e01ULL, 0x0706000b070d030fULL, 0x040d090d0e0e0904ULL, 0x000b0605010a0202ULL, 0x08070b060c02070eULL, 0x0c01040e03060c08ULL, 
0x030b090609030a0bULL, 0x0c0a020b020c0e0aULL, 0x080c0d030d08050cULL, 0x0605010c01060705ULL, 0x0f010b0d0b0f0401ULL, 0x0000000000000000ULL, 0x0b070405040b0f07ULL, 0x0e090c0f0c0e0209ULL, 0x04060f080f040b06ULL, 0x0a0f0307030a090fULL, 0x070d060e0607010dULL, 0x02030e040e020c03ULL, 0x0108070207010608ULL, 0x050e080a08050d0eULL, 0x0d020509050d0802ULL, 0x09040a010a090304ULL, 
0x0b03050d03080109ULL, 0x04020e0008070508ULL, 0x0004010807030e0eULL, 0x0e0d0d070b0d0c07ULL, 0x0709070601040f03ULL, 0x08080c0b0a0b0b02ULL, 0x030f080e0e000405ULL, 0x060100040605090bULL, 0x0c0e0303050f0004ULL, 0x02070f0c0901020dULL, 0x0f050a050c0c0a0fULL, 0x0a0b020f04090701ULL, 0x09000b090d0a0d0aULL, 0x0d060401020e060cULL, 0x050a09020f060300ULL, 0x010c060a00020806ULL, 
0x08000e08040d040dULL, 0x070105050f02000cULL, 0x03070a0d00060b0aULL, 0x0d0e06020c080903ULL, 0x040a0c0306010a07ULL, 0x0b0b070e0d0e0e06ULL, 0x000c030b09050101ULL, 0x05020b0101000c0fULL, 0x0f0d0806020a0500ULL, 0x010404090e040709ULL, 0x0c0601000b090f0bULL, 0x0908090a030c0205ULL, 0x0a03000c0a0f080eULL, 0x0e050f04050b0308ULL, 0x0609020708030604ULL, 0x020f0d0f07070d02ULL, 
0x0e060b020a070e05ULL, 0x0107000f01080a04ULL, 0x05010f070e0c0102ULL, 0x0b0803080202030bULL, 0x020c0909080b000fULL, 0x0d0d02040304040eULL, 0x060a0601070f0b09ULL, 0x03040e0b0f0a0607ULL, 0x090b0d0c0c000f08ULL, 0x07020103000e0d01ULL, 0x0a00040a05030503ULL, 0x0f0e0c000d06080dULL, 0x0c05050604050206ULL, 0x08030a0e0b010900ULL, 0x000f070d06090c0cULL, 0x04090805090d070aULL, 
0x050d0c0c07090003ULL, 0x0a0c07010c060402ULL, 0x0e0a080903020f04ULL, 0x000304060f0c0d0dULL, 0x09070e0705050e09ULL, 0x0606050a0e0a0a08ULL, 0x0d01010f0a01050fULL, 0x080f090502040801ULL, 0x02000a02010e010eULL, 0x0c09060d0d000307ULL, 0x010b0304080d0b05ULL, 0x04050b0e0008060bULL, 0x070e0208090b0c00ULL, 0x03080d00060f0706ULL, 0x0b0400030b07020aULL, 0x0f020f0b0403090cULL, 
0x0f07030106040d08ULL, 0x0006080c0d0b0909ULL, 0x04000704020f020fULL, 0x0a090b0b0e010006ULL, 0x030d010a04080302ULL, 0x0c0c0a070f070703ULL, 0x070b0e020b0c0804ULL, 0x020506080309050aULL, 0x080a050f00030c05ULL, 0x060309000c0d0e0cULL, 0x0b010c090900060eULL, 0x0e0f040301050b00ULL, 0x0d040d050806010bULL, 0x0902020d07020a0dULL, 0x010e0f0e0a0a0f01ULL, 0x05080006050e0407ULL, 
0x0c0408040101080cULL, 0x030503090a0e0c0dULL, 0x07030c01050a070bULL, 0x090a000e09040502ULL, 0x000e0a0f030d0606ULL, 0x0f0f010208020207ULL, 0x040805070c090d00ULL, 0x01060d0d040c000eULL, 0x0b090e0a07060901ULL, 0x050002050b080b08ULL, 0x0802070c0e05030aULL, 0x0d0c0f0606000e04ULL, 0x0e0706000f03040fULL, 0x0a01090800070f09ULL, 0x020d040b0d0f0a05ULL, 0x060b0b03020b0103ULL, 
0x0d0500070d020b01ULL, 0x02040b0a060d0f00ULL, 0x0602040209090406ULL, 0x080b080d0507060fULL, 0x010f020c0f0e050bULL, 0x0e0e09010401010aULL, 0x05090d04000a0e0dULL, 0x0007050e080f0303ULL, 0x0a0806090b050a0cULL, 0x04010a06070b0805ULL, 0x09030f0f02060007ULL, 0x0c0d07050a030d09ULL, 0x0f060e0303000702ULL, 0x0b00010b0c040c04ULL, 0x030c0c08010c0908ULL, 0x070a03000e08020eULL, 
0x000802030e060f0fULL, 0x0f09090e05090b0eULL, 0x0b0f06060a0d0008ULL, 0x05060a0906030201ULL, 0x0c0200080c0a0105ULL, 0x03030b0507050504ULL, 0x08040f00030e0a03ULL, 0x0d0a070a0b0b070dULL, 0x0705040d08010e02ULL, 0x090c0802040f0c0bULL, 0x040e0d0b01020409ULL, 0x0100050109070907ULL, 0x020b0c070004030cULL, 0x060d030f0f00080aULL, 0x0e010e0c02080d06ULL, 0x0a0701040d0c0600ULL, 
0x0901060b080e0700ULL, 0x06000d0603010301ULL, 0x0206020e0c050807ULL, 0x0c0f0e01000b0a0eULL, 0x050b04000a02090aULL, 0x0a0a0f0d010d0d0bULL, 0x010d0b080506020cULL, 0x040303020d030f02ULL, 0x0e0c00050e09060dULL, 0x00050c0a02070404ULL, 0x0d070903070a0c06ULL, 0x080901090f0f0108ULL, 0x0b02080f060c0b03ULL, 0x0f04070709080005ULL, 0x07080a0404000509ULL, 0x030e050c0b040e0fULL, 
0x040c040f0b0a030eULL, 0x0b0d0f020005070fULL, 0x0f0b000a0f010c09ULL, 0x01020c05030f0e00ULL, 0x0806060409060d04ULL, 0x07070d0902090905ULL, 0x0c00090c06020602ULL, 0x090e01060e070b0cULL, 0x030102010d0d0203ULL, 0x0d080e0e0103000aULL, 0x000a0b07040e0808ULL, 0x0504030d0c0b0506ULL, 0x060f0a0b05080f0dULL, 0x020905030a0c040bULL, 0x0a05080007040107ULL, 0x0e03070808000a01ULL, 
},
{
0x080b0a0d0c030001ULL, 0x0303080a0a0e0a00ULL, 0x0c06040b0d060306ULL, 0x000205010e09060fULL, 0x0a040d0e0508080bULL, 0x010c0f090305020aULL, 0x0501010f0200010dULL, 0x0d080e03000a0703ULL, 0x0e090308040d0b0cULL, 0x020d020207020e05ULL, 0x070e060c0b0b0907ULL, 0x0f07090009010f09ULL, 0x06000c0406070d02ULL, 0x09050005010f0404ULL, 0x040f0b070f0c0508ULL, 0x0b0a070608040c0eULL, 
0x0d020c0603010a05ULL, 0x060a0e01050c0004ULL, 0x090f020002040902ULL, 0x050b030a010b0c0bULL, 0x0f0d0b050a0a020fULL, 0x040509020c07080eULL, 0x000807040d020b09ULL, 0x080108080f080d07ULL, 0x0b0005030b0f0108ULL, 0x0704040908000401ULL, 0x0207000704090303ULL, 0x0a0e0f0b0603050dULL, 0x03090a0f09050706ULL, 0x0c0c060e0e0d0e00ULL, 0x01060d0c000e0f0cULL, 0x0e03010d0706060aULL, 
0x00010b09070d030eULL, 0x0b09090e0100090fULL, 0x040c050f06080009ULL, 0x0808040505070500ULL, 0x020e0c0a0e060b04ULL, 0x09060e0d080b0105ULL, 0x0d0b000b090e0202ULL, 0x05020f070b04040cULL, 0x0603020c0f030803ULL, 0x0a0703060c0c0d0aULL, 0x0f04070800050a08ULL, 0x070d0804020f0c06ULL, 0x0e0a0d000d090e0dULL, 0x010f01010a01070bULL, 0x0c050a0304020607ULL, 0x03000602030a0f01ULL, 
0x0b0c0805090c060cULL, 0x00040a020f010c0dULL, 0x0f0106030809050bULL, 0x030507090b060002ULL, 0x09030f0600070e06ULL, 0x020b0d01060a0407ULL, 0x06060307070f0700ULL, 0x0e0f0c0b0505010eULL, 0x0d0e010001020d01ULL, 0x010a000a020d0808ULL, 0x040904040e040f0aULL, 0x0c000b080c0e0904ULL, 0x05070e0c03080b0fULL, 0x0a02020d04000209ULL, 0x0708090f0a030305ULL, 0x080d050e0d0b0a03ULL, 
0x0c0e030f0004080fULL, 0x070601080609020eULL, 0x08030d0901010b08ULL, 0x04070c03020e0e01ULL, 0x0e01040c090f0005ULL, 0x0509060b0f020a04ULL, 0x0104080d0e070903ULL, 0x090d07010c0d0f0dULL, 0x0a0c0a0a080a0302ULL, 0x06080b000b05060bULL, 0x030b0f0e070c0109ULL, 0x0b02000205060707ULL, 0x020505060a00050cULL, 0x0d0009070d080c0aULL, 0x000a0205030b0d06ULL, 0x0f0f0e0404030400ULL, 
0x090705040f06020bULL, 0x020f0703090b080aULL, 0x0d0a0b020e03010cULL, 0x010e0a080d0c0405ULL, 0x0b080207060d0a01ULL, 0x0000000000000000ULL, 0x040d0e0601050307ULL, 0x0c04010a030f0509ULL, 0x0f050c0107080906ULL, 0x03010d0b04070c0fULL, 0x06020905080e0b0dULL, 0x0e0b06090a040d03ULL, 0x070c030d05020f08ULL, 0x08090f0c020a060eULL, 0x0503040e0c090702ULL, 0x0a06080f0b010e04ULL, 
0x010d040004080104ULL, 0x0a05060702050b05ULL, 0x05000a06050d0203ULL, 0x09040b0c0602070aULL, 0x030203030d03090eULL, 0x080a01040b0e030fULL, 0x0c070f020a0b0008ULL, 0x040e000e08010606ULL, 0x070f0d050c060a09ULL, 0x0b0b0c0f0f090f00ULL, 0x0e08080103000802ULL, 0x0601070d010a0e0cULL, 0x0f0602090e0c0c07ULL, 0x00030e0809040501ULL, 0x0d09050a0707040dULL, 0x020c090b000f0d0bULL, 
0x020a060801070709ULL, 0x0902040f070a0d08ULL, 0x0607080e0002040eULL, 0x0a030904030d0107ULL, 0x0005010b080c0f03ULL, 0x0b0d030c0e010502ULL, 0x0f000d0a0f040605ULL, 0x070902060d0e000bULL, 0x04080f0d09090c04ULL, 0x080c0e070a06090dULL, 0x0d0f0a09060f0e0fULL, 0x0506050504050801ULL, 0x0c0100010b030a0aULL, 0x03040c000c0b030cULL, 0x0e0e070202080200ULL, 0x010b0b0305000b06ULL, 
0x0404020b0b0a0b00ULL, 0x0f0c000c0d070101ULL, 0x00090c0d0a0f0807ULL, 0x0c0d0d0709000d0eULL, 0x060b05080201030aULL, 0x0d03070f040c090bULL, 0x090e090905090a0cULL, 0x0107060507030c02ULL, 0x02060b0e0304000dULL, 0x0e020a04000b0504ULL, 0x0b010e0a0c020206ULL, 0x030801060e080408ULL, 0x0a0f0402010e0603ULL, 0x050a080306060f05ULL, 0x0800030108050e09ULL, 0x07050f000f0d070fULL, 
0x0f090107050b0e02ULL, 0x0401030003060403ULL, 0x0b040f01040e0d05ULL, 0x07000e0b0701080cULL, 0x0d0606040c000608ULL, 0x060e04030a0d0c09ULL, 0x02030a050b080f0eULL, 0x0a0a050909020900ULL, 0x090b08020d05050fULL, 0x050f09080e0a0006ULL, 0x000c0d0602030704ULL, 0x0805020a0009010aULL, 0x0102070e0f0f0301ULL, 0x0e070b0f08070a07ULL, 0x030d000d06040b0bULL, 0x0c080c0c010c020dULL, 
0x05080d02080f090aULL, 0x0e000f050e02030bULL, 0x01050304090a0a0dULL, 0x0d01020e0a050f04ULL, 0x07070a0101040100ULL, 0x0c0f080607090b01ULL, 0x08020600060c0806ULL, 0x000b090c04060e08ULL, 0x030a040700010207ULL, 0x0f0e050d030e070eULL, 0x0a0d01030f07000cULL, 0x02040e0f0d0d0602ULL, 0x0b030b0b020b0409ULL, 0x0406070a05030d0fULL, 0x090c0c080b000c03ULL, 0x060900090c080505ULL, 
0x060f0f0a0d000f07ULL, 0x0d070d0d0b0d0506ULL, 0x0202010c0c050c00ULL, 0x0e0600060f0a0909ULL, 0x04000809040b070dULL, 0x0f080a0e02060d0cULL, 0x0b05040803030e0bULL, 0x030c0b0401090805ULL, 0x000d060f050e040aULL, 0x0c09070506010103ULL, 0x090a030b0a080601ULL, 0x01030c070802000fULL, 0x0804090307040204ULL, 0x07010502000c0b02ULL, 0x0a0b0e000e0f0a0eULL, 0x050e020109070308ULL, 
0x070300030e050d0dULL, 0x0c0b02040808070cULL, 0x030e0e050f000e0aULL, 0x0f0a0f0f0c0f0b03ULL, 0x050c0700070e0507ULL, 0x0e04050701030f06ULL, 0x0a090b0100060c01ULL, 0x0200040d020c0a0fULL, 0x01010906060b0600ULL, 0x0d05080c05040309ULL, 0x08060c02090d040bULL, 0x000f030e0b070205ULL, 0x0908060a0401000eULL, 0x060d0a0b03090908ULL, 0x0b0701090d0a0804ULL, 0x04020d080a020102ULL, 
0x0a00070c0a090406ULL, 0x0108050b0c040e07ULL, 0x0e0d090a0b0c0701ULL, 0x0209080008030208ULL, 0x080f000f03020c0cULL, 0x03070208050f060dULL, 0x070a0c0e040a050aULL, 0x0f03030206000304ULL, 0x0c020e0902070f0bULL, 0x00060f0301080a02ULL, 0x05050b0d0d010d00ULL, 0x0d0c04010f0b0b0eULL, 0x040b0105000d0905ULL, 0x0b0e0d0407050003ULL, 0x060406060906010fULL, 0x09010a070e0e0809ULL, 
0x0306090102020503ULL, 0x080e0b06040f0f02ULL, 0x070b070703070604ULL, 0x0b0f060d0008030dULL, 0x01090e020b090d09ULL, 0x0a010c050d040708ULL, 0x0e0c02030c01040fULL, 0x06050d0f0e0b0201ULL, 0x050400040a0c0e0eULL, 0x0900010e09030b07ULL, 0x0c030500050a0c05ULL, 0x040a0a0c07000a0bULL, 0x0d0d0f0808060800ULL, 0x020803090f0e0106ULL, 0x0f02080b010d000aULL, 0x0007040a0605090cULL, 
0x0e050e0e060e0c08ULL, 0x050d0c0900030609ULL, 0x0a080008070b0f0fULL, 0x060c010204040a06ULL, 0x0c0a090d0f050402ULL, 0x07020b0a09080e03ULL, 0x030f050c080d0d04ULL, 0x0b060a000a070b0aULL, 0x0807070b0e000705ULL, 0x040306010d0f020cULL, 0x0100020f0106050eULL, 0x09090d03030c0300ULL, 0x000e08070c0a010bULL, 0x0f0b04060b02080dULL, 0x02010f0405010901ULL, 0x0d04030502090007ULL, 
},
{
0x0c0808070c050207ULL, 0x0d010500020a090cULL, 0x0b020d01000e0603ULL, 0x020f020b07000a0fULL, 0x060d03040a090005ULL, 0x07040e0304060b0eULL, 0x000e0b05080d0f0aULL, 0x0e09010903080702ULL, 0x0107060206020401ULL, 0x080a0908010c080dULL, 0x0a0b00060e010d08ULL, 0x040c0a0a05040500ULL, 0x0f000c0e0d070c09ULL, 0x0903040f0f030306ULL, 0x0505070d0b0b0e0bULL, 0x03060f0c090f0104ULL, 
0x040f0b080b080304ULL, 0x0506060f0507080fULL, 0x03050e0e07030700ULL, 0x0a080104000d0b0cULL, 0x0e0a000b0d040106ULL, 0x0f030d0c030b0a0dULL, 0x0809080a0f000e09ULL, 0x060e020604050601ULL, 0x0900050d010f0502ULL, 0x000d0a070601090eULL, 0x020c0309090c0c0bULL, 0x0c0b090502090403ULL, 0x07070f010a0a0d0aULL, 0x01040700080e0205ULL, 0x0d0204020c060f08ULL, 0x0b010c030e020007ULL, 
0x010e010c0a00050eULL, 0x00070c0b040f0e05ULL, 0x0604040a060b010aULL, 0x0f090b0001050d06ULL, 0x0b0b0a0f0c0c070cULL, 0x0a02070802030c07ULL, 0x0d08020e0e080803ULL, 0x030f0802050d000bULL, 0x0c010f0900070308ULL, 0x050c000307090f04ULL, 0x070d090d08040a01ULL, 0x090a030103010209ULL, 0x020605050b020b00ULL, 0x04050d040906040fULL, 0x08030e060d0e0902ULL, 0x0e0006070f0a060dULL, 
0x05040902000f0c06ULL, 0x040d04050e00070dULL, 0x020e0c040c040802ULL, 0x0b03030e0b0a040eULL, 0x0f01020106030e04ULL, 0x0e080f06080c050fULL, 0x09020a000407010bULL, 0x0705000c0f020903ULL, 0x080b07070a080a00ULL, 0x0106080d0d06060cULL, 0x03070103020b0309ULL, 0x0d000b0f090e0b01ULL, 0x060c0d0b010d0208ULL, 0x000f050a03090d07ULL, 0x0c0906080701000aULL, 0x0a0a0e0905050f05ULL, 
0x030b050b0f0e080aULL, 0x0202080c01010301ULL, 0x0401000d03050c0eULL, 0x0d0c0f07040b0002ULL, 0x090e0e0809020a08ULL, 0x0807030f070d0103ULL, 0x0f0d06090b060507ULL, 0x010a0c0500030d0fULL, 0x0e040b0e05090e0cULL, 0x0709040402070200ULL, 0x05080d0a0d0a0705ULL, 0x0b0f0706060f0f0dULL, 0x000301020e0c0604ULL, 0x060009030c08090bULL, 0x0a060a0108000406ULL, 0x0c0502000a040b09ULL, 
0x0b0c060408030909ULL, 0x0a050b03060c0202ULL, 0x0c06030204080d0dULL, 0x050b0c0803060101ULL, 0x01090d070e0f0b0bULL, 0x0000000000000000ULL, 0x070a05060c0b0404ULL, 0x090d0f0a070e0c0cULL, 0x0603080102040f0fULL, 0x0f0e070b050a0303ULL, 0x0d0f0e050a070606ULL, 0x0308040901020e0eULL, 0x0804020d09010707ULL, 0x0e070a0c0b050808ULL, 0x0201090e0f0d0505ULL, 0x0402010f0d090a0aULL, 
0x060a0f0f0e060e00ULL, 0x070302080009050bULL, 0x01000a09020d0a04ULL, 0x080d050305030608ULL, 0x0c0f040c080a0c02ULL, 0x0d06090b06050709ULL, 0x0a0c0c0d0a0e030dULL, 0x040b0601010b0b05ULL, 0x0b05010a04010806ULL, 0x02080e00030f040aULL, 0x0009070e0c02010fULL, 0x0e0e0d0207070907ULL, 0x05020b060f04000eULL, 0x030103070d000f01ULL, 0x0f0700050908020cULL, 0x090408040b0c0d03ULL, 
0x0f060e0a020c0001ULL, 0x0e0f030d0c030b0aULL, 0x080c0b0c0e070405ULL, 0x0101040609090809ULL, 0x0503050904000203ULL, 0x040a080e0a0f0908ULL, 0x03000d0806040d0cULL, 0x0d0707040d010504ULL, 0x0209000f080b0607ULL, 0x0b040f050f050a0bULL, 0x0905060b00080f0eULL, 0x07020c070b0d0706ULL, 0x0c0e0a03030e0e0fULL, 0x0a0d0202010a0100ULL, 0x060b010005020c0dULL, 0x0008090107060302ULL, 
0x0e0d0c00090b0f03ULL, 0x0f04010707040408ULL, 0x0907090605000b07ULL, 0x000a060c020e070bULL, 0x040807030f070d01ULL, 0x05010a040108060aULL, 0x020b0f020d03020eULL, 0x0c0c050e06060a06ULL, 0x03020205030c0905ULL, 0x0a0f0d0f04020509ULL, 0x080e04010b0f000cULL, 0x06090e0d000a0804ULL, 0x0d0508090809010dULL, 0x0b0600080a0d0e02ULL, 0x0700030a0e05030fULL, 0x01030b0b0c010c00ULL, 
0x0a07040e0304060bULL, 0x0b0e09090d0b0d00ULL, 0x0d0d01080f0f020fULL, 0x04000e0208010e03ULL, 0x00020f0d05080409ULL, 0x010b020a0b070f02ULL, 0x0601070c070c0b06ULL, 0x08060d000c09030eULL, 0x07080a0b0903000dULL, 0x0e0505010e0d0c01ULL, 0x0c040c0f01000904ULL, 0x020306030a05010cULL, 0x090f000702060805ULL, 0x0f0c08060002070aULL, 0x030a0b04040a0a07ULL, 0x05090305060e0508ULL, 
0x090902030d0d040dULL, 0x08000f0403020f06ULL, 0x0e03070501060009ULL, 0x070e080f06080c05ULL, 0x030c09000b01060fULL, 0x02050407050e0d04ULL, 0x050f010109050900ULL, 0x0b080b0d02000108ULL, 0x04060c06070a020bULL, 0x0d0b030c00040e07ULL, 0x0f0a0a020f090b02ULL, 0x010d000e040c030aULL, 0x0a01060a0c0f0a03ULL, 0x0c020e0b0e0b050cULL, 0x00040d090a030801ULL, 0x060705080807070eULL, 
0x0005030601070a0cULL, 0x010c0e010f080107ULL, 0x070f06000d0c0e08ULL, 0x0e02090a0a020204ULL, 0x0a000805070b080eULL, 0x0b09050209040305ULL, 0x0c030004050f0701ULL, 0x02040a080e0a0f09ULL, 0x0d0a0d030b000c0aULL, 0x040702090c0e0006ULL, 0x06060b0703030503ULL, 0x0801010b08060d0bULL, 0x030d070f00050402ULL, 0x050e0f0e02010b0dULL, 0x09080c0c06090600ULL, 0x0f0b040d040d090fULL, 
0x07010d0505010102ULL, 0x060800020b0e0a09ULL, 0x000b0803090a0506ULL, 0x090607090e04090aULL, 0x0d040606030d0300ULL, 0x0c0d0b010d02080bULL, 0x0b070e0701090c0fULL, 0x0500040b0a0c0407ULL, 0x0a0e03000f060704ULL, 0x03030c0a08080b08ULL, 0x0102050407050e0dULL, 0x0f050f080c000605ULL, 0x0409090c04030f0cULL, 0x020a010d06070003ULL, 0x0e0c020f020f0d0eULL, 0x080f0a0e000b0201ULL, 
0x0200070104090708ULL, 0x03090a060a060c03ULL, 0x050a02070802030cULL, 0x0c070d0d0f0c0f00ULL, 0x08050c020205050aULL, 0x090c01050c0a0e01ULL, 0x0e06040300010a05ULL, 0x00010e0f0b04020dULL, 0x0f0f09040e0e010eULL, 0x0602060e09000d02ULL, 0x04030f00060d0807ULL, 0x0a04050c0d08000fULL, 0x01080308050b0906ULL, 0x070b0b09070f0609ULL, 0x0b0d080b03070b04ULL, 0x0d0e000a0103040bULL, 
0x08020009060a0b0fULL, 0x090b0d0e08050004ULL, 0x0f08050f0a010f0bULL, 0x06050a050d0f0307ULL, 0x02070b0a0006090dULL, 0x030e060d0e090206ULL, 0x0404030b02020602ULL, 0x0a03090709070e0aULL, 0x050d0e0c0c0d0d09ULL, 0x0c0001060b030105ULL, 0x0e010808040e0400ULL, 0x000602040f0b0c08ULL, 0x0b0a040007080501ULL, 0x0d090c01050c0a0eULL, 0x010f0f0301040703ULL, 0x070c07020300080cULL, 
0x0d030a0d07020d05ULL, 0x0c0a070a090d060eULL, 0x0a090f0b0b090901ULL, 0x030400010c07050dULL, 0x0706010e010e0f07ULL, 0x060f0c090f01040cULL, 0x0105090f030a0008ULL, 0x0f020303080f0800ULL, 0x000c04080d050b03ULL, 0x09010b020a0b070fULL, 0x0b00020c0506020aULL, 0x050708000e030a02ULL, 0x0e0b0e040600030bULL, 0x0808060504040c04ULL, 0x040e0507000c0109ULL, 0x020d0d0602080e06ULL, 
},
};



inline static void AddKey(uint8_t state[D][D], int round)
{
	*((uint64_t *)state[0]) ^= *((uint64_t *)RC[round]);
}

inline static void SCShRMCS(uint8_t state[D][D])
{
	int c;
	uint8_t os[D][D];
	uint8_t s2i0;
	uint8_t s2i1;
	uint8_t s2i2;
	uint8_t s2i3;
	uint64_t s2o0;
	uint64_t s2o1;
	uint64_t s2o2;
	uint64_t s2o3;
	memcpy(os, state, D*D);

	for(c = 0; c < D; c++) // for all columns
	{
		s2i0 = os[(0+c)&0x7][0] | (os[(1+c)&0x7][1] << 4);
		s2i1 = os[(2+c)&0x7][2] | (os[(3+c)&0x7][3] << 4);
		s2i2 = os[(4+c)&0x7][4] | (os[(5+c)&0x7][5] << 4);
		s2i3 = os[(6+c)&0x7][6] | (os[(7+c)&0x7][7] << 4);
		s2o0 = SCShRMCS_Table2[0][s2i0];
		s2o1 = SCShRMCS_Table2[1][s2i1];
		s2o2 = SCShRMCS_Table2[2][s2i2];
		s2o3 = SCShRMCS_Table2[3][s2i3];
		s2o0 ^= s2o1;
		s2o2 ^= s2o3;
		s2o0 ^= s2o2;
		*((uint64_t *)state[c]) = s2o0;
	}
}

inline static void Permutation(uint8_t state[D][D], int R)
{
	int i;
	for(i = 0; i < R; i++) {
		AddKey(state, i);
		SCShRMCS(state);
	}
}

void PHOTON_Permutation(unsigned char *State_inout)
{
    uint8_t state[D][D];
    int i;

	uint32_t *State_inout_pt;
	uint32_t a_dword;
	uint64_t x;
	uint64_t xl;
	uint64_t xh;
	uint64_t t;

#define STATESIZE_INuint8_tS          ((D * D * S + 7) / 8) // (8 * 8 * 4 + 7) / 8 = 32 uint8_ts
#define STATESIZE_INDWORDS ((STATESIZE_INuint8_tS + 3) / 4) // (32 + 3) / 4 = 8 dwords
	State_inout_pt = (uint32_t *)State_inout;
	for (i = 0; i < STATESIZE_INDWORDS; i++)
	{
		a_dword = State_inout_pt[i];
		xl = (uint64_t)a_dword & 0x0F0F0F0FULL;
		xh = (uint64_t)a_dword & 0xF0F0F0F0ULL;
		x = (xh << 28ULL) | xl;
		t = (x ^ (x >> 16ULL)) & 0x00000000FFFF0000ULL; x = x ^ t ^ (t << 16ULL);
		t = (x ^ (x >>  8ULL)) & 0x0000FF000000FF00ULL; x = x ^ t ^ (t <<  8ULL);
		state[0][i] = (uint8_t)(x) & 0x0F;
		state[1][i] = (uint8_t)(x >> (1 * 8ULL)) & 0x0F;
		state[2][i] = (uint8_t)(x >> (2 * 8ULL)) & 0x0F;
		state[3][i] = (uint8_t)(x >> (3 * 8ULL)) & 0x0F;
		state[4][i] = (uint8_t)(x >> (4 * 8ULL)) & 0x0F;
		state[5][i] = (uint8_t)(x >> (5 * 8ULL)) & 0x0F;
		state[6][i] = (uint8_t)(x >> (6 * 8ULL)) & 0x0F;
		state[7][i] = (uint8_t)(x >> (7 * 8ULL)) & 0x0F;
	}
 
    Permutation(state, ROUND);

	State_inout_pt = (uint32_t *)State_inout;
	for (i = 0; i < STATESIZE_INDWORDS; i++)
	{
		x = ((uint64_t)state[0][i]) |
		    (((uint64_t)state[1][i]) << (1 * 8ULL)) |
		    (((uint64_t)state[2][i]) << (2 * 8ULL)) |
		    (((uint64_t)state[3][i]) << (3 * 8ULL)) |
		    (((uint64_t)state[4][i]) << (4 * 8ULL)) |
		    (((uint64_t)state[5][i]) << (5 * 8ULL)) |
		    (((uint64_t)state[6][i]) << (6 * 8ULL)) |
		    (((uint64_t)state[7][i]) << (7 * 8ULL));
		t = (x ^ (x >>  8ULL)) & 0x0000FF000000FF00ULL; x = x ^ t ^ (t <<  8ULL);
		t = (x ^ (x >> 16ULL)) & 0x00000000FFFF0000ULL; x = x ^ t ^ (t << 16ULL);
		xl = x & 0x0F0F0F0FULL;
		xh = (x >> 28ULL) & 0xF0F0F0F0ULL;
		a_dword = (xh | xl);
		State_inout_pt[i] = a_dword;
	}
}