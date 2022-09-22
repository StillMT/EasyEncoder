#ifndef EASYENCODER_H
#define EASYENCODER_H

#define EASYENCODERLIB_VER "1.0.0"

class EasyEncoder
{
	private:
		byte pinA, pinB;
		bool lastState, beginned, invert;
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
	EasyEncoder::pinA = pinA;
	EasyEncoder::pinB = pinB;
	return true;
}

void EasyEncoder::invert(bool invertt)
{
	invert = invertt;
}

short EasyEncoder::check()
{
	if (!beginned)
		return -2;
	bool read = digitalRead(pinA);
	if (lastState && !read)
	{
		lastState = read;
		if (digitalRead(pinB))
			return invert ? 1 : -1;
		else
			return invert ? -1 : 1;
	}
	return 0;
}

#endif
