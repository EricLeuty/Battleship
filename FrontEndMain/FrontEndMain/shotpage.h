#ifndef SHOTPAGE_H
#define SHOTPAGE_H

#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class ShotPage;
}

class ShotPage : public QWidget
{
    Q_OBJECT

public:
    explicit ShotPage(MainWindow *parent = nullptr);
    ~ShotPage();
    void createShotGrid();
    Coordinates getShotCords(QPushButton *button);
    void loadShotGrid(Grid currentGrid, bool showShips, string shipType);
    void on_shotGridClick(QPushButton *button);
    int getInt(QString ui_label);
    void updateSunkUI(int gridIndex);
    void updateStats(Grid currentGrid);




private slots:
    void on_shootScreenEndTurn_clicked();

private:
    Ui::ShotPage *ui;
    MainWindow *main;
    vector<vector<int> > ship_passing;

};

#endif // SHOTPAGE_H
