#ifndef COUNTER_H
#define COUNTER_H
#define FRAME_FREQUENCY 60

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

typedef unsigned int uint;

enum Values{
    HOURS, MINUTES, SECONDS
};

class Counter : public QWidget
{
    Q_OBJECT
public:
    explicit Counter(QWidget *parent = nullptr);
    virtual ~Counter();

    QString getTimeText(uint value) const;
    int getFrameFrequency() const;

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* timeLayout;
    QHBoxLayout* buttonsLayout;

    QPushButton* modeTrigger;    // decimal or normal
    QPushButton* pauseTrigger;
    bool isDecimal;
    bool paused;

    QLineEdit* hoursField;
    QLineEdit* minutesField;
    QLineEdit* secondsField;

    double hours;
    double minutes;
    double seconds;

    static const double msr;    // minute & second ratio normal to decimal (60/100)
    static const double hr;     // hour ratio normal to decimal (12/10)
    static const uint digits;

    int initLayouts();
    int initButtons();
    int initFields();
    int initVariables();

    void binding();

signals:
    bool timerPaused();
    bool modeChanged();
    // true if from normal to decimal
    // false if from decimal to normal

public slots:
    void pause();
    void changeMode();
    void updateNormalTime();
    void updateDecimalTime();
};

#endif // COUNTER_H
