#include "AppState.hpp"

namespace chesspp
{
    AppStateGame::AppStateGame(Application *_app, sf::RenderWindow *_display)
    : AppState(_display)
    , app(_app)
    , graphics(display)
    {
        board = new board::Board();
        board->newGame(boardConfig.getInitialLayout());
    }

    int AppStateGame::id()
    {
        return 1;
    }

    void AppStateGame::OnRender()
    {
        graphics.drawBoard(board);
    }

    void AppStateGame::OnLButtonPressed(int x, int y) noexcept
    {
        board->setSelected(board->getCurrent()); //No matter if nullptr
    }
    void AppStateGame::OnMouseMoved(int x, int y) noexcept
    {
        board->setCurrent(x, y);
    }
    void AppStateGame::OnLButtonReleased(int x, int y) noexcept
    {
        //board knows what is selected, but I think this looks more clear
        board->move(board->getSelected(), x, y);
        board->setSelected(nullptr);
    }
}
