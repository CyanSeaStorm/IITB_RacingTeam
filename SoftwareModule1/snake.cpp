#include <ncurses.h>
#include <deque>
#include <random> 
//Some Logic of This was AI generated.

// ------------------ Random Utility ------------------
int rand_int(int lo, int hi) {
    static std::mt19937 gen(std::random_device{}());
    return std::uniform_int_distribution<int>(lo, hi)(gen);
}

// ------------------ Board ------------------
class Board {
    int height, width;
    int score;

public:
    Board(int h, int w) : height(h), width(w), score(0) {}

    int getHeight() const { return height; }
    int getWidth() const { return width; }

    void addScore(int v = 10) { score += v; }
    int getScore() const { return score; }

    void draw() const {
        box(stdscr, 0, 0);
        mvprintw(0, 2, " Score: %d ", score);
    }
};

// ------------------ Snake ------------------
class Snake {
    std::deque<std::pair<int,int>> body;
    int dx, dy;

public:
    Snake(int x, int y) : dx(1), dy(0) {
        body.push_back({y, x});
    }

    void setDirection(int ndx, int ndy) {
        if (ndx == -dx && ndy == -dy) return;  // prevent reverse
        dx = ndx; dy = ndy;
    }

    std::pair<int,int> nextHead() const {
        auto [y, x] = body.front();
        return {y + dy, x + dx};
    }

    void move(bool grow) {
        body.push_front(nextHead());
        if (!grow)
            body.pop_back();
    }

    bool collides(int y, int x) const {
        for (auto &p : body)
            if (p.first == y && p.second == x)
                return true;
        return false;
    }

    bool selfCollision() const {
        auto head = body.front();
        for (size_t i = 1; i < body.size(); i++)
            if (body[i] == head)
                return true;
        return false;
    }

    void draw() const {
        for (auto &p : body)
            mvaddch(p.first, p.second, 'O');
    }
};

// ------------------ Food ------------------
class Food {
    int x, y;
    bool exists;

public:
    Food() : exists(false) {}

    void spawn(const Board& board, const Snake& snake) {
        if (exists) return;

        do {
            y = rand_int(1, board.getHeight() - 2);
            x = rand_int(1, board.getWidth() - 2);
        } while (snake.collides(y, x));

        exists = true;
    }

    bool isAt(int sy, int sx) const {
        return exists && sy == y && sx == x;
    }

    void consume() { exists = false; }

    void draw() const {
        if (exists)
            mvaddch(y, x, '*');
    }
};

// ------------------ Game ------------------
class Game {
    Board board;
    Snake snake;
    Food food;
    bool running;

public:
    Game() : board(20, 40), snake(20, 10), running(true) {}

    void handleInput(int ch) {
        switch (ch) {
            case KEY_UP:
            case 'w': snake.setDirection(0, -1); break;
            case KEY_DOWN:
            case 's': snake.setDirection(0, 1); break;
            case KEY_LEFT:
            case 'a': snake.setDirection(-1, 0); break;
            case KEY_RIGHT:
            case 'd': snake.setDirection(1, 0); break;
            case 'q': running = false; break;
        }
    }

    void update() {
        auto [ny, nx] = snake.nextHead();

        // wall collision
        if (ny <= 0 || ny >= board.getHeight() - 1 ||
            nx <= 0 || nx >= board.getWidth() - 1) {
            running = false;
            return;
        }

        bool grow = food.isAt(ny, nx);
        snake.move(grow);

        if (snake.selfCollision()) {
            running = false;
            return;
        }

        if (grow) {
            food.consume();
            board.addScore();
        }

        food.spawn(board, snake);
    }

    void draw() {
        clear();
        board.draw();
        snake.draw();
        food.draw();
        refresh();
    }

    void gameOver() {
        clear();
        mvprintw(10, 10, "GAME OVER");
        mvprintw(12, 10, "Final Score: %d", board.getScore());
        mvprintw(14, 10, "Press R to restart or Q to quit");
        refresh();

        int ch;
        while ((ch = getch()) != ERR) {
            if (ch == 'q') break;
            if (ch == 'r') {
                *this = Game();
                run();
                break;
            }
            napms(50);
        }
    }

    void run() {
        const int FRAME_DELAY_MS = 120;

        while (running) {
            int ch = getch();   // non-blocking
            handleInput(ch);
            update();
            draw();
            napms(FRAME_DELAY_MS);
        }
        gameOver();
    }
};

// ------------------ main ------------------
int main() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    Game game;
    game.run();

    endwin();
    return 0;
}
