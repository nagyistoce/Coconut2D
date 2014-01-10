#include "SceneTitle.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
SceneTitle::SceneTitle()
{
	__sceneName = "SceneTitle";
	__fps = 30;
	__view_width = 480;
	__view_height = 320;
	__view_pixel_ratio = 1;
	CocoImage* Image_INTRO_PAPYRI = newResourceImage("INTRO_PAPYRI", "./assets/images/");
	{
		Image_INTRO_PAPYRI->viewOptimalWidth = 572;
		Image_INTRO_PAPYRI->viewOptimalHeight = 429;
		Image_INTRO_PAPYRI->addSibling(new CocoImageSibling("INTRO_PAPYRI_mdpi.png", 1, 1024, 768));
		Image_INTRO_PAPYRI->addSibling(new CocoImageSibling("INTRO_PAPYRI_xhdpi.png", 2, 2048, 1536));
		Image_INTRO_PAPYRI->textureCellWidth = 1024;
		Image_INTRO_PAPYRI->textureCellHeight = 768;
		Image_INTRO_PAPYRI->textureGrid = new Float32Array({0, 0});
	}
	CocoImage* Image_INTRO_SHIELD = newResourceImage("INTRO_SHIELD", "./assets/images/");
	{
		Image_INTRO_SHIELD->viewOptimalWidth = 521;
		Image_INTRO_SHIELD->viewOptimalHeight = 391;
		Image_INTRO_SHIELD->addSibling(new CocoImageSibling("INTRO_SHIELD_mdpi.png", 1, 1024, 768));
		Image_INTRO_SHIELD->addSibling(new CocoImageSibling("INTRO_SHIELD_xhdpi.png", 2, 2048, 1536));
		Image_INTRO_SHIELD->textureCellWidth = 1024;
		Image_INTRO_SHIELD->textureCellHeight = 768;
		Image_INTRO_SHIELD->textureGrid = new Float32Array({0, 0});
	}
	CocoImage* Image_title_screen = newResourceImage("title_screen", "./assets/images/");
	{
		Image_title_screen->viewOptimalWidth = 572;
		Image_title_screen->viewOptimalHeight = 429;
		Image_title_screen->addSibling(new CocoImageSibling("title_screen_mdpi.png", 1, 1024, 768));
		Image_title_screen->addSibling(new CocoImageSibling("title_screen_xhdpi.png", 2, 2048, 1536));
		Image_title_screen->textureCellWidth = 1024;
		Image_title_screen->textureCellHeight = 768;
		Image_title_screen->textureGrid = new Float32Array({0, 0});
	}
	CocoImage* Image_TITLE_SCREEN_LOGO = newResourceImage("TITLE_SCREEN_LOGO", "./assets/images/");
	{
		Image_TITLE_SCREEN_LOGO->viewOptimalWidth = 257;
		Image_TITLE_SCREEN_LOGO->viewOptimalHeight = 293;
		Image_TITLE_SCREEN_LOGO->addSibling(new CocoImageSibling("TITLE_SCREEN_LOGO_mdpi.png", 1, 561, 638));
		Image_TITLE_SCREEN_LOGO->addSibling(new CocoImageSibling("TITLE_SCREEN_LOGO_xhdpi.png", 2, 1122, 1276));
		Image_TITLE_SCREEN_LOGO->textureCellWidth = 561;
		Image_TITLE_SCREEN_LOGO->textureCellHeight = 638;
		Image_TITLE_SCREEN_LOGO->textureGrid = new Float32Array({0, 0});
	}
	__root = new CocoClip();
	__root->__instanceName = "root";
	__root->__timeline->clear();
	__root->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, nullptr, false, false);
	{
		CocoClip* inst1 = new CocoClip(nullptr, "");
		inst1->__instanceName = "inst1_INTRO_PAPYRI";
		__root->addChild(inst1);
		inst1->__timeline->clear();
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 1, nullptr, false, false);
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 88, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 1, nullptr, false, false);
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 95, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 0, nullptr, false, false);
		inst1->__timeline->addKeyFrameEx(nullptr, nullptr, 96, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, false, 0, 0, 0.558594, 0.558594, 0, 0, 0, 0, nullptr, false, false);
		{
			CocoClip* inst2 = new CocoClip(Image_INTRO_PAPYRI, "");
			inst2->__instanceName = ":: INTRO_PAPYRI";
			inst1->addChild(inst2);
			inst2->__timeline->clear();
			inst2->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, nullptr, false, false);
		}
		CocoClip* inst3 = new CocoClip(nullptr, "");
		inst3->__instanceName = "inst1_INTRO_SHIELD";
		__root->addChild(inst3);
		inst3->__timeline->clear();
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.008594, 0.008594, 0, 0, 0, 1, nullptr, false, false);
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 18, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.508594, 0.508594, 0, 0, 0, 0.7, nullptr, false, false);
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 24, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.408594, 0.408594, 0, 0, 0, 1, nullptr, false, false);
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 25, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.408594, 0.408594, 0, 0, 0, 1, nullptr, false, false);
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 88, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.408594, 0.408594, 0, 0, 0, 1, nullptr, false, false);
		inst3->__timeline->addKeyFrameEx(nullptr, nullptr, 89, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, false, 0, 0, 0.408594, 0.408594, 0, 0, 0, 1, nullptr, false, false);
		{
			CocoClip* inst4 = new CocoClip(Image_INTRO_SHIELD, "");
			inst4->__instanceName = ":: INTRO_SHIELD";
			inst3->addChild(inst4);
			inst4->__timeline->clear();
			inst4->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, nullptr, false, false);
		}
		CocoClip* inst5 = new CocoClip(nullptr, "");
		inst5->__instanceName = "inst1_title_screen";
		__root->addChild(inst5);
		inst5->__timeline->clear();
		inst5->__timeline->addKeyFrameEx(nullptr, nullptr, 88, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 0, nullptr, false, false);
		inst5->__timeline->addKeyFrameEx(nullptr, nullptr, 96, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 1, nullptr, false, false);
		inst5->__timeline->addKeyFrameEx(nullptr, nullptr, 214, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 1, nullptr, false, false);
		inst5->__timeline->addKeyFrameEx(nullptr, nullptr, 223, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 0.558594, 0.558594, 0, 0, 0, 0, nullptr, false, false);
		{
			CocoClip* inst6 = new CocoClip(Image_title_screen, "");
			inst6->__instanceName = ":: title_screen";
			inst5->addChild(inst6);
			inst6->__timeline->clear();
			inst6->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, nullptr, false, false);
		}
		CocoClip* inst7 = new CocoClip(nullptr, "");
		inst7->__instanceName = "inst1_TITLE_SCREEN_LOGO";
		__root->addChild(inst7);
		inst7->__timeline->clear();
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 5, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0,  -10, 0.458594, 0.458594, 0, 0, 0, 0, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 18, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0,  -10, 0.208594, 0.208594, 0, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 24, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_ECHO, false, true, 0,  -10, 0.308594, 0.308594, 0, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 88, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0,  -10, 0.308594, 0.308594, 0, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 96, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 0, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 106, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 116, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 125, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 135, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 145, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 155, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 164, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 174, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 183, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 193, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 202, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594,  -5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 212, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 5, 0, 0, 1, nullptr, false, false);
		inst7->__timeline->addKeyFrameEx(nullptr, nullptr, 223, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 168,  -79, 0.258594, 0.258594, 0, 0, 0, 0, nullptr, false, false);
		{
			CocoClip* inst8 = new CocoClip(Image_TITLE_SCREEN_LOGO, "");
			inst8->__instanceName = ":: TITLE_SCREEN_LOGO";
			inst7->addChild(inst8);
			inst8->__timeline->clear();
			inst8->__timeline->addKeyFrameEx(nullptr, nullptr, 0, COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN, false, true, 0, 0, 1, 1, 0, 0, 0, 1, nullptr, false, false);
		}
	}
}
