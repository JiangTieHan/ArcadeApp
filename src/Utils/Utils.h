#pragma once
static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool isEqual(float x, float y);

bool isGreaterThanOrEqual(float x, float y);

bool isLessThanOrEqual(float x, float y);

float MillisecondToSeconds(unsigned int milliseconds);