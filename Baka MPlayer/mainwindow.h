#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

#include "mpvhandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual bool event(QEvent *event);
    bool HandleMpvEvent(MpvHandler::MpvEvent event);

    inline void SetDurationLabel();
    inline void SetRemainingLabel();
    inline void SetSeekBar();
    inline void SetPlayButton();
    inline void EnableControls();

private slots:
    void on_action_Open_File_triggered();
    void on_actionE_xit_triggered();
    void on_openButton_clicked();
    void on_playButton_clicked();
    void on_rewindButton_clicked();
    void on_previousButton_clicked();
    void on_nextButton_clicked();
    void on_volumeSlider_sliderMoved(int position);
    void on_seekBar_sliderMoved(int position);
    void on_seekBar_sliderPressed();

    void on_playlistButton_clicked();

private:
    Ui::MainWindow *ui;
    MpvHandler *mpv;

    QSlider *seekBar;
    QLabel *durationLabel,
           *remainingLabel;
    QListWidget *playlist;
    QPushButton *playButton,
                *rewindButton,
                *previousButton,
                *nextButton;
};

#endif // MAINWINDOW_H