// Copyright -> Scott Bishel

#pragma once

#include "MetaEvent.h"

/**
 * 
 */
class MIDI_API Tempo : public MetaEvent
{
	int mMPQN;
	float mBPM;

public:
	static const float DEFAULT_BPM; // 120.0f
	static const int DEFAULT_MPQN; // 60000000 / DEFAULT_BPM

	Tempo();
	Tempo(long tick, long delta, int mpqn);

	int getMpqn();
	float getBpm();

	void setMpqn(int m);
	void setBpm(float b);

protected:
	int getEventSize();

public:
	void writeToFile(FMemoryWriter & output);

	static Tempo * parseTempo(long tick, long delta, FBufferReader & input);
	int CompareTo(MidiEvent *other);
};
