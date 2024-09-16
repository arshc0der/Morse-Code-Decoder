#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <sstream>
#include <QTimer>
#include <Windows.h>
#include <QClipboard>
#include <QApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , shouldStop(false)
    , currentIndex(0)
{
    ui->setupUi(this);

    morseCodeMap = {
        {".-", "A"}, {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, {".", "E"},
        {"..-.", "F"}, {"--.", "G"}, {"....", "H"}, {"..", "I"}, {".---", "J"},
        {"-.-", "K"}, {".-..", "L"}, {"--", "M"}, {"-.", "N"}, {"---", "O"},
        {".--.", "P"}, {"--.-", "Q"}, {".-.", "R"}, {"...", "S"}, {"-", "T"},
        {"..-", "U"}, {"...-", "V"}, {".--", "W"}, {"-..-", "X"}, {"-.--", "Y"},
        {"--..", "Z"}, {"/", " "}, // Space
        {".-.-.-", "."}, // Period
        {",", ","}, // Comma
        {"-", "-"}, // Hyphen
        {"-.-.--", "!"}, // Exclamation Mark
        {"--..--", "?"} // Question Mark
    };

    // Initialize the playback timer
    playbackTimer = new QTimer(this);
    connect(playbackTimer, &QTimer::timeout, this, &MainWindow::on_playbackTimer_timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::decodeMorseCode(const std::string& morseCode)
{
    std::istringstream stream(morseCode);
    std::string token;
    std::string decodedMessage;

    while (std::getline(stream, token, ' ')) {
        auto it = morseCodeMap.find(token);
        if (it != morseCodeMap.end()) {
            decodedMessage += it->second;
        } else {
            decodedMessage += "?"; // Unknown code
        }
    }

    return decodedMessage;
}

void MainWindow::startPlayback(const std::string& morseCode)
{
    shouldStop = false; // Reset the stop flag
    currentMorseCode = morseCode;
    currentIndex = 0;
    playbackTimer->start(200); // Start the timer with an initial interval
}

void MainWindow::playSystemBeep(bool isShort)
{
    if (isShort) {
        Beep(1000, 200); // Short beep
    } else {
        Beep(1000, 600); // Long beep
    }
}

void MainWindow::stopPlayback()
{
    shouldStop = true;
    playbackTimer->stop(); // Stop the timer
}

void MainWindow::on_playbackTimer_timeout()
{
    if (shouldStop) {
        stopPlayback(); // Stop playback if requested
        return;
    }

    if (currentIndex >= currentMorseCode.size()) {
        stopPlayback(); // Stop playback when done
        return;
    }

    char c = currentMorseCode[currentIndex++];
    if (c == '.') {
        playSystemBeep(true);  // Short beep
        playbackTimer->start(200); // Short pause between sounds
    } else if (c == '-') {
        playSystemBeep(false); // Long beep
        playbackTimer->start(600); // Longer pause between sounds
    } else {
        playbackTimer->start(200); // Space between symbols
    }
}

void MainWindow::on_CodeInput_textChanged()
{
    lastInput = ui->CodeInput->toPlainText().trimmed();
    std::string inputStr = lastInput.toStdString();
    std::string decodedMessage = decodeMorseCode(inputStr);
    ui->Decode->setText(QString::fromStdString(decodedMessage));
}

void MainWindow::on_hearcode_clicked()
{
    std::string inputStr = lastInput.toStdString();
    std::string decodedMessage = decodeMorseCode(inputStr);
    ui->Decode->setText(QString::fromStdString(decodedMessage));
    startPlayback(inputStr); // Start playback
}

void MainWindow::on_stop_hear_code_clicked()
{
    stopPlayback(); // Stop playback
}

void MainWindow::on_copy_decode_code_clicked()
{
    // Retrieve the text from the Decode text widget
    QString decodedText = ui->Decode->text();

    // Access the application's clipboard
    QClipboard *clipboard = QApplication::clipboard();

    // Set the text to the clipboard
    clipboard->setText(decodedText);

    // Optionally, you can print a debug message
    qDebug() << "Copied to clipboard:" << decodedText;

    // Change the button text to "Copied"
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString originalText = button->text();
        button->setText("Copied");

        // Start a timer to revert the button text after 1 second (1000 milliseconds)
        QTimer::singleShot(1000, [button, originalText]() {
            button->setText(originalText);
        });
    }
}

