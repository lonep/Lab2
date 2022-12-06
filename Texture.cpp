﻿#include "Texture.h"

Uint32 Uint32FromRgba(SDL_Color color)
{
	return color.a + (color.b << 8) + (color.g << 16) + (color.r << 24);
}

Texture::Texture(SDL_Renderer* renderer, SDL_Point size):
	_renderer(renderer),
	_size(size),
	_pixels(_size.x * _size.y)
{
	_sdlTexture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET,
		size.x,
		size.y);
	
	for (Uint32& pixel : _pixels)
		pixel = 0xaa555500;
	UpdateTexture();
}

Texture::~Texture()
{
    SDL_DestroyTexture(_sdlTexture);
}

void Texture::Render()
{
	SDL_RenderCopy(_renderer, _sdlTexture, nullptr, nullptr);
}

void Texture::SetPixel(SDL_Point pixel, SDL_Color color)
{
	_pixels.at(pixel.x + pixel.y * _size.x) = Uint32FromRgba(color);
}

void Texture::UpdateTexture()
{
	SDL_UpdateTexture(_sdlTexture,
		nullptr,
		_pixels.data(),
		_size.x * sizeof(_pixels[0]));
}
