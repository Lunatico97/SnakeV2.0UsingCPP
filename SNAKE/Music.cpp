
#include "Music.hpp"

Mix_Chunk *Music::loadMusic(const char *filename)
{
	Mix_Init(MIX_INIT_MP3) ;
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT ,2, 7600) ;
	Mix_Chunk *chunk = Mix_LoadWAV(filename) ;
	bool playing ;
	if(chunk == nullptr)
	{
		std::cout << "\nMusic Loader Diagnosis -> " << std::endl ;
		std::cout << "Error loading the audio : " << filename << std::endl << "{Troubleshoot : " << Mix_GetError() << "}\n" << std::endl ; 
	}
	else
	{
		std::cout << "Audio Channel Initialized ..." << std::endl ;
	}
	
	return chunk ;
}

void Music::playMusic(Mix_Chunk *chunk, int volume)
{
	if(!Launcher::switchedOn)
	{
		Mix_FreeChunk(chunk) ;
		Mix_Quit() ;
	}
	else
	{
		Mix_VolumeChunk(chunk, volume) ;
		Mix_PlayChannel(-1, chunk, 0) ;
	}
}
