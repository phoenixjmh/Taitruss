#include "../headers/Audio.h"
Mix_Chunk* Audio::Sound_Move = nullptr;
Mix_Chunk * Audio::Sound_Clear = nullptr;
Mix_Chunk * Audio::Sound_GameOver = nullptr;
Mix_Chunk* Audio::Sound_Place = nullptr;
Mix_Chunk * Audio::Sound_Pause = nullptr;
Mix_Music * Audio::music = nullptr;
void Audio::CreateAudioMixer()
{
	int init = Mix_Init(0);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	music = Mix_LoadMUS("res/audio/Taitruss_Theme.wav");
	if (!music)
	{
		std::cout << "Music Error:" << Mix_GetError() << "\n";
		
	}

	Sound_Move = Mix_LoadWAV("res/audio/MoveBlock.wav");
	Sound_Clear = Mix_LoadWAV("res/audio/ClearRow.wav");
	Sound_GameOver = Mix_LoadWAV("res/audio/GameOver.wav");
	Sound_Place = Mix_LoadWAV("res/audio/PlaceBlock.wav");
	Sound_Pause = Mix_LoadWAV("res/audio/PauseGame.wav");

}
void Audio::PlayMusic()
{
	Mix_PlayMusic(music, -1);
}
void Audio::Pause()
{
	Mix_PauseMusic();
}
void Audio::Resume()
{
	Mix_ResumeMusic();
}
void Audio::PlaySound(SOUNDS sound)
{
	switch(sound)
	{
	case SOUNDS::MOVE:
		Mix_PlayChannel(-1, Sound_Move, 0);
		break;
	case SOUNDS::CLEAR:
		Mix_PlayChannel(-1, Sound_Clear, 0);
		break;
	case SOUNDS::GAMEOVER:
		Mix_PlayChannel(-1, Sound_GameOver, 0);
		break;
	case SOUNDS::PLACE:
		Mix_PlayChannel(-1, Sound_Place, 0);
		break;
	case SOUNDS::PAUSE:
		Mix_PlayChannel(-1, Sound_Pause, 0);
	default:
		break;
		
	
	}
}
