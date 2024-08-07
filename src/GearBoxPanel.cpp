#include "../include/GearBoxPanel.h"

GearBoxPanel::GearBoxPanel(QWidget *parent) : QFrame(parent) {}

GearBoxPanel::~GearBoxPanel() { removeEndRangeGearBox(0); }

void GearBoxPanel::addGearBox() {
  if (this->gearBoxes.size() > 11)
    return;
  this->gearBoxes.push_back(new MyGearInWidget(
      this->gearBoxes.size() * 27 + 2, this->gearBoxes.size() + 1, this));
  this->gearBoxes.back()->myShow();
}

void GearBoxPanel::addGearBoxFromArray(const std::vector<uint32_t> &result,
                                       const int startPosition,
                                       const bool isGreaterOne,
                                       const TypesCollum typeCollum,
                                       int **exampleBoxes) {
  auto it = this->gearBoxes.begin();
  std::advance(it, startPosition);
  int i = result.size() - 1;
  while (i >= 0) {
    int temp = result[i];
    while (temp > 0) {
      if (it == this->gearBoxes.end()) {
        addGearBox();
        it = (--this->gearBoxes.end());
      }
      (*it)->setValue(exampleBoxes[i], isGreaterOne, typeCollum);
      temp--;
      ++it;
    }
    i--;
  }
}

void GearBoxPanel::removeGearBox(MyGearInWidget *gearBox) {
  auto it = this->gearBoxes.begin();
  while (it != this->gearBoxes.end() && (*it) != gearBox)
    ++it;
  ++it;

  while (it != this->gearBoxes.end()) {
    (*it)->shiftCordY();
    ++it;
  }

  delete gearBox;
  this->gearBoxes.remove(gearBox);
}

void GearBoxPanel::removeEndRangeGearBox(uint32_t start) {
  auto startIt = this->gearBoxes.begin();
  std::advance(startIt, start);
  auto it = startIt;
  while (it != this->gearBoxes.end()) {
    delete (*it);
    ++it;
  }
  this->gearBoxes.erase(startIt, this->gearBoxes.end());
}

void GearBoxPanel::setAllOne() {
  for (auto it : this->gearBoxes)
    it->setOne();
}

bool GearBoxPanel::checkCorec() {
  bool result = true;
  for (auto it = this->gearBoxes.begin(); it != this->gearBoxes.end(); ++it)
    result = result && (*it)->checkCorec();
  return result;
}

int **GearBoxPanel::getValue() {
  int **result = new int *[this->gearBoxes.size()];
  int i = 0;
  for (auto it = this->gearBoxes.begin(); it != this->gearBoxes.end(); ++it) {
    result[i] = (*it)->getValue();
    i++;
  }
  return result;
}

//======================================================================================

MyGearInWidget::MyGearInWidget(int y, int n, GearBoxPanel *panel)
    : QFrame(panel) {
  this->setGeometry(QRect(2, y, 245, 25));

  this->numBox = new NumBox(this);
  this->numBox->setGeometry(QRect(0, 0, 25, 25));
  this->numBox->setReadOnly(true);
  this->numBox->setAlignment(Qt::AlignCenter);
  this->numBox->setValue(n);
  this->numBox->setEnabled(false);

  this->gear = new QSpinBox *[4];
  for (int i = 0; i < 4; i++) {
    this->gear[i] = new QSpinBox(this);
    this->gear[i]->setGeometry(QRect(45 * i + 35, 0, 35, 25));
    this->gear[i]->setMinimum(1);
    this->gear[i]->setMaximum(9);
  }

  this->deleteButton = new QPushButton(this);
  this->deleteButton->setGeometry(QRect(215, 0, 25, 25));
  this->deleteButton->setText(QString::fromUtf8("-"));
  this->deleteButton->setStyleSheet(QString::fromUtf8("text-align: top"));
  QObject::connect(this->deleteButton, &QPushButton::clicked,
                   [panel, this]() { panel->removeGearBox(this); });
}

MyGearInWidget::~MyGearInWidget() {
  delete this->numBox;
  delete this->deleteButton;
  for (int i = 0; i < 4; i++)
    delete this->gear[i];
  delete[] this->gear;
}

void MyGearInWidget::shiftCordY() {
  this->move(this->x(), this->y() - 27);
  this->numBox->stepDown();
}

void MyGearInWidget::myShow() { this->show(); }

bool MyGearInWidget::checkCorec() {
  if (this->gear[0]->value() == this->gear[1]->value() ||
      this->gear[2]->value() == this->gear[3]->value())
    return true;
  return (((this->gear[0]->value() - this->gear[1]->value()) & (1 << 31)) ==
          ((this->gear[2]->value() - this->gear[3]->value()) & (1 << 31)));
}

void MyGearInWidget::setValue(const int *exampleBox, const bool isGreaterOne,
                              const TypesCollum typesCollum) {
  this->gear[((uint32_t)typesCollum == TypesCollum::OffCollum) * 2]->setValue(
      exampleBox[!isGreaterOne]);
  this->gear[1 + ((uint32_t)typesCollum == TypesCollum::OffCollum) * 2]
      ->setValue(exampleBox[isGreaterOne]);
}

//======================================================================================

NumBox::NumBox(QWidget *parent) : QLineEdit(parent) {}

NumBox::~NumBox() {}

void NumBox::stepDown() { this->setText(QString::number(--this->value)); }

void NumBox::setValue(int value) {
  this->setText(QString::number(this->value = value));
}