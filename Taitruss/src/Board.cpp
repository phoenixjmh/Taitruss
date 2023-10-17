#include "../headers/Board.h"

#include <algorithm>
#include <iostream>
#include <set>

#include "../headers/Engine.h"

void Board::AddPiece(ALL_PIECES type) {
  hard_drop = false;
  tempGameSpeed = Game::frame_delay;
  dropPiece = false;
  if (type == SQUARE) {
    m_currentType = type;

    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0 || s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) - 1 || s.xLocation == (WIDTH / 2)) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }
  if (type == LONG) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2) - 2 || s.xLocation == (WIDTH / 2) - 1 ||
            s.xLocation == WIDTH / 2 || s.xLocation == (WIDTH / 2) + 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }

  if (type == R_PIECE) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2) - 1) {  // top left
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2)) {
          s.isCenter = true;
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) - 1 ||  // mid left
            s.xLocation == WIDTH / 2 ||        // mid
            s.xLocation == (WIDTH / 2) + 1) {  // mid right
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }
  if (type == L_PIECE) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2) + 1) {  // top right
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2)) {
          s.isCenter = true;
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) - 1 || s.xLocation == WIDTH / 2 ||
            s.xLocation == (WIDTH / 2) + 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }
  if (type == S_PIECE) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2) || s.xLocation == (WIDTH / 2) + 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2)) {
          s.isCenter = true;
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) - 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }
  if (type == Z_PIECE) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2) || s.xLocation == (WIDTH / 2) - 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2)) {
          s.isCenter = true;
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) + 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }

  if (type == T_PIECE) {
    m_currentType = type;
    for (auto& s : m_squareObjects) {
      if (s.yLocation == 0) {
        if (s.xLocation == (WIDTH / 2)) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2)) {
          s.isCenter = true;
        }
      }
      if (s.yLocation == 1) {
        if (s.xLocation == (WIDTH / 2) - 1 || s.xLocation == WIDTH / 2 ||
            s.xLocation == (WIDTH / 2) + 1) {
          s.type = type;
          s.isOccupied = true;
          s.facing = "N";
        }
      }
    }
  }

  UpdateVectors();
	if (type != BLANK && m_occupiedSquares.size() > 0 && m_squareObjects.size() > 0)
        m_currentPiece = std::make_unique<Piece>(type, "N", m_occupiedSquares, m_squareObjects, WIDTH, HEIGHT);
	else {
		std::cout << "ERROR::Failed to create 'Piece' in Board::AddPiece function::ERROR\n";
		std::cout << "TYPE: " << type << " OCCUPIED SQUARES SIZE: " << m_occupiedSquares.size() << " ALLSQUARES SIZE: " << m_squareObjects.size() << "\n";
    std::cout << "ERROR::Failed to create 'Piece' in Board::AddPiece "
                 "function::ERROR\n";
  }
}

void Board::RotatePiece() {
  // Clockwise Turn
  if (m_currentPiece != nullptr && !busyMoving) {
    if (m_currentPiece->CanRotate(m_currentType, m_currentFacing,
                                  m_occupiedSquares, m_squareObjects, WIDTH,
                                  HEIGHT)) {
      busyMoving = true;

      if (m_currentType == LONG) {
        PauseUpdate();
        m_currentPiece->RotateLong(m_occupiedSquares, m_squareObjects);
        ResumeUpdate();
      } else if (m_currentType != LONG) {
        PauseUpdate();
        m_currentPiece->Rotate();
        m_currentPiece->RefreshPiece();
        ResumeUpdate();
      }

    } else
      std::cout << "CANNOT ROTATE\n";
  }
}

