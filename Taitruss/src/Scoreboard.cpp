#include "../headers/Scoreboard.h"

///Gets the number on screen, and selects the textures in order, to render the digits \brief 
void Scoreboard::GetTextures()
{
	if (texturesToRender.size() > 0)
	{
		texturesToRender.clear();
		std::cout << "GOT HERE\n";
	}
	std::vector<int> digits;


	int idx = score;
	while (idx > 0)
	{
		int digit = idx % 10;
		digits.insert(digits.begin(), digit);
		idx /= 10;
	}

	for (auto& d : digits)
	{

		switch (d)
		{
		case 0:
			texturesToRender.push_back(zero);
			break;
		case 1:
			texturesToRender.push_back(one);
			break;
		case 2:
			texturesToRender.push_back(two);
			break;
		case 3:
			texturesToRender.push_back(three);
			break;
		case 4:
			texturesToRender.push_back(four);
			break;
		case 5:
			texturesToRender.push_back(five);
			break;
		case 6:
			texturesToRender.push_back(six);
			break;
		case 7:
			texturesToRender.push_back(seven);
			break;
		case 8:
			texturesToRender.push_back(eight);
			break;
		case 9:
			texturesToRender.push_back(nine);

			break;
		default:
			break;
		}

	}
}

void Scoreboard::Draw()
{
	
	int border_box_size = 100;



	this->dest.x = winWidth-border_box_size;
	this->dest.y = winHeight-border_box_size;
	this->dest.w = border_box_size;
	this->dest.h = border_box_size;
	TextureManager::Draw(blankSquare, src, this->dest);
	src.w = bannerXRes;
	src.h = bannerYRes;
	this->dest.w = 75;
	this->dest.y  +=10;
	this->dest.h = 40;
	TextureManager::Draw(banner, src, dest);
	this->dest.w = 50;
	this->dest.y += 50;
	/*if(this->texturesToRender.size()>0)*/
	for(auto& t:this->texturesToRender)
	{
		TextureManager::Draw(t, src, dest);
		this->dest.x += 50;
	}
	this->dest.x = 0;


}
void Scoreboard::AddPoint()
{
	score++;
	this->GetTextures();

}