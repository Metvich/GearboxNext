#ifndef MY_GEARS_PANEL
#define MY_GEARS_PANEL

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QString>
#include <list>

class MyGearOutWidget;
class GearsPanel;

class GearsPanel : public QScrollArea {
private:
  std::list<MyGearOutWidget *> gears;
  QFrame *scrolledArea;
  QLineEdit *countGear;
  int numBox;

public:
  GearsPanel(QLineEdit *countGear, QWidget *parent = nullptr);
  ~GearsPanel();

  void addGear(const QString &gear, const QString &ratio);
  void addGearFromMap(const std::map<double, unsigned short> &result,
                      int numBox);
  void removeGear(MyGearOutWidget *gear);
  void setMaximumFrame();
  QString *getGearBoxState();
  inline int getNumGear() { return this->gears.size(); }
  inline int getNumBox() { return this->numBox; }
};

class MyGearOutWidget : public QFrame {
private:
  QLineEdit *gear, *ratio;
  QPushButton *deleteButton;

public:
  MyGearOutWidget(int y, const QString &gear, const QString &ratio,
                  GearsPanel *panel, QWidget *parent);
  ~MyGearOutWidget();
  void setGear(const QString &gear, const QString &ratio);
  void myShow();
  void shiftCordY();
  inline QString getGearText() { return this->gear->text(); }
};

#endif