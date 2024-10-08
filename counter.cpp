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
    QString res = "";
    if(this->isDecimal){
    }
    else{

    }
    return res;
}

int Counter::getFrameFrequency() const {
    return FRAME_FREQUENCY; // 60 frames per seconds
}

// ------ INITIALIZE ------

int Counter::initLayouts() {
    this->mainLayout = new QVBoxLayout(this);
    this->buttonsLayout = new QHBoxLayout(this);
    this->timeLayout = new QHBoxLayout(this);

    return 0;
}

int Counter::initButtons() {
    this->modeTrigger = new QPushButton(this);
    this->pauseTrigger = new QPushButton(this);

    this->modeTrigger->setText("Change mode");
    this->pauseTrigger->setText("Pause");

    return 0;
}

int Counter::initFields() {
    this->hoursField = new QLineEdit(this);
    this->minutesField = new QLineEdit(this);
    this->secondsField = new QLineEdit(this);

    return 0;
}

int Counter::initVariables() {
    this->isDecimal = false;
    this->paused = false;

    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;

    return 0;
}

void Counter::binding() {
    connect(this->modeTrigger, SIGNAL(this->modeChanged()), this, SLOT(this->changeMode()));
    connect(this->pauseTrigger,SIGNAL(this->timerPaused()), this, SLOT(this->pause()));
    connect(this              ,SIGNAL(this->QWidget::repaint()),     this, SLOT(this->updateNormalTime()));

    // Layouts
    this->buttonsLayout->addWidget(this->modeTrigger);
    this->buttonsLayout->addWidget(this->pauseTrigger);

    this->timeLayout->addWidget(this->hoursField);
    this->timeLayout->addWidget(this->minutesField);
    this->timeLayout->addWidget(this->secondsField);

    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addLayout(this->timeLayout);
}

// ----- SIGNALS -----

bool Counter::timerPaused(){
    this->pauseTrigger->setCheckable(false);
    return paused;
}

bool Counter::modeChanged(){
    return this->isDecimal;
}

void Counter::pause() {
    this->paused = true;
}

void Counter::changeMode() {
    this->isDecimal = !this->isDecimal;
}

void Counter::updateNormalTime() {
    double dt = 1;
    for(size_t i = 0; i < digits; i++){
        dt /= 10;
    }
    dt /= 60;
    this->seconds -= dt;
    if(this->seconds < 0){
        this->seconds = 60.f;
        this->minutes -= 1;
        if(this->minutes < 0.f){
            this->minutes = 60.f;
            this->hours -= 1;
            if(this->hours < 0){
                hours = 0;
            }
        }
    }
}

void Counter::updateDecimalTime()
{

}
