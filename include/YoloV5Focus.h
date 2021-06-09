#pragma once
#include "layer.h"

class YoloV5Focus : public ncnn::Layer
{
public:
	YoloV5Focus()
	{
	}

	virtual int forward(const ncnn::Mat&, ncnn::Mat&, const ncnn::Option&) const
	{
	}
};

DEFINE_LAYER_CREATOR(YoloV5Focus)