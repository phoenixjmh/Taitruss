#pragma once
#include <SDL_mixer.h>

#include <iostream>
class Audio {
 public:
  enum class SOUNDS { MOVE, CLEAR, GAMEOVER, PLACE, PAUSE };
  static Mix_Music* music;
  static Mix_Chunk* Sound_Move;
  static Mix_Chunk* Sound_Clear;
  static Mix_Chunk* Sound_GameOver;
  static Mix_Chunk* Sound_Place;
  static Mix_Chunk* Sound_Pause;
  void CreateAudioMixer();
  static void PlayMusic();
  static void Pause();
  static void Resume();
  static void PlaySound(SOUNDS);

  Audio() { CreateAudioMixer(); }
};
