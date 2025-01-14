#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QWheelEvent>

#include "AttributeWidget.h"
#include "ModifiedScene.h"
#include "Field/Field.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonEditor_clicked();
    void on_buttonClose_clicked();

private:
    Ui::MainWindow *ui;
    ModifiedScene *sceneEditor;
};
