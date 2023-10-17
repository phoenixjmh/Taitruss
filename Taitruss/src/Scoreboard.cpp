#include "../headers/Scoreboard.h"

void Scoreboard::Reset() {
  score = 0;
  level = 1;
  TOTAL_CLEARED_ROWS = 0;
  this->GetLevelNumberTexture();
  this->GetTextures();
  blinkTimes = 4;
}
void Scoreboard::CheckLevel() {
  int currentScore = TOTAL_CLEARED_ROWS;
  if (currentScore < 10) {
    level = 1;
  }

  else if (currentScore >= 10 && currentScore < 20) {
    level = 2;
  } else if (currentScore >= 20 && currentScore < 30) {
    level = 3;
  } else if (currentScore >= 30) {
    level = 4;
  }
}
void Scoreboard::Update() {
  if (isBlinking) {
    level = 1;
    TOTAL_CLEARED_ROWS = 0;

    int presentTime = SDL_GetTicks();
    int timeSinceLastBlink = presentTime - blinkStartTime;
    if ((timeSinceLastBlink) >= 500 && blinkTimes > 0) {
      blink = !blink;
      std::cout << "BLINK\n";
      blinkStartTime = presentTime;
      blinkTimes--;
    }

    else if (blinkTimes == 0) {
      blink = false;
      Reset();
      isBlinking = false;
    }
  }
}
void Scoreboard::GetLevelNumberTexture() {
  switch (level) {
    case 1:
      currentLevelNumber = one;
      break;
    case 2:
      currentLevelNumber = two;
      break;
    case 3:
      currentLevelNumber = three;
      break;
    case 4:
      currentLevelNumber = four;
      break;

    default:
      break;
  }
}

/// Gets the number on screen, and selects the textures in order, to render the
/// digits \brief
void Scoreboard::GetTextures() {
  if (texturesToRender.size() > 0) {
    texturesToRender.clear();
  }
  std::vector<int> digits;
  std::vector<int> levelNum;

  int idx = score;

  if (idx != 0) {
    while (idx > 0) {
      int digit = idx % 10;
      digits.insert(digits.begin(), digit);
      idx /= 10;
    }
  } else {
    digits.insert(digits.begin(), 0);
  }

  for (auto& d : digits) {
    switch (d) {
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

void Scoreboard::Draw() {
  int border_box_size = 100;
  src.w = bannerXRes;
  src.h = bannerYRes;
  this->dest.w = 50;
  this->dest.x = winWidth - border_box_size - 80;
  this->dest.y = winHeight - border_box_size + 10;
  this->dest.h = 30;
  TextureManager::Draw(banner, src, dest);
  src.x = 0;
  src.y = 0;
  src.w = 128;
  src.h = 256;
  this->dest.w = 12;
  this->dest.h = 20;
  this->dest.x = winWidth - border_box_size - 10;
  dest.y = winHeight - border_box_size + 15;
  for (auto& t : this->texturesToRender) {
    if (!blink) {
      TextureManager::Draw(t, src, dest);
      this->dest.x += 10;
    }
  }

  this->dest.x = winWidth - border_box_size - 100;
  this->dest.y = winHeight - border_box_size;
  this->dest.w = winWidth - dest.x;
  this->dest.h = border_box_size - 55;
  TextureManager::Draw(blankSquare, src, this->dest);
  src.w = bannerXRes;
  src.h = bannerYRes;
  this->dest.w = 50;
  this->dest.x = winWidth - border_box_size - 80;
  this->dest.y = winHeight - border_box_size + 60;
  this->dest.h = 30;
  TextureManager::Draw(levelBanner, src, dest);
  src.x = 0;
  src.y = 0;
  src.w = 128;
  src.h = 256;
  this->dest.w = 12;
  this->dest.h = 20;
  this->dest.x = winWidth - border_box_size - 10;
  dest.y = winHeight - border_box_size + 65;
  TextureManager::Draw(currentLevelNumber, src, dest);
}
void Scoreboard::AddPoints(int cleared) {
  TOTAL_CLEARED_ROWS += cleared;
  switch (cleared) {
    case 1:
      score += 40;
      break;
    case 2:
      score += 100;
      break;
    case 3:
      score += 300;
      break;
    case 4:
      score += 1200;
      break;
    default:
      break;
  }
  this->GetTextures();
  this->GetLevelNumberTexture();
}