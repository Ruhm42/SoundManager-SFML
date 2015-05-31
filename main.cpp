#include <SFML/Audio.hpp>
#include "SoundEffect.hpp"
#include "SoundManager.hpp"

#include <unistd.h>

/* tests */

int main()
{
	try
	{
		SoundManager	test("sound_test/Ambiance.wav");

		/* use playSound to play brackground sounds (loop) */

		while (1)
		{
			usleep(500000);
			test.playEffect("sound_test/Tp.wav"); /* use playEffect to play short sounds */
			std::cout << test;
			usleep(500000);
			test.playEffect("sound_test/Tp.wav");
			std::cout << test;
			sleep(3);
			test.update();
			std::cout << test;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}