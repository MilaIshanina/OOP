﻿#ifndef UIFACADE_H
#define UIFACADE_H

#include <QApplication>
#include <QScreen>
#include <QDebug>

#include "GUI/mainwindow.h"
#include "InformationHeaders/commandPar.h"
#include "game.h"
#include "GameField/Coords.h"

class UIFacade : public QObject, public std::enable_shared_from_this<UIFacade>
{
    Q_OBJECT

public:
    UIFacade(int argc, char *argv[]);
    ~UIFacade() = default;

    void start();
    void receiveStrAnswer(std::string answer);

private:
    QApplication *application;
    // GUI
    std::shared_ptr<MainWindow> window;
    // Game
    std::shared_ptr<Game> game;
    void guiSetup();

public slots:
    void createFieldRequest(size_t fieldSize, size_t playersCount);
    void addBaseRequest(eBaseType baseType, size_t xCoord, size_t yCoord, QString name);
    void addUnitRequest(eUnitsType unitType, QString sourceBaseName);
    void moveUnitReguest(size_t xSource, size_t ySource, size_t xDest, size_t yDist);
    void attackUnitRequest(size_t xSource, size_t ySource, size_t xDest, size_t yDist);
    void cellInformationReqiest(size_t xCoord, size_t yCoord, eRequest infRequest);
};

#endif // UIFACADE_H
