/* Generated by Coconut2D C++ Compiler from file CocoEngine.jspp */

#ifndef __COCOENGINE_HPP__
#define __COCOENGINE_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Coconut2D.hpp"
#include "ITickable.hpp"
#include "ICocoRenderContext.hpp"
#include "CocoClip.hpp"
#include "DeviceMessage.hpp"
#include "CocoScene.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CocoEngine
{
public:
	const float TICK_TIME = ((float)(1000.0) / (float)(60.0));
	State* __currentState;
	State* __nextState;
	Array<ITickable*>* __tickables;
	float __clock;
	ICocoRenderContext* __ctx;
	Array<DEVICE_MESSAGE*>* __deviceMessageQueue;
	Array<CocoClip*>* __clicked;
	bool __track_touch;
	bool __has_touch_device_message;
	const String __className = String("CocoEngine");
	CocoEngine();
	virtual ~CocoEngine();
	void setNextState(State* s);
	void run(float time);
	void __attachDevices();
	void __dettachDevices();
	void __translateDeviceMessage(HTMLEvent* e);
	bool __hasTouchDeviceMessage();
	void __removeTouchMessages();
	DEVICE_MESSAGE* __peekDeviceMessage(DEVICE_MESSAGE_ENUM mask);
	void __clearDeviceMessageQueue();
	void __pushClicked(CocoClip* clip);
	int isClicked(Array<CocoClip*>* check);
	void addTickListener(ITickable* tickable);
	void removeTickListener(ITickable* tickable);
	int getTickableIndex(ITickable* tickable);
	void __tick(float time);
	void __debug_trace(CocoScene* scene, CocoClip* clip, String message);
};

#endif // __COCOENGINE_HPP__