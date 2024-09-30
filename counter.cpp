#include "counter.h"
#include <QMessageBox>
#include <QLayout>
#include <QSizePolicy>

const double Counter::msr = 0.6;
const double Counter::hr = 1.2;
const uint Counter::digits = 1;

Counter::Counter(QWidget *parent)
    : QWidget{parent} {
    if( this->initLayouts() ||
        this->initFields()  ||
        this->initButtons() ||
        this->initVariables()){
        QMessageBox fail;
        fail.setInformativeText("ERROR::COUNTER::failed to initialize counter");
        fail.setWindowTitle("FAIL");
        fail.exec();
        std::abort();
    }

    this->binding();
}

Counter::~Counter() {
    delete this->modeTrigger;       // there are trigger buttons
    delete this->pauseTrigger;

    delete this->hoursField;        // there are time values fields
    delete this->minutesField;
    delete this->secondsField;

    delete this->timeLayout;        // there are layouts
    delete this->buttonsLayout;
    delete this->mainLayout;
}

QString Counter::getTimeText(uint value) const {

}

// ------ INITIALIZE ------

int Counter::initLayouts() {
    this->mainLayout = new QVBoxLayout(this);
    this->buttonsLayout = new QHBoxLayout(this);
    this->timeLayout = new QHBoxLayout(this);
}

int Counter::initButtons() {
    this->modeTrigger = new QPushButton(this);
    this->pauseTrigger = new QPushButton(this);

    this->modeTrigger->setText("Change mode");
    this->pauseTrigger->setText("Pause");
}

int Counter::initFields() {
    this->hoursField = new QLineEdit(this);
    this->minutesField = new QLineEdit(this);
    this->secondsField = new QLineEdit(this);
}

int Counter::initVariables() {
    this->isDecimal = false;
    this->paused = false;

    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

void Counter::binding() {
    connect(this->modeTrigger, SIGNAL(this->modeChanged()), this, SLOT(this->changeMode()));
    connect(this->pauseTrigger,SIGNAL(this->timerPaused()), this, SLOT(this->pause()));

    this->buttonsLayout->addWidget(this->modeTrigger);
    this->buttonsLayout->addWidget(this->pauseTrigger);

    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addLayout(this->timeLayout);
}

// ----- SIGNALS -----

bool Counter::timerPaused(){

}

bool Counter::modeChanged(){
    // random things
}

void Counter::pause() {

}

void Counter::changeMode() {

}

void Counter::updateNormalTime() {

}

void Counter::updateDecimalTime()
{

}