/// <summary>
/// Assign tiles to row, then loop through and check if all in row are placed.
///	If full row is placed, clear it, passing in the yposition, for dropping
/// the 	pieces above it, and the amount of rows to clear to the
/// MovePlacedDown function
/// </summary>
void Board::CheckClearRow() {
  std::vector<std::vector<Tile*>> rows;
  for (int r = 0; r < HEIGHT; r++) {
    std::vector<Tile*> row;
    for (int c = 0; c < WIDTH; c++) {
      int index = r * WIDTH + c;
      if (index < m_squareObjects.size()) {
        row.push_back(&m_squareObjects[index]);
      }
    }
    rows.push_back(row);
  }

  std::vector<std::vector<Tile*>> rowsToClear;
  for (auto& row : rows) {
    int occupiedInRow = 0;
		for (const auto& column : row) {
      if (column->isPlaced) {
        occupiedInRow++;
      }
      if (occupiedInRow == WIDTH) {
				auto it = std::find(rowsToClear.begin(), rowsToClear.end(), row);
        if (it == rowsToClear.end()) {
          rowsToClear.push_back(row);
        }
      }
    }
  }
  if (rowsToClear.size() <= 0) {
    return;
  }
  const int times_to_move = rowsToClear.size();
  for (auto& r : rowsToClear) {  // extract height from this row, update that
                                 // way
    int clear_index = r[0]->yLocation;
    ClearRow(r);  // Clear index needs to be updated after clearing one row..
    Audio::PlaySound(Audio::SOUNDS::CLEAR);
    MovePlacedDown(clear_index, times_to_move);
  }
  Game::engine->OnClearRow(rowsToClear.size());
}

void Board::ClearRow(const std::vector<Tile*>& row_to_clear) {
  int clearDelay = 20;
  int start = SDL_GetTicks();
  for (int i = 0; i < row_to_clear.size();) {
    // row_to_clear[i]->isPlaced = false;
    row_to_clear[i]->type = BLANK;
    row_to_clear[i]->facing = "NA";
    int current = SDL_GetTicks();
    if (current - start > clearDelay) {
      i++;
      start = current;
    }
    Game::engine->render();
  }
  UpdateVectors();
}
void Board::MovePlacedDown(int index, int times_to_move) {
  PauseUpdate();

  for (int i = m_squareObjects.size() - 1; i - WIDTH > 0; --i) {
    if (m_squareObjects[i].yLocation <= index) {
      m_squareObjects[i] = m_squareObjects[i - (WIDTH)];
    }
  }
  ResumeUpdate();
  UpdateVectors();
}


void Board::ClearSquares()
{
	for (auto& s : m_occupiedSquares) {
		if (s->isPlaced == false)
			s->isOccupied = false;

  }
}
void Board::ClearPlaced(int index) {
  int cnt = 0;
  for (auto& os : placedSquares) {
    cnt++;
    if (os->isPlaced && os->yLocation < index) {
      os->isPlaced = false;
    }
  }
  ResumeUpdate();
}

bool Board::CanMove(std::string dir) {
  if (busyMoving) return false;

  if (dir == "Right") {
    for (auto& s : m_occupiedSquares) {
      if (s->xLocation + 1 == WIDTH && !s->isPlaced) {
        return false;
      }
    }
    for (const auto& i : m_squareObjects) {
      for (const auto& square_object : m_squareObjects) {
        if (i.isOccupied) {
          if (i.yLocation == square_object.yLocation) {
            if (i.xLocation + 1 == square_object.xLocation) {
              if (square_object.isPlaced) {
                return false;
              }
            }
          }
        }
      }
    }
  } else if (dir == "Left") {
    for (auto& s : m_occupiedSquares) {
      if (s->xLocation - 1 == -1 && !s->isPlaced) {
        return false;
      }
    }
    for (const auto& i : m_squareObjects) {
      for (const auto& square_object : m_squareObjects) {
        if (i.isOccupied) {
          if (i.yLocation == square_object.yLocation) {
            if (i.xLocation - 1 == square_object.xLocation) {
              if (square_object.isPlaced) {
                return false;
              }
            }
          }
        }
      }
    }
  } else if (dir == "Down") {
    for (auto& s : m_occupiedSquares) {
      if (s->yLocation + 1 == HEIGHT) {
        return false;
      }
    }
    for (const auto& square_object : m_squareObjects) {
      for (const auto& neighbor_square : m_squareObjects) {
        if (neighbor_square.isOccupied) {
          if (neighbor_square.xLocation == square_object.xLocation) {
            if (neighbor_square.yLocation + 1 == square_object.yLocation) {
              if (neighbor_square.isPlaced) {
                return false;
              }
            }
          }
        }
      }
    }
  }

  return true;
}

