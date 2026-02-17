/**
  ******************************************************************************
  * @file    commands_model_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-02-16T20:45:42+0100
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "commands_model_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_commands_model_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_commands_model_weights_array_u64[298] = {
  0xbecce642bee3d2f7U, 0xbf1d01afbe2852eeU, 0x3eb4a95e3d805692U, 0x3e81e625beb11c81U,
  0x3e5e5eb73e5a97bdU, 0x3efa416cbe4bd869U, 0xbe07e7353e845a97U, 0xbdaafa4dbd481061U,
  0xbf133adb3e654ac1U, 0x3dd50a19bdc3aaa3U, 0x3ecc47e23eb88aa0U, 0x3df04064beb9aef0U,
  0x3e58a8ed3ec0dfffU, 0x3f01770e3e0360edU, 0x3c1d1c19bcf1a001U, 0x3ea3956b3e580f71U,
  0xbe5984293de8b3d3U, 0xbe0068a6be08aa12U, 0x3eb98a7dbe4e612fU, 0xbe957d703e90754cU,
  0x3e8270b13e88edb4U, 0xbe59fb933967e9dcU, 0x3e0dfdd13d091019U, 0xbc403ae4bd9af862U,
  0x3ee9760bba162478U, 0x3d40c736bed7f05dU, 0xbdae40883dd27c70U, 0xbe5926f43f3c9e1eU,
  0x3e9e201d3e371945U, 0xbd4601763f4e35ddU, 0x3f4e138bbd943cd3U, 0x3e2374e43d1f8e39U,
  0x3dd4df7a3ea9a217U, 0x3f18faec3f567679U, 0x3f28b0c9bdd0379aU, 0xbe673e7ebe6f0788U,
  0xbf22abd3bdc3f82cU, 0xbd430eabbf22ad09U, 0x3d7ae04fbe9c541dU, 0xbf3bf194befd84c6U,
  0x3ec1c9fa3e0f6146U, 0x3eb7fe02bf4544beU, 0x3e09aeed3e05a588U, 0xbee8d06fbe75aaacU,
  0xbe8663273f309f95U, 0xbf345ec3be8e73a6U, 0xbe671dbebc9814daU, 0x3e449f42bf0ab8f6U,
  0xbeab1d303eb9419bU, 0xbe877b823ef1f9c2U, 0x3def9cffbe387f34U, 0xbd809db4beeb776fU,
  0x3ea5970d3e8ba241U, 0x3d8a30debc9b1752U, 0x3d3428c03d237700U, 0x3c4af689bea33e0eU,
  0x3e2966b63ec2e72aU, 0x3f2d47ae3d3e519aU, 0x3e712c38be630578U, 0x3e6dcfca3d8ac539U,
  0xbeedcad13e9d3940U, 0xbe67892a3e3464b1U, 0xbd0f066b3f24863aU, 0x3f25bfd4bc8a8c90U,
  0xbd0198f93d31057dU, 0x3ba1c4d03e2a6943U, 0x3d10a6ab3d02cc13U, 0x3e9e28f23e81c689U,
  0xbdf3237bbe8bd11dU, 0xbe6596303d272ad8U, 0x3c89058cbe988aafU, 0x3eebab77be18b2baU,
  0x3f19e59b3eb31d6eU, 0xbeb440fdbc568666U, 0x3ec433ffbea5fb1aU, 0xbf11997dbd517802U,
  0xbe281a963ece2439U, 0xbe5b2e3d3ef79f7dU, 0xbe6656423f049e55U, 0x3e969038bee3b945U,
  0xbddadb0cbe7350f5U, 0x3ed60986be751832U, 0xbc76a2e4beac7c77U, 0xbdfff492be5202bfU,
  0x3e731a11bd2b2708U, 0x3d31e6103e8c731fU, 0xbe5cbff03d4654eeU, 0x3e8d5cdb3df73dd4U,
  0x3e807f73be84e53fU, 0x3ce89b0b3f2b4137U, 0x39efe9dcbe206830U, 0x3e3f3d853e191032U,
  0xbd0be79bbdb95721U, 0xbe4e3a8dbd9fbe14U, 0x3dafc8673ee64fbeU, 0xbe29eadbbe4cb8b1U,
  0xbc6ff33d3cdb9e36U, 0xbeab6b913dd71932U, 0x3e7481b1be278967U, 0xbdfac7d0be1afe31U,
  0xbdbf0eacbe2a1194U, 0x3e85c5ba3ecd6e69U, 0x3e1956743ea020dbU, 0x3b301f41be9f1684U,
  0x3efb00263c367060U, 0xbc3f591d3f07c87dU, 0xbd1fe95abe36361cU, 0xbddfeca93aa695beU,
  0x3da3dbbabe4afaedU, 0xbce2ab183d82cc90U, 0x3f14e08fbe2e66e2U, 0x3dcbe18c3eaea471U,
  0x3e55dc9ebdae6ebeU, 0x3e0b2770bcab19aeU, 0x3d6e4e39bc4b543dU, 0x3db1da2cbe32475aU,
  0xbea757503e0ed823U, 0xbd7fcbf8bdef7430U, 0xbcbebf40be4cf513U, 0x3e0fc47abdf1ba4aU,
  0x3e26b3c63e630344U, 0xbcd0c810be1a46a2U, 0xbe8a38bf3ecce22eU, 0xbeadea38bd8b76ccU,
  0xbe9ad735bda80042U, 0x3ebbcdd1bd7bf931U, 0x3e1f4396be50f0dfU, 0x3f41014abce1243dU,
  0x3e2d161abe90803aU, 0x3ec3a6063eccd0d6U, 0xbeb084b0be5b2550U, 0x3e6df8bd3ef85a4eU,
  0xbc9fe9b13e66860dU, 0x3ea219df3e88e26dU, 0xbe8f6b1fbc3f4d0cU, 0x3f12ac79be64e47fU,
  0x3efda4c73ee03d18U, 0xbe28aac6bd86910cU, 0xbf352015bf12f501U, 0x3edd15b73f1c2f25U,
  0x3ee9ad603ee105aaU, 0x3dd584673e66e39eU, 0x3f5c0609be61a04dU, 0xbe96f4953e9c7064U,
  0x3e674ac4bf13323fU, 0xbba60cb43e696631U, 0x3e2aef183ee661d5U, 0x3cd584303eb3ebd0U,
  0x3ce4ee353ea6edbeU, 0x3f017a883eb0e14aU, 0x3d3fe0c23ec497cfU, 0xbd99b570bd8db2d5U,
  0x3df1ed2b3e77ecefU, 0xbd6e3fb03ee28304U, 0xbed579e4be4126f4U, 0x3f0dc9cbbf1f2393U,
  0x3f4d85873ed2a92aU, 0x3e019aa8be14af68U, 0x3e75b7043ee6328bU, 0x3e6ffdf33f1ecae7U,
  0xbea7d76fbeb2a7c5U, 0x3f036c8d3e5200bdU, 0x3e43025bbe27e71aU, 0x3e43e42a3e03e9f1U,
  0x3e06d3e3be69ee9cU, 0x3f2161543e8fff5eU, 0xbe5ed7853e2381a7U, 0x3e8b66a83ecde24fU,
  0xbe4f0e63bdcb5f1cU, 0xbeb1ff2bbe15d97bU, 0xbe94914e3e78fd1eU, 0xbeb27dafbbd0b41fU,
  0x3e3bcc6ebd863381U, 0x3f336ef6bf122ec2U, 0x3ec2fa7a3d872b8aU, 0xbe58cd663cec02f0U,
  0xbd3a680fbddfad0aU, 0xbed5dfec3cd0c6fcU, 0x3eb506843f062cacU, 0xbe845906be15f853U,
  0x3e381bb23ea04e2dU, 0xbe9b69c03d52d10eU, 0xbdb2d52a3d543becU, 0x3f171c71bd73b69aU,
  0xbeade5b13e044a6bU, 0xbefab58bbef9d65cU, 0xbe2983d13d949a38U, 0x3f5701af3e48cd34U,
  0x3e3dacd53f800b96U, 0xbe9cd44fbec35861U, 0x3d6873013ebd7eceU, 0x3ea5ed06be08e2a1U,
  0x3ed00253bf00b093U, 0x3f52b12e3f4eacd4U, 0xbf1806eebe9621cfU, 0xbeada3b33e228fa2U,
  0xbe2fed46be47421aU, 0x3d988bee3eeed017U, 0xbd82c868be2986f5U, 0xbe2d44213d499f1cU,
  0x3d7d253c3efb4b18U, 0x3dfa7b0c3ddb0e64U, 0x3db316d8be8f59f6U, 0xbd7a87383e95863bU,
  0x3ea69e5abdff6efcU, 0xbe1562efbea4d9deU, 0xbe3d5f61be702844U, 0xbd9c77e4be639720U,
  0xbe299a06bcfd1ae9U, 0x3f136de13dff19faU, 0x3da18e573ed4eb8fU, 0x3da6ce163c986554U,
  0x3cf95afcbeb2ce64U, 0x3d4fecf5bd9c24e0U, 0xbe0c4c92be9680b1U, 0xbd38c567be8d27f5U,
  0xbe44708cbe10d850U, 0x3e09f5e6bdfed8f6U, 0xbe5c43573f224651U, 0xbe9ae8573c2d64ceU,
  0xbc3a0b58bbd79680U, 0xbb3ede8dbdbc5570U, 0x3dc2922abe2b015eU, 0xbe81db07bdcb74adU,
  0xbeaff3623eb463b1U, 0xbe22de553ec2cceaU, 0xbe92c44dbe58f954U, 0x3e12edbb3f0ac57aU,
  0x3ea583ec3e19b9d9U, 0x3eb1be363d6bcee4U, 0x3e3c53e8bca1b760U, 0x3ef032463ece2d6fU,
  0x3f001f38bd4c4490U, 0x3f16ade43dad9a54U, 0xbdc13b5c3dce2070U, 0x3e369b01be8fd7d2U,
  0x3ea698d6be98f5d6U, 0x3f2ceba13efcca1fU, 0xbda2af78bbd4299eU, 0x3ed70e14bef296b6U,
  0x3e3ed6f4bdb619b3U, 0xbeeb5a8c3e40419fU, 0x3e78abb43f1b74f5U, 0xbe86fcf43ecd74bcU,
  0x3e5c3bf73e17396aU, 0x3dbdfb69be9068acU, 0x3e8b83ae3e3df3b3U, 0xbdb11af63cd49fedU,
  0xbd010a52bdc00fafU, 0xbe856154be5b2113U, 0xbc7ec040beacab5fU, 0x3e6f5ad4be84db03U,
  0xbe21a2ecbe834fd6U, 0xbe2e2f633e9715c6U, 0x3cc56fff3ca776e2U, 0x3f1fdf153e0d6043U,
  0xbe03c2c0be5d35b5U, 0xbe174fd13e1c8e14U, 0xbe810478be3a991eU, 0x3f0165c1be784cb8U,
  0x3e0ed44a3ee45b7dU, 0xbe9d9ba23edc65e4U, 0x3e908d3c3e2952daU, 0xbe5cf0c8bd4cb595U,
  0x3e596c813ee3ce0bU, 0x3e83476a3efde30eU, 0x3c7653b43e730df2U, 0xbdb293a03ce2929cU,
  0x3ee33b263f132742U, 0x3e9ba1c93e592c21U, 0x3e0bf62e3e2a19b2U, 0x3d7e057f3e936731U,
  0xbf97f376bf878090U, 0xbf7310a93f64f180U, 0xbf3610fabecc5e7dU, 0xbf2c8deebe8e6ceeU,
  0x3e1b035c3f05cc29U, 0xbe1a40313f24d03cU, 0xbec1836bbf2e6bc9U, 0xbefc999dbcc566e6U,
  0x3f163ae63e8de4ceU, 0x3f60d01dbf87a8b5U, 0xbf1f3450bf890b9dU, 0xbc97be36bf106c75U,
  0x3ed948943f19e917U, 0xbf0e22c9bfa349ceU, 0x3ee1ac35bf5ce268U, 0x3f598713bfa94460U,
  0x3d24da963f2c6b40U, 0xbdf2c975bf6aa890U, 0x3f3d37333f0eb19aU, 0x3e4a604e3f492d3dU,
  0xbf8927ebbf0f2b6eU, 0x3f103af9be253bceU, 0xbf2e9ddd3c95af60U, 0x3ef122ff3ef0b971U,
  0x3dd9c9533db6c25bU, 0xbe666367U,
};


ai_handle g_commands_model_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_commands_model_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

