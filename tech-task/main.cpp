#include <iostream>
//#include "gamer_class/abstract_gamer.h"
#include "gamer_class/gamer.h"
#include "gamer_class/smart_gamer.h"
#include "board_class/board.h"
#include "main_game_class/maingame.h"
#include <cstdlib>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

/*
    TODO:
        1) Board class?
        2)
*/
std::mutex gFileMutex;

// run games in threads
void threadMainGame(int begin, int end)
{
    std::cerr << "Hi, I'm a new thread with id:" << std::this_thread::get_id() << std::endl;;
    MainGame mg;
    size_t turn = 0;
    for(size_t i = begin; i < end; ++i)
    {

        for(; turn < 9 && mg.run(); ++turn) {
               if(turn % 2 == 0)
               {
                   mg.firstGamerStep();
                   //mg.printBoard();
               }
               else {
                   mg.secondGamerStep();
                   //mg.printBoard();
               }
           }
//        std::lock_guard<std::mutex> gl(gFileMutex); // user RAII-style mechanism
        mg.save(mg.saveFileName_,i,mg.winner_, turn);
        turn = 0;
        mg.reset();
    }
}

int main(int argc, char* argv[])
{
    srand(time(static_cast<time_t>(0)));
    int gamesCount = 1000;
    // algo for division count of games between CPU cores
    int coresCount = std::thread::hardware_concurrency();
    if(argc >= 2)
    {
        std::string ar(argv[1]);
        gamesCount = std::stoi(ar);
    }
    int step = gamesCount / coresCount;
    std::cout << "step is :" << step << std::endl;
    std::vector<int> begins, ends;
    if(step * coresCount != gamesCount)
    {
        //need to save original number of games
        int delta =  gamesCount - step * coresCount;
        for(size_t i = 0; i < coresCount; ++i)
        {
            begins.push_back(step * i);
            ends.push_back(step * (i+1));
        }
        ends.at(coresCount - 1) += delta;
    }
    else
    {
        for(size_t i = 0; i < coresCount; ++i)
        {
            begins.push_back(step * i);
            ends.push_back(step * (i+1));
        }
    }
    unsigned int time_start = clock();
    std::cout << "Main func start " <<  std::endl;
    for(size_t i = 0; i < gamesCount; ++i)
    {
        MainGame mg;
        size_t turn = 0;
        for(; turn < 9 && mg.run(); ++turn)
        {
               if(turn % 2 == 0)
               {
                   mg.firstGamerStep();
                  // mg.printBoard();
               }
               else {

                   mg.secondGamerStep();
                   //mg.printBoard();
               }
        }
        mg.save(mg.saveFileName_,i,mg.winner_, turn);
        //    gFileMutex.unlock();
    }

    // try to use threads for calculation distributions, but the threads
    // play the same game every time

//    std::vector<std::thread> thrds;
//    for(size_t i = 0; i < coresCount; ++i)
//    {
//        thrds.push_back(std::thread(threadMainGame, begins.at(i), ends.at(i)));
//    }
//    for(auto &t : thrds)
//    {
//        t.join();
//    }

    unsigned int time_end = clock();
    unsigned int time_delta = time_end - time_start;


    std::cout << "Main func end for " << time_delta << std::endl;
    return 0;
}
