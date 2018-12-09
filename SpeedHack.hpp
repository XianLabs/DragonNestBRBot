#include "windows.h"

void SetSpeed(float Acceleration);
void SpeedHack(bool Enabled);
void PlantDetourJMP(BYTE* source, const BYTE* destination, const int length);