#include "Test.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
Test::Test()
{
	__sceneName = "Test";
	__fps = 30;
	__view_width = 480;
	__view_height = 320;
	__view_pixel_ratio = 1;
	CocoImage* Image_SpriteSymbol_metal_slug = newResourceImage("SpriteSymbol_metal_slug", "./assets/images/");
	{
		Image_SpriteSymbol_metal_slug->viewOptimalWidth = 0;
		Image_SpriteSymbol_metal_slug->viewOptimalHeight = 0;
		Image_SpriteSymbol_metal_slug->addSibling(new CocoImageSibling("metal_slug_mdpi.png", 1, 36, 42));
		Image_SpriteSymbol_metal_slug->addSibling(new CocoImageSibling("metal_slug_xhdpi.png", 2, 72, 84));
		Image_SpriteSymbol_metal_slug->textureCellWidth = 36;
		Image_SpriteSymbol_metal_slug->textureCellHeight = 42;
		Image_SpriteSymbol_metal_slug->textureGrid = new Float32Array({0, 0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8});
		Image_SpriteSymbol_metal_slug->addSequence(new CocoSequence("Walk", {0, 1, 2, 3, 4, 5, 6, 7, 8}));
	}
	CocoImage* Image_SpriteSymbol_Sparrow = newResourceImage("SpriteSymbol_Sparrow", "./assets/images/");
	{
		Image_SpriteSymbol_Sparrow->viewOptimalWidth = 48;
		Image_SpriteSymbol_Sparrow->viewOptimalHeight = 48;
		Image_SpriteSymbol_Sparrow->addSibling(new CocoImageSibling("Sparrow.png", 1, 48, 48));
		Image_SpriteSymbol_Sparrow->textureCellWidth = 48;
		Image_SpriteSymbol_Sparrow->textureCellHeight = 48;
		Image_SpriteSymbol_Sparrow->textureGrid = new Float32Array({0, 0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 2, 0, 2, 1, 2, 2, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 3, 5, 3, 6, 3, 7, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7, 5, 0, 5, 1, 5, 2, 5, 3, 5, 4, 5, 5, 5, 6, 5, 7, 6, 0, 6, 1, 6, 2, 6, 3});
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Fly", {22, 23, 24}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Fire", {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Die", {37, 38, 39, 40, 41, 42, 41, 42, 41, 42}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Eat", {0, 44, 44, 45, 45, 46, 46, 47, 47}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Burb", {0, 48, 48, 48, 49, 49, 49, 48, 48, 48, 49, 49, 49, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51, 50, 51}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Borred", {0, 1, 2, 1, 0}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Jump", {10, 11, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Walk", {3, 4, 5, 6, 7, 8, 9}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Fall", {14, 15}));
		Image_SpriteSymbol_Sparrow->addSequence(new CocoSequence("Happy", {16, 17, 18, 19, 20, 21}));
	}
	__root = new CocoClip();
	__root->__instanceName = "root";
	__root->__scene = this;
	__root->__timeline->clear();
	__root->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, "");
	{
		CocoClip* inst1 = new CocoClip(Image_SpriteSymbol_Sparrow);
		inst1->__instanceName = "Sparrow1";
		__root->addChild(inst1);
		inst1->__scene = this;
		inst1->__timeline->clear();
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -187.5,  -53.5, 1, 1, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, "Fly");
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 30, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0.5,  -54.5, 1, 1, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, "Walk");
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 65, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 211.5,  -41.5, 1, 1, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, "Borred");
		CocoClip* inst2 = new CocoClip(nullptr);
		inst2->__instanceName = "Text1";
		__root->addChild(inst2);
		inst2->__scene = this;
		inst2->createTextTexture("Balance", "Arial", 66, COCO_TEXT_ALIGN_ENUM::TEXT_ALIGN_NEAR, COCO_TEXT_ALIGN_ENUM::TEXT_ALIGN_NEAR, false, COCO_TEXT_TRIMMING_ENUM::StringTrimmingNone, "0", 300, 66);
		inst2->__timeline->clear();
		inst2->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true,  -74.5, 115.5, 1, 1, 0, 0, 0, 1, 1, 1, 1, nullptr, false, false, "");
	}
}