#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <unordered_map>
#include <QTimer>  // Include for QTimer

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CodeInput_textChanged();
    void on_hearcode_clicked();
    void on_stop_hear_code_clicked();
    void on_playbackTimer_timeout(); // Slot for timer timeout

    void on_copy_decode_code_clicked();

private:
    Ui::MainWindow *ui;
    std::unordered_map<std::string, std::string> morseCodeMap;
    std::string decodeMorseCode(const std::string& morseCode);
    void startPlayback(const std::string& morseCode); // Start playback
    void playSystemBeep(bool isShort); // Play system beep
    void stopPlayback(); // Stop playback

    QString lastInput;
    bool shouldStop;
    QTimer *playbackTimer; // Timer for playback
    std::string currentMorseCode; // Morse code to play
    size_t currentIndex; // Current position in Morse code
};

#endif // MAINWINDOW_H