void Board::Move(std::string dir) {
  if (m_currentPiece != nullptr) {
    PauseUpdate();
    if (dir == "Left" && CanMove("Left")) {
      busyMoving = true;
      std::cout << "STARTED MOVING" << dir;
      bool moved_center = false;
      ClearSquares();
      for (auto& s : m_squareObjects) {
        for (auto& os : m_occupiedSquares) {
          if (s.xLocation == os->xLocation - 1 &&
              s.yLocation == os->yLocation) {
            s.isOccupied = true;
            s.type = m_currentType;
            s.facing = m_currentFacing;
            if (os->isCenter && !moved_center) {
              s.isCenter = true;
              os->isCenter = false;
              moved_center = true;
            }
          }
        }
      }
      m_currentPiece->UpdateRadius(m_occupiedSquares);

    } else if (dir == "Right" && CanMove("Right")) {
      bool moved_center = false;
      busyMoving = true;
      std::cout << "STARTED MOVING" << dir;

      ClearSquares();

      for (auto& s : m_squareObjects) {
        for (auto& os : m_occupiedSquares) {
          if (s.xLocation == os->xLocation + 1 &&
              s.yLocation == os->yLocation) {
            s.isOccupied = true;
            s.type = m_currentType;
            s.facing = m_currentFacing;
            if (os->isCenter && !moved_center) {
              s.isCenter = true;
              os->isCenter = false;
              moved_center = true;
            }
          }
        }
      }
      m_currentPiece->UpdateRadius(m_occupiedSquares);

    } else if (dir == "Down" && CanMove("Down")) {
      MoveDown();
    }
    std::cout << "FINISHED MOVING\n";

    ResumeUpdate();
  }
}
void Board::MoveDown() {
  // push all occupied squares down one piece
  // for every square, if it's location is directly below an occupied square,
  // we  call it as occupied
  if (placeOnNextTick == false) {
    busyMoving = true;
    PauseUpdate();
    m_placed = false;
    ClearSquares();
    bool moved_center = false;
    // use those cleared square's location data to activate the tile's directly
    // beneath
    for (auto& s : m_squareObjects) {
      for (auto& os : m_occupiedSquares) {
        if (s.xLocation == os->xLocation && s.yLocation == os->yLocation + 1) {
          s.isOccupied = true;

          s.type = m_currentType;
          s.facing = m_currentFacing;
          if (os->isCenter && !moved_center) {
            s.isCenter = true;
            os->isCenter = false;
            moved_center = true;
          }
        }
      }
    }
    if (m_currentPiece != nullptr) {
      m_currentPiece->UpdateRadius(m_occupiedSquares);
    }

    ResumeUpdate();
  }
}
void Board::PauseUpdate() { m_pauseUpdate = true; }
void Board::ResumeUpdate() { m_pauseUpdate = false; }
void Board::UpdateVectors() {
  // Find all occupied squares
  if (!m_pauseUpdate) {
    m_occupiedSquares.clear();
    placedSquares.clear();
    for (auto& s : m_squareObjects) {
      s.placedHasFallen = false;
      if (s.isPlaced) {
        placedSquares.push_back(&s);
      }
      if (s.isOccupied && !s.isPlaced) {
        m_currentType = s.type;
        m_currentFacing = s.facing;
				auto it = std::find(m_occupiedSquares.begin(), m_occupiedSquares.end(), &s);
				if (it == m_occupiedSquares.end())
          m_occupiedSquares.push_back(&s);
        }
			else if (!s.isOccupied && !s.isPlaced) {
				s.facing = "NA";
				s.type = BLANK;
      }
    }
  }
  busyMoving = false;
}

