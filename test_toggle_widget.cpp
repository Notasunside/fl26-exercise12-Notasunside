#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  
   void startsOff();
    void buttonTogglesLight();
};

// Implement the tests here
  void TestToggleWidget::startsOff()
  {
      ToggleWidget widget;
      QVERIFY(!widget.isOn());
  }

  void TestToggleWidget::buttonTogglesLight()
  {
      ToggleWidget widget;
      widget.show();
      QPushButton *button = widget.findChild<QPushButton *>();
      QVERIFY(button != nullptr);
      //-- The light starts off. //
      QVERIFY(!widget.isOn());
      //-- a click turns it on. //
      QTest::mouseClick(button, Qt::LeftButton);
      QVERIFY(widget.isOn());
      //-- an click turns it off. //
      QTest::mouseClick(button, Qt::LeftButton);
      QVERIFY(!widget.isOn());
      //-- one more time lmao //
      QTest::mouseClick(button, Qt::LeftButton);
      QVERIFY(widget.isOn());
  }

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"


