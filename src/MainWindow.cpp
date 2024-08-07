#include "../include/MainWindow.h"

#include <QClipboard>
#include <QIcon>
#include <cmath>
#include <map>
#include <qcoreapplication.h>
#include <vector>

MainWindow::MainWindow() {
  this->setFixedSize(521, 441);
  QIcon icon;
  icon.addFile(QString::fromUtf8("Documents/C++/EasyGearBox/Logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
  this->setWindowIcon(icon);

  this->numBoxLine = new QLineEdit(QString::fromUtf8("№"), this);
  this->numBoxLine->setAlignment(Qt::AlignCenter);
  this->numBoxLine->setGeometry(QRect(12, 10, 25, 25));
  this->numBoxLine->setEnabled(false);

  this->onState = new QLineEdit(QString::fromUtf8("On"), this);
  this->onState->setGeometry(47, 10, 80, 25);
  this->onState->setEnabled(false);
  this->onState->setAlignment(Qt::AlignCenter);
  this->offState = new QLineEdit(QString::fromUtf8("Off"), this);
  this->offState->setGeometry(137, 10, 80, 25);
  this->offState->setEnabled(false);
  this->offState->setAlignment(Qt::AlignCenter);
  this->gearBoxState = new QLineEdit(QString::fromUtf8("Gears"), this);
  this->gearBoxState->setGeometry(267, 10, 94, 25);
  this->gearBoxState->setEnabled(false);
  this->gearBoxState->setAlignment(Qt::AlignCenter);
  this->ratio = new QLineEdit(QString::fromUtf8("Ratio"), this);
  this->ratio->setGeometry(371, 10, 81, 25);
  this->ratio->setEnabled(false);
  this->ratio->setAlignment(Qt::AlignCenter);
  this->countGear = new QLineEdit(this);
  this->countGear->setGeometry(462, 10, 47, 25);
  this->countGear->setEnabled(false);
  this->countGear->setAlignment(Qt::AlignCenter);
  this->countGear->setToolTip(QString::fromUtf8("Count Gears"));

  this->gearBoxFrame = new GearBoxPanel(this);
  this->gearBoxFrame->setGeometry(QRect(10, 45, 245, 327));
  this->gearBoxFrame->setFrameShape(QFrame::Shape::Panel);
  this->gearBoxFrame->setFrameShadow(QFrame::Shadow::Sunken);

  this->addButtonGearBox = new QPushButton(this);
  this->addButtonGearBox->setGeometry(QRect(227, 10, 25, 25));
  this->addButtonGearBox->setText(QString::fromUtf8("+"));
  this->addButtonGearBox->setStyleSheet("text-align: top");
  connect(this->addButtonGearBox, &QPushButton::clicked, this->gearBoxFrame,
          &GearBoxPanel::addGearBox);

  this->gearFrame = new GearsPanel(this->countGear, this);
  this->gearFrame->setGeometry(QRect(265, 45, 246, 327));
  this->gearFrame->setFrameShape(QFrame::Shape::Panel);
  this->gearFrame->setFrameShadow(QFrame::Shadow::Sunken);
  this->gearFrame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  this->gearFrame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  this->calculateButton = new QPushButton(QString::fromUtf8("Calculate"), this);
  this->calculateButton->setGeometry(10, 381, 195, 50);
  this->calculateButton->setStyleSheet("font-size: 18px");
  connect(this->calculateButton, &QPushButton::clicked, this,
          &MainWindow::calculate);

  this->dial = new QDialog(this, Qt::Tool);
  this->dial->setFixedSize(120, 159);
  this->dial->setWindowTitle(QString::fromUtf8("Menu"));
  this->minGearText =
      new QLabel(QString::fromUtf8("Min Gear Ratio"), this->dial);
  this->minGearText->setGeometry(10, 5, 100, 25);
  this->minGear = new QDoubleSpinBox(this->dial);
  this->minGear->setGeometry(10, 32, 100, 25);
  this->minGear->setButtonSymbols(QAbstractSpinBox::NoButtons);
  this->minGear->setDecimals(3);

  this->maxGearText =
      new QLabel(QString::fromUtf8("Max Gear Ratio"), this->dial);
  this->maxGearText->setGeometry(10, 62, 100, 25);
  this->maxGear = new QDoubleSpinBox(this->dial);
  this->maxGear->setGeometry(10, 89, 100, 25);
  this->maxGear->setButtonSymbols(QAbstractSpinBox::NoButtons);
  this->maxGear->setDecimals(3);
  this->genBoxButton =
      new QPushButton(QString::fromUtf8("Generate"), this->dial);
  this->genBoxButton->setGeometry(10, 124, 100, 25);
  QObject::connect(this->genBoxButton, &QPushButton::clicked, this,
                   &MainWindow::generate);

  this->genButton = new QPushButton(QString::fromUtf8("Gen"), this);
  this->genButton->setGeometry(205, 381, 50, 50);
  this->genButton->setStyleSheet("font-size: 18px");
  QObject::connect(this->genButton, &QPushButton::clicked, this->dial,
                   &QDialog::show);

  this->copyButton = new QPushButton(QString::fromUtf8("Copy Gears"), this);
  this->copyButton->setGeometry(265, 381, 246, 50);
  this->copyButton->setStyleSheet("font-size: 18px");
  QObject::connect(this->copyButton, &QPushButton::clicked, this,
                   &MainWindow::copy);

  this->numExampleBox = 7;
  int *a = new int[2]{1, 1};
  this->exampleBox = new int *[this->numExampleBox] {
    new int[2]{1, 1}, new int[2]{5, 6}, new int[2]{2, 3}, new int[2]{5, 9},
        new int[2]{1, 2}, new int[2]{2, 5}, new int[2] {
      1, 3
    }
  };
}

MainWindow::~MainWindow() {
  delete this->numBoxLine;
  delete this->onState;
  delete this->offState;
  delete this->gearBoxState;
  delete this->ratio;
  delete this->countGear;
  delete this->addButtonGearBox;
  delete this->calculateButton;
  delete this->copyButton;
  delete this->genBoxButton;
  delete this->gearBoxFrame;
  delete this->gearFrame;
  delete this->dial;
  delete this->minGearText;
  delete this->maxGearText;
  delete this->genButton;
  for (int i = 0; i < this->numExampleBox; i++)
    delete[] this->exampleBox[i];
  delete[] this->exampleBox;
}

void MainWindow::calculate() {
  const int numBox = this->gearBoxFrame->getNumBox();
  if (numBox == 0)
    return;
  int numGear = std::pow(2, numBox);
  int **gearBoxes = this->gearBoxFrame->getValue();
  std::map<double, unsigned short> result;

  for (unsigned short i = 0; i < numGear; i++) {
    double tempUp = 1, tempUnder = 1;
    for (unsigned short j = 0; j < numBox; j++) {
      tempUp *= (gearBoxes[j][3 - (((i >> j) & 0b1) << 1)]);
      tempUnder *= (gearBoxes[j][2 - (((i >> j) & 0b1) << 1)]);
    }
    result.emplace(tempUp / tempUnder, i);
  }

  this->gearFrame->addGearFromMap(result, numBox);
  this->countGear->setText(QString::number(result.size()));

  for (int i = 0; i < numBox; i++)
    delete[] gearBoxes[i];
  delete[] gearBoxes;
}

void MainWindow::copy() {
  QString result("{");
  QString *gears = this->gearFrame->getGearBoxState();
  int numGear = this->gearFrame->getNumGear(),
      numBox = this->gearFrame->getNumBox();

  for (int i = 0; i < numBox; i++) {
    result.push_back('{');
    for (int j = 0; j < numGear; j++)
      result.push_back((gears[j][i] + ',')); // gears[j][i], ','
    if (result.back() == ',')
      result.back() = '}';
    else
      result.push_back('}');
    result.push_back(",\n");
  }
  result.replace(result.length() - 2, 2, '}');

  QApplication::clipboard()->setText(result);

  delete[] gears;
}

void MainWindow::generate() {
  std::vector<uint32_t> result(this->numExampleBox, 0);
  uint32_t numBox, numBox2;
  bool isGreaterOne;
  this->gearBoxFrame->setAllOne();

  auto foo = [&](double ratio) -> uint32_t {
    std::fill(result.begin(), result.end(), 0);
    if (ratio == 0 || ratio == 1)
      return 0;
    int startBox = this->numExampleBox - 1;
    uint32_t numBox = 0;
    double temp;
    isGreaterOne = ratio > 1;
    if ((ratio <= (double)this->exampleBox[startBox][0] /
                      (double)this->exampleBox[startBox][1]) ||
        (ratio >= (double)this->exampleBox[startBox][1] /
                      (double)this->exampleBox[startBox][0])) {
      numBox = result.back() = std::floor(
          std::log(ratio) /
          std::log(((double)this->exampleBox[startBox][isGreaterOne]) /
                   ((double)this->exampleBox[startBox][!isGreaterOne])));
      ratio *=
          std::pow((double)this->exampleBox[startBox][!isGreaterOne], numBox) /
          std::pow((double)this->exampleBox[startBox][isGreaterOne], numBox);
    }
    numBox++;

    do {
      temp = ((double)this->exampleBox[startBox][!isGreaterOne]) /
             ((double)this->exampleBox[startBox][isGreaterOne]);
      temp = std::round(ratio * 10000 * temp) / 10000;
      startBox--;
    } while ((1 - temp) > 0 != (1 - ratio) > 0 && startBox >= 0);
    result[startBox + 1]++;

    if (numBox > 2) {
      auto pred = [](uint32_t value) { return value != 0; };
      auto it = std::find_if(result.begin(), result.end(), pred);
      auto it2 = std::find_if(it + 1, result.end(), pred);
      while ((result.end() - it) > 1 && it2 != result.end()) {
        uint32_t sum = (it - result.begin()) + (it2 - result.begin());
        (*it)--;
        (*it2)--;
        result[sum >> 1]++;
        result[(sum >> 1) + (sum & 1)]++;
        it = result.begin() + (sum >> 1) + (sum & 1);
        it2 = std::find_if(it + 1, result.end(), pred);
      }
    }

    return numBox;
  };

  numBox = foo(this->minGear->value());
  this->gearBoxFrame->addGearBoxFromArray(
      result, 0, isGreaterOne, TypesCollum::OnCollum, this->exampleBox);
  numBox2 = foo(this->maxGear->value());
  if (std::signbit(1.0 - this->minGear->value()) ==
      std::signbit(1.0 - this->maxGear->value())) {
    this->gearBoxFrame->addGearBoxFromArray(
        result, 0, isGreaterOne, TypesCollum::OffCollum, this->exampleBox);
    this->gearBoxFrame->removeEndRangeGearBox(std::max(numBox, numBox2));
  } else {
    this->gearBoxFrame->addGearBoxFromArray(
        result, numBox, isGreaterOne, TypesCollum::OnCollum, this->exampleBox);
    this->gearBoxFrame->removeEndRangeGearBox(numBox + numBox2);
  }
}