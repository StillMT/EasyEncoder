/*
 *
 *	Library created by StillMT
 *
*/

#ifndef EASYENCODER_H
#define EASYENCODER_H

#define EASYENCODERLIB_VER "1.0.1"

class EasyEncoder
{
	private:
		byte pinA, pinB;
		bool lastState, beginned, inverted;
	public:
		EasyEncoder();
		bool begin(byte pinA, byte pinB);
		void invert(bool invert);
		short check();
};

EasyEncoder::EasyEncoder()
{
	lastState = HIGH; //You have to set pins on INPUT_PULLUP
	beginned = false;
}

bool EasyEncoder::begin(byte pinA, byte pinB)
{
	if (!digitalRead(pinA) || !digitalRead(pinB))
		return false;
	beginned = true;
	inverted = false;
	EasyEncoder::pinA = pinA;
	EasyEncoder::pinB = pinB;
	return true;
}

void EasyEncoder::invert(bool invert)
{
	inverted = invert;
}

short EasyEncoder::check()
{
	if (!beginned)
		return -2;
	bool read = digitalRead(pinA);
	if (lastState && !read)
		if (digitalRead(pinB))
			return inverted ? -1 : 1;
		else
			return inverted ? 1 : -1;
	lastState = read;
	return 0;
}

#endif