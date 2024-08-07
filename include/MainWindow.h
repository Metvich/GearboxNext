#ifndef MY_MAIN_WINDOW
#define MY_MAIN_WINDOW

#include <QApplication>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollBar>
#include <QSpinBox>

#include "GearBoxPanel.h"
#include "GearsPanel.h"

class MainWindow : public QMainWindow {
private:
  QLineEdit *numBoxLine, *onState, *offState, *gearBoxState, *ratio, *countGear;
  QPushButton *addButtonGearBox, *calculateButton, *copyButton, *genBoxButton;
  GearBoxPanel *gearBoxFrame;
  GearsPanel *gearFrame;
  QDialog *dial;
  QLabel *minGearText, *maxGearText;
  QDoubleSpinBox *minGear, *maxGear;
  QPushButton *genButton;
  int numExampleBox;
  int **exampleBox;

public:
  MainWindow();
  ~MainWindow();
  void calculate();
  void copy();
  void generate();
};

#endif