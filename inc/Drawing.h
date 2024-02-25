#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#include <ncurses.h>
#endif

#include <iostream>

static inline void SetConsoleCursor(uint32_t x, uint32_t y)
{
#ifdef __linux__
    move(x, y);
#elif _WIN32
#endif
}

static inline void ClearConsoleWindow()
{
#ifdef __linux__
    clear();
#elif _WIN32
#endif
}

static inline void HideConsoleCursor(bool hide)
{
#ifdef __linux__
    if (hide)
        std::printf("\e[?25l");
    else
        std::printf("\e[?25h");
#elif _WIN32
#endif
}

static inline void ConsoleSleep(uint32_t sec)
{
#ifdef __linux__
    sleep(sec);
#elif _WIN32
#endif
}

