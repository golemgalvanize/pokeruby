Route125_MapObjects:: @ 8384E28
	object_event 1, MAP_OBJ_GFX_SWIMMER_M, 0, 46, 0, 9, 0, 1, 23, 0, 0, 1, 0, 2, 0, Route125_EventScript_151F2E, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_SWIMMER_M, 0, 9, 0, 32, 0, 1, 10, 82, 0, 1, 0, 2, 0, Route125_EventScript_151F45, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_SWIMMER_F, 0, 31, 0, 33, 0, 1, 28, 6, 0, 1, 0, 3, 0, Route125_EventScript_151F5C, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_SWIMMER_F, 0, 39, 0, 20, 0, 1, 52, 153, 0, 1, 0, 3, 0, Route125_EventScript_151F73, 0, 0, 0
	object_event 5, MAP_OBJ_GFX_SAILOR, 0, 23, 0, 28, 0, 3, 14, 0, 0, 1, 0, 2, 0, Route125_EventScript_151F8A, 0, 0, 0
	object_event 6, MAP_OBJ_GFX_LASS, 0, 20, 0, 21, 0, 3, 8, 17, 0, 1, 0, 0, 0, Route125_EventScript_151FC8, 0, 0, 0
	object_event 7, MAP_OBJ_GFX_LASS, 0, 21, 0, 21, 0, 3, 8, 17, 0, 1, 0, 0, 0, Route125_EventScript_151FE3, 0, 0, 0

Route125_MapWarps:: @ 8384ED0
	warp_def 22, 19, 0, 0, MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM

Route125_MapBGEvents:: @ 8384ED8
	bg_secret_base_event 53, 10, 0, SECRET_BASE_RED_CAVE1_2
	bg_secret_base_event 55, 11, 0, SECRET_BASE_RED_CAVE4_2
	bg_secret_base_event 7, 25, 0, SECRET_BASE_YELLOW_CAVE2_2
	bg_secret_base_event 24, 32, 0, SECRET_BASE_YELLOW_CAVE4_2

Route125_MapEvents:: @ 8384F08
	map_events Route125_MapObjects, Route125_MapWarps, 0x0, Route125_MapBGEvents
