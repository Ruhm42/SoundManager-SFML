#ifndef SOUNDMANAGER_HPP
# define SOUNDMANAGER_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <queue>

# include "SoundEffect.hpp"

# include <SFML/Audio.hpp>

	constexpr int maxSounds = 100;

	class SoundManager
	{
		public:

			SoundManager(void);
			SoundManager(std::string name);
			SoundManager(SoundManager const &src);
			~SoundManager(void);
		
			SoundManager	&operator=(SoundManager const &rhs);
			std::string		toString(void) const;
			void			playSound(std::string name);
			void			playEffect(std::string name);
			void			update(void);

			static SoundManager									*instance;
		
		private:
			std::priority_queue<std::shared_ptr<SoundEffect> >	_sounds;
			sf::Music											_music;
			std::string											_musicName;
	};

	std::ostream	&operator<<(std::ostream &o, SoundManager const &rhs);

#endif