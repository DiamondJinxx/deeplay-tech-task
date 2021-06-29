TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board_class/board.cpp \
        gamer_class/abstract_gamer.cpp \
        gamer_class/gamer.cpp \
        gamer_class/smart_gamer.cpp \
        main.cpp \
        main_game_class/maingame.cpp

HEADERS += \
    board_class/board.h \
    gamer_class/abstract_gamer.h \
    gamer_class/gamer.h \
    gamer_class/smart_gamer.h \
    main_game_class/maingame.h