bool Board::CanMoveDown() {
  for (auto i = 0; i < m_squareObjects.size(); i++) {
    if (i > WIDTH * 2) {
      if (m_squareObjects[i].yLocation == HEIGHT - 1 &&
          m_squareObjects[i].isOccupied &&
          m_squareObjects[i].isPlaced == false) {
        if (!m_placed) return false;
      }

      // if this block is placed
      if (m_squareObjects[i].isPlaced &&
          m_squareObjects[i - WIDTH].isPlaced == false) {
        // check if block above is occupied and not placed
        if (m_squareObjects[i - WIDTH].isOccupied) {
          // Wait for next tick, then place the piece.
          return false;
        }
      }
    }
  }
  return true;
}
void Board::CollisionCheck() {
  if (placeOnNextTick == false) {
    for (auto i = 0; i < m_squareObjects.size(); i++) {
      // Check gameOver
      if (i > 0 && i < WIDTH) {
        if (m_squareObjects[i + WIDTH].isPlaced) {
          GAMEOVER = true;
        }
      }
      if (i > WIDTH * 2) {
        if (m_squareObjects[i].yLocation == HEIGHT - 1 &&
            m_squareObjects[i].isOccupied &&
            m_squareObjects[i].isPlaced == false) {
          if (!m_placed) placeOnNextTick = true;
        }

        // if this block is placed
        if (m_squareObjects[i].isPlaced &&
            m_squareObjects[i - WIDTH].isPlaced == false) {
          // check if block above is occupied and not placed
          if (m_squareObjects[i - WIDTH].isOccupied) {
            // Wait for next tick, then place the piece.
            placeOnNextTick = true;
          }
        }
      }
    }
  }
}
void Board::PlacePiece() {
  PauseUpdate();
  placeOnNextTick = false;
  if (CanMoveDown()) {
    MoveDown();
    return;
  }
  busyMoving = true;
  m_placed = true;
  Game::engine->OnPlaceBlock();
  for (auto& all_occupied_squares : m_occupiedSquares) {
    all_occupied_squares->isPlaced = true;
    all_occupied_squares->isOccupied = false;
    all_occupied_squares->isCenter = false;
  }
  placeOnNextTick = false;
  Game::frame_delay = tempGameSpeed;
  ResumeUpdate();
  UpdateVectors();
  CheckClearRow();
  dropPiece = true;
}

void Board::HardDrop() {
  tempGameSpeed = Game::frame_delay;
  Game::frame_delay = 1;
  hard_drop = true;
}

void Board::DrawBoard() {
  if (busyMoving) {
    std::cout << "BUSY\n";
  }
  for (auto& s : m_squareObjects) {
    const int centered_start_x = (winWidth / 2) +
                                 (s.xLocation * Game::BLOCK_RESOLUTION) -
                                 ((WIDTH * Game::BLOCK_RESOLUTION) / 2);
    const int centered_start_y = (winHeight / 2) +
                                 (s.yLocation * Game::BLOCK_RESOLUTION) -
                                 ((HEIGHT * Game::BLOCK_RESOLUTION) / 2);
    src.x = 0;
    src.y = 0;
    src.w = 256;
    src.h = 256;
    dest.x = centered_start_x;
    dest.y = centered_start_y;
    dest.w = Game::BLOCK_RESOLUTION;
    dest.h = Game::BLOCK_RESOLUTION;

    if (!s.isOccupied && !s.isPlaced || s.type == BLANK) {
      TextureManager::Draw(Textures::blankSquare, src, dest);
    }

    else {
      if (s.type == SQUARE) {
        TextureManager::Draw(Textures::yellowSquare, src, dest);
      }
      if (s.type == LONG) {
        TextureManager::Draw(Textures::lightBlueSquare, src, dest);
      }
      if (s.type == R_PIECE) {
        TextureManager::Draw(Textures::blueSquare, src, dest);
      }
      if (s.type == L_PIECE) {
        TextureManager::Draw(Textures::orangeSquare, src, dest);
      }
      if (s.type == T_PIECE) {
        TextureManager::Draw(Textures::purpleSquare, src, dest);
      }
      if (s.type == S_PIECE) {
        TextureManager::Draw(Textures::greenSquare, src, dest);
      }
      if (s.type == Z_PIECE) {
        TextureManager::Draw(Textures::redSquare, src, dest);
      }
    }
  }
}
