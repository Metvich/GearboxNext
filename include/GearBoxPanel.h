#ifndef MY_GEARBOX_PANEL
#define MY_GEARBOX_PANEL

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QString>
#include <list>

enum TypesCollum { OffCollum, OnCollum };

class NumBox;
class MyGearInWidget;
class GearBoxPanel;

class GearBoxPanel : public QFrame {
 private:
  std::list<MyGearInWidget *> gearBoxes;

 public:
  GearBoxPanel(QWidget *parent = nullptr);
  ~GearBoxPanel();

  void addGearBox();
  void addGearBoxFromArray(const std::vector<uint32_t> &result,
                           const int startPosition, const bool isGreaterOne,
                           const TypesCollum typeCollum, int **exampleBoxes);
  void removeGearBox(MyGearInWidget *gearBox);
  void removeEndRangeGearBox(uint32_t start);
  void setAllOne();
  bool checkCorec();
  inline int getNumBox() { return this->gearBoxes.size(); }
  int **getValue();
};

class MyGearInWidget : public QFrame {
 private:
  NumBox *numBox;
  QSpinBox **gear;
  QPushButton *deleteButton;

 public:
  MyGearInWidget(int y, int n, GearBoxPanel *panel);
  ~MyGearInWidget();
  void myShow();
  void shiftCordY();
  bool checkCorec();
  void setValue(const int *exampleBox, const bool isGreaterOne,
                const TypesCollum typeCollum);
  inline void setOne() {
    for (int i = 0; i < 4; i++) this->gear[i]->setValue(1);
  }
  inline int *getValue() {
    return new int[4]{this->gear[0]->value(), this->gear[1]->value(),
                      this->gear[2]->value(), this->gear[3]->value()};
  }
};

class NumBox : public QLineEdit {
 private:
  int value;

 public:
  NumBox(QWidget *parent);
  ~NumBox();
  void stepDown();
  void setValue(int value);
};

#endif