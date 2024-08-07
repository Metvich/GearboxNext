#include "../include/GearsPanel.h"

GearsPanel::GearsPanel(QLineEdit *countGear, QWidget *parent)
    : QScrollArea(parent) {
  this->scrolledArea = new QFrame(this);
  this->scrolledArea->setGeometry(0, 0, 222, 0);
  this->setWidget(this->scrolledArea);

  this->countGear = countGear;
}

GearsPanel::~GearsPanel() { delete this->scrolledArea; }

void GearsPanel::addGear(const QString &gear, const QString &ratio) {
  this->gears.push_back(new MyGearOutWidget(this->gears.size() * 27 + 1, gear,
                                            ratio, this, this->scrolledArea));
  this->gears.back()->setToolTip(ratio);
  this->gears.back()->myShow();
}

void GearsPanel::addGearFromMap(const std::map<double, unsigned short> &result,
                                int numBox) {
  auto to_binString = [](unsigned short value, int numBox) {
    QString result;
    result.reserve(numBox);
    do {
      result.push_back(QChar('0' + (value & 0b1)));
      value >>= 1;
      numBox--;
    } while (numBox > 0);
    return result;
  };

  auto itResult = result.begin();
  auto itGears = this->gears.begin();
  for (; itGears != this->gears.end() && itResult != result.end();
       ++itGears, ++itResult)
    (*itGears)->setGear(to_binString(itResult->second, numBox),
                        QString::number(itResult->first, 'f', 3));

  this->gears.erase(itGears, this->gears.end());

  while (itResult != result.end()) {
    addGear(to_binString(itResult->second, numBox),
            QString::number(itResult->first, 'f', 3));
    itResult++;
  }
  setMaximumFrame();
  this->numBox = numBox;
}

void GearsPanel::setMaximumFrame() {
  this->scrolledArea->setFixedHeight(this->gears.size() * 27);
}

void GearsPanel::removeGear(MyGearOutWidget *gear) {
  auto it = this->gears.begin();
  while (it != this->gears.end() && (*it) != gear)
    ++it;
  ++it;

  while (it != this->gears.end()) {
    (*it)->shiftCordY();
    ++it;
  }

  this->gears.remove(gear);
  setMaximumFrame();
  this->countGear->setText(QString::number(this->gears.size()));
}

QString *GearsPanel::getGearBoxState() {
  QString *result = new QString[this->gears.size()];
  int i = 0;
  for (auto it = this->gears.begin(); it != this->gears.end(); ++it, i++)
    result[i] = (*it)->getGearText();
  return result;
}

//======================================================================================

MyGearOutWidget::MyGearOutWidget(int y, const QString &gear,
                                 const QString &ratio, GearsPanel *panel,
                                 QWidget *parent)
    : QFrame(parent) {
  this->setGeometry(QRect(1, y, 220, 25));

  this->gear = new QLineEdit(gear, this);
  this->gear->setGeometry(0, 0, 94, 25);
  this->gear->setAlignment(Qt::AlignLeft);
  this->gear->setEnabled(false);

  this->ratio = new QLineEdit(ratio, this);
  this->ratio->setGeometry(104, 0, 81, 25);
  this->ratio->setAlignment(Qt::AlignCenter);
  this->ratio->setEnabled(false);

  this->deleteButton = new QPushButton(this);
  this->deleteButton->setGeometry(QRect(195, 0, 25, 25));
  this->deleteButton->setText(QString::fromUtf8("-"));
  this->deleteButton->setStyleSheet(QString::fromUtf8("text-align: top"));
  QObject::connect(this->deleteButton, &QPushButton::clicked,
                   [panel, this]() { panel->removeGear(this); });
}

MyGearOutWidget::~MyGearOutWidget() {
  delete this->deleteButton;
  delete this->gear;
  delete this->ratio;
}

void MyGearOutWidget::setGear(const QString &gear, const QString &ratio) {
  this->gear->setText(gear);
  this->ratio->setText(ratio);
  this->ratio->setToolTip(ratio);
}

void MyGearOutWidget::shiftCordY() { this->move(this->x(), this->y() - 27); }

void MyGearOutWidget::myShow() { this->show(); }
