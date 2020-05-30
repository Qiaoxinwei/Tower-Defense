#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "tdobj.h"
#include <vector>
#include "enemy1.h"
#include "enemy2.h"
#include <QList>

class Enemy1;
class Enemy2;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void getHPdamage(int damage=1);
    void removeEnemy1(Enemy1* enemy);
    void removeEnemy2(Enemy2* enemy);
    void initworld();
    void showworld(QPainter *painter);
protected slots:
    void initenemy1();
    void initenemy2();
    void updateenemy1();
    void updateenemy2();
public:
    Ui::MainWindow *ui;
    QTimer *timer1,*timer2,*timer3,*timer4;
    QList<Enemy1 *> m_enemy1list;
    QList<Enemy2 *> m_enemy2list;
    QList<TDobj *> objs;
};
#endif // MAINWINDOW_H

