#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QTime>

class Model : public QObject {
    Q_OBJECT

public:
    Model(QObject *parent = nullptr);
    void setBalance(int index, double balance);
    void setPeriod(int index, double period);
    double getTotalBalans();

private:
    double m_totalbalance;
    QVector<double> m_balances;
    QVector<double> m_periods;
    QVector<QTimer *> m_timer;
    QTime m_time;
private slots:
    void update1();
    void update2();
    void update3();
signals:
    void BalanceChanged();
};


#endif // MODEL_H
